/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : example_pca.c
  - Author        : zeweni
  - Update date   : 2020.07.31
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
#include "example_pca.h"
#include "ELL_LIB.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#define EXAMPLE_CTRL     (0)

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @brief      PAC外设作为PWM示例代码初始化。
 * @details    The PAC peripheral is initialized as the PWM sample code.
 * @param      None.
 * @return     None.
 * @note       每种例程，只能调用一个初始化函数和运行函数，各例程之间并不兼容。
 *             Each routine can only call an initialization function and a run function, 
 *             and the routines are not compatible with each other.
**/
void Example_PCA_To_PWM_Init(void)
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
     PCA3_PWM_Init(PCA_PWM_10Bits,0x200);
     PCA_CNT_Init(PCA_TIMER0,ENABLE);
}





/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



