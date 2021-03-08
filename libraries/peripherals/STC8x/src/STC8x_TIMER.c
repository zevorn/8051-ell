/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TIMER.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_TIMER.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: TIMER mode configure define function     |
--------------------------------------------------------*/

#define TIMER0_MODE_CFG(mode)  TMOD = (TMOD & 0xFC) | (mode)
#define TIMER1_MODE_CFG(mode)  TMOD = (TMOD & 0xCF) | (mode << 4)

/*--------------------------------------------------------
| @Description: TIMER clk mode configure define function |
--------------------------------------------------------*/

#define  TIMER0_TCY_CFG(tCycle) do{ AUXR  = (AUXR  & 0x7F) | ( !tCycle << 7 ); }while(0)
#define  TIMER1_TCY_CFG(tCycle) do{ AUXR  = (AUXR  & 0xBF) | ( !tCycle << 6 ); }while(0)
#define  TIMER2_TCY_CFG(tCycle) do{ AUXR  = (AUXR  & 0xFB) | ( !tCycle << 2 ); }while(0)
#define  TIMER3_TCY_CFG(tCycle) do{ T4T3M = (T4T3M & 0xFD) | ( !tCycle << 1 ); }while(0)
#define  TIMER4_TCY_CFG(tCycle) do{ T4T3M = (T4T3M & 0xDF) | ( !tCycle << 5 ); }while(0)

/*--------------------------------------------------------
| @Description: TIMER value configure define function    |
--------------------------------------------------------*/

#define TIMER0_VALUE_CFG(value) do{ \
value = (65536UL - (sysClk_FRE / (1000000UL /  value \
	         * (11 * (!(AUXR & 0x80)) + 1)) ) );}while(0)

#define TIMER1_VALUE_CFG(value) do{ \
value = (65536UL - (sysClk_FRE / (1000000UL /  value \
	         * (11 * (!(AUXR & 0x40)) + 1)) ) );}while(0)

#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
    
    #define TIMER2_VALUE_CFG(value) do{ \
    value = (65536UL - (sysClk_FRE / (1000000UL /  value \
    	         * (11 * (!(AUXR & 0x04)) + 1)) ) );}while(0)

    #define TIMER3_VALUE_CFG(value) do{ \
    value = (65536UL - (sysClk_FRE / (1000000UL /  value \
    	        * (11 * (!(T4T3M & 0x02)) + 1)) ) );}while(0)

    #define TIMER4_VALUE_CFG(value) do{ \
    value = (65536UL - (sysClk_FRE / (1000000UL /  value \
	          * (11 * (!(T4T3M & 0x20)) + 1)) ) );}while(0)	
              
#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    #define TIMER2_VALUE_CFG(value) do{ \
    value = (65536UL - ( (sysClk_FRE / (TM2PS + 1) ) / (1000000UL /  value \
    	         * (11 * (!(AUXR & 0x04)) + 1)) ) );}while(0)

    #define TIMER3_VALUE_CFG(value) do{ \
    value = (65536UL - ( (sysClk_FRE / (TM3PS + 1) ) / (1000000UL /  value \
    	        * (11 * (!(T4T3M & 0x02)) + 1)) ) );}while(0)

    #define TIMER4_VALUE_CFG(value) do{ \
    value = (65536UL - ( (sysClk_FRE / (TM2PS + 1) ) / (1000000UL /  value \
	          * (11 * (!(T4T3M & 0x20)) + 1)) ) );}while(0)	
    
