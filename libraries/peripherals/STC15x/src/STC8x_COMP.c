/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_COMP.c
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

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_COMP.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: COMP PEPin select define function        |
--------------------------------------------------------*/

#define  COMP_PEINPUT_CFG(PEPin)  { \
    if(PEPin == COMP_PE_P37) {CMPCR1 &= 0xF7;}\
    else {CMPCR1 |= 0x08; \
    ADC_CONTR = (ADC_CONTR & 0xF0)|(PEPin)|0x80;  }}

/*--------------------------------------------------------
| @Description: COMP NEPin select define function        |
--------------------------------------------------------*/

#define  COMP_NEINPUT_CFG(NEPin)     CMPCR1 = (CMPCR1 & 0xFB) | ((NEPin & 0xF0) >> 2)

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    COMP_Init
  * @brief   COMP init function
  * @param   *compx : COMP_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE COMP_Init(const COMP_InitType* compx)
{
    if(compx -> DC_FTW > 0x3F) return FSC_FAIL;
    COMP_PEINPUT_CFG(compx -> PEPin);
    COMP_NEINPUT_CFG(compx -> NEPin);
    CMPCR2 = (CMPCR2 & 0xBF) | (compx -> AC_FTW << 6);
    CMPCR2 = (CMPCR2 & 0xC0) | (compx -> DC_FTW);
    CMPCR2 = (CMPCR2 & 0x7F) | (compx -> DIRPut << 7);
    CMPCR1 = (CMPCR1 & 0xFD) | (compx -> Output << 1);
    CMPCR1 = (CMPCR1 & 0x7F) | (compx -> Run << 7);
    return FSC_SUCCESS;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



