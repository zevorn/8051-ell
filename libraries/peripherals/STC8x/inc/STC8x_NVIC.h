/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_NVIC.h
  - Author        : zeweni
  - Update date   : 2020.01.29
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote NVIC chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *
  *  2020.01.11         zeweni       Update code comment format.
  * 
  *  2020.01.29         zeweni       Optimize library architecture.
  *
***/

#ifndef __STC8x_NVIC_H_
#define __STC8x_NVIC_H_
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
| @Description: Interrupt priority                       |
--------------------------------------------------------*/

typedef enum
{
  NVIC_PR0  =  0x00,  //Lowest  priority |
  NVIC_PR1  =  0x01,  //Lower   priority |
  NVIC_PR2  =  0x02,  //Higher  priority |
  NVIC_PR3  =  0x03   //Highest priority V
} NVICPri_Type;

/*--------------------------------------------------------
| @Description: External interrupt Trigger define        |
--------------------------------------------------------*/

typedef enum
{
  EXTI_Tri_Edge    = 0x00,  //Both rising and falling edges triggered
  EXTI_Tri_Falling = 0x01    //Falling edge trigger
} EXTITri_Type;

/*--------------------------------------------------------
| @Description: COMP interrupt Trigger enum              |
--------------------------------------------------------*/

typedef enum
{
  COMP_Tri_Null    = 0x00,
  COMP_Tri_Falling = 0x10,
  COMP_Tri_Rising  = 0x20,
  COMP_Tri_Edge    = 0x30
} COMPTri_Type;

/*--------------------------------------------------------
| @Description: COMP interrupt Trigger enum              |
--------------------------------------------------------*/

typedef enum
{
  PCA_Tri_Null    = 0x00,
  PCA_Tri_Falling = 0x10,
  PCA_Tri_Rising  = 0x20,
  PCA_Tri_Edge    = 0x30
} PCATri_Type;

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

/*--------------------------------------------------------
| @Description: I2C slave interrupt Trigger enum         |
--------------------------------------------------------*/

typedef enum
{
  I2C_STri_RevStart_Done  = 0x40,
  I2C_STri_RevData_Done   = 0x20,
  I2C_STri_SendData_Done  = 0x10,
  I2C_STri_RevStop_Done   = 0x80
} I2CSTri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Global interrupt switch define           |
--------------------------------------------------------*/

#define    NVIC_GLOBAL_ENABLE()     EA = 1
#define    NVIC_GLOBAL_DISABLE()    EA = 0

/*--------------------------------------------------------
| @Description: EXTI ISR define                          |
--------------------------------------------------------*/

#define	 EXTI0_ISRQ_Handler(void)  EXTI0_ISR(void) interrupt   0  
#define	 EXTI1_ISRQ_Handler(void)  EXTI1_ISR(void) interrupt	 2 
#define	 EXTI2_ISRQ_Handler(void)  EXTI2_ISR(void) interrupt	10 	
#define	 EXTI3_ISRQ_Handler(void)  EXTI3_ISR(void) interrupt	11 	
#define	 EXTI4_ISRQ_Handler(void)  EXTI4_ISR(void) interrupt	16 	

FSCSTATE EXTI0_TRIMode_Init(EXTITri_Type triMode);
FSCSTATE EXTI1_TRIMode_Init(EXTITri_Type triMode);

FSCSTATE NVIC_EXTI0_Init(NVICPri_Type priority,FUNSTATE run);
FSCSTATE NVIC_EXTI1_Init(NVICPri_Type priority,FUNSTATE run);
FSCSTATE NVIC_EXTI2_Init(FUNSTATE run);
FSCSTATE NVIC_EXTI3_Init(FUNSTATE run);
FSCSTATE NVIC_EXTI4_Init(FUNSTATE run);

/*--------------------------------------------------------
| @Description: TIMER ISR define                         |
--------------------------------------------------------*/

#define TIMER0_ISRQ_Handler(void)  TIMER0_ISR(void) interrupt  1
#define TIMER1_ISRQ_Handler(void)  TIMER1_ISR(void) interrupt  3
#define TIMER2_ISRQ_Handler(void)  TIMER2_ISR(void) interrupt 12
#define TIMER3_ISRQ_Handler(void)  TIMER3_ISR(void) interrupt 19
#define TIMER4_ISRQ_Handler(void)  TIMER4_ISR(void) interrupt 20

