/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_RST.h
  - Author        : zeweni
  - Update date   : 2020.02.06
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
#ifndef __STC8x_RST_H_
#define __STC8x_RST_H_

/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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


#ifndef PER_LIB_RST_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_RST_CTRL 1
#endif


#ifndef PER_LIB_RST_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_RST_INIT_CTRL 1
#endif


#ifndef PER_LIB_RST_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_RST_WORK_CTRL 1
#endif


/**
 * @brief     RST复位方式选择枚举体。
 * @details   RST Reset Select Enumerator.
**/
typedef enum
{

	RST_USER_DATA_KEEP = 0x00,	/*!< 软件复位后，代码从用户程序区执行，并且用户数据区中的数据保持不变。
									 After the software is reset,
									 the code is executed from the user program area, 
									 and the data in the user data area remains unchanged. */
	
	RST_USER_DATA_CLEAN = 0x01 	/*!< 软件复位后，代码从系统的ISP区域执行，并且清除用户数据区域中的数据。
									 After the software is reset,
									 the code is executed from the ISP area of the system,
									 and the data in the user data area is cleared. */
} RSTChoice_Type;


/**
* @brief     低压复位的电压临界点选择枚举体。
 * @details   Low voltage reset Reset working mode enum.
**/
typedef enum
{
  LVD_RST_2_2V = 0x00,  /*!< 2.2V */
  LVD_RST_2_4V = 0x01,  /*!< 2.4V */
  LVD_RST_2_7V = 0x02,  /*!< 2.7V */
  LVD_RST_3_0V = 0x03   /*!< 3.0V */
} LVDRstDiv_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_RST_CTRL == 1)
	
	#if (PER_LIB_RST_INIT_CTRL == 1)

		/**
		 * @brief       低压复位函数，可以选择不同低压复位标准。
		 * @details     Low voltage reset function, 
		 *              you can select different low voltage reset standards.
		 * @param[in]   lvDiv   低压复位标准。low voltage reset standards.
		 * @param[in]   run     使能控制位。 Enable control bit.
		 * @return      FSC_SUCCESS 返回成功。Return to success.
		 * @return      FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE LVD_RST_Init(LVDRstDiv_Type lvDiv,BOOL run);

	#endif
	
	#if (PER_LIB_RST_WORK_CTRL == 1)
	
		/**
		 * @brief        软件复位控制函数。
		 * @details     Software reset function.
		 * @param[in]   choice   复位方式选择。Reset mode selection.
		 * @param[in]   run      使能控制位。 Enable control bit.
		 * @return      FSC_SUCCESS 返回成功。Return to success.
		 * @return      FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE SFW_RST_Ctrl(RSTChoice_Type choice, BOOL run);


		/**
		 * @brief    软件复位自动下载功能，需要在串口中断里调用，
		 *           需要在STC-ISP助手里设置下载口令：10个0x7F。
		 * @details  Software reset automatic download function, 
		 *			 need to be called in serial interrupt,
		 *			 The download password needs to be 
		 *			 set in the STC-ISP assistant: 10 0x7F.
		 * @param    None.
		 * @return   None.
		**/
		void Auto_RST_download(void);


		/**
		 * @brief     使能P54作为复位IO。
		 * @details   Enables P54 to act as a reset IO.
		**/						
		#define    RST_P54_ENABLE()      do{RSTCFG |= 0x10;}while(0)


		/**
		 * @brief     不使能P54作为复位IO。
		 * @details   Disables P54 to act as a reset IO.
		**/				
		#define    RST_P54_DISABLE()     do{RSTCFG &= 0xEF;}while(0)

	#endif
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif