/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_UART.h
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
#ifndef __STC8x_UART_H_
#define __STC8x_UART_H_

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"
#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#if    (PER_LIB_MCU_MUODEL == STC8Ax)
    #include "STC8Ax_REG.h"  
#elif  (PER_LIB_MCU_MUODEL == STC8Cx)
    #include "STC8Cx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Fx)
    #include "STC8Fx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Gx)
    #include "STC8Gx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Hx)
    #include "STC8Hx_REG.h"
#endif
/*--------------------------------------------------------
| @Description: ELL library core                         |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#ifndef PER_LIB_MCU_MUODEL
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif


#ifndef PER_LIB_UART_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_UART_CTRL 1
#endif


#ifndef PER_LIB_UART_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_UART_INIT_CTRL 1
#endif


#ifndef PER_LIB_UART_NVIC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_UART_NVIC_CTRL 1
#endif


#ifndef PER_LIB_UART_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_UART_WORK_CTRL 1
#endif


/**
 * @brief     串口工作模式枚举体。
 * @details   UART working mode enum. 
**/
typedef enum
{
	UART_SyncShift       = 0x00, /*!< 同步移位串行工作模式。Synchronous shift serial.*/
	UART_8bit_BRTx       = 0x01, /*!< 8位可变波特率工作模式。8-bit data, variable baud rate.*/
	UART_9bit_Fixed_BRTx = 0x02, /*!< 9位固定波特率工作模式。9-bit data, fixed baud rate. */
	UART_9bit_BRTx       = 0x03  /*!< 9位可变波特率工作模式。9-bit data, variable baud rate.*/
} UARTMode_Type;


/**
 * @brief     串口波特率发生器枚举体。
 * @details   UART Baud rate generatorenum. 
**/
typedef enum
{
	UART_BRT_TIM1 = 0x00,    /*!< 定时器1做波特率发生器。Timer 1 as baud rate generator.*/
	UART_BRT_TIM2 = 0x01,	 /*!< 定时器2做波特率发生器。Timer 2 as baud rate generator.*/
	UART_BRT_TIM3 = 0x02,	 /*!< 定时器3做波特率发生器。Timer 3 as baud rate generator.*/
	UART_BRT_TIM4 = 0x03 	 /*!< 定时器4做波特率发生器。Timer 4 as baud rate generator.*/
} UART_BRTGen_Type;


/**
 * @brief     串口波特率发生器指令周期枚举体。
 * @details   UART Baud rate Clock mode enum. 
**/
typedef enum
{
    UART_BRT_1T  = 0x00,  /*!< 1T指令周期。 CPU clock without frequency division.*/
	UART_BRT_12T = 0x01   /*!< 12T指令周期。CPU clock 12 frequency division.*/
}	UART_BRTMode_Type;


