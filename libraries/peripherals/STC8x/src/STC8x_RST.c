/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_RST.c
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
#include "STC8x_RST.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    SFW_RST_Ctrl
  * @brief   Software reset function
  * @param   choice   RST_USER_DATA_KEEP | RST_USER_DATA_CLEAN
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE SFW_RST_Ctrl(RSTChoice_Type choice, BOOL run)
{
	IAP_CONTR = (IAP_CONTR & 0xBF) | (choice << 6);
	IAP_CONTR = (IAP_CONTR & 0xDF) | (run << 5);
	return FSC_SUCCESS;
}

/**
  * @name    LVD_RST_Init
  * @brief   Software reset function
  * @param   lvDiv   LVD_RST_2_2V | LVD_RST_2_4V | LVD_RST_2_7V | LVD_RST_3_0V
  * @param   run     ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE LVD_RST_Init(LVDRstDiv_Type lvDiv, BOOL run)
{
	RSTCFG = (RSTCFG & 0xFC) | lvDiv;
	RSTCFG = (RSTCFG & 0xEF) | (run << 6);
	return FSC_SUCCESS;
}

/**
  * @name    Auto_RST_download
  * @brief   Software auto reset download function
  * @param   none
  * @return  none
***/
void Auto_RST_download(void)
{
  static uint8_t semCont = 0;
  if(SBUF == 0x7F || SBUF == 0x80) 
  {
    if(++semCont >= 10)
    {
      semCont = 0;
      IAP_CONTR = 0x60;
    }
  }
  else
  {
    semCont = 0;
  }
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



