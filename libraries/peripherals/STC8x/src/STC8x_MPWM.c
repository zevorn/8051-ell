/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_MPWM.c
  - Author        : slipperstree
  - Update date   : 2021.07.25
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, slipperstree (slipperstree@gmail.com)

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
#include "STC8x_MPWM.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Gx)

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
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
FSCSTATE MPWMn_Port_Init(MPWMPort_Type port, MPWMCLKSrc_Type clkSrc, uint16_t period)
{
    if(period <= 0x7FFF)
    {
    EAXFR_ENABLE();
    PWM_ENABLE(port);
    setRegPWMnCKS(port, clkSrc);
    setRegPWMnC(port, period);
    EAXFR_DISABLE();
    return FSC_SUCCESS;
    }
    else return FSC_FAIL;
}

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
FSCSTATE MPWMn_Channel_Init(MPWMPort_Type port, MPWMChannel_Type ch, MPWMStartLevel_Type level, uint16_t fValue, uint16_t sValue, BOOL run)
{
    if(fValue <= 0x7FFF && sValue <= 0x7FFF)
    {
    EAXFR_ENABLE();
    setRegPWMniT1(port, ch, fValue);
    setRegPWMniT2(port, ch, sValue);
    // 开始电平
    if (level) 
    {
        setBitPWMniStartLevel(port, ch);
    } else {
        clrBitPWMniStartLevel(port, ch);
    }
    // 使能
    if (run)
    {
        setBitPWMniEnableOut(port, ch);
    } else {
        clrBitPWMniEnableOut(port, ch);
    }   
    EAXFR_DISABLE();
    return FSC_SUCCESS;
    }
    else return FSC_FAIL;
}

/**
 * @brief     指定PWM端口开始工作。Run specified PWM port.
 * @details   指定PWM端口开始工作，输出PWM波形。Run specified PWM port. (Start PWM signal outputs)
 * @param[in] port PWM端口枚举体。PWM port enumerator.
 * @return    FSC_SUCCESS 返回成功。Return to success.
 * @return    FSC_FAIL    返回失败。Return to fail.
**/
FSCSTATE MPWMn_run(MPWMPort_Type port){
    EAXFR_ENABLE();
    setBitPWMnCEN(port);
    EAXFR_DISABLE();
    return FSC_SUCCESS;
}

/**
 * @brief     指定PWM端口停止工作。Stop specified PWM port working.
 * @details   指定PWM端口停止工作，停止输出PWM波形。Stop specified PWM port. (Stop PWM signal outputs)
 * @param[in] port PWM端口枚举体。PWM port enumerator.
 * @return    FSC_SUCCESS 返回成功。Return to success.
 * @return    FSC_FAIL    返回失败。Return to fail.
**/
FSCSTATE MPWMn_stop(MPWMPort_Type port){
    EAXFR_ENABLE();
    clrBitPWMnCEN(port);
    EAXFR_DISABLE();
    return FSC_SUCCESS;
}


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



