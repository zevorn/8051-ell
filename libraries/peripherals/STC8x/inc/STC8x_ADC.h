/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_ADC.h
  - Author        : zeweni
  - Update date   : 2020.03.02
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
#ifndef __STC8x_ADC_H_
#define __STC8x_ADC_H_
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
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
/*--------------------------------------------------------
| @Description: ADC road defin                           |
--------------------------------------------------------*/

#define    ADC_Road_REV    0x0F	   //Test the internal refv voltage

/* STC8Ax */
#define    ADC_Road_P10_8Ax    0x00
#define    ADC_Road_P11_8Ax    0x01
#define    ADC_Road_P12_8Ax    0x02
#define    ADC_Road_P13_8Ax    0x03
#define    ADC_Road_P14_8Ax    0x04
#define    ADC_Road_P15_8Ax    0x05
#define    ADC_Road_P16_8Ax    0x06
#define    ADC_Road_P17_8Ax    0x07
#define    ADC_Road_P00_8Ax    0x08
#define    ADC_Road_P01_8Ax    0x09
#define    ADC_Road_P02_8Ax    0x0A
#define    ADC_Road_P03_8Ax    0x0B
#define    ADC_Road_P04_8Ax    0x0C
#define    ADC_Road_P05_8Ax    0x0D
#define    ADC_Road_P06_8Ax    0x0E

/* STC8G1K08A 8Pin */
#define    ADC_Road_P30_8G1K08A    0x00
#define    ADC_Road_P31_8G1K08A    0x01
#define    ADC_Road_P32_8G1K08A    0x02
#define    ADC_Road_P33_8G1K08A    0x03        
#define    ADC_Road_P54_8G1K08A    0x04
#define    ADC_Road_P55_8G1K08A    0x05

/* STC8G1K08 16Pin and 20Pin / STC8G1K08T 20Pin */
#define    ADC_Road_P10_8G1K08_T    0x00
#define    ADC_Road_P11_8G1K08_T    0x01
#define    ADC_Road_P12_8G1K08_T    0x02
#define    ADC_Road_P13_8G1K08_T    0x03
#define    ADC_Road_P14_8G1K08_T    0x04
#define    ADC_Road_P15_8G1K08_T    0x05
#define    ADC_Road_P16_8G1K08_T    0x06
#define    ADC_Road_P17_8G1K08_T    0x07
#define    ADC_Road_P30_8G1K08_T    0x08
#define    ADC_Road_P31_8G1K08_T    0x09
#define    ADC_Road_P32_8G1K08_T    0x0A
#define    ADC_Road_P33_8G1K08_T    0x0B
#define    ADC_Road_P34_8G1K08_T    0x0C
#define    ADC_Road_P35_8G1K08_T    0x0D
#define    ADC_Road_P36_8G1K08_T    0x0E

/* STC8G2K64S4 16Pin / STC8G2K64S2 */
#define    ADC_Road_P10_8G2K64S2_S4    0x00
#define    ADC_Road_P11_8G2K64S2_S4    0x01
#define    ADC_Road_P12_8G2K64S2_S4    0x02
#define    ADC_Road_P13_8G2K64S2_S4    0x03
#define    ADC_Road_P14_8G2K64S2_S4    0x04
#define    ADC_Road_P15_8G2K64S2_S4    0x05
#define    ADC_Road_P16_8G2K64S2_S4    0x06
#define    ADC_Road_P17_8G2K64S2_S4    0x07
#define    ADC_Road_P00_8G2K64S2_S4    0x08
#define    ADC_Road_P01_8G2K64S2_S4    0x09
#define    ADC_Road_P02_8G2K64S2_S4    0x0A
#define    ADC_Road_P03_8G2K64S2_S4    0x0B
#define    ADC_Road_P04_8G2K64S2_S4    0x0C
#define    ADC_Road_P05_8G2K64S2_S4    0x0D
#define    ADC_Road_P06_8G2K64S2_S4    0x0E
   
/* STC8H1K28 */
#define    ADC_Road_P10_8H1K28    0x00
#define    ADC_Road_P11_8H1K28    0x01
#define    ADC_Road_P12_8H1K28    0x02
#define    ADC_Road_P13_8H1K28    0x03
#define    ADC_Road_P14_8H1K28    0x04
#define    ADC_Road_P15_8H1K28    0x05
#define    ADC_Road_P16_8H1K28    0x06
#define    ADC_Road_P17_8H1K28    0x07
#define    ADC_Road_P00_8H1K28    0x08
#define    ADC_Road_P01_8H1K28    0x09
#define    ADC_Road_P02_8H1K28    0x0A
#define    ADC_Road_P03_8H1K28    0x0B