#define    TIMER2_CLEAR_FLAG()    AUXINTIF &= 0xFE
#define    TIMER3_CLEAR_FLAG()    AUXINTIF &= 0xFD
#define    TIMER4_CLEAR_FLAG()    AUXINTIF &= 0xFB

FSCSTATE NVIC_TIMER0_Init(NVICPri_Type priority,FUNSTATE run);
FSCSTATE NVIC_TIMER1_Init(NVICPri_Type priority,FUNSTATE run);
FSCSTATE NVIC_TIMER2_Init(FUNSTATE run);
FSCSTATE NVIC_TIMER3_Init(FUNSTATE run);
FSCSTATE NVIC_TIMER4_Init(FUNSTATE run);

/*--------------------------------------------------------
| @Description: UART ISR define                          |
--------------------------------------------------------*/

#define UART1_ISRQ_Handler(void)  UART1_ISR(void) interrupt  4
#define UART2_ISRQ_Handler(void)  UART2_ISR(void) interrupt  8
#define UART3_ISRQ_Handler(void)  UART3_ISR(void) interrupt 17
#define UART4_ISRQ_Handler(void)  UART4_ISR(void) interrupt 18

#define    UART1_GET_RX_FLAG()    (SCON  & 0x01)
#define    UART2_GET_RX_FLAG()    (S2CON & 0x01)
#define    UART3_GET_RX_FLAG()    (S3CON & 0x01)
#define    UART4_GET_RX_FLAG()    (S4CON & 0x01)
				   		    
#define    UART1_GET_TX_FLAG()    (SCON  & 0x02)
#define    UART2_GET_TX_FLAG()    (S2CON & 0x02)
#define    UART3_GET_TX_FLAG()    (S3CON & 0x02)
#define    UART4_GET_TX_FLAG()    (S4CON & 0x02)

#define	   UART1_CLEAR_RX_FLAG()  SCON  &= ~0x01
#define	   UART2_CLEAR_RX_FLAG()  S2CON &= ~0x01
#define	   UART3_CLEAR_RX_FLAG()  S3CON &= ~0x01
#define	   UART4_CLEAR_RX_FLAG()  S4CON &= ~0x01
   
#define	   UART1_CLEAR_TX_FLAG()  SCON  &= ~0x02
#define	   UART2_CLEAR_TX_FLAG()  S2CON &= ~0x02
#define	   UART3_CLEAR_TX_FLAG()  S3CON &= ~0x02
#define	   UART4_CLEAR_TX_FLAG()  S4CON &= ~0x02

FSCSTATE NVIC_UART1_Init(NVICPri_Type priority,FUNSTATE run);
FSCSTATE NVIC_UART2_Init(NVICPri_Type priority,FUNSTATE run);

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)

	FSCSTATE NVIC_UART3_Init(FUNSTATE run);
	FSCSTATE NVIC_UART4_Init(FUNSTATE run);

#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

	FSCSTATE NVIC_UART3_Init(NVICPri_Type priority,FUNSTATE run);
	FSCSTATE NVIC_UART4_Init(NVICPri_Type priority,FUNSTATE run);

#endif
/*--------------------------------------------------------
| @Description: COMP ISR define                          |
--------------------------------------------------------*/

#define COMP_ISRQ_Handler(void)  COMP_ISR(void) interrupt  21

#define COMP_GET_FLAG()        (CMPCR1 &= 0x40)
#define COMP_CLEAR_FLAG()        CMPCR1 &= 0xBF
#define COMP_GET_RES()          (CMPCR1 & 0x01)

FSCSTATE NVIC_COMP_Init(NVICPri_Type priority,COMPTri_Type triMode);

/*--------------------------------------------------------
| @Description: ADC ISR define                           |
--------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

    #define ADC_ISRQ_Handler(void)  ADC_ISR(void) interrupt  5

    #define ADC_GET_FLAG()       (ADC_CONTR & 0x20)
    #define ADC_CLEAR_FLAG()      ADC_CONTR &= 0xDF

    FSCSTATE NVIC_ADC_Init(NVICPri_Type priority,FUNSTATE run);
	
#endif
/*--------------------------------------------------------
| @Description: LVD ISR define                           |
--------------------------------------------------------*/

#define LVD_ISRQ_Handler(void)  LVD_ISR(void) interrupt  6

