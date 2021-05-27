/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Hx_REG.h
  - Author        : zeweni
  - Update date   : 2020.02.19                 
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
#ifndef __STC8Hx_REG_H_
#define __STC8Hx_REG_H_

#include "ELL_TYPE.h"

/*-----------------------------------------------------------------------
|                                REGISTER                               |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: kernel management                        |
--------------------------------------------------------*/

//内核特殊功能寄存器
sfr ACC         =   0xe0;
sfr B           =   0xf0;
sfr PSW         =   0xd0;
sbit CY         =   PSW^7;
sbit AC         =   PSW^6;
sbit F0         =   PSW^5;
sbit RS1        =   PSW^4;
sbit RS0        =   PSW^3;
sbit OV         =   PSW^2;
sbit F1         =   PSW^1;
sbit P          =   PSW^0;
sfr SP          =   0x81;
sfr DPL         =   0x82;
sfr DPH         =   0x83;
sfr TA          =   0xae;
sfr DPS         =   0xe3;
sfr DPL1        =   0xe4;
sfr DPH1        =   0xe5;

/*--------------------------------------------------------
| @Description: system management                        |
--------------------------------------------------------*/

/* Base address define */
#define AUXR_ADDRESS       0x8EU
#define AUXR2_ADDRESS      0x8FU
#define PER_SW1_ADDRESS    0xA2U
#define PER_SW2_ADDRESS    0xBAU

/* register */
sfr AUXR  =          AUXR_ADDRESS;
sfr AUXR2 =         AUXR2_ADDRESS;
sfr P_SW1 =       PER_SW1_ADDRESS;
sfr P_SW2 =       PER_SW2_ADDRESS;

#define EAXFR_ENABLE()  P_SW2 |= 0x80
#define EAXFR_DISABLE() P_SW2 &= 0x7F

/*--------------------------------------------------------
| @Description: System clock IO register structure       |
--------------------------------------------------------*/

typedef struct
{
    __IO uint8_t CKSEL_REG;    /*----Clock selection register */

    __IO uint8_t CLKDIV_REG;   /*----Clock frequency division register */
	
    __IO uint8_t HIRCCR_REG;   /*----High internal 24MHz oscillator control register */	
	
    __IO uint8_t XOSCCR_REG;   /*----External oscillator control register */
	
    __IO uint8_t IRC32KCR_REG; /*----Internal 32KHz oscillator control register */

    __IO uint8_t MCLKOCR_REG;  /*----Master clock output control register */ 

    __IO uint8_t X32KCR_REG;   /*----External 32KHz oscillator control register */

}   SYSCLK_TypeDef;


/*--------------------------------------------------------
| @Description: System clock peripherals                 |
--------------------------------------------------------*/

#define IRCBAND_ADDRESS   0x9DU
#define LIRTRIM_ADDRESS   0x9EU
#define IRTRIM_ADDRESS    0x9FU


/* System clock base address in the 
internal expansion RAM area */
#define    SYSCLK_BASE    0xFE00U  

#define    CKSEL_ADDRESS      (SYSCLK_BASE + 0x0000U)
#define    CLKDIV_ADDRESS     (SYSCLK_BASE + 0x0001U)
#define    HIRCCR_ADDRESS     (SYSCLK_BASE + 0x0002U)
#define    XOSCCR_ADDRESS     (SYSCLK_BASE + 0x0003U)
#define    IRC32KCR_ADDRESS   (SYSCLK_BASE + 0x0004U)
#define    MCLKOCR_ADDRESS    (SYSCLK_BASE + 0x0005U)
#define    X32KCR_ADDRESS     (SYSCLK_BASE + 0x0006U)
/* Define type of SYSCLK */

#define    SYSCLK     (* (SYSCLK_TypeDef  xdata *) SYSCLK_BASE)

/* SYSCLIL register */

#define    CKSEL       ( *(__IO uint8_t xdata *)    CKSEL_ADDRESS)
#define    CLKDIV      ( *(__IO uint8_t xdata *)   CLKDIV_ADDRESS)
#define    IRC24MCR    ( *(__IO uint8_t xdata *)   HIRCCR_ADDRESS)
#define    XOSCCR      ( *(__IO uint8_t xdata *)   XOSCCR_ADDRESS)
#define    IRC32KCR    ( *(__IO uint8_t xdata *) IRC32KCR_ADDRESS)
#define    MCLKOCR     ( *(__IO uint8_t xdata *)  MCLKOCR_ADDRESS)
#define    X32KCR      ( *(__IO uint8_t xdata *)   X32KCR_ADDRESS)

/* IRC frequency adjustment register */

sfr IRCBAND     =   IRCBAND_ADDRESS;
sfr IRTRIM      =   IRTRIM_ADDRESS;
sfr LIRTRIM     =   LIRTRIM_ADDRESS;

#define IRC_22_1184M  (*(__I uint8_t idata *)0xFA)
#define IRC_24M       (*(__I uint8_t idata *)0xFB)

/*--------------------------------------------------------
| @Description: Power peripherals                        |
--------------------------------------------------------*/

/* Power base address */
#define    PCON_ADDRESS      0x87U
#define    VOCTRL_ADDRESS    0xBBU

/* Power register */
sfr PCON = PCON_ADDRESS;
sfr VOCTRL = VOCTRL_ADDRESS;

/*--------------------------------------------------------
| @Description: ISR peripherals                          |
--------------------------------------------------------*/

/* ISR base address */
#define    IE_ADDRESS            0xA8U
#define    IE2_ADDRESS           0xAFU
#define    IP_ADDRESS            0xB8U
#define    IPH_ADDRESS           0xB7U
#define    IP2_ADDRESS           0xB5U
#define    IP2H_ADDRESS          0xB6U
#define    IP3_ADDRESS           0xDFU
#define    IP3H_ADDRESS          0xEEU
#define    INTCLKO_ADDRESS       0x8FU
#define    AUXINTIF_ADDRESS      0xEFU
#define    INTE_GPIO_ADDRESS   0xFD00U
#define    INTF_GPIO_ADDRESS   0xFD10U

/* GPIO */

#define P0INTE_ADDRESS              INTE_GPIO_ADDRESS
#define P1INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0001U)
#define P2INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0002U)
#define P3INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0003U)
#define P4INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0004U)
#define P5INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0005U)
#define P6INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0006U)
#define P7INTE_ADDRESS  (INTE_GPIO_ADDRESS + 0x0007U)

#define P0INTF_ADDRESS              INTF_GPIO_ADDRESS
#define P1INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0001U)
#define P2INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0002U)
#define P3INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0003U)
#define P4INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0004U)
#define P5INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0005U)
#define P6INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0006U)
#define P7INTF_ADDRESS  (INTF_GPIO_ADDRESS + 0x0007U)

/* ISR register */
sfr IE   =   IE_ADDRESS;
sfr IE2  =  IE2_ADDRESS;
sfr IP   =   IP_ADDRESS;
sfr IPH  =  IPH_ADDRESS;
sfr IP2  = IP2H_ADDRESS;
sfr IP2H = IP2H_ADDRESS;
sfr IP3  =  IP3_ADDRESS;
sfr IP3H = IP3H_ADDRESS;
sfr INTCLKO  =  INTCLKO_ADDRESS;
sfr AUXINTIF = AUXINTIF_ADDRESS;

sbit EA   = IE^7;
sbit ELVD = IE^6;
sbit EADC = IE^5;
sbit ES   = IE^4;
sbit ET1  = IE^3;
sbit EX1  = IE^2;
sbit ET0  = IE^1;
sbit EX0  = IE^0;

sbit PPCA = IP^7;
sbit PLVD = IP^6;
sbit PADC = IP^5;
sbit PS   = IP^4;
sbit PT1  = IP^3;
sbit PX1  = IP^2;
sbit PT0  = IP^1;
sbit PX0  = IP^0;

#define    P0INTE    ( *(__IO uint8_t xdata *)   P0INTE_ADDRESS)
#define    P1INTE    ( *(__IO uint8_t xdata *)   P1INTE_ADDRESS)
#define    P2INTE    ( *(__IO uint8_t xdata *)   P2INTE_ADDRESS)
#define    P3INTE    ( *(__IO uint8_t xdata *)   P3INTE_ADDRESS)
#define    P4INTE    ( *(__IO uint8_t xdata *)   P4INTE_ADDRESS)
#define    P5INTE    ( *(__IO uint8_t xdata *)   P5INTE_ADDRESS)

