/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_UART.c
  - Author        : zeweni
  - Update date   : 2020.01.29
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_UART.h"
/*-----------------------------------------------------------------------
|                                 datA                                  |
-----------------------------------------------------------------------*/
vuint8_t UART_BUSY_FLAG[4] = {0,0,0,0};		 //Busy flag of receive
/*--------------------------------------------------------
| @Description: UART mode configure define function      |
--------------------------------------------------------*/

#define  UART1_MODE_CFG(mode)  SM0 = mode >> 1, SM1 = mode
#define  UART2_MODE_CFG(mode)  S2CON = (S2CON & 0x3F)|((mode & 0x02) << 6)
#define  UART3_MODE_CFG(mode)  S3CON = (S3CON & 0x3F)|((mode & 0x02) << 6)
#define  UART4_MODE_CFG(mode)  S4CON = (S4CON & 0x3F)|((mode & 0x02) << 6)

/*--------------------------------------------------------
| @Description: UART Baud rate configure define function |
--------------------------------------------------------*/

#define UART1_TIMER1_BRTMODE_CFG(brtMode,baudRate) do{ \
AUXR = (AUXR & 0xBF) | ( !brtMode << 6 ); \
T1L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x40)) + 1 ))) ; \
T1H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x40)) + 1 ))) >> 8;} \
while(0)

#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)

	#define uartx_TIMER2_BRTMODE_CFG(brtMode,baudRate) do{ \
	AUXR = (AUXR & 0xFB) | ( !brtMode << 2 ); \
	T2L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 ))) ; \
	T2H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 ))) >> 8;} \
	while(0)

	#define UART3_TIMER3_BRTMODE_CFG(brtMode,baudRate) do{ \
	T4T3M = (T4T3M & 0xFD) | ( !brtMode << 1 ); \
	T3L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 ))) ; \
	T3H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 ))) >> 8;} \
	while(0)

	#define UART4_TIMER4_BRTMODE_CFG(brtMode,baudRate) do{ \
	T4T3M = (T4T3M & 0xDF) | ( !brtMode << 5 ); \
	T4L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 ))) ; \
	T4H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 ))) >> 8;} \
	while(0)
		
#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
	
	#define uartx_TIMER2_BRTMODE_CFG(brtMode,baudRate) do{ \
	AUXR = (AUXR & 0xFB) | ( !brtMode << 2 ); \
	T2L = (65536UL - (sysClk_FRE / (TM2PS + 1) ) / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 ))) ; \
	T2H = (65536UL - (sysClk_FRE / (TM2PS + 1) ) / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 ))) >> 8;} \
	while(0)

	#define UART3_TIMER3_BRTMODE_CFG(brtMode,baudRate) do{ \
	T4T3M = (T4T3M & 0xFD) | ( !brtMode << 1 ); \
	T3L = (65536UL - (sysClk_FRE / (TM3PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 ))) ; \
	T3H = (65536UL - (sysClk_FRE / (TM3PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 ))) >> 8;} \
	while(0)

	#define UART4_TIMER4_BRTMODE_CFG(brtMode,baudRate) do{ \
	T4T3M = (T4T3M & 0xDF) | ( !brtMode << 5 ); \
	T4L = (65536UL - (sysClk_FRE / (TM4PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 ))) ; \
	T4H = (65536UL - (sysClk_FRE / (TM4PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 ))) >> 8;} \
	while(0)
		
