/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_WDT.h
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
#ifndef __STC8x_WDT_H_
#define __STC8x_WDT_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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


#ifndef PER_LIB_RST_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_RST_CTRL 1
#endif


#ifndef PER_LIB_RST_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_RST_INIT_CTRL 1
#endif


#ifndef PER_LIB_RST_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_RST_WORK_CTRL 1
#endif


/*--------------------------------------------------------
| @Description: WDT clock ferquency division define      |
--------------------------------------------------------*/

#define      WDTCLK_DIV2    0x00
#define      WDTCLK_DIV4    0x01
#define      WDTCLK_DIV8    0x02
#define     WDTCLK_DIV16    0x03
#define     WDTCLK_DIV32    0x04
#define     WDTCLK_DIV64    0x05
#define    WDTCLK_DIV128    0x06
#define    WDTCLK_DIV256    0x07

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

#if (PER_LIB_RST_CTRL == 1)

	#if (PER_LIB_RST_INIT_CTRL == 1)
	
		/**
		 * @brief       看门狗初始函数。
		 * @details     WDT initialization function. 
		 * @param[in]   cLKDiv   系统时钟分频数。clock division.
		 * @param[in]   run      运行控制位。Run control bit.
		 * @return      FSC_SUCCESS 返回成功。Return to success.
		 * @return      FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE WDT_Init(uint8_t clKDiv,BOOL run);
	
	#endif
	
	#if (PER_LIB_RST_WORK_CTRL == 1)

		/**
		 * @brief   获取喂狗时间函数，以便定时喂狗。
		 * @details Get WDT  feeding time function.
		 * @param   None.
		 * @return  [uint32_t] 获取喂狗时间，单位us。Get the feeding time, the unit is us.
		**/
		uint32_t Get_WDT_Time(void);


		/**
		 * @brief    喂狗宏函数，如果不定时喂狗，系统将会复位。
		 * @details  Feeding the dog macro function, 
		 *           if the dog is not fed regularly, the system will reset.
		**/
		#define   WDT_FEED()   do{WDT_CONTR |= 0x10;}while(0)

	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif