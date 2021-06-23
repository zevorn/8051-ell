/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_UART.c
  - Author        : zeweni
  - Update date   : 2020.04.27
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, zeweni (17870070675@163.com)

 * This file is part of 8051 ELL low-layer libraries.

 * 8051 ELL low-layer libraries is free software: you can redistribute 
 * it and/or modify it under the terms of the Apache-2.0 License.

 * 8051 ELL low-layer libraries is distributed in the hope that it will 
 * be useful,but WITHOUT ANY WARRANTY; without even the implied warranty 
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * Apache-2.0 License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_UART.h"

/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: UART mode configure define function      |
--------------------------------------------------------*/

/**
 * @brief   串口1工作模式选择宏函数，仅限本文件内调用。
 * @details Serial Port 1 mode of operation selects macro functions and is only called within this file.
**/
#define  UART1_MODE_CFG(mode)  do{SM0 = mode >> 1, SM1 = mode;}while(0)


/**
 * @brief   串口2工作模式选择宏函数，仅限本文件内调用。
 * @details Serial Port 2 mode of operation selects macro functions and is only called within this file.
**/
#define  UART2_MODE_CFG(mode)  do{S2CON = (S2CON & 0x3F)|((mode & 0x02) << 6);}while(0)


/**
 * @brief   串口3工作模式选择宏函数，仅限本文件内调用。
 * @details Serial Port 3 mode of operation selects macro functions and is only called within this file.
**/
#define  UART3_MODE_CFG(mode)  do{S3CON = (S3CON & 0x3F)|((mode & 0x02) << 6);}while(0)


/**
 * @brief   串口4工作模式选择宏函数，仅限本文件内调用。
 * @details Serial Port 4 mode of operation selects macro functions and is only called within this file.
**/
#define  UART4_MODE_CFG(mode)  do{S4CON = (S4CON & 0x3F)|((mode & 0x02) << 6);}while(0)

/*--------------------------------------------------------
| @Description: UART Baud rate configure define function |
--------------------------------------------------------*/

/**
 * @brief     串口1用定时器1做波特率发生器计算波特率宏函数，仅限本文件内调用。
 * @details   Serial port 1 uses timer 1 to do baud rate generator calculation baud rate macro function, 
 *            which is only called in this file.
 * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
 * @param[in] baudRate 波特率。Baud rate.
**/
#define UART1_TIMER1_BRTMODE_CFG(brtMode,baudRate)                                      \
do{                                                                                     \
    AUXR = (AUXR & 0xBF) | ( !brtMode << 6 );                                           \
    T1L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x40)) + 1 )));       \
    T1H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x40)) + 1 ))) >> 8;  \
}while(0)

#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)

    /**
     * @brief     串口用定时器2做波特率发生器计算波特率宏函数，仅限本文件内调用。
     * @details   Serial port uses timer 2 to do baud rate generator calculation baud rate macro function, 
     *            which is only called in this file.
     * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
     * @param[in] baudRate 波特率。Baud rate.
    **/
	#define uartx_TIMER2_BRTMODE_CFG(brtMode,baudRate)                                     \
    do{                                                                                    \
	    AUXR = (AUXR & 0xFB) | ( !brtMode << 2 );                                          \
	    T2L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 )));      \
	    T2H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 ))) >> 8; \
	}while(0)


    /**
     * @brief     串口3用定时器3做波特率发生器计算波特率宏函数，仅限本文件内调用。
     * @details   Serial port 3 uses timer 3 to do baud rate generator calculation baud rate macro function, 
     *            which is only called in this file.
     * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
     * @param[in] baudRate 波特率。Baud rate.
    **/
	#define UART3_TIMER3_BRTMODE_CFG(brtMode,baudRate)                                      \
    do{                                                                                     \
	    T4T3M = (T4T3M & 0xFD) | ( !brtMode << 1 );                                         \
	    T3L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 )));      \
	    T3H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 ))) >> 8; \
	}while(0)


    /**
     * @brief     串口4用定时器4做波特率发生器计算波特率宏函数，仅限本文件内调用。
     * @details   Serial port 4 uses timer 4 to do baud rate generator calculation baud rate macro function, 
     *            which is only called in this file.
     * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
     * @param[in] baudRate 波特率。Baud rate.
    **/
	#define UART4_TIMER4_BRTMODE_CFG(brtMode,baudRate)                                      \
    do{                                                                                     \
	    T4T3M = (T4T3M & 0xDF) | ( !brtMode << 5 );                                         \
	    T4L = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 )));      \
	    T4H = (65536UL - sysClk_FRE / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 ))) >> 8; \
	}while(0)
		
