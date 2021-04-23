/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_PCA.h
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
#ifndef __STC8x_PCA_H_
#define __STC8x_PCA_H_

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
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx)

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
	PCA_PWM_8Bits   = 0x00,  // 8-bit PCA_PWM mode
	PCA_PWM_7Bits   = 0x01,	// 7-bit PCA_PWM mode
	PCA_PWM_6Bits   = 0x02,	// 6-bit PCA_PWM mode
	PCA_PWM_10Bits  = 0x03	//10-bit PCA_PWM mode
}	PCA_PWMBits_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

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

#if (PER_LIB_MCU_MUODEL == STC8Ax)
FSCSTATE PCA3_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);
#endif

#define PCA0_PWM_6BITS_CTRL(duty)     do{ \
                                            CCAPM0 = PCA_TYPE_PWM; \
                                            PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x02 << 6); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x40) >> 6);  \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x40) >> 5);  \
                                            CCAP0L = (uint8_t)(duty & 0x003F); \
                                            CCAP0H = (uint8_t)(duty & 0x003F); \
                                        } while (0)

#define PCA0_PWM_7BITS_CTRL(duty)     do{ \
                                            CCAPM0 = PCA_TYPE_PWM; \
                                            PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x01 << 6); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x80) >> 7); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x80) >> 6); \
                                            CCAP0L = (uint8_t)(duty & 0x007F); \
                                            CCAP0H = (uint8_t)(duty & 0x007F); \
                                        } while (0)

#define PCA0_PWM_8BITS_CTRL(duty)     do{ \
                                            CCAPM0 = PCA_TYPE_PWM; \
                                            PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x00 << 6); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x100) >> 8); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x100) >> 7); \
                                            CCAP0L = (uint8_t)duty; \
                                            CCAP0H = (uint8_t)duty; \
                                        } while (0)

#define PCA0_PWM_10BITS_CTRL(duty)     do{ \
                                            CCAPM0 = PCA_TYPE_PWM; \
                                            PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x03 << 6); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x400) >> 10); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x400) >> 9); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XF3) | ((duty & 0x300) >> 6); \
                                            PCA_PWM0 = (PCA_PWM0 & 0XCF) | ((duty & 0x300) >> 4); \
                                            CCAP0L = (uint8_t)duty;  \
                                            CCAP0H = (uint8_t)duty;  \
                                        } while (0)

#define PCA1_PWM_6BITS_CTRL(duty)     do{ \
                                            CCAPM1 = PCA_TYPE_PWM; \
                                            PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x02 << 6); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x40) >> 6);  \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x40) >> 5);  \
                                            CCAP1L = (uint8_t)(duty & 0x003F); \
                                            CCAP1H = (uint8_t)(duty & 0x003F); \
                                        } while (0)

#define PCA1_PWM_7BITS_CTRL(duty)     do{ \
                                            CCAPM1 = PCA_TYPE_PWM; \
                                            PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x01 << 6); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x80) >> 7); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x80) >> 6); \
                                            CCAP1L = (uint8_t)(duty & 0x007F); \
                                            CCAP1H = (uint8_t)(duty & 0x007F); \
                                        } while (0)

#define PCA1_PWM_8BITS_CTRL(duty)     do{ \
                                            CCAPM1 = PCA_TYPE_PWM; \
                                            PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x00 << 6); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x100) >> 8); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x100) >> 7); \
                                            CCAP1L = (uint8_t)duty; \
                                            CCAP1H = (uint8_t)duty; \
                                        } while (0)

#define PCA1_PWM_10BITS_CTRL(duty)     do{ \
                                            CCAPM1 = PCA_TYPE_PWM; \
                                            PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x03 << 6); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x400) >> 10); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x400) >> 9); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XF3) | ((duty & 0x300) >> 6); \
                                            PCA_PWM1 = (PCA_PWM1 & 0XCF) | ((duty & 0x300) >> 4); \
                                            CCAP1L = (uint8_t)duty;  \
                                            CCAP1H = (uint8_t)duty;  \
                                        } while (0)

#define PCA2_PWM_6BITS_CTRL(duty)     do{ \
                                            CCAPM2 = PCA_TYPE_PWM; \
                                            PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x02 << 6); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x40) >> 6);  \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x40) >> 5);  \
                                            CCAP2L = (uint8_t)(duty & 0x003F); \
                                            CCAP2H = (uint8_t)(duty & 0x003F); \
                                        } while (0)

#define PCA2_PWM_7BITS_CTRL(duty)     do{ \
                                            CCAPM2 = PCA_TYPE_PWM; \
                                            PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x01 << 6); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x80) >> 7); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x80) >> 6); \
                                            CCAP2L = (uint8_t)(duty & 0x007F); \
                                            CCAP2H = (uint8_t)(duty & 0x007F); \
                                        } while (0)

