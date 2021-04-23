/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_GPIO.h
  - Author        : zeweni
  - Update date   : 2020.01.29
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
#ifndef __STC8x_GPIO_H_
#define __STC8x_GPIO_H_

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
#include "ELL_CORE.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: GPIO Pin define                          |
--------------------------------------------------------*/
/* GPIO */
#define	GPIO_P0      0x00 //IO P0
#define	GPIO_P1      0x01 //IO P1
#define	GPIO_P2      0x02 //IO P2
#define	GPIO_P3      0x03 //IO P3
#define	GPIO_P4      0x04 //IO P4
#define	GPIO_P5      0x05 //IO P5
#define	GPIO_P6      0x06 //IO P6
#define	GPIO_P7      0x07 //IO P7

/* Pin */
#define	Pin_0    0x01  //IO Pin Px.0
#define	Pin_1    0x02  //IO Pin Px.1
#define	Pin_2    0x04  //IO Pin Px.2
#define	Pin_3    0x08  //IO Pin Px.3
#define	Pin_4    0x10  //IO Pin Px.4
#define	Pin_5    0x20  //IO Pin Px.5
#define	Pin_6    0x40  //IO Pin Px.6
#define	Pin_7    0x80  //IO Pin Px.7
#define	Pin_Low  0x0F  //IO Pin Px.0~3
#define	Pin_High 0xF0  //IO Pin Px.4~7
#define	Pin_All  0xFF  //IO All  Pin	

/*--------------------------------------------------------
| @Description: External interrupt Trigger define        |
--------------------------------------------------------*/

typedef enum
{
  EXTI_Tri_Edge    = 0x00,  //Both rising and falling edges triggered
  EXTI_Tri_Falling = 0x01    //Falling edge trigger
} EXTITri_Type;



/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: GPIO control define function             |
--------------------------------------------------------*/

#define  GPIO_MODE_WEAK_PULL(GPIO_x,Pin)    do{ GPIO_x##M1 &= ~(Pin), GPIO_x##M0 &= ~(Pin); }while(0)
#define  GPIO_MODE_IN_FLOATING(GPIO_x,Pin)  do{ GPIO_x##M1 |=  (Pin), GPIO_x##M0 &= ~(Pin); }while(0)
#define  GPIO_MODE_OUT_OD(GPIO_x,Pin)       do{ GPIO_x##M1 |=  (Pin), GPIO_x##M0 |=  (Pin); }while(0)
#define  GPIO_MODE_OUT_PP(GPIO_x,Pin)       do{ GPIO_x##M1 &= ~(Pin), GPIO_x##M0 |=  (Pin); }while(0)

/*--------------------------------------------------------
| @Description: GPIO toggel pin control define function  |
--------------------------------------------------------*/

#define  GPIO_TOGGLE_PIN(GPIO_x,Pin)    {GPIO_x##_IO ^= Pin;}

/*--------------------------------------------------------
| @Description: GPIO pull up control define              |
--------------------------------------------------------*/

#define GPIO_PULL_UP_ENABLE(GPIO_x,Pin)    do{EAXFR_ENABLE(); PxPU(GPIO_x##PU_ADDRESS) |=  (Pin); EAXFR_DISABLE();}while(0)
#define GPIO_PULL_UP_DISABLE(GPIO_x,Pin)   do{EAXFR_ENABLE(); PxPU(GPIO_x##PU_ADDRESS) &= ~(Pin); EAXFR_DISABLE();}while(0)
																	
/*--------------------------------------------------------
| @Description: GPIO schmidt trigger control define      |
--------------------------------------------------------*/

#define GPIO_ST_ENABLE(GPIO_x,Pin)     do{EAXFR_ENABLE(); PxNCS(GPIO_x##NCS_ADDRESS) |=  (Pin); EAXFR_DISABLE();}while(0)
#define GPIO_ST_DISABLE(GPIO_x,Pin)    do{EAXFR_ENABLE(); PxNCS(GPIO_x##NCS_ADDRESS) &= ~(Pin); EAXFR_DISABLE();}while(0)

/*--------------------------------------------------------
| @Description: GPIO level conversion speed define       |
--------------------------------------------------------*/

#define GPIO_SPEED_LOW(GPIO_x,Pin)      do{EAXFR_ENABLE(); PxSR(GPIO_x##SR_ADDRESS) |= (Pin);  EAXFR_DISABLE();}while(0)
#define GPIO_SPEED_HIGH(GPIO_x,Pin)     do{EAXFR_ENABLE(); PxSR(GPIO_x##SR_ADDRESS) &= ~(Pin); EAXFR_DISABLE();}while(0)

/*--------------------------------------------------------
| @Description: GPIO drive current control define        |
--------------------------------------------------------*/

#define GPIO_DRIVE_MEDIUM(GPIO_x,Pin)   do{EAXFR_ENABLE(); PxDR(GPIO_x##DR_ADDRESS) |=  (Pin); EAXFR_DISABLE();}while(0)
#define GPIO_DRIVE_HIGH(GPIO_x,Pin)     do{EAXFR_ENABLE(); PxDR(GPIO_x##DR_ADDRESS) &= ~(Pin); EAXFR_DISABLE();}while(0)

FSCSTATE EXTI0_Init(EXTITri_Type triMode);
FSCSTATE EXTI1_Init(EXTITri_Type triMode);

FSCSTATE NVIC_EXTI0_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_EXTI1_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_EXTI2_Init(BOOL run);
FSCSTATE NVIC_EXTI3_Init(BOOL run);
FSCSTATE NVIC_EXTI4_Init(BOOL run);

#define    NVIC_EXTI0_CTRL(run)     do{ EX0 = run; }while(0)
#define    NVIC_EXTI1_CTRL(run)     do{ EX1 = run; }while(0)
#define    NVIC_EXTI2_CTRL(run)     do{ INTCLKO = (INTCLKO & 0xEF) | (run << 4); }while(0)
#define    NVIC_EXTI3_CTRL(run)     do{ INTCLKO = (INTCLKO & 0xDF) | (run << 5); }while(0)
#define    NVIC_EXTI4_CTRL(run)     do{ INTCLKO = (INTCLKO & 0xBF) | (run << 6); }while(0)

/*--------------------------------------------------------
| @Description: GPIO Pin switching function              |
--------------------------------------------------------*/



#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

