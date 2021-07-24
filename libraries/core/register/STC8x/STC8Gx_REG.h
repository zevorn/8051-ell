/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Gx_REG.h
  - Author        : zeweni / slipperstree
  - Update date   : 2021.07.25
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, zeweni (17870070675@163.com) / slipperstree (slipperstree@gmail.com)

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
#ifndef __STC8Gx_REG_H_
#define __STC8Gx_REG_H_

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
/* Define type of SYSCLK */

#define    SYSCLK     (* (SYSCLK_TypeDef  xdata *) SYSCLK_BASE)

/* SYSCLIL register */

#define    CKSEL       ( *(__IO uint8_t xdata *)    CKSEL_ADDRESS)
#define    CLKDIV      ( *(__IO uint8_t xdata *)   CLKDIV_ADDRESS)
#define    IRC24MCR    ( *(__IO uint8_t xdata *)   HIRCCR_ADDRESS)
#define    XOSCCR      ( *(__IO uint8_t xdata *)   XOSCCR_ADDRESS)
#define    IRC32KCR    ( *(__IO uint8_t xdata *) IRC32KCR_ADDRESS)
#define    MCLKOCR     ( *(__IO uint8_t xdata *)  MCLKOCR_ADDRESS)

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
| @Description: PCA peripherals                          |
--------------------------------------------------------*/

/*  Base address define */
#define    CCON_ADDRESS      0xD8U
#define    CMOD_ADDRESS      0xD9U
#define    CL_ADDRESS        0xE9U
#define    CH_ADDRESS        0xF9U
#define    CCAPM0_ADDRESS    0xDAU
#define    CCAPM1_ADDRESS    0xDBU
#define    CCAPM2_ADDRESS    0xDCU
#define    CCAP0L_ADDRESS    0xEAU
#define    CCAP1L_ADDRESS    0xEBU
#define    CCAP2L_ADDRESS    0xECU
#define    CCAP0H_ADDRESS    0xFAU
#define    CCAP1H_ADDRESS    0xFBU
#define    CCAP2H_ADDRESS    0xFCU
#define    PCA_PWM0_ADDRESS  0xF2U
#define    PCA_PWM1_ADDRESS  0xF3U
#define    PCA_PWM2_ADDRESS  0xF4U

/* CMOD */
#define CIDL        0x80
#define ECF         0x01

/* CCAPM0 */
#define ECOM0       0x40
#define CCAPP0      0x20
#define CCAPN0      0x10
#define MAT0        0x08
#define TOG0        0x04
#define PWM0        0x02
#define ECCF0       0x01

/* CCAPM1 */
#define ECOM1       0x40
#define CCAPP1      0x20
#define CCAPN1      0x10
#define MAT1        0x08
#define TOG1        0x04
#define PWM1        0x02
#define ECCF1       0x01

/* CCAMP2 */
#define ECOM2       0x40
#define CCAPP2      0x20
#define CCAPN2      0x10
#define MAT2        0x08
#define TOG2        0x04
#define PWM2        0x02
#define ECCF2       0x01

/* PCA register */
sfr CCON      =   CCON_ADDRESS;
sfr CMOD      =   CMOD_ADDRESS;
sfr CL        =   CL_ADDRESS;
sfr CH        =   CH_ADDRESS;
sfr CCAPM0    =   CCAPM0_ADDRESS;
sfr CCAPM1    =   CCAPM1_ADDRESS;
sfr CCAPM2    =   CCAPM2_ADDRESS;
sfr CCAP0L    =   CCAP0L_ADDRESS;
sfr CCAP1L    =   CCAP1L_ADDRESS;
sfr CCAP2L    =   CCAP2L_ADDRESS;

sfr CCAP0H    =   CCAP0H_ADDRESS;
sfr CCAP1H    =   CCAP1H_ADDRESS;
sfr CCAP2H    =   CCAP2H_ADDRESS;
sfr PCA_PWM0  =   PCA_PWM0_ADDRESS;
sfr PCA_PWM1  =   PCA_PWM1_ADDRESS;
sfr PCA_PWM2  =   PCA_PWM2_ADDRESS;

sbit CF    =  CCON ^ 7;
sbit CR    =  CCON ^ 6;
sbit CCF3  =  CCON ^ 3;
sbit CCF2  =  CCON ^ 2;
sbit CCF1  =  CCON ^ 1;
sbit CCF0  =  CCON ^ 0;

/*--------------------------------------------------------
| @Description: PWM peripherals                          |
--------------------------------------------------------*/

/*  Base address define */
#define    PWMSET_ADDRESS    0xF1U
#define    PWMCFG01_ADDRESS  0xF6U
#define    PWMCFG23_ADDRESS  0xF7U
#define    PWMCFG45_ADDRESS  0xFEU

/*  PWM0 control address define */
#define    PWM0_BASE          0xFF00U
#define    PWM0C_ADDRESS      (PWM0_BASE + 0x00U)
#define    PWM0CH_ADDRESS     (PWM0C_ADDRESS +  0x00U)
#define    PWM0CL_ADDRESS     (PWM0CH_ADDRESS + 0x01U)
#define    PWM0CKS_ADDRESS    (PWM0CL_ADDRESS + 0x01U)
#define    PWM0TADC_ADDRESS   (PWM0CKS_ADDRESS + 0x01U)
#define    PWM0TADCH_ADDRESS  (PWM0TADC_ADDRESS + 0x00U)
#define    PWM0TADCL_ADDRESS  (PWM0TADCH_ADDRESS +  0x01U)
#define    PWM0IF_ADDRESS     (PWM0TADCL_ADDRESS + 0x01U)
#define    PWM0FDCR_ADDRESS   (PWM0IF_ADDRESS + 0x01U)

