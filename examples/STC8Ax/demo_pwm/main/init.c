/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : init.c
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

/*--------------------------------------------------------
| @Description: MCU peripheral initialization function   |
--------------------------------------------------------*/

static void STC8x_UART_Config(void);
static void STC8x_GPIO_Config(void);
static void STC8x_PWM_Config(void);

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
	delay_init(); /* Initialization delay function */

	STC8x_UART_Config();
	STC8x_GPIO_Config();
	STC8x_PWM_Config();

	NVIC_GLOBAL_ENABLE();
}

/**
  * @name    STC8x_UART_Config
  * @brief   MCU UART initialization function
  * @param   None
  * @return  None
***/
static void STC8x_UART_Config(void)
{
	UART_InitType UART_InitStruct={0};	

	/* UART1 TXD */
	GPIO_MODE_OUT_PP(GPIO_P3,Pin_1);
	/* UART1 RXD */
	GPIO_MODE_IN_FLOATING(GPIO_P3,Pin_0); 

	GPIO_UART1_SWPort(SW_Port1);

	UART_InitStruct.Mode = UART_8bit_BRTx;
	UART_InitStruct.BRTGen = UART_BRT_TIM1;
	UART_InitStruct.BRTMode = UART_BRT_1T;
	UART_InitStruct.BaudRate = 115200;
	UART_InitStruct.RxEnable = ENABLE;

	UART1_Init(&UART_InitStruct);
	NVIC_UART1_Init(NVIC_PR3,ENABLE);
}

/**
  * @name    STC8x_GPIO_Config
  * @brief   MCU GPIO initialization function
  * @param   None
  * @return  None
***/
static void STC8x_GPIO_Config(void)
{
	GPIO_MODE_WEAK_PULL(GPIO_P0,Pin_All);
	GPIO_MODE_WEAK_PULL(GPIO_P1,Pin_All);
	GPIO_MODE_WEAK_PULL(GPIO_P2,Pin_All);
	GPIO_MODE_WEAK_PULL(GPIO_P3,Pin_All);
	GPIO_MODE_WEAK_PULL(GPIO_P4,Pin_All);

	RST_P54_ENABLE();
}

/**
  * @name    STC8x_PWM_Config
  * @brief   MCU ADC initialization function
  * @param   None
  * @return  None
***/
static void STC8x_PWM_Config(void)
{
	GPIO_MODE_OUT_PP(GPIO_P2,Pin_5);
	GPIO_PWM5_SWPort(SW_Port1);


   /**
    * 配置PWM频率：
    * 如果系统时钟频率== 24Mhz，
    * 配置PWM_SCLK_DIV = 1，
    * 配置计数频率= 0x1000（4096）
    * 因此，PWM频率= 24M /（1 * 4096）Hz = 5.86KHz
    *
    * 配置占空比：
    * 配置启动的PWM电平=高电平，
    * 配置第一个点= 0x100，
    * 配置第二点= 0x500，
    * 因此，占空比=（0x1000-（0x500-0x100））/ 0x1000 = 75％
   **/

    /*
     * PWM frequency:
     * If system clock frequency == 24Mhz,
     * to configure PWM_SCLK_DIV = 1,
     * to configure frequency of counts = 0x1000( 4096 )
     * so, PWM frequency = 24M / (1*4096) Hz = 5.86KHz
     * 
     * duty:
     * to configure PWM level of start = High level,
     * to configure first point = 0x100,
     * to configure second point = 0x500,
     * so, duty = (0x1000-(0x500-0x100))/0x1000 = 75%
     */

	PWM5_Init(PWM_Start_High_Level,0x0100,0x0500,ENABLE);
	PWM_CNT_Init(PWM_SCLK_DIV_1,0x1000,ENABLE);

}
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