#define    P0INTF    ( *(__IO uint8_t xdata *)   P0INTF_ADDRESS)
#define    P1INTF    ( *(__IO uint8_t xdata *)   P1INTF_ADDRESS)
#define    P2INTF    ( *(__IO uint8_t xdata *)   P2INTF_ADDRESS)
#define    P3INTF    ( *(__IO uint8_t xdata *)   P3INTF_ADDRESS)
#define    P4INTF    ( *(__IO uint8_t xdata *)   P4INTF_ADDRESS)
#define    P5INTF    ( *(__IO uint8_t xdata *)   P5INTF_ADDRESS)

/*--------------------------------------------------------
| @Description: GPIO peripherals                         |
--------------------------------------------------------*/

/* Base address define */
#define    GPIO_BASE       0x80U
#define    PxM1_BASE       0x93U
#define    PxM0_BASE       0x94U
#define BUS_SPEED_ADDRESS  0xA1U

/* There are internal extended 
ram areas below */
#define    PxPU_BASE     0xFE10U
#define    PxNCS_BASE    0xFE18U
#define    PxSR_BASE     0xFE20U
#define    PxDR_BASE     0xFE28U
#define    PxIE_BASE     0xFE30U

/* GPIO address define */
#define    P0_ADDRESS  GPIO_BASE 
#define    P1_ADDRESS      0x90U 
#define    P2_ADDRESS      0xA0U
#define    P3_ADDRESS      0xB0U 
#define    P4_ADDRESS      0xC0U
#define    P5_ADDRESS      0xC8U 
#define    P6_ADDRESS      0xE8U 
#define    P7_ADDRESS      0xF8U 

/*PxMx address define*/
#define    P0M1_ADDRESS  PxM1_BASE
#define    P1M1_ADDRESS      0x91U
#define    P2M1_ADDRESS      0x95U
#define    P3M1_ADDRESS      0xB1U
#define    P4M1_ADDRESS      0xB3U
#define    P5M1_ADDRESS      0xC9U
#define    P6M1_ADDRESS      0xCBU
#define    P7M1_ADDRESS      0xE1U
				 							    
#define    P0M0_ADDRESS  PxM0_BASE
#define    P1M0_ADDRESS      0x92U
#define    P2M0_ADDRESS      0x96U
#define    P3M0_ADDRESS      0xB2U
#define    P4M0_ADDRESS      0xB4U
#define    P5M0_ADDRESS      0xCAU
#define    P6M0_ADDRESS      0xCCU
#define    P7M0_ADDRESS      0xE2U

/*GPIO pull up address */
#define    P0PU_ADDRESS    (PxPU_BASE + 0x00U)
#define    P1PU_ADDRESS    (PxPU_BASE + 0x01U)
#define    P2PU_ADDRESS    (PxPU_BASE + 0x02U)
#define    P3PU_ADDRESS    (PxPU_BASE + 0x03U)
#define    P4PU_ADDRESS    (PxPU_BASE + 0x04U)
#define    P5PU_ADDRESS    (PxPU_BASE + 0x05U)
#define    P6PU_ADDRESS    (PxPU_BASE + 0x06U)
#define    P7PU_ADDRESS    (PxPU_BASE + 0x07U)

/*GPIO schmidt trigger address */

#define    P0NCS_ADDRESS   (PxNCS_BASE + 0x00U)
#define    P1NCS_ADDRESS   (PxNCS_BASE + 0x01U)
#define    P2NCS_ADDRESS   (PxNCS_BASE + 0x02U)
#define    P3NCS_ADDRESS   (PxNCS_BASE + 0x03U)
#define    P4NCS_ADDRESS   (PxNCS_BASE + 0x04U)
#define    P5NCS_ADDRESS   (PxNCS_BASE + 0x05U)
#define    P6NCS_ADDRESS   (PxNCS_BASE + 0x06U)
#define    P7NCS_ADDRESS   (PxNCS_BASE + 0x07U)

/* GPIO level conversion address */

#define    P0SR_ADDRESS    (PxSR_BASE + 0x00U)
#define    P1SR_ADDRESS    (PxSR_BASE + 0x01U)
#define    P2SR_ADDRESS    (PxSR_BASE + 0x02U)
#define    P3SR_ADDRESS    (PxSR_BASE + 0x03U)
#define    P4SR_ADDRESS    (PxSR_BASE + 0x04U)
#define    P5SR_ADDRESS    (PxSR_BASE + 0x05U)
#define    P6SR_ADDRESS    (PxSR_BASE + 0x06U)
#define    P7SR_ADDRESS    (PxSR_BASE + 0x07U)

/* GPIO drive current address */

#define    P0DR_ADDRESS    (PxDR_BASE + 0x00U)
#define    P1DR_ADDRESS    (PxDR_BASE + 0x01U)
#define    P2DR_ADDRESS    (PxDR_BASE + 0x02U)
#define    P3DR_ADDRESS    (PxDR_BASE + 0x03U)
#define    P4DR_ADDRESS    (PxDR_BASE + 0x04U)
#define    P5DR_ADDRESS    (PxDR_BASE + 0x05U)
#define    P6DR_ADDRESS    (PxDR_BASE + 0x06U)
#define    P7DR_ADDRESS    (PxDR_BASE + 0x07U)

/* GPIO intput enable address*/
#define    P0IE_ADDRESS    (PxIE_BASE + 0x00U)
#define    P1IE_ADDRESS    (PxIE_BASE + 0x01U)
#define    P3IE_ADDRESS    (PxIE_BASE + 0x03U)

/* GPIO register */
sfr P0 = P0_ADDRESS;
sfr P1 = P1_ADDRESS;
sfr P2 = P2_ADDRESS;
sfr P3 = P3_ADDRESS;
sfr P4 = P4_ADDRESS;
sfr P5 = P5_ADDRESS;
sfr P6 = P6_ADDRESS;
sfr P7 = P7_ADDRESS;

/* GPIO register */
sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;
sbit P07 = P0^7;

/* Pin register */
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;
						
sbit P20 = P2^0;
sbit P21 = P2^1;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;
sbit P25 = P2^5;
sbit P26 = P2^6;
sbit P27 = P2^7;
					 
sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;
						
sbit P40 = P4^0;
sbit P41 = P4^1;
sbit P42 = P4^2;
sbit P43 = P4^3;
sbit P44 = P4^4;
						
sbit P50 = P5^0;
sbit P51 = P5^1;
sbit P52 = P5^2;
sbit P53 = P5^3;
sbit P54 = P5^4;
sbit P55 = P5^5;
sbit P56 = P5^6;
sbit P57 = P5^7;

sbit P60 = P6^0;
sbit P61 = P6^1;
sbit P62 = P6^2;
sbit P63 = P6^3;
sbit P64 = P6^4;
sbit P65 = P6^5;
sbit P66 = P6^6;
sbit P67 = P6^7;
						
sbit P70 = P7^0;
sbit P71 = P7^1;
sbit P72 = P7^2;
sbit P73 = P7^3;
sbit P74 = P7^4;
sbit P75 = P7^5;
sbit P76 = P7^6;
sbit P77 = P7^7;

/* GPIO mode register  */
sfr P0M1 = P0M1_ADDRESS;
sfr P1M1 = P1M1_ADDRESS;
sfr P2M1 = P2M1_ADDRESS;
sfr P3M1 = P3M1_ADDRESS;
sfr P4M1 = P4M1_ADDRESS;
sfr P5M1 = P5M1_ADDRESS;
sfr P6M1 = P6M1_ADDRESS;
sfr P7M1 = P7M1_ADDRESS;

/* GPIO mode register  */
sfr P0M0 = P0M0_ADDRESS;
sfr P1M0 = P1M0_ADDRESS;
sfr P2M0 = P2M0_ADDRESS;
sfr P3M0 = P3M0_ADDRESS;
sfr P4M0 = P4M0_ADDRESS;
sfr P5M0 = P5M0_ADDRESS;
sfr P6M0 = P6M0_ADDRESS;
sfr P7M0 = P7M0_ADDRESS;

/* Bus speed control register  */
sfr BUS_SPEED = BUS_SPEED_ADDRESS;

/* GPIO Driver register */

#define    P0PU    ( *(__IO uint8_t xdata *) P0PU_ADDRESS)
#define    P1PU    ( *(__IO uint8_t xdata *) P1PU_ADDRESS)
#define    P2PU    ( *(__IO uint8_t xdata *) P2PU_ADDRESS)
#define    P3PU    ( *(__IO uint8_t xdata *) P3PU_ADDRESS)
#define    P4PU    ( *(__IO uint8_t xdata *) P4PU_ADDRESS)
#define    P5PU    ( *(__IO uint8_t xdata *) P5PU_ADDRESS)
#define    P6PU    ( *(__IO uint8_t xdata *) P6PU_ADDRESS)
#define    P7PU    ( *(__IO uint8_t xdata *) P7PU_ADDRESS)
								   