#endif     
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    UART1_Init
  * @brief   UART1 init function   
  * @param   *uartx: UART_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE UART1_Init(const UART_InitType *uartx)
{
    extern uint32 Get_SysClk_FRE(void);
    uint32 sysClk_FRE;
	  /* Get system clock frequency */
  	sysClk_FRE = Get_SysClk_FRE();
    UART1_MODE_CFG(uartx -> Mode);
    switch(uartx -> BRTGen)
    {
      case UART_BRT_TIM1:
      {
        TR1 = 0;        //Turn off timer0
        ET1 = 0;        //Ban timer0 interrupt
        AUXR &= 0xFE;   //Select timer 1 as baud rate generator
        TMOD &= 0x0F; 	//Timer 1 is fixed to 16 bit auto reload mode
        UART1_TIMER1_BRTMODE_CFG(uartx -> BRTMode,
                               uartx -> BaudRate);
        TR1 = 1;        //Turn on timer0
        break;
      }
      case UART_BRT_TIM2:
      {
        AUXR &= 0xEF;  //Turn off timer2
        IE2 &= 0xFB;   //Ban timer2 interrupt
        AUXR |= 0x01;  //Select timer2 as baud rate generator
		#if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			EAXFR_ENABLE();
			TM2PS = uartx -> BRTGenClkDiv;
			EAXFR_DISABLE();
		#endif	
        uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,
                               uartx -> BaudRate);   
        AUXR |= 0X10;  //Turn on timer2
        break;
      }
      default: return FSC_FAIL;
    }
	
    AUXR = (AUXR & 0xDF) | (uartx -> BRTDouble << 5);
    SCON = (SCON & 0xDF) | (uartx -> MulitComm << 5);
    SCON = (SCON & 0xEF) | (uartx -> RxEnable << 4);
    AUXR2 = (AUXR2 & 0xEF) | (uartx -> Relay << 4);
    UART1_CLEAR_BUSY_FLAG();
	
    return FSC_SUCCESS;
}

/**
  * @name    UART2_Init
  * @brief   UART2 init function   
  * @param   *uartx: UART_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE UART2_Init(const UART_InitType *uartx)
{
    extern uint32 Get_SysClk_FRE(void);
    uint32 sysClk_FRE;
  	/* Get system clock frequency */
   	sysClk_FRE = Get_SysClk_FRE();
    UART2_MODE_CFG(uartx -> Mode);
    if(uartx -> BRTGen == UART_BRT_TIM2)
    {
		AUXR &= 0xEF;  //Turn off timer2
		IE2 &= 0xFB;   //Ban timer2 interrupt
		#if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			EAXFR_ENABLE();
			TM2PS = uartx -> BRTGenClkDiv;
			EAXFR_DISABLE();
		#endif	
		uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,
                               uartx -> BaudRate);     
		AUXR |= 0X10;  //Turn on timer2
    }
    else return FSC_FAIL;
    S2CON = (S2CON & 0xDF) | (uartx -> MulitComm << 5);
    S2CON = (S2CON & 0xEF) | (uartx -> RxEnable << 4);
    UART2_CLEAR_BUSY_FLAG();
    return FSC_SUCCESS;
}

/**
  * @name    UART3_Init
  * @brief   UART3 init function   
  * @param   *uartx: UART_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE UART3_Init(const UART_InitType *uartx)
{
    extern uint32 Get_SysClk_FRE(void);
    uint32 sysClk_FRE;
  	/* Get system clock frequency */
  	sysClk_FRE = Get_SysClk_FRE();
    UART3_MODE_CFG(uartx -> Mode);
    switch(uartx -> BRTGen)
    {
        case UART_BRT_TIM2:
        {
            AUXR &= 0xEF;  //Turn off timer2
            IE2 &= 0xFB;   //Ban timer2 interrupt
            S3CON &= 0xBF;  //Select timer2 as baud rate generator
			#if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				EAXFR_ENABLE();
				TM2PS = uartx -> BRTGenClkDiv;
				EAXFR_DISABLE();
			#endif	
            uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,
                                   uartx -> BaudRate);     
            AUXR |= 0X10;  //Turn on timer2
            break;
        }
        case UART_BRT_TIM3:
        {
            T4T3M &= 0xF7;  //Turn off timer3
            IE2 &= 0xDF;  //Ban timer3 interrupt
            S3CON |= 0x40;    //Select timer3 as baud rate generator
			#if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				EAXFR_ENABLE();
				TM3PS = uartx -> BRTGenClkDiv;
				EAXFR_DISABLE();
			#endif	
            UART3_TIMER3_BRTMODE_CFG(uartx -> BRTMode,
                                   uartx -> BaudRate);
            T4T3M |= 0x08; //Turn on timer3 
            break;
         }
         default: return FSC_FAIL;
    }
    S3CON = (S3CON & 0xDF) | (uartx -> MulitComm << 5);
    S3CON = (S3CON & 0xEF) | (uartx -> RxEnable << 4);
    UART3_CLEAR_BUSY_FLAG();
    return FSC_SUCCESS;
}