/*  PWM0.0-PWM0.7 channal address define */
#define    PWM00T1_ADDRESS    (PWM0FDCR_ADDRESS + 0x03U)
#define    PWM00T1H_ADDRESS   (PWM00T1_ADDRESS +  0x00U)
#define    PWM00T1L_ADDRESS   (PWM00T1H_ADDRESS + 0x01U)
#define    PWM00T2_ADDRESS    (PWM00T1L_ADDRESS + 0x01U)
#define    PWM00T2H_ADDRESS   (PWM00T2_ADDRESS +  0x00U)
#define    PWM00T2L_ADDRESS   (PWM00T2H_ADDRESS + 0x01U)
#define    PWM00CR_ADDRESS    (PWM00T2L_ADDRESS + 0x01U)
#define    PWM00HLD_ADDRESS   (PWM00CR_ADDRESS +  0x01U)
#define    PWM01T1_ADDRESS    (PWM00HLD_ADDRESS + 0x03U)
#define    PWM01T1H_ADDRESS   (PWM01T1_ADDRESS +  0x00U)
#define    PWM01T1L_ADDRESS   (PWM01T1H_ADDRESS + 0x01U)
#define    PWM01T2_ADDRESS    (PWM01T1L_ADDRESS + 0x01U)
#define    PWM01T2H_ADDRESS   (PWM01T2_ADDRESS +  0x00U)
#define    PWM01T2L_ADDRESS   (PWM01T2H_ADDRESS + 0x01U)
#define    PWM01CR_ADDRESS    (PWM01T2L_ADDRESS + 0x01U)
#define    PWM01HLD_ADDRESS   (PWM01CR_ADDRESS +  0x01U)
#define    PWM02T1_ADDRESS    (PWM01HLD_ADDRESS + 0x03U)
#define    PWM02T1H_ADDRESS   (PWM02T1_ADDRESS +  0x00U)
#define    PWM02T1L_ADDRESS   (PWM02T1H_ADDRESS + 0x01U)
#define    PWM02T2_ADDRESS    (PWM02T1L_ADDRESS + 0x01U)
#define    PWM02T2H_ADDRESS   (PWM02T2_ADDRESS +  0x00U)
#define    PWM02T2L_ADDRESS   (PWM02T2H_ADDRESS + 0x01U)
#define    PWM02CR_ADDRESS    (PWM02T2L_ADDRESS + 0x01U)
#define    PWM02HLD_ADDRESS   (PWM02CR_ADDRESS +  0x01U)
#define    PWM03T1_ADDRESS    (PWM02HLD_ADDRESS + 0x03U)
#define    PWM03T1H_ADDRESS   (PWM03T1_ADDRESS +  0x00U)
#define    PWM03T1L_ADDRESS   (PWM03T1H_ADDRESS + 0x01U)
#define    PWM03T2_ADDRESS    (PWM03T1L_ADDRESS + 0x01U)
#define    PWM03T2H_ADDRESS   (PWM03T2_ADDRESS +  0x00U)
#define    PWM03T2L_ADDRESS   (PWM03T2H_ADDRESS + 0x01U)
#define    PWM03CR_ADDRESS    (PWM03T2L_ADDRESS + 0x01U)
#define    PWM03HLD_ADDRESS   (PWM03CR_ADDRESS +  0x01U)
#define    PWM04T1_ADDRESS    (PWM03HLD_ADDRESS + 0x03U)
#define    PWM04T1H_ADDRESS   (PWM04T1_ADDRESS +  0x00U)
#define    PWM04T1L_ADDRESS   (PWM04T1H_ADDRESS + 0x01U)
#define    PWM04T2_ADDRESS    (PWM04T1L_ADDRESS + 0x01U)
#define    PWM04T2H_ADDRESS   (PWM04T2_ADDRESS +  0x00U)
#define    PWM04T2L_ADDRESS   (PWM04T2H_ADDRESS + 0x01U)
#define    PWM04CR_ADDRESS    (PWM04T2L_ADDRESS + 0x01U)
#define    PWM04HLD_ADDRESS   (PWM04CR_ADDRESS +  0x01U)
#define    PWM05T1_ADDRESS    (PWM04HLD_ADDRESS + 0x03U)
#define    PWM05T1H_ADDRESS   (PWM05T1_ADDRESS +  0x00U)
#define    PWM05T1L_ADDRESS   (PWM05T1H_ADDRESS + 0x01U)
#define    PWM05T2_ADDRESS    (PWM05T1L_ADDRESS + 0x01U)
#define    PWM05T2H_ADDRESS   (PWM05T2_ADDRESS +  0x00U)
#define    PWM05T2L_ADDRESS   (PWM05T2H_ADDRESS + 0x01U)
#define    PWM05CR_ADDRESS    (PWM05T2L_ADDRESS + 0x01U)
#define    PWM05HLD_ADDRESS   (PWM05CR_ADDRESS +  0x01U)
#define    PWM06T1_ADDRESS    (PWM05HLD_ADDRESS + 0x03U)
#define    PWM06T1H_ADDRESS   (PWM06T1_ADDRESS +  0x00U)
#define    PWM06T1L_ADDRESS   (PWM06T1H_ADDRESS + 0x01U)
#define    PWM06T2_ADDRESS    (PWM06T1L_ADDRESS + 0x01U)
#define    PWM06T2H_ADDRESS   (PWM06T2_ADDRESS +  0x00U)
#define    PWM06T2L_ADDRESS   (PWM06T2H_ADDRESS + 0x01U)
#define    PWM06CR_ADDRESS    (PWM06T2L_ADDRESS + 0x01U)
#define    PWM06HLD_ADDRESS   (PWM06CR_ADDRESS +  0x01U)
#define    PWM07T1_ADDRESS    (PWM06HLD_ADDRESS + 0x03U)
#define    PWM07T1H_ADDRESS   (PWM07T1_ADDRESS +  0x00U)
#define    PWM07T1L_ADDRESS   (PWM07T1H_ADDRESS + 0x01U)
#define    PWM07T2_ADDRESS    (PWM07T1L_ADDRESS + 0x01U)
#define    PWM07T2H_ADDRESS   (PWM07T2_ADDRESS +  0x00U)
#define    PWM07T2L_ADDRESS   (PWM07T2H_ADDRESS + 0x01U)
#define    PWM07CR_ADDRESS    (PWM07T2L_ADDRESS + 0x01U)
#define    PWM07HLD_ADDRESS   (PWM07CR_ADDRESS +  0x01U)

/*  PWM1 control address define */
#define    PWM1_BASE          0xFF50U
#define    PWM1C_ADDRESS      (PWM1_BASE + 0x00U)
#define    PWM1CH_ADDRESS     (PWM1C_ADDRESS +  0x00U)
#define    PWM1CL_ADDRESS     (PWM1CH_ADDRESS + 0x01U)
#define    PWM1CKS_ADDRESS    (PWM1CL_ADDRESS + 0x01U)
#define    PWM1TADC_ADDRESS   (PWM1CKS_ADDRESS + 0x01U)
#define    PWM1TADCH_ADDRESS  (PWM1TADC_ADDRESS + 0x00U)
#define    PWM1TADCL_ADDRESS  (PWM1TADCH_ADDRESS +  0x01U)
#define    PWM1IF_ADDRESS     (PWM1TADCL_ADDRESS + 0x01U)
#define    PWM1FDCR_ADDRESS   (PWM1IF_ADDRESS + 0x01U)

