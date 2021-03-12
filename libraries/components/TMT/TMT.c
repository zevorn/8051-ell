/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : TMT.c
  - Author        : zeweni
  - Update date   : 2020.01.11                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "TMT.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (COM_LIB_TMT_CTRL == 1)
/*--------------------------------------------------------
| @Description: Task definition                          |
--------------------------------------------------------*/

typedef struct 
{
	uint8_t Run;               //Program running flag
    uint16_t TIMCount;         //Time counter
	uint16_t TRITime;          //Task running interval
	void (*TaskFunction) (void); //Task function to run
} TASK_COMPONENTS;       

TMT_Struct TMT;

/*--------------------------------------------------------
| @Description: Task definition                          |
--------------------------------------------------------*/

static TASK_COMPONENTS Task_Comps[TASKS_MAX];

/*--------------------------------------------------------
| @Description: Maximum number of task lists             |
--------------------------------------------------------*/

static uint8_t Tasks_Max;

/*--------------------------------------------------------
| @Description: Task execution status                    |
--------------------------------------------------------*/

static uint8_t tmt_state = 0; /* Initialize to 0 */

/*--------------------------------------------------------
| @Description: function                                 |
--------------------------------------------------------*/

static void TMT_Tick_t(void);
static void TMT_Run_t(void);
static DeleteFun_Type TMT_Delete_t(void (*taskFunc) (void));
static CreateFun_Type TMT_Create_t(void (*taskFunc) (void),uint16_t triTime);
static CtrlFun_Type TMT_TimeCtrl_t(void (*taskFunc) (void),uint16_t triTime);
static CtrlFun_Type TMT_RunCtrl_t(void (*taskFunc) (void),TaskState_Type state);

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
	for(i=0; i<Tasks_Max; i++){
		 /* If time arrives */
		Task_Comps[i].TIMCount--;
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
	for(i=0; i<Tasks_Max; i++){
		 /* If time arrives */
		if(Task_Comps[i].TIMCount == 0 && Task_Comps[i].Run == 1)
		{
			Task_Comps[i].TIMCount = Task_Comps[i].TRITime;
			/* 
				To prevent process conflict, 
				only one process can be executed in the same time period.
			*/
		    Task_Comps[i].TaskFunction();  /* Run task */
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
CreateFun_Type TMT_Create_t(void (*taskFunc) (void),uint16_t triTime)
{	
    static uint8_t task_num = 0; /* Initialize to 0 */
	if(task_num>=0 && task_num < TASKS_MAX)
	{
		Task_Comps[task_num].TaskFunction = taskFunc;
		Task_Comps[task_num].TRITime = triTime;
		Task_Comps[task_num].TIMCount = triTime;
		Task_Comps[task_num].Run = 1;
		task_num += 1;
		Tasks_Max = task_num;
		return Create_Success;
	}
	else
	{
		return Create_Fail;	
	}		
}

/**
  * @name    TMT_Delete_t
  * @brief   Delete task function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @return  None
***/
DeleteFun_Type TMT_Delete_t(void (*taskFunc) (void))
{	
	uint8_t i;
	if(Tasks_Max > 0 && Tasks_Max < TASKS_MAX)
	{
		NVIC_TIMER_ISR_DISABLE();
		for(i=0; i<Tasks_Max; i++)
		{
			if(Task_Comps[i].TaskFunction == taskFunc)
			{
					Task_Comps[i].TaskFunction = Task_Comps[Tasks_Max-1].TaskFunction;
					Task_Comps[i].TRITime = Task_Comps[Tasks_Max-1].TRITime;
					Task_Comps[i].TIMCount = Task_Comps[Tasks_Max-1].TIMCount;
					Task_Comps[i].Run =Task_Comps[Tasks_Max-1].Run;
					Tasks_Max -= 1;
					return Delete_Success;
			}
		}
		NVIC_TIMER_ISR_ENABLE();
		return Delete_Success;
	}
	else 
	{
        return Delete_Fail;		
	}
}


/**
  * @name    TMT_RunCtrl_t
  * @brief   Control task run function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @param   state   Task_Continue | Task_Stop
  * @return  None
***/
CtrlFun_Type TMT_RunCtrl_t(void (*taskFunc) (void),TaskState_Type state)
{
	uint8_t i;
	for(i=0; i<Tasks_Max; i++)
	{
		if(Task_Comps[i].TaskFunction == taskFunc)
		{
		    Task_Comps[i].Run = state;
			return Ctrl_Success;
		}
	}
	return Ctrl_Fail;
}

/**
  * @name    TMT_TimeCtrl_t
  * @brief   Control task time function
  * @param   *taskFunc (void)   A pointer function without formal parameters.
  * @param   triTime  task run time (ticks)
  * @return  None
***/
CtrlFun_Type TMT_TimeCtrl_t(void (*taskFunc) (void),uint16_t triTime)
{	
	uint8_t i;
	for(i=0; i<Tasks_Max; i++)
	{
		if(Task_Comps[i].TaskFunction == taskFunc)
		{
			Task_Comps[i].TIMCount = triTime;
			Task_Comps[i].TRITime = triTime;
			return Ctrl_Success;
		}
	}
	return Ctrl_Fail;
}

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


