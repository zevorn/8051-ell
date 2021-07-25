/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_MPWM.h
  - Author        : slipperstree
  - Update date   : 2020.07.25
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, zeweni (slipperstree@gmail.com)

 * This file is part of 8051 ELL low-layer libraries.

 * 8051 ELL low-layer libraries is free software: you can redistribute 
 * it and/or modify it under the terms of the Apache-2.0 License.

 * 8051 ELL low-layer libraries is distributed in the hope that it will 
 * be useful,but WITHOUT ANY WARRANTY; without even the implied warranty 
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_MPWM_H_
#define __STC8x_MPWM_H_

/*--------------------------------------------------------
| @Description: STC8x core                               |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/

#if  (PER_LIB_MCU_MUODEL == STC8Gx)

    #include "STC8Gx_REG.h"
	
#endif

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#ifndef PER_LIB_MCU_MUODEL 
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */  
    #define PER_LIB_MCU_MUODEL STC8Gx
#endif


#ifndef PER_LIB_MPWM_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_CTRL 1
#endif


#ifndef PER_LIB_MPWM_INIT_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_INIT_CTRL 1
#endif


#ifndef PER_LIB_MPWM_NVIC_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_NVIC_CTRL 1
#endif


#ifndef PER_LIB_MPWM_WORK_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_WORK_CTRL 1
#endif


#if (PER_LIB_MCU_MUODEL == STC8Gx)


    /*--------------------------------------------------------
    | @Description: PWM clock source enum                    |
    --------------------------------------------------------*/

    /**
     * @brief     MPWM系统时钟选择枚举体。
     * @details   PWM clock source Enumerator.
     **/
    typedef enum
    {
        MPWM_SCLK_DIV_1  =  0x00,
        MPWM_SCLK_DIV_2  =  0x01,
        MPWM_SCLK_DIV_3  =  0x02,
        MPWM_SCLK_DIV_4  =  0x03,
        MPWM_SCLK_DIV_5  =  0x04,
        MPWM_SCLK_DIV_6  =  0x05,
        MPWM_SCLK_DIV_7  =  0x06,
        MPWM_SCLK_DIV_8  =  0x07,
        MPWM_SCLK_DIV_9  =  0x08,
        MPWM_SCLK_DIV_10 =  0x09,
        MPWM_SCLK_DIV_11 =  0x0A,
        MPWM_SCLK_DIV_12 =  0x0B,
        MPWM_SCLK_DIV_13 =  0x0C,
        MPWM_SCLK_DIV_14 =  0x0D,
        MPWM_SCLK_DIV_15 =  0x0E,
        MPWM_SCLK_DIV_16 =  0x0F,
        MPWM_TIMER2_PULSE = 0x1F
    }   MPWMCLKSrc_Type;

    /*--------------------------------------------------------
    | @Description: PWM road start level configure enum      |
    --------------------------------------------------------*/

    typedef enum
    {
        MPWM_Start_Low_Level  =  0x00,
        MPWM_Start_High_Level =  0x01  
    }   MPWMStartLevel_Type;

    /*--------------------------------------------------------
    | @Description: PWM port enum                            |
    --------------------------------------------------------*/
    typedef enum
	{
		MPWM_Port_0 = 0x00 , 
		MPWM_Port_1 = 0x01 ,
		MPWM_Port_2 = 0x02 ,
		MPWM_Port_3 = 0x03 ,
		MPWM_Port_4 = 0x04 ,
		MPWM_Port_5 = 0x05
	}   MPWMPort_Type;

    /*--------------------------------------------------------
    | @Description: PWM channel enum                         |
    --------------------------------------------------------*/

    typedef enum
    {
        MPWM_Channel_0 = 0x00 , 
        MPWM_Channel_1 = 0x01 ,
        MPWM_Channel_2 = 0x02 ,
        MPWM_Channel_3 = 0x03 ,
        MPWM_Channel_4 = 0x04 ,
        MPWM_Channel_5 = 0x05 ,
        MPWM_Channel_6 = 0x06 ,
        MPWM_Channel_7 = 0x07
    }   MPWMChannel_Type;


    /*-----------------------------------------------------------------------
    |                             API FUNCTION                              |
    -----------------------------------------------------------------------*/

    /**
     * @brief     PWM端口初始化函数。Init PWM port function.
     * @details   初始化指定端口(0-5)。Init the specified PWM port. (from 0 to 5)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @param[in] clkSrc PWM时钟源。PWM clock source.
     * @param[in] period PWM周期值（计数器重装载值）。PWM period value (counter reload value)
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Port_Init(MPWMPort_Type port, MPWMCLKSrc_Type clkSrc, uint16_t period);

    /**
     * @brief     PWM通道初始化函数。Init PWM channel function.
     * @details   初始化指定端口(0-5)的指定通道(0-7)。Init the specified port's channel (port from 0 to 5, channel from 0 to 7)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @param[in] ch   PWM通道枚举体。PWM channel enumerator.
     * @param[in] level    PWM开始电平。PWM start level.
     * @param[in] fValue   第一个电平翻转点。The value of the first reversal point.
     * @param[in] sValue   第二个电平翻转点。The value of the second reversal point.
     * @param[in] run     运行控制位。Run control bit.
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Channel_Init(MPWMPort_Type port, MPWMChannel_Type ch, MPWMStartLevel_Type level, uint16_t fValue, uint16_t sValue, BOOL run);

    /**
     * @brief     指定PWM端口开始工作。Run specified PWM port.
     * @details   指定PWM端口开始工作，输出PWM波形。Run specified PWM port. (Start PWM signal outputs)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Run(MPWMPort_Type port);

    /**
     * @brief     指定PWM端口停止工作。Stop specified PWM port working.
     * @details   指定PWM端口停止工作，停止输出PWM波形。Stop specified PWM port. (Stop PWM signal outputs)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Stop(MPWMPort_Type port);

#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