/**
  * @name    UART4_Init
  * @brief   UART4 init function   
  * @param   *uartx: UART_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE UART4_Init(const UART_InitType *uartx)
{
    extern uint32 Get_SysClk_FRE(void);
    uint32 sysClk_FRE;
  	/* Get system clock frequency */
  	sysClk_FRE = Get_SysClk_FRE();
    UART4_MODE_CFG(uartx -> Mode);
    switch(uartx -> BRTGen)
    {
        case UART_BRT_TIM2:
        {
            AUXR &= 0xEF;  //Turn off timer2
            IE2 &= 0xFB;   //Ban timer2 interrupt
            S4CON &= 0xBF;  //Select timer2 as baud rate generator
			#if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				EAXFR_ENABLE();
				TM2PS = uartx -> BRTGenClkDiv;
				EAXFR_DISABLE();
			#endif	
            uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,
                                   uartx -> BaudRate);     
            AUXR |= 0X10;  //Turn on timer2
            break;
        }
        case UART_BRT_TIM4:
        {
            T4T3M &= 0x7F;  //Turn off timer3
            IE2 &= 0xBF;  //Ban timer4 interrupt
            S4CON |= 0x40;   //Select timer3 as baud rate generator
			#if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				EAXFR_ENABLE();
				TM4PS = uartx -> BRTGenClkDiv;
				EAXFR_DISABLE();
			#endif	
            UART4_TIMER4_BRTMODE_CFG(uartx -> BRTMode,
                                   uartx -> BaudRate);
            T4T3M |= 0x80; //Turn on timer4
            break;
        } 
        default: return FSC_FAIL;
     }
    S4CON = (S4CON & 0xDF) | (uartx -> MulitComm << 5);
    S4CON = (S4CON & 0xEF) | (uartx -> RxEnable << 4);
    UART4_CLEAR_BUSY_FLAG();
    return FSC_SUCCESS;
}

/**
  * @name    UART1_Send_Byte
  * @brief   UART1 Send byte function  
  * @param   dat: uint8_t
  * @return  None 
***/
void UART1_Send_Byte(uint8_t dat)
{
    while(UART1_GET_BUSY_FLAG());
    UART1_SET_BUSY_FLAG();
    SBUF = dat;
}

/**
  * @name    UART2_Send_Byte
  * @brief   UART2 Send byte function  
  * @param   dat: uint8_t
  * @return  None 
***/
void UART2_Send_Byte(uint8_t dat)
{
    while(UART2_GET_BUSY_FLAG());
    UART2_SET_BUSY_FLAG();
    S2BUF = dat;
}

/**
  * @name    UART3_Send_Byte
  * @brief   UART3 Send byte function  
  * @param   dat: uint8_t
  * @return  None 
***/
void UART3_Send_Byte(uint8_t dat)
{
    while(UART3_GET_BUSY_FLAG());
    UART3_SET_BUSY_FLAG();
    S3BUF = dat;
}

/**
  * @name    UART4_Send_Byte
  * @brief   UART4 Send byte function  
  * @param   dat: uint8_t
  * @return  None 
***/
void UART4_Send_Byte(uint8_t dat)
{
    while(UART4_GET_BUSY_FLAG());
    UART4_SET_BUSY_FLAG();
    S4BUF = dat;
}

