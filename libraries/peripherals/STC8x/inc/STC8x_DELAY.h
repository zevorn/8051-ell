/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_DELAY.c
  - Author        : zeweni
  - Update date   : 2020.07.23                
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
#ifndef __STC8x_DELAY_H_
#define __STC8x_DELAY_H_

/*--------------------------------------------------------
| @Description: ELL library core                         |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/

#if   (PER_LIB_MCU_MUODEL == STC8Ax)
    #include "STC8Ax_REG.h"  
#elif (PER_LIB_MCU_MUODEL == STC8Cx)
    #include "STC8Cx_REG.h"
#elif (PER_LIB_MCU_MUODEL == STC8Fx)
    #include "STC8Fx_REG.h"
#elif (PER_LIB_MCU_MUODEL == STC8Gx)
    #include "STC8Gx_REG.h"
#elif (PER_LIB_MCU_MUODEL == STC8Hx)
    #include "STC8Hx_REG.h"
#endif

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/**
 * @brief      这是一个非常关键的宏，主要用于实现延时时间的精度。
 *             默认是11000UL，你可以在这个基础上进行微调。
 *             建议使用一个IO翻转，用延时函数延时，通过示波器抓波形进行校准。
 * @details    This is a very critical macro, mainly used to achieve the accuracy of the delay time.
 *             The default is 11000UL, you can make fine adjustments on this basis.
 *             It is recommended to use an IO flip, delay with a delay function in the middle, 
 *             and use an oscilloscope to capture the waveform for calibration.
**/   
#define   DELAY_COUNT         PER_LIB_PREDELAY_BASE


/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_PREDELAY_CTRL == 1)

    /**
     * @brief      精准延时组件初始化。
     * @details    Precisely delay component initialization.  
     * @param      None.
     * @return     FSC_SUCCESS 返回成功。Return to success.
     * @return     FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE DELAY_Init(void);

    /**
     * @brief      上电延时，帮助系统稳定。
     * @details    Power-on delay helps to stabilize the system.
     * @param      None.
     * @return     None.
    **/
    void DELAY_Set_Pos(void); 

 
    /**
     * @brief      延时一段时间，ms级别。
     * @details    Delay for a period of time, ms level.  
     * @param[in]  nms 延时时间.Delay time.
     * @return     None.
    **/   
	void DELAY_Set_Ms(uint16_t nms);


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
