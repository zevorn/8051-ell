/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : Printfred.c
  - Author        : zeweni
  - Update date   : 2020.01.11                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "Printfred.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#ifndef COM_LIB_PRINTFRED_CTRL
    #define COM_LIB_PRINTFRED_CTRL (0)
#endif

#ifndef COM_LIB_PRINTFRED_ROAD
    #define COM_LIB_PRINTFRED_ROAD (0)
#endif

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    putchar
  * @brief   Redefining printf function     
  * @param   c  put data
  * @return  char
***/
#if (COM_LIB_PRINTFRED_CTRL == 1)      
char putchar(char c)
{
	#if   (COM_LIB_PRINTFRED_ROAD == 1)
	{
	  UART1_Send_Byte((uint8_t)c);
	}
	#elif (COM_LIB_PRINTFRED_ROAD == 2)
	{
	  UART2_Send_Byte((uint8_t)c);	
	}
	#elif (COM_LIB_PRINTFRED_ROAD == 3)
	{
	  UART3_Send_Byte((uint8_t)c);
	}
	#elif (COM_LIB_PRINTFRED_ROAD == 4)
	{
	  UART4_Send_Byte((uint8_t)c);
	}
	#endif
	return c;
}
#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