#define    P0SR    ( *(__IO uint8_t xdata *) P0SR_ADDRESS)
#define    P1SR    ( *(__IO uint8_t xdata *) P1SR_ADDRESS)
#define    P2SR    ( *(__IO uint8_t xdata *) P2SR_ADDRESS)
#define    P3SR    ( *(__IO uint8_t xdata *) P3SR_ADDRESS)
#define    P4SR    ( *(__IO uint8_t xdata *) P4SR_ADDRESS)
#define    P5SR    ( *(__IO uint8_t xdata *) P5SR_ADDRESS)
#define    P6SR    ( *(__IO uint8_t xdata *) P6SR_ADDRESS)
#define    P7SR    ( *(__IO uint8_t xdata *) P7SR_ADDRESS)
								   
#define    P0DR    ( *(__IO uint8_t xdata *) P0DR_ADDRESS)
#define    P1DR    ( *(__IO uint8_t xdata *) P1DR_ADDRESS)
#define    P2DR    ( *(__IO uint8_t xdata *) P2DR_ADDRESS)
#define    P3DR    ( *(__IO uint8_t xdata *) P3DR_ADDRESS)
#define    P4DR    ( *(__IO uint8_t xdata *) P4DR_ADDRESS)
#define    P5DR    ( *(__IO uint8_t xdata *) P5DR_ADDRESS)
#define    P6DR    ( *(__IO uint8_t xdata *) P6DR_ADDRESS)
#define    P7DR    ( *(__IO uint8_t xdata *) P7DR_ADDRESS)
								   
#define    P0IE    ( *(__IO uint8_t xdata *) P0IE_ADDRESS)
#define    P1IE    ( *(__IO uint8_t xdata *) P1IE_ADDRESS)
#define    P3IE    ( *(__IO uint8_t xdata *) P3IE_ADDRESS)
//#define  P2IE    ( *(__IO uint8_t xdata *) P2IE_ADDRESS)
//#define  P4IE    ( *(__IO uint8_t xdata *) P4IE_ADDRESS)
//#define  P5IE    ( *(__IO uint8_t xdata *) P5IE_ADDRESS)
//#define  P6IE    ( *(__IO uint8_t xdata *) P6IE_ADDRESS)
//#define  P7IE    ( *(__IO uint8_t xdata *) P7IE_ADDRESS)
								   
#define    P0NCS  ( *(__IO uint8_t xdata *) P0NCS_ADDRESS)
#define    P1NCS  ( *(__IO uint8_t xdata *) P1NCS_ADDRESS)
#define    P2NCS  ( *(__IO uint8_t xdata *) P2NCS_ADDRESS)
#define    P3NCS  ( *(__IO uint8_t xdata *) P3NCS_ADDRESS)
#define    P4NCS  ( *(__IO uint8_t xdata *) P4NCS_ADDRESS)
#define    P5NCS  ( *(__IO uint8_t xdata *) P5NCS_ADDRESS)
#define    P6NCS  ( *(__IO uint8_t xdata *) P6NCS_ADDRESS)
#define    P7NCS  ( *(__IO uint8_t xdata *) P7NCS_ADDRESS)

#define GPIO_Px(x)  (P##x)
#define Px_M1(x) 	(P##x##M1)  // GPIO_P0M1 GPIO_P0M0
#define Px_M0(x) 	(P##x##M0)  // P0M1 P0M0
#define Px_PU(x)    (P##x##PU)
#define Px_SR(x)    (P##x##SR)
#define Px_DR(x)    (P##x##DR)
#define Px_IE(x)    (P##x##IE)
#define Px_NCS(x)   (P##x##NCS)

/*--------------------------------------------------------
| @Description: WDT peripherals                          |
--------------------------------------------------------*/

/* Base address define */

#define   WDT_ADDRESS      0xC1U
#define   RSTCFG_ADDRESS   0xFFU

/* WDT register */
sfr   WDT_CONTR = WDT_ADDRESS;
//sfr IAP_CONTR = IAR_ADDRESS;
sfr   RSTCFG = RSTCFG_ADDRESS;

/*--------------------------------------------------------
| @Description: TIMER peripherals                        |
--------------------------------------------------------*/

/* Base address define */
#define   TCON_ADDRESS    0x88U
#define   TMOD_ADDRESS    0x89U
#define   T0L_ADDRESS     0x8AU
#define   T1L_ADDRESS     0x8BU
#define   T0H_ADDRESS     0x8CU
#define   T1H_ADDRESS     0x8DU
#define   T4T3M_ADDRESS   0xD1U
#define   T4H_ADDRESS     0xD2U
#define   T4L_ADDRESS     0xD3U
#define   T3H_ADDRESS     0xD4U
#define   T3L_ADDRESS     0xD5U
#define   T2H_ADDRESS     0xD6U
#define   T2L_ADDRESS     0xD7U
#define   WKTCL_ADDRESS   0xAAU
#define   WKTCH_ADDRESS   0xABU

#define   TM2PS_ADDRESS   0xFEA2U
#define   TM3PS_ADDRESS   0xFEA3U
#define   TM4PS_ADDRESS   0xFEA4U

/* TMOD */
#define T1_GATE     0x80
#define T1_CT       0x40
#define T1_M1       0x20
#define T1_M0       0x10
#define T0_GATE     0x08
#define T0_CT       0x04
#define T0_M1       0x02
#define T0_M0       0x01

/* T4T3 */
#define T4R         0x80
#define T4_CT       0x40
#define T4x12       0x20
#define T4CLKO      0x10
#define T3R         0x08
#define T3_CT       0x04
#define T3x12       0x02
#define T3CLKO      0x01

/* WKTCH */
#define WKTEN       0x80

/* WDT_CONTR */
#define WDT_FLAG    0x80
#define EN_WDT      0x20
#define CLR_WDT     0x10
#define IDL_WDT     0x08

/* TIMER register */
sfr TCON  =  TCON_ADDRESS;
sfr TMOD  =  TMOD_ADDRESS;
sfr T0L   =   T0L_ADDRESS;
sfr T1L   =   T1L_ADDRESS;
sfr T0H   =   T0H_ADDRESS;
sfr T1H   =   T1H_ADDRESS;
sfr TL0   =   T0L_ADDRESS;
sfr TL1   =   T1L_ADDRESS;
sfr TH0   =   T0H_ADDRESS;
sfr TH1   =   T1H_ADDRESS;
sfr T4T3M = T4T3M_ADDRESS;
sfr T4H   =   T4H_ADDRESS;
sfr T4L   =   T4L_ADDRESS;
sfr T3H   =   T3H_ADDRESS;
sfr T3L   =   T3L_ADDRESS;
sfr T2H   =   T2H_ADDRESS;
sfr T2L   =   T2L_ADDRESS;
sfr WKTCL = WKTCL_ADDRESS;
sfr WKTCH = WKTCH_ADDRESS;

sbit TF1  =  TCON^7;
sbit TR1  =  TCON^6;
sbit TF0  =  TCON^5;
sbit TR0  =  TCON^4;
sbit IE1  =  TCON^3;
sbit IE0  =  TCON^1;

#define TM2PS    (*(__IO uint8_t xdata *)TM2PS_ADDRESS)
#define TM3PS    (*(__IO uint8_t xdata *)TM3PS_ADDRESS)
#define TM4PS    (*(__IO uint8_t xdata *)TM4PS_ADDRESS)

/* Clock frequency address of timer5 */

#define FWTH    (*(__I uint8_t idata *)0xF8)
#define FWTL    (*(__I uint8_t idata *)0xF9)

/*--------------------------------------------------------
| @Description: EXTI peripherals                         |
--------------------------------------------------------*/

/* EXTI register */
sbit IT0   =   TCON^0;
sbit IT1   =   TCON^2;

/*--------------------------------------------------------
| @Description: UART peripherals                         |
--------------------------------------------------------*/

/* Base address define */

#define    SCON_ADDRESS    0x98U
#define    SBUF_ADDRESS    0x99U
#define    S2CON_ADDRESS   0x9AU
#define    S2BUF_ADDRESS   0x9BU
#define    S3CON_ADDRESS   0xACU
#define    S3BUF_ADDRESS   0xADU
#define    S4CON_ADDRESS   0x84U
#define    S4BUF_ADDRESS   0x85U
#define    SADDR_ADDRESS   0xA9U
#define    SADEN_ADDRESS   0xB9U

