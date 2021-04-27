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
static void STC8x_TIMER_Config(void);

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
	
	NVIC_GLOBAL_ENABLE();

	STC8x_TIMER_Config();
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

	UART_InitStruct.Mode = UART_8bit_BRTx;
	UART_InitStruct.BRTGen = UART_BRT_TIM1;
	UART_InitStruct.BRTMode = UART_BRT_1T;
	UART_InitStruct.BaudRate = 115200;
	UART_InitStruct.RxEnable = ENABLE;

	UART1_Init(&UART_InitStruct);
	NVIC_UART1_Init(NVIC_PR3,ENABLE);
	
	GPIO_UART2_SWPort(SW_Port2);
	
	UART_InitStruct.Mode = UART_8bit_BRTx;  // 8位波特率
	UART_InitStruct.BRTGen = UART_BRT_TIM2; //定时器2
	UART_InitStruct.BRTMode = UART_BRT_1T;  // 1T模式
	UART_InitStruct.BRTGenClkDiv = 4;  //预分频数
	UART_InitStruct.BaudRate = 9600;  // 波特率960
	UART_InitStruct.RxEnable = ENABLE; //接收使能

	UART2_Init(&UART_InitStruct);
	NVIC_UART2_Init(NVIC_PR2,ENABLE);	
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

	GPIO_MODE_IN_FLOATING(GPIO_P5,Pin_4);
}

/**
  * @name    STC8x_TIMER_Config
  * @brief   MCU TIMER initialization function
  * @param   None
  * @return  None
***/
void STC8x_TIMER_Config(void)
{
	TIMER_InitType  TIMER_InitStruct = {0};
	
	TIMER_InitStruct.SysClkDiv = 10;
    TIMER_InitStruct.Type = TIMER_Type_Timer;       //timer type
    TIMER_InitStruct.Mode = TIMER_16BitAutoReload;       //Working mode
    TIMER_InitStruct.TCycle = TIMER_TCY_1T;   //Instruction cycle
    TIMER_InitStruct.ClkOut = DISABLE;           //Programmable clock output
    TIMER_InitStruct.Time = 10000;              //Loading initial value 
    TIMER_InitStruct.Run = ENABLE;              //Operation control bit
	
	if(TIMER3_Init(&TIMER_InitStruct) != FSC_SUCCESS)
	{
		printf("Timer3 init erro! \r\n");
	}
	else
	{
		printf("Timer3 init success! \r\n");
	}
	
	NVIC_TIMER3_Init(ENABLE);

}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
