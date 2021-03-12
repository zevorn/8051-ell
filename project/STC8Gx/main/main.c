/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : main.c
  - Author        : zeweni
  - Update date   : 2020.01.11
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "main.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
/**
  * @name    Task1_Led
  * @brief   main program
  * @param   None
  * @return  None
***/
void Task1_Led(void)
{
	GPIO_TOGGLE_PIN(GPIO_P5,Pin_5);
}

void Key_Handle(Sem_Click *clickMode)
{
	if(*clickMode == Click_Short)
	DEBUG_LOG(" Key success \r\n");
}
/**
  * @name    Read_Pin
  * @brief   Get pin valuie
  * @param   None
  * @return  None
***/
uint8_t Read_Pin(void) 
{
	return P54;
}

/**
  * @name    main
  * @brief   main program
  * @param   None
  * @return  None
***/
int main(void)
{
    STC8x_System_Init();
	
	TMT_Init();
	KeyScan_Init();
	
	KeyScan.Add(Read_Pin,Click_Short,Tri_Low_level);
	
	KeyScan.Attach(Key_Handle);
	
	if(TMT.Create(KeyScan.Run,20) == Create_Success)
	{
		DEBUG_LOG("success \r\n");
	}
	else
	{
		DEBUG_LOG("fail  \r\n");		
	}	
	
	if(TMT.Create(KeyScan.Scan,20) == Create_Success)
	{
		DEBUG_LOG("success \r\n");
	}
	else
	{
		DEBUG_LOG("fail  \r\n");		
	}	
	
	if(TMT.Create(Task1_Led,500) == Create_Success)
	{
		DEBUG_LOG("success \r\n");
	}
	else
	{
		DEBUG_LOG("fail  \r\n");		
	}
	
    for(;;)
    {
		TMT.Run();
    }

}




/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



