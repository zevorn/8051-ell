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
 * Apache-2.0 License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_TIMER.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/**
 * @brief      定时器0工作模式选择宏函数（作用域为本文件）。
 * @details    Timer 0 working mode selection macro function (scope for this file).
 * @param[in]  mode 工作模式。working mode.
**/
#define TIMER0_MODE_CFG(mode)  do{TMOD = (TMOD & 0xFC) | (mode);}while(0)


/**
 * @brief     定时器1工作模式选择宏函数（作用域为本文件）。
 * @details   Timer 1 working mode selection macro function (scope for this file).
 * @param[in] mode 工作模式。working mode.
**/
#define TIMER1_MODE_CFG(mode)  do{TMOD = (TMOD & 0xCF) | (mode << 4);}while(0)


/**
 * @brief     定时器0指令周期选择宏函数（作用域为本文件）。
 * @details   Timer 0 instruction cycle selects macro function (scope is this file).
 * @param[in] tCycle 指令周期。 instruction cycle.
**/
#define  TIMER0_TCY_CFG(tCycle)  do{AUXR  = (AUXR  & 0x7F) | ( !tCycle << 7 );}while(0)


/**
 * @brief     定时器1指令周期选择宏函数（作用域为本文件）。
 * @details   Timer 1 instruction cycle selects macro function (scope is this file).
 * @param[in] tCycle 指令周期。 instruction cycle.
**/
#define  TIMER1_TCY_CFG(tCycle) do{AUXR  = (AUXR  & 0xBF) | ( !tCycle << 6 );}while(0)


/**
 * @brief   定时器2指令周期选择宏函数（作用域为本文件）。
 * @details   Timer 2 instruction cycle selects macro function (scope is this file).
 * @param[in] tCycle 指令周期。 instruction cycle.
**/
#define  TIMER2_TCY_CFG(tCycle) do{AUXR  = (AUXR  & 0xFB) | ( !tCycle << 2 );}while(0)


/**
 * @brief     定时器3指令周期选择宏函数（作用域为本文件）。
 * @details   Timer 3 instruction cycle selects macro function (scope is this file).
 * @param[in] tCycle 指令周期。 instruction cycle.
**/
#define  TIMER3_TCY_CFG(tCycle) do{T4T3M = (T4T3M & 0xFD) | ( !tCycle << 1 );}while(0)


/**
 * @brief   定时器4指令周期选择宏函数（作用域为本文件）。
 * @details   Timer 4 instruction cycle selects macro function (scope is this file).
 * @param[in] tCycle 指令周期 instruction cycle.
**/
#define  TIMER4_TCY_CFG(tCycle) do{T4T3M = (T4T3M & 0xDF) | ( !tCycle << 5 );}while(0)


/**
 * @brief     定时器0定时时间设置函数（作用域为本文件）。
 * @details   Timer 0 timing time setting function (scope is this file).
 * @param[in] time 定时时间。 timing time.
**/
#define TIMER0_TIM_CFG(time)                           \
do{                                                    \
	time = (65536UL - (sysClk_FRE / (1000000UL /  time \
	       * (11 * (!(AUXR & 0x80)) + 1)) ) );         \
	G_Time0_CntValue = time;                           \
}while(0)


/**
 * @brief     定时器1定时时间设置函数（作用域为本文件）。
 * @details   Timer 1 timing time setting function (scope is this file).
 * @param[in] time 定时时间。 timing time.
**/
#define TIMER1_TIM_CFG(time)                           \
do{                                                    \
	time = (65536UL - (sysClk_FRE / (1000000UL /  time \
	       * (11 * (!(AUXR & 0x40)) + 1)) ) );         \
	G_Time1_CntValue = time;                           \
}while(0)



