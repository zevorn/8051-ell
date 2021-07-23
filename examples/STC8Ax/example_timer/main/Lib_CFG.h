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
/**
  * Update note:
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Woite call list of peripheral driver.
  *  2020.01.19         zeweni       Update code comment format.
  *  2020.02.06         zeweni       Update code style.
  *
***/

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

#define    PER_LIB_MCU_MUODEL     STC8Ax

/*--------------------------------------------------------
| @Description: STC8x Driver config                      |
--------------------------------------------------------*/

/* None */

/*--------------------------------------------------------
| @Description: STC8x Componets config                   |
--------------------------------------------------------*/

/**
  * @name    PrintfRed
  * @brief   You need to initialize the uart bay yourself.  
***/
#define  COM_LIB_PRINTFRED_CTRL        (1)    // "1" is enable, "0" is disable 
#define  COM_LIB_PRINTFRED_ROAD        (1)    // Select printf uart(1\2\3\4)

/**
  * @name    TMT
  * @brief   Task time tool
***/
#define  COM_LIB_TMT_CTRL              (1)    // "1" is enable, "0" is disable 
#define  COM_LIB_TMT_TASK_NUM_MAX      (8)    // task number max
#define  COM_LIB_NVIC_TIMER_ISR_ENABLE    ET0 = 1
#define  COM_LIB_NVIC_TIMER_ISR_DISABLE   ET0 = 0

/**
  * @name    PreDelay
  * @brief   Precision delay
***/
#define  COM_LIB_PREDELAY_CTRL        (1)     // "1" is enable, "0" is disable 
#define  COM_LIB_PREDELAY_BASE        (11000U) // task number max


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


