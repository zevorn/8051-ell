/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : example_adc.c
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
#include "example_adc.h"
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
 * @brief      ADC外设示例代码初始化。
 * @details    Example code for ADC peripherals initialized.
 * @param      None.
 * @return     None.
 * @note       每种例程，只能调用一个初始化函数和运行函数，各例程之间并不兼容。
 *             Each routine can only call an initialization function and a run function, 
 *             and the routines are not compatible with each other.
**/
void Example_ADC_Init(void)
{
	ADC_InitType ADC_InitStruct = {0};

	ADC_InitStruct.Power = ENABLE; // ADC power control bit
	ADC_InitStruct.Channel = ADC_Channel_P04_8Ax; // ADC channel selection
	ADC_InitStruct.Speed = 0X0F; // The maximum ADC conversion speed (working clock frequency) is 0x0f
	ADC_InitStruct.Align = ADC_Right; // ADC data format alignment
	ADC_InitStruct.Run = ENABLE; //  ADC conversion operation control bit
	ADC_Init(&ADC_InitStruct);		
	
}


/**
 * @brief      运行ADC外设示例代码。
 * @details    Run the ADC peripheral sample code.
 * @param      None.
 * @return     None.
 * @note       每种例程，只能调用一个初始化函数和运行函数，各例程之间并不兼容。
 *             Each routine can only call an initialization function and a run function, 
 *             and the routines are not compatible with each other.
**/
void Example_ADC_Run(void)
{
	uint16_t ret;
	
	ret = ADC_Get_Sample(ADC_Channel_P04_8Ax,ADC_Acc_12Bits);
	
	UART1_Isr_Send_Byte(0xFF);
	UART1_Isr_Send_Byte(ret);
	UART1_Isr_Send_Byte(ret>>8);
	
	DELAY_Set_Ms(500);
}

/**
  * @name    STC8x_Exti_Config
  * @brief   MCU Exti initialization function
  * @param   None
  * @return  None
***/
static void STC8x_Exti_Config(void)
{
	GPIO_MODE_IN_FLOATING(GPIO_P3,Pin_3);
   
	NVIC_EXTI0_Init(EXTI_Tri_Falling,NVIC_PR0,ENABLE);
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



