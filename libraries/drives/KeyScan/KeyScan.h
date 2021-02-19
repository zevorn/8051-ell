/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : drv_KeyScan.h
  - Author        : zeweni
  - Update date   : 2020.01.11                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                      Note               
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote key scan device driver.
  * 
  *  2020.01.11         zeweni       Update code comment format.
  * 
***/
#ifndef __drv_KeyScan_H_
#define __drv_KeyScan_H_
/*-----------------------------------------------------------------------
|                                INCLUDES                               |
-----------------------------------------------------------------------*/

#include "STC8x_TYPE.h"
#include "STC8x_CORE.h"

/*-----------------------------------------------------------------------
|                                 CONFIG                                |
-----------------------------------------------------------------------*/

#define KEY_NUM_MAX  ( 5 )

/*-----------------------------------------------------------------------
|                                  DATA                                 |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Key state enum                           |
--------------------------------------------------------*/

typedef enum 
{
  Click_None   = 0x00,
  Click_Short  = 0x01,
  Click_Long   = 0x02,
  Click_Double = 0x03
} Sem_Click;

typedef void (* KeyScan_FunCallBack)  (Sem_Click *clickMode);
typedef void (* KeyScan_ReadPin_Func)  (uint8 *rValue);

/*--------------------------------------------------------
| @Description: Key state enum                           |
--------------------------------------------------------*/

typedef enum 
{
  Tri_Low_level  = 0x01,
  Tri_High_level = 0x02
} Sem_Tri;
/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

typedef struct
{
  void (*    Scan)  (void);
  void (*     Run)  (void);
  void (*  Config)  (Sem_Click clickMode,Sem_Tri triMode);
  void (* ReadPin)  (KeyScan_ReadPin_Func ReadPin);
  void (*  Attach)  (KeyScan_FunCallBack keyScan_CallBack);
}KeyScan_object;

extern KeyScan_object Key;

void KeyScan_Init(void);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

