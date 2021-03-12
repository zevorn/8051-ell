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

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (COM_LIB_TMT_CTRL == 1)
/*--------------------------------------------------------
| @Description: Task work state                          |
--------------------------------------------------------*/
typedef enum
{
	Task_Continue = 1,
	Task_Stop = !Task_Continue
}   TaskState_Type;

typedef enum
{
    Create_Fail = 0x00,
    Create_Success = !Create_Fail
}   CreateFun_Type;

typedef enum
{
    Delete_Fail = 0x00,
    Delete_Success = !Delete_Fail
}   DeleteFun_Type;

typedef enum
{
    Ctrl_Fail = 0x00,
    Ctrl_Success = !Delete_Fail
}   CtrlFun_Type;

/*-----------------------------------------------------------------------
|                                CONFIG                                 |
-----------------------------------------------------------------------*/
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

/**
  * @name    TMT_Init
  * @brief   Init TMT tool function
  * @param   None
  * @return  None
***/
void TMT_Init(void);

/**
  * @name    TMT_Struct
  * @brief   TMT.Run(void)                                              Task run function
             TMT.Tick(void)                                             Get ticks of task function
             TMT.Create(void (*taskFunc) (void), uint16_t triTime)      Create task function
             TMT.Delete(void (*taskFunc) (void))                        Delete task function
             TMT.TimeCtrl(void (*taskFunc) (void), uint16_t triTime)    Control task time function
             TMT.RunCtrl(void (*taskFunc) (void))                       Control task run function				 
***/
typedef struct
{
  void            (*      Run)   (void);
  void            (*     Tick)   (void);
  CreateFun_Type  (*   Create)   (void (*taskFunc) (void), uint16_t triTime);
  DeleteFun_Type  (*   Delete)   (void (*taskFunc) (void));
  CtrlFun_Type    (* TimeCtrl)   (void (*taskFunc) (void), uint16_t triTime);
  CtrlFun_Type    (*  RunCtrl)   (void (*taskFunc) (void), TaskState_Type state);
}TMT_Struct;

extern TMT_Struct TMT;

#endif

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/

