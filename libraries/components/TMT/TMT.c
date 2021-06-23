/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : TMT.c
  - Author        : zeweni
  - Update date   : 2020.01.11                  
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
#include "TMT.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (COM_LIB_TMT_CTRL == 1)

/*--------------------------------------------------------
| @Description: Task object definition                   |
--------------------------------------------------------*/

TMT_Object TMT;

/*--------------------------------------------------------
| @Description: Task definition                          |
--------------------------------------------------------*/

typedef struct 
{
	void (* TaskFunction) (void); //Task function to run
    uint16_t TIMCount;         //Time counter
	uint16_t TRITime;          //Task running interval
	uint8_t Run;               //Program running flag
}TASK_COMPONENTS;       

static struct Task_Object
{
	TASK_COMPONENTS Comp[TASKS_MAX];
	uint8_t Number_Max;
}Task_Object;

/*--------------------------------------------------------
| @Description: Task execution status                    |
--------------------------------------------------------*/

static uint8_t tmt_state = 0; /* Initialize to 0 */

/*--------------------------------------------------------
| @Description: function                                 |
--------------------------------------------------------*/

static void TMT_Tick_t(void);
static void TMT_Run_t(void);
static FSCSTATE TMT_Delete_t(void (*taskFunc) (void));
static FSCSTATE TMT_Create_t(void (*taskFunc) (void),uint16_t triTime);
static FSCSTATE TMT_TimeCtrl_t(void (*taskFunc) (void),uint16_t triTime);
static FSCSTATE TMT_RunCtrl_t(void (*taskFunc) (void),TaskState_Type state);

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    TMT_Init
  * @brief   Init TMT tool function
  * @param   None
  * @return  None
***/
void TMT_Init(void)
{
	TMT.Run = TMT_Run_t;
	TMT.Tick = TMT_Tick_t;
	TMT.Create = TMT_Create_t;
	TMT.Delete = TMT_Delete_t;
	TMT.TimeCtrl = TMT_TimeCtrl_t;
	TMT.RunCtrl = TMT_RunCtrl_t;
	Task_Object.Number_Max = 0;
}

/**
  * @name    TMT_Tick_t
  * @brief   Get ticks of task function
  * @param   None
  * @return  None
***/
void TMT_Tick_t(void)
{
	uint8_t i;
	for(i=0; i<Task_Object.Number_Max; i++)
    {
		 /* If time arrives */
        if(Task_Object.Comp[i].TIMCount > 0 )
        {
            Task_Object.Comp[i].TIMCount--;
        }
		
	}	
}

/**
  * @name    TMT_Run_t
  * @brief   Task run function
  * @param   None
  * @return  None
***/
void TMT_Run_t(void)
{
	uint8_t i;
	for(i=0; i<Task_Object.Number_Max; i++){
		 /* If time arrives */
		if(Task_Object.Comp[i].TIMCount == 0 && Task_Object.Comp[i].Run == 1)
		{
			Task_Object.Comp[i].TIMCount = Task_Object.Comp[i].TRITime;
			/* 
				To prevent process conflict, 
				only one process can be executed in the same time period.
			*/
		    Task_Object.Comp[i].TaskFunction();  /* Run task */
		}
	}
}

/**
  * @name    TMT_Create_t
  * @brief   Create task function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @param   triTime  task run time (ticks)
  * @return  None
***/
FSCSTATE TMT_Create_t(void (* taskFunc) (void),uint16_t triTime)
{	
    static uint8_t task_num = 0; /* Initialize to 0 */
	if(task_num>=0 && task_num < TASKS_MAX)
	{
		Task_Object.Comp[task_num].TaskFunction = taskFunc;
		Task_Object.Comp[task_num].TRITime = triTime;
		Task_Object.Comp[task_num].TIMCount = triTime;
		Task_Object.Comp[task_num].Run = 1;
		task_num += 1;
		Task_Object.Number_Max = task_num;
		return FSC_SUCCESS;
	}
	else
	{
		return FSC_FAIL;	
	}		
}

/**
  * @name    TMT_Delete_t
  * @brief   Delete task function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @return  None
***/
FSCSTATE TMT_Delete_t(void (* taskFunc) (void))
{	
	uint8_t i;
	if(Task_Object.Number_Max > 0 && Task_Object.Number_Max < Task_Object.Number_Max)
	{
		NVIC_TIMER_ISR_DISABLE();
		for(i=0; i<Task_Object.Number_Max; i++)
		{
			if(Task_Object.Comp[i].TaskFunction == taskFunc)
			{
					Task_Object.Comp[i].TaskFunction = Task_Object.Comp[Task_Object.Number_Max-1].TaskFunction;
					Task_Object.Comp[i].TRITime = Task_Object.Comp[Task_Object.Number_Max-1].TRITime;
					Task_Object.Comp[i].TIMCount = Task_Object.Comp[Task_Object.Number_Max-1].TIMCount;
					Task_Object.Comp[i].Run = Task_Object.Comp[Task_Object.Number_Max-1].Run;
					Task_Object.Number_Max -= 1;
					return FSC_SUCCESS;
			}
		}
		NVIC_TIMER_ISR_ENABLE();
		return FSC_SUCCESS;
	}
	else 
	{
        return FSC_FAIL;		
	}
}


/**
  * @name    TMT_RunCtrl_t
  * @brief   Control task run function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @param   state   Task_Continue | Task_Stop
  * @return  None
***/
FSCSTATE TMT_RunCtrl_t(void (* taskFunc) (void),TaskState_Type state)
{
	uint8_t i;
	for(i=0; i<Task_Object.Number_Max; i++)
	{
		if(Task_Object.Comp[i].TaskFunction == taskFunc)
		{
		    Task_Object.Comp[i].Run = state;
			return FSC_SUCCESS;
		}
	}
	return FSC_FAIL;
}

/**
  * @name    TMT_TimeCtrl_t
  * @brief   Control task time function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @param   triTime  task run time (ticks)
  * @return  None
***/
FSCSTATE TMT_TimeCtrl_t(void (* taskFunc) (void),uint16_t triTime)
{	
	uint8_t i;
	for(i=0; i<Task_Object.Number_Max; i++)
	{
		if(Task_Object.Comp[i].TaskFunction == taskFunc)
		{
			Task_Object.Comp[i].TIMCount = triTime;
			Task_Object.Comp[i].TRITime = triTime;
			return FSC_SUCCESS;
		}
	}
	return FSC_FAIL;
}

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