/* S2CON */
#define S2SM0       0x80
#define S2ST4       0x40
#define S2SM2       0x20
#define S2REN       0x10
#define S2TB8       0x08
#define S2RB8       0x04
#define S2TI        0x02
#define S2RI        0x01

/* S3CON */
#define S3SM0       0x80
#define S3ST4       0x40
#define S3SM2       0x20
#define S3REN       0x10
#define S3TB8       0x08
#define S3RB8       0x04
#define S3TI        0x02
#define S3RI        0x01

/* S4CON */
#define S4SM0       0x80
#define S4ST4       0x40
#define S4SM2       0x20
#define S4REN       0x10
#define S4TB8       0x08
#define S4RB8       0x04
#define S4TI        0x02
#define S4RI        0x01

/* UART register */

sfr SCON  =  SCON_ADDRESS;
sfr SBUF  =  SBUF_ADDRESS; 
sfr S2CON = S2CON_ADDRESS;
sfr S2BUF = S2BUF_ADDRESS;
sfr S3CON = S3CON_ADDRESS;
sfr S3BUF = S3BUF_ADDRESS;
sfr S4CON = S4CON_ADDRESS;
sfr S4BUF = S4BUF_ADDRESS;
sfr SADDR = SADDR_ADDRESS;
sfr SADEN = SADEN_ADDRESS;

sbit SM0  =   SCON^7;
sbit SM1  =   SCON^6;
sbit SM2  =   SCON^5;
sbit REN  =   SCON^4;
sbit TB8  =   SCON^3;
sbit RB8  =   SCON^2;
sbit TI   =   SCON^1;
sbit RI   =   SCON^0;

/*--------------------------------------------------------
| @Description: COMP peripherals                         |
--------------------------------------------------------*/

/* Base address define */
#define    CMPCR1_ADDRESS    0xE6U
#define    CMPCR2_ADDRESS    0xE7U

/* CMPCR1 */
#define CMPEN       0x80
#define CMPIF       0x40
#define PIE         0x20
#define NIE         0x10
#define PIS         0x08
#define NIS         0x04
#define CMPOE       0x02
#define CMPRES      0x01

/* CMPAR2 */
#define INVCMPO     0x80
#define DISFLT      0x40

/* COMP register */
sfr CMPCR1 = CMPCR1_ADDRESS;
sfr CMPCR2 = CMPCR2_ADDRESS;

/*--------------------------------------------------------
| @Description: ADC peripherals                          |
--------------------------------------------------------*/

/* Base address define */
#define    ADC_CONTR_ADDRESS    0xBCU
#define    ADC_RES_ADDRESS      0xBDU
#define    ADC_RESH_ADDRESS     0xBDU
#define    ADC_RESL_ADDRESS     0xBEU
#define    ADCCFG_ADDRESS       0xDEU
#define    ADCTIM_ADDRESS     0xFEA8U
/* ADC_CONTR */
#define ADC_POWER   0x80
#define ADC_START   0x40
#define ADC_FLAG    0x20

/* ADCCFG */
#define ADC_RESFMT  0x20


/* ADC register */
sfr ADC_CONTR  = ADC_CONTR_ADDRESS;
sfr ADC_RES    =  ADC_RESH_ADDRESS;
sfr ADC_RESL   =  ADC_RESL_ADDRESS;
sfr ADCCFG     =    ADCCFG_ADDRESS;

#define ADCTIM    (*(__IO uint8_t xdata *)ADCTIM_ADDRESS)

/*--------------------------------------------------------
| @Description: EEPROM peripherals                       |
--------------------------------------------------------*/

/*  Base address define */
#define    IAP_DATA_ADDRESS    0xC2U
#define    IAP_ADDRH_ADDRESS   0xC3U
#define    IAP_ADDRL_ADDRESS   0xC4U
#define    IAP_CMD_ADDRESS     0xC5U
#define    IAP_TRIG_ADDRESS    0xC6U
#define    IAP_CONTR_ADDRESS   0xC7U
#define    IAP_TPS_ADDRESS     0xF5U

#define    ISP_DATA_ADDRESS    0xC2U
#define    ISP_ADDRH_ADDRESS   0xC3U
#define    ISP_ADDRL_ADDRESS   0xC4U
#define    ISP_CMD_ADDRESS     0xC5U
#define    ISP_TRIG_ADDRESS    0xC6U
#define    ISP_CONTR_ADDRESS   0xC7U

/* IAP_CMD */
#define IAP_IDL     0x00
#define IAP_READ    0x01
#define IAP_WRITE   0x02
#define IAP_ERASE   0x03

/* IAP_CONTR */
#define IAPEN       0x80
#define SWBS        0x40
#define SWRST       0x20
#define CMD_FAIL    0x10

/* EEPROM register */
sfr IAP_DATA    =   IAP_DATA_ADDRESS;
sfr IAP_ADDRH   =   IAP_ADDRH_ADDRESS;
sfr IAP_ADDRL   =   IAP_ADDRL_ADDRESS;
sfr IAP_CMD     =   IAP_CMD_ADDRESS;
sfr IAP_TRIG    =   IAP_TRIG_ADDRESS;
sfr IAP_CONTR   =   IAP_CONTR_ADDRESS;
sfr IAP_TPS     =   IAP_TPS_ADDRESS;

sfr ISP_DATA    =   ISP_DATA_ADDRESS;
sfr ISP_ADDRH   =   ISP_ADDRH_ADDRESS;
sfr ISP_ADDRL   =   ISP_ADDRL_ADDRESS;
sfr ISP_CMD     =   ISP_CMD_ADDRESS;
sfr ISP_TRIG    =   ISP_TRIG_ADDRESS;
sfr ISP_CONTR   =   ISP_CONTR_ADDRESS;

/*--------------------------------------------------------
| @Description: HPWM peripherals                         |
--------------------------------------------------------*/

/*  Base address define */
#define    PWMCFG_ADDRESS    0xF1U
#define    PWMIF_ADDRESS     0xF6U
#define    PWMFDCR_ADDRESS   0xF7U
#define    PWMCR_ADDRESS     0xFEU

#define    PWM_BASE1       0xFFF0U
#define    PWM0_BASE       0xFF00U
#define    PWM1_BASE       0xFF10U
#define    PWM2_BASE       0xFF20U
#define    PWM3_BASE       0xFF30U
#define    PWM4_BASE       0xFF40U
#define    PWM5_BASE       0xFF50U
#define    PWM6_BASE       0xFF60U
#define    PWM7_BASE       0xFF70U

#define    PWMC_ADDRESS    (PWM_BASE1 + 0x00U)
#define    PWMCH_ADDRESS   (PWMC_ADDRESS +  0x00U)
#define    PWMCL_ADDRESS   (PWMCH_ADDRESS + 0x01U)
#define    PWMCKS_ADDRESS  (PWMCL_ADDRESS + 0x01U)

#define    TADCP_ADDRESS   (PWMCKS_ADDRESS + 0x01U)
#define    TADCPH_ADDRESS  (TADCP_ADDRESS +  0x00U)
#define    TADCPL_ADDRESS  (PWMCL_ADDRESS +  0x01U)

#define    PWM0T1_ADDRESS   (PWM0_BASE + 0x00U)
#define    PWM0T1H_ADDRESS  (PWM0T1_ADDRESS +  0x00U)
#define    PWM0T1L_ADDRESS  (PWM0T1H_ADDRESS + 0x01U)
#define    PWM0T2_ADDRESS   (PWM0T1L_ADDRESS + 0x01U)
#define    PWM0T2H_ADDRESS  (PWM0T2_ADDRESS +  0x00U)
#define    PWM0T2L_ADDRESS  (PWM0T2H_ADDRESS + 0x01U)
#define    PWM0CR_ADDRESS   (PWM0T2L_ADDRESS + 0x01U)
#define    PWM0HLD_ADDRESS  (PWM0CR_ADDRESS +  0x01U)

#define    PWM1T1_ADDRESS   (PWM1_BASE + 0x00U)
#define    PWM1T1H_ADDRESS  (PWM1T1_ADDRESS +  0x00U)
#define    PWM1T1L_ADDRESS  (PWM1T1H_ADDRESS + 0x01U)
#define    PWM1T2_ADDRESS   (PWM1T1L_ADDRESS + 0x01U)
#define    PWM1T2H_ADDRESS  (PWM1T2_ADDRESS +  0x00U)
#define    PWM1T2L_ADDRESS  (PWM1T2H_ADDRESS + 0x01U)
#define    PWM1CR_ADDRESS   (PWM1T2L_ADDRESS + 0x01U)
#define    PWM1HLD_ADDRESS  (PWM1CR_ADDRESS +  0x01U)