#define LVD_GET_FLAG()       (PCON & 0x20)
#define LVD_CLEAR_FLAG()      PCON &= 0xDF

FSCSTATE NVIC_LVD_Init(NVICPri_Type priority,FUNSTATE run);

/*--------------------------------------------------------
| @Description: PCA ISR define                           |
--------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx)

    #define PCA_ISRQ_Handler(void)  PCA_ISR(void) interrupt  7
    
    #define PCA_CNT_GET_FLAG()      CF
    #define PCA_CNT_CLEAR_FLAG()    CF = 0
    
    #define PCA0_GET_FLAG()           CCF0
    #define PCA1_GET_FLAG()           CCF1
    #define PCA2_GET_FLAG()           CCF2
    #define PCA3_GET_FLAG()           CCF3
    
    #define PCA0_CLEAR_FLAG()     CCF0 = 0
    #define PCA1_CLEAR_FLAG()     CCF1 = 0
    #define PCA2_CLEAR_FLAG()     CCF2 = 0
    #define PCA3_CLEAR_FLAG()     CCF3 = 0
    
    FSCSTATE NVIC_PCA_CNT_Init(NVICPri_Type priority,FUNSTATE run);
    
    FSCSTATE NVIC_PCA0_TIM_POP_Init(FUNSTATE run);
    FSCSTATE NVIC_PCA1_TIM_POP_Init(FUNSTATE run);
    FSCSTATE NVIC_PCA2_TIM_POP_Init(FUNSTATE run);
    FSCSTATE NVIC_PCA3_TIM_POP_Init(FUNSTATE run);
    
    FSCSTATE NVIC_PCA0_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run);
    FSCSTATE NVIC_PCA1_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run);
    FSCSTATE NVIC_PCA2_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run);
    FSCSTATE NVIC_PCA3_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run);
	
#endif
/*--------------------------------------------------------
| @Description: PWM ISR define                           |
--------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Ax )

    #define PWM_ISRQ_Handler(void)          PWM_ISR(void) interrupt 22
    #define PWM_ABD_ISRQ_Handler(void)  PWM_ABD_ISR(void) interrupt 23
    
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
    
    FSCSTATE NVIC_PWM_CNT_Init(NVICPri_Type priority,FUNSTATE run);
    FSCSTATE NVIC_PWM_ABD_Init(NVICPri_Type priority,FUNSTATE run);
    FSCSTATE NVIC_PWM0_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM1_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM2_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM3_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM4_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM5_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM6_Init(PWMFlip_Type flipMode);
    FSCSTATE NVIC_PWM7_Init(PWMFlip_Type flipMode);
	
#endif

/*--------------------------------------------------------
| @Description: SPI ISR define                           |
--------------------------------------------------------*/

#define SPI_ISRQ_Handler(void)          SPI_ISR(void) interrupt 9

#define SPI_GET_FLAG()                  (SPSTAT & 0x80)
#define SPI_CLEAR_FLAG()                 SPSTAT = 0xC0

FSCSTATE NVIC_SPI_Init(NVICPri_Type priority,FUNSTATE run);

/*--------------------------------------------------------
| @Description: I2C ISR define                           |
--------------------------------------------------------*/

#define I2C_ISRQ_Handler(void)          I2C_ISR(void) interrupt 24

#define I2C_GET_MASTER_FLAG()           (I2CMSST & 0x40)
#define I2C_GET_REVSTART_FLAG()         (I2CMLST & 0x40)
#define I2C_GET_REVDATA_FLAG()          (I2CMLST & 0x20)
#define I2C_GET_SENDATA_FLAG()          (I2CMLST & 0x10)
#define I2C_GET_REVSTOP_FLAG()          (I2CMLST & 0x08)

#define I2C_CLEAR_MASTER_FLAG()          I2CMSST &= 0xBF
#define I2C_CLEAR_REVSTART_FLAG()        I2CMLST &= 0xBF
#define I2C_CLEAR_REVDATA_FLAG()         I2CMLST &= 0xDF
#define I2C_CLEAR_SENDATA_FLAG()         I2CMLST &= 0xEF
#define I2C_CLEAR_REVSTOP_FLAG()         I2CMLST &= 0xF7

FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type priority,FUNSTATE run);
FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type priority,I2CSTri_Type triMode);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

