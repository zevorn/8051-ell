/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_PCA.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_PCA.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx )

static vuint16_t PCA_Value[4];
static vuint16_t PCA_Rvalue[4];
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    PCA_CNT_Init
  * @brief   PCA0 counter init function,It must be initialized last
  * @param   clkSrc   PCA_SCLK_DIV_1 | PCA_SCLK_DIV_2 | PCA_SCLK_DIV_4
  *                   PCA_SCLK_DIV_6 | PCA_SCLK_DIV_8 | PCA_SCLK_DIV_12
  *                   PCA_TIMER0     | PCA_ECI
  * @param   run      ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA_CNT_Init(PCACLKSrc_Type clkSrc,FUNSTATE run) 
{
    CMOD = (CMOD & 0xF1)|(clkSrc);
    CL = 0;
    CH = 0;
    CR = run;
    return FSC_SUCCESS;
}

/**
  * @name    PCA0_PWM_Init
  * @brief   PCA0 PWM init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA0_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
{
    CCAPM0 = PCA_TYPE_PWM;
    PCA_PWM0 = (PCA_PWM0 & 0x3F)|(pwmBits << 6);
		if(pwmBits == PCA_PWM_6Bits)
		{
			PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x40) >> 6); //EPC0L
			PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x40) >> 5); //EPC0H			
			CCAP0L = (uint8_t)(duty & 0x003F);
			CCAP0H = (uint8_t)(duty & 0x003F);
		}
		else if(pwmBits == PCA_PWM_7Bits)
		{
			PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x80) >> 7); //EPC0L
			PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x80) >> 6); //EPC0H			
			CCAP0L = (uint8_t)(duty & 0x007F);
			CCAP0H = (uint8_t)(duty & 0x007F);		 		
		}
		else if(pwmBits == PCA_PWM_8Bits)
		{	
			PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x100) >> 8); //EPC0L
			PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x100) >> 7); //EPC0H			
			CCAP0L = (uint8_t)duty;
			CCAP0H = (uint8_t)duty;		 					
		}
		else if(pwmBits == PCA_PWM_10Bits)
		{
			PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x400) >> 10); //EPC0L
			PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x400) >> 9); //EPC0H					
			PCA_PWM0 = (PCA_PWM0 & 0XF3) | ((duty & 0x300) >> 6); //XCCAP0L
			PCA_PWM0 = (PCA_PWM0 & 0XCF) | ((duty & 0x300) >> 4); //XCCAP0H	
			CCAP0L = (uint8_t)duty;
			CCAP0H = (uint8_t)duty;		 					
		}
		else  return FSC_FAIL;
			
    return FSC_SUCCESS;
}

/**
  * @name    PCA1_PWM_Init
  * @brief   PCA1 PWM init function,it must first is initialized
  * @param   pwmBits | PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty    | duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA1_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
{
    CCAPM1 = PCA_TYPE_PWM;
    PCA_PWM1 = (PCA_PWM1 & 0x3F)|(pwmBits << 6);
    if(pwmBits == PCA_PWM_6Bit)
	{
		PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x40) >> 6); //EPC0L
		PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x40) >> 5); //EPC0H			
        CCAP1L = (uint8_t)(duty & 0x003F);
        CCAP1H = (uint8_t)(duty & 0x003F);	 
	}
	else if(pwmBits == PCA_PWM_7Bit)
	{
		PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x80) >> 7); //EPC0L
		PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x80) >> 6); //EPC0H			
		CCAP1L = (uint8_t)(duty & 0x007F);
        CCAP1H = (uint8_t)(duty & 0x007F);
	}
	else if(pwmBits == PCA_PWM_8Bit)
	{	
		PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x100) >> 8); //EPC0L
		PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x100) >> 7); //EPC0H			
		CCAP1L = (uint8_t)duty;
		CCAP1H = (uint8_t)duty;
	}
	else if(pwmBits == PCA_PWM_10Bit)
	{
		PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x400) >> 10); //EPC0L
		PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x400) >> 9); //EPC0H					
		PCA_PWM1 = (PCA_PWM1 & 0XF3) | ((duty & 0x300) >> 6); //XCCAP0L
		PCA_PWM1 = (PCA_PWM1 & 0XCF) | ((duty & 0x300) >> 4); //XCCAP0H	
		CCAP1L = (uint8_t)duty;
		CCAP1H = (uint8_t)duty;		 					
	}
	else  return FSC_FAIL;
			
    return FSC_SUCCESS;
}

/**
  * @name    PCA2_PWM_Init
  * @brief   PCA2 PWM init function,it must first is initialized
  * @param   pwmBits | PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty    | duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA2_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
{
    CCAPM2 = PCA_TYPE_PWM;
    PCA_PWM2 = (PCA_PWM2 & 0x3F)|(pwmBits << 6);
	if(pwmBits == PCA_PWM_6Bit)
	{
		PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x40) >> 6); //EPC0L
		PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x40) >> 5); //EPC0H			
        CCAP2L = (uint8_t)(duty & 0x003F);
        CCAP2H = (uint8_t)(duty & 0x003F);	 
	}
	else if(pwmBits == PCA_PWM_7Bit)
	{
		PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x80) >> 7); //EPC0L
		PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x80) >> 6); //EPC0H			
        CCAP2L = (uint8_t)(duty & 0x007F);
        CCAP2H = (uint8_t)(duty & 0x007F);	 		
	}
	else if(pwmBits == PCA_PWM_8Bit)
	{	
		PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x100) >> 8); //EPC0L
		PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x100) >> 7); //EPC0H			
		CCAP2L = (uint8_t)duty;
		CCAP2H = (uint8_t)duty;		 					
	}
	else if(pwmBits == PCA_PWM_10Bit)
	{
		PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x400) >> 10); //EPC0L
		PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x400) >> 9); //EPC0H					
		PCA_PWM2 = (PCA_PWM2 & 0XF3) | ((duty & 0x300) >> 6); //XCCAP0L
		PCA_PWM2 = (PCA_PWM2 & 0XCF) | ((duty & 0x300) >> 4); //XCCAP0H	
		CCAP2L = (uint8_t)duty;
		CCAP2H = (uint8_t)duty;		 					
	}
	else  return FSC_FAIL;
			
    return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    PCA3_PWM_Init
  * @brief   PCA3 PWM init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA3_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
{
    CCAPM3 = PCA_TYPE_PWM;
    PCA_PWM3 = (PCA_PWM3 & 0x3F)|(pwmBits << 6);
	if(pwmBits == PCA_PWM_6Bit)
	{
		PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0040) >> 6); //EPC0L
		PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0040) >> 5); //EPC0H			
        CCAP3L = (uint8_t)(duty & 0x003F);
        CCAP3H = (uint8_t)(duty & 0x003F);	 	 
	}
	else if(pwmBits == PCA_PWM_7Bit)
	{
		PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0080) >> 7); //EPC0L
		PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0080) >> 6); //EPC0H			
        CCAP2L = (uint8_t)(duty & 0x007F);
        CCAP2H = (uint8_t)(duty & 0x007F);	 
	}
	else if(pwmBits == PCA_PWM_8Bit)
	{	
		PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0100) >> 8); //EPC0L
		PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0100) >> 7); //EPC0H			
		CCAP3L = (uint8_t)duty;
		CCAP3H = (uint8_t)duty;
	}
	else if(pwmBits == PCA_PWM_10Bit)
	{
		PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0400) >> 10); //EPC0L
		PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0400) >> 9); //EPC0H					
		PCA_PWM3 = (PCA_PWM3 & 0XF3) | ((duty & 0x0300) >> 6); //XCCAP0L
		PCA_PWM3 = (PCA_PWM3 & 0XCF) | ((duty & 0x0300) >> 4); //XCCAP0H	
		CCAP3L = (uint8_t)duty;
		CCAP3H = (uint8_t)duty;		 					
	}
	else  return FSC_FAIL;

    return FSC_SUCCESS;
}
#endif

/**
  * @name    PCA0_TIM_Init
  * @brief   PCA0 TIMER init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA0_TIM_Init(uint16_t value) 
{
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    /* Get system clock frequency */
  	sysClk_FRE = Get_SysClk_FRE();
    CCAPM0 = PCA_TYPE_TIM;
    value = sysClk_FRE / (12000000UL / value);
    PCA_Value[0] = value;
    CCAP0L = value;
    CCAP0H = value >> 8;
    return FSC_SUCCESS;
}

