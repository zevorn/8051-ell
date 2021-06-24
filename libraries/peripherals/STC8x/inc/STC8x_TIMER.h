/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TIMER.h
  - Author        : zeweni
  - Update date   : 2020.05.11
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
#ifndef __STC8x_TIMER_H_
#define __STC8x_TIMER_H_

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


#ifndef PER_LIB_TIMER_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_TIMER_CTRL 1
#endif


#ifndef PER_LIB_TIMER_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_TIMER_INIT_CTRL 1
#endif

#ifndef PER_LIB_TIMER_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_TIMER_WORK_CTRL 1
#endif

#ifndef PER_LIB_TIMER_NVIC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_TIMER_NVIC_CTRL 1
#endif


/**
 * @name    TIMERType_Type
 * @brief   定时器类型状态枚举体。
 * @details Timer type state enumeration body.
**/
typedef enum
{
    TIMER_Type_Timer   = 0x00,  /*!< 工作在定时器类型。Working on timer type. */
    TIMER_Type_Counter = 0x01   /*!< 工作在计数器类型。Working on counter type. */
}   TIMERType_Type;


/**
 * @name    TIMERMode_Type
 * @brief   定时器工作模式枚举体。
 * @details Timer work mode enumeration body.
**/
typedef enum
{
	TIMER_16BitAutoReload       = 0x00, /*!< 十六位自动重装载模式。16 Bit auto reload timer. */
	TIMER_16Bit                 = 0x01, /*!< 十六位手动重装载模式。16 Bit non auto reload timer. */
	TIMER_8BitAutoReload        = 0x02, /*!< 八位自动重装载模式。8 Bit auto reload timer. */
	TIMER_16BitAutoReloadNoMask = 0x03  /*!< 十六位自动重装载不可被打断模式。16 Bit auto reload non maskable interrupt. */
}	TIMERMode_Type;


/**
 * @name    TIMERTCycle_Type
 * @brief   定时器指令周期枚举体。
 * @details Timer instruction cycle enumeration body.
**/
typedef enum
{
	TIMER_TCY_1T  = 0x00,	/*!< 1T指令周期。The machine executes 1 cycles. */
	TIMER_TCY_12T = 0x01	/*!< 12T指令周期（其实是1T的十二分频）。The machine executes 12 cycles. */
}	TIMERTCycle_Type;


/**
 * @brief   定时器初始化结构体句柄，初始化时请定义该句柄，并用其地址来传参。
 * @details The timer initializes the structure handle. When initializing, 
 *          please define the handle and use its address to pass parameters.
 * @note    关于SysClkDiv这个参数，在系统时钟发生改变以后，需要你手动重新更改，
 *          以匹配你需要的定时时间，它不可以向Time参数一样可以自己做修正。
**/
typedef struct 
{
#if  (PER_LIB_MCU_MUODEL == STC8Cx ||PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
    uint8_t SysClkDiv;       /*!< 定时器时钟源八分频。system clock division to timer use.*/
#endif
    TIMERType_Type Type;      /*!< 定时器类型状态。timer type. */
    TIMERMode_Type Mode;      /*!< 定时器工作模式。Working mode. */
    TIMERTCycle_Type TCycle;  /*!< 定时器指令周期。Instruction cycle. */
    BOOL ClkOut;              /*!< 定时器可编程时钟输出控制位。Programmable clock output. */
    uint32_t Time;           /*!< 定时器定时时间。Loading initial value. */
    BOOL Run;                 /*!< 定时器运行控制位。Operation control bit. */
}   TIMER_InitType;