#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
    
    /**
     * @brief      定时器2定时时间设置函数（作用域为本文件）。
     * @details    Timer 2 timing time setting function (scope is this file).
     * @param[in]  time 定时时间。 timing time.
    **/
    #define TIMER2_TIM_CFG(time)                           \
	do{                                                    \
		time = (65536UL - (sysClk_FRE / (1000000UL /  time \
    	       * (11 * (!(AUXR & 0x04)) + 1)) ) );         \
	}while(0)
	
	
    /**
     * @brief     定时器3定时时间设置函数（作用域为本文件）。
     * @details   Timer 3 timing time setting function (scope is this file).
     * @param[in] time 定时时间。 timing time.
    **/
    #define TIMER3_TIM_CFG(time)                           \
	do{                                                    \
		time = (65536UL - (sysClk_FRE / (1000000UL /  time \
    	       * (11 * (!(T4T3M & 0x02)) + 1)) ) );        \
	}while(0)
	
	
    /**
     * @brief     定时器3定时时间设置函数（作用域为本文件）。
     *            Timer 3 timing time setting function (scope is this file).
     * @param[in] time 定时时间。 timing time.
    **/
    #define TIMER4_TIM_CFG(time)                           \
	do{                                                    \
		time = (65536UL - (sysClk_FRE / (1000000UL /  time \
	          * (11 * (!(T4T3M & 0x20)) + 1)) ) );         \
	}while(0)
              
#elif  (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    /**
     * @brief     定时器2定时时间设置函数（作用域为本文件）。
     *            Timer 2 timing time setting function (scope is this file).
     * @param[in] time 定时时间。 timing time.
    **/
    #define TIMER2_TIM_CFG(time)                                             \
	do{                                                                      \
		time = (65536UL - ( (sysClk_FRE / (TM2PS + 1) ) / (1000000UL /  time \
    	         * (11 * (!(AUXR & 0x04)) + 1)) ) );                         \
	}while(0)
	
	
    /**
     * @brief     定时器3定时时间设置函数（作用域为本文件）。
     *            Timer 3 timing time setting function (scope is this file).
     * @param[in] time 定时时间。 timing time.
    **/
    #define TIMER3_TIM_CFG(time)                                             \
	do{ 															         \
		time = (65536UL - ( (sysClk_FRE / (TM3PS + 1) ) / (1000000UL /  time \
    	       * (11 * (!(T4T3M & 0x02)) + 1)) ) );                          \
	}while(0)
	
	
    /**
     * @name      TIMER4_TIM_CFG
     * @brief     定时器4定时时间设置函数（作用域为本文件）。
     *            Timer 4 timing time setting function (scope is this file).
     * @param[in] time 定时时间。 timing time.
    **/
    #define TIMER4_TIM_CFG(time)                                             \
	do{                                                                      \
		time = (65536UL - ( (sysClk_FRE / (TM2PS + 1) ) / (1000000UL /  time \
	           * (11 * (!(T4T3M & 0x20)) + 1)) ) );                          \
	}while(0)
    
#endif            


