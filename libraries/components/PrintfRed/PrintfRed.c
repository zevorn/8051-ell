/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : Printfred.c
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
			
		  UART1_Isr_Send_Byte((uint8_t)c);
			
		}
		#elif (COM_LIB_PRINTFRED_ROAD == 2)
		{
			
		  UART2_Isr_Send_Byte((uint8_t)c);	
			
		}
		#elif (COM_LIB_PRINTFRED_ROAD == 3)
		{
			
		  UART3_Isr_Send_Byte((uint8_t)c);
			
		}
		#elif (COM_LIB_PRINTFRED_ROAD == 4)
		{
			
		  UART4_Isr_Send_Byte((uint8_t)c);
			
		}
		#endif
		
		return c;
	}
	
#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
