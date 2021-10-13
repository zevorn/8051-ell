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
 * Apache-2.0 License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
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
#if (PER_LIB_RST_CTRL == 1)

	#if (PER_LIB_RST_INIT_CTRL == 1)
	
		/**
		 * @brief       看门狗初始函数。
		 * @details     WDT initialization function. 
		 * @param[in]   cLKDiv   系统时钟分频数。clock division.
		 * @param[in]   run      运行控制位。Run control bit.
		 * @return      FSC_SUCCESS 返回成功。Return to success.
		 * @return      FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE WDT_Init(uint8_t clKDiv, BOOL run)
		{
			WDT_CONTR = clKDiv;
			if(run == ENABLE) WDT_CONTR |= 0x20;
			else WDT_CONTR &= 0xDF;
			return FSC_SUCCESS;
		}

	#endif
		
	#if (PER_LIB_RST_WORK_CTRL == 1)
		
		/**
		 * @brief   获取喂狗时间函数，以便定时喂狗。
		 * @details Get WDT  feeding time function.
		 * @param   None.
		 * @return  [uint32_t] 获取喂狗时间，单位us。Get the feeding time, the unit is us.
		**/
		uint32_t Get_WDT_Time(void)
		{
			extern uint32_t Get_SysClk_FRE(void);
			uint8_t i;
			uint32_t sysClk_FRE,dat = 2;
			sysClk_FRE = Get_SysClk_FRE();
			for(i=0; i<(WDT_CONTR & 0x07); i++) dat *= 2;
			dat = ((12UL * 32768UL * dat) / sysClk_FRE) / 1000UL;
			return dat;
		}
		
	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
