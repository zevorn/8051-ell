/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : TMT.h
  - Author        : zeweni
  - Update date   : 2020.02.06                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
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
#ifndef __TMT_H_
#define __TMT_H_

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"

#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#ifndef COM_LIB_TMT_CTRL                      
    #define COM_LIB_TMT_CTRL           (1)
#endif

#ifndef COM_LIB_TMT_TASK_NUM_MAX                   
    #define COM_LIB_TMT_TASK_NUM_MAX   (8)
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

#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (COM_LIB_TMT_CTRL == 1)

/*--------------------------------------------------------
| @Description: Task work state                          |
--------------------------------------------------------*/
typedef enum
{
    Task_Stop = 0x00,
	Task_Continue = !Task_Stop
}   TaskState_Type;

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
  void      (*     Run)   (void);
  void      (*    Tick)   (void);
  FSCSTATE  (*   Create)   (void (*taskFunc) (void), uint16_t triTime);
  FSCSTATE  (*   Delete)   (void (*taskFunc) (void));
  FSCSTATE  (* TimeCtrl)   (void (*taskFunc) (void), uint16_t triTime);
  FSCSTATE  (*  RunCtrl)   (void (*taskFunc) (void), TaskState_Type state);
}TMT_Object;

extern TMT_Object TMT;

#endif

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/