/*  PWM1.0-PWM1.7 channal address define */
#define    PWM10T1_ADDRESS    (PWM1FDCR_ADDRESS + 0x03U)
#define    PWM10T1H_ADDRESS   (PWM10T1_ADDRESS +  0x00U)
#define    PWM10T1L_ADDRESS   (PWM10T1H_ADDRESS + 0x01U)
#define    PWM10T2_ADDRESS    (PWM10T1L_ADDRESS + 0x01U)
#define    PWM10T2H_ADDRESS   (PWM10T2_ADDRESS +  0x00U)
#define    PWM10T2L_ADDRESS   (PWM10T2H_ADDRESS + 0x01U)
#define    PWM10CR_ADDRESS    (PWM10T2L_ADDRESS + 0x01U)
#define    PWM10HLD_ADDRESS   (PWM10CR_ADDRESS +  0x01U)
#define    PWM11T1_ADDRESS    (PWM10HLD_ADDRESS + 0x03U)
#define    PWM11T1H_ADDRESS   (PWM11T1_ADDRESS +  0x00U)
#define    PWM11T1L_ADDRESS   (PWM11T1H_ADDRESS + 0x01U)
#define    PWM11T2_ADDRESS    (PWM11T1L_ADDRESS + 0x01U)
#define    PWM11T2H_ADDRESS   (PWM11T2_ADDRESS +  0x00U)
#define    PWM11T2L_ADDRESS   (PWM11T2H_ADDRESS + 0x01U)
#define    PWM11CR_ADDRESS    (PWM11T2L_ADDRESS + 0x01U)
#define    PWM11HLD_ADDRESS   (PWM11CR_ADDRESS +  0x01U)
#define    PWM12T1_ADDRESS    (PWM11HLD_ADDRESS + 0x03U)
#define    PWM12T1H_ADDRESS   (PWM12T1_ADDRESS +  0x00U)
#define    PWM12T1L_ADDRESS   (PWM12T1H_ADDRESS + 0x01U)
#define    PWM12T2_ADDRESS    (PWM12T1L_ADDRESS + 0x01U)
#define    PWM12T2H_ADDRESS   (PWM12T2_ADDRESS +  0x00U)
#define    PWM12T2L_ADDRESS   (PWM12T2H_ADDRESS + 0x01U)
#define    PWM12CR_ADDRESS    (PWM12T2L_ADDRESS + 0x01U)
#define    PWM12HLD_ADDRESS   (PWM12CR_ADDRESS +  0x01U)
#define    PWM13T1_ADDRESS    (PWM12HLD_ADDRESS + 0x03U)
#define    PWM13T1H_ADDRESS   (PWM13T1_ADDRESS +  0x00U)
#define    PWM13T1L_ADDRESS   (PWM13T1H_ADDRESS + 0x01U)
#define    PWM13T2_ADDRESS    (PWM13T1L_ADDRESS + 0x01U)
#define    PWM13T2H_ADDRESS   (PWM13T2_ADDRESS +  0x00U)
#define    PWM13T2L_ADDRESS   (PWM13T2H_ADDRESS + 0x01U)
#define    PWM13CR_ADDRESS    (PWM13T2L_ADDRESS + 0x01U)
#define    PWM13HLD_ADDRESS   (PWM13CR_ADDRESS +  0x01U)
#define    PWM14T1_ADDRESS    (PWM13HLD_ADDRESS + 0x03U)
#define    PWM14T1H_ADDRESS   (PWM14T1_ADDRESS +  0x00U)
#define    PWM14T1L_ADDRESS   (PWM14T1H_ADDRESS + 0x01U)
#define    PWM14T2_ADDRESS    (PWM14T1L_ADDRESS + 0x01U)
#define    PWM14T2H_ADDRESS   (PWM14T2_ADDRESS +  0x00U)
#define    PWM14T2L_ADDRESS   (PWM14T2H_ADDRESS + 0x01U)
#define    PWM14CR_ADDRESS    (PWM14T2L_ADDRESS + 0x01U)
#define    PWM14HLD_ADDRESS   (PWM14CR_ADDRESS +  0x01U)
#define    PWM15T1_ADDRESS    (PWM14HLD_ADDRESS + 0x03U)
#define    PWM15T1H_ADDRESS   (PWM15T1_ADDRESS +  0x00U)
#define    PWM15T1L_ADDRESS   (PWM15T1H_ADDRESS + 0x01U)
#define    PWM15T2_ADDRESS    (PWM15T1L_ADDRESS + 0x01U)
#define    PWM15T2H_ADDRESS   (PWM15T2_ADDRESS +  0x00U)
#define    PWM15T2L_ADDRESS   (PWM15T2H_ADDRESS + 0x01U)
#define    PWM15CR_ADDRESS    (PWM15T2L_ADDRESS + 0x01U)
#define    PWM15HLD_ADDRESS   (PWM15CR_ADDRESS +  0x01U)
#define    PWM16T1_ADDRESS    (PWM15HLD_ADDRESS + 0x03U)
#define    PWM16T1H_ADDRESS   (PWM16T1_ADDRESS +  0x00U)
#define    PWM16T1L_ADDRESS   (PWM16T1H_ADDRESS + 0x01U)
#define    PWM16T2_ADDRESS    (PWM16T1L_ADDRESS + 0x01U)
#define    PWM16T2H_ADDRESS   (PWM16T2_ADDRESS +  0x00U)
#define    PWM16T2L_ADDRESS   (PWM16T2H_ADDRESS + 0x01U)
#define    PWM16CR_ADDRESS    (PWM16T2L_ADDRESS + 0x01U)
#define    PWM16HLD_ADDRESS   (PWM16CR_ADDRESS +  0x01U)
#define    PWM17T1_ADDRESS    (PWM16HLD_ADDRESS + 0x03U)
#define    PWM17T1H_ADDRESS   (PWM17T1_ADDRESS +  0x00U)
#define    PWM17T1L_ADDRESS   (PWM17T1H_ADDRESS + 0x01U)
#define    PWM17T2_ADDRESS    (PWM17T1L_ADDRESS + 0x01U)
#define    PWM17T2H_ADDRESS   (PWM17T2_ADDRESS +  0x00U)
#define    PWM17T2L_ADDRESS   (PWM17T2H_ADDRESS + 0x01U)
#define    PWM17CR_ADDRESS    (PWM17T2L_ADDRESS + 0x01U)
#define    PWM17HLD_ADDRESS   (PWM17CR_ADDRESS +  0x01U)

/*  PWM2 control address define */
#define    PWM2_BASE          0xFFA0U
#define    PWM2C_ADDRESS      (PWM2_BASE + 0x00U)
#define    PWM2CH_ADDRESS     (PWM2C_ADDRESS +  0x00U)
#define    PWM2CL_ADDRESS     (PWM2CH_ADDRESS + 0x01U)
#define    PWM2CKS_ADDRESS    (PWM2CL_ADDRESS + 0x01U)
#define    PWM2TADC_ADDRESS   (PWM2CKS_ADDRESS + 0x01U)
#define    PWM2TADCH_ADDRESS  (PWM2TADC_ADDRESS + 0x00U)
#define    PWM2TADCL_ADDRESS  (PWM2TADCH_ADDRESS +  0x01U)
#define    PWM2IF_ADDRESS     (PWM2TADCL_ADDRESS + 0x01U)
#define    PWM2FDCR_ADDRESS   (PWM2IF_ADDRESS + 0x01U)

