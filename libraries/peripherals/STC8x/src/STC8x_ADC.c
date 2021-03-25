/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_ADC.c
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

 * You should have received a copy of the Apache-2.0 License.Ant Real Time
 * Operating System. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_ADC.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
/**
  * @name    nop
  * @brief   working wait nop function
  * @param   None
  * @return  None
***/
static void nop(void)
{
	uint8_t i = 255;
	while(i--);
}

/**
  * @name    ADC_Init
  * @brief   ADC peripheral init function
  * @param   *adcx  ADC_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE ADC_Init(const ADC_InitType* adcx)
{
    if(adcx -> Speed <= 0x0F) 
    {
        EAXFR_ENABLE();
        ADCTIM = 0x3F;
        EAXFR_DISABLE();
        ADC_CONTR = (ADC_CONTR & 0x70)|(adcx -> Power << 7)|(adcx -> Road);
        nop();
        ADCCFG = (ADCCFG & 0xF0) | (adcx -> Speed);	
        ADCCFG = (ADCCFG & 0xDF) | (adcx -> Align << 5);	
        ADC_CONTR = (ADC_CONTR & 0xBF) | (adcx -> Run << 6);
        return FSC_SUCCESS;
    }
    else return FSC_FAIL;
}

/**
  * @name    ADC_Get_Sample
  * @brief   ADC get sample function
  * @param   road  ADCRoad_Type
  * @param   acc   ADCAcc_Type
  * @return  value of adc sample (uint16_t)
***/
uint16_t ADC_Get_Sample(uint8_t road, ADCAcc_Type acc)
{	
    uint16_t value;
    ADC_RES = 0;
    ADC_RESL = 0;
    ADC_CONTR = (ADC_CONTR & 0xF0) | ADC_POWER | (road);
    while (!(ADC_CONTR & 0x20));  //Query ADC completion flag
    ADC_CONTR &= 0xDF;  //Completion mark
    value = (uint16_t)(ADC_RES << 8) | ADC_RESL;  
    value >>= acc; //Selection accuracy
    ADC_CONTR |= 0x40; //Restart
    return value;
}

/**
  * @name    ADC_Get_Sample_interrupt
  * @brief   ADC get sample in interrupt function
  * @param   road  ADCRoad_Type
  * @param   acc   ADCAcc_Type
  * @return  value of adc sample (uint16_t)
***/
uint16_t ADC_Get_Sample_interrupt(uint8_t road, ADCAcc_Type acc)
{	
    uint16_t value;
    ADC_RES = 0;
    ADC_RESL = 0;
    ADC_CONTR = (ADC_CONTR & 0xF0) | (road);
    ADC_CONTR &= 0xDF;  //Completion mark
    value = (uint16_t)(ADC_RES << 8) | ADC_RESL;  
    value >>= acc; //Selection accuracy
    ADC_CONTR |= 0x40; //Restart
    return value;
}
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



