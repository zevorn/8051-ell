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

 * You should have received a copy of the Apache-2.0 License.Ant Real Time
 * Operating System. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_CORE_H_
#define __STC8x_CORE_H_
/*--------------------------------------------------------
| @Description: STC8Hx Data type                         |
--------------------------------------------------------*/

#include "STC8x_TYPE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Functional State                         |
--------------------------------------------------------*/

typedef enum 
{
	DISABLE = 0, ENABLE = !DISABLE
}   FUNSTATE;

/*--------------------------------------------------------
| @Description: Function self checking                   |
--------------------------------------------------------*/

typedef enum
{
    FSC_FAIL= 0, /* Function self checking failed */
    FSC_SUCCESS = !FSC_FAIL /* Function self checking successfed */ 
}   FSCSTATE; 

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/