#define    PWM2T1_ADDRESS   (PWM2_BASE + 0x00U)
#define    PWM2T1H_ADDRESS  (PWM2T1_ADDRESS +  0x00U)
#define    PWM2T1L_ADDRESS  (PWM2T1H_ADDRESS + 0x01U)
#define    PWM2T2_ADDRESS   (PWM2T1L_ADDRESS + 0x01U)
#define    PWM2T2H_ADDRESS  (PWM2T2_ADDRESS +  0x00U)
#define    PWM2T2L_ADDRESS  (PWM2T2H_ADDRESS + 0x01U)
#define    PWM2CR_ADDRESS   (PWM2T2L_ADDRESS + 0x01U)
#define    PWM2HLD_ADDRESS  (PWM2CR_ADDRESS +  0x01U)

#define    PWM3T1_ADDRESS   (PWM3_BASE + 0x00U)
#define    PWM3T1H_ADDRESS  (PWM3T1_ADDRESS +  0x00U)
#define    PWM3T1L_ADDRESS  (PWM3T1H_ADDRESS + 0x01U)
#define    PWM3T2_ADDRESS   (PWM3T1L_ADDRESS + 0x01U)
#define    PWM3T2H_ADDRESS  (PWM3T2_ADDRESS +  0x00U)
#define    PWM3T2L_ADDRESS  (PWM3T2H_ADDRESS + 0x01U)
#define    PWM3CR_ADDRESS   (PWM3T2L_ADDRESS + 0x01U)
#define    PWM3HLD_ADDRESS  (PWM3CR_ADDRESS +  0x01U)

#define    PWM4T1_ADDRESS   (PWM4_BASE + 0x00U)
#define    PWM4T1H_ADDRESS  (PWM4T1_ADDRESS +  0x00U)
#define    PWM4T1L_ADDRESS  (PWM4T1H_ADDRESS + 0x01U)
#define    PWM4T2_ADDRESS   (PWM4T1L_ADDRESS + 0x01U)
#define    PWM4T2H_ADDRESS  (PWM4T2_ADDRESS +  0x00U)
#define    PWM4T2L_ADDRESS  (PWM4T2H_ADDRESS + 0x01U)
#define    PWM4CR_ADDRESS   (PWM4T2L_ADDRESS + 0x01U)
#define    PWM4HLD_ADDRESS  (PWM4CR_ADDRESS +  0x01U)

#define    PWM5T1_ADDRESS   (PWM5_BASE + 0x00U)
#define    PWM5T1H_ADDRESS  (PWM5T1_ADDRESS +  0x00U)
#define    PWM5T1L_ADDRESS  (PWM5T1H_ADDRESS + 0x01U)
#define    PWM5T2_ADDRESS   (PWM5T1L_ADDRESS + 0x01U)
#define    PWM5T2H_ADDRESS  (PWM5T2_ADDRESS +  0x00U)
#define    PWM5T2L_ADDRESS  (PWM5T2H_ADDRESS + 0x01U)
#define    PWM5CR_ADDRESS   (PWM5T2L_ADDRESS + 0x01U)
#define    PWM5HLD_ADDRESS  (PWM5CR_ADDRESS +  0x01U)

#define    PWM6T1_ADDRESS   (PWM6_BASE + 0x00U)
#define    PWM6T1H_ADDRESS  (PWM6T1_ADDRESS +  0x00U)
#define    PWM6T1L_ADDRESS  (PWM6T1H_ADDRESS + 0x01U)
#define    PWM6T2_ADDRESS   (PWM6T1L_ADDRESS + 0x01U)
#define    PWM6T2H_ADDRESS  (PWM6T2_ADDRESS +  0x00U)
#define    PWM6T2L_ADDRESS  (PWM6T2H_ADDRESS + 0x01U)
#define    PWM6CR_ADDRESS   (PWM6T2L_ADDRESS + 0x01U)
#define    PWM6HLD_ADDRESS  (PWM6CR_ADDRESS +  0x01U)

#define    PWM7T1_ADDRESS   (PWM7_BASE + 0x00U)
#define    PWM7T1H_ADDRESS  (PWM7T1_ADDRESS +  0x00U)
#define    PWM7T1L_ADDRESS  (PWM7T1H_ADDRESS + 0x01U)
#define    PWM7T2_ADDRESS   (PWM7T1L_ADDRESS + 0x01U)
#define    PWM7T2H_ADDRESS  (PWM7T2_ADDRESS +  0x00U)
#define    PWM7T2L_ADDRESS  (PWM7T2H_ADDRESS + 0x01U)
#define    PWM7CR_ADDRESS   (PWM7T2L_ADDRESS + 0x01U)
#define    PWM7HLD_ADDRESS  (PWM7CR_ADDRESS +  0x01U)



