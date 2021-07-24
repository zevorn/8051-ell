/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_DELAY.c
  - Author        : zeweni
  - Update date   : 2020.07.23                
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
#include "STC8x_DELAY.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
static uint16_t G_MS_Count = 0;
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_PREDELAY_CTRL == 1)

    /**
     * @brief      精准延时组件初始化。
     * @details    Precisely delay component initialization.  
     * @param      None.
     * @return     FSC_SUCCESS 返回成功。Return to success.
     * @return     FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE DELAY_Init(void)
    {
        extern uint32_t Get_SysClk_FRE(void);
        uint32_t sysClk_FRE;
        /* Get system clock frequency */
        sysClk_FRE = Get_SysClk_FRE();
        G_MS_Count = sysClk_FRE / DELAY_COUNT;
        return FSC_SUCCESS;
    }


    /**
     * @brief      延时一段时间，ms级别。
     * @details    Delay for a period of time, ms level.  
     * @param[in]  nms 延时时间.Delay time.
     * @return     None.
    **/
    void DELAY_Set_Ms(uint16_t nms)
    {
        uint16_t i;
        for(; nms>0; nms--)
        {			
            i = G_MS_Count;
            while(--i);
        }
    }

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/




