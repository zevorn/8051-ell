/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TIMER.c
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

#include "STC8x_TIMER.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None. */
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/**
  * @name    TIMER0_MODE_CFG
  * @brief   定时器0工作模式选择宏函数（作用域为本文件）。
  *          Timer 0 working mode selection macro function (scope for this file).
  * @param   mode [uint8_t] 工作模式。working mode.
***/
#define TIMER0_MODE_CFG(mode)  TMOD = (TMOD & 0xFC) | (mode)

/**
  * @name    TIMER1_MODE_CFG
  * @brief   定时器1工作模式选择宏函数（作用域为本文件）。
  *          Timer 1 working mode selection macro function (scope for this file).
  * @param   mode [uint8_t] 工作模式。working mode.
***/
#define TIMER1_MODE_CFG(mode)  TMOD = (TMOD & 0xCF) | (mode << 4)

/**
  * @name    TIMER0_TCY_CFG
  * @brief   定时器0指令周期选择宏函数（作用域为本文件）。
  *          Timer 0 instruction cycle selects macro function (scope is this file).
  * @param   tCycle [uint8_t] 指令周期 instruction cycle.
***/
#define  TIMER0_TCY_CFG(tCycle) do{ AUXR  = (AUXR  & 0x7F) | ( !tCycle << 7 ); }while(0)

/**
  * @name    TIMER1_TCY_CFG
  * @brief   定时器1指令周期选择宏函数（作用域为本文件）。
  *          Timer 1 instruction cycle selects macro function (scope is this file).
  * @param   tCycle [uint8_t] 指令周期 instruction cycle.
***/
#define  TIMER1_TCY_CFG(tCycle) do{ AUXR  = (AUXR  & 0xBF) | ( !tCycle << 6 ); }while(0)

/**
  * @name    TIMER2_TCY_CFG
  * @brief   定时器2指令周期选择宏函数（作用域为本文件）。
  *          Timer 2 instruction cycle selects macro function (scope is this file).
  * @param   tCycle [uint8_t] 指令周期 instruction cycle.
***/
#define  TIMER2_TCY_CFG(tCycle) do{ AUXR  = (AUXR  & 0xFB) | ( !tCycle << 2 ); }while(0)

/**
  * @name    TIMER3_TCY_CFG
  * @brief   定时器3指令周期选择宏函数（作用域为本文件）。
  *          Timer 3 instruction cycle selects macro function (scope is this file).
  * @param   tCycle [uint8_t] 指令周期 instruction cycle.
***/
#define  TIMER3_TCY_CFG(tCycle) do{ T4T3M = (T4T3M & 0xFD) | ( !tCycle << 1 ); }while(0)

/**
  * @name    TIMER4_TCY_CFG
  * @brief   定时器4指令周期选择宏函数（作用域为本文件）。
  *          Timer 4 instruction cycle selects macro function (scope is this file).
  * @param   tCycle [uint8_t] 指令周期 instruction cycle.
***/
#define  TIMER4_TCY_CFG(tCycle) do{ T4T3M = (T4T3M & 0xDF) | ( !tCycle << 5 ); }while(0)

/**
  * @name    TIMER0_VALUE_CFG
  * @brief   定时器0定时时间设置函数（作用域为本文件）。
  *          Timer 0 timing time setting function (scope is this file).
  * @param   time [uint16_t] 定时时间 timing time.
***/
#define TIMER0_VALUE_CFG(time) do{ \
time = (65536UL - (sysClk_FRE / (1000000UL /  time \
	         * (11 * (!(AUXR & 0x80)) + 1)) ) );}while(0)

/**
  * @name    TIMER1_VALUE_CFG
  * @brief   定时器1定时时间设置函数（作用域为本文件）。
  *          Timer 1 timing time setting function (scope is this file).
  * @param   time [uint16_t] 定时时间 timing time.
***/
#define TIMER1_VALUE_CFG(time) do{ \
time = (65536UL - (sysClk_FRE / (1000000UL /  time \
	         * (11 * (!(AUXR & 0x40)) + 1)) ) );}while(0)

