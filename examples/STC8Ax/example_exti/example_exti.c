/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : example_exti.c
  - Author        : zeweni
  - Update date   : 2020.07.23
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
#include "example_exti.h"
#include "ELL_LIB.h"
#include "stdio.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None. */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @brief      外部中断外设示例代码初始化。
 * @details    External interrupt peripheral sample code initialization.
 * @param      None.
 * @return     None.
**/
void Example_EXTI_Init(void)
{
	GPIO_MODE_IN_FLOATING(GPIO_P3,Pin_3);
   
	NVIC_EXTI0_Init(EXTI_Tri_Falling,NVIC_PR0,ENABLE);
}

#if 0

/**
 * @brief      外部0中断服务函数。
 * @details    External 0 interrupt service function.
 * @param      None.
 * @return     None.
**/
void EXTI0_ISRQ_Handler(void)
{
	static uint16_t cnt = 0;
	UART1_Isr_Send_Byte(cnt++);
}

#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