/**
  * @name    UART1_Rev_Byte
  * @brief   UART1 get byte function  
  * @param   None
  * @return  receive data (uint8_t) 
***/
uint8_t UART1_Rev_Byte(void)
{
    while(UART1_GET_BUSY_FLAG());
    return SBUF;
}

/**
  * @name    UART2_Rev_Byte
  * @brief   UART2 get byte function  
  * @param   None
  * @return  receive data (uint8_t) 
***/
uint8_t UART2_Rev_Byte(void)
{
    while(UART2_GET_BUSY_FLAG());
    return S2BUF;
}

/**
  * @name    UART3_Rev_Byte
  * @brief   UART3 get byte function  
  * @param   None
  * @return  receive data (uint8_t) 
***/
uint8_t UART3_Rev_Byte(void)
{
    while(UART3_GET_BUSY_FLAG());
    return S3BUF;
}

/**
  * @name    UART4_Rev_Byte
  * @brief   UART4 get byte function  
  * @param   None
  * @return  receive data (uint8_t) 
***/
uint8_t UART4_Rev_Byte(void)
{
    while(UART4_GET_BUSY_FLAG());
    return S4BUF;
}

/**
  * @name    UART1_Send_String
  * @brief   UART1 send string function  
  * @param   *str  String first address (uint8_t)
  * @return  None 
***/
void UART1_Send_String(uint8_t *str)
{
   	while(*str)
  	{
        UART1_Send_Byte(*(str++));
    }
}

/**
  * @name    UART2_Send_String
  * @brief   UART2 send string function  
  * @param   *str  String first address (uint8_t)
  * @return  None 
***/
void UART2_Send_String(uint8_t *str)
{
  	while(*str)
  	{
        UART2_Send_Byte(*(str++));
  	}
}

/**
  * @name    UART3_Send_String
  * @brief   UART3 send string function  
  * @param   *str  String first address (uint8_t)
  * @return  None 
***/
void UART3_Send_String(uint8_t *str)
{
    while(*str)
  	{
        UART3_Send_Byte(*(str++));
    }
}

/**
  * @name    UART4_Send_String
  * @brief   UART4 send string function  
  * @param   *str  String first address (uint8_t)
  * @return  None 
***/
void UART4_Send_String(uint8_t *str)
{
  	while(*str)
  	{
        UART4_Send_Byte(*(str++));
  	}
}

/**
  * @name    UART1_Send_Array
  * @brief   UART1 send arry function  
  * @param   *str  Array first address (uint8_t) 
  * @param   len   Array length (uint16)
  * @return  None 
***/
void UART1_Send_Array(const uint8_t *str,uint16 len)
{
  	while(len--)
  	{
        UART1_Send_Byte(*(str++));
  	}
}

/**
  * @name    UART2_Send_Array
  * @brief   UART2 send arry function  
  * @param   *str  Array first address (uint8_t) 
  * @param   len   Array length (uint16)
  * @return  None 
***/
void UART2_Send_Array(const uint8_t *str,uint16 len)
{
    while(len--)
  	{
        UART2_Send_Byte(*(str++));
  	}
}

/**
  * @name    UART3_Send_Array
  * @brief   UART3 send arry function  
  * @param   *str  Array first address (uint8_t) 
  * @param   len   Array length (uint16)
  * @return  None 
***/
void UART3_Send_Array(const uint8_t *str,uint16 len)
{
  	while(len--)
    {
        UART3_Send_Byte(*(str++));
    } 
}

/**
  * @name    UART4_Send_Array
  * @brief   UART4 send arry function  
  * @param   *str  Array first address (uint8_t) 
  * @param   len   Array length (uint16)
  * @return  None 
***/
void UART4_Send_Array(const uint8_t *str,uint16 len)
{
  	while(len--)
  	{
        UART4_Send_Byte(*(str++));
  	}
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



