/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : PerList.h
  - Author        : zeweni
  - Update date   : 2020.02.06                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                      Note               
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Woite call list of peripheral driver.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/
#ifndef __PerList_H_
#define __PerList_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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
| @Description: STC8x MCU peripheral                     |
--------------------------------------------------------*/
#include "STC8x_SYSCLK.h"
#include "STC8x_NVIC.h"
#include "STC8x_GPIO.h"
#include "STC8x_WDT.h"
#include "STC8x_POWER.h"
#include "STC8x_TIMER.h"
#include "STC8x_UART.h"
#include "STC8x_COMP.h"
#include "STC8x_EEPROM.h"
#include "STC8x_ADC.h"
#include "STC8x_PCA.h"
#include "STC8x_RST.h"
#include "STC8x_PWM.h"
#include "STC8x_SPI.h"
#include "STC8x_I2C.h"
#include "STC8x_MDU16.h"

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

