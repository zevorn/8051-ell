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

void Key_Handle(void)
{
	GPIO_TOGGLE_PIN(GPIO_P5,Pin_5);
	UART1_Send_Byte(64);
}


/**
  * @name    main
  * @brief   main program
  * @param   None
  * @return  None
***/
int main(void)
{
	KeyScan_Type KeyHandle = {0};
	
    STC8x_System_Init();
	TMT_Init();
	
	TMT.Create(KeyScan.ReadPin_P5,20);
	
	KeyHandle.GPIO = GPIO_P5;
	KeyHandle.Pin = Pin_4;
	KeyHandle.EffMode = Effect_Release;
	KeyHandle.TriMode = Tri_Low_level;
	KeyHandle.HandleFunc = Key_Handle;
	KeyScan_Init(&KeyHandle);
	
    for(;;)
    {
		KeyScan.Run();
		TMT.Run(); 
    }

}




/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