/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_TIMER_CTRL == 1)

    #if (PER_LIB_TIMER_INIT_CTRL == 1)

        /**
         * @brief     调电唤醒定时器5初始化函数。 
         * @details   Power up timer 5 initialization function.
         * @param[in] time  定时器5调电唤醒时间值。Timer power up time value.
         * @param[in] run   定时器5调电唤醒运行控制位。Timer 5 power up operation control bit.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER5_Wake_Up_Power(uint16_t value,BOOL run);


        /**
         * @brief     定时器0初始化函数。 
         * @details   TIMER0 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER0_Init(const TIMER_InitType *timerx);


        /**
         * @brief     定时器1初始化函数。 
         * @details   TIMER1 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER1_Init(const TIMER_InitType *timerx);


        /**
         * @brief     定时器2初始化函数。 
         * @details   TIMER2 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER2_Init(const TIMER_InitType *timerx);


        /**
         * @brief     定时器3初始化函数。 
         * @details   TIMER3 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER3_Init(const TIMER_InitType *timerx);


        /**
         * @brief     定时器4初始化函数。 
         * @details   TIMER4 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER4_Init(const TIMER_InitType *timerx);

    #endif
	
	#if (PER_LIB_TIMER_WORK_CTRL == 1)
	
        /**
         * @brief     定时器0工作开关控制宏函数。
         * @details   timer0 working switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    TIMER0_WORK_CTRL(run)     do{ TR0 = run; }while(0)	

		
        /**
         * @brief     定时器1工作开关控制宏函数。
         * @details   timer1 working switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    TIMER1_WORK_CTRL(run)     do{ TR1 = run; }while(0)	
		
		

        /**
         * @brief     定时器2工作开关控制宏函数。
         * @details   timer2 working switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    TIMER2_WORK_CTRL(run)     do{AUXR = (AUXR & 0xEF) | (run << 4);  }while(0)	
		
		
        /**
         * @brief     定时器3工作开关控制宏函数。
         * @details   timer3 working switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    TIMER3_WORK_CTRL(run)     do{ T4T3M = (T4T3M & 0xF7) | (run << 3)}while(0)	
		
		
        /**
         * @brief     定时器4工作开关控制宏函数。
         * @details   timer4 working switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    TIMER4_WORK_CTRL(run)     do{ T4T3M = (T4T3M & 0x7F) | (run << 7)}while(0)		

	#endif
		
    #if (PER_LIB_TIMER_NVIC_CTRL == 1)

        /**
         * @brief     定时器0中断初始化函数。
         * @details   TIMER0 NVIC function.
         * @param[in] pri 中断优先级。interrupt priority.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER0_Init(NVICPri_Type pri,BOOL run);


        /**
         * @brief     定时器1中断初始化函数。
         * @details   TIMER1 NVIC function.
         * @param[in] pri 中断优先级。interrupt priority.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER1_Init(NVICPri_Type pri,BOOL run);


        /**
         * @brief     定时器2中断初始化函数。
         * @details   TIMER2 NVIC function.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER2_Init(BOOL run);


        /**
         * @brief     定时器3中断初始化函数。
         * @details   TIMER3 NVIC function.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER3_Init(BOOL run);


        /**
         * @brief     定时器4中断初始化函数。
         * @details   TIMER4 NVIC function.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER4_Init(BOOL run);


        /**
		 * @brief   定时器2清除中断请求标志位宏函数,
		 *          只有STC8A，STC8F需要清，STC8AxD4和其它STC8型号不需要清。
         * @details TIMER2 clears  interrupt request flag bit macro function. 
        **/
        #define    TIMER2_CLEAR_FLAG()    do{ AUXINTIF &= 0xFE; }while(0)


        /**
         * @brief   定时器3清除中断请求标志位宏函数，
		 *          只有STC8A，STC8F需要清，STC8AxD4和其它STC8型号不需要清。
         * @details TIMER3 clears  interrupt request flag bit macro function. 
        **/
        #define    TIMER3_CLEAR_FLAG()    do{ AUXINTIF &= 0xFD; }while(0)


        /**
         * @brief   定时器4清除中断请求标志位宏函数，
		 *          只有STC8A，STC8F需要清，STC8AxD4和其它STC8型号不需要清。
         * @details TIMER4 clears  interrupt request flag bit macro function. 
        **/
        #define    TIMER4_CLEAR_FLAG()    do{ AUXINTIF &= 0xFB; }while(0)


        /**
         * @brief      TIMER0选择中断优先级宏函数。
         * @details    TIMER0 select interrupt pri macro function.
         * @param[in]  pri 中断优先级。 pri of interrupt.
        **/
        #define NVIC_TIMER0_PRI(pri)                  \
        do{                                           \
            IPH = (IPH & 0xFD) |  (pri & 0x02) ;      \
            IP  = (IP  & 0xFD) | ((pri & 0x01) << 1); \
        }while(0)


        /**
         * @brief      TIMER1选择中断优先级宏函数。
         * @details    TIMER1 select interrupt pri macro function.
         * @param[in]  pri 中断优先级。 pri of interrupt.
        **/
        #define NVIC_TIMER1_PRI(pri)                  \
        do{                                           \
            IPH = (IPH & 0xF7) | ((pri & 0x02) << 2); \
            IP  = (IP  & 0xF7) | ((pri & 0x01) << 3); \
        }while(0)


        /**
         * @brief     定时器0中断开关控制宏函数。
         * @details   timer0 interrupt switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    NVIC_TIMER0_CTRL(run)     do{ ET0 = run; }while(0)


        /**
         * @brief     定时器1中断开关控制宏函数。
         * @details   timer1 interrupt switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    NVIC_TIMER1_CTRL(run)     do{ ET1 = run; }while(0)


        /**
         * @brief     定时器2中断开关控制宏函数。
         * @details   timer2 interrupt switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    NVIC_TIMER2_CTRL(run)     do{ IE2 = (IE2 & 0xFB) | (run << 2); }while(0)


        /**
         * @brief     定时器3中断开关控制宏函数。
         * @details   timer3 interrupt switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    NVIC_TIMER3_CTRL(run)     do{ IE2 = (IE2 & 0xDF) | (run << 5); }while(0)


        /**
         * @brief     定时器4中断开关控制宏函数。
         * @details   timer4 interrupt switch control macro function.
         * @param[in] run  使能控制位。Enable control bit.
        **/
        #define    NVIC_TIMER4_CTRL(run)     do{ IE2 = (IE2 & 0xBF) | (run << 6); }while(0)

    #endif

				
    #if (PER_LIB_TIMER_WORK_CTRL == 1)
		
        /**
		 * @brief     定时器0计数器重装载宏函数。
         * @details   Timer 0 counter reload macro function。
         * @note      适用于定时器0十六位手动重装载模式。
		 *            Suitable for timer 0 sixteen-bit manual reload mode.
        **/
        #define    TIMER0_RELOAD_CNT()                    \
		do{                                               \
			T0L = (uint8_t)(G_Time0_CntValue);           \
			T0H = (uint8_t)(G_Time0_CntValue >> 8);      \
		}while(0)
		
		
        /**
		 * @brief     定时器1计数器重装载宏函数。
         * @details   Timer 1 counter reload macro function。
         * @note      适用于定时器1十六位手动重装载模式。
		 *            Suitable for timer 1 sixteen-bit manual reload mode.
        **/
        #define    TIMER1_RELOAD_CNT()                    \
		do{                                               \
			T1L = (uint8_t)(G_Time1_CntValue);           \
			T1H = (uint8_t)(G_Time1_CntValue >> 8);      \
		}while(0)
				
		
        /**
         * @brief     定时器0设置定时时间函数。
         * @details   Timer 0 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER0_Set_Time(uint32_t time);
		

        /**
         * @brief     定时器1设置定时时间函数。
         * @details   Timer 1 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER1_Set_Time(uint32_t time);

        /**
         * @brief     定时器2设置定时时间函数。
         * @details   Timer 2 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			FSCSTATE TIMER2_Set_Time(uint32_t time);
		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			FSCSTATE TIMER2_Set_Time(uint8_t clkDiv,uint32_t time);	
  		#endif			


        /**
         * @brief     定时器3设置定时时间函数。
         * @details   Timer 3 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			FSCSTATE TIMER3_Set_Time(uint32_t time);
		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			FSCSTATE TIMER3_Set_Time(uint8_t clkDiv,uint32_t time);
  		#endif			
		
		
        /**
         * @brief     定时器4设置定时时间函数。
         * @details   Timer 4 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			FSCSTATE TIMER4_Set_Time(uint32_t time);
		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			FSCSTATE TIMER4_Set_Time(uint8_t clkDiv,uint32_t time);
  		#endif			


	#endif
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
