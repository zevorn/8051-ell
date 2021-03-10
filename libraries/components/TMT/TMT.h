/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : TMT.h
  - Author        : zeweni
  - Update date   : 2020.02.06                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                         Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote the functions of time slice 
  *                                  task management.
  *  2020.01.11         zeweni       Update code comment format.
  * 
***/

#ifndef __TMT_H_
#define __TMT_H_
/*-----------------------------------------------------------------------
|                                INCLUED                                |
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
| @Description: STC8x MCU type                           |
--------------------------------------------------------*/

#include "STC8x_TYPE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: Task work state                          |
--------------------------------------------------------*/
typedef enum
{
	Task_Continue = 1,
	Task_Stop = !Task_Continue
} TaskState_Type;

/*-----------------------------------------------------------------------
|                                CONFIG                                 |
-----------------------------------------------------------------------*/
#if (COM_LIB_TMT_CTRL == 1)
/*--------------------------------------------------------
| @Description: Task definition max number               |
--------------------------------------------------------*/

/* The maximum number is 256 */
#define  TASKS_MAX       COM_LIB_TMT_TASK_NUM_MAX

/*--------------------------------------------------------
| @Description: Add timer interrupt control code         |
--------------------------------------------------------*/

#define   NVIC_TIMER_ISR_ENABLE()      COM_LIB_NVIC_TIMER_ISR_ENABLE
#define   NVIC_TIMER_ISR_DISABLE()     COM_LIB_NVIC_TIMER_ISR_DISABLE

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: Task control function                    |
--------------------------------------------------------*/

void TMT_Init(void);

typedef struct
{
  void (*      Run)   (void);
  void (*     Tick)   (void);
  void (*   Create)   (void (*taskFunc) (void), uint16_t triTime);
  void (*   Delete)   (void (*taskFunc) (void));
  void (* TimeCtrl)   (void (*taskFunc) (void), uint16_t triTime);
  void (*  RunCtrl)   (void (*taskFunc) (void), TaskState_Type state);
}TMT_Struct;

extern TMT_Struct TMT;

#endif
#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/

