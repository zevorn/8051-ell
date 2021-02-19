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
| @Description: Task number of now                       |
--------------------------------------------------------*/

static uint8_t task_num = 0; /* Initialize to 0 */

/*--------------------------------------------------------
| @Description: function                                 |
--------------------------------------------------------*/

static void TMT_Pro_Time_Callback(void);
static void TMT_Pro_Handler_Callback(void);
static void TMT_Pro_Delete(void (*TaskFunction) (void));
static void TMT_Pro_Create(void (*TaskFunction) (void),uint16_t TRITime);
static void TMT_Pro_Time_Ctrl(void (*TaskFunction) (void),uint16_t TRITime);
static void TMT_Pro_Run_Ctrl(void (*TaskFunction) (void),TaskState_Type State);

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Task time tool init function             |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void TMT_Init(void)
{
	TMT.Run = TMT_Pro_Handler_Callback;
	TMT.Tick = TMT_Pro_Time_Callback;
	TMT.Create = TMT_Pro_Create;
	TMT.Delete = TMT_Pro_Delete;
	TMT.TimeCtrl = TMT_Pro_Time_Ctrl;
	TMT.RunCtrl = TMT_Pro_Run_Ctrl;
}

/*--------------------------------------------------------
| @Description: Task time handler function               |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void TMT_Pro_Time_Callback(void)
{
	uint8_t i;
	for(i=0; i<Tasks_Max; i++){
		 /* If time arrives */
		Task_Comps[i].TIMCount--;
	}	
}

/*--------------------------------------------------------
| @Description: Task remarks handler function            |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void TMT_Pro_Handler_Callback(void)
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

/*--------------------------------------------------------
| @Description: Task process create function             |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void TMT_Pro_Create(void (*TaskFunction) (void),uint16_t TRITime)
{	
	Task_Comps[task_num].TaskFunction = TaskFunction;
	Task_Comps[task_num].TRITime = TRITime;
	Task_Comps[task_num].TIMCount = TRITime;
	Task_Comps[task_num].Run = 1;
    task_num = (task_num + 1) % (TASKS_MAX+1);
	Tasks_Max = task_num;
}

/*--------------------------------------------------------
| @Description: Task process time config function        |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void TMT_Pro_Time_Ctrl(void (*TaskFunction) (void),uint16_t TRITime)
{	
	uint8_t i;
	for(i=0; i<Tasks_Max; i++)
	{
		if(Task_Comps[i].TaskFunction == TaskFunction)
		{
			Task_Comps[i].TIMCount = TRITime;
			Task_Comps[i].TRITime = TRITime;
			return;
		}
	}
}

/*--------------------------------------------------------
| @Description: Task process delete function             |
| @param      : void (*TaskFunction) (void)              |
| @return     : None                                     |
--------------------------------------------------------*/

void TMT_Pro_Delete(void (*TaskFunction) (void))
{	
	uint8_t i;
    NVIC_TIMER_ISR_DISABLE();
	if(Tasks_Max == 0) return;
	for(i=0; i<Tasks_Max; i++)
	{
		if(Task_Comps[i].TaskFunction == TaskFunction)
		{
				Task_Comps[i].TaskFunction = Task_Comps[Tasks_Max-1].TaskFunction;
				Task_Comps[i].TRITime = Task_Comps[Tasks_Max-1].TRITime;
				Task_Comps[i].TIMCount = Task_Comps[Tasks_Max-1].TIMCount;
				Task_Comps[i].Run =Task_Comps[Tasks_Max-1].Run;
				Tasks_Max -= 1;			
			    return;
		}
	}
    NVIC_TIMER_ISR_ENABLE();
}


/*--------------------------------------------------------
| @Description: Task process run function                |
| @param      : void (*TaskFunction) (void)              |
| @return     : None                                     |
--------------------------------------------------------*/
void TMT_Pro_Run_Ctrl(void (*TaskFunction) (void),TaskState_Type State)
{
	uint8_t i;
	for(i=0; i<Tasks_Max; i++)
	{
		if(Task_Comps[i].TaskFunction == TaskFunction)
		{
		    Task_Comps[i].Run = State;
			return;
		}
	}
}
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