#define     PWM1_ETRPS  (*(unsigned char volatile xdata *)0xfeb0)
#define     PWM1_ENO    (*(unsigned char volatile xdata *)0xfeb1)
#define     PWM1_PS     (*(unsigned char volatile xdata *)0xfeb2)
#define     PWM1_IOAUX  (*(unsigned char volatile xdata *)0xfeb3)
#define     PWM2_ETRPS  (*(unsigned char volatile xdata *)0xfeb4)
#define     PWM2_ENO    (*(unsigned char volatile xdata *)0xfeb5)
#define     PWM2_PS     (*(unsigned char volatile xdata *)0xfeb6)
#define     PWM2_IOAUX  (*(unsigned char volatile xdata *)0xfeb7)
#define     PWM1_CR1    (*(unsigned char volatile xdata *)0xfec0)
#define     PWM1_CR2    (*(unsigned char volatile xdata *)0xfec1)
#define     PWM1_SMCR   (*(unsigned char volatile xdata *)0xfec2)
#define     PWM1_ETR    (*(unsigned char volatile xdata *)0xfec3)
#define     PWM1_IER    (*(unsigned char volatile xdata *)0xfec4)
#define     PWM1_SR1    (*(unsigned char volatile xdata *)0xfec5)
#define     PWM1_SR2    (*(unsigned char volatile xdata *)0xfec6)
#define     PWM1_EGR    (*(unsigned char volatile xdata *)0xfec7)
#define     PWM1_CCMR1  (*(unsigned char volatile xdata *)0xfec8)
#define     PWM1_CCMR2  (*(unsigned char volatile xdata *)0xfec9)
#define     PWM1_CCMR3  (*(unsigned char volatile xdata *)0xfeca)
#define     PWM1_CCMR4  (*(unsigned char volatile xdata *)0xfecb)
#define     PWM1_CCER1  (*(unsigned char volatile xdata *)0xfecc)
#define     PWM1_CCER2  (*(unsigned char volatile xdata *)0xfecd)
#define     PWM1_CNTR   (*(unsigned  int volatile xdata *)0xfece)
#define     PWM1_CNTRH  (*(unsigned char volatile xdata *)0xfece)
#define     PWM1_CNTRL  (*(unsigned char volatile xdata *)0xfecf)
#define     PWM1_PSCR   (*(unsigned  int volatile xdata *)0xfed0)
#define     PWM1_PSCRH  (*(unsigned char volatile xdata *)0xfed0)
#define     PWM1_PSCRL  (*(unsigned char volatile xdata *)0xfed1)
#define     PWM1_ARR    (*(unsigned  int volatile xdata *)0xfed2)
#define     PWM1_ARRH   (*(unsigned char volatile xdata *)0xfed2)
#define     PWM1_ARRL   (*(unsigned char volatile xdata *)0xfed3)
#define     PWM1_RCR    (*(unsigned char volatile xdata *)0xfed4)
#define     PWM1_CCR1   (*(unsigned  int volatile xdata *)0xfed5)
#define     PWM1_CCR1H  (*(unsigned char volatile xdata *)0xfed5)
#define     PWM1_CCR1L  (*(unsigned char volatile xdata *)0xfed6)
#define     PWM1_CCR2   (*(unsigned  int volatile xdata *)0xfed7)
#define     PWM1_CCR2H  (*(unsigned char volatile xdata *)0xfed7)
#define     PWM1_CCR2L  (*(unsigned char volatile xdata *)0xfed8)
#define     PWM1_CCR3   (*(unsigned  int volatile xdata *)0xfed9)
#define     PWM1_CCR3H  (*(unsigned char volatile xdata *)0xfed9)
#define     PWM1_CCR3L  (*(unsigned char volatile xdata *)0xfeda)
#define     PWM1_CCR4   (*(unsigned  int volatile xdata *)0xfedb)
#define     PWM1_CCR4H  (*(unsigned char volatile xdata *)0xfedb)
#define     PWM1_CCR4L  (*(unsigned char volatile xdata *)0xfedc)
#define     PWM1_BKR    (*(unsigned char volatile xdata *)0xfedd)
#define     PWM1_DTR    (*(unsigned char volatile xdata *)0xfede)
#define     PWM1_OISR   (*(unsigned char volatile xdata *)0xfedf)
#define     PWM2_CR1    (*(unsigned char volatile xdata *)0xfee0)
#define     PWM2_CR2    (*(unsigned char volatile xdata *)0xfee1)
#define     PWM2_SMCR   (*(unsigned char volatile xdata *)0xfee2)
#define     PWM2_ETR    (*(unsigned char volatile xdata *)0xfee3)
#define     PWM2_IER    (*(unsigned char volatile xdata *)0xfee4)
#define     PWM2_SR1    (*(unsigned char volatile xdata *)0xfee5)
#define     PWM2_SR2    (*(unsigned char volatile xdata *)0xfee6)
#define     PWM2_EGR    (*(unsigned char volatile xdata *)0xfee7)
#define     PWM2_CCMR1  (*(unsigned char volatile xdata *)0xfee8)
#define     PWM2_CCMR2  (*(unsigned char volatile xdata *)0xfee9)
#define     PWM2_CCMR3  (*(unsigned char volatile xdata *)0xfeea)
#define     PWM2_CCMR4  (*(unsigned char volatile xdata *)0xfeeb)
#define     PWM2_CCER1  (*(unsigned char volatile xdata *)0xfeec)
#define     PWM2_CCER2  (*(unsigned char volatile xdata *)0xfeed)
#define     PWM2_CNTR   (*(unsigned  int volatile xdata *)0xfeee)
#define     PWM2_CNTRH  (*(unsigned char volatile xdata *)0xfeee)
#define     PWM2_CNTRL  (*(unsigned char volatile xdata *)0xfeef)
#define     PWM2_PSCR   (*(unsigned  int volatile xdata *)0xfef0)
#define     PWM2_PSCRH  (*(unsigned char volatile xdata *)0xfef0)
#define     PWM2_PSCRL  (*(unsigned char volatile xdata *)0xfef1)
#define     PWM2_ARR    (*(unsigned  int volatile xdata *)0xfef2)
#define     PWM2_ARRH   (*(unsigned char volatile xdata *)0xfef2)
#define     PWM2_ARRL   (*(unsigned char volatile xdata *)0xfef3)
#define     PWM2_RCR    (*(unsigned char volatile xdata *)0xfef4)
#define     PWM2_CCR1   (*(unsigned  int volatile xdata *)0xfef5)
#define     PWM2_CCR1H  (*(unsigned char volatile xdata *)0xfef5)
#define     PWM2_CCR1L  (*(unsigned char volatile xdata *)0xfef6)
#define     PWM2_CCR2   (*(unsigned  int volatile xdata *)0xfef7)
#define     PWM2_CCR2H  (*(unsigned char volatile xdata *)0xfef7)
#define     PWM2_CCR2L  (*(unsigned char volatile xdata *)0xfef8)
#define     PWM2_CCR3   (*(unsigned  int volatile xdata *)0xfef9)
#define     PWM2_CCR3H  (*(unsigned char volatile xdata *)0xfef9)
#define     PWM2_CCR3L  (*(unsigned char volatile xdata *)0xfefa)
#define     PWM2_CCR4   (*(unsigned  int volatile xdata *)0xfefb)
#define     PWM2_CCR4H  (*(unsigned char volatile xdata *)0xfefb)
#define     PWM2_CCR4L  (*(unsigned char volatile xdata *)0xfefc)
#define     PWM2_BKR    (*(unsigned char volatile xdata *)0xfefd)
#define     PWM2_DTR    (*(unsigned char volatile xdata *)0xfefe)
#define     PWM2_OISR   (*(unsigned char volatile xdata *)0xfeff)

#define     PWMA_ETRPS  (*(unsigned char volatile xdata *)0xfeb0)
#define     PWMA_ENO    (*(unsigned char volatile xdata *)0xfeb1)
#define     PWMA_PS     (*(unsigned char volatile xdata *)0xfeb2)
#define     PWMA_IOAUX  (*(unsigned char volatile xdata *)0xfeb3)
#define     PWMB_ETRPS  (*(unsigned char volatile xdata *)0xfeb4)
#define     PWMB_ENO    (*(unsigned char volatile xdata *)0xfeb5)
#define     PWMB_PS     (*(unsigned char volatile xdata *)0xfeb6)
#define     PWMB_IOAUX  (*(unsigned char volatile xdata *)0xfeb7)
#define     PWMA_CR1    (*(unsigned char volatile xdata *)0xfec0)
#define     PWMA_CR2    (*(unsigned char volatile xdata *)0xfec1)
#define     PWMA_SMCR   (*(unsigned char volatile xdata *)0xfec2)
#define     PWMA_ETR    (*(unsigned char volatile xdata *)0xfec3)
#define     PWMA_IER    (*(unsigned char volatile xdata *)0xfec4)
#define     PWMA_SR1    (*(unsigned char volatile xdata *)0xfec5)
#define     PWMA_SR2    (*(unsigned char volatile xdata *)0xfec6)
#define     PWMA_EGR    (*(unsigned char volatile xdata *)0xfec7)
#define     PWMA_CCMR1  (*(unsigned char volatile xdata *)0xfec8)
#define     PWMA_CCMR2  (*(unsigned char volatile xdata *)0xfec9)
#define     PWMA_CCMR3  (*(unsigned char volatile xdata *)0xfeca)
#define     PWMA_CCMR4  (*(unsigned char volatile xdata *)0xfecb)
#define     PWMA_CCER1  (*(unsigned char volatile xdata *)0xfecc)
#define     PWMA_CCER2  (*(unsigned char volatile xdata *)0xfecd)
#define     PWMA_CNTR   (*(unsigned  int volatile xdata *)0xfece)
#define     PWMA_CNTRH  (*(unsigned char volatile xdata *)0xfece)
#define     PWMA_CNTRL  (*(unsigned char volatile xdata *)0xfecf)
#define     PWMA_PSCR   (*(unsigned  int volatile xdata *)0xfed0)
#define     PWMA_PSCRH  (*(unsigned char volatile xdata *)0xfed0)
#define     PWMA_PSCRL  (*(unsigned char volatile xdata *)0xfed1)
#define     PWMA_ARR    (*(unsigned  int volatile xdata *)0xfed2)
#define     PWMA_ARRH   (*(unsigned char volatile xdata *)0xfed2)
#define     PWMA_ARRL   (*(unsigned char volatile xdata *)0xfed3)
#define     PWMA_RCR    (*(unsigned char volatile xdata *)0xfed4)
#define     PWMA_CCR1   (*(unsigned  int volatile xdata *)0xfed5)
#define     PWMA_CCR1H  (*(unsigned char volatile xdata *)0xfed5)
#define     PWMA_CCR1L  (*(unsigned char volatile xdata *)0xfed6)
#define     PWMA_CCR2   (*(unsigned  int volatile xdata *)0xfed7)
#define     PWMA_CCR2H  (*(unsigned char volatile xdata *)0xfed7)
#define     PWMA_CCR2L  (*(unsigned char volatile xdata *)0xfed8)
#define     PWMA_CCR3   (*(unsigned  int volatile xdata *)0xfed9)
#define     PWMA_CCR3H  (*(unsigned char volatile xdata *)0xfed9)
#define     PWMA_CCR3L  (*(unsigned char volatile xdata *)0xfeda)
#define     PWMA_CCR4   (*(unsigned  int volatile xdata *)0xfedb)
#define     PWMA_CCR4H  (*(unsigned char volatile xdata *)0xfedb)
#define     PWMA_CCR4L  (*(unsigned char volatile xdata *)0xfedc)
#define     PWMA_BKR    (*(unsigned char volatile xdata *)0xfedd)
#define     PWMA_DTR    (*(unsigned char volatile xdata *)0xfede)
#define     PWMA_OISR   (*(unsigned char volatile xdata *)0xfedf)
#define     PWMB_CR1    (*(unsigned char volatile xdata *)0xfee0)
#define     PWMB_CR2    (*(unsigned char volatile xdata *)0xfee1)
#define     PWMB_SMCR   (*(unsigned char volatile xdata *)0xfee2)
#define     PWMB_ETR    (*(unsigned char volatile xdata *)0xfee3)
#define     PWMB_IER    (*(unsigned char volatile xdata *)0xfee4)
#define     PWMB_SR1    (*(unsigned char volatile xdata *)0xfee5)
#define     PWMB_SR2    (*(unsigned char volatile xdata *)0xfee6)
#define     PWMB_EGR    (*(unsigned char volatile xdata *)0xfee7)
#define     PWMB_CCMR1  (*(unsigned char volatile xdata *)0xfee8)
#define     PWMB_CCMR2  (*(unsigned char volatile xdata *)0xfee9)
#define     PWMB_CCMR3  (*(unsigned char volatile xdata *)0xfeea)
#define     PWMB_CCMR4  (*(unsigned char volatile xdata *)0xfeeb)
#define     PWMB_CCER1  (*(unsigned char volatile xdata *)0xfeec)
#define     PWMB_CCER2  (*(unsigned char volatile xdata *)0xfeed)
#define     PWMB_CNTR   (*(unsigned  int volatile xdata *)0xfeee)
#define     PWMB_CNTRH  (*(unsigned char volatile xdata *)0xfeee)
#define     PWMB_CNTRL  (*(unsigned char volatile xdata *)0xfeef)
#define     PWMB_PSCR   (*(unsigned  int volatile xdata *)0xfef0)
#define     PWMB_PSCRH  (*(unsigned char volatile xdata *)0xfef0)
#define     PWMB_PSCRL  (*(unsigned char volatile xdata *)0xfef1)
#define     PWMB_ARR    (*(unsigned  int volatile xdata *)0xfef2)
#define     PWMB_ARRH   (*(unsigned char volatile xdata *)0xfef2)
#define     PWMB_ARRL   (*(unsigned char volatile xdata *)0xfef3)
#define     PWMB_RCR    (*(unsigned char volatile xdata *)0xfef4)
#define     PWMB_CCR5   (*(unsigned  int volatile xdata *)0xfef5)
#define     PWMB_CCR5H  (*(unsigned char volatile xdata *)0xfef5)
#define     PWMB_CCR5L  (*(unsigned char volatile xdata *)0xfef6)
#define     PWMB_CCR6   (*(unsigned  int volatile xdata *)0xfef7)
#define     PWMB_CCR6H  (*(unsigned char volatile xdata *)0xfef7)
#define     PWMB_CCR6L  (*(unsigned char volatile xdata *)0xfef8)
#define     PWMB_CCR7   (*(unsigned  int volatile xdata *)0xfef9)
#define     PWMB_CCR7H  (*(unsigned char volatile xdata *)0xfef9)
#define     PWMB_CCR7L  (*(unsigned char volatile xdata *)0xfefa)
#define     PWMB_CCR8   (*(unsigned  int volatile xdata *)0xfefb)
#define     PWMB_CCR8H  (*(unsigned char volatile xdata *)0xfefb)
#define     PWMB_CCR8L  (*(unsigned char volatile xdata *)0xfefc)
#define     PWMB_BKR    (*(unsigned char volatile xdata *)0xfefd)
#define     PWMB_DTR    (*(unsigned char volatile xdata *)0xfefe)
#define     PWMB_OISR   (*(unsigned char volatile xdata *)0xfeff)