/* STC8H1K08 */
#define    ADC_Road_P10_8H1K08    0x00
#define    ADC_Road_P11_8H1K08    0x01
#define    ADC_Road_P30_8H1K08    0x08
#define    ADC_Road_P31_8H1K08    0x09
#define    ADC_Road_P32_8H1K08    0x0A
#define    ADC_Road_P33_8H1K08    0x0B
#define    ADC_Road_P34_8H1K08    0x0C
#define    ADC_Road_P35_8H1K08    0x0D
#define    ADC_Road_P36_8H1K08    0x0E

/* STC8H3K64S2 / STC8H3K64S4 */
#define    ADC_Road_P10_8H3K64S2_S4    0x00
#define    ADC_Road_P11_8H3K64S2_S4    0x01
#define    ADC_Road_P12_8H3K64S2_S4    0x02
#define    ADC_Road_P16_8H3K64S2_S4    0x06
#define    ADC_Road_P17_8H3K64S2_S4    0x07
#define    ADC_Road_P00_8H3K64S2_S4    0x08
#define    ADC_Road_P01_8H3K64S2_S4    0x09
#define    ADC_Road_P02_8H3K64S2_S4    0x0A
#define    ADC_Road_P03_8H3K64S2_S4    0x0B
#define    ADC_Road_P04_8H3K64S2_S4    0x0C
#define    ADC_Road_P05_8H3K64S2_S4    0x0D
#define    ADC_Road_P06_8H3K64S2_S4    0x0E

/* STC8H8K64U / STC8H2K64T */
#define    ADC_Road_P10_8H8K64U_2K64T    0x00
#define    ADC_Road_P11_8H8K64U_2K64T    0x01
#define    ADC_Road_P54_8H8K64U_2K64T    0x02
#define    ADC_Road_P13_8H8K64U_2K64T    0x03
#define    ADC_Road_P14_8H8K64U_2K64T    0x04
#define    ADC_Road_P15_8H8K64U_2K64T    0x05
#define    ADC_Road_P16_8H8K64U_2K64T    0x06
#define    ADC_Road_P17_8H8K64U_2K64T    0x07
#define    ADC_Road_P00_8H8K64U_2K64T    0x08
#define    ADC_Road_P01_8H8K64U_2K64T    0x09
#define    ADC_Road_P02_8H8K64U_2K64T    0x0A
#define    ADC_Road_P03_8H8K64U_2K64T    0x0B
#define    ADC_Road_P04_8H8K64U_2K64T    0x0C
#define    ADC_Road_P05_8H8K64U_2K64T    0x0D
#define    ADC_Road_P06_8H8K64U_2K64T    0x0E

/*--------------------------------------------------------
| @Description: ADC Accuracy enum                        |
--------------------------------------------------------*/

#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Hx )
    typedef enum
    {
        ADC_Acc_12Bit = 0x00,    //12 bit accuracy
        ADC_Acc_11Bit = 0x01,    //11 bit accuracy
        ADC_Acc_10Bit = 0x02,    //10 bit accuracy
        ADC_Acc_9Bit  = 0x03,    //9 bit accuracy
        ADC_Acc_8Bit  = 0x04     //8 bit accuracy
    }   ADCAcc_Type;
#elif  (PER_LIB_MCU_MUODEL == STC8Gx )
    typedef enum
    {
        ADC_Acc_10Bit = 0x00,    //10 bit accuracy
        ADC_Acc_09Bit = 0x01,    // 9 bit accuracy
        ADC_Acc_08Bit = 0x02     // 8 bit accuracy
    }   ADCAcc_Type;
#endif
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
    uint8_t Road;
    uint8_t Speed;
    ADCAlign_Type Align; 
    FUNSTATE Run;
}   ADC_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: ADC get Sample (Query mode)              |
--------------------------------------------------------*/

uint16_t ADC_Get_Sample(uint8_t road, ADCAcc_Type acc);
uint16_t ADC_Get_Sample_interrupt(uint8_t road, ADCAcc_Type acc);

/*--------------------------------------------------------
| @Description: ADC init function                        |
--------------------------------------------------------*/

FSCSTATE ADC_Init(const ADC_InitType *adcx);


#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

