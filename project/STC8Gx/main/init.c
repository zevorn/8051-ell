/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : init.c
  - Author        : zeweni
  - Update date   : 2020.01.11
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

 * You should have received a copy of the Apache-2.0 License.Ant Real Time
 * Operating System. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "main.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: MCU peripheral initialization function   |
--------------------------------------------------------*/

static void STC8x_SYSCLK_Config(void);
static void STC8x_UART_Config(void);
static void STC8x_GPIO_Config(void);
static void STC8x_TIMER_Config(void);
static void STC8x_ADC_Config(void);

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    STC8x_System_Init
  * @brief   MCU initialization function
  * @param   None
  * @return  None
***/
void STC8x_System_Init(void)
{
	
	DELAY_POS(); /* Power on stability delay */	
	//STC8x_SYSCLK_Config(); /* Initialize system clock */
    NVIC_GLOBAL_ENABLE();	
    delay_init();
	
	STC8x_GPIO_Config();
	STC8x_UART_Config();
	STC8x_TIMER_Config();
	STC8x_ADC_Config();
	/*
		Add hardware driver initialization code here.
	*/
	
	
}

/**
  * @name    STC8x_SYSCLK_Config
  * @brief   MCU SYSCLK initialization function
  * @param   None
  * @return  None
***/
static void STC8x_SYSCLK_Config(void)
{
	SYSCLK_InitType SYSCLK_InitStruct={0}; /* Declare structure */

	SYSCLK_InitStruct.MCLKSrc = HIRC;
    SYSCLK_InitStruct.IRCBand = IRC_Band_20MHz;
	SYSCLK_InitStruct.IRCTRIM = 150;
    SYSCLK_InitStruct.LIRCTRIM = TRIM1;
	SYSCLK_InitStruct.MCLKDiv = 2;
	SYSCLK_InitStruct.SCLKDiv = 0; /* if SCLKDiv = 0, Not output */
	SYSCLK_InitStruct.SCLKOutPin = SCLK_OUT_P16;
	SYSCLK_Init(&SYSCLK_InitStruct);
	
}

/**
  * @name    STC8x_GPIO_Config
  * @brief   MCU GPIO initialization function
  * @param   None
  * @return  None
***/
static void STC8x_GPIO_Config(void)
{
    /* Run lamp */
	GPIO_MODE_IN_FLOATING(GPIO_P5,Pin_4);  //P54
	GPIO_MODE_OUT_PP(GPIO_P3,Pin_All);  //P55
}

/**
  * @name    STC8x_TIMER_Config
  * @brief   MCU TIMER initialization function
  * @param   None
  * @return  None
***/
static void STC8x_TIMER_Config(void)
{
	TIMER_InitType TIMER_InitStruct={0};
	
	TIMER_InitStruct.Mode = TIMER_16BitAutoReload;
	TIMER_InitStruct.Value = 1000;     //1ms
	TIMER_InitStruct.Run = ENABLE;
	TIMER0_Init(&TIMER_InitStruct);
	NVIC_TIMER0_Init(NVIC_PR0,ENABLE);
	
}

/**
  * @name    STC8x_UART_Config
  * @brief   MCU UART initialization function
  * @param   None
  * @return  None
***/
static void STC8x_UART_Config(void)
{
	UART_InitType UART_InitStruct = {0};
	
	/* UART1 TXD */
	GPIO_MODE_OUT_PP(GPIO_P3,Pin_1);
	/* UART1 RXD */
	GPIO_MODE_IN_FLOATING(GPIO_P3,Pin_0); 

	UART_InitStruct.Mode = UART_8bit_BRTx;
	UART_InitStruct.BRTGen = UART_BRT_TIM1;
	UART_InitStruct.BRTMode = UART_BRT_1T;
	UART_InitStruct.BaudRate = 115200;
	UART_InitStruct.RxEnable = ENABLE;
	UART1_Init(&UART_InitStruct);
	NVIC_UART1_Init(NVIC_PR0,ENABLE);

}

/**
  * @name    STC8x_ADC_Config
  * @brief   MCU ADC initialization function
  * @param   None
  * @return  None
***/
static void STC8x_ADC_Config(void)
{
	ADC_InitType ADC_InitStruct = {0};
	
    GPIO_MODE_IN_FLOATING(GPIO_P1,Pin_0);
	
	ADC_InitStruct.Power = ENABLE; // ADC power control bit
	ADC_InitStruct.Road = ADC_Road_P10_8G1K08_T; // ADC channel selection
	ADC_InitStruct.Speed = 0x0F; // The maximum ADC conversion speed (working clock frequency) is 0x0f
	ADC_InitStruct.Align = ADC_Right; // ADC data format alignment
	ADC_InitStruct.Run = ENABLE; //  ADC conversion operation control bit
	ADC_Init(&ADC_InitStruct);
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
