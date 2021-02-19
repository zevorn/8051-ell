/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_PCA.h
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
  *  2020.12.20         zeweni       Wrote PCA chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_PCA_H_
#define __STC8x_PCA_H_
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
| @Description: PCA mode enum                            |
--------------------------------------------------------*/

typedef enum
{
  PCA_TYPE_CAP = 0X00,
  PCA_TYPE_PWM = 0x42,
  PCA_TYPE_TIM = 0x48,
  PCA_TYPE_POP = 0x4C
} PCAType_Type;

/*--------------------------------------------------------
| @Description: CAP mode enum                            |
--------------------------------------------------------*/

typedef enum
{
  CAP_Mode_Falling = 0x01,
  CAP_Mode_Rising  = 0X02,
  CAP_Mode_Edge    = 0x03
} CAPMode_Type;

/*--------------------------------------------------------
| @Description: PCA clock mode enum                      |
--------------------------------------------------------*/

typedef enum
{
	PCA_SCLK_DIV_12 = 0x00,  //  System clock / 12
	PCA_SCLK_DIV_2  = 0x02,  //  System clock / 2
	PCA_TIMER0	    = 0x04,  //  Overflow pulse of timer 0
	PCA_ECI         = 0x06,  //  External input clock of ECI pin
	PCA_SCLK_DIV_1	= 0x08,  //  System clock / 1
	PCA_SCLK_DIV_4  = 0x0A,  //  System clock / 4
	PCA_SCLK_DIV_6  = 0x0C,  //  System clock / 6
	PCA_SCLK_DIV_8  = 0x0E   //  System clock / 8
}	PCACLKSrc_Type;

/*--------------------------------------------------------
| @Description: PCA PWM bits mode enum                   |
--------------------------------------------------------*/

typedef enum
{
	PCA_PWM_8Bit   = 0x00,  // 8-bit PCA_PWM mode
	PCA_PWM_7Bit   = 0x01,	// 7-bit PCA_PWM mode
	PCA_PWM_6Bit   = 0x02,	// 6-bit PCA_PWM mode
	PCA_PWM_10Bit  = 0x03	//10-bit PCA_PWM mode
}	PCA_PWMBits_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL != STC8Fx)
/*--------------------------------------------------------
| @Description: PCA Counter working function             |
--------------------------------------------------------*/

FSCSTATE PCA_CNT_Init(PCACLKSrc_Type clkSrc,FUNSTATE run);

/*--------------------------------------------------------
| @Description: PCA PWM mode working function            |
--------------------------------------------------------*/

FSCSTATE PCA0_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);
FSCSTATE PCA1_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);
FSCSTATE PCA2_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);
FSCSTATE PCA3_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);

/*--------------------------------------------------------
| @Description: PCA CAP mode working function            |
--------------------------------------------------------*/

FSCSTATE PCA0_CAP_Init(CAPMode_Type mode);
FSCSTATE PCA1_CAP_Init(CAPMode_Type mode);
FSCSTATE PCA2_CAP_Init(CAPMode_Type mode);
FSCSTATE PCA3_CAP_Init(CAPMode_Type mode);

/*--------------------------------------------------------
| @Description: PCA TIMER mode working function          |
--------------------------------------------------------*/

FSCSTATE PCA0_TIM_Init(uint16_t value);
FSCSTATE PCA1_TIM_Init(uint16_t value);
FSCSTATE PCA2_TIM_Init(uint16_t value);
FSCSTATE PCA3_TIM_Init(uint16_t value);

/*--------------------------------------------------------
| @Description: PCA POP mode working function            |
--------------------------------------------------------*/

FSCSTATE PCA0_POP_Init(uint16_t value);
FSCSTATE PCA1_POP_Init(uint16_t value);
FSCSTATE PCA2_POP_Init(uint16_t value);
FSCSTATE PCA3_POP_Init(uint16_t value);

/*--------------------------------------------------------
| @Description: PCA PWM and POP reload value function    |
--------------------------------------------------------*/

void PCA0_TIM_POP_ReValue(void);
void PCA1_TIM_POP_ReValue(void);
void PCA2_TIM_POP_ReValue(void);
void PCA3_TIM_POP_ReValue(void);

/*--------------------------------------------------------
| @Description: PCA control define function              |
--------------------------------------------------------*/

#define    PCA0_WORK_STOP()   CCAPM0 = 0
#define    PCA1_WORK_STOP()   CCAPM1 = 0
#define    PCA2_WORK_STOP()   CCAPM2 = 0
#define    PCA3_WORK_STOP()   CCAPM3 = 0

#endif
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

