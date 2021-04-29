/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TIMER.h
  - Author        : zeweni
  - Update date   : 2020.02.06
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
 * Apache-2.0 License License for more details.

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

/**
  * @name    TIMERType_Type
  * @brief   定时器类型状态枚举体。
  *          Timer type state enumeration body.
  * @param   TIMER_Type_Timer    [uint8_t] 工作在定时器状态。Working in timer state.
  * @param   TIMER_Type_Counter  [uint8_t] 工作在计数器状态。Working in counter state.
***/
typedef enum
{
    TIMER_Type_Timer   = 0x00, 
    TIMER_Type_Counter = 0x01
}   TIMERType_Type;

/**
  * @name    TIMERMode_Type
  * @brief   定时器工作模式枚举体。
  *          Timer work mode enumeration body.
  * @param   TIMER_16BitAutoReload       [uint8_t] 十六位自动重装载模式。16 Bit auto reload timer.
  * @param   TIMER_16Bit                 [uint8_t] 十六位手动重装载模式。16 Bit non auto reload timer.
  * @param   TIMER_8BitAutoReload        [uint8_t] 八位自动重装载模式。8 Bit auto reload timer.
  * @param   TIMER_16BitAutoReloadNoMask [uint8_t] 十六位自动重装载不可被打断模式。16 Bit auto reload non maskable interrupt.
***/
typedef enum
{
	TIMER_16BitAutoReload       = 0x00, 
	TIMER_16Bit                 = 0x01, 
	TIMER_8BitAutoReload        = 0x02,  
	TIMER_16BitAutoReloadNoMask = 0x03 
}	TIMERMode_Type;

/**
  * @name    TIMERTCycle_Type
  * @brief   定时器指令周期枚举体。
  *          Timer instruction cycle enumeration body.
  * @param   TIMER_TCY_1T   [uint8_t] 1T指令周期。The machine executes 1 cycles.
  * @param   TIMER_TCY_12T  [uint8_t] 12T指令周期（其实是1T的十二分频）。The machine executes 12 cycles
***/
typedef enum
{
	TIMER_TCY_1T  = 0x00,	
	TIMER_TCY_12T = 0x01
}	TIMERTCycle_Type;

/**
  * @name    TIMER_InitType
  * @brief   定时器初始化结构体句柄，初始化时请定义该句柄，并用其地址来传参。
  *          The timer initializes the structure handle. When initializing, 
  *          please define the handle and use its address to pass parameters.
  * @param   SysClokDiv [uint8_t] 定时器时钟源八分频。system clock division to timer use.
  * @param   Type       [TIMERType_Type] 定时器类型状态。timer type.
  * @param   Mode       [TIMERMode_Type] 定时器工作模式。Working mode.
  * @param   TCycle     [TIMERTCycle_Type] 定时器指令周期。Instruction cycle.
  * @param   ClkOut     [BOOL] 定时器可编程时钟输出控制位。Programmable clock output.
  * @param   Time       [uint16_t] 定时器定时时间。Loading initial value.
  * @param   Run        [BOOL] 定时器运行控制位。Operation control bit.
***/
typedef struct 
{
#if  (PER_LIB_MCU_MUODEL == STC8Cx ||PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
    uint8_t SysClkDiv;   /* just STC8G、STC8H */
#endif
    TIMERType_Type Type;
    TIMERMode_Type Mode;
    TIMERTCycle_Type TCycle;
    BOOL ClkOut;
    uint16_t Time;
    BOOL Run;
}   TIMER_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/**
  * @name    TIMER5_Wake_Up_Power
  * @brief   调电唤醒定时器5初始化函数。 
  *          Power up timer 5 initialization function.
  * @param   value  [IN] 定时器5调电唤醒时间值。Timer power up time value.
  * @param   run    [IN] 定时器5调电唤醒运行控制位。Timer 5 power up operation control bit.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER5_Wake_Up_Power(uint16_t value,BOOL run);

/**
  * @name    TIMER0_Init
  * @brief   定时器0初始化函数。 
  *          TIMER0 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER0_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER1_Init
  * @brief   定时器1初始化函数。 
  *          TIMER1 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER1_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER2_Init
  * @brief   定时器2初始化函数。 
  *          TIMER2 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER2_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER3_Init
  * @brief   定时器3初始化函数。 
  *          TIMER3 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER3_Init(const TIMER_InitType *timerx);

/**
  * @name    TIMER4_Init
  * @brief   定时器4初始化函数。 
  *          TIMER4 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER4_Init(const TIMER_InitType *timerx);

FSCSTATE NVIC_TIMER0_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_TIMER1_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_TIMER2_Init(BOOL run);
FSCSTATE NVIC_TIMER3_Init(BOOL run);
FSCSTATE NVIC_TIMER4_Init(BOOL run);

#define    TIMER2_CLEAR_FLAG()    do{ AUXINTIF &= 0xFE; }while(0)
#define    TIMER3_CLEAR_FLAG()    do{ AUXINTIF &= 0xFD; }while(0)
#define    TIMER4_CLEAR_FLAG()    do{ AUXINTIF &= 0xFB; }while(0)

#define    NVIC_TIMER0_CTRL(run)     do{ ET0 = run; }while(0)
#define    NVIC_TIMER1_CTRL(run)     do{ ET1 = run; }while(0)

/**
 * @brief      TIMER0选择中断优先级宏函数，仅限本文件调用。
 * @details    TIMER0 select interrupt priority macro function, 
 *             only this file call.
 * @param[in]  pri 中断优先级。 Priority of interrupt.
**/
#define NVIC_TIMER0_PRI(pri)                  \
do{                                           \
	IPH = (IPH & 0xFD) |  (pri & 0x02) ;      \
	IP  = (IP  & 0xFD) | ((pri & 0x01) << 1); \
}while(0)


/**
 * @brief      TIMER1选择中断优先级宏函数，仅限本文件调用。
 * @details    TIMER1 select interrupt priority macro function, 
 *             only this file call.
 * @param[in]  pri 中断优先级。 Priority of interrupt.
**/
#define NVIC_TIMER1_PRI(pri)                  \
do{                                           \
	IPH = (IPH & 0xF7) | ((pri & 0x02) << 2); \
	IP  = (IP  & 0xF7) | ((pri & 0x01) << 3); \
}while(0)

#define    NVIC_TIMER2_CTRL(run)     do{ IE2 = (IE2 & 0xFB) | (run << 2); }while(0)
#define    NVIC_TIMER3_CTRL(run)     do{ IE2 = (IE2 & 0xDF) | (run << 5); }while(0)
#define    NVIC_TIMER4_CTRL(run)     do{ IE2 = (IE2 & 0xBF) | (run << 6); }while(0)


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

