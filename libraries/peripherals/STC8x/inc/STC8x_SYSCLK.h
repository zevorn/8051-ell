/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_SYSCLK.h
  - Author        : zeweni
  - Update date   : 2020.05.03
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
#ifndef __STC8x_SYSCLK_H_
#define __STC8x_SYSCLK_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"


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
| @Description: STC8x core                               |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#ifndef PER_LIB_MCU_MUODEL  
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#ifndef PER_LIB_SYSCLK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_SYSCLK_CTRL 1
#endif

#ifndef PER_LIB_SYSCLK_VALUE   
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_SYSCLK_VALUE 0
#endif


#ifndef PER_LIB_SYSCLK_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_SYSCLK_INIT_CTRL 1
#endif


#ifndef PER_LIB_SYSCLK_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_SYSCLK_WORK_CTRL 1
#endif

/*--------------------------------------------------------
| @Description: System clock ferquency division define   |
--------------------------------------------------------*/

#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx )

    #define     SYSCLK_DIV1     0x10
    #define     SYSCLK_DIV2     0x20
    #define     SYSCLK_DIV4     0x40
    #define     SYSCLK_DIV8     0x70
    #define    SYSCLK_DIV16     0x90
    #define    SYSCLK_DIV32     0xB0
    #define    SYSCLK_DIV64     0xD0
    #define   SYSCLK_DIV128     0xF0

#endif

/** 
 * @brief   IRC频率微调枚举体。
 * @details	IRC frequency little trimmer enum.
**/
typedef enum
{
	TRIM0 = 0x00, /*!< 微调等级0。Fine-tuning level 0. */
	TRIM1 = 0x01, /*!< 微调等级1。Fine-tuning level 1. */
	TRIM2 = 0x02, /*!< 微调等级2。Fine-tuning level 2. */
    TRIM3 = 0x03  /*!< 微调等级3。Fine-tuning level 3. */
}   LIRCTRIM_Type;


/** 
 * @brief	系统时钟输出引脚枚举体。
 * @details	System clock out pin enum.
**/
typedef enum
{
	SCLK_OUT_P54 = 0x00, /*!< 输出时钟到P54。GPIO Port 5 pin 4 */
	SCLK_OUT_P16 = 0x01  /*!< 输出时钟到P16。GPIO Port 1 pin 6 */
}   SCLKOut_Type;


/** 
 * @brief	系统主时钟源枚举体。
 * @details	Master clock source enum.
**/
typedef enum
{
	AUTO = 0x00,   /*!< 由STC-ISP助手设置。 stc -isp toll control. */
	HIRC = 0x01,   /*!< 选择内部高速IRC时钟。High internal 4MHz~24MHz oscillator. */
	LIRC = 0x02,   /*!< 选择内部32K时钟。Internal 32KHz oscillator. */
	#if (PER_LIB_MCU_MUODEL == STC8Hx)
		X32KSC = 0x03,  /*!< 选择外部32K时钟。External  32KHzoscillator control. */
	#endif
    XOSC = 0x04    /*!< 选择外部晶振。 External oscillator control. */
} MCLKSrc_Type;


#if (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

	/** 
	 * @brief	IRC频段选择器枚举体。
	 * @details	IRC band selector enum.
	**/
    typedef enum
    {
        IRC_Band_20MHz = 0x00, /*!< 选择20M频段。 Select the 20M frequency band. */
		#if   (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx)
				IRC_Band_33MHz = 0x01 /*!< 选择33M频段。 Select the 33M frequency band. */
		#elif (PER_LIB_MCU_MUODEL == STC8Hx)
				IRC_Band_35MHz = 0x01 /*!< 选择35M频段。 Select the 35M frequency band. */
		#endif
    }  IRCBand_Type;
	
#endif

#if (PER_LIB_MCU_MUODEL == STC8Hx)
	
	/** 
	 * @brief	外部晶振滤波频段枚举体。
	 * @details	External crystal filter enum.
	**/	
    typedef enum
    {
        XOSC_Filter_150MHz = 0x00,
        XOSC_Filter_125MHz = 0x01,
        XOSC_Filter_66MHz  = 0x02,
        XOSC_Filter_Null   = 0x03
    }   XOSCFilter_Type;

#endif

/**
 * @brief	系统时钟初始化结构体句柄，需要在函数初始化时定义它，并用其地址传参。
 * @details	System clock init struct type.
**/
typedef struct
{
    MCLKSrc_Type MCLKSrc;  /*!< 主时钟源。Master clock source. */
    uint8_t IRCTRIM;    /*!< IRC时钟频率调整。IRC frequency trimmer. */
    LIRCTRIM_Type LIRCTRIM;  /*!< IRC时钟频率微调。 IRC little trimmer. */
	#if (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
		IRCBand_Type  IRCBand; /*!< 选择IRC频段。IRC band selector. */
	#endif
    uint8_t MCLKDiv;  /*!< 主时钟分频。 Master clock frequency 
	                        division Parameter range: 0 <= MDiv <= 255. */
    uint8_t SCLKDiv;  /*!< 系统时钟分频。System clock ferquency division. */
    SCLKOut_Type SCLKOutPin; /*!< 选择系统时钟输出脚。Select system clock output pin. */
#if (PER_LIB_MCU_MUODEL == STC8Hx)
    XOSCFilter_Type XOSCFilter; /*!< 外部晶振滤波频段。External crystal filter. */
#endif

} SYSCLK_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_SYSCLK_CTRL == 1)

	#if (PER_LIB_SYSCLK_INIT_CTRL == 1)

		/**
		 * @brief     系统时钟初始化函数。 
		 * @details   System clock init function.
		 * @param[in] sysClkn 系统时钟初始化结构体句柄，需要在初始化时定义它，并用其地址传参。
							  The system clock initializes the structure handle, 
							  which needs to be defined during initialization and its 
							  address is used to pass parameters.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE SYSCLK_Init(const SYSCLK_InitType *sysClkn);

	#endif

	#if (PER_LIB_SYSCLK_WORK_CTRL == 1)

		/**
		 * @brief   获取系统时钟频率函数，用于定时器、串口、EEPROM等进行时钟计算。
		 *          这个函数只能获取内部IRC做时钟源时的系统频率，如果你使用的是外部晶振，
		 *          请在Lib_CFG.h中配置PER_LIB_SYSCLK_VALUE宏，填写你的系统时钟频率。
		 * @details Get System clock frequendy function.
		 * @param   None
		 * @return  [uint32_t] 时钟频率。value of system clock frequenction. 
		**/
		uint32_t Get_SysClk_FRE(void);

	#endif
	
#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