/* PWM register */
sfr PWMCFG      =   PWMCFG_ADDRESS;
sfr PWMIF       =   PWMIF_ADDRESS;
sfr PWMFDCR     =   PWMFDCR_ADDRESS;
sfr PWMCR       =   PWMCR_ADDRESS;

#define PWMC        (*(__IO uint16_t xdata *)   PWMC_ADDRESS)
#define PWMCH       (*(__IO uint8_t xdata *)   PWMCH_ADDRESS)
#define PWMCL       (*(__IO uint8_t xdata *)   PWMCL_ADDRESS)
#define PWMCKS      (*(__IO uint8_t xdata *)  PWMCKS_ADDRESS)
#define TADCP       (*(__IO uint8_t xdata *)   TADCP_ADDRESS)
#define TADCPH      (*(__IO uint8_t xdata *)  TADCPH_ADDRESS)
#define TADCPL      (*(__IO uint8_t xdata *)  TADCPL_ADDRESS)

#define PWMxT1(PWMxT1_ADDRESS)      ( *(__IO uint16_t xdata *) PWMxT1_ADDRESS)
#define PWMxT2(PWMxT2_ADDRESS)      ( *(__IO uint16_t xdata *) PWMxT2_ADDRESS)
#define PWMxCR(PWMxCR_ADDRESS)      ( *(__IO uint8_t  xdata *) PWMxCR_ADDRESS)
#define PWMxHLD(PWMxHLD_ADDRESS)    ( *(__IO uint8_t  xdata *)PWMxHLD_ADDRESS)

#define PWM0T1      (*(__IO uint16_t xdata *) PWM0T1_ADDRESS)
#define PWM0T1H     (*(__IO uint8_t  xdata *)PWM0T1H_ADDRESS)
#define PWM0T1L     (*(__IO uint8_t  xdata *)PWM0T1L_ADDRESS)
#define PWM0T2      (*(__IO uint16_t xdata *) PWM0T2_ADDRESS)
#define PWM0T2H     (*(__IO uint8_t  xdata *)PWM0T2H_ADDRESS)
#define PWM0T2L     (*(__IO uint8_t  xdata *)PWM0T2L_ADDRESS)
#define PWM0CR      (*(__IO uint8_t  xdata *) PWM0CR_ADDRESS)
#define PWM0HLD     (*(__IO uint8_t  xdata *)PWM0HLD_ADDRESS)

#define PWM1T1      (*(__IO uint16_t xdata *) PWM1T1_ADDRESS)
#define PWM1T1H     (*(__IO uint8_t  xdata *)PWM1T1H_ADDRESS)
#define PWM1T1L     (*(__IO uint8_t  xdata *)PWM1T1L_ADDRESS)
#define PWM1T2      (*(__IO uint16_t xdata *) PWM1T2_ADDRESS)
#define PWM1T2H     (*(__IO uint8_t  xdata *)PWM1T2H_ADDRESS)
#define PWM1T2L     (*(__IO uint8_t  xdata *)PWM1T2L_ADDRESS)
#define PWM1CR      (*(__IO uint8_t  xdata *) PWM1CR_ADDRESS)
#define PWM1HLD     (*(__IO uint8_t  xdata *)PWM1HLD_ADDRESS)

#define PWM2T1      (*(__IO uint16_t xdata *) PWM2T1_ADDRESS)
#define PWM2T1H     (*(__IO uint8_t  xdata *)PWM2T1H_ADDRESS)
#define PWM2T1L     (*(__IO uint8_t  xdata *)PWM2T1L_ADDRESS)
#define PWM2T2      (*(__IO uint16_t xdata *) PWM2T2_ADDRESS)
#define PWM2T2H     (*(__IO uint8_t  xdata *)PWM2T2H_ADDRESS)
#define PWM2T2L     (*(__IO uint8_t  xdata *)PWM2T2L_ADDRESS)
#define PWM2CR      (*(__IO uint8_t  xdata *) PWM2CR_ADDRESS)
#define PWM2HLD     (*(__IO uint8_t  xdata *)PWM2HLD_ADDRESS)

#define PWM3T1      (*(__IO uint16_t xdata *) PWM3T1_ADDRESS)
#define PWM3T1H     (*(__IO uint8_t  xdata *)PWM3T1H_ADDRESS)
#define PWM3T1L     (*(__IO uint8_t  xdata *)PWM3T1L_ADDRESS)
#define PWM3T2      (*(__IO uint16_t xdata *) PWM3T2_ADDRESS)
#define PWM3T2H     (*(__IO uint8_t  xdata *)PWM3T2H_ADDRESS)
#define PWM3T2L     (*(__IO uint8_t  xdata *)PWM3T2L_ADDRESS)
#define PWM3CR      (*(__IO uint8_t  xdata *) PWM3CR_ADDRESS)
#define PWM3HLD     (*(__IO uint8_t  xdata *)PWM3HLD_ADDRESS)

#define PWM4T1      (*(__IO uint16_t xdata *) PWM4T1_ADDRESS)
#define PWM4T1H     (*(__IO uint8_t  xdata *)PWM4T1H_ADDRESS)
#define PWM4T1L     (*(__IO uint8_t  xdata *)PWM4T1L_ADDRESS)
#define PWM4T2      (*(__IO uint16_t xdata *) PWM4T2_ADDRESS)
#define PWM4T2H     (*(__IO uint8_t  xdata *)PWM4T2H_ADDRESS)
#define PWM4T2L     (*(__IO uint8_t  xdata *)PWM4T2L_ADDRESS)
#define PWM4CR      (*(__IO uint8_t  xdata *) PWM4CR_ADDRESS)
#define PWM4HLD     (*(__IO uint8_t  xdata *)PWM4HLD_ADDRESS)