#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
    
    /**
      * @name    TIMER2_VALUE_CFG
      * @brief   定时器2定时时间设置函数（作用域为本文件）。
      *          Timer 2 timing time setting function (scope is this file).
      * @param   time [uint16_t] 定时时间 timing time.
    ***/
    #define TIMER2_VALUE_CFG(time) do{ \
    time = (65536UL - (sysClk_FRE / (1000000UL /  time \
    	         * (11 * (!(AUXR & 0x04)) + 1)) ) );}while(0)
    /**
      * @name    TIMER3_VALUE_CFG
      * @brief   定时器3定时时间设置函数（作用域为本文件）。
      *          Timer 3 timing time setting function (scope is this file).
      * @param   time [uint16_t] 定时时间 timing time.
    ***/
    #define TIMER3_VALUE_CFG(time) do{ \
    time = (65536UL - (sysClk_FRE / (1000000UL /  time \
    	        * (11 * (!(T4T3M & 0x02)) + 1)) ) );}while(0)
    /**
      * @name    TIMER3_VALUE_CFG
      * @brief   定时器3定时时间设置函数（作用域为本文件）。
      *          Timer 3 timing time setting function (scope is this file).
      * @param   time [uint16_t] 定时时间 timing time.
    ***/
    #define TIMER4_VALUE_CFG(time) do{ \
    time = (65536UL - (sysClk_FRE / (1000000UL /  time \
	          * (11 * (!(T4T3M & 0x20)) + 1)) ) );}while(0)	
              
#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    /**
      * @name    TIMER2_VALUE_CFG
      * @brief   定时器2定时时间设置函数（作用域为本文件）。
      *          Timer 2 timing time setting function (scope is this file).
      * @param   time [uint16_t] 定时时间 timing time.
    ***/
    #define TIMER2_VALUE_CFG(time) do{ \
    time = (65536UL - ( (sysClk_FRE / (TM2PS + 1) ) / (1000000UL /  time \
    	         * (11 * (!(AUXR & 0x04)) + 1)) ) );}while(0)
    /**
      * @name    TIMER3_VALUE_CFG
      * @brief   定时器3定时时间设置函数（作用域为本文件）。
      *          Timer 3 timing time setting function (scope is this file).
      * @param   time [uint16_t] 定时时间 timing time.
    ***/
    #define TIMER3_VALUE_CFG(time) do{ \
    time = (65536UL - ( (sysClk_FRE / (TM3PS + 1) ) / (1000000UL /  time \
    	        * (11 * (!(T4T3M & 0x02)) + 1)) ) );}while(0)
    /**
      * @name    TIMER4_VALUE_CFG
      * @brief   定时器4定时时间设置函数（作用域为本文件）。
      *          Timer 4 timing time setting function (scope is this file).
      * @param   time [uint16_t] 定时时间 timing time.
    ***/
    #define TIMER4_VALUE_CFG(time) do{ \
    time = (65536UL - ( (sysClk_FRE / (TM2PS + 1) ) / (1000000UL /  time \
	          * (11 * (!(T4T3M & 0x20)) + 1)) ) );}while(0)	
    
#endif             
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    TIMER0_Init
  * @brief   定时器0初始化函数。 
  *          TIMER0 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER0_Init(const TIMER_InitType* timerx)
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
  * @brief   定时器1初始化函数。
  *          TIMER1 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER1_Init(const TIMER_InitType* timerx)
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
  * @brief   定时器2初始化函数。 
  *          TIMER2 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER2_Init(const TIMER_InitType* timerx)
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
  * @brief   定时器3初始化函数。 
  *          TIMER3 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER3_Init(const TIMER_InitType* timerx)
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
  * @brief   定时器4初始化函数。 
  *          TIMER4 peripheral init function. 
  * @param   *timerx  [IN] 定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
  *                        The timer initializes the structure handle. When initializing, 
  *                        please define the handle and pass its address to the parameter.
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE TIMER4_Init(const TIMER_InitType* timerx)
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
  * @brief   调电唤醒定时器5初始化函数。 
  *          Power up timer 5 initialization function.
  * @param   value  [IN] 定时器5调电唤醒时间值。Timer power up time value.
  * @param   run    [IN] 定时器5调电唤醒运行控制位。Timer 5 power up operation control bit.
  * @return  [FSC_SUCCESS / FSC_FAIL]
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



