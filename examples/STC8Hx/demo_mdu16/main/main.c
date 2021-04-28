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
extern bit Time500MsFlag;
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    main
  * @brief   main program
  * @param   None
  * @return  None
***/
int main(void)
{
	uint16_t i = 1000;
	uint16_t j = 200;	
	uint32_t k = 2;	
	
	STC8x_System_Init();
	
	for(;;)
	{
      if(Time500MsFlag == 1)
      {
          Time500MsFlag = 0;
		  MUL_16_BIT(i,j,k);
		  printf("%ld\r\n",k);
        
      }
	}

}



/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/


