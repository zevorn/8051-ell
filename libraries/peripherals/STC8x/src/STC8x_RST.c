/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_RST.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
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
FSCSTATE SFW_RST_Ctrl(RSTChoice_Type choice, FUNSTATE run)
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
FSCSTATE LVD_RST_Init(LVDRstDiv_Type lvDiv, FUNSTATE run)
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
  static uint8 semCont = 0;
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



