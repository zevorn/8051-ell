/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : isr.c
  - Author        : zeweni
  - Update date   : 2020.01.11
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
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