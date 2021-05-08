/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_COMP.c
  - Author        : zeweni
  - Update date   : 2020.04.23                 
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
#include "STC8x_COMP.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/**
 * @brief     COMP选择触发模式宏函数，仅限本文件调用。
 * @details   Comp select trigger state macro function, 
 *            only this file call.
 * @param[in] triMode 触发模式。 Mode of trigeer.
**/
#define COMP_TRISTATE_SELECT(triMode)    \
do{                                      \
	CMPCR1 = (CMPCR1 & 0xCF)|(triMode);  \
}while(0)

/**
 * @brief     COMP选择正极输入脚宏函数，仅限本文件调用。
 * @details   Comp select positive input pin macro function, 
 *            only this file call.
 * @param[in] pePin 正极输入引脚。Positive input pin.
**/
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
	
	#define  COMP_PEINPUT_SELECT(pePin)                   \
	do{                                                   \
			if(pePin == COMP_PE_P37) {CMPCR1 &= 0xF7;}    \
			else {CMPCR1 |= 0x08;                         \
			ADC_CONTR = (ADC_CONTR & 0xF0)|(pePin)|0x80;} \
	}while(0)
	
#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Fx)
		
	#define  COMP_PEINPUT_SELECT(pePin)  do{CMPCR1 &= pePin;}while(0)
		
#endif	

/**
 * @brief     COMP选择负极输入脚宏函数，仅限本文件调用。
 * @details   Comp select negative input pin macro function, 
 *            only this file call.
 * @param[in] nePin 负极输入引脚。Negative input pin.
**/
#define  COMP_NEINPUT_SELECT(nePin)                   \
do{                                                   \
	CMPCR1 = (CMPCR1 & 0xFB) | ((nePin & 0xF0) >> 2); \
}while(0)

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None. */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_COMP_CTRL == 1)

    #if (PER_LIB_COMP_INIT_CTRL == 1)

        /**
         * @brief     COMP初始化函数。
         * @details   COMP initialization function.
         * @param[in] compx  COMP结构体句柄，初始化时请定义该句柄，并用其地址来传参。
         *                   COMP structure handle. When initializing, 
         *                   please define the handle and use its address 
         *                   to pass parameters.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        ***/
        FSCSTATE COMP_Init(const COMP_InitType* compx)
        {
            if(compx -> DC_FTW > 0x3F) return FSC_FAIL;
            COMP_PEINPUT_SELECT(compx -> PEPin);
            COMP_NEINPUT_SELECT(compx -> NEPin);
            CMPCR2 = (CMPCR2 & 0xBF) | (compx -> AC_FTW << 6);
            CMPCR2 = (CMPCR2 & 0xC0) | (compx -> DC_FTW);
            CMPCR2 = (CMPCR2 & 0x7F) | (compx -> DIRPut << 7);
            CMPCR1 = (CMPCR1 & 0xFD) | (compx -> Output << 1);
            CMPCR1 = (CMPCR1 & 0x7F) | (compx -> Run << 7);
            return FSC_SUCCESS;
        }

    #endif


    #if (PER_LIB_COMP_NVIC_CTRL == 1)

        /**
         * @brief       COMP中断初始化函数。
         * @details     COMP interrupt initialization function.
         * @param[in]   pri 中断优先级。Interrupt priority.
         * @param[in]   triMode  触发模式。Trigger mode.
         * @return      FSC_SUCCESS 返回成功。Return to success.
         * @return      FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_COMP_Init(NVICPri_Type pri,COMPTri_Type triMode)
        {
            COMP_TRISTATE_SELECT(triMode);
            COMP_NVIC_PRI(pri);
            return FSC_SUCCESS;
        }

    #endif

    #if (PER_LIB_COMP_WORK_CTRL == 1)

        /**
         * @brief   COMP切换复用IO函数。
         * @details COMP switch out port control function.  
         * @param   port [IN] 复用IO枚举体。IO switch enumerator.
         * @return  FSC_SUCCESS 返回成功。Return to success.
         * @return  FSC_FAIL    返回失败。Return to fail.
        ***/
        FSCSTATE GPIO_COMP_SWPort(GPIOSWPort_Type port)
        {
            if(port < SW_Port3)
            {
                P_SW2 = (P_SW2 & 0xF7) | (port << 3);
                return FSC_SUCCESS;
            }
            else return FSC_FAIL;
        }

    #endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



