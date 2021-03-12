/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_NVIC.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_NVIC.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: EXTI priority define function            |
--------------------------------------------------------*/

#define EXTI0_NVIC_PRI(pri) { \
IPH = (IPH & 0xFE) | ((pri & 0x02) >> 1); \
IP  = (IP  & 0xFE) | (pri & 0x01); }

#define EXTI1_NVIC_PRI(pri) { \
IPH = (IPH & 0xFB) | ((pri & 0x02) << 1); \
IP  = (IP  & 0xFB) | ((pri & 0x01) << 2); }

/*--------------------------------------------------------
| @Description: TIMER priority define function           |
--------------------------------------------------------*/

#define TIMER0_NVIC_PRI(pri) { \
IPH = (IPH & 0xFD) |  (pri & 0x02) ; \
IP  = (IP  & 0xFD) | ((pri & 0x01) << 1);}

#define TIMER1_NVIC_PRI(pri) { \
IPH = (IPH & 0xF7) | ((pri & 0x02) << 2); \
IP  = (IP  & 0xF7) | ((pri & 0x01) << 3); }

/*--------------------------------------------------------
| @Description: UART priority define function            |
--------------------------------------------------------*/

#define UART1_NVIC_PRI(pri) { \
IPH = (IPH & 0xEF) | ((pri & 0x02) << 3); \
IP  = (IP  & 0xEF) | ((pri & 0x01) << 4); }

#define UART2_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xFE) | ((pri & 0x02) >> 1); \
IP2  = (IP2  & 0xFE) | (pri & 0x01); }

#define UART3_NVIC_PRI(pri) { \
IP3H = (IP3H & 0xFE) | ((pri & 0x02) >> 1); \
IP3  = (IP3  & 0xFE) | (pri & 0x01); }

#define UART4_NVIC_PRI(pri) { \
IP3H = (IP3H & 0xFD) | (pri & 0x02); \
IP3  = (IP3  & 0xFD) | (pri & 0x01) << 1;}

/*--------------------------------------------------------
| @Description: COMP priority define function            |
--------------------------------------------------------*/

#define COMP_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xEF) | ((pri & 0x02) << 3); \
IP2  = (IP2  & 0xEF) | ((pri & 0x01) << 4); }

/*--------------------------------------------------------
| @Description: ADC priority define function             |
--------------------------------------------------------*/

#define ADC_NVIC_PRI(pri) { \
IPH = (IPH & 0xDF) | ((pri & 0x02) << 4); \
IP  = (IP  & 0xDF) | ((pri & 0x01) << 5); }

/*--------------------------------------------------------
| @Description: LVD priority define function             |
--------------------------------------------------------*/

#define LVD_NVIC_PRI(pri) { \
IPH = (IPH & 0xBF) | ((pri & 0x02) << 5); \
IP  = (IP  & 0xBF) | ((pri & 0x01) << 6); }

/*--------------------------------------------------------
| @Description: PCA priority define function             |
--------------------------------------------------------*/

#define PCA_NVIC_PRI(pri) { \
IPH = (IPH & 0x7F) | ((pri & 0x02) << 6); \
IP  = (IP  & 0x7F) | ((pri & 0x01) << 7); }

/*--------------------------------------------------------
| @Description: PWM priority define function             |
--------------------------------------------------------*/

#define PWM_CNT_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xFB) | ((pri & 0x02) << 1); \
IP2  = (IP2  & 0xFB) | ((pri & 0x01) << 2); }

#define PWM_ABD_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xF7) | ((pri & 0x02) << 2); \
IP2  = (IP2  & 0xF7) | ((pri & 0x01) << 3); }

/*--------------------------------------------------------
| @Description: SPI priority define function             |
--------------------------------------------------------*/

#define SPI_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xFD) |  (pri & 0x02); \
IP2  = (IP2  & 0xFD) | ((pri & 0x01) << 1); }

/*--------------------------------------------------------
| @Description: I2C priority define function             |
--------------------------------------------------------*/

#define I2C_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xBF) | ((pri & 0x02) << 5); \
IP2  = (IP2  & 0xBF) | ((pri & 0x01) << 6); }

/*--------------------------------------------------------
| @Description: COMP interrupt Trigger enum              |
--------------------------------------------------------*/

#define COMP_TRIState_Ctrl(triMode) CMPCR1 = (CMPCR1 & 0xCF)|(triMode)

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    EXTI0_TRIMode_Init
  * @brief   EXTI0 trigger mode function
  * @param   triMode   EXTI_Tri_Edge | EXTI_Tri_Falling
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE EXTI0_TRIMode_Init(EXTITri_Type triMode)
{
	IT0 = triMode;
	return FSC_SUCCESS;
}