/*  PWM2.0-PWM2.7 channal address define */
#define    PWM20T1_ADDRESS    (PWM2FDCR_ADDRESS + 0x03U)
#define    PWM20T1H_ADDRESS   (PWM20T1_ADDRESS +  0x00U)
#define    PWM20T1L_ADDRESS   (PWM20T1H_ADDRESS + 0x01U)
#define    PWM20T2_ADDRESS    (PWM20T1L_ADDRESS + 0x01U)
#define    PWM20T2H_ADDRESS   (PWM20T2_ADDRESS +  0x00U)
#define    PWM20T2L_ADDRESS   (PWM20T2H_ADDRESS + 0x01U)
#define    PWM20CR_ADDRESS    (PWM20T2L_ADDRESS + 0x01U)
#define    PWM20HLD_ADDRESS   (PWM20CR_ADDRESS +  0x01U)
#define    PWM21T1_ADDRESS    (PWM20HLD_ADDRESS + 0x03U)
#define    PWM21T1H_ADDRESS   (PWM21T1_ADDRESS +  0x00U)
#define    PWM21T1L_ADDRESS   (PWM21T1H_ADDRESS + 0x01U)
#define    PWM21T2_ADDRESS    (PWM21T1L_ADDRESS + 0x01U)
#define    PWM21T2H_ADDRESS   (PWM21T2_ADDRESS +  0x00U)
#define    PWM21T2L_ADDRESS   (PWM21T2H_ADDRESS + 0x01U)
#define    PWM21CR_ADDRESS    (PWM21T2L_ADDRESS + 0x01U)
#define    PWM21HLD_ADDRESS   (PWM21CR_ADDRESS +  0x01U)
#define    PWM22T1_ADDRESS    (PWM21HLD_ADDRESS + 0x03U)
#define    PWM22T1H_ADDRESS   (PWM22T1_ADDRESS +  0x00U)
#define    PWM22T1L_ADDRESS   (PWM22T1H_ADDRESS + 0x01U)
#define    PWM22T2_ADDRESS    (PWM22T1L_ADDRESS + 0x01U)
#define    PWM22T2H_ADDRESS   (PWM22T2_ADDRESS +  0x00U)
#define    PWM22T2L_ADDRESS   (PWM22T2H_ADDRESS + 0x01U)
#define    PWM22CR_ADDRESS    (PWM22T2L_ADDRESS + 0x01U)
#define    PWM22HLD_ADDRESS   (PWM22CR_ADDRESS +  0x01U)
#define    PWM23T1_ADDRESS    (PWM22HLD_ADDRESS + 0x03U)
#define    PWM23T1H_ADDRESS   (PWM23T1_ADDRESS +  0x00U)
#define    PWM23T1L_ADDRESS   (PWM23T1H_ADDRESS + 0x01U)
#define    PWM23T2_ADDRESS    (PWM23T1L_ADDRESS + 0x01U)
#define    PWM23T2H_ADDRESS   (PWM23T2_ADDRESS +  0x00U)
#define    PWM23T2L_ADDRESS   (PWM23T2H_ADDRESS + 0x01U)
#define    PWM23CR_ADDRESS    (PWM23T2L_ADDRESS + 0x01U)
#define    PWM23HLD_ADDRESS   (PWM23CR_ADDRESS +  0x01U)
#define    PWM24T1_ADDRESS    (PWM23HLD_ADDRESS + 0x03U)
#define    PWM24T1H_ADDRESS   (PWM24T1_ADDRESS +  0x00U)
#define    PWM24T1L_ADDRESS   (PWM24T1H_ADDRESS + 0x01U)
#define    PWM24T2_ADDRESS    (PWM24T1L_ADDRESS + 0x01U)
#define    PWM24T2H_ADDRESS   (PWM24T2_ADDRESS +  0x00U)
#define    PWM24T2L_ADDRESS   (PWM24T2H_ADDRESS + 0x01U)
#define    PWM24CR_ADDRESS    (PWM24T2L_ADDRESS + 0x01U)
#define    PWM24HLD_ADDRESS   (PWM24CR_ADDRESS +  0x01U)
#define    PWM25T1_ADDRESS    (PWM24HLD_ADDRESS + 0x03U)
#define    PWM25T1H_ADDRESS   (PWM25T1_ADDRESS +  0x00U)
#define    PWM25T1L_ADDRESS   (PWM25T1H_ADDRESS + 0x01U)
#define    PWM25T2_ADDRESS    (PWM25T1L_ADDRESS + 0x01U)
#define    PWM25T2H_ADDRESS   (PWM25T2_ADDRESS +  0x00U)
#define    PWM25T2L_ADDRESS   (PWM25T2H_ADDRESS + 0x01U)
#define    PWM25CR_ADDRESS    (PWM25T2L_ADDRESS + 0x01U)
#define    PWM25HLD_ADDRESS   (PWM25CR_ADDRESS +  0x01U)
#define    PWM26T1_ADDRESS    (PWM25HLD_ADDRESS + 0x03U)
#define    PWM26T1H_ADDRESS   (PWM26T1_ADDRESS +  0x00U)
#define    PWM26T1L_ADDRESS   (PWM26T1H_ADDRESS + 0x01U)
#define    PWM26T2_ADDRESS    (PWM26T1L_ADDRESS + 0x01U)
#define    PWM26T2H_ADDRESS   (PWM26T2_ADDRESS +  0x00U)
#define    PWM26T2L_ADDRESS   (PWM26T2H_ADDRESS + 0x01U)
#define    PWM26CR_ADDRESS    (PWM26T2L_ADDRESS + 0x01U)
#define    PWM26HLD_ADDRESS   (PWM26CR_ADDRESS +  0x01U)
#define    PWM27T1_ADDRESS    (PWM26HLD_ADDRESS + 0x03U)
#define    PWM27T1H_ADDRESS   (PWM27T1_ADDRESS +  0x00U)
#define    PWM27T1L_ADDRESS   (PWM27T1H_ADDRESS + 0x01U)
#define    PWM27T2_ADDRESS    (PWM27T1L_ADDRESS + 0x01U)
#define    PWM27T2H_ADDRESS   (PWM27T2_ADDRESS +  0x00U)
#define    PWM27T2L_ADDRESS   (PWM27T2H_ADDRESS + 0x01U)
#define    PWM27CR_ADDRESS    (PWM27T2L_ADDRESS + 0x01U)
#define    PWM27HLD_ADDRESS   (PWM27CR_ADDRESS +  0x01U)

/*  PWM3 control address define */
#define    PWM3_BASE          0xFC00U
#define    PWM3C_ADDRESS      (PWM3_BASE + 0x00U)
#define    PWM3CH_ADDRESS     (PWM3C_ADDRESS +  0x00U)
#define    PWM3CL_ADDRESS     (PWM3CH_ADDRESS + 0x01U)
#define    PWM3CKS_ADDRESS    (PWM3CL_ADDRESS + 0x01U)
#define    PWM3TADC_ADDRESS   (PWM3CKS_ADDRESS + 0x01U)
#define    PWM3TADCH_ADDRESS  (PWM3TADC_ADDRESS + 0x00U)
#define    PWM3TADCL_ADDRESS  (PWM3TADCH_ADDRESS +  0x01U)
#define    PWM3IF_ADDRESS     (PWM3TADCL_ADDRESS + 0x01U)
#define    PWM3FDCR_ADDRESS   (PWM3IF_ADDRESS + 0x01U)