#endif             
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
/**
  * @name    TIMER0_Init
  * @brief   TIMER0 peripheral init function 
  * @param   *timerx: TIMER_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE TIMER0_Init(const TIMER_InitType *timerx)
{
	extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
	TR0 = 0; //Turn off Timer0
	TMOD = (TMOD & 0xFB) | (timerx -> Type << 2);
	TIMER0_MODE_CFG(timerx -> Mode);
	TIMER0_TCY_CFG(timerx -> TCycle);
	TIMER0_VALUE_CFG(timerx -> Value);
	if(timerx -> Mode == TIMER_8BitAutoReload) T0L = (uint8_t)(timerx -> Value), T0H = (uint8_t)(timerx -> Value); 
	else                                       T0L = (uint8_t)(timerx -> Value), T0H = (uint8_t)(timerx -> Value >> 8);
	INTCLKO = (INTCLKO & 0xFE) | (timerx -> ClkOut);
	TR0 = timerx -> Run;
	return FSC_SUCCESS;
}

/**
  * @name    TIMER1_Init
  * @brief   TIMER1 peripheral init function 
  * @param   *timerx: TIMER_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE TIMER1_Init(const TIMER_InitType *timerx)
{
	extern uint32_t Get_SysClk_FRE(void);
	uint32_t sysClk_FRE;
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
	TR1 = 0; //Turn off Timer1
	if(timerx -> Mode != TIMER_16BitAutoReloadNoMask) TIMER1_MODE_CFG(timerx -> Mode);
	else return FSC_FAIL;
	TMOD = (TMOD & 0xBF) | (timerx -> Type << 6);
	TIMER1_TCY_CFG(timerx -> TCycle);
	TIMER1_VALUE_CFG(timerx -> Value);	
	if(timerx -> Mode == TIMER_8BitAutoReload) T1L = (uint8_t)(timerx -> Value), T1H = (uint8_t)(timerx -> Value); 
	else                                       T1L = (uint8_t)(timerx -> Value), T1H = (uint8_t)(timerx -> Value >> 8);
	INTCLKO = (INTCLKO & 0xFD) | (timerx -> ClkOut << 1);
	TF1 = 0; //Clear Flag
	TR1 = timerx -> Run; 
	return FSC_SUCCESS;		
}

/**
  * @name    TIMER2_Init
  * @brief   TIMER2 peripheral init function 
  * @param   *timerx: TIMER_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE TIMER2_Init(const TIMER_InitType *timerx)
{
	extern uint32_t Get_SysClk_FRE(void);
	uint32_t sysClk_FRE;
    #if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
        EAXFR_ENABLE();
        TM2PS = timerx -> SysClkDiv;
        EAXFR_DISABLE();
    #endif
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
	AUXR &= 0xEF; //Turn off timer2
	AUXR = (AUXR & 0xF7) | (timerx -> Type << 3);
	TIMER2_TCY_CFG(timerx -> TCycle);
	TIMER2_VALUE_CFG(timerx -> Value);	
	T2L = (uint8_t)(timerx -> Value);
	T2H = (uint8_t)(timerx -> Value >> 8);
	INTCLKO = (INTCLKO & 0xFB) | (timerx -> ClkOut << 2);	
	AUXR = (AUXR & 0xEF) | (timerx -> Run << 4);  
	return FSC_SUCCESS;	
}

/**
  * @name    TIMER3_Init
  * @brief   TIMER3 peripheral init function 
  * @param   *timerx: TIMER_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE TIMER3_Init(const TIMER_InitType *timerx)
{
	extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    #if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
        EAXFR_ENABLE();
        TM3PS = timerx -> SysClkDiv;
        EAXFR_DISABLE();
    #endif
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
	T4T3M &= 0XF7;//Turn off timer3
	T4T3M = (T4T3M & 0xFB) | (timerx -> Type << 2);
	TIMER3_TCY_CFG(timerx -> TCycle);
	TIMER3_VALUE_CFG(timerx -> Value);
	T3L = (uint8_t)(timerx -> Value);
	T3H = (uint8_t)(timerx -> Value >> 8);
	T4T3M = (T4T3M & 0xFE) | (timerx -> ClkOut);
	T4T3M = (T4T3M & 0xF7) | (timerx -> Run << 3);		
	return FSC_SUCCESS;	
}

/**
  * @name    TIMER4_Init
  * @brief   TIMER4 peripheral init function 
  * @param   *timerx: TIMER_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE TIMER4_Init(const TIMER_InitType *timerx)
{
	extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    #if  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
        EAXFR_ENABLE();
        TM4PS = timerx -> SysClkDiv;
        EAXFR_DISABLE();
    #endif
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
	T4T3M &= 0X7F; //Turn off timer4
	T4T3M = (T4T3M & 0xBF) | (timerx -> Type << 6);
	TIMER4_TCY_CFG(timerx -> TCycle);
	TIMER4_VALUE_CFG(timerx -> Value);	
	T4L = (uint8_t)(timerx -> Value);
	T4H = (uint8_t)(timerx -> Value >> 8);
	T4T3M = (T4T3M & 0xEF) | (timerx -> ClkOut << 4);
	T4T3M = (T4T3M & 0x7F) | (timerx -> Run << 7);	
	return FSC_SUCCESS;		
}

/**
  * @name    TIMER5_Wake_Up_Power
  * @brief   TIMER5 peripheral init function 
  * @param   *timerx: TIMER_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE TIMER5_Wake_Up_Power(uint16_t value,FUNSTATE run)
{
	uint16_t fwt;
	fwt = (uint16_t)((FWTH << 8) | FWTL);    //Calculate the clock frequency 
	value = (uint16_t)((fwt * (uint32_t) value) / 16000000UL);//Count count times
	WKTCH = (uint8_t)((value - 1) >> 8);
	WKTCL = (uint8_t)( value - 1);
	WKTCH = (WKTCH & 0x7F) | (run << 7);
	return FSC_SUCCESS;
}


/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



