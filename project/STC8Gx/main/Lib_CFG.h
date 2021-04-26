/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : Lib_CFG.h
  - Author        : zeweni
  - Update date   : 2020.02.06                  
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
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
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __Lib_CFG_H_
#define __Lib_CFG_H_
/*-----------------------------------------------------------------------
|                                 CONFIG                                |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: STC8x Peripheral config                  |
--------------------------------------------------------*/

#define    STC8Ax      (0)
#define    STC8Cx      (1)
#define    STC8Fx      (2)
#define    STC8Gx      (3)
#define    STC8Hx      (4)

#define    PER_LIB_MCU_MUODEL     STC8Gx

/**
 * @brief		配置ADC片内外设。
 * @details	    Configure ADC chip internal  peripheral.
**/
#define   PER_LIB_ADC_CTRL         (0) /*!< ADC模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_ADC_INIT_CTRL    (1) /*!< ADC模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_ADC_NVIC_CTRL    (1) /*!< ADC模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_ADC_WORK_CTRL    (1) /*!< ADC模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置COMP片内外设。
 * @details	    Configure COMP chip internal  peripheral.
**/
#define   PER_LIB_COMP_CTRL         (0) /*!< COMP模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_COMP_INIT_CTRL    (1) /*!< COMP模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_COMP_NVIC_CTRL    (1) /*!< COMP模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_COMP_WORK_CTRL    (1) /*!< COMP模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置EEPROM片内外设。
 * @details	    Configure EEPROM chip internal  peripheral.
**/
#define   PER_LIB_EEPROM_CTRL         (0) /*!< EEPROM模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_EEPROM_INIT_CTRL    (1) /*!< EEPROM模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_EEPROM_WORK_CTRL    (1) /*!< EEPROM模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置GPIO片内外设。
 * @details	    Configure GPIO chip internal  peripheral.
**/
#define   PER_LIB_GPIO_CTRL         (1) /*!< GPIO模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_GPIO_INIT_CTRL    (1) /*!< GPIO模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_GPIO_NVIC_CTRL    (1) /*!< GPIO模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_GPIO_WORK_CTRL    (1) /*!< GPIO模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置TIMER片内外设。
 * @details	    Configure TIMER chip internal  peripheral.
**/
#define   PER_LIB_TIMER_CTRL         (1) /*!< TIMER模块控制宏，写1开启，写0关闭。*/
											  
#define   PER_LIB_TIMER_INIT_CTRL    (1) /*!< TIMER模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_TIMER_NVIC_CTRL    (1) /*!< TIMER模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_TIMER_WORK_CTRL    (1) /*!< TIMER模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置MDU16片内外设。
 * @details	    Configure MDU16 chip internal  peripheral.
**/
#define   PER_LIB_MDU16_CTRL         (1) /*!< MDU16模块控制宏，写1开启，写0关闭。*/


/*--------------------------------------------------------
| @Description: STC8x Driver config                      |
--------------------------------------------------------*/

/**
  * @name    KeyScan
  * @brief   You need to config key scan.  
***/
#define  DRV_LIB_KEYSCAN_CTRL        (0)    // "1" is enable, "0" is disable 
#define  DRV_LIB_KEYSCAN_NUM_MAX     (8)    // key scan number max


/*--------------------------------------------------------
| @Description: STC8x Componets config                   |
--------------------------------------------------------*/

/**
  * @name    PrintfRed
  * @brief   You need to initialize the uart bay yourself.  
***/
#define  COM_LIB_PRINTFRED_CTRL        (1)    // "1" is enable, "0" is disable 
#define  COM_LIB_PRINTFRED_ROAD        (1)    // Select printf uart(1\2\3\4)
#define  DEBUG_CTRL                    (1)    // "1" is enable, "0" is disable 

/**
  * @name    TMT
  * @brief   Task time tool
***/
#define  COM_LIB_TMT_CTRL              (0)    // "1" is enable, "0" is disable 
#define  COM_LIB_TMT_TASK_NUM_MAX      (8)    // task number max
#define  COM_LIB_NVIC_TIMER_ISR_ENABLE    ET0 = 1
#define  COM_LIB_NVIC_TIMER_ISR_DISABLE   ET0 = 0

/**
  * @name    PreDelay
  * @brief   Precision delay
***/
#define  COM_LIB_PREDELAY_CTRL        (1)     // "1" is enable, "0" is disable 
#define  COM_LIB_PREDELAY_BASE        (11000UL) // PREDELAY number max


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