#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    /**
     * @brief     串口用定时器2做波特率发生器计算波特率宏函数，仅限本文件内调用。
     * @details   Serial port uses timer 2 to do baud rate generator calculation baud rate macro function, 
     *            which is only called in this file.
     * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
     * @param[in] baudRate 波特率。Baud rate.
    **/	
	#define uartx_TIMER2_BRTMODE_CFG(brtMode,baudRate)                                                      \
    do{                                                                                                     \
	    AUXR = (AUXR & 0xFB) | ( !brtMode << 2 );                                                           \
	    T2L = (65536UL - (sysClk_FRE / (TM2PS + 1) ) / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 )));      \
	    T2H = (65536UL - (sysClk_FRE / (TM2PS + 1) ) / (baudRate * 4 * (11 * (!(AUXR & 0x04)) + 1 ))) >> 8; \
	}while(0)


    /**
     * @brief     串口3用定时器3做波特率发生器计算波特率宏函数，仅限本文件内调用。
     * @details   Serial port 3 uses timer 3 to do baud rate generator calculation baud rate macro function, 
     *            which is only called in this file.
     * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
     * @param[in] baudRate 波特率。Baud rate.
    **/
	#define UART3_TIMER3_BRTMODE_CFG(brtMode,baudRate)                                                       \
    do{                                                                                                      \
	    T4T3M = (T4T3M & 0xFD) | ( !brtMode << 1 );                                                          \
	    T3L = (65536UL - (sysClk_FRE / (TM3PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 )));      \
	    T3H = (65536UL - (sysClk_FRE / (TM3PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x02)) + 1 ))) >> 8; \
	}while(0)


    /**
     * @brief     串口4用定时器4做波特率发生器计算波特率宏函数，仅限本文件内调用。
     * @details   Serial port 4 uses timer 4 to do baud rate generator calculation baud rate macro function, 
     *            which is only called in this file.
     * @param[in] brtMode  波特率发生器模式。Baud rate generator mode.
     * @param[in] baudRate 波特率。Baud rate.
    **/
	#define UART4_TIMER4_BRTMODE_CFG(brtMode,baudRate)                                                        \
    do{                                                                                                       \
	    T4T3M = (T4T3M & 0xDF) | ( !brtMode << 5 );                                                           \
	    T4L = (65536UL - (sysClk_FRE / (TM4PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 )));       \
	    T4H = (65536UL - (sysClk_FRE / (TM4PS + 1) ) / (baudRate * 4 * (11 * (!(T4T3M & 0x20)) + 1 ))) >> 8;  \
	}while(0)
		
#endif

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if ( PER_LIB_UART_CTRL == 1)

