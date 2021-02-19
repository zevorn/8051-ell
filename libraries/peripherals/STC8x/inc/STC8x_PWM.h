/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_PWM.h
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote PWM chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_PWM_H_
#define __STC8x_PWM_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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
| @Description: PWM clock source enum                    |
--------------------------------------------------------*/

typedef enum
{
    PWM_SCLK_DIV_1  =  0x00,
    PWM_SCLK_DIV_2  =  0x01,
    PWM_SCLK_DIV_3  =  0x02,
    PWM_SCLK_DIV_4  =  0x03,
    PWM_SCLK_DIV_5  =  0x04,
    PWM_SCLK_DIV_6  =  0x05,
    PWM_SCLK_DIV_7  =  0x06,
    PWM_SCLK_DIV_8  =  0x07,
    PWM_SCLK_DIV_9  =  0x08,
    PWM_SCLK_DIV_10 =  0x09,
    PWM_SCLK_DIV_11 =  0x0A,
    PWM_SCLK_DIV_12 =  0x0B,
    PWM_SCLK_DIV_13 =  0x0C,
    PWM_SCLK_DIV_14 =  0x0D,
    PWM_SCLK_DIV_15 =  0x0E,
    PWM_SCLK_DIV_16 =  0x0F,
    PWM_TIMER2_PULSE = 0x1F
}   PWMCLKSrc_Type;

/*--------------------------------------------------------
| @Description: PWM road start level configure enum      |
--------------------------------------------------------*/

typedef enum
{
    PWM_Start_Low_Level  =  0x00,
    PWM_Start_High_Level =  0x01  
}   PWMStartLevel_Type;

/*--------------------------------------------------------
| @Description: PWM Anomaly detection selection enum     |
--------------------------------------------------------*/

typedef enum
{
    PWM_ADS_P35  = 0x02,
    PWM_ADS_COMP = 0x04
}   PWMADSMode_Type;

/*--------------------------------------------------------
| @Description: PWM Abnormal signal processing enum      |
--------------------------------------------------------*/

typedef enum
{
    PWM_COMP_Low_To_High = 0x00,
    PWM_COMP_High_To_Low = 0x80,
    PWM_P35_Low_To_High  = 0x00,
    PWM_P35_High_To_Low  = 0x40
}   PWMABSignal_Type;

/*--------------------------------------------------------
| @Description: PWM level hold configure enum            |
--------------------------------------------------------*/

typedef enum
{
    PWM_Hold_Normal_Level =  0x00,
    PWM_Hold_Low_Level    =  0x01,
    PWM_Hold_High_Level   =  0x02,  
}   PWMHoldLevel_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL != STC8Fx)
/*--------------------------------------------------------
| @Description: PWM Adjust the duty cycle define function|
--------------------------------------------------------*/

#define PWM0_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM0T1_ADDRESS) = fValue; PWMxT2(PWM0T2_ADDRESS) = sValue;}while(0)
#define PWM1_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM1T1_ADDRESS) = fValue; PWMxT2(PWM1T2_ADDRESS) = sValue;}while(0)
#define PWM2_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM2T1_ADDRESS) = fValue; PWMxT2(PWM2T2_ADDRESS) = sValue;}while(0)
#define PWM3_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM3T1_ADDRESS) = fValue; PWMxT2(PWM3T2_ADDRESS) = sValue;}while(0)
#define PWM4_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM4T1_ADDRESS) = fValue; PWMxT2(PWM4T2_ADDRESS) = sValue;}while(0)
#define PWM5_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM5T1_ADDRESS) = fValue; PWMxT2(PWM5T2_ADDRESS) = sValue;}while(0)
#define PWM6_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM6T1_ADDRESS) = fValue; PWMxT2(PWM6T2_ADDRESS) = sValue;}while(0)
#define PWM7_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM7T1_ADDRESS) = fValue; PWMxT2(PWM7T2_ADDRESS) = sValue;}while(0)

/*--------------------------------------------------------
| @Description: PWM working function                     |
--------------------------------------------------------*/

FSCSTATE PWM_CNT_Init(PWMCLKSrc_Type clkSrc,uint16_t value,FUNSTATE run);

/*--------------------------------------------------------
| @Description: PWM road working function                |
--------------------------------------------------------*/

FSCSTATE PWM0_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM1_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM2_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM3_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM4_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM5_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM6_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);
FSCSTATE PWM7_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,FUNSTATE run);

/*--------------------------------------------------------
| @Description: PWM abnormal detection init function      |
--------------------------------------------------------*/

FSCSTATE PWM_ABD_Init(PWMADSMode_Type mode,PWMABSignal_Type signal,FUNSTATE run);

/*--------------------------------------------------------
| @Description: PWM trigger associated ADC init function |
--------------------------------------------------------*/

FSCSTATE PWM_ETADC_Init(uint16_t tValue,FUNSTATE run);
#endif
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

