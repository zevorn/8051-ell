/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : PrintfRed.h
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
#ifndef __PrintfRed_H_
#define __PrintfRed_H_

#include "Lib_CFG.h"
#include "stdio.h"
#include "ELL_TYPE.h"
#include "STC8x_UART.h"

#ifndef DEBUG_CTRL

    #define    DEBUG_CTRL    (0)
	
#endif

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

#if (DEBUG_CTRL == 1)

    #define DEBUG_LOG_LINE()    printf("Code line number: [%bd] \r\n", __LINE__)
    #define DEBUG_LOG_FILE()    printf("File path: %s \r\n", __FILE__)
	#define DEBUG_LOG(format)   do{ printf("Line is <%bd> and Path is [%s]:\r\n", __LINE__, __FILE__); printf(format); }while(0)
		
#else
	
	#define DEBUG_LOG_LINE()
    #define DEBUG_LOG_FILE()	
	#define DEBUG_LOG(format)
	
#endif
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

