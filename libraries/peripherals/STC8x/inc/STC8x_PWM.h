/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_PWM.h
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
#ifndef __STC8x_PWM_H_
#define __STC8x_PWM_H_

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
#include "ELL_CORE.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#if (PER_LIB_MCU_MUODEL == STC8Ax)

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

/*--------------------------------------------------------
| @Description: PWM road interrupt flip enum             |
--------------------------------------------------------*/

typedef enum
{
  PWM_Flip_Null   = 0x00 , 
  PWM_Flip_First  = 0x05 ,
  PWM_Flip_Second = 0x06 ,
  PWM_Flip_Both   = 0x07 
} PWMFlip_Type;


/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

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

FSCSTATE PWM_CNT_Init(PWMCLKSrc_Type clkSrc,uint16_t value,BOOL run);

/*--------------------------------------------------------
| @Description: PWM road working function                |
--------------------------------------------------------*/

FSCSTATE PWM0_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM1_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM2_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM3_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM4_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM5_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM6_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
FSCSTATE PWM7_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);

/*--------------------------------------------------------
| @Description: PWM abnormal detection init function      |
--------------------------------------------------------*/

FSCSTATE PWM_ABD_Init(PWMADSMode_Type mode,PWMABSignal_Type signal,BOOL run);

/*--------------------------------------------------------
| @Description: PWM trigger associated ADC init function |
--------------------------------------------------------*/

FSCSTATE PWM_ETADC_Init(uint16_t tValue,BOOL run);

#define PWM_CNT_RTZ_GET_FLAG()    (PWMCFG &  0x80)
#define PWM_ABD_GET_FLAG()        (PWMFDCR & 0x01)

#define PWM0_GET_FLAG()           (PWMIF  &  0x01)
#define PWM1_GET_FLAG()           (PWMIF  &  0x02)
#define PWM2_GET_FLAG()           (PWMIF  &  0x04)
#define PWM3_GET_FLAG()           (PWMIF  &  0x08)
#define PWM4_GET_FLAG()           (PWMIF  &  0x10)
#define PWM5_GET_FLAG()           (PWMIF  &  0x20)
#define PWM6_GET_FLAG()           (PWMIF  &  0x40)
#define PWM7_GET_FLAG()           (PWMIF  &  0x80)

#define PWM_CNT_RTZ_CLEAR_FLAG()  PWMCFG  &= 0x7F
#define PWM_ABD_CLEAR_FLAG()      PWMFDCR &= 0xFE

#define PWM0_CLEAR_FLAG()         PWMIF &= 0xFE
#define PWM1_CLEAR_FLAG()         PWMIF &= 0xFD
#define PWM2_CLEAR_FLAG()         PWMIF &= 0xFB
#define PWM3_CLEAR_FLAG()         PWMIF &= 0xF7
#define PWM4_CLEAR_FLAG()         PWMIF &= 0xEF
#define PWM5_CLEAR_FLAG()         PWMIF &= 0xDF
#define PWM6_CLEAR_FLAG()         PWMIF &= 0xBF
#define PWM7_CLEAR_FLAG()         PWMIF &= 0x7F

FSCSTATE NVIC_PWM_CNT_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_PWM_ABD_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_PWM0_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM1_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM2_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM3_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM4_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM5_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM6_Init(PWMFlip_Type flipMode);
FSCSTATE NVIC_PWM7_Init(PWMFlip_Type flipMode);

#define    NVIC_PWM_CNT_CTRL(run)     do{ PWMCR = (PWMCR & 0xBF) | (run << 6); }while(0)	
#define    NVIC_PWM_ABD_CTRL(run)     do{ PWMFDCR = (PWMFDCR & 0xF7) | (run << 3); }while(0)	
#define    NVIC_PWM0_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)	
#define    NVIC_PWM1_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM2_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM3_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM4_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM5_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM6_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM6_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
#define    NVIC_PWM7_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		




FSCSTATE GPIO_PWM0_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM1_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM2_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM3_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM4_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM5_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM6_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_PWM7_SWPort(GPIOSWPort_Type port);



#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

