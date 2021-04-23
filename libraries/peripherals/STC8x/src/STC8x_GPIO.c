/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_GPIO.c
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
#include "STC8x_GPIO.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/**
 * @name    EXTI0_NVIC_PRI
 * @brief   EXTI0选择中断优先级宏函数，仅限本文件调用。
 *          EXTI0 select interrupt priority macro function, 
 *          only this file call.
***/
#define EXTI0_NVIC_PRI(pri) { \
IPH = (IPH & 0xFE) | ((pri & 0x02) >> 1); \
IP  = (IP  & 0xFE) | (pri & 0x01); }


/**
 * @name    EXTI1_NVIC_PRI
 * @brief   EXTI1选择中断优先级宏函数，仅限本文件调用。
 *          EXTI1 select interrupt priority macro function, 
 *          only this file call.
***/
#define EXTI1_NVIC_PRI(pri) { \
IPH = (IPH & 0xFB) | ((pri & 0x02) << 1); \
IP  = (IP  & 0xFB) | ((pri & 0x01) << 2); }

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
/**
  * @name    EXTI0_TRIMode_Init
  * @brief   EXTI0 trigger mode function
  * @param   triMode   EXTI_Tri_Edge | EXTI_Tri_Falling
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE EXTI0_Init(EXTITri_Type triMode)
{
	IT0 = triMode;
	return FSC_SUCCESS;
}

/**
  * @name    EXTI1_TRIMode_Init
  * @brief   EXTI1 trigger mode function
  * @param   triMode   EXTI_Tri_Edge | EXTI_Tri_Falling
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE EXTI1_Init(EXTITri_Type triMode)
{
	IT1 = triMode;
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI0_Init
  * @brief   EXTI0 NVIC function  
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI0_Init(NVICPri_Type priority,BOOL run)
{
	EX0 = run;
    EXTI0_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI1_Init
  * @brief   EXTI1 NVIC function  
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI1_Init(NVICPri_Type priority,BOOL run)
{
	EX1 = run;
    EXTI1_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI2_Init
  * @brief   EXTI2 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI2_Init(BOOL run)
{
	INTCLKO = (INTCLKO & 0xEF) | (run << 4);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI3_Init
  * @brief   EXTI3 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI3_Init(BOOL run)
{

	INTCLKO = (INTCLKO & 0xDF) | (run << 5);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI4_Init
  * @brief   EXTI4 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI4_Init(BOOL run)
{
	INTCLKO = (INTCLKO & 0xBF) | (run << 6);
	return FSC_SUCCESS;
}


/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