#define PWM5T1      (*(__IO uint16_t xdata *) PWM5T1_ADDRESS)
#define PWM5T1H     (*(__IO uint8_t  xdata *)PWM5T1H_ADDRESS)
#define PWM5T1L     (*(__IO uint8_t  xdata *)PWM5T1L_ADDRESS)
#define PWM5T2      (*(__IO uint16_t xdata *) PWM5T2_ADDRESS)
#define PWM5T2H     (*(__IO uint8_t  xdata *)PWM5T2H_ADDRESS)
#define PWM5T2L     (*(__IO uint8_t  xdata *)PWM5T2L_ADDRESS)
#define PWM5CR      (*(__IO uint8_t  xdata *) PWM5CR_ADDRESS)
#define PWM5HLD     (*(__IO uint8_t  xdata *)PWM5HLD_ADDRESS)

#define PWM6T1      (*(__IO uint16_t xdata *) PWM6T1_ADDRESS)
#define PWM6T1H     (*(__IO uint8_t  xdata *)PWM6T1H_ADDRESS)
#define PWM6T1L     (*(__IO uint8_t  xdata *)PWM6T1L_ADDRESS)
#define PWM6T2      (*(__IO uint16_t xdata *) PWM6T2_ADDRESS)
#define PWM6T2H     (*(__IO uint8_t  xdata *)PWM6T2H_ADDRESS)
#define PWM6T2L     (*(__IO uint8_t  xdata *)PWM6T2L_ADDRESS)
#define PWM6CR      (*(__IO uint8_t  xdata *) PWM6CR_ADDRESS)
#define PWM6HLD     (*(__IO uint8_t  xdata *)PWM6HLD_ADDRESS)

#define PWM7T1      (*(__IO uint16_t xdata *) PWM7T1_ADDRESS)
#define PWM7T1H     (*(__IO uint8_t  xdata *)PWM7T1H_ADDRESS)
#define PWM7T1L     (*(__IO uint8_t  xdata *)PWM7T1L_ADDRESS)
#define PWM7T2      (*(__IO uint16_t xdata *) PWM7T2_ADDRESS)
#define PWM7T2H     (*(__IO uint8_t  xdata *)PWM7T2H_ADDRESS)
#define PWM7T2L     (*(__IO uint8_t  xdata *)PWM7T2L_ADDRESS)
#define PWM7CR      (*(__IO uint8_t  xdata *) PWM7CR_ADDRESS)
#define PWM7HLD     (*(__IO uint8_t  xdata *)PWM7HLD_ADDRESS)

/*--------------------------------------------------------
| @Description: SPI peripherals                          |
--------------------------------------------------------*/

/* Base address */
#define    SPSTAT_ADDRESS   0xCDU
#define    SPCTL_ADDRESS    0xCEU
#define    SPDAT_ADDRESS    0xCFU

/* SPSTAT */
#define SPIF        0x80
#define WCOL        0x40

/* SPCTL */
#define SSIG        0x80
#define SPEN        0x40
#define DORD        0x20
#define MSTR        0x10
#define CPOL        0x08
#define CPHA        0x04

/* SPI register */
sfr SPSTAT   =  SPSTAT_ADDRESS;
sfr SPCTL    =   SPCTL_ADDRESS;
sfr SPDAT    =   SPDAT_ADDRESS;

/*--------------------------------------------------------
| @Description: I2C peripherals                          |
--------------------------------------------------------*/

/* Base address */
#define    I2C_BASE         0xFE80U
#define    I2CCFG_ADDRESS   (I2C_BASE + 0x00U)
#define    I2CMSCR_ADDRESS  (I2C_BASE + 0x01U)
#define    I2CMSST_ADDRESS  (I2C_BASE + 0x02U)
#define    I2CSLCR_ADDRESS  (I2C_BASE + 0x03U)
#define    I2CSLST_ADDRESS  (I2C_BASE + 0x04U)
#define    I2CSLADR_ADDRESS (I2C_BASE + 0x05U)
#define    I2CTXD_ADDRESS   (I2C_BASE + 0x06U)
#define    I2CRXD_ADDRESS   (I2C_BASE + 0x07U)

/* I2CCFG */
#define ENI2C       0x80
#define MSSL        0x40

/* I2CMSCR */
#define EMSI        0x80

/* I2CMSST */
#define MSBUSY      0x80
#define MSIF        0x40
#define MSACKI      0x02
#define MSACKO      0x01

/* I2CSLCR */
#define ESTAI       0x40
#define ERXI        0x20
#define ETXI        0x10
#define ESTOI       0x08
#define SLRST       0x01

/* I2CSLST */
#define SLBUSY      0x80
#define STAIF       0x40
#define RXIF        0x20
#define TXIF        0x10
#define STOIF       0x08
#define TXING       0x04
#define SLACKI      0x02
#define SLACKO      0x01

/* SPI register */

#define I2CCFG      (*(__IO uint8_t xdata *)  I2CCFG_ADDRESS)
#define I2CMSCR     (*(__IO uint8_t xdata *) I2CMSCR_ADDRESS)
#define I2CMSST     (*(__IO uint8_t xdata *) I2CMSST_ADDRESS)
#define I2CSLCR     (*(__IO uint8_t xdata *) I2CSLCR_ADDRESS)
#define I2CSLST     (*(__IO uint8_t xdata * )I2CSLST_ADDRESS)
#define I2CSLADR    (*(__IO uint8_t xdata *)I2CSLADR_ADDRESS)
#define I2CTXD      (*(__IO uint8_t xdata *)  I2CTXD_ADDRESS)
#define I2CRXD      (*(__IO uint8_t xdata *)  I2CRXD_ADDRESS)

/*--------------------------------------------------------
| @Description: MDU16 peripherals                        |
--------------------------------------------------------*/

typedef struct
{
    __IO uint8_t MD3_REG;    /*---- MDU Divisor data register */

    __IO uint8_t MD2_REG;   /*---- MDU Divisor data register */
	
    __IO uint8_t MD1_REG;   /*---- MDU Divisor data register   */	
	
    __IO uint8_t MD0_REG;   /*---- MDU Divisor data register  */
	
    __IO uint8_t MD5_REG; /*---- MDU Divisor data register */

    __IO uint8_t MD4_REG;  /*---- MDU Divisor data register */ 

    __IO uint8_t ARCON_REG;   /*----MDU module data registe */

    __IO uint8_t OPCON_REG;   /*----MDU control data registe */

}   MDU16_TypeDef;

#define    MDU16_BASE    0xFCF0U

#define    MD3_ADDRESS      (MDU16_BASE)
#define    MD2_ADDRESS      (MDU16_BASE + 0x0001U)
#define    MD1_ADDRESS      (MDU16_BASE + 0x0002U)
#define    MD0_ADDRESS      (MDU16_BASE + 0x0003U)
#define    MD5_ADDRESS      (MDU16_BASE + 0x0004U)
#define    MD4_ADDRESS      (MDU16_BASE + 0x0005U)
#define    ARCON_ADDRESS    (MDU16_BASE + 0x0006U)
#define    OPCON_ADDRESS    (MDU16_BASE + 0x0007U)

/* Define type of MDU16 */

#define    MDU16      (* (MDU16_TypeDef  xdata *) MDU16_BASE)

#define    MD3U32      (*(__IO uint32_t xdata *)  MD3_ADDRESS)
#define    MD3U16      (*(__IO uint16_t xdata *)  MD3_ADDRESS)
#define    MD1U16      (*(__IO uint16_t xdata *)  MD1_ADDRESS)
#define    MD5U16      (*(__IO uint16_t xdata *)  MD5_ADDRESS)

#define    MD3         (*(__IO uint8_t xdata *)  MD3_ADDRESS)
#define    MD2         (*(__IO uint8_t xdata *)  MD2_ADDRESS)
#define    MD1         (*(__IO uint8_t xdata *)  MD1_ADDRESS)
#define    MD0         (*(__IO uint8_t xdata *)  MD0_ADDRESS)
#define    MD5         (*(__IO uint8_t xdata *)  MD5_ADDRESS)
#define    MD4         (*(__IO uint8_t xdata *)  MD4_ADDRESS)

#define    ARCON     (*(__IO uint8_t xdata *)  ARCON_ADDRESS)
#define    OPCON     (*(__IO uint8_t xdata *)  OPCON_ADDRESS)

/*--------------------------------------------------------
| @Description: USB peripherals                          |
--------------------------------------------------------*/

#define SUBCLK



#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/
