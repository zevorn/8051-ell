/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : PrintfRed.h
  - Author        : zeweni
  - Update date   : 2020.01.11                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                         Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote printf redirection to the 
  *                                  serial port function.
  * 
  * 
***/

#ifndef __PrintfRed_H_
#define __PrintfRed_H_

/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/

#include "Lib_CFG.h"
#include "stdio.h"
#include "STC8x_TYPE.h"
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

