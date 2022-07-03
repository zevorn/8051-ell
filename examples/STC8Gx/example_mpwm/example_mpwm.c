/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : example_mpwm.c
  - Author        : slipperstree
  - Update date   : 2022.07.03
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2022, slipperstree (https://gitee.com/slipperstree)

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
#include "example_mpwm.h"
#include "ELL_LIB.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None. */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @brief      MPWM外设示例代码初始化。
 * @details    Example code for MPWM peripherals initialized.
 * @param      None.
 * @return     None.
 * @note       每种例程，只能调用一个初始化函数和运行函数，各例程之间并不兼容。
 *             Each routine can only call an initialization function and a run function, 
 *             and the routines are not compatible with each other.
**/
void Example_MPWM_Init(void)
{
	GPIO_MODE_OUT_PP(GPIO_P0,Pin_4);
	GPIO_MODE_OUT_PP(GPIO_P0,Pin_5);
	GPIO_MODE_OUT_PP(GPIO_P4,Pin_7);

	/* Init PWM port 0 */
	UART1_Isr_Send_String("Init PWM port 0 \r\n");
	MPWMn_Port_Init(MPWM_Port_0, MPWM_SCLK_DIV_16, 0x1000);	

	/* Init PWM channel P04 */
	UART1_Isr_Send_String("Init PWM channel P04 \r\n");
	MPWMn_Channel_Init(MPWM_Port_0, MPWM_Channel_4, MPWM_Start_Low_Level, 0x0000, 0x0200, ENABLE);

	/* Init PWM channel P05 but output is disabled */
	UART1_Isr_Send_String("Init PWM channel P05 but output is disabled \r\n");
	MPWMn_Channel_Init(MPWM_Port_0, MPWM_Channel_5, MPWM_Start_Low_Level, 0x0000, 0x0500, DISABLE);

	/* Init PWM channel P47 while PWM port 4 hasn't initalized yet */
	UART1_Isr_Send_String("Init PWM channel P47 while PWM port 4 hasn't initalized yet \r\n");
	MPWMn_Channel_Init(MPWM_Port_4, MPWM_Channel_7, MPWM_Start_Low_Level, 0x0100, 0x0500, ENABLE);

	/* Init PWM port 4 */
	UART1_Isr_Send_String("Init PWM port 4 \r\n");
	MPWMn_Port_Init(MPWM_Port_4, MPWM_SCLK_DIV_16, 0x1000);
}


/**
 * @brief      运行MPWM外设示例代码。
 * @details    Run the MPWM peripheral sample code.
 * @param      None.
 * @return     None.
 * @note       每种例程，只能调用一个初始化函数和运行函数，各例程之间并不兼容。
 *             Each routine can only call an initialization function and a run function, 
 *             and the routines are not compatible with each other.
**/
void Example_MPWM_Run(void)
{
	/* Run PWM port 0 */
	/* 启动 PWM port 0 */
	MPWMn_Run(MPWM_Port_0);

	/* Run PWM port 4 */
	/* 启动 PWM port 4 */
	MPWMn_Run(MPWM_Port_4);

	DELAY_Set_Ms(3000);  // Wait a while to see what happening 等待一会观察现象
	// Now, P04 is working. 现在 P04已经工作了（在Init函数中已经初始化过P04并将OutPut设置为ENABLE）
	//      P05 is not work cause output is disabled P05并没有开始工作因为在Init中P05的OutPut设置为Disable
	//      P47 is not work cause PORT MUST BE INITALIZED FIRST BEFORE CHANNEL P07也没有工作因为PORT必须在通道之前初始化，顺序不能反了
	// 

	/* Enable P05 Output by Set Register [PWMnCR]'s bit [ENO[7:7]] to 1 directly 可以通过设置寄存器的方式将P05的output设置为enable */
	/* (Or you can just call MPWMn_Channel_Init() again by pass ENABLE to last param [run]) 你也可以重新调用一次初始化函数 MPWMn_Channel_Init 并设置为ENABLE*/
	EAXFR_ENABLE();
	setBitPWMniEnableOut(MPWM_Port_0, MPWM_Channel_5);
	EAXFR_DISABLE();

	DELAY_Set_Ms(3000);  // Wait a while to see what happening 等待一会观察现象
	// 
	// P05 is now working. fine. 现在P05开始工作了
	// 

	/* Like P05, let's try enable P47 Output by Set Register [PWMnCR]'s bit [ENO[7:7]] to 1 directly 和P05一样尝试通过设置寄存器的方式将P47的output设置为enable */
	EAXFR_ENABLE();
	setBitPWMniEnableOut(MPWM_Port_4, MPWM_Channel_7);
	EAXFR_DISABLE();

	DELAY_Set_Ms(3000);  // Wait a while to see what happening 等待一会观察现象
	//
	// Oh no! P47 is still sleeping cause initalized values(StartLevel/T1/T2) hasn't been affected at all. 此时P47依然没有开始工作
	// 

	/* So you need init P47 by call MPWMn_Channel_Init() again 你需要调用MPWMn_Channel_Init重新初始化一次P47 */
	MPWMn_Channel_Init(MPWM_Port_4, MPWM_Channel_7, MPWM_Start_Low_Level, 0x0100, 0x0500, ENABLE);

	DELAY_Set_Ms(3000);  // Wait a while to see what happening 等待一会观察现象
	//
	// P47 is running now! P47现在正常工作了
	// PORT MUST BE INITALIZED FIRST BEFORE CHANNEL. PORT必须在通道之前初始化，不要忘记这一点
	// Don't forget it.
	// 

	/* Stop PWM port 0 停止PORT0的PWM */
	MPWMn_Stop(MPWM_Port_0);

	DELAY_Set_Ms(3000);  // Wait a while to see what happening 等待一会观察现象
	//
	// Now, P04/P05 stoped. P04和P05停止工作了
	// 
	
	/* Stop PWM port 4 停止PORT4的PWM  */
	UART1_Isr_Send_String("Stop PWM port 4 \r\n");
	MPWMn_Stop(MPWM_Port_4);

	DELAY_Set_Ms(3000);  // Wait a while to see what happening 等待一会观察现象
	//
	// Now, P47 stoped as well. P47也停止工作了
	//

	DELAY_Set_Ms(5000);  // Wait a while to see what happening
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT slipperstree            |
-----------------------------------------------------------------------*/



