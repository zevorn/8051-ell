/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : Lib_CFG.h
  - Author        : zeweni
  - Update date   : 2020.05.03                 
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
#define    STC8AxD4    (1)
#define    STC8Cx      (2)
#define    STC8Fx      (3)
#define    STC8Gx      (4)
#define    STC8Hx      (5)


/**
 * @brief		配置ELL库MCU选型。
 * @details	    Configure ADC chip internal  peripheral.
**/
#define    PER_LIB_MCU_MUODEL     STC8Ax


/**
 * @brief		配置系统时钟管理片内外设，没有中断相关的控制宏。
 * @details	    Configure the system clock for time calculation.
**/
#define   PER_LIB_SYSCLK_CTRL        (1) /*!< 系统时钟模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_SYSCLK_INIT_CTRL   (1) /*!< 系统时钟模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_SYSCLK_WORK_CTRL   (1) /*!< 系统时钟模块工作相关宏，写1开启，写0关闭。*/
#define   PER_LIB_SYSCLK_VALUE     (0UL) /*!< 等于0,自动获取系统时钟 */


/**
 * @brief		配置TIMER片内外设，没有工作相关的控制宏。
 * @details	    Configure TIMER chip internal  peripheral.
**/
#define   PER_LIB_TIMER_CTRL         (1) /*!< TIMER模块控制宏，写1开启，写0关闭。*/
											  
#define   PER_LIB_TIMER_INIT_CTRL    (1) /*!< TIzMER模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_TIMER_NVIC_CTRL    (1) /*!< TIMER模块中断相关宏，写1开启，写0关闭。*/

/**
 * @brief		配置UART片内外设。
 * @details	    Configure GPIO chip internal  peripheral.
**/
#define   PER_LIB_UART_CTRL         (1) /*!< UART模块控制宏，写1开启，写0关闭。*/
											
#define   PER_LIB_UART_INIT_CTRL    (1) /*!< UART模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_UART_NVIC_CTRL    (1) /*!< UART模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_UART_WORK_CTRL    (1) /*!< UART模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置GPIO片内外设。
 * @details	    Configure GPIO chip internal  peripheral.
**/
#define   PER_LIB_GPIO_CTRL         (1) /*!< GPIO模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_GPIO_INIT_CTRL    (1) /*!< GPIO模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_GPIO_NVIC_CTRL    (1) /*!< GPIO模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_GPIO_WORK_CTRL    (1) /*!< GPIO模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置ADC片内外设。
 * @details	    Configure ADC chip internal  peripheral.
**/
#define   PER_LIB_ADC_CTRL         (1) /*!< ADC模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_ADC_INIT_CTRL    (1) /*!< ADC模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_ADC_NVIC_CTRL    (1) /*!< ADC模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_ADC_WORK_CTRL    (1) /*!< ADC模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置COMP片内外设。
 * @details	    Configure COMP chip internal  peripheral.
**/
#define   PER_LIB_COMP_CTRL         (1) /*!< COMP模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_COMP_INIT_CTRL    (1) /*!< COMP模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_COMP_NVIC_CTRL    (1) /*!< COMP模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_COMP_WORK_CTRL    (1) /*!< COMP模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置EEPROM片内外设，没有中断相关的控制宏。
 * @details	    Configure EEPROM chip internal  peripheral.
**/
#define   PER_LIB_EEPROM_CTRL         (1) /*!< EEPROM模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_EEPROM_INIT_CTRL    (1) /*!< EEPROM模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_EEPROM_WORK_CTRL    (1) /*!< EEPROM模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置I2C片内外设。
 * @details	    Configure I2C chip internal  peripheral.
**/
#define   PER_LIB_I2C_CTRL         (1) /*!< I2C模块控制宏，写1开启，写0关闭。*/
											
#define   PER_LIB_I2C_INIT_CTRL    (1) /*!< I2C模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_I2C_NVIC_CTRL    (1) /*!< I2C模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_I2C_WORK_CTRL    (1) /*!< I2C模块工作相关宏，写1开启，写0关闭。*/

/**
 * @brief		配置SPI片内外设。
 * @details	    Configure PCA chip internal  peripheral.
**/
#define   PER_LIB_SPI_CTRL         (1) /*!< SPI模块控制宏，写1开启，写0关闭。*/
				  
#define   PER_LIB_SPI_INIT_CTRL    (1) /*!< SPI模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_SPI_NVIC_CTRL    (1) /*!< SPI模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_SPI_WORK_CTRL    (1) /*!< SPI模块工作相关宏，写1开启，写0关闭。*/

/**
 * @brief		配置PCA片内外设。
 * @details	    Configure PCA chip internal  peripheral.
**/
#define   PER_LIB_PCA_CTRL         (1) /*!< GPIO模块控制宏，写1开启，写0关闭。*/
				 
#define   PER_LIB_PCA_INIT_CTRL    (1) /*!< GPIO模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_PCA_NVIC_CTRL    (1) /*!< GPIO模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_PCA_WORK_CTRL    (1) /*!< GPIO模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置电源管理片内外设，没有初始化相关的控制宏。
 * @details	    Configure on-chip peripherals for power management.
**/
#define   PER_LIB_POWER_CTRL        (1) /*!< 电源管理模块控制宏，写1开启，写0关闭。*/

#define   PER_LIB_POWER_NVIC_CTRL   (1) /*!< 电源管理模块中断相关宏，写1开启，写0关闭。*/
#define   PER_LIB_POWER_WORK_CTRL   (1) /*!< 电源管理模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置RST片内外设，没有中断相关的控制宏。
 * @details	    Configure RST chip internal  peripheral.
**/
#define   PER_LIB_RST_CTRL         (1) /*!< RST模块控制宏，写1开启，写0关闭。*/
									
#define   PER_LIB_RST_INIT_CTRL    (1) /*!< RST模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_RST_WORK_CTRL    (1) /*!< RST模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置WDT片内外设，没有中断相关的控制宏。
 * @details	    Configure RST chip internal  peripheral.
**/
#define   PER_LIB_WDT_CTRL         (1) /*!< WDT模块控制宏，写1开启，写0关闭。*/
								
#define   PER_LIB_WDT_INIT_CTRL    (1) /*!< WDT模块初始化相关宏，写1开启，写0关闭。*/
#define   PER_LIB_WDT_WORK_CTRL    (1) /*!< WDT模块工作相关宏，写1开启，写0关闭。*/


/**
 * @brief		配置MDU16片内外设。
 * @details	    Configure MDU16 chip internal  peripheral.
**/
#define   PER_LIB_MDU16_CTRL         (1) /*!< MDU16模块控制宏，写1开启，写0关闭。*/


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
  * @brief   精准延时组件。
  @details	 Precision delay components.
***/
#define  COM_LIB_PREDELAY_CTRL        (1)     // "1" is enable, "0" is disable 
#define  COM_LIB_PREDELAY_BASE        (11000UL)  /*!< 计算延时时间系数，根据实际情况需要微调。*/


/*--------------------------------------------------------
| @Description: STC8x Driver config                      |
--------------------------------------------------------*/

/**
  * @name    KeyScan
  * @brief   You need to config key scan.  
***/
#define  DRV_LIB_KEYSCAN_CTRL        (0)    // "1" is enable, "0" is disable 
#define  DRV_LIB_KEYSCAN_NUM_MAX     (8)    // key scan number max


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