/**
  * @name    PCA1_TIM_Init
  * @brief   PCA1 TIMER init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA1_TIM_Init(uint16_t value) 
{
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    /* Get system clock frequency */
    sysClk_FRE = Get_SysClk_FRE();
    CCAPM1 = PCA_TYPE_TIM;
    value = sysClk_FRE / (12000000UL / value);
    PCA_Value[1] = value;
    CCAP1L = value;
    CCAP1H = value >> 8;
    return FSC_SUCCESS;
}

/**
  * @name    PCA2_TIM_Init
  * @brief   PCA2 TIMER init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA2_TIM_Init(uint16_t value) 
{
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    /* Get system clock frequency */
    sysClk_FRE = Get_SysClk_FRE();
    CCAPM2 = PCA_TYPE_TIM;
    value = sysClk_FRE / (12000000UL / value);
    PCA_Value[2] = value;
    CCAP2L = value;
    CCAP2H = value >> 8;
    return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    PCA3_TIM_Init
  * @brief   PCA3 TIMER init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA3_TIM_Init(uint16_t value) 
{
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    /* Get system clock frequency */
    sysClk_FRE = Get_SysClk_FRE();
    CCAPM3 = PCA_TYPE_TIM;
    value = sysClk_FRE / (12000000UL / value);
    PCA_Value[3] = value;
    CCAP3L = value;
    CCAP3H = value >> 8;
    return FSC_SUCCESS;
}
#endif