/*  PWM3.0-PWM3.7 channal address define */
#define    PWM30T1_ADDRESS    (PWM3FDCR_ADDRESS + 0x03U)
#define    PWM30T1H_ADDRESS   (PWM30T1_ADDRESS +  0x00U)
#define    PWM30T1L_ADDRESS   (PWM30T1H_ADDRESS + 0x01U)
#define    PWM30T2_ADDRESS    (PWM30T1L_ADDRESS + 0x01U)
#define    PWM30T2H_ADDRESS   (PWM30T2_ADDRESS +  0x00U)
#define    PWM30T2L_ADDRESS   (PWM30T2H_ADDRESS + 0x01U)
#define    PWM30CR_ADDRESS    (PWM30T2L_ADDRESS + 0x01U)
#define    PWM30HLD_ADDRESS   (PWM30CR_ADDRESS +  0x01U)
#define    PWM31T1_ADDRESS    (PWM30HLD_ADDRESS + 0x03U)
#define    PWM31T1H_ADDRESS   (PWM31T1_ADDRESS +  0x00U)
#define    PWM31T1L_ADDRESS   (PWM31T1H_ADDRESS + 0x01U)
#define    PWM31T2_ADDRESS    (PWM31T1L_ADDRESS + 0x01U)
#define    PWM31T2H_ADDRESS   (PWM31T2_ADDRESS +  0x00U)
#define    PWM31T2L_ADDRESS   (PWM31T2H_ADDRESS + 0x01U)
#define    PWM31CR_ADDRESS    (PWM31T2L_ADDRESS + 0x01U)
#define    PWM31HLD_ADDRESS   (PWM31CR_ADDRESS +  0x01U)
#define    PWM32T1_ADDRESS    (PWM31HLD_ADDRESS + 0x03U)
#define    PWM32T1H_ADDRESS   (PWM32T1_ADDRESS +  0x00U)
#define    PWM32T1L_ADDRESS   (PWM32T1H_ADDRESS + 0x01U)
#define    PWM32T2_ADDRESS    (PWM32T1L_ADDRESS + 0x01U)
#define    PWM32T2H_ADDRESS   (PWM32T2_ADDRESS +  0x00U)
#define    PWM32T2L_ADDRESS   (PWM32T2H_ADDRESS + 0x01U)
#define    PWM32CR_ADDRESS    (PWM32T2L_ADDRESS + 0x01U)
#define    PWM32HLD_ADDRESS   (PWM32CR_ADDRESS +  0x01U)
#define    PWM33T1_ADDRESS    (PWM32HLD_ADDRESS + 0x03U)
#define    PWM33T1H_ADDRESS   (PWM33T1_ADDRESS +  0x00U)
#define    PWM33T1L_ADDRESS   (PWM33T1H_ADDRESS + 0x01U)
#define    PWM33T2_ADDRESS    (PWM33T1L_ADDRESS + 0x01U)
#define    PWM33T2H_ADDRESS   (PWM33T2_ADDRESS +  0x00U)
#define    PWM33T2L_ADDRESS   (PWM33T2H_ADDRESS + 0x01U)
#define    PWM33CR_ADDRESS    (PWM33T2L_ADDRESS + 0x01U)
#define    PWM33HLD_ADDRESS   (PWM33CR_ADDRESS +  0x01U)
#define    PWM34T1_ADDRESS    (PWM33HLD_ADDRESS + 0x03U)
#define    PWM34T1H_ADDRESS   (PWM34T1_ADDRESS +  0x00U)
#define    PWM34T1L_ADDRESS   (PWM34T1H_ADDRESS + 0x01U)
#define    PWM34T2_ADDRESS    (PWM34T1L_ADDRESS + 0x01U)
#define    PWM34T2H_ADDRESS   (PWM34T2_ADDRESS +  0x00U)
#define    PWM34T2L_ADDRESS   (PWM34T2H_ADDRESS + 0x01U)
#define    PWM34CR_ADDRESS    (PWM34T2L_ADDRESS + 0x01U)
#define    PWM34HLD_ADDRESS   (PWM34CR_ADDRESS +  0x01U)
#define    PWM35T1_ADDRESS    (PWM34HLD_ADDRESS + 0x03U)
#define    PWM35T1H_ADDRESS   (PWM35T1_ADDRESS +  0x00U)
#define    PWM35T1L_ADDRESS   (PWM35T1H_ADDRESS + 0x01U)
#define    PWM35T2_ADDRESS    (PWM35T1L_ADDRESS + 0x01U)
#define    PWM35T2H_ADDRESS   (PWM35T2_ADDRESS +  0x00U)
#define    PWM35T2L_ADDRESS   (PWM35T2H_ADDRESS + 0x01U)
#define    PWM35CR_ADDRESS    (PWM35T2L_ADDRESS + 0x01U)
#define    PWM35HLD_ADDRESS   (PWM35CR_ADDRESS +  0x01U)
#define    PWM36T1_ADDRESS    (PWM35HLD_ADDRESS + 0x03U)
#define    PWM36T1H_ADDRESS   (PWM36T1_ADDRESS +  0x00U)
#define    PWM36T1L_ADDRESS   (PWM36T1H_ADDRESS + 0x01U)
#define    PWM36T2_ADDRESS    (PWM36T1L_ADDRESS + 0x01U)
#define    PWM36T2H_ADDRESS   (PWM36T2_ADDRESS +  0x00U)
#define    PWM36T2L_ADDRESS   (PWM36T2H_ADDRESS + 0x01U)
#define    PWM36CR_ADDRESS    (PWM36T2L_ADDRESS + 0x01U)
#define    PWM36HLD_ADDRESS   (PWM36CR_ADDRESS +  0x01U)
#define    PWM37T1_ADDRESS    (PWM36HLD_ADDRESS + 0x03U)
#define    PWM37T1H_ADDRESS   (PWM37T1_ADDRESS +  0x00U)
#define    PWM37T1L_ADDRESS   (PWM37T1H_ADDRESS + 0x01U)
#define    PWM37T2_ADDRESS    (PWM37T1L_ADDRESS + 0x01U)
#define    PWM37T2H_ADDRESS   (PWM37T2_ADDRESS +  0x00U)
#define    PWM37T2L_ADDRESS   (PWM37T2H_ADDRESS + 0x01U)
#define    PWM37CR_ADDRESS    (PWM37T2L_ADDRESS + 0x01U)
#define    PWM37HLD_ADDRESS   (PWM37CR_ADDRESS +  0x01U)

/*  PWM4 control address define */
#define    PWM4_BASE          0xFC50U
#define    PWM4C_ADDRESS      (PWM4_BASE + 0x00U)
#define    PWM4CH_ADDRESS     (PWM4C_ADDRESS +  0x00U)
#define    PWM4CL_ADDRESS     (PWM4CH_ADDRESS + 0x01U)
#define    PWM4CKS_ADDRESS    (PWM4CL_ADDRESS + 0x01U)
#define    PWM4TADC_ADDRESS   (PWM4CKS_ADDRESS + 0x01U)
#define    PWM4TADCH_ADDRESS  (PWM4TADC_ADDRESS + 0x00U)
#define    PWM4TADCL_ADDRESS  (PWM4TADCH_ADDRESS +  0x01U)
#define    PWM4IF_ADDRESS     (PWM4TADCL_ADDRESS + 0x01U)
#define    PWM4FDCR_ADDRESS   (PWM4IF_ADDRESS + 0x01U)

/*  PWM4.0-PWM4.7 channal address define */
#define    PWM40T1_ADDRESS    (PWM4FDCR_ADDRESS + 0x03U)
#define    PWM40T1H_ADDRESS   (PWM40T1_ADDRESS +  0x00U)
#define    PWM40T1L_ADDRESS   (PWM40T1H_ADDRESS + 0x01U)
#define    PWM40T2_ADDRESS    (PWM40T1L_ADDRESS + 0x01U)
#define    PWM40T2H_ADDRESS   (PWM40T2_ADDRESS +  0x00U)
#define    PWM40T2L_ADDRESS   (PWM40T2H_ADDRESS + 0x01U)
#define    PWM40CR_ADDRESS    (PWM40T2L_ADDRESS + 0x01U)
#define    PWM40HLD_ADDRESS   (PWM40CR_ADDRESS +  0x01U)
#define    PWM41T1_ADDRESS    (PWM40HLD_ADDRESS + 0x03U)
#define    PWM41T1H_ADDRESS   (PWM41T1_ADDRESS +  0x00U)
#define    PWM41T1L_ADDRESS   (PWM41T1H_ADDRESS + 0x01U)
#define    PWM41T2_ADDRESS    (PWM41T1L_ADDRESS + 0x01U)
#define    PWM41T2H_ADDRESS   (PWM41T2_ADDRESS +  0x00U)
#define    PWM41T2L_ADDRESS   (PWM41T2H_ADDRESS + 0x01U)
#define    PWM41CR_ADDRESS    (PWM41T2L_ADDRESS + 0x01U)
#define    PWM41HLD_ADDRESS   (PWM41CR_ADDRESS +  0x01U)
#define    PWM42T1_ADDRESS    (PWM41HLD_ADDRESS + 0x03U)
#define    PWM42T1H_ADDRESS   (PWM42T1_ADDRESS +  0x00U)
#define    PWM42T1L_ADDRESS   (PWM42T1H_ADDRESS + 0x01U)
#define    PWM42T2_ADDRESS    (PWM42T1L_ADDRESS + 0x01U)
#define    PWM42T2H_ADDRESS   (PWM42T2_ADDRESS +  0x00U)
#define    PWM42T2L_ADDRESS   (PWM42T2H_ADDRESS + 0x01U)
#define    PWM42CR_ADDRESS    (PWM42T2L_ADDRESS + 0x01U)
#define    PWM42HLD_ADDRESS   (PWM42CR_ADDRESS +  0x01U)
#define    PWM43T1_ADDRESS    (PWM42HLD_ADDRESS + 0x03U)
#define    PWM43T1H_ADDRESS   (PWM43T1_ADDRESS +  0x00U)
#define    PWM43T1L_ADDRESS   (PWM43T1H_ADDRESS + 0x01U)
#define    PWM43T2_ADDRESS    (PWM43T1L_ADDRESS + 0x01U)
#define    PWM43T2H_ADDRESS   (PWM43T2_ADDRESS +  0x00U)
#define    PWM43T2L_ADDRESS   (PWM43T2H_ADDRESS + 0x01U)
#define    PWM43CR_ADDRESS    (PWM43T2L_ADDRESS + 0x01U)
#define    PWM43HLD_ADDRESS   (PWM43CR_ADDRESS +  0x01U)
#define    PWM44T1_ADDRESS    (PWM43HLD_ADDRESS + 0x03U)
#define    PWM44T1H_ADDRESS   (PWM44T1_ADDRESS +  0x00U)
#define    PWM44T1L_ADDRESS   (PWM44T1H_ADDRESS + 0x01U)
#define    PWM44T2_ADDRESS    (PWM44T1L_ADDRESS + 0x01U)
#define    PWM44T2H_ADDRESS   (PWM44T2_ADDRESS +  0x00U)
#define    PWM44T2L_ADDRESS   (PWM44T2H_ADDRESS + 0x01U)
#define    PWM44CR_ADDRESS    (PWM44T2L_ADDRESS + 0x01U)
#define    PWM44HLD_ADDRESS   (PWM44CR_ADDRESS +  0x01U)
#define    PWM45T1_ADDRESS    (PWM44HLD_ADDRESS + 0x03U)
#define    PWM45T1H_ADDRESS   (PWM45T1_ADDRESS +  0x00U)
#define    PWM45T1L_ADDRESS   (PWM45T1H_ADDRESS + 0x01U)
#define    PWM45T2_ADDRESS    (PWM45T1L_ADDRESS + 0x01U)
#define    PWM45T2H_ADDRESS   (PWM45T2_ADDRESS +  0x00U)
#define    PWM45T2L_ADDRESS   (PWM45T2H_ADDRESS + 0x01U)
#define    PWM45CR_ADDRESS    (PWM45T2L_ADDRESS + 0x01U)
#define    PWM45HLD_ADDRESS   (PWM45CR_ADDRESS +  0x01U)
#define    PWM46T1_ADDRESS    (PWM45HLD_ADDRESS + 0x03U)
#define    PWM46T1H_ADDRESS   (PWM46T1_ADDRESS +  0x00U)
#define    PWM46T1L_ADDRESS   (PWM46T1H_ADDRESS + 0x01U)
#define    PWM46T2_ADDRESS    (PWM46T1L_ADDRESS + 0x01U)
#define    PWM46T2H_ADDRESS   (PWM46T2_ADDRESS +  0x00U)
#define    PWM46T2L_ADDRESS   (PWM46T2H_ADDRESS + 0x01U)
#define    PWM46CR_ADDRESS    (PWM46T2L_ADDRESS + 0x01U)
#define    PWM46HLD_ADDRESS   (PWM46CR_ADDRESS +  0x01U)
#define    PWM47T1_ADDRESS    (PWM46HLD_ADDRESS + 0x03U)
#define    PWM47T1H_ADDRESS   (PWM47T1_ADDRESS +  0x00U)
#define    PWM47T1L_ADDRESS   (PWM47T1H_ADDRESS + 0x01U)
#define    PWM47T2_ADDRESS    (PWM47T1L_ADDRESS + 0x01U)
#define    PWM47T2H_ADDRESS   (PWM47T2_ADDRESS +  0x00U)
#define    PWM47T2L_ADDRESS   (PWM47T2H_ADDRESS + 0x01U)
#define    PWM47CR_ADDRESS    (PWM47T2L_ADDRESS + 0x01U)
#define    PWM47HLD_ADDRESS   (PWM47CR_ADDRESS +  0x01U)

