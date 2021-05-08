/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : Predelay.h
  - Author        : zeweni
  - Update date   : 2020.05.07                
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
#include "PreDelay.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
static uint16_t G_MS_Count = 0;
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (COM_LIB_PREDELAY_CTRL == 1)

    /**
     * @brief      精准延时组件初始化。
     * @details    Precisely delay component initialization.  
     * @param      None.
     * @return     FSC_SUCCESS 返回成功。Return to success.
     * @return     FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE Pre_Delay_init(void)
    {
        extern uint32_t Get_SysClk_FRE(void);
        uint32_t sysClk_FRE;
        /* Get system clock frequency */
        sysClk_FRE = Get_SysClk_FRE();
        G_MS_Count = sysClk_FRE / DELAY_COUNT;
        return FSC_SUCCESS;
    }


    /**
     * @brief      上电延时，帮助系统稳定。
     * @details    Power-on delay helps to stabilize the system.
     * @param      None.
     * @return     None.
    **/
    void Pre_Delay_Pos(void) 
    {
        uint16_t i = 10000;
        for(; i>0; i--);
    }


    /**
     * @brief      延时一段时间，ms级别。
     * @details    Delay for a period of time, ms level.  
     * @param[in]  nms 延时时间.Delay time.
     * @return     None.
    **/
    void Pre_Delay_ms(uint16_t nms)
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