/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
uint32_t G_Time0_CntValue = 0;
uint32_t G_Time1_CntValue = 0;	
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_TIMER_CTRL == 1)

    #if (PER_LIB_TIMER_INIT_CTRL == 1)

        /**
         * @brief     定时器0初始化函数。 
         * @details   TIMER0 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
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
            TIMER0_TIM_CFG(timerx -> Time);
            if(timerx -> Mode == TIMER_8BitAutoReload) T0L = (uint8_t)(timerx -> Time), T0H = (uint8_t)(timerx -> Time); 
            else                                       T0L = (uint8_t)(timerx -> Time), T0H = (uint8_t)(timerx -> Time >> 8);
            INTCLKO = (INTCLKO & 0xFE) | (timerx -> ClkOut);
            TR0 = timerx -> Run;
            return FSC_SUCCESS;
        }


        /**
         * @brief     定时器1初始化函数。 
         * @details   TIMER1 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
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
            TIMER1_TIM_CFG(timerx -> Time);	
            if(timerx -> Mode == TIMER_8BitAutoReload) T1L = (uint8_t)(timerx -> Time), T1H = (uint8_t)(timerx -> Time); 
            else                                       T1L = (uint8_t)(timerx -> Time), T1H = (uint8_t)(timerx -> Time >> 8);
            INTCLKO = (INTCLKO & 0xFD) | (timerx -> ClkOut << 1);
            TF1 = 0; //Clear Flag
            TR1 = timerx -> Run; 
            return FSC_SUCCESS;		
        }


        /**
         * @brief     定时器2初始化函数。 
         * @details   TIMER2 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER2_Init(const TIMER_InitType* timerx)
        {
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
            AUXR &= 0xEF; //Turn off timer2
            AUXR = (AUXR & 0xF7) | (timerx -> Type << 3);
            TIMER2_TCY_CFG(timerx -> TCycle);
            
            #if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
            
                TIMER2_TIM_CFG(timerx -> Time);
            
            #elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
            
                EAXFR_ENABLE();
                TM2PS = timerx -> SysClkDiv;
			
                TIMER2_TIM_CFG(timerx -> Time);
                EAXFR_DISABLE();
            
            #endif	
            
            T2L = (uint8_t)(timerx -> Time);
            T2H = (uint8_t)(timerx -> Time >> 8);
            INTCLKO = (INTCLKO & 0xFB) | (timerx -> ClkOut << 2);	
            AUXR = (AUXR & 0xEF) | (timerx -> Run << 4);  
            return FSC_SUCCESS;	
        }


        /**
         * @brief     定时器3初始化函数。 
         * @details   TIMER3 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER3_Init(const TIMER_InitType* timerx)
        {
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
            T4T3M &= 0XF7;//Turn off timer3
            T4T3M = (T4T3M & 0xFB) | (timerx -> Type << 2);
            TIMER3_TCY_CFG(timerx -> TCycle);
            
            #if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
            
                TIMER3_TIM_CFG(timerx -> Time);
            
            #elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
            
                EAXFR_ENABLE();
                TM3PS = timerx -> SysClkDiv;
                TIMER3_TIM_CFG(timerx -> Time);
                EAXFR_DISABLE();
            
            #endif	
            
            T3L = (uint8_t)(timerx -> Time);
            T3H = (uint8_t)(timerx -> Time >> 8);
            T4T3M = (T4T3M & 0xFE) | (timerx -> ClkOut);
            T4T3M = (T4T3M & 0xF7) | (timerx -> Run << 3);		
            return FSC_SUCCESS;	
        }


        /**
         * @brief     定时器4初始化函数。 
         * @details   TIMER4 peripheral init function. 
         * @param[in] timerx  定时器初始化结构体句柄，初始化时请定义该句柄，并将其地址传参。
         *                    The timer initializes the structure handle. When initializing, 
         *                    please define the handle and pass its address to the parameter.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER4_Init(const TIMER_InitType* timerx)
        {
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
            T4T3M &= 0X7F; //Turn off timer4
            T4T3M = (T4T3M & 0xBF) | (timerx -> Type << 6);
			
            TIMER4_TCY_CFG(timerx -> TCycle);
            
            #if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
            
                TIMER4_TIM_CFG(timerx -> Time);
            
            #elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
            
                EAXFR_ENABLE();
                TM4PS = timerx -> SysClkDiv;
                TIMER4_TIM_CFG(timerx -> Time);
                EAXFR_DISABLE();
            
            #endif
            
            T4L = (uint8_t)(timerx -> Time);
            T4H = (uint8_t)(timerx -> Time >> 8);
            T4T3M = (T4T3M & 0xEF) | (timerx -> ClkOut << 4);
            T4T3M = (T4T3M & 0x7F) | (timerx -> Run << 7);	
            return FSC_SUCCESS;		
        }


        /**
         * @name      TIMER5_Wake_Up_Power
         * @brief     调电唤醒定时器5初始化函数。 
         * @details   Power up timer 5 initialization function.
         * @param[in] time 定时器5调电唤醒时间值。Timer power up time value.
         * @param[in] run  定时器5调电唤醒运行控制位。Timer 5 power up operation control bit.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER5_Wake_Up_Power(uint16_t time,BOOL run)
        {
            uint16_t fwt;
            fwt = (uint16_t)((FWTH << 8) | FWTL);    //Calculate the clock frequency 
            time = (uint16_t)((fwt * (uint32_t) time) / 16000000UL);//Count count times
            WKTCH = (uint8_t)((time - 1) >> 8);
            WKTCL = (uint8_t)( time - 1);
            WKTCH = (WKTCH & 0x7F) | (run << 7);
            return FSC_SUCCESS;
        }

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
        FSCSTATE NVIC_TIMER0_Init(NVICPri_Type pri,BOOL run)
        {
            ET0 = run;
            NVIC_TIMER0_PRI(pri);
            return FSC_SUCCESS;
        }


        /**
         * @brief     定时器1中断初始化函数。
         * @details   TIMER1 NVIC function.
         * @param[in] pri 中断优先级。interrupt priority.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER1_Init(NVICPri_Type pri,BOOL run)
        {
            ET1 = run;
            NVIC_TIMER1_PRI(pri);
            return FSC_SUCCESS;
        }


        /**
         * @brief     定时器2中断初始化函数。
         * @details   TIMER2 NVIC function.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER2_Init(BOOL run)
        {
            IE2 = (IE2 & 0xFB) | (run << 2);
            return FSC_SUCCESS;
        }


        /**
         * @brief     定时器3中断初始化函数。
         * @details   TIMER3 NVIC function.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER3_Init(BOOL run)
        {
            IE2 = (IE2 & 0xDF) | (run << 5);
            return FSC_SUCCESS;
        }

        /**
         * @brief     定时器4中断初始化函数。
         * @details   TIMER4 NVIC function.
         * @param[in] run 使能控制位。enable control. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_TIMER4_Init(BOOL run)
        {
            IE2 = (IE2 & 0xBF) | (run << 6);
            return FSC_SUCCESS;
        }

    #endif
		
    #if (PER_LIB_TIMER_WORK_CTRL == 1)
		
        /**
         * @brief     定时器0设置定时时间函数。
         * @details   Timer 0 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER0_Set_Time(uint32_t time)		
		{
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
            TIMER0_TIM_CFG(time);
			if((TMOD & 0x03) == 0x02) T0L = (uint8_t)(time), T0H = (uint8_t)(time); 
            else              T0L = (uint8_t)(time), T0H = (uint8_t)(time >> 8);
			return FSC_SUCCESS;
		}
		
		
        /**
         * @brief     定时器1设置定时时间函数。
         * @details   Timer 1 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE TIMER1_Set_Time(uint32_t time)		
		{
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
            TIMER0_TIM_CFG(time);
			if((TMOD & 0x30) == 0x20) T1L = (uint8_t)(time), T1H = (uint8_t)(time); 
            else              T1L = (uint8_t)(time), T1H = (uint8_t)(time >> 8);
			return FSC_SUCCESS;
		}		
		
		
        /**
         * @brief     定时器2设置定时时间函数。
         * @details   Timer 2 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			FSCSTATE TIMER2_Set_Time(uint32_t time)
		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			FSCSTATE TIMER2_Set_Time(uint8_t clkDiv,uint32_t time)	
  		#endif			
		{
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
			#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			{
				TIMER2_TIM_CFG(time);
			}
			#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			{
				EAXFR_ENABLE();
                TM2PS = clkDiv;
                TIMER2_TIM_CFG(time);
                EAXFR_DISABLE();
			}
			#endif	
            T2L = (uint8_t)(time), T2H = (uint8_t)(time >> 8);
			return FSC_SUCCESS;
		}		

		
        /**
         * @brief     定时器3设置定时时间函数。
         * @details   Timer 3 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			FSCSTATE TIMER3_Set_Time(uint32_t time)
		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			FSCSTATE TIMER3_Set_Time(uint8_t clkDiv,uint32_t time)	
  		#endif			
		{
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
			#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			{
				TIMER3_TIM_CFG(time);
			}
			#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			{
				EAXFR_ENABLE();
                TM3PS = clkDiv;
                TIMER3_TIM_CFG(time);
                EAXFR_DISABLE();
			}
			#endif	
            T3L = (uint8_t)(time), T3H = (uint8_t)(time >> 8);
			return FSC_SUCCESS;
		}		

        /**
         * @brief     定时器4设置定时时间函数。
         * @details   Timer 4 sets the timing function.
         * @param[in] time 定时时间。timing. 
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			FSCSTATE TIMER4_Set_Time(uint32_t time)
		#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			FSCSTATE TIMER4_Set_Time(uint8_t clkDiv,uint32_t time)	
  		#endif			
		{
            extern uint32_t Get_SysClk_FRE(void);
            uint32_t sysClk_FRE;
            /* Get system clock frequency */
            sysClk_FRE = Get_SysClk_FRE();
			#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			{
				TIMER4_TIM_CFG(time);
			}
			#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
			{
				EAXFR_ENABLE();
                TM4PS = clkDiv;
                TIMER4_TIM_CFG(time);
                EAXFR_DISABLE();
			}
			#endif	
            T4L = (uint8_t)(time), T4H = (uint8_t)(time >> 8);
			return FSC_SUCCESS;
		}		
		
	#endif
		
		
#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



