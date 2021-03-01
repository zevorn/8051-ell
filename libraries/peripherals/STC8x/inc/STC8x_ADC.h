/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_ADC.h
  - Author        : zeweni
  - Update date   : 2020.01.29
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                      Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote ADC chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_ADC_H_
#define __STC8x_ADC_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"
#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#if    (PER_LIB_MCU_MUODEL == STC8Ax)
    #include "STC8Ax_REG.h"  
#elif  (PER_LIB_MCU_MUODEL == STC8Cx)
    #include "STC8Cx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Fx)
    #include "STC8Fx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Gx)
    #include "STC8Gx_REG.h"
#elif  (PER_LIB_MCU_MUODEL == STC8Hx)
    #include "STC8Hx_REG.h"
#endif
/*--------------------------------------------------------
| @Description: STC8x core                               |
--------------------------------------------------------*/
#include "STC8x_CORE.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: ADC road enum                            |
--------------------------------------------------------*/
typedef enum
{
    ADC_Road_P10 = 0x00, 
    ADC_Road_P11 = 0x01, 
    ADC_Road_P12 = 0x02, 
    ADC_Road_P13 = 0x03, 
    ADC_Road_P14 = 0x04, 
    ADC_Road_P15 = 0x05, 
    ADC_Road_P16 = 0x06, 
    ADC_Road_P17 = 0x07, 

    #if    (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Fx)		  
        ADC_Road_P00 = 0x08, 
        ADC_Road_P01 = 0x09, 
        ADC_Road_P02 = 0x0A, 
        ADC_Road_P03 = 0x0B, 
        ADC_Road_P04 = 0x0C, 
        ADC_Road_P05 = 0x0D, 
        ADC_Road_P06 = 0x0E, 
    #elif  (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx )
        ADC_Road_P30 = 0x08, 
        ADC_Road_P31 = 0x09, 
        ADC_Road_P32 = 0x0A, 
        ADC_Road_P33 = 0x0B, 
        ADC_Road_P34 = 0x0C, 
        ADC_Road_P35 = 0x0D, 
        ADC_Road_P36 = 0x0E, 
    #endif
    ADC_Road_REV = 0x0F	//Test the internal 1.344v refv voltage
}   ADCRoad_Type;

/*--------------------------------------------------------
| @Description: ADC Accuracy enum                        |
--------------------------------------------------------*/

typedef enum
{
    ADC_Acc_12Bit = 0,    //12 bit accuracy
    ADC_Acc_11Bit    ,    //11 bit accuracy
    ADC_Acc_10Bit    ,    //10 bit accuracy
    ADC_Acc_9Bit     ,    //9 bit accuracy
    ADC_Acc_8Bit          //8 bit accuracy
}   ADCAcc_Type;

/*--------------------------------------------------------
| @Description: ADC Align enum                           |
--------------------------------------------------------*/

typedef enum
{
    ADC_Left  = 0,  //After set, the data is aligned to the left
    ADC_Right = 1,  //After collection, the data is aligned to the right
}   ADCAlign_Type;


/**
  * @name    ADC_InitType
  * @brief   ADC Init structure
  * @param   Power  ADC power control bit
  * @param   Road  ADC channel selection
  * @param   Speed  The maximum ADC conversion speed (working clock frequency) is 0x0f
  * @param   Align  ADC data format alignment
  * @param   Run ADC conversion operation control bit
***/
typedef struct 
{
    FUNSTATE Power;
    ADCRoad_Type Road;
    uint8_t Speed;
    ADCAlign_Type Align; 
    FUNSTATE Run;  
}   ADC_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL != STC8Fx)
/*--------------------------------------------------------
| @Description: ADC get Sample (Query mode)              |
--------------------------------------------------------*/

uint16_t ADC_Get_Sample(ADCRoad_Type road, ADCAcc_Type acc);
uint16_t ADC_Get_Sample_interrupt(ADCRoad_Type road, ADCAcc_Type acc);

/*--------------------------------------------------------
| @Description: ADC init function                        |
--------------------------------------------------------*/

FSCSTATE ADC_Init(const ADC_InitType *adcx);
#endif
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

