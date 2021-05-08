/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_POWER.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
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
#include "STC8x_POWER.h"


/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @brief		电源工作模式控制函数。
 * @details	    Power mode configure function. 
 * @param[in]	mode 电源工作模式。Power working mode. 
 * @return      FSC_SUCCESS 返回成功。Return to success.
 * @return      FSC_FAIL    返回失败。Return to fail.
**/
FSCSTATE POWER_Mode_Ctrl(POWERMode_Type mode)
{
  PCON = (PCON & 0xFC) | mode;
  return FSC_SUCCESS;
}


/**
* @brief	   低压检测中断初始化函数。
 * @details	   Low-voltage detection interrupt initialization function.
 * @param[in]  pri 中断优先级。Interrupt priority.
 * @param[in]  run 中断运行控制位。Interrupt operation control bit.
 * @return     FSC_SUCCESS 返回成功。Return to success.
 * @return     FSC_FAIL    返回失败。Return to fail.
**/
FSCSTATE NVIC_LVD_Init(NVICPri_Type priority,BOOL run)
{
	ELVD = run;
	NVIC_LVD_PRI(priority);
	return FSC_SUCCESS;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



