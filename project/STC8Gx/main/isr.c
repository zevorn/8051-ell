/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : isr.c
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
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    TIMER0_ISRQ_Handler
  * @brief   MCU TIMER0 Interrupt request service function
  * @param   None
  * @return  None
***/
void TIMER0_ISRQ_Handler(void)
{
	static uint16_t i=0;
	if(++i>=500)
	{
		i = 0;
		GPIO_FLIP_PIN_LEVEL(GPIO_P5,Pin_5);
	}
}


/**
  * @name    UART1_ISRQ_Handler
  * @brief   MCU UART1 Interrupt request service function
  * @param   None
  * @return  None
***/
void UART1_ISRQ_Handler(void)
{
	if(UART1_GET_RX_FLAG())
	{
		  UART1_CLEAR_RX_FLAG();
		  Auto_RST_download();
	}
	else if(UART1_GET_TX_FLAG())
	{
		  UART1_CLEAR_TX_FLAG();
		  UART1_CLEAR_BUSY_FLAG();
	}
}

/*--------------------------------------------------------
| @Description: Interrupt service function               |
--------------------------------------------------------*/
/*           
 * TIMER:
 * void TIMER0_ISRQ_Handler(void)                            
 * void TIMER1_ISRQ_Handler(void)
 * void TIMER2_ISRQ_Handler(void)
 * void TIMER3_ISRQ_Handler(void)
 * void TIMER4_ISRQ_Handler(void)
 *
 * UART:
 * void UART1_ISRQ_Handler(void)
 * void UART2_ISRQ_Handler(void)
 * void UART3_ISRQ_Handler(void)
 * void UART4_ISRQ_Handler(void)
 *
 * EXTI:
 * void EXTI0_ISRQ_Handler(void)                             
 * void EXTI1_ISRQ_Handler(void)                             
 * void EXTI2_ISRQ_Handler(void)                             
 * void EXTI3_ISRQ_Handler(void)  
 *
 * ADC:
 * void ADC_ISRQ_Handler(void)
 *
 * COMP:
 * void COMP_ISRQ_Handler(void)
 *
 * PCA:
 * void PCA_ISRQ_Handler(void)
 *
 * LVD:
 * void LVD_ISRQ_Handler(void)
 *
 * PWM:
 * void PWM_ISRQ_Handler(void)
 * void PWM_ABD_ISRQ_Handler(void)
 *
 */

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/