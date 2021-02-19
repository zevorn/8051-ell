/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_COMP.c
  - Author        : zeweni
  - Update date   : 2020.02.06                 
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
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
    ADC_CONTR = (ADC_CONTR & 0xF0)|(PEPin);  }}

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
FSCSTATE COMP_Init(const COMP_InitType *compx)
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