/**
 * @brief   串口初始化结构体句柄，初始化时请定义该句柄，并用其地址来传参。
 * @details The uart initializes the structure handle. When initializing, 
 *          please define the handle and use its address to pass parameters.
 * @note    关于BRTGenClkDiv这个参数，在系统时钟发生改变以后，需要你手动重新更改，
 *          以匹配你需要的定时时间，它不可以向BaudRate参数一样可以自己做修正。
**/
typedef struct 
{
	UARTMode_Type Mode;       /*!< 1T指令周期。 Working mode. */
	UART_BRTGen_Type BRTGen;  /*!< 1T指令周期。 Baud rate generator. */
	#if  (PER_LIB_MCU_MUODEL == STC8Cx ||PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
		uint8_t BRTGenClkDiv;  /*!< 1T指令周期。 Baud rate generator clock division. */
	#endif
	UART_BRTMode_Type BRTMode;  /*!< 波特率发生器时钟模式。 Baud rate generator clock mode. */
	BOOL BRTDouble;            /*!< 波特率加倍控制位。 Baud rate double control bit. */
	uint32_t BaudRate;         /*!< 波特率值。 Baud rate value. */
	BOOL MulitComm;             /*!< 多机通信控制位。Multi-machine communication control bit. */
	BOOL Relay;                /*!< 中继广播控制位。 Relay broadcasting control bit. */
	BOOL RxEnable;             /*!< 串口接收控制位。 Serial port receive control bit. */
} UART_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if ( PER_LIB_UART_CTRL == 1)

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
		FSCSTATE UART1_Init(const UART_InitType *uartx);


		/**
		 * @brief     串口2初始化函数。 
		 * @details   UART2 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART2_Init(const UART_InitType *uartx);


		/**
		 * @brief     串口3初始化函数。 
		 * @details   UART3 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART3_Init(const UART_InitType *uartx);


		/**
		 * @brief     串口4初始化函数。 
		 * @details   UART4 peripheral init function. 
		 * @param[in] uartx  串口初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
		 *                    The uart initializes the structure handle. When initializing, 
		 *                    please define the handle and pass its address to the parameter.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE UART4_Init(const UART_InitType *uartx);
		
	#endif
	
	#if (PER_LIB_UART_NVIC_CTRL == 1)

		/**
		 * @brief   串口1获取接收标志位宏函数。
		 * @details Serial port 1 gets received flag macro function.
		**/
		#define    UART1_GET_RX_FLAG()    (SCON  & 0x01)


		/**
		 * @brief   串口2获取接收标志位宏函数。
		 * @details Serial port 2 gets received flag macro function.
		**/
		#define    UART2_GET_RX_FLAG()    (S2CON & 0x01)


		/**
		 * @brief   串口3获取接收标志位宏函数。
		 * @details Serial port 3 gets received flag macro function.
		**/
		#define    UART3_GET_RX_FLAG()    (S3CON & 0x01)


		/**
		 * @brief   串口4获取接收标志位宏函数。
		 * @details Serial port 4 gets received flag macro function.
		**/
		#define    UART4_GET_RX_FLAG()    (S4CON & 0x01)


		/**
		 * @brief   串口1清除接收标志位宏函数。
		 * @details Serial port 1 clears received flag macro function.
		**/
		#define	   UART1_CLEAR_RX_FLAG()  do{SCON  &= 0xFE;}while(0)


		/**
		 * @brief   串口2清除接收标志位宏函数。
		 * @details Serial port 2 clears received flag macro function.
		**/
		#define	   UART2_CLEAR_RX_FLAG()  do{S2CON &= 0xFE;}while(0)


		/**
		 * @brief   串口3清除接收标志位宏函数。
		 * @details Serial port 3 clears received flag macro function.
		**/
		#define	   UART3_CLEAR_RX_FLAG()  do{S3CON &= 0xFE;}while(0)


		/**
		 * @brief   串口4清除接收标志位宏函数。
		 * @details Serial port 4 clears received flag macro function.
		**/
		#define	   UART4_CLEAR_RX_FLAG()  do{S4CON &= 0xFE;}while(0)
							

		/**
		 * @brief   串口1获取发送标志位宏函数。
		 * @details Serial port 1 gets sending flag macro function.
		**/
		#define    UART1_GET_TX_FLAG()    (SCON  & 0x02)


		/**
		 * @brief   串口2获取发送标志位宏函数。
		 * @details Serial port 2 gets sending flag macro function.
		**/
		#define    UART2_GET_TX_FLAG()    (S2CON & 0x02)


		/**
		 * @brief   串口3获取发送标志位宏函数。
		 * @details Serial port 3 gets sending flag macro function.
		**/
		#define    UART3_GET_TX_FLAG()    (S3CON & 0x02)


		/**
		 * @brief   串口4获取发送标志位宏函数。
		 * @details Serial port 4 gets sending flag macro function.
		**/
		#define    UART4_GET_TX_FLAG()    (S4CON & 0x02)


		/**
		 * @brief   串口1清除发送标志位宏函数。
		 * @details Serial port 1 clears the sending flag bit macro function.
		**/
		#define	   UART1_CLEAR_TX_FLAG()  do{SCON  &= 0xFD;}while(0)


		/**
		 * @brief   串口2清除发送标志位宏函数。
		 * @details Serial port 2 clears the sending flag bit macro function.
		**/
		#define	   UART2_CLEAR_TX_FLAG()  do{S2CON &= 0xFD;}while(0)


		/**
		 * @brief   串口3清除发送标志位宏函数。
		 * @details Serial port 3 clears the sending flag bit macro function.
		**/
		#define	   UART3_CLEAR_TX_FLAG()  do{S3CON &= 0xFD;}while(0)


		/**
		 * @brief   串口4清除发送标志位宏函数。
		 * @details Serial port 4 clears the sending flag bit macro function.
		**/
		#define	   UART4_CLEAR_TX_FLAG()  do{S4CON &= 0xFD;}while(0)


		/**
		 * @brief     串口1中断初始化函数。
		 * @details   UART1 NVIC function.
		 * @param[in] pri 中断优先级。interrupt pri.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_UART1_Init(NVICPri_Type pri,BOOL run);


		/**
		 * @brief     串口2中断初始化函数。
		 * @details   UART2 NVIC function.
		 * @param[in] pri 中断优先级。interrupt pri.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_UART2_Init(NVICPri_Type pri,BOOL run);


		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			
			/**
			 * @brief     串口3中断初始化函数。
			 * @details   UART3 NVIC function.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_UART3_Init(BOOL run);
			
			/**
			 * @brief     串口4中断初始化函数。
			 * @details   UART4 NVIC function.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_UART4_Init(BOOL run);

		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

			/**
			 * @brief     串口3中断初始化函数。
			 * @details   UART3 NVIC function.
			 * @param[in] pri 中断优先级。interrupt pri.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_UART3_Init(NVICPri_Type pri,BOOL run);
			
			
			/**
			 * @brief     串口4中断初始化函数。
			 * @details   UART4 NVIC function.
			 * @param[in] pri 中断优先级。interrupt pri.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_UART4_Init(NVICPri_Type pri,BOOL run);

		#endif


		/**
		 * @brief     UART1中断开关控制宏函数。
		 * @details   UART1 interrupt switch control macro function.
		 * @param[in] run  使能控制位。Enable control bit.
		**/
		#define    NVIC_UART1_CTRL(run)     do{ ES = run; }while(0)


		/**
		 * @brief     UART2中断开关控制宏函数。
		 * @details   UART2 interrupt switch control macro function.
		 * @param[in] run  使能控制位。Enable control bit.
		**/
		#define    NVIC_UART2_CTRL(run)     do{ IE2 = (IE2 & 0xFE) | (run); }while(0)


		/**
		 * @brief     UART3中断开关控制宏函数。
		 * @details   UART3 interrupt switch control macro function.
		 * @param[in] run  使能控制位。Enable control bit.
		**/
		#define    NVIC_UART3_CTRL(run)     do{ IE2 = (IE2 & 0xF7) | (run << 3); }while(0)


		/**
		 * @brief     UART4中断开关控制宏函数。
		 * @details   UART4 interrupt switch control macro function.
		 * @param[in] run  使能控制位。Enable control bit.
		**/
		#define    NVIC_UART4_CTRL(run)     do{ IE2 = (IE2 & 0xEF) | (run << 4); }while(0)


		/**
		 * @brief      UART1选择中断优先级宏函数。
		 * @details    UART1 select interrupt pri macro function.
		 * @param[in]  pri 中断优先级。 pri of interrupt.
		**/
		#define NVIC_UART1_PRI(pri)                   \
		do{                                           \
			IPH = (IPH & 0xEF) | ((pri & 0x02) << 3); \
			IP  = (IP  & 0xEF) | ((pri & 0x01) << 4); \
		}while(0)


		/**
		 * @brief      UART2选择中断优先级宏函数。
		 * @details    UART2 select interrupt pri macro function.
		 * @param[in]  pri 中断优先级。 pri of interrupt.
		**/
		#define NVIC_UART2_PRI(pri)                     \
		do{                                             \
			IP2H = (IP2H & 0xFE) | ((pri & 0x02) >> 1); \
			IP2  = (IP2  & 0xFE) | (pri & 0x01);        \
		}while(0)

		#if (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

			/**
			 * @brief      UART3选择中断优先级宏函数。
			 * @details    UART3 select interrupt pri macro function.
			 * @param[in]  pri 中断优先级。 pri of interrupt.
			**/
			#define NVIC_UART3_PRI(pri)                     \
			do{                                             \
				IP3H = (IP3H & 0xFE) | ((pri & 0x02) >> 1); \
				IP3  = (IP3  & 0xFE) | (pri & 0x01);        \
			}while(0)

			
			/**
			 * @brief      UART4选择中断优先级宏函数。
			 * @details    UART4 select interrupt pri macro function.
			 * @param[in]  pri 中断优先级。 pri of interrupt.
			**/
			#define NVIC_UART4_PRI(pri)                    \
			do{                                            \
				IP3H = (IP3H & 0xFD) | (pri & 0x02);       \
				IP3  = (IP3  & 0xFD) | (pri & 0x01) << 1;  \
			}while(0)
			
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
		FSCSTATE GPIO_UART1_SWPort(GPIOSWPort_Type port);
			
			
		/**
		 * @brief     串口2切换复用IO函数。
		 * @details   UART2 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART2_SWPort(GPIOSWPort_Type port);


		/**
		 * @brief     串口3切换复用IO函数。
		 * @details   UART3 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART3_SWPort(GPIOSWPort_Type port);


		/**
		 * @brief     串口4切换复用IO函数。
		 * @details   UART4 switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_UART4_SWPort(GPIOSWPort_Type port);


		/**
		 * @brief   串口忙标志位，这是ELL库自定义从防止多串口冲突的变量。
		 * @details Serial port busy flag, this is a variable customized 
		 *          by the ELL library to prevent multiple serial port conflicts.
		**/
		extern uint8_t UART_BUSY_FLAG;		


		/**
		 * @brief   串口1获取忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 1 gets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		 * @return  [bit] 忙标志位。Busy flag.
		**/
		#define      UART1_GET_BUSY_FLAG()    (UART_BUSY_FLAG & 0x01)


		/**
		 * @brief   串口2获取忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 2 gets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		 * @return  [bit] 忙标志位。Busy flag.
		**/
		#define      UART2_GET_BUSY_FLAG()    (UART_BUSY_FLAG & 0x02)


		/**
		 * @brief   串口3获取忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 3 gets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		 * @return  [bit] 忙标志位。Busy flag.
		**/
		#define      UART3_GET_BUSY_FLAG()    (UART_BUSY_FLAG & 0x04)


		/**
		 * @brief   串口4获取忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 4 gets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		 * @return  [bit] 忙标志位。Busy flag.
		**/
		#define      UART4_GET_BUSY_FLAG()    (UART_BUSY_FLAG & 0x08)

		/**
		 * @brief   串口1设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 1 sets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define      UART1_SET_BUSY_FLAG()    do{UART_BUSY_FLAG |= 0x01;}while(0)


		/**
		 * @brief   串口2设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 2 sets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define      UART2_SET_BUSY_FLAG()    do{UART_BUSY_FLAG |= 0x02;}while(0)


		/**
		 * @brief   串口3设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 3 sets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define      UART3_SET_BUSY_FLAG()    do{UART_BUSY_FLAG |= 0x04;}while(0)


		/**
		 * @brief   串口4设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 4 sets busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define      UART4_SET_BUSY_FLAG()    do{UART_BUSY_FLAG |= 0x08;}while(0)


		/**
		 * @brief   串口1设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 1 clears busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define    UART1_CLEAR_BUSY_FLAG()    do{UART_BUSY_FLAG &= 0xFE;}while(0)

		
		/**
		 * @brief   串口2设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 2 clears busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define    UART2_CLEAR_BUSY_FLAG()    do{UART_BUSY_FLAG &= 0xFD;}while(0)


		/**
		 * @brief   串口3设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 3 clears busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define    UART3_CLEAR_BUSY_FLAG()    do{UART_BUSY_FLAG &= 0xFB;}while(0)

		
		/**
		 * @brief   串口4设置忙标志位宏函数，
		 *          这是ELL自定义的标志位变量，并非硬件寄存器。
		 * @details Serial port 4 clears busy flag macro function,
		 *          This is a self-defined flag bit variable of ELL, not a hardware register.
		**/
		#define    UART4_CLEAR_BUSY_FLAG()    do{UART_BUSY_FLAG &= 0xF7;}while(0)


		/**
		 * @brief      串口1接收一个字节宏函数。
		 * @details    Serial port 1 receives a byte function。
         * @param[in]  byte 字节。
		**/
		#define UART1_RECEIVE_BYTE(byte) do{byte = SBUF;}while(0)


		/**
		 * @brief      串口2接收一个字节宏函数。
		 * @details    Serial port 2 receives a byte function。
         * @param[in]  byte 字节。
		**/
		#define UART2_RECEIVE_BYTE(byte) do{byte = S2BUF;}while(0)


		/**
		 * @brief      串口3接收一个字节宏函数。
		 * @details    Serial port 3 receives a byte function。
         * @param[in]  byte 字节。
		**/
		#define UART3_RECEIVE_BYTE(byte) do{byte = S3BUF;}while(0)


		/**
		 * @brief      串口4接收一个字节宏函数。
		 * @details    Serial port 4 receives a byte function。
         * @param[in]  byte 字节。
		**/
		#define UART4_RECEIVE_BYTE(byte) do{byte = S4BUF;}while(0)

		/**
		 * @brief      串口1发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 1 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART1_Isr_Send_Byte(uint8_t dat);

		/**
		 * @brief      串口2发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 2 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART2_Isr_Send_Byte(uint8_t dat);


		/**
		 * @brief      串口3发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 3 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART3_Isr_Send_Byte(uint8_t dat);
			
			
		/**
		 * @brief      串口4发送一个字节函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 4 sends a byte function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  dat 要发送的字节数据。The byte data to be sent.
		 * @return     None. 
		**/
		void UART4_Isr_Send_Byte(uint8_t dat);
        

		/**
		 * @brief      串口1发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 1 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART1_Isr_Send_String(const uint8_t *str);


		/**
		 * @brief      串口2发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 2 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART2_Isr_Send_String(const uint8_t *str);


		/**
		 * @brief      串口3发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 3 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART3_Isr_Send_String(const uint8_t *str);


		/**
		 * @brief      串口4发送一个字符串函数，
		 *             需要开启中断，并在中断服务函数中清除发送标志位。
		 * @details    Serial port 4 sends a string function,
		 *             Need to turn on the interrupt and clear the sending flag,
		 *             in the interrupt service function.
		 * @param[in]  str 要发送的字符串地址。String address to be sent.
		 * @return     None. 
		**/
		void UART4_Isr_Send_String(const uint8_t *str);

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
		void UART1_Isr_Send_Array(const uint8_t *str,uint16_t len);


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
		void UART2_Isr_Send_Array(const uint8_t *str,uint16_t len);


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
		void UART3_Isr_Send_Array(const uint8_t *str,uint16_t len);


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
		void UART4_Isr_Send_Array(const uint8_t *str,uint16_t len);
	
	#endif
	
#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