/*  PWM5 control address define */
#define    PWM5_BASE          0xFCA0U
#define    PWM5C_ADDRESS      (PWM5_BASE + 0x00U)
#define    PWM5CH_ADDRESS     (PWM5C_ADDRESS +  0x00U)
#define    PWM5CL_ADDRESS     (PWM5CH_ADDRESS + 0x01U)
#define    PWM5CKS_ADDRESS    (PWM5CL_ADDRESS + 0x01U)
#define    PWM5TADC_ADDRESS   (PWM5CKS_ADDRESS + 0x01U)
#define    PWM5TADCH_ADDRESS  (PWM5TADC_ADDRESS + 0x00U)
#define    PWM5TADCL_ADDRESS  (PWM5TADCH_ADDRESS +  0x01U)
#define    PWM5IF_ADDRESS     (PWM5TADCL_ADDRESS + 0x01U)
#define    PWM5FDCR_ADDRESS   (PWM5IF_ADDRESS + 0x01U)

/*  PWM5.0-PWM5.7 channal address define */
#define    PWM50T1_ADDRESS    (PWM5FDCR_ADDRESS + 0x03U)
#define    PWM50T1H_ADDRESS   (PWM50T1_ADDRESS +  0x00U)
#define    PWM50T1L_ADDRESS   (PWM50T1H_ADDRESS + 0x01U)
#define    PWM50T2_ADDRESS    (PWM50T1L_ADDRESS + 0x01U)
#define    PWM50T2H_ADDRESS   (PWM50T2_ADDRESS +  0x00U)
#define    PWM50T2L_ADDRESS   (PWM50T2H_ADDRESS + 0x01U)
#define    PWM50CR_ADDRESS    (PWM50T2L_ADDRESS + 0x01U)
#define    PWM50HLD_ADDRESS   (PWM50CR_ADDRESS +  0x01U)
#define    PWM51T1_ADDRESS    (PWM50HLD_ADDRESS + 0x03U)
#define    PWM51T1H_ADDRESS   (PWM51T1_ADDRESS +  0x00U)
#define    PWM51T1L_ADDRESS   (PWM51T1H_ADDRESS + 0x01U)
#define    PWM51T2_ADDRESS    (PWM51T1L_ADDRESS + 0x01U)
#define    PWM51T2H_ADDRESS   (PWM51T2_ADDRESS +  0x00U)
#define    PWM51T2L_ADDRESS   (PWM51T2H_ADDRESS + 0x01U)
#define    PWM51CR_ADDRESS    (PWM51T2L_ADDRESS + 0x01U)
#define    PWM51HLD_ADDRESS   (PWM51CR_ADDRESS +  0x01U)
#define    PWM52T1_ADDRESS    (PWM51HLD_ADDRESS + 0x03U)
#define    PWM52T1H_ADDRESS   (PWM52T1_ADDRESS +  0x00U)
#define    PWM52T1L_ADDRESS   (PWM52T1H_ADDRESS + 0x01U)
#define    PWM52T2_ADDRESS    (PWM52T1L_ADDRESS + 0x01U)
#define    PWM52T2H_ADDRESS   (PWM52T2_ADDRESS +  0x00U)
#define    PWM52T2L_ADDRESS   (PWM52T2H_ADDRESS + 0x01U)
#define    PWM52CR_ADDRESS    (PWM52T2L_ADDRESS + 0x01U)
#define    PWM52HLD_ADDRESS   (PWM52CR_ADDRESS +  0x01U)
#define    PWM53T1_ADDRESS    (PWM52HLD_ADDRESS + 0x03U)
#define    PWM53T1H_ADDRESS   (PWM53T1_ADDRESS +  0x00U)
#define    PWM53T1L_ADDRESS   (PWM53T1H_ADDRESS + 0x01U)
#define    PWM53T2_ADDRESS    (PWM53T1L_ADDRESS + 0x01U)
#define    PWM53T2H_ADDRESS   (PWM53T2_ADDRESS +  0x00U)
#define    PWM53T2L_ADDRESS   (PWM53T2H_ADDRESS + 0x01U)
#define    PWM53CR_ADDRESS    (PWM53T2L_ADDRESS + 0x01U)
#define    PWM53HLD_ADDRESS   (PWM53CR_ADDRESS +  0x01U)
#define    PWM54T1_ADDRESS    (PWM53HLD_ADDRESS + 0x03U)
#define    PWM54T1H_ADDRESS   (PWM54T1_ADDRESS +  0x00U)
#define    PWM54T1L_ADDRESS   (PWM54T1H_ADDRESS + 0x01U)
#define    PWM54T2_ADDRESS    (PWM54T1L_ADDRESS + 0x01U)
#define    PWM54T2H_ADDRESS   (PWM54T2_ADDRESS +  0x00U)
#define    PWM54T2L_ADDRESS   (PWM54T2H_ADDRESS + 0x01U)
#define    PWM54CR_ADDRESS    (PWM54T2L_ADDRESS + 0x01U)
#define    PWM54HLD_ADDRESS   (PWM54CR_ADDRESS +  0x01U)
#define    PWM55T1_ADDRESS    (PWM54HLD_ADDRESS + 0x03U)
#define    PWM55T1H_ADDRESS   (PWM55T1_ADDRESS +  0x00U)
#define    PWM55T1L_ADDRESS   (PWM55T1H_ADDRESS + 0x01U)
#define    PWM55T2_ADDRESS    (PWM55T1L_ADDRESS + 0x01U)
#define    PWM55T2H_ADDRESS   (PWM55T2_ADDRESS +  0x00U)
#define    PWM55T2L_ADDRESS   (PWM55T2H_ADDRESS + 0x01U)
#define    PWM55CR_ADDRESS    (PWM55T2L_ADDRESS + 0x01U)
#define    PWM55HLD_ADDRESS   (PWM55CR_ADDRESS +  0x01U)
#define    PWM56T1_ADDRESS    (PWM55HLD_ADDRESS + 0x03U)
#define    PWM56T1H_ADDRESS   (PWM56T1_ADDRESS +  0x00U)
#define    PWM56T1L_ADDRESS   (PWM56T1H_ADDRESS + 0x01U)
#define    PWM56T2_ADDRESS    (PWM56T1L_ADDRESS + 0x01U)
#define    PWM56T2H_ADDRESS   (PWM56T2_ADDRESS +  0x00U)
#define    PWM56T2L_ADDRESS   (PWM56T2H_ADDRESS + 0x01U)
#define    PWM56CR_ADDRESS    (PWM56T2L_ADDRESS + 0x01U)
#define    PWM56HLD_ADDRESS   (PWM56CR_ADDRESS +  0x01U)
#define    PWM57T1_ADDRESS    (PWM56HLD_ADDRESS + 0x03U)
#define    PWM57T1H_ADDRESS   (PWM57T1_ADDRESS +  0x00U)
#define    PWM57T1L_ADDRESS   (PWM57T1H_ADDRESS + 0x01U)
#define    PWM57T2_ADDRESS    (PWM57T1L_ADDRESS + 0x01U)
#define    PWM57T2H_ADDRESS   (PWM57T2_ADDRESS +  0x00U)
#define    PWM57T2L_ADDRESS   (PWM57T2H_ADDRESS + 0x01U)
#define    PWM57CR_ADDRESS    (PWM57T2L_ADDRESS + 0x01U)
#define    PWM57HLD_ADDRESS   (PWM57CR_ADDRESS +  0x01U)