/**
  * @name    PCA0_POP_Init
  * @brief   PCA0 POP init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA0_POP_Init(uint16_t value) 
{
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
    /* Get system clock frequency */
    sysClk_FRE = Get_SysClk_FRE();
    CCAPM0 = PCA_TYPE_POP;
    value = sysClk_FRE / (12UL / value);
    PCA_Value[0] = value;
    CCAP0L = value;
    CCAP0H = value >> 8;
    return FSC_SUCCESS;
}

/**
  * @name    PCA1_POP_Init
  * @brief   PCA1 POP init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA1_POP_Init(uint16_t value) 
{
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
  	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
    CCAPM1 = PCA_TYPE_POP;
    value = sysClk_FRE / (12UL / value);
    PCA_Value[1] = value;
    CCAP1L = value;
    CCAP1H = value >> 8;
    return FSC_SUCCESS;
}

/**
  * @name    PCA2_POP_Init
  * @brief   PCA2 POP init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA2_POP_Init(uint16_t value) 
{
	extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
    CCAPM2 = PCA_TYPE_POP;
    value = sysClk_FRE / (12UL / value);
    PCA_Value[2] = value;
    CCAP2L = value;
    CCAP2H = value >> 8;
    return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    PCA3_POP_Init
  * @brief   PCA3 POP init function,it must first is initialized
  * @param   pwmBits   PCA_PWM_8Bit | PCA_PWM_7Bit | PCA_PWM_6Bit | PCA_PWM_10Bit
  * @param   duty      duty of PWM (uint16_t)
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA3_POP_Init(uint16_t value) 
{
	extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
	/* Get system clock frequency */
	sysClk_FRE = Get_SysClk_FRE();
    CCAPM3 = PCA_TYPE_POP;
    value = sysClk_FRE / (12UL / value);
    PCA_Value[3] = value;
    CCAP3L = value;
    CCAP3H = value >> 8;
    return FSC_SUCCESS;
}
#endif

