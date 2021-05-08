/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_PCA.c
  - Author        : zeweni
  - Update date   : 2020.04.27
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
 * Apache-2.0 License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_PCA.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

static vuint16_t PCA_Value[4];
static vuint16_t PCA_Rvalue[4];

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_PCA_CTRL == 1)

	#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx )
		
		#if (PER_LIB_PCA_INIT_CTRL == 1)

			/**
			 * @brief     PCA计数器初始化,必须放在所有PCA函数的后面。
			 * @details   PCA counter init function,It must be initialized last.
			 * @param[in] clkSrc PCA时钟源。PCA clock source.
			 * @param[in] run 使能控制位.enable control.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA_CNT_Init(PCACLKSrc_Type clkSrc,BOOL run) 
			{
				CMOD = (CMOD & 0xF1)|(clkSrc);
				CL = 0;
				CH = 0;
				CR = run;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA0做PWM初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 PWM init function,it must first is initialized.
			 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
			 * @param[in] duty      PWM占空比。PWM duty.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
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
			 * @brief     PCA1做PWM初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 PWM init function,it must first is initialized.
			 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
			 * @param[in] duty      PWM占空比。PWM duty.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
			{
				CCAPM1 = PCA_TYPE_PWM;
				PCA_PWM1 = (PCA_PWM1 & 0x3F)|(pwmBits << 6);
				if(pwmBits == PCA_PWM_6Bits)
				{
					PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x40) >> 6); //EPC0L
					PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x40) >> 5); //EPC0H			
					CCAP1L = (uint8_t)(duty & 0x003F);
					CCAP1H = (uint8_t)(duty & 0x003F);	 
				}
				else if(pwmBits == PCA_PWM_7Bits)
				{
					PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x80) >> 7); //EPC0L
					PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x80) >> 6); //EPC0H			
					CCAP1L = (uint8_t)(duty & 0x007F);
					CCAP1H = (uint8_t)(duty & 0x007F);
				}
				else if(pwmBits == PCA_PWM_8Bits)
				{	
					PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x100) >> 8); //EPC0L
					PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x100) >> 7); //EPC0H			
					CCAP1L = (uint8_t)duty;
					CCAP1H = (uint8_t)duty;
				}
				else if(pwmBits == PCA_PWM_10Bits)
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
			 * @brief     PCA2做PWM初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 PWM init function,it must first is initialized.
			 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
			 * @param[in] duty      PWM占空比。PWM duty.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
			{
				CCAPM2 = PCA_TYPE_PWM;
				PCA_PWM2 = (PCA_PWM2 & 0x3F)|(pwmBits << 6);
				if(pwmBits == PCA_PWM_6Bits)
				{
					PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x40) >> 6); //EPC0L
					PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x40) >> 5); //EPC0H			
					CCAP2L = (uint8_t)(duty & 0x003F);
					CCAP2H = (uint8_t)(duty & 0x003F);	 
				}
				else if(pwmBits == PCA_PWM_7Bits)
				{
					PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x80) >> 7); //EPC0L
					PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x80) >> 6); //EPC0H			
					CCAP2L = (uint8_t)(duty & 0x007F);
					CCAP2H = (uint8_t)(duty & 0x007F);	 		
				}
				else if(pwmBits == PCA_PWM_8Bits)
				{	
					PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x100) >> 8); //EPC0L
					PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x100) >> 7); //EPC0H			
					CCAP2L = (uint8_t)duty;
					CCAP2H = (uint8_t)duty;		 					
				}
				else if(pwmBits == PCA_PWM_10Bits)
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
				 * @brief     PCA3做PWM初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 PWM init function,it must first is initialized.
				 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
				 * @param[in] duty      PWM占空比。PWM duty.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t duty) 
				{
					CCAPM3 = PCA_TYPE_PWM;
					PCA_PWM3 = (PCA_PWM3 & 0x3F)|(pwmBits << 6);
					if(pwmBits == PCA_PWM_6Bits)
					{
						PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0040) >> 6); //EPC0L
						PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0040) >> 5); //EPC0H			
						CCAP3L = (uint8_t)(duty & 0x003F);
						CCAP3H = (uint8_t)(duty & 0x003F);	 	 
					}
					else if(pwmBits == PCA_PWM_7Bits)
					{
						PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0080) >> 7); //EPC0L
						PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0080) >> 6); //EPC0H			
						CCAP2L = (uint8_t)(duty & 0x007F);
						CCAP2H = (uint8_t)(duty & 0x007F);	 
					}
					else if(pwmBits == PCA_PWM_8Bits)
					{	
						PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x0100) >> 8); //EPC0L
						PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x0100) >> 7); //EPC0H			
						CCAP3L = (uint8_t)duty;
						CCAP3H = (uint8_t)duty;
					}
					else if(pwmBits == PCA_PWM_10Bits)
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
			 * @brief     PCA0做TIMER初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 TIMER init function,it must first is initialized.
			 * @param[in] time  定时时间。Timing.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_TIM_Init(uint16_t time) 
			{
				extern uint32_t Get_SysClk_FRE(void);
				uint32_t sysClk_FRE;
				/* Get system clock frequency */
				sysClk_FRE = Get_SysClk_FRE();
				CCAPM0 = PCA_TYPE_TIM;
				time = sysClk_FRE / (12000000UL / time);
				PCA_Value[0] = time;
				CCAP0L = time;
				CCAP0H = time >> 8;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA1做TIMER初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 TIMER init function,it must first is initialized.
			 * @param[in] time  定时时间。Timing.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_TIM_Init(uint16_t time) 
			{
				extern uint32_t Get_SysClk_FRE(void);
				uint32_t sysClk_FRE;
				/* Get system clock frequency */
				sysClk_FRE = Get_SysClk_FRE();
				CCAPM1 = PCA_TYPE_TIM;
				time = sysClk_FRE / (12000000UL / time);
				PCA_Value[1] = time;
				CCAP1L = time;
				CCAP1H = time >> 8;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA2做TIMER初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 TIMER init function,it must first is initialized.
			 * @param[in] time  定时时间。Timing.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_TIM_Init(uint16_t time) 
			{
				extern uint32_t Get_SysClk_FRE(void);
				uint32_t sysClk_FRE;
				/* Get system clock frequency */
				sysClk_FRE = Get_SysClk_FRE();
				CCAPM2 = PCA_TYPE_TIM;
				time = sysClk_FRE / (12000000UL / time);
				PCA_Value[2] = time;
				CCAP2L = time;
				CCAP2H = time >> 8;
				return FSC_SUCCESS;
			}

			#if (PER_LIB_MCU_MUODEL == STC8Ax)

			
				/**
				 * @brief     PCA3做TIMER初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 TIMER init function,it must first is initialized.
				 * @param[in] time  定时时间。Timing.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_TIM_Init(uint16_t time) 
				{
					extern uint32_t Get_SysClk_FRE(void);
					uint32_t sysClk_FRE;
					/** Get system clock frequency */
					sysClk_FRE = Get_SysClk_FRE();
					CCAPM3 = PCA_TYPE_TIM;
					time = sysClk_FRE / (12000000UL / time);
					PCA_Value[3] = time;
					CCAP3L = time;
					CCAP3H = time >> 8;
					return FSC_SUCCESS;
				}
				
			#endif

				
			/**
			 * @brief     PCA0做POP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 POP init function,it must first is initialized.
			 * @param[in] fre  脉冲输出频率。Output frequency.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_POP_Init(uint16_t fre) 
			{
				extern uint32_t Get_SysClk_FRE(void);
				uint32_t sysClk_FRE;
				/* Get system clock frequency */
				sysClk_FRE = Get_SysClk_FRE();
				CCAPM0 = PCA_TYPE_POP;
				fre = sysClk_FRE / (12UL / fre);
				PCA_Value[0] = fre;
				CCAP0L = fre;
				CCAP0H = fre >> 8;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA1做POP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 POP init function,it must first is initialized.
			 * @param[in] fre  脉冲输出频率。Output frequency.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_POP_Init(uint16_t fre) 
			{
				extern uint32_t Get_SysClk_FRE(void);
				uint32_t sysClk_FRE;
				/* Get system clock frequency */
				sysClk_FRE = Get_SysClk_FRE();
				CCAPM1 = PCA_TYPE_POP;
				fre = sysClk_FRE / (12UL / fre);
				PCA_Value[1] = fre;
				CCAP1L = fre;
				CCAP1H = fre >> 8;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA2做POP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 POP init function,it must first is initialized.
			 * @param[in] fre  脉冲输出频率。Output frequency.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_POP_Init(uint16_t fre) 
			{
				extern uint32_t Get_SysClk_FRE(void);
				uint32_t sysClk_FRE;
				/* Get system clock frequency */
				sysClk_FRE = Get_SysClk_FRE();
				CCAPM2 = PCA_TYPE_POP;
				fre = sysClk_FRE / (12UL / fre);
				PCA_Value[2] = fre;
				CCAP2L = fre;
				CCAP2H = fre >> 8;
				return FSC_SUCCESS;
			}

			#if (PER_LIB_MCU_MUODEL == STC8Ax)

			
				/**
				 * @brief     PCA3做POP初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 POP init function,it must first is initialized.
				 * @param[in] fre  脉冲输出频率。Output frequency.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_POP_Init(uint16_t fre) 
				{
					extern uint32_t Get_SysClk_FRE(void);
					uint32_t sysClk_FRE;
					/* Get system clock frequency */
					sysClk_FRE = Get_SysClk_FRE();
					CCAPM3 = PCA_TYPE_POP;
					fre = sysClk_FRE / (12UL / fre);
					PCA_Value[3] = fre;
					CCAP3L = fre;
					CCAP3H = fre >> 8;
					return FSC_SUCCESS;
				}
			#endif

				
			/**
			 * @brief     PCA0做CAP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 CAP init function,it must first is initialized.
			 * @param[in] mode  捕获模式。Capture mode.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_CAP_Init(PCA_CAPMode_Type mode) 
			{
				CCAPM0 = PCA_TYPE_CAP;
				CCAPM0 = mode << 4;
				CCAP0L = 0;
				CCAP0H = 0;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA1做CAP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 CAP init function,it must first is initialized.
			 * @param[in] mode  捕获模式。Capture mode.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_CAP_Init(PCA_CAPMode_Type mode) 
			{
				CCAPM1 = PCA_TYPE_CAP;
				CCAPM1 = mode << 4;
				CCAP1L = 0;
				CCAP1H = 0;
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA2做CAP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 CAP init function,it must first is initialized.
			 * @param[in] mode  捕获模式。Capture mode.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_CAP_Init(PCA_CAPMode_Type mode) 
			{
				CCAPM2 = PCA_TYPE_CAP;
				CCAPM2 = mode << 4;
				CCAP2L = 0;
				CCAP2H = 0;
				return FSC_SUCCESS;
			}

			#if (PER_LIB_MCU_MUODEL == STC8Ax)

			
				/**
				 * @brief     PCA3做CAP初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 CAP init function,it must first is initialized.
				 * @param[in] mode  捕获模式。Capture mode.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_CAP_Init(PCA_CAPMode_Type mode) 
				{
					CCAPM3 = PCA_TYPE_CAP;
					CCAPM3 = mode << 4;
					CCAP3L = 0;
					CCAP3H = 0;
					return FSC_SUCCESS;
				}
				
			#endif
				
		#endif

        #if (PER_LIB_PCA_NVIC_CTRL == 1)
				
				
			/**
			 * @brief     PCA计数器中断初始化函数。
			 * @details   PCA Counter NVIC function.   
			 * @param[in] pri 中断优先级。interrupt priority.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA_CNT_Init(NVICPri_Type pri,BOOL run)
			{
				CMOD = (CMOD & 0xFE) | run;
				NVIC_PCA_PRI(pri);
				return FSC_SUCCESS;
			}


			/**
			 * @brief     PCA0做TIMER或POP中断初始化函数。
			 * @details   PCA0 Timer and POP NVIC function .  
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA0_TIM_POP_Init(BOOL run)
			{
				CCAPM0 = (CCAPM0 & 0xFE) | (run);
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA1做TIMER或POP中断初始化函数。
			 * @details   PCA1 Timer and POP NVIC function .  
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA1_TIM_POP_Init(BOOL run)
			{
				CCAPM1 = (CCAPM1 & 0xFE) | (run);
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA2做TIMER或POP中断初始化函数。
			 * @details   PCA2 Timer and POP NVIC function .  
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA2_TIM_POP_Init(BOOL run)
			{
				CCAPM2 = (CCAPM2 & 0xFE) | (run);
				return FSC_SUCCESS;
			}


			#if (PER_LIB_MCU_MUODEL == STC8Ax)

				/**
				 * @brief     PCA3做TIMER或POP中断初始化函数。
				 * @details   PCA3 Timer and POP NVIC function .  
				 * @param[in] run 使能控制位。enable control. 
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE NVIC_PCA3_TIM_POP_Init(BOOL run)
				{
					CCAPM3 = (CCAPM3 & 0xFE) | (run);
					return FSC_SUCCESS;
				}

			#endif


			/**
			 * @brief     PCA0做PWM或CAP中断初始化函数。
			 * @details   PCA0 PWM and CAP NVIC function.  
			 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
			 * @param[in] run      使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA0_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run)
			{
				CCAPM0 = (CCAPM0 & 0xCE) | (triMode) | (run);
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA1做PWM或CAP中断初始化函数。
			 * @details   PCA1 PWM and CAP NVIC function.  
			 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
			 * @param[in] run      使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA1_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run)
			{
				CCAPM1 = (CCAPM1 & 0xCE) | (triMode) | (run);
				return FSC_SUCCESS;
			}

			
			/**
			 * @brief     PCA2做PWM或CAP中断初始化函数。
			 * @details   PCA2 PWM and CAP NVIC function.  
			 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
			 * @param[in] run      使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA2_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run)
			{
				CCAPM2 = (CCAPM2 & 0xCE) | (triMode) | (run);
				return FSC_SUCCESS;
			}

			#if (PER_LIB_MCU_MUODEL == STC8Ax)

			
				/**
				 * @brief     PCA3做PWM或CAP中断初始化函数。
				 * @details   PCA3 PWM and CAP NVIC function.  
				 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
				 * @param[in] run      使能控制位。enable control. 
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE NVIC_PCA3_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run)
				{
					CCAPM3 = (CCAPM3 & 0xCE) | (triMode) | (run);
					return FSC_SUCCESS;
				}

			#endif
				
		#endif
				
				
		#if (PER_LIB_PCA_WORK_CTRL == 1)
			
			/**
			 * @brief     PCA0做TIMER或POP时，重载载计数器。
			 * @details   PCA0 TIM and POP reload value function.
			 * @param[in] None.
			 * @return    None.
			**/
			void PCA0_TIM_POP_ReValue(void)
			{
				PCA_Rvalue[0] += PCA_Value[0];
				CCAP0L = PCA_Rvalue[0];
				CCAP0H = PCA_Rvalue[0] >> 8;
			}

			
			/**
			 * @brief     PCA1做TIMER或POP时，重载载计数器。
			 * @details   PCA0 TIM and POP reload value function.
			 * @param[in] None.
			 * @return    None.
			**/
			void PCA1_TIM_POP_ReValue(void)
			{
				PCA_Rvalue[1] += PCA_Value[1];
				CCAP1L = PCA_Rvalue[1];
				CCAP1H = PCA_Rvalue[1] >> 8;
			}

			
			/**
			 * @brief     PCA2做TIMER或POP时，重载载计数器。
			 * @details   PCA2 TIM and POP reload value function.
			 * @param[in] None.
			 * @return    None.
			**/
			void PCA2_TIM_POP_ReValue(void)
			{
				PCA_Rvalue[2] += PCA_Value[2];
				CCAP2L = PCA_Rvalue[2];
				CCAP2H = PCA_Rvalue[2] >> 8;
			}

			#if (PER_LIB_MCU_MUODEL == STC8Ax)

				/**
				 * @brief     PCA3做TIMER或POP时，重载载计数器。
				 * @details   PCA3 TIM and POP reload value function.
				 * @param[in] None.
				 * @return    None.
				**/
				void PCA3_TIM_POP_ReValue(void)
				{
					PCA_Rvalue[3] += PCA_Value[3];
					CCAP3L = PCA_Rvalue[3];
					CCAP3H = PCA_Rvalue[3] >> 8;
				}
				
			#endif
				
			/**
			 * @brief     PCA切换复用IO函数。
			 * @details   PCA switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PCA_SWPort(GPIOSWPort_Type port)
			{
				#if (PER_LIB_MCU_MUODEL == STC8Gx)
				if(port > SW_Port3) return FSC_FAIL;
				#endif
				P_SW1 = (P_SW1 & 0xCF) | (port << 4);
				return FSC_SUCCESS;
			}
			
		#endif
			
	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



