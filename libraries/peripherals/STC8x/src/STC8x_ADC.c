/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_ADC.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
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
FSCSTATE ADC_Init(const ADC_InitType *adcx)
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
  * @return  Value of adc sample (uint16_t)
***/
uint16_t ADC_Get_Sample(ADCRoad_Type road, ADCAcc_Type acc)
{	
    uint16_t Value;
    ADC_RES = 0;
    ADC_RESL = 0;
    ADC_CONTR = (ADC_CONTR & 0xF0) | ADC_POWER | (road);
    while (!(ADC_CONTR & 0x20));  //Query ADC completion flag
    ADC_CONTR &= 0xDF;  //Completion mark
    Value = (uint16_t)(ADC_RES << 8) | ADC_RESL;  
    Value >>= acc; //Selection accuracy
    ADC_CONTR |= 0x40; //Restart
    return Value;
}

/**
  * @name    ADC_Get_Sample_interrupt
  * @brief   ADC get sample in interrupt function
  * @param   road  ADCRoad_Type
  * @param   acc   ADCAcc_Type
  * @return  Value of adc sample (uint16_t)
***/
uint16_t ADC_Get_Sample_interrupt(ADCRoad_Type road, ADCAcc_Type acc)
{	
    uint16_t Value;
    ADC_RES = 0;
    ADC_RESL = 0;
    ADC_CONTR = (ADC_CONTR & 0xF0) | (road);
    ADC_CONTR &= 0xDF;  //Completion mark
    Value = (uint16_t)(ADC_RES << 8) | ADC_RESL;  
    Value >>= acc; //Selection accuracy
    ADC_CONTR |= 0x40; //Restart
    return Value;
}
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