#define PCA2_PWM_8BITS_CTRL(duty)     do{ \
                                            CCAPM2 = PCA_TYPE_PWM; \
                                            PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x00 << 6); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x100) >> 8); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x100) >> 7); \
                                            CCAP2L = (uint8_t)duty; \
                                            CCAP2H = (uint8_t)duty; \
                                        } while (0)

#define PCA2_PWM_10BITS_CTRL(duty)     do{ \
                                            CCAPM2 = PCA_TYPE_PWM; \
                                            PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x03 << 6); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x400) >> 10); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x400) >> 9); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XF3) | ((duty & 0x300) >> 6); \
                                            PCA_PWM2 = (PCA_PWM2 & 0XCF) | ((duty & 0x300) >> 4); \
                                            CCAP2L = (uint8_t)duty;  \
                                            CCAP2H = (uint8_t)duty;  \
                                        } while (0)

#if (PER_LIB_MCU_MUODEL == STC8Ax)

    #define PCA3_PWM_6BITS_CTRL(duty)     do{ \
                                                CCAPM3 = PCA_TYPE_PWM; \
                                                PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x02 << 6); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x40) >> 6);  \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x40) >> 5);  \
                                                CCAP3L = (uint8_t)(duty & 0x003F); \
                                                CCAP3H = (uint8_t)(duty & 0x003F); \
                                            } while (0)

    #define PCA3_PWM_7BITS_CTRL(duty)     do{ \
                                                CCAPM3 = PCA_TYPE_PWM; \
                                                PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x01 << 6); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x80) >> 7); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x80) >> 6); \
                                                CCAP3L = (uint8_t)(duty & 0x007F); \
                                                CCAP3H = (uint8_t)(duty & 0x007F); \
                                            } while (0)

    #define PCA3_PWM_8BITS_CTRL(duty)     do{ \
                                                CCAPM3 = PCA_TYPE_PWM; \
                                                PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x00 << 6); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x100) >> 8); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x100) >> 7); \
                                                CCAP3L = (uint8_t)duty; \
                                                CCAP3H = (uint8_t)duty; \
                                            } while (0)

    #define PCA3_PWM_10BITS_CTRL(duty)     do{ \
                                                CCAPM3 = PCA_TYPE_PWM; \
                                                PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x03 << 6); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x400) >> 10); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x400) >> 9); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XF3) | ((duty & 0x300) >> 6); \
                                                PCA_PWM3 = (PCA_PWM3 & 0XCF) | ((duty & 0x300) >> 4); \
                                                CCAP3L = (uint8_t)duty;  \
                                                CCAP3H = (uint8_t)duty;  \
                                            } while (0)

#endif

/*--------------------------------------------------------
| @Description: PCA CAP mode working function            |
--------------------------------------------------------*/

FSCSTATE PCA0_CAP_Init(CAPMode_Type mode);
FSCSTATE PCA1_CAP_Init(CAPMode_Type mode);
FSCSTATE PCA2_CAP_Init(CAPMode_Type mode);

#if (PER_LIB_MCU_MUODEL == STC8Ax)
    FSCSTATE PCA3_CAP_Init(CAPMode_Type mode);
#endif

/*--------------------------------------------------------
| @Description: PCA TIMER mode working function          |
--------------------------------------------------------*/

FSCSTATE PCA0_TIM_Init(uint16_t value);
FSCSTATE PCA1_TIM_Init(uint16_t value);
FSCSTATE PCA2_TIM_Init(uint16_t value);

#if (PER_LIB_MCU_MUODEL == STC8Ax)
    FSCSTATE PCA3_TIM_Init(uint16_t value);
#endif

/*--------------------------------------------------------
| @Description: PCA POP mode working function            |
--------------------------------------------------------*/

FSCSTATE PCA0_POP_Init(uint16_t value);
FSCSTATE PCA1_POP_Init(uint16_t value);
FSCSTATE PCA2_POP_Init(uint16_t value);

#if (PER_LIB_MCU_MUODEL == STC8Ax)
    FSCSTATE PCA3_POP_Init(uint16_t value);
#endif

/*--------------------------------------------------------
| @Description: PCA PWM and POP reload value function    |
--------------------------------------------------------*/

void PCA0_TIM_POP_ReValue(void);
void PCA1_TIM_POP_ReValue(void);
void PCA2_TIM_POP_ReValue(void);

#if (PER_LIB_MCU_MUODEL == STC8Ax)
    void PCA3_TIM_POP_ReValue(void);
#endif

/*--------------------------------------------------------
| @Description: PCA control define function              |
--------------------------------------------------------*/

#define    PCA0_WORK_STOP()   CCAPM0 = 0
#define    PCA1_WORK_STOP()   CCAPM1 = 0
#define    PCA2_WORK_STOP()   CCAPM2 = 0

#if (PER_LIB_MCU_MUODEL == STC8Ax)
    #define    PCA3_WORK_STOP()   CCAPM3 = 0
#endif

#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