/*  Register bit define */
/* PWMSET */
#define ENGLBSET    0x80
#define PWMRST      0x40
#define ENPWM5      0x20
#define ENPWM4      0x10
#define ENPWM3      0x08
#define ENPWM2      0x04
#define ENPWM1      0x02
#define ENPWM0      0x01

/* PWMCFGxx bits */
#define PWMCBIF135    0x80
#define EPWMCBI135    0x40
#define FLTPS         0x20
#define PWMCEN135     0x10
#define PWMCBIF024    0x08
#define EPWMCBI024    0x04
#define ENPWMTA024    0x02
#define PWMCEN024     0x01

/* PWMnIF */
#define C7IF        0x80
#define C6IF        0x40
#define C5IF        0x20
#define C4IF        0x10
#define C3IF        0x08
#define C2IF        0x04
#define C1IF        0x02
#define C0IF        0x01

/* PWMnFDCR */
#define INVCMP      0x80
#define INVIO       0x40
#define ENFD        0x20
#define FLTFLIO     0x10
#define EFDI        0x08
#define FDCMP       0x04
#define FDIO        0x02
#define FDIF        0x01

/* PWMniCR */
#define ENO         0x80
#define INI         0x40
#define ENI         0x04
#define ENT2I       0x02
#define ENT1I       0x01

/* PWM register */
/*** 全体设置（PORT无关/CHANNEL无关） ************************************************/
/*** 增强型 PWM 全局配置寄存器(PWMSET) ***/
sfr PWMSET      =   PWMSET_ADDRESS;

/* ENGLBSET:全局设置功能控制。 
    0:6 组 PWM 采用各自独立设置方式。
      每组 PWM 分别使用 PWMCFG01/PWMCFG23/PWMCFG45 相应的控制位就绪独立配置。
    1:6 组 PWM 采用统一设置方式。
      每组 PWM 均采用 PWMCFG01 中的 PWM0 的设置进行配置。
*/
#define clrBitENGLBSET()    PWMSET&=(~ENGLBSET)
#define setBitENGLBSET()    PWMSET|=( ENGLBSET)

/* PWMRST:软件复位 6 组 PWM。
    0:无效
    1:复位所有 PWM 的 XFR 寄存器，但不复位 SFR。(需要软件清零)
*/
#define clrBitPWMRST()      PWMSET&=(~PWMRST)
#define setBitPWMRST()      PWMSET|=( PWMRST)

/*** PORT单位设置（CHANNEL无关）*******************************************************/
/* ENPWMn PWMn 使能位 (n=0~5) */
#define PWM_ENABLE(PORT)     PWMSET|=(1<<PORT)
#define PWM_DISABLE(PORT)    PWMSET&=(~(1<<PORT))

/*** 增强型 PWM 配置寄存器(PWMCFGn) ***/
sfr PWMCFG01    =   PWMCFG01_ADDRESS;
sfr PWMCFG23    =   PWMCFG23_ADDRESS;
sfr PWMCFG45    =   PWMCFG45_ADDRESS;

/* PWMn 计数器归零中断标志位。(n=0~5)  
  当 15 位的 PWMn 计数器记满溢出归零时，硬件自动将此位置 1，
  并向 CPU 提出中断请求，此标志位需要软件清零。
*/
#define clrBitPWMnCBIF(PORT)  {if(PORT==0){PWMCFG01&=(~PWMCBIF024);} \
                          else if(PORT==1){PWMCFG01&=(~PWMCBIF135);} \
                          else if(PORT==2){PWMCFG23&=(~PWMCBIF024);} \
                          else if(PORT==3){PWMCFG23&=(~PWMCBIF135);} \
                          else if(PORT==4){PWMCFG45&=(~PWMCBIF024);} \
                          else if(PORT==5){PWMCFG45&=(~PWMCBIF135);}}

/* PWMn 计数器归零中断使能位。(n=0~5) */
/* PWMn 计数器归零中断使能位。0:关闭 PWMn 计数器归零中断(PWMnCBIF 依然会被硬件置位) (n=0~5) */
#define clrBitEPWMnCBI(PORT)  {if(PORT==0){PWMCFG01&=(~EPWMCBI024);} \
                          else if(PORT==1){PWMCFG01&=(~EPWMCBI135);} \
                          else if(PORT==2){PWMCFG23&=(~EPWMCBI024);} \
                          else if(PORT==3){PWMCFG23&=(~EPWMCBI135);} \
                          else if(PORT==4){PWMCFG45&=(~EPWMCBI024);} \
                          else if(PORT==5){PWMCFG45&=(~EPWMCBI135);}}
/* PWMn 计数器归零中断使能位。1:使能 PWMn 计数器归零中断 (n=0~5) */
#define setBitEPWMnCBI(PORT)  {if(PORT==0){PWMCFG01|=( EPWMCBI024);} \
                          else if(PORT==1){PWMCFG01|=( EPWMCBI135);} \
                          else if(PORT==2){PWMCFG23|=( EPWMCBI024);} \
                          else if(PORT==3){PWMCFG23|=( EPWMCBI135);} \
                          else if(PORT==4){PWMCFG45|=( EPWMCBI024);} \
                          else if(PORT==5){PWMCFG45|=( EPWMCBI135);}}

