/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_WDT.c
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
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.Ant Real Time
 * Operating System. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_WDT.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* none*/
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    WDT_Init
  * @brief   WDT initialization function 
  * @param   CLKDiv   clock division  (uint8_t)
  * @param   Run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE WDT_Init(uint8_t clKDiv, FUNSTATE run)
{
	WDT_CONTR = clKDiv;
	if(run == ENABLE) WDT_CONTR |= 0x20;
	else WDT_CONTR &= 0xDF;
	return FSC_SUCCESS;
}

/**
  * @name    Get_WDT_Time
  * @brief   Get WDT  feeding time function
  * @param   None
  * @return  feeding time data (uint32_t) 
***/
uint32_t Get_WDT_Time(void)
{
	extern uint32_t Get_SysClk_FRE(void);
	uint8_t i;
    uint32_t sysClk_FRE,dat = 2;
	sysClk_FRE = Get_SysClk_FRE();
	for(i=0; i<(WDT_CONTR & 0x03); i++) dat *= 2;
	dat = (12 * 32768 * dat) / sysClk_FRE;
	return dat;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
