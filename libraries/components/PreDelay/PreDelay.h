/*----------------------------------------------------------------------
  - File name      : com_pre_delay.h
  - Author         : Quark Team
  - Update date    : 2020-12-29                  
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Printf redirection component.
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
#ifndef __COM_Pre_DELAY_H_
#define __COM_Pre_DELAY_H_

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"

#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#if    (PER_LIB_MCU_MUODEL == STC8Ax)
    #include "STC8Ax_REG.h"  
#elif  (PER_LIB_MCU_MUODEL == STC8Cx)
    #include "STC8Cx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Fx)
    #include "STC8Fx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Gx)
    #include "STC8Gx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Hx)
    #include "STC8Hx_REG.h"
#endif

/*--------------------------------------------------------
| @Description: STC8x MCU core                           |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/**
 * @brief      这是一个非常关键的宏，主要用于实现延时时间的精度。
 *             默认是11000UL，你可以在这个基础上进行微调。
 *             建议使用一个IO翻转，中间用延时函数延时，用示波器抓波形进行校准。
 * @details    This is a very critical macro, mainly used to achieve the accuracy of the delay time.
 *             The default is 11000UL, you can make fine adjustments on this basis.
 *             It is recommended to use an IO flip, delay with a delay function in the middle, 
 *             and use an oscilloscope to capture the waveform for calibration.
**/   
#define   DELAY_COUNT         COM_LIB_PREDELAY_BASE


/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (COM_LIB_PREDELAY_CTRL == 1)

    /**
     * @brief      精准延时组件初始化。
     * @details    Precisely delay component initialization.  
     * @param      None.
     * @return     FSC_SUCCESS 返回成功。Return to success.
     * @return     FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE Pre_Delay_init(void);

    /**
     * @brief      上电延时，帮助系统稳定。
     * @details    Power-on delay helps to stabilize the system.
     * @param      None.
     * @return     None.
    **/
    void Pre_Delay_Pos(void); 

 
    /**
     * @brief      延时一段时间，ms级别。
     * @details    Delay for a period of time, ms level.  
     * @param[in]  nms 延时时间.Delay time.
     * @return     None.
    **/   
	void Pre_Delay_ms(uint16_t nms);


    /**
     * @brief      延时组件初始化函数重命名。
     * @details    The delay component initialization function is renamed.
    **/   
	#define delay_init    Pre_Delay_init


    /**
     * @brief      延时ms级别时间函数重命名。
     * @details    Delay ms level time function renamed.
    **/   
	#define delay_ms      Pre_Delay_ms


    /**
     * @brief      上电延时函数重命名。
     * @details    Rename the power-on delay function.
    **/   
	#define DELAY_POS     Pre_Delay_Pos


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
