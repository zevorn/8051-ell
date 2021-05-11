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
static void STC8x_PCA_Config(void);

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
	STC8x_PCA_Config();
	
	NVIC_GLOBAL_ENABLE();
	
	STC8x_TIMER_Config();
}

/**
  * @name    STC8x_PCA_Config
  * @brief   MCU PCA initialization function
  * @param   None
  * @return  None
***/
static void STC8x_PCA_Config(void)
{
   TIMER_InitType TIMER_InitStruct={0};

    /**
     * PCA至PWM频率：
     * 如果系统时钟频率== 24Mhz，
     * 配置PCA时钟源= Timer0溢出脉冲，
     * 配置定时器0 = 19 us
     * 配置PCA位= 10位
     * 因此时钟源的pca = 52.6KHZ
     * 因此，PCA至PWM频率= 52.6 / 1024 Hz = 51Hz
    **/

    /*
     * PCA to PWM frequency:
     * If system clock frequency == 24Mhz,
     * to configure PCA clock source = Timer0 overflow pulse,
     * to configure timer0 = 19 us
     * to configure PCA  bits = 10 bits
     * so pca of clock source = 52.6KHZ
     * so, PCA to PWM frequency = 52.6 / 1024 Hz = 51Hz
     */
	TIMER_InitStruct.Mode = TIMER_16BitAutoReload;
	TIMER_InitStruct.Time = 19;     //19us
	TIMER_InitStruct.Run = ENABLE;
	TIMER0_Init(&TIMER_InitStruct);
    
    /**
     * 配置占空比：
     * 配置PCA位= 10位
     * 值= 0x200
     * 因此，占空比=（0x400-0x200）/ 0x400 = 50％
    **/
   
    /*
     * duty:
     * to configure PCA  bits = 10 bits
     * to  value = 0x200
     * so, duty = (0x400 - 0x200) / 0x400 = 50%
     */
     PCA0_PWM_10BITS_CTRL(0x200);
     PCA_CNT_Init(PCA_TIMER0,ENABLE);
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
	
    TIMER_InitStruct.Type = TIMER_Type_Timer;       //timer type
    TIMER_InitStruct.Mode = TIMER_16BitAutoReload;       //Working mode
    TIMER_InitStruct.TCycle = TIMER_TCY_1T;   //Instruction cycle
    TIMER_InitStruct.ClkOut = DISABLE;           //Programmable clock output
    TIMER_InitStruct.Value = 1000;              //Loading initial value
    TIMER_InitStruct.Run = ENABLE;              //Operation control bit
	
	if(TIMER0_Init(&TIMER_InitStruct) != FSC_SUCCESS)
	{
		printf("Timer0 init erro! \r\n");
	}
	else
	{
		printf("Timer0 init success! \r\n");
	}
	
	NVIC_TIMER0_Init(NVIC_PR1,ENABLE);

}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
