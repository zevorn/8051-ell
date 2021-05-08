/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
  - File name      : STC8x_CORE.h
  - Author         : Quark Team
  - Update date    : 2020.12.20                   
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Header file of MCU core.
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
 * Apache-2.0 License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_CORE_H_
#define __STC8x_CORE_H_

#include "Lib_CFG.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/**
  * @name    BOOL
  * @brief   功能状态枚举体，常用于指示硬件的某个寄存器工作状态。
  *          Function state enumerator is often used to 
  *          indicate the working state of a register of hardware.
  * @param   DISABLE  [0] 未使能。 Not enabled.
  * @param   ENABLE   [1] 使能。 enabled.
***/
typedef enum 
{
	DISABLE = 0, 
	ENABLE = !DISABLE
} BOOL;


/**
  * @name    FSCSTATE
  * @brief   函数自检枚举体，指示函数是否正常执行。
  *          Function self checks enumerator. 
  *          indicating whether the function is normally executed.
  * @param   FSC_SUCCESS  [0] 函数执行成功。 Function executed successfully.
  * @param   FSC_FAIL     [1] 函数执行失败。 Function executed failed.
***/
typedef enum
{
    FSC_FAIL= 1, /* Function self checking failed */
    FSC_SUCCESS = !FSC_FAIL /* Function self checking successfed */ 
}   FSCSTATE; 


/**
  * @name    GPIOSWPort_Type
  * @brief   外设复用GPIO切换枚举体。
  *          Peripheral IO define. 
  * @param   SW_Port1  [uint8_t] 切换第一组IO。 Switch the first group io.
  * @param   SW_Port2  [uint8_t] 切换第二组IO。 Switch the second group io.
  * @param   SW_Port3  [uint8_t] 切换第三组IO。 Switch the third group io.
  * @param   SW_Port4  [uint8_t] 切换第四组IO。 Switch the fouth group io.
***/
typedef enum
{
	SW_Port1 = 0x00 ,
	SW_Port2 = 0x01 ,
	SW_Port3 = 0x02 ,
	SW_Port4 = 0x03 
}   GPIOSWPort_Type;


/**
  * @name    NVICPri_Type
  * @brief   中断管理优先级枚举体。
  *          Interrupt management priority enumeration body.
  * @param   NVIC_PR0  [uint8_t] 优先级0。 Priority 0.
  * @param   NVIC_PR1  [uint8_t] 优先级1。 Priority 1.
  * @param   NVIC_PR2  [uint8_t] 优先级2。 Priority 2.
  * @param   NVIC_PR3  [uint8_t] 优先级3。 Priority 3.
***/
typedef enum
{
  NVIC_PR0  =  0x00,  //Lowest  priority |
  NVIC_PR1  =  0x01,  //Lower   priority |
  NVIC_PR2  =  0x02,  //Higher  priority |
  NVIC_PR3  =  0x03   //Highest priority V
} NVICPri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

extern void      _nop_     (void);

/*--------------------------------------------------------
| @Description: Global interrupt switch define           |
--------------------------------------------------------*/

/**
  * @name    NVIC_GLOBAL_ENABLE
  * @brief   使能总中断。
  *          Enable total interrupt.
***/
#define    NVIC_GLOBAL_ENABLE()     do{_nop_();EA = 1;_nop_();}while(0)


/**
  * @name    NVIC_GLOBAL_DISABLE
  * @brief   不使能总中断。
  *          Disable total interrupt.
***/
#define    NVIC_GLOBAL_DISABLE()    do{_nop_();EA = 0;_nop_();}while(0)

/*-----------------------------------------------------------------------
|                         ISR FUNCTION(Public STC)                      |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: EXTI ISR define                          |
--------------------------------------------------------*/

#define	 EXTI0_ISRQ_Handler(void)  EXTI0_ISR(void) interrupt   0  
#define	 EXTI1_ISRQ_Handler(void)  EXTI1_ISR(void) interrupt	 2 
#define	 EXTI2_ISRQ_Handler(void)  EXTI2_ISR(void) interrupt	10 	
#define	 EXTI3_ISRQ_Handler(void)  EXTI3_ISR(void) interrupt	11 	
#define	 EXTI4_ISRQ_Handler(void)  EXTI4_ISR(void) interrupt	16 	

/*--------------------------------------------------------
| @Description: TIMER ISR define                         |
--------------------------------------------------------*/

#define TIMER0_ISRQ_Handler(void)  TIMER0_ISR(void) interrupt  1
#define TIMER1_ISRQ_Handler(void)  TIMER1_ISR(void) interrupt  3
#define TIMER2_ISRQ_Handler(void)  TIMER2_ISR(void) interrupt 12
#define TIMER3_ISRQ_Handler(void)  TIMER3_ISR(void) interrupt 19
#define TIMER4_ISRQ_Handler(void)  TIMER4_ISR(void) interrupt 20

/*--------------------------------------------------------
| @Description: UART ISR define                          |
--------------------------------------------------------*/

#define UART1_ISRQ_Handler(void)  UART1_ISR(void) interrupt  4
#define UART2_ISRQ_Handler(void)  UART2_ISR(void) interrupt  8
#define UART3_ISRQ_Handler(void)  UART3_ISR(void) interrupt 17
#define UART4_ISRQ_Handler(void)  UART4_ISR(void) interrupt 18

/*--------------------------------------------------------
| @Description: SPI ISR define                           |
--------------------------------------------------------*/

#define SPI_ISRQ_Handler(void)          SPI_ISR(void) interrupt 9

/*--------------------------------------------------------
| @Description: COMP ISR define                          |
--------------------------------------------------------*/

#define COMP_ISRQ_Handler(void)  COMP_ISR(void) interrupt  21

/*--------------------------------------------------------
| @Description: I2C ISR define                           |
--------------------------------------------------------*/

#define I2C_ISRQ_Handler(void)          I2C_ISR(void) interrupt 24

/*--------------------------------------------------------
| @Description: LVD ISR define                           |
--------------------------------------------------------*/

#define LVD_ISRQ_Handler(void)  LVD_ISR(void) interrupt  6


/*-----------------------------------------------------------------------
|                          ISR FUNCTION(STC8x)                          |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: ADC ISR define                           |
--------------------------------------------------------*/

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    #define ADC_ISRQ_Handler(void)  ADC_ISR(void) interrupt  5

#endif
	
/*--------------------------------------------------------
| @Description: PCA ISR define                           |
--------------------------------------------------------*/

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx)

    #define PCA_ISRQ_Handler(void)  PCA_ISR(void) interrupt  7
    
#endif

/*--------------------------------------------------------
| @Description: PWM ISR define                           |
--------------------------------------------------------*/

#if (PER_LIB_MCU_MUODEL == STC8Ax)

    #define PWM_ISRQ_Handler(void)          PWM_ISR(void) interrupt 22
    #define PWM_ABD_ISRQ_Handler(void)  PWM_ABD_ISR(void) interrupt 23
    
#endif















#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/
