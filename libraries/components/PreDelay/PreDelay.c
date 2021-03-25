/*----------------------------------------------------------------------
  - File name      : PreDelay.c
  - Author         : Quark Team
  - Update date    : 2020-12-29                
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Precision delay component.
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
#include "PreDelay.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
static uint16_t MS_Count = 0;
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (COM_LIB_PREDELAY_CTRL == 1)
/*--------------------------------------------------------
| @Description: MCU delay ms function                    |
| @param      : None                                     |
| @return     : Success(1) / Fail(0)                     |
--------------------------------------------------------*/

FSCSTATE Pre_Delay_init(void)
{
	extern uint32 Get_SysClk_FRE(void);
    uint32 sysClk_FRE;
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
	MS_Count = sysClk_FRE / DELAY_COUNT;
	return FSC_SUCCESS;
}

/*--------------------------------------------------------
| @Description: MCU power on stability delay function    |
| @param      : None                                     |
| @return     : Success(1) / Fail(0)                     |
--------------------------------------------------------*/

FSCSTATE Pre_Delay_Pos(void) 
{
	vuint16_t i = 1000;
	for(; i>0; i--) ;
	return FSC_SUCCESS;
}

/*--------------------------------------------------------
| @Description: MCU delay ms function                    |
| @param      : uint16 nms                               |
| @return     : None                                     |
--------------------------------------------------------*/

void Pre_Delay_ms(uint16 nms)
{
	uint16_t i;
	 for(; nms>0; nms--)
	 {			
		 i = MS_Count;
		 while(--i);
	 }
}

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/