/**
  * @name    EXTI1_TRIMode_Init
  * @brief   EXTI1 trigger mode function
  * @param   triMode   EXTI_Tri_Edge | EXTI_Tri_Falling
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE EXTI1_TRIMode_Init(EXTITri_Type triMode)
{
	IT1 = triMode;
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI0_Init
  * @brief   EXTI0 NVIC function  
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI0_Init(NVICPri_Type priority,FUNSTATE run)
{
	EX0 = run;
    EXTI0_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI1_Init
  * @brief   EXTI1 NVIC function  
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI1_Init(NVICPri_Type priority,FUNSTATE run)
{
	EX1 = run;
    EXTI1_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI2_Init
  * @brief   EXTI2 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI2_Init(FUNSTATE run)
{
	INTCLKO = (INTCLKO & 0xEF) | (run << 4);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI3_Init
  * @brief   EXTI3 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI3_Init(FUNSTATE run)
{

	INTCLKO = (INTCLKO & 0xDF) | (run << 5);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_EXTI4_Init
  * @brief   EXTI4 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_EXTI4_Init(FUNSTATE run)
{
	INTCLKO = (INTCLKO & 0xBF) | (run << 6);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_TIMER0_Init
  * @brief   TIMER0 NVIC function  
  * @param   priority  NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run       ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_TIMER0_Init(NVICPri_Type priority,FUNSTATE run)
{
	ET0 = run;
    TIMER0_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_TIMER1_Init
  * @brief   TIMER1 NVIC function  
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_TIMER1_Init(NVICPri_Type priority,FUNSTATE run)
{
	ET1 = run;
    TIMER1_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_TIMER2_Init
  * @brief   TIMER2 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_TIMER2_Init(FUNSTATE run)
{
	IE2 = (IE2 & 0xFB) | (run << 2);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_TIMER3_Init
  * @brief   TIMER3 NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_TIMER3_Init(FUNSTATE run)
{
	IE2 = (IE2 & 0xDF) | (run << 5);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_TIMER4_Init
  * @brief   TIMER4 NVIC function  
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_TIMER4_Init(FUNSTATE run)
{
	IE2 = (IE2 & 0xBF) | (run << 6);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_UART1_Init
  * @brief   UART1 NVIC function  
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_UART1_Init(NVICPri_Type priority,FUNSTATE run)
{
	ES = run;
	UART1_NVIC_PRI(priority); 
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_UART2_Init
  * @brief   UART2 NVIC function  
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_UART2_Init(NVICPri_Type priority,FUNSTATE run)
{
	IE2 = (IE2 & 0xFE) | (run);
    UART2_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
/**
  * @name    NVIC_UART3_Init
  * @brief   UART3 NVIC function  
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_UART3_Init(FUNSTATE run)
{
	IE2 = (IE2 & 0xF7) | (run << 3);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_UART4_Init
  * @brief   UART4 NVIC function  
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_UART4_Init(FUNSTATE run)
{
	IE2 = (IE2 & 0xEF) | (run << 4);
	return FSC_SUCCESS;
}

#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

/**
  * @name    NVIC_UART3_Init
  * @brief   UART3 NVIC function  
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_UART3_Init(NVICPri_Type priority,FUNSTATE run)
{
	IE2 = (IE2 & 0xF7) | (run << 3);
    UART3_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_UART4_Init
  * @brief   UART4 NVIC function  
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_UART4_Init(NVICPri_Type priority,FUNSTATE run)
{
	IE2 = (IE2 & 0xEF) | (run << 4);
    UART4_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

#endif
/**
  * @name    NVIC_COMP_Init
  * @brief   COMP NVIC function
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   triMode    COMP_Tri_None | COMP_Tri_Falling | COMP_Tri_Rising | COMP_Tri_Edge
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_COMP_Init(NVICPri_Type priority,COMPTri_Type triMode)
{
	COMP_TRIState_Ctrl(triMode);
	COMP_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

/**
  * @name    NVIC_ADC_Init
  * @brief   ADC NVIC function
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_ADC_Init(NVICPri_Type priority,FUNSTATE run)
{
	EADC = run;
	ADC_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

#endif
/**
  * @name    NVIC_LVD_Init
  * @brief   LVD NVIC function
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_LVD_Init(NVICPri_Type priority,FUNSTATE run)
{
	ELVD = run;
	LVD_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx)

/**
  * @name    NVIC_PCA_CNT_Init
  * @brief   PCA Counter NVIC function
  * @param   priority NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA_CNT_Init(NVICPri_Type priority,FUNSTATE run)
{
	CMOD = (CMOD & 0xFE) | run;
	PCA_NVIC_PRI(priority);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PCA0_TIM_POP_Init
  * @brief   PCA0 Timer and POP NVIC function 
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA0_TIM_POP_Init(FUNSTATE run)
{
	CCAPM0 = (CCAPM0 & 0xFE) | (run);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PCA1_TIM_POP_Init
  * @brief   PCA1 Timer and POP NVIC function  
  * @param   run    ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA1_TIM_POP_Init(FUNSTATE run)
{
	CCAPM1 = (CCAPM1 & 0xFE) | (run);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PCA2_TIM_POP_Init
  * @brief   PCA2 Timer and POP NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA2_TIM_POP_Init(FUNSTATE run)
{
	CCAPM2 = (CCAPM2 & 0xFE) | (run);
	return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)

/**
  * @name    NVIC_PCA3_TIM_POP_Init
  * @brief   PCA3 Timer and POP NVIC function  
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA3_TIM_POP_Init(FUNSTATE run)
{
	CCAPM3 = (CCAPM3 & 0xFE) | (run);
	return FSC_SUCCESS;
}

#endif

/**
  * @name    NVIC_PCA0_PWM_CAP_Init
  * @brief   PCA0 Timer and POP NVIC function  
  * @param   triMode    PCA_Tri_None   | PCA_Tri_Falling 
  *                     PCA_Tri_Rising | PCA_Tri_Edge
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA0_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run)
{
	CCAPM0 = (CCAPM0 & 0xCE) | (triMode) | (run);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PCA1_PWM_CAP_Init
  * @brief   PCA1 Timer and POP NVIC function  
  * @param   triMode    PCA_Tri_None   | PCA_Tri_Falling 
  *                     PCA_Tri_Rising | PCA_Tri_Edge
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA1_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run)
{
	CCAPM1 = (CCAPM1 & 0xCE) | (triMode) | (run);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PCA2_PWM_CAP_Init
  * @brief   PCA2 Timer and POP NVIC function  
  * @param   triMode    PCA_Tri_None   | PCA_Tri_Falling 
  *                     PCA_Tri_Rising | PCA_Tri_Edge
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA2_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run)
{
	CCAPM2 = (CCAPM2 & 0xCE) | (triMode) | (run);
	return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)

/**
  * @name    NVIC_PCA3_PWM_CAP_Init
  * @brief   PCA3 Timer and POP NVIC function  
  * @param   triMode    PCA_Tri_None   | PCA_Tri_Falling 
  *                     PCA_Tri_Rising | PCA_Tri_Edge
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PCA3_PWM_CAP_Init(PCATri_Type triMode,FUNSTATE run)
{
	CCAPM3 = (CCAPM3 & 0xCE) | (triMode) | (run);
	return FSC_SUCCESS;
}

#endif

#endif

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    NVIC_PWM_CNT_Init
  * @brief   PWM CNT return to zero NVIC function 
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM_CNT_Init(NVICPri_Type priority,FUNSTATE run)
{
	PWM_CNT_NVIC_PRI(priority);
	PWMCR = (PWMCR & 0xBF) | (run << 6);
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM_ABD_Init
  * @brief   PWM abnormal detection NVIC function 
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM_ABD_Init(NVICPri_Type priority,FUNSTATE run)
{
	EAXFR_ENABLE();
	PWM_ABD_NVIC_PRI(priority);
	PWMFDCR = (PWMFDCR & 0xF7) | (run << 3);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM0_Init
  * @brief   PWM0 road flip NVIC function 
  * @param   flipMode    PWM_Flip_None   | PWM_Flip_First
  *                      PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM0_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM1_Init
  * @brief   PWM1 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM1_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM2_Init
  * @brief   PWM2 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM2_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM3_Init
  * @brief   PWM3 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM3_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM4_Init
  * @brief   PWM4 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM4_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM5_Init
  * @brief   PWM5 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM5_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM6_Init
  * @brief   PWM6 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM6_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVIC_PWM7_Init
  * @brief   PWM7 road flip NVIC function 
  * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
  *                       PWM_Flip_Second | PWM_Flip_Both
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_PWM7_Init(PWMFlip_Type flipMode)
{
	EAXFR_ENABLE();
	PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xF8) | (flipMode);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}
#endif
/**
  * @name    NVIC_SPI_Init
  * @brief   SPI init NVIC function 
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_SPI_Init(NVICPri_Type priority,FUNSTATE run)
{
	SPI_NVIC_PRI(priority);
	IE2 = (IE2 & 0xFD) | (run << 1);
	return FSC_SUCCESS;
}

/**
  * @name    NVCI_I2C_Master_Init
  * @brief   I2C Master init NVIC function
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type priority,FUNSTATE run)
{
	EAXFR_ENABLE();
	I2C_NVIC_PRI(priority);
	I2CMSCR = run << 7;
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/**
  * @name    NVCI_I2C_Slave_Init
  * @brief   I2C Slave init NVIC function
  * @param   priority    NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   triState    I2C_STri_RevStart_Done | I2C_STri_RevData_Done
  *                      I2C_STri_SendData_Done | I2C_STri_RevStop_Done 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type priority,I2CSTri_Type triState)
{
	EAXFR_ENABLE();
	I2C_NVIC_PRI(priority);
	I2CSLCR &= (I2CSLCR & 0x01 )| (triState);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