/**
 * @brief   串口忙标志位，这是ELL库自定义从防止多串口冲突的变量。
 * @details Serial port busy flag, this is a variable customized 
 *          by the ELL library to prevent multiple serial port conflicts.
**/
uint8_t UART_BUSY_FLAG = 0; //Busy flag of receive

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

	#if (PER_LIB_UART_INIT_CTRL == 1)
	
		/**
		 * @brief     串口1初始化函数。 
		 * @details   UART1 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART1_Init(const UART_InitType* uartx)
		{
			extern uint32_t Get_SysClk_FRE(void);
			uint32_t sysClk_FRE;
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
				  
				#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
				  
					uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate); 
				  
				#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				  
					EAXFR_ENABLE();
					TM2PS = uartx -> BRTGenClkDiv;
					uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate);     
					EAXFR_DISABLE();
				  
				#endif	
		  
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
		 * @brief     串口2初始化函数。 
		 * @details   UART2 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART2_Init(const UART_InitType* uartx)
		{
			extern uint32_t Get_SysClk_FRE(void);
			uint32_t sysClk_FRE;
			/* Get system clock frequency */
			sysClk_FRE = Get_SysClk_FRE();
			UART2_MODE_CFG(uartx -> Mode);
			if(uartx -> BRTGen == UART_BRT_TIM2)
			{
				AUXR &= 0xEF;  //Turn off timer2
				IE2 &= 0xFB;   //Ban timer2 interrupt
				
				#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
				  
					uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate); 
				  
				#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				  
					EAXFR_ENABLE();
					TM2PS = uartx -> BRTGenClkDiv;
					uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate);     
					EAXFR_DISABLE();
				  
				#endif	
		  
				AUXR |= 0X10;  //Turn on timer2
			}
			else return FSC_FAIL;
			S2CON = (S2CON & 0xDF) | (uartx -> MulitComm << 5);
			S2CON = (S2CON & 0xEF) | (uartx -> RxEnable << 4);
			UART2_CLEAR_BUSY_FLAG();
			return FSC_SUCCESS;
		}


		/**
		 * @brief     串口3初始化函数。 
		 * @details   UART3 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART3_Init(const UART_InitType* uartx)
		{
			extern uint32_t Get_SysClk_FRE(void);
			uint32_t sysClk_FRE;
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
					
					#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
					  
						uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate); 
					  
					#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
					  
						EAXFR_ENABLE();
						TM2PS = uartx -> BRTGenClkDiv;
						uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate);     
						EAXFR_DISABLE();
					  
					#endif	
		  
					AUXR |= 0X10;  //Turn on timer2
					break;
				}
				case UART_BRT_TIM3:
				{
					T4T3M &= 0xF7;  //Turn off timer3
					IE2 &= 0xDF;  //Ban timer3 interrupt
					S3CON |= 0x40;    //Select timer3 as baud rate generator
					
					#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
					  
						UART3_TIMER3_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate); 
					  
					#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
					  
						EAXFR_ENABLE();
						TM3PS = uartx -> BRTGenClkDiv;
						UART3_TIMER3_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate);     
						EAXFR_DISABLE();
					  
					#endif	
		  
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
		 * @brief     串口4初始化函数。 
		 * @details   UART4 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART4_Init(const UART_InitType* uartx)
		{
			extern uint32_t Get_SysClk_FRE(void);
			uint32_t sysClk_FRE;
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
					
					#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
					  
						uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate); 
					  
					#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
					  
						EAXFR_ENABLE();
						TM2PS = uartx -> BRTGenClkDiv;
						uartx_TIMER2_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate);     
						EAXFR_DISABLE();
					  
					#endif	
		  
					AUXR |= 0X10;  //Turn on timer2
					break;
				}
				case UART_BRT_TIM4:
				{
					T4T3M &= 0x7F;  //Turn off timer3
					IE2 &= 0xBF;  //Ban timer4 interrupt
					S4CON |= 0x40;   //Select timer3 as baud rate generator
					
					#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
					  
						UART4_TIMER4_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate); 
					  
					#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
					  
						EAXFR_ENABLE();
						TM4PS = uartx -> BRTGenClkDiv;
						UART4_TIMER4_BRTMODE_CFG(uartx -> BRTMode,uartx -> BaudRate);     
						EAXFR_DISABLE();
					  
					#endif	
		  
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

	#endif
		
	#if (PER_LIB_UART_NVIC_CTRL == 1)

		/**
		 * @brief     串口1中断初始化函数。
		 * @details   UART1 NVIC function.
		 * @param[in] pri 中断优先级。interrupt pri.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_UART1_Init(NVICPri_Type pri,BOOL run)
		{
			ES = run;
			NVIC_UART1_PRI(pri); 
			return FSC_SUCCESS;
		}


		/**
		 * @brief     串口2中断初始化函数。
		 * @details   UART2 NVIC function.
		 * @param[in] pri 中断优先级。interrupt pri.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_UART2_Init(NVICPri_Type pri,BOOL run)
		{
			IE2 = (IE2 & 0xFE) | (run);
			NVIC_UART2_PRI(pri);
			return FSC_SUCCESS;
		}


		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)

		/**
		 * @brief     串口3中断初始化函数。
		 * @details   UART3 NVIC function.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_UART3_Init(BOOL run)
		{
			IE2 = (IE2 & 0xF7) | (run << 3);
			return FSC_SUCCESS;
		}


		/**
		 * @brief     串口4中断初始化函数。
		 * @details   UART4 NVIC function.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_UART4_Init(BOOL run)
		{
			IE2 = (IE2 & 0xEF) | (run << 4);
			return FSC_SUCCESS;
		}


		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

			/**
			 * @brief     串口3中断初始化函数。
			 * @details   UART3 NVIC function.
			 * @param[in] pri 中断优先级。interrupt pri.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_UART3_Init(NVICPri_Type pri,BOOL run)
			{
				IE2 = (IE2 & 0xF7) | (run << 3);
				NVIC_UART3_PRI(pri);
				return FSC_SUCCESS;
			}

			/**
			 * @brief     串口4中断初始化函数。
			 * @details   UART4 NVIC function.
			 * @param[in] pri 中断优先级。interrupt pri.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_UART4_Init(NVICPri_Type pri,BOOL run)
			{
				IE2 = (IE2 & 0xEF) | (run << 4);
				NVIC_UART4_PRI(pri);
				return FSC_SUCCESS;
			}

		#endif

	#endif

	#if (PER_LIB_UART_WORK_CTRL == 1)
			
		/**
		 * @brief     串口1切换复用IO函数。
		 * @details   UART1 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART1_SWPort(GPIOSWPort_Type port)
		{
			P_SW1 = (P_SW1 & 0x3F) | (port << 6);
			return FSC_SUCCESS;
		}


		/**
		 * @brief     串口2切换复用IO函数。
		 * @details   UART2 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART2_SWPort(GPIOSWPort_Type port)
		{
			if(port < SW_Port3)
			{
				P_SW2 = (P_SW2 & 0xFE) | (port);
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}


		/**
		 * @brief     串口3切换复用IO函数。
		 * @details   UART3 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART3_SWPort(GPIOSWPort_Type port)
		{
			if(port < SW_Port3)
			{
				P_SW2 = (P_SW2 & 0xFD) | (port << 1);
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}


		/**
		 * @brief     串口4切换复用IO函数。
		 * @details   UART4 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART4_SWPort(GPIOSWPort_Type port)
		{
			if(port < SW_Port3)
			{
				P_SW2 = (P_SW2 & 0xFB) | (port << 2);
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}


		/**
		 * @brief      串口1发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 1 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART1_Isr_Send_Byte(uint8_t dat)
		{
			while(UART1_GET_BUSY_FLAG());
			UART1_SET_BUSY_FLAG();
			SBUF = dat;
		}


		/**
		 * @brief      串口2发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 2 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART2_Isr_Send_Byte(uint8_t dat)
		{
			while(UART2_GET_BUSY_FLAG());
			UART2_SET_BUSY_FLAG();
			S2BUF = dat;
		}


		/**
		 * @brief      串口3发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 3 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART3_Isr_Send_Byte(uint8_t dat)
		{
			while(UART3_GET_BUSY_FLAG());
			UART3_SET_BUSY_FLAG();
			S3BUF = dat;
		}


		/**
		 * @brief      串口4发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 4 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART4_Isr_Send_Byte(uint8_t dat)
		{
			while(UART4_GET_BUSY_FLAG());
			UART4_SET_BUSY_FLAG();
			S4BUF = dat;
		}
        

		/**
		 * @brief      串口1发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 1 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART1_Isr_Send_String(const uint8_t *str)
		{
			while(*str != '\0')
			{
				UART1_Isr_Send_Byte(*(str++));
			}
		}


		/**
		 * @brief      串口2发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 2 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART2_Isr_Send_String(const uint8_t *str)
		{
			while(*str != '\0')
			{
				UART2_Isr_Send_Byte(*(str++));
			}
		}


		/**
		 * @brief      串口3发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 3 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART3_Isr_Send_String(const uint8_t* str)
		{
			while(*str != '\0')
			{
				UART3_Isr_Send_Byte(*(str++));
			}
		}


		/**
		 * @brief      串口4发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 4 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART4_Isr_Send_String(const uint8_t *str)
		{
			while(*str != '\0')
			{
				UART4_Isr_Send_Byte(*(str++));
			}
		}


		/**
		 * @brief      串口1发送一个数组函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 1 sends a arry function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  arry 要发送的数组地址。The address of the array to be sent.
		 * @param[in]  len  要发送的数组长度。The length of the array to be sent.
		 * @return     None. 
		**/
		void UART1_Isr_Send_Array(const uint8_t *arry,uint16_t len)
		{
			while(len--)
			{
				UART1_Isr_Send_Byte(*(arry++));
			}
		}


		/**
		 * @brief      串口2发送一个数组函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 2 sends a arry function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  arry 要发送的数组地址。The address of the array to be sent.
		 * @param[in]  len  要发送的数组长度。The length of the array to be sent.
		 * @return     None. 
		**/
		void UART2_Isr_Send_Array(const uint8_t *arry,uint16_t len)
		{
			while(len--)
			{
				UART2_Isr_Send_Byte(*(arry++));
			}
		}


		/**
		 * @brief      串口3发送一个数组函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 3 sends a arry function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  arry 要发送的数组地址。The address of the array to be sent.
		 * @param[in]  len  要发送的数组长度。The length of the array to be sent.
		 * @return     None. 
		**/
		void UART3_Isr_Send_Array(const uint8_t *arry,uint16_t len)
		{
			while(len--)
			{
				UART3_Isr_Send_Byte(*(arry++));
			}
		}


		/**
		 * @brief      串口4发送一个数组函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 4 sends a arry function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  arry 要发送的数组地址。The address of the array to be sent.
		 * @param[in]  len  要发送的数组长度。The length of the array to be sent.
		 * @return     None. 
		**/
		void UART4_Isr_Send_Array(const uint8_t *arry,uint16_t len)
		{
			while(len--)
			{
				UART4_Isr_Send_Byte(*(arry++));
			}
		}
		
	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