/* PWMn 波形发生器是否开始计数。(n=0~5) */
/* PWMn 波形发生器停止计数。(n=0~5) */
#define clrBitPWMnCEN(PORT)   {if(PORT==0){PWMCFG01&=(~PWMCEN024);} \
                          else if(PORT==1){PWMCFG01&=(~PWMCEN135);} \
                          else if(PORT==2){PWMCFG23&=(~PWMCEN024);} \
                          else if(PORT==3){PWMCFG23&=(~PWMCEN135);} \
                          else if(PORT==4){PWMCFG45&=(~PWMCEN024);} \
                          else if(PORT==5){PWMCFG45&=(~PWMCEN135);}}
/* PWMn 波形发生器开始计数。(n=0~5) */
#define setBitPWMnCEN(PORT)   {if(PORT==0){PWMCFG01|=( PWMCEN024);} \
                          else if(PORT==1){PWMCFG01|=( PWMCEN135);} \
                          else if(PORT==2){PWMCFG23|=( PWMCEN024);} \
                          else if(PORT==3){PWMCFG23|=( PWMCEN135);} \
                          else if(PORT==4){PWMCFG45|=( PWMCEN024);} \
                          else if(PORT==5){PWMCFG45|=( PWMCEN135);}}

/* ENPWMnTA:PWMn 是否与 ADC 关联。(n=0、2、4) */
/* ENPWMnTA:0:PWMn 与 ADC 不关联。 (n=0、2、4) */
#define clrBitENPWMnTA(PORT)  {if(PORT==0){PWMCFG01&=(~ENPWMTA024);} \
                          else if(PORT==2){PWMCFG23&=(~ENPWMTA024);} \
                          else if(PORT==4){PWMCFG45&=(~ENPWMTA024);}}
/* ENPWMnTA:1:PWMn 与 ADC 相关联。(n=0、2、4) */
#define setBitENPWMnTA(PORT)  {if(PORT==0){PWMCFG01|=( ENPWMTA024);} \
                          else if(PORT==2){PWMCFG23|=( ENPWMTA024);} \
                          else if(PORT==4){PWMCFG45|=( ENPWMTA024);}}

/* PWM 异常检测控制寄存器(PWMnFDCR) */
#define setRegPWMnFDCR(PORT, VALUE)              ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x06))) = VALUE

/* PWM 计数器寄存器(PWMnCH，PWMnCL) (n=0~5)
    可设定 1~32767 之间的任意值作为 PWMn 的周期。PWMn 波形发
    生器内部的计数器从 0 开始计数，每个 PWMn 时钟周期递增 1，
    当内部计数器的计数值达到 [PWMnCH，PWMnCL]所设定的 PWMn 周期时，
    PWMn 波形发生器内部的计数器将会从 0 重新开始计数，
    硬件会自动将 PWMn 归零中断中断标志位 PWMnCBIF 置 1，
    若 EPWMnCBI=1，程序将跳转到相应中断入口执行中断服务程序。
*/
#define setRegPWMnC(PORT, VALUE)                 ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x00))) = VALUE

/* PWM 时钟选择寄存器(PWMnCKS) (n=0~5) */
#define setRegPWMnCKS(PORT, VALUE)               ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x02))) = VALUE

/* PWM 触发 ADC 计数器寄存器(PWMnTADC) (n=0、2、4) */
#define setRegPWMnTADC(PORT, VALUE)              ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x03))) = VALUE

/*** CHANNEL单位设置 **************************************************************/
/* PWM 电平输出设置计数值寄存器 第一个点(PWMnT2) (n=0~5;i=0~7) */
#define setRegPWMniT1(PORT, CHANNEL, VALUE)      ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 0))) = VALUE
#define setRegPWMniT1H(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 0))) = VALUE
#define setRegPWMniT1L(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 1))) = VALUE
/* PWM 电平输出设置计数值寄存器 第二个点(PWMnT2) (n=0~5;i=0~7) */
#define setRegPWMniT2(PORT, CHANNEL, VALUE)      ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 2))) = VALUE
#define setRegPWMniT2H(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 2))) = VALUE
#define setRegPWMniT2L(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 3))) = VALUE

/* PWM 通道控制寄存器(PWMnCR) (n=0~5;i=0~7) */
#define setRegPWMniCR(PORT, CHANNEL, VALUE)      ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) = VALUE

/* PWMnCR.ENO:PWMni 输出使能位。
    1:第 n 路 PWM 的 i 通道相应 PWMni 端口为 PWM 输出口，受 PWMn 波形发生器控制 */
#define setBitPWMniEnableOut(PORT, CHANNEL)       ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENO)
/* PWMnCR.ENO:PWMni 输出使能位。
    0:第 n 路 PWM 的 i 通道相应 PWMni 端口为 GPIO */
#define clrBitPWMniEnableOut(PORT, CHANNEL)       ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENO)
/* PWMnCR.INI:设置 PWMni 输出端口的初始电平。(n=0~5，i=0~7)
    1:第 n 路 PWM 的 i 通道初始电平为高电平
*/
#define setBitPWMniStartLevel(PORT, CHANNEL)      ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( INI)
/* PWMnCR.INI:设置 PWMni 输出端口的初始电平。(n=0~5，i=0~7) 
    0:第 n 路 PWM 的 i 通道初始电平为低电平 */
#define clrBitPWMniStartLevel(PORT, CHANNEL)      ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~INI)
/* PWMnCR.ENI:第 n 路 PWM 的 i 通道中断使能控制位。(n=0~5，i=0~7)
    1:使能第 n 路 PWM 的 i 通道的 PWM 中断
*/
#define setBitPWMniEnableIntrupt(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENI)
/* PWMnCR.ENI:第 n 路 PWM 的 i 通道中断使能控制位。(n=0~5，i=0~7)
    0:关闭第 n 路 PWM 的 i 通道的 PWM 中断
*/
#define clrBitPWMniEnableIntrupt(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENI)
/* PWMnCR.ENT2I:第 n 路 PWM 的 i 通道在第 2 个触发点中断使能控制位。(n=0~5，i=0~7)
    1:使能第 n 路 PWM 的 i 通道在第 2 个触发点中断
*/
#define setBitPWMniEnableIntruptAtTrig2(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENT2I)
/* PWMnCR.ENT2I:第 n 路 PWM 的 i 通道在第 2 个触发点中断使能控制位。(n=0~5，i=0~7)
    0:关闭第 n 路 PWM 的 i 通道在第 2 个触发点中断
*/
#define clrBitPWMniEnableIntruptAtTrig2(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENT2I)
/* PWMnCR.ENT1I:第 n 路 PWM 的 i 通道在第 1 个触发点中断使能控制位。(n=0~5，i=0~7)
    1:使能第 n 路 PWM 的 i 通道在第 1 个触发点中断
*/
#define setBitPWMniEnableIntruptAtTrig1(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENT1I)
/* PWMnCR.ENT1I:第 n 路 PWM 的 i 通道在第 1 个触发点中断使能控制位。(n=0~5，i=0~7)
    0:关闭第 n 路 PWM 的 i 通道在第 1 个触发点中断
*/
#define clrBitPWMniEnableIntruptAtTrig1(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENT1I)

/* PWM通道电平保持控制寄存器(PWMnHLD) (n=0~5，i=0~7) */
#define setRegPWMniHLD(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 5))) = VALUE

/* PWM 中断标志寄存器(PWMnIF) PWMn 的第 i 通道中断标志位。(n=0~5;i=0~7) */
#define clrBitPWMniIF(PORT, CHANNEL)             ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x05))) &= (~(1<<CHANNEL))






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

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/
