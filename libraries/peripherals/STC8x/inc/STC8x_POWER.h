/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_POWER.h
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
#ifndef __STC8x_POWER_H_
#define __STC8x_POWER_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "Lib_CFG.h"

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
| @Description: STC8x core                               |
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


#ifndef PER_LIB_POWER_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_POWER_CTRL 1
#endif


#ifndef PER_LIB_POWER_NVIC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_POWER_NVIC_CTRL 1
#endif


#ifndef PER_LIB_POWER_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_POWER_WORK_CTRL 1
#endif


/**
 * @brief   电源工作模式枚举体。
 * @details Power mode enumerator.
**/
typedef enum
{
  POWER_Mode_Normal = 0x00, /*!< 正常模式。 Power normal mode. */
  POWER_Mode_Stop   = 0x02, /*!< 掉电模式。Power down mode. */
  POWER_Mode_Idle   = 0x03  /*!< 空闲模式。Power idle mode. */
} POWERMode_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_POWER_CTRL == 1)
	
	#if (PER_LIB_POWER_WORK_CTRL == 1)

		/**
		 * @brief		电源工作模式控制函数。
		 * @details	    Power mode configure function. 
		 * @param[in]	mode 电源工作模式。Power working mode. 
		 * @return      FSC_SUCCESS 返回成功。Return to success.
		 * @return      FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE POWER_Mode_Ctrl(POWERMode_Type mode);

		/**
		 * @brief		获取电源工作模式函数。
		 * @details	    PGet power mode function. 
		 * @return      POWERMode_Type 电源工作模式。
		**/
		#define POWER_GET_WORK_MODE()  (PCON & 0x10)


		/**
		 * @brief		使能外部静态电流保持电流控制电路，功耗更低。
		 * @details	    Enable external quiescent current to maintain 
		 *              current control circuit, lower power consumption.
		**/
		#define ESH_CURRENT_ENABLE()   VOCTRL = 0x80  /* Use external */
		
		
		/**
		 * @brief		不使能外部静态电流保持电流控制电路，
		 *              选择内部的静态电流保持电流控制电路。
		 * @details	    Disable external quiescent current to maintain 
		 *              current control circuit, lower power consumption.
		**/
		#define ESH_CURRENT_DISABLE()  VOCTRL = 0x00  /* Use internal */

	#endif
	
	#if (PER_LIB_POWER_NVIC_CTRL == 1)
	
		/**
		 * @brief	   低压检测中断初始化函数。
		 * @details	   Low-voltage detection interrupt initialization function.
		 * @param[in]  pri 中断优先级。Interrupt priority.
		 * @param[in]  run 中断运行控制位。Interrupt operation control bit.
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_LVD_Init(NVICPri_Type priority,BOOL run);
		
		 /**
         * @brief   获取比较中断标志位宏函数。
         * @details LVD gets interrupt flag bit macro function.
         * @return  [bit] 完成（也是中断）标志位。Completion (interrupt) flag bit.
        **/
		#define LVD_GET_FLAG()       (PCON & 0x20)
		
		 /**
         * @brief   清除比较中断标志位宏函数。
         * @details LVD clears interrupt flag bit macro function.
         * @return  [bit] 完成（也是中断）标志位。Completion (interrupt) flag bit.
        **/		
		#define LVD_CLEAR_FLAG()     do{PCON &= 0xDF;}while(0)
		
        /**
         * @brief     LVD中断开关控制宏函数。
         * @details   LVD interrupt switch control macro function.
         * @param[in] run 使能控制位。Enable control bit.
        ***/		
		#define    NVIC_LVD_CTRL(run)     do{ELVD = run;}while(0)
		
		
		/**
		 * @brief      LVD选择中断优先级宏函数，仅限本文件调用。
		 * @details    LVD select interrupt priority macro function, 
		 *             only this file call.
		 * @param[in]  pri 中断优先级。 Priority of interrupt.
		**/
		#define NVIC_LVD_PRI(pri)                     \
		do{                                           \
			IPH = (IPH & 0xBF) | ((pri & 0x02) << 5); \
			IP  = (IP  & 0xBF) | ((pri & 0x01) << 6); \
		}while(0)
	
	#endif
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