/**
  * @name    PCA0_CAP_Init
  * @brief   PCA0 CAP init function,it must first is initialized
  * @param   mode   CAP_Mode_Falling | CAP_Mode_Rising | CAP_Mode_Edge 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA0_CAP_Init(CAPMode_Type mode) 
{
    CCAPM0 = PCA_TYPE_CAP;
    CCAPM0 = mode << 4;
    CCAP0L = 0;
    CCAP0H = 0;
    return FSC_SUCCESS;
}

/**
  * @name    PCA1_CAP_Init
  * @brief   PCA1 CAP init function,it must first is initialized
  * @param   mode   CAP_Mode_Falling | CAP_Mode_Rising | CAP_Mode_Edge 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA1_CAP_Init(CAPMode_Type mode) 
{
    CCAPM1 = PCA_TYPE_CAP;
    CCAPM1 = mode << 4;
    CCAP1L = 0;
    CCAP1H = 0;
    return FSC_SUCCESS;
}

/**
  * @name    PCA2_CAP_Init
  * @brief   PCA2 CAP init function,it must first is initialized
  * @param   mode   CAP_Mode_Falling | CAP_Mode_Rising | CAP_Mode_Edge 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA2_CAP_Init(CAPMode_Type mode) 
{
    CCAPM2 = PCA_TYPE_CAP;
    CCAPM2 = mode << 4;
    CCAP2L = 0;
    CCAP2H = 0;
    return FSC_SUCCESS;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    PCA3_CAP_Init
  * @brief   PCA3 CAP init function,it must first is initialized
  * @param   mode   CAP_Mode_Falling | CAP_Mode_Rising | CAP_Mode_Edge 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE PCA3_CAP_Init(CAPMode_Type mode) 
{
    CCAPM3 = PCA_TYPE_CAP;
    CCAPM3 = mode << 4;
    CCAP3L = 0;
    CCAP3H = 0;
    return FSC_SUCCESS;
}
#endif

/**
  * @name    PCA0_TIM_POP_ReValue
  * @brief   PCA0 TIM and POP reload value function
  * @param   None
  * @return  None
***/
void PCA0_TIM_POP_ReValue(void)
{
    PCA_Rvalue[0] += PCA_Value[0];
    CCAP0L = PCA_Rvalue[0];
    CCAP0H = PCA_Rvalue[0] >> 8;
}

/**
  * @name    PCA1_TIM_POP_ReValue
  * @brief   PCA1 TIM and POP reload value function
  * @param   None
  * @return  None
***/
void PCA1_TIM_POP_ReValue(void)
{
    PCA_Rvalue[1] += PCA_Value[1];
    CCAP1L = PCA_Rvalue[1];
    CCAP1H = PCA_Rvalue[1] >> 8;
}

/**
  * @name    PCA2_TIM_POP_ReValue
  * @brief   PCA2 TIM and POP reload value function
  * @param   None
  * @return  None
***/
void PCA2_TIM_POP_ReValue(void)
{
    PCA_Rvalue[2] += PCA_Value[2];
    CCAP2L = PCA_Rvalue[2];
    CCAP2H = PCA_Rvalue[2] >> 8;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    PCA3_TIM_POP_ReValue
  * @brief   PCA3 TIM and POP reload value function
  * @param   None
  * @return  None
***/
void PCA3_TIM_POP_ReValue(void)
{
    PCA_Rvalue[3] += PCA_Value[3];
    CCAP3L = PCA_Rvalue[3];
    CCAP3H = PCA_Rvalue[3] >> 8;
}
#endif

#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



