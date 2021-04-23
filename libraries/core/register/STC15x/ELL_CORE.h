/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
  - File name      : STC8x_CORE.h
  - Author         : Quark Team
  - Update date    : 2020.12.20                   
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Header file of MCU core.
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

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_CORE_H_
#define __STC8x_CORE_H_

/*--------------------------------------------------------
| @Description: STC8Hx Data type                         |
--------------------------------------------------------*/

#include "ELL_TYPE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/**
  * @name    FUNSTATE
  * @brief   功能状态枚举体，常用于指示硬件的某个寄存器工作状态。
  *          Function state enumerator is often used to 
  *          indicate the working state of a register of hardware.
  * @param   DISABLE  [0] 未使能。 Not enabled.
  * @param   ENABLE   [1] 使能。 enabled.
***/
typedef enum 
{
	DISABLE = 0, ENABLE = !DISABLE
}   FUNSTATE;

/*--------------------------------------------------------
| @Description: Function self checking                   |
--------------------------------------------------------*/
/**
  * @name    FSCSTATE
  * @brief   函数自检枚举体，指示函数是否正常执行。
  *          Function self checks enumerator, 
  *          indicating whether the function is normally executed.
  * @param   FSC_SUCCESS  [0] 函数执行成功。 Function executed successfully.
  * @param   FSC_FAIL     [1] 函数执行失败。 Function executed failed.
***/
typedef enum
{
    FSC_FAIL= 1, /* Function self checking failed */
    FSC_SUCCESS = !FSC_FAIL /* Function self checking successfed */ 
}   FSCSTATE; 


/*--------------------------------------------------------
| @Description: Peripheral IO define                     |
--------------------------------------------------------*/

typedef enum
{
	SW_Port1 = 0x00 ,
	SW_Port2 = 0x01 ,
	SW_Port3 = 0x02 ,
	SW_Port4 = 0x03 
}   GPIOSWPort_Type;

/*--------------------------------------------------------
| @Description: Interrupt priority                       |
--------------------------------------------------------*/

typedef enum
{
  NVIC_PR0  =  0x00,  //Lowest  priority |
  NVIC_PR1  =  0x01,  //Lower   priority |
  NVIC_PR2  =  0x02,  //Higher  priority |
  NVIC_PR3  =  0x03   //Highest priority V
} NVICPri_Type;


#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/
