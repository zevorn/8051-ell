/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_COMP.c
  - Author        : zeweni
  - Update date   : 2020.04.23                 
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
#include "STC8x_COMP.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/**
 * @name    COMP_NVIC_PRI
 * @brief   COMP选择中断优先级宏函数，仅限本文件调用。
 *          COMP select interrupt priority macro function, 
 *          only this file call.
***/
#define COMP_NVIC_PRI(pri)                          \
	do{                                             \
		IP2H = (IP2H & 0xEF) | ((pri & 0x02) << 3); \
	    IP2  = (IP2  & 0xEF) | ((pri & 0x01) << 4); \
	}while(0)

/**
 * @name    COMP_TRIState_Select
 * @brief   COMP选择触发模式宏函数，仅限本文件调用。
 *          Comp select trigger state macro function, 
 *          only this file call.
***/
#define COMP_TRISTATE_SELECT(triMode)              \
	do {CMPCR1 = (CMPCR1 & 0xCF)|(triMode);}while(0)

/**
 * @name    COMP_PEINPUT_CFG
 * @brief   COMP选择正极输入脚宏函数，仅限本文件调用。
 *          Comp select positive input pin macro function, 
 *          only this file call.
***/
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
	
	#define  COMP_PEINPUT_SELECT(PEPin)                   \
		do{                                               \ 
			if(PEPin == COMP_PE_P37) {CMPCR1 &= 0xF7;}    \
			else {CMPCR1 |= 0x08;                         \
			ADC_CONTR = (ADC_CONTR & 0xF0)|(PEPin)|0x80;} \
		}while(0)
	
#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Fx)
		
	#define  COMP_PEINPUT_SELECT(PEPin)  do{CMPCR1 &= PEPin;}while(0)
		
#endif	

/**
 * @name    COMP_NEINPUT_SELECT
 * @brief   COMP选择负极输入脚宏函数，仅限本文件调用。
 *          Comp select negative input pin macro function, 
 *          only this file call.
***/
#define  COMP_NEINPUT_SELECT(NEPin)                             \
	do{CMPCR1 = (CMPCR1 & 0xFB) | ((NEPin & 0xF0) >> 2);}while(0)

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None. */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    COMP_Init
  * @brief   COMP初始化函数
  *          COMP init function
  * @param   *compx [IN] COMP结构体句柄，初始化时请定义该句柄，并用其地址来传参。
  *                      COMP structure handle. When initializing, 
  *                      please define the handle and use its address 
  *                      to pass parameters.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE COMP_Init(const COMP_InitType* compx)
{
    if(compx -> DC_FTW > 0x3F) return FSC_FAIL;
    COMP_PEINPUT_SELECT(compx -> PEPin);
    COMP_NEINPUT_SELECT(compx -> NEPin);
    CMPCR2 = (CMPCR2 & 0xBF) | (compx -> AC_FTW << 6);
    CMPCR2 = (CMPCR2 & 0xC0) | (compx -> DC_FTW);
    CMPCR2 = (CMPCR2 & 0x7F) | (compx -> DIRPut << 7);
    CMPCR1 = (CMPCR1 & 0xFD) | (compx -> Output << 1);
    CMPCR1 = (CMPCR1 & 0x7F) | (compx -> Run << 7);
    return FSC_SUCCESS;
}

/**
  * @name    NVIC_COMP_Init
  * @brief   COMP中断初始化函数
  *          COMP interrupt initialization function.
  * @param   priority [IN] 优先级。Priority.
  * @param   triMode  [IN] 触发模式。Trigger mode.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_COMP_Init(NVICPri_Type priority,COMPTri_Type triMode)
{
	COMP_TRISTATE_SELECT(triMode);
	COMP_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    GPIO_COMP_SWPort
  * @brief   COMP切换复用IO函数。
  *          COMP switch out port control function.  
  * @param   port [IN] 复用IO枚举体。IO switch enumerator.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_COMP_SWPort(GPIOSWPort_Type port)
{
	if(port < SW_Port3)
	{
		P_SW2 = (P_SW2 & 0xF7) | (port << 3);
		return FSC_SUCCESS;
	}
	else return FSC_FAIL;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



