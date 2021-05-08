/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_GPIO.c
  - Author        : zeweni
  - Update date   : 2020.04.24
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
#include "STC8x_GPIO.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_GPIO_CTRL == 1)

	#if (PER_LIB_GPIO_NVIC_CTRL == 1)

		/**
		 * @brief     外部中断0中断初始化函数。
		 * @details   EXTI0 NVIC function.
		 * @param[in] triMode  触发模式。Trigger mode. 
		 * @param[in] pri 中断优先级。interrupt priority.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI0_Init(EXTITri_Type triMode,NVICPri_Type pri,BOOL run)
		{
			IT0 = triMode;
			EX0 = run;
			NVIC_EXTI0_PRI(pri);
			return FSC_SUCCESS;
		}


		/**
		 * @brief      外部中断1中断初始化函数。
		 * @details    EXTI1 NVIC function.
		 * @param[in]  triMode  触发模式。Trigger mode. 
		 * @param[in]  pri 中断优先级。interrupt priority.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI1_Init(EXTITri_Type triMode,NVICPri_Type pri,BOOL run)
		{
			IT1 = triMode;
			EX1 = run;
			NVIC_EXTI1_PRI(pri);
			return FSC_SUCCESS;
		}

		/**
		 * @brief      外部中断2中断初始化函数,固定下降沿触发。
		 * @details    EXTI2 NVIC function.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI2_Init(BOOL run)
		{
			INTCLKO = (INTCLKO & 0xEF) | (run << 4);
			return FSC_SUCCESS;
		}


		/**
		 * @brief      外部中断3中断初始化函数，固定下降沿触发。
		 * @details    EXTI3 NVIC function.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI3_Init(BOOL run)
		{
			INTCLKO = (INTCLKO & 0xDF) | (run << 5);
			return FSC_SUCCESS;
		}


		/**
		 * @brief      外部中断4中断初始化函数，固定下降沿触发。
		 * @details    EXTI4 NVIC function.
		 * @param[in]  pri 中断优先级。interrupt priority.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI4_Init(NVICPri_Type pri,BOOL run)
		{
			NVIC_EXTI4_PRI(pri);
			INTCLKO = (INTCLKO & 0xBF) | (run << 6);
			return FSC_SUCCESS;
		}
		
	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



