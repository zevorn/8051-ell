/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_SPI.c
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
#include "STC8x_SPI.h"
/*-----------------------------------------------------------------------
|                                 datA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    SPI_Init
  * @brief   SPI init function 
  * @param   *spix    SPIInit_Type
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE SPI_Init(SPIInit_Type* spix)
{
    SPDAT = 0;
    SPSTAT = SPIF | WCOL;          
    SPCTL = (SPCTL & 0x6B) | (spix -> Type);
    SPCTL = (SPCTL & 0xFC) | (spix -> ClkSrc);
    SPCTL = (SPCTL & 0xF3) | (spix -> Mode << 2);
    SPCTL = (SPCTL & 0xDF) | (spix -> Tran << 5);
    SPCTL = (SPCTL & 0xBF) | (spix -> Run << 6);  
    return FSC_SUCCESS;
}

/**
  * @name    SPI_Send_Data
  * @brief   SPI send data function 
  * @param   dat    data of SPI (uint8)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE SPI_Send_Data(uint8_t dat)
{
    SPDAT = dat;			//Data register assignment
    while (!(SPSTAT & 0x80));  //Query completion flag
    SPSTAT = 0xC0;         //Clear interrupt flag
	return FSC_SUCCESS;
}

/**
  * @name    SPI_Rev_Data
  * @brief   SPI receive data function 
  * @param   None
  * @return  receive data (uint8) 
***/
uint8_t SPI_Rev_Data(void)
{
    while (!(SPSTAT & 0x80));  //Query completion flag
    SPSTAT = 0xC0;         //Clear interrupt flag
    return SPDAT;  //Data register assignment
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



