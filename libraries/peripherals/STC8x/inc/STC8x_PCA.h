/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_PCA.h
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
#ifndef __STC8x_PCA_H_
#define __STC8x_PCA_H_

#include "Lib_CFG.h"



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


#ifndef PER_LIB_MCU_MUODEL 
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */  
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif


#ifndef PER_LIB_PCA_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PCA_CTRL 1
#endif


#ifndef PER_LIB_PCA_INIT_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PCA_INIT_CTRL 1
#endif


#ifndef PER_LIB_PCA_NVIC_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PCA_NVIC_CTRL 1
#endif


#ifndef PER_LIB_PCA_WORK_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PCA_WORK_CTRL 1
#endif


/** 
 * @brief	 PCA工作类型枚举体
 * @details	 PCA type control enumenumeration.
**/
typedef enum
{
	PCA_TYPE_CAP = 0X00,   /*!< PAC工作在捕获模式。PAC works in capture mode. */
	PCA_TYPE_PWM = 0x42,   /*!< PAC工作在PWM模式。PAC works in PWM mode. */
	PCA_TYPE_TIM = 0x48,   /*!< PAC工作在定时器模式。PAC works in timer mode. */
	PCA_TYPE_POP = 0x4C    /*!< PAC工作在脉冲输出模式。PAC works in pulse output mode. */
} PCAType_Type;


/** 
 * @brief	 PCA做CAP时，触发模式枚举体。
 * @details	 CAP trigger mode enumenumeration.
**/
typedef enum
{
	PCA_CAP_Mode_Falling = 0x01, /*!< 下降沿捕获。Capture on falling edge.*/
	PCA_CAP_Mode_Rising  = 0X02, /*!< 上升沿捕获。Rising edge capture. */
	PCA_CAP_Mode_Edge    = 0x03  /*!< 边沿捕获。Edge capture. */
} PCA_CAPMode_Type;


/** 
 * @brief	 PCA时钟源枚举体
 * @details	 PCA working clock enumeration body.
**/
typedef enum
{
	PCA_SCLK_DIV_12 = 0x00,   /*!< 系统时钟12分频。System clock / 12. */
	PCA_SCLK_DIV_2  = 0x02,   /*!< 系统时钟2分频。System clock / 2. */
	PCA_TIMER0	    = 0x04,   /*!< 定时器0溢出频率。Overflow pulse of timer 0.*/
	PCA_ECI         = 0x06,   /*!< 外部时钟源。External input clock of ECI pin. */
	PCA_SCLK_DIV_1	= 0x08,   /*!< 系统时钟1分频。System clock / 1. */
	PCA_SCLK_DIV_4  = 0x0A,   /*!< 系统时钟4分频。System clock / 4. */
	PCA_SCLK_DIV_6  = 0x0C,   /*!< 系统时钟6分频。System clock / 6. */
	PCA_SCLK_DIV_8  = 0x0E    /*!< 系统时钟8分频。System clock / 8.*/
} PCACLKSrc_Type;


/** 
 * @brief	 PCA做PWM时，分辨率枚举体。
 * @details	 PCA PWM bits mode enumenumeration.
**/
typedef enum
{
	PCA_PWM_8Bits   = 0x00,  /*!< 8-bit PCA_PWM mode. */
	PCA_PWM_7Bits   = 0x01,	 /*!< 7-bit PCA_PWM mode. */
	PCA_PWM_6Bits   = 0x02,	 /*!< 6-bit PCA_PWM mode. */
	PCA_PWM_10Bits  = 0x03	 /*!< 10-bit PCA_PWM mode.*/
} PCA_PWMBits_Type;


/** 
 * @brief	 PCA做CAP时，触发中断方式枚举体。
 * @details	 PCA CAP interrupt trigger enumenumeration.
**/
typedef enum
{
	PCA_CAPTri_Null    = 0x00,   /*!< 无触发模式，不使能中断。
									No trigger mode, no interrupt is enabled. */
	PCA_CAPTri_Falling = 0x10,   /*!< 下降沿触发模式，使能中断。
									Falling edge trigger mode, enable interrupt. */
	PCA_CAPTri_Rising  = 0x20,   /*!< 上升沿触发模式，使能中断。
									The rising edge trigger mode enables interrupts. */
	PCA_CAPTri_Edge    = 0x30    /*!< 边沿触发模式，使能中断。
									Edge trigger mode, enable interrupt.*/
} PCA_CAPTri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

#if ( PER_LIB_PCA_CTRL == 1)

	#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx)

		#if ( PER_LIB_PCA_INIT_CTRL == 1)


			/**
			 * @brief     PCA计数器初始化,必须放在所有PCA函数的后面。
			 * @details   PCA counter init function,It must be initialized last.
			 * @param[in] clkSrc PCA时钟源。PCA clock source.
			 * @param[in] run 使能控制位.enable control.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA_CNT_Init(PCACLKSrc_Type clkSrc,BOOL run);


			/**
			 * @brief     PCA0做PWM初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 PWM init function,it must first is initialized.
			 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
			 * @param[in] duty      PWM占空比。PWM duty.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);
			
			
			/**
			 * @brief     PCA1做PWM初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 PWM init function,it must first is initialized.
			 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
			 * @param[in] duty      PWM占空比。PWM duty.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);


			/**
			 * @brief     PCA2做PWM初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 PWM init function,it must first is initialized.
			 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
			 * @param[in] duty      PWM占空比。PWM duty.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);


			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     PCA3做PWM初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 PWM init function,it must first is initialized.
				 * @param[in] pwmBits   PWM分辨率。PWM accuracy of bits.
				 * @param[in] duty      PWM占空比。PWM duty.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_PWM_Init(PCA_PWMBits_Type pwmBits,uint16_t  duty);
				
			#endif

			
			/**
			 * @brief     PCA0做CAP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 CAP init function,it must first is initialized.
			 * @param[in] mode  捕获模式。Capture mode.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_CAP_Init(PCA_CAPMode_Type mode);
			
			
			/**
			 * @brief     PCA1做CAP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 CAP init function,it must first is initialized.
			 * @param[in] mode  捕获模式。Capture mode.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_CAP_Init(PCA_CAPMode_Type mode);
			
			
			/**
			 * @brief     PCA2做CAP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 CAP init function,it must first is initialized.
			 * @param[in] mode  捕获模式。Capture mode.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_CAP_Init(PCA_CAPMode_Type mode);


			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
			
				/**
				 * @brief     PCA3做CAP初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 CAP init function,it must first is initialized.
				 * @param[in] mode  捕获模式。Capture mode.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/			
				FSCSTATE PCA3_CAP_Init(PCA_CAPMode_Type mode);
				
			#endif


			/**
			 * @brief     PCA0做TIMER初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 TIMER init function,it must first is initialized.
			 * @param[in] time  定时时间。Timing.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_TIM_Init(uint16_t time);
			
			
			/**
			 * @brief     PCA1做TIMER初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 TIMER init function,it must first is initialized.
			 * @param[in] time  定时时间。Timing.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_TIM_Init(uint16_t time);
			
			
			/**
			 * @brief     PCA2做TIMER初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 TIMER init function,it must first is initialized.
			 * @param[in] time  定时时间。Timing.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_TIM_Init(uint16_t time);


			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     PCA3做TIMER初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 TIMER init function,it must first is initialized.
				 * @param[in] time  定时时间。Timing.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_TIM_Init(uint16_t time);
				
			#endif


			/**
			 * @brief     PCA0做POP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA0 POP init function,it must first is initialized.
			 * @param[in] fre  脉冲输出频率。Output frequency.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA0_POP_Init(uint16_t fre);
			
			
			/**
			 * @brief     PCA1做POP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA1 POP init function,it must first is initialized.
			 * @param[in] fre  脉冲输出频率。Output frequency.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA1_POP_Init(uint16_t fre);
			
			
			/**
			 * @brief     PCA2做POP初始化,必须放在PCA计数器初始化之前。
			 * @details   PCA2 POP init function,it must first is initialized.
			 * @param[in] fre  脉冲输出频率。Output frequency.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE PCA2_POP_Init(uint16_t fre);


			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     PCA3做POP初始化,必须放在PCA计数器初始化之前。
				 * @details   PCA3 POP init function,it must first is initialized.
				 * @param[in] fre  脉冲输出频率。Output frequency.
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE PCA3_POP_Init(uint16_t fre);
				
			#endif
			
		#endif
		
		
		#if ( PER_LIB_PCA_WORK_CTRL == 1 )
		
			/**
			 * @brief     PCA0做TIMER或POP时，重载载计数器。
			 * @details   PCA0 TIM and POP reload value function.
			 * @param[in] None.
			 * @return    None.
			**/
			void PCA0_TIM_POP_ReValue(void);
			
			
			/**
			 * @brief     PCA1做TIMER或POP时，重载载计数器。
			 * @details   PCA1 TIM and POP reload value function.
			 * @param[in] None.
			 * @return    None.
			**/
			void PCA1_TIM_POP_ReValue(void);
			
			
			/**
			 * @brief     PCA2做TIMER或POP时，重载载计数器。
			 * @details   PCA2 TIM and POP reload value function.
			 * @param[in] None.
			 * @return    None.
			**/
			void PCA2_TIM_POP_ReValue(void);


			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     PCA3做TIMER或POP时，重载载计数器。
				 * @details   PCA3 TIM and POP reload value function.
				 * @param[in] None.
				 * @return    None.
				**/
				void PCA3_TIM_POP_ReValue(void);
				
			#endif
				
				
			/**
			 * @brief     PCA0停止工作宏函数。
			 * @details   PCA0 stops working macro function. 
			**/
			#define    PCA0_WORK_STOP()   do{CCAPM0 = 0;}while(0)
			
			
			/**
			 * @brief     PCA1停止工作宏函数。
			 * @details   PCA1 stops working macro function. 
			**/
			#define    PCA1_WORK_STOP()   do{CCAPM1 = 0;}while(0)
			
			
			/**
			 * @brief     PCA2停止工作宏函数。
			 * @details   PCA2 stops working macro function. 
			**/
			#define    PCA2_WORK_STOP()   do{CCAPM2 = 0;}while(0)	
			
			
			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     PCA3停止工作宏函数。
				 * @details   PCA3 stops working macro function. 
				**/
				#define    PCA3_WORK_STOP()   do{CCAPM3 = 0;}while(0)	
			
			#endif

				
			/**
			 * @brief     PCA0做6位PWM时，占空比调节宏函数。
			 * @details   When PCA0 is used as 6-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA0_PWM_6BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM0 = PCA_TYPE_PWM;                                \
				PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x02 << 6);             \
				PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x40) >> 6);  \
				PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x40) >> 5);  \
				CCAP0L = (uint8_t)(duty & 0x003F);                   \
				CCAP0H = (uint8_t)(duty & 0x003F);                   \
			}while(0)
			
			
			/**
			 * @brief     PCA0做7位PWM时，占空比调节宏函数。
			 * @details   When PCA0 is used as 7-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA0_PWM_7BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM0 = PCA_TYPE_PWM;                                \
				PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x01 << 6);             \
				PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x80) >> 7);  \
				PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x80) >> 6);  \
				CCAP0L = (uint8_t)(duty & 0x007F);                   \
				CCAP0H = (uint8_t)(duty & 0x007F);                   \
			}while(0)
			
			
			/**
			 * @brief     PCA0做8位PWM时，占空比调节宏函数。
			 * @details   When PCA0 is used as 8-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA0_PWM_8BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM0 = PCA_TYPE_PWM;                                \
				PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x00 << 6);             \
				PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x100) >> 8); \
				PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x100) >> 7); \
				CCAP0L = (uint8_t)duty;                              \
				CCAP0H = (uint8_t)duty;                              \
			}while(0)
			
			
			/**
			 * @brief     PCA0做10位PWM时，占空比调节宏函数。
			 * @details   When PCA0 is used as 10-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA0_PWM_10BITS_CTRL(duty)                         \
			do{                                                        \
				CCAPM0 = PCA_TYPE_PWM;                                 \
				PCA_PWM0 = (PCA_PWM0 & 0x3F)|(0x03 << 6);              \
				PCA_PWM0 = (PCA_PWM0 & 0XFE) | ((duty & 0x400) >> 10); \
				PCA_PWM0 = (PCA_PWM0 & 0XFD) | ((duty & 0x400) >> 9);  \
				PCA_PWM0 = (PCA_PWM0 & 0XF3) | ((duty & 0x300) >> 6);  \
				PCA_PWM0 = (PCA_PWM0 & 0XCF) | ((duty & 0x300) >> 4);  \
				CCAP0L = (uint8_t)duty;                               \
				CCAP0H = (uint8_t)duty;                               \
			} while (0)
	
			
			/**
			 * @brief     PCA1做6位PWM时，占空比调节宏函数。
			 * @details   When PCA1 is used as 6-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA1_PWM_6BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM1 = PCA_TYPE_PWM;                                \
				PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x02 << 6);             \
				PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x40) >> 6);  \
				PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x40) >> 5);  \
				CCAP1L = (uint8_t)(duty & 0x003F);                   \
				CCAP1H = (uint8_t)(duty & 0x003F);                   \
			}while(0)
			
			
			/**
			 * @brief     PCA1做7位PWM时，占空比调节宏函数。
			 * @details   When PCA1 is used as 7-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA1_PWM_7BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM1 = PCA_TYPE_PWM;                                \
				PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x01 << 6);             \
				PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x80) >> 7);  \
				PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x80) >> 6);  \
				CCAP1L = (uint8_t)(duty & 0x007F);                   \
				CCAP1H = (uint8_t)(duty & 0x007F);                   \
			}while(0)
			
			
			/**
			 * @brief     PCA1做8位PWM时，占空比调节宏函数。
			 * @details   When PCA1 is used as 8-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA1_PWM_8BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM1 = PCA_TYPE_PWM;                                \
				PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x00 << 6);             \
				PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x100) >> 8); \
				PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x100) >> 7); \
				CCAP1L = (uint8_t)duty;                              \
				CCAP1H = (uint8_t)duty;                              \
			}while(0)
			
			
			/**
			 * @brief     PCA1做10位PWM时，占空比调节宏函数。
			 * @details   When PCA1 is used as 10-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA1_PWM_10BITS_CTRL(duty)                         \
			do{                                                        \
				CCAPM1 = PCA_TYPE_PWM;                                 \
				PCA_PWM1 = (PCA_PWM1 & 0x3F)|(0x03 << 6);              \
				PCA_PWM1 = (PCA_PWM1 & 0XFE) | ((duty & 0x400) >> 10); \
				PCA_PWM1 = (PCA_PWM1 & 0XFD) | ((duty & 0x400) >> 9);  \
				PCA_PWM1 = (PCA_PWM1 & 0XF3) | ((duty & 0x300) >> 6);  \
				PCA_PWM1 = (PCA_PWM1 & 0XCF) | ((duty & 0x300) >> 4);  \
				CCAP1L = (uint8_t)duty;                               \
				CCAP1H = (uint8_t)duty;                               \
			}while(0)
			
			
			/**
			 * @brief     PCA2做6位PWM时，占空比调节宏函数。
			 * @details   When PCA2 is used as 6-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA2_PWM_6BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM2 = PCA_TYPE_PWM;                                \
				PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x02 << 6);             \
				PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x40) >> 6);  \
				PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x40) >> 5);  \
				CCAP2L = (uint8_t)(duty & 0x003F);                   \
				CCAP2H = (uint8_t)(duty & 0x003F);                   \
			}while(0)
			
			
			/**
			 * @brief     PCA2做7位PWM时，占空比调节宏函数。
			 * @details   When PCA2 is used as 7-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA2_PWM_7BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM2 = PCA_TYPE_PWM;                                \
				PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x01 << 6);             \
				PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x80) >> 7);  \
				PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x80) >> 6);  \
				CCAP2L = (uint8_t)(duty & 0x007F);                   \
				CCAP2H = (uint8_t)(duty & 0x007F);                   \
			}while(0)
			
			
			/**
			 * @brief     PCA2做8位PWM时，占空比调节宏函数。
			 * @details   When PCA2 is used as 8-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA2_PWM_8BITS_CTRL(duty)                         \
			do{                                                       \
				CCAPM2 = PCA_TYPE_PWM;                                \
				PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x00 << 6);             \
				PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x100) >> 8); \
				PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x100) >> 7); \
				CCAP2L = (uint8_t)duty;                              \
				CCAP2H = (uint8_t)duty;                              \
			}while(0)
			
			
			/**
			 * @brief     PCA2做10位PWM时，占空比调节宏函数。
			 * @details   When PCA2 is used as 10-bit precision PWM, 
			 *            set the duty cycle macro function.
			 * @param[in] duty 占空比。PWM duty.
			**/
			#define PCA2_PWM_10BITS_CTRL(duty)                         \
			do{                                                        \
				CCAPM2 = PCA_TYPE_PWM;                                 \
				PCA_PWM2 = (PCA_PWM2 & 0x3F)|(0x03 << 6);              \
				PCA_PWM2 = (PCA_PWM2 & 0XFE) | ((duty & 0x400) >> 10); \
				PCA_PWM2 = (PCA_PWM2 & 0XFD) | ((duty & 0x400) >> 9);  \
				PCA_PWM2 = (PCA_PWM2 & 0XF3) | ((duty & 0x300) >> 6);  \
				PCA_PWM2 = (PCA_PWM2 & 0XCF) | ((duty & 0x300) >> 4);  \
				CCAP2L = (uint8_t)duty;                               \
				CCAP2H = (uint8_t)duty;                               \
			}while(0)

			
			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     PCA3做6位PWM时，占空比调节宏函数。
				 * @details   When PCA3 is used as 6-bit precision PWM, 
				 *            set the duty cycle macro function.
				 * @param[in] duty 占空比。PWM duty.
				**/
				#define PCA3_PWM_6BITS_CTRL(duty)                         \
				do{                                                       \
					CCAPM3 = PCA_TYPE_PWM;                                \
					PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x02 << 6);             \
					PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x40) >> 6);  \
					PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x40) >> 5);  \
					CCAP3L = (uint8_t)(duty & 0x003F);                   \
					CCAP3H = (uint8_t)(duty & 0x003F);                   \
				}while(0)
				
				
				/**
				 * @brief     PCA3做7位PWM时，占空比调节宏函数。
				 * @details   When PCA3 is used as 7-bit precision PWM, 
				 *            set the duty cycle macro function.
				 * @param[in] duty 占空比。PWM duty.
				**/
				#define PCA3_PWM_7BITS_CTRL(duty)                         \
				do{                                                       \
					CCAPM3 = PCA_TYPE_PWM;                                \
					PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x01 << 6);             \
					PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x80) >> 7);  \
					PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x80) >> 6);  \
					CCAP3L = (uint8_t)(duty & 0x007F);                   \
					CCAP3H = (uint8_t)(duty & 0x007F);                   \
				}while(0)
				
				
				/**
				 * @brief     PCA3做8位PWM时，占空比调节宏函数。
				 * @details   When PCA3 is used as 8-bit precision PWM, 
				 *            set the duty cycle macro function.
				 * @param[in] duty 占空比。PWM duty.
				**/
				#define PCA3_PWM_8BITS_CTRL(duty)                          \
				do{                                                        \
					CCAPM3 = PCA_TYPE_PWM;                                 \
					PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x00 << 6);              \
					PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x100) >> 8);  \
					PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x100) >> 7);  \
					CCAP3L = (uint8_t)duty;                               \
					CCAP3H = (uint8_t)duty;                               \
				}while(0)
				
				
				/**
				 * @brief     PCA3做10位PWM时，占空比调节宏函数。
				 * @details   When PCA3 is used as 10-bit precision PWM, 
				 *            set the duty cycle macro function.
				 * @param[in] duty 占空比。PWM duty.
				**/
				#define PCA3_PWM_10BITS_CTRL(duty)                         \
				do{                                                        \
					CCAPM3 = PCA_TYPE_PWM;                                 \
					PCA_PWM3 = (PCA_PWM3 & 0x3F)|(0x03 << 6);              \
					PCA_PWM3 = (PCA_PWM3 & 0XFE) | ((duty & 0x400) >> 10); \
					PCA_PWM3 = (PCA_PWM3 & 0XFD) | ((duty & 0x400) >> 9);  \
					PCA_PWM3 = (PCA_PWM3 & 0XF3) | ((duty & 0x300) >> 6);  \
					PCA_PWM3 = (PCA_PWM3 & 0XCF) | ((duty & 0x300) >> 4);  \
					CCAP3L = (uint8_t)duty;                               \
					CCAP3H = (uint8_t)duty;                               \
				}while(0)

			#endif
			
				
			/**
			 * @brief     PCA切换复用IO函数。
			 * @details   PCA switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PCA_SWPort(GPIOSWPort_Type port);
				
		#endif
				
		#if ( PER_LIB_PCA_INIT_CTRL == 1)		

			/**
			 * @brief     PCA计数器中断初始化函数。
			 * @details   PCA Counter NVIC function.   
			 * @param[in] pri 中断优先级。interrupt priority.
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA_CNT_Init(NVICPri_Type pri,BOOL run);


			/**
			 * @brief     PCA0做TIMER或POP中断初始化函数。
			 * @details   PCA0 Timer and POP NVIC function .  
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA0_TIM_POP_Init(BOOL run);
			
			
			/**
			 * @brief     PCA1做TIMER或POP中断初始化函数。
			 * @details   PCA1 Timer and POP NVIC function .  
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA1_TIM_POP_Init(BOOL run);
			
			
			/**
			 * @brief     PCA2做TIMER或POP中断初始化函数。
			 * @details   PCA2 Timer and POP NVIC function .  
			 * @param[in] run 使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA2_TIM_POP_Init(BOOL run);


			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
			
				/**
				 * @brief     PCA3做TIMER或POP中断初始化函数。
				 * @details   PCA3 Timer and POP NVIC function .  
				 * @param[in] run 使能控制位。enable control. 
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE NVIC_PCA3_TIM_POP_Init(BOOL run);
				
			#endif
			
			/**
			 * @brief     PCA0做PWM或CAP中断初始化函数。
			 * @details   PCA0 PWM and CAP NVIC function.  
			 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
			 * @param[in] run      使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA0_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run);
			
			
			/**
			 * @brief     PCA1做PWM或CAP中断初始化函数。
			 * @details   PCA1 PWM and CAP NVIC function.  
			 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
			 * @param[in] run      使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA1_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run);
			
			
			/**
			 * @brief     PCA2做PWM或CAP中断初始化函数。
			 * @details   PCA2 PWM and CAP NVIC function.  
			 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
			 * @param[in] run      使能控制位。enable control. 
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE NVIC_PCA2_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run);
			
			
			
			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
			
				/**
				 * @brief     PCA3做PWM或CAP中断初始化函数。
				 * @details   PCA3 PWM and CAP NVIC function.  
				 * @param[in] triMode  触发模式。 Interrupt trigger mode. 
				 * @param[in] run      使能控制位。enable control. 
				 * @return    FSC_SUCCESS 返回成功。Return to success.
				 * @return    FSC_FAIL    返回失败。Return to fail.
				**/
				FSCSTATE NVIC_PCA3_PWM_CAP_Init(PCA_CAPTri_Type triMode,BOOL run);
				
			#endif
			
			/**
			 * @brief     获取PCA计数器溢出（中断）标志位。
			 * @details   Get the PCA counter overflow (interrupt) flag macro function.
			 * @return    [bit] 标志位。Flag.
			**/			
			#define PCA_CNT_GET_FLAG()      (CF)
			
			
			/**
			 * @brief     清除PCA计数器溢出（中断）标志位。
			 * @details   Clear the PCA counter overflow (interrupt) flag macro function.
			**/						
			#define PCA_CNT_CLEAR_FLAG()    do{CF = 0;}while(0)
			
			
			/**
			 * @brief     获取PCA0计数器溢出（中断）标志位。
			 * @details   Get the PCA0 overflow (interrupt) flag macro function.
			 * @return    [bit] 标志位。Flag.
			**/			
			#define PCA0_GET_FLAG()           (CCF0)
			
			
			/**
			 * @brief     获取PCA1计数器溢出（中断）标志位。
			 * @details   Get the PCA1 overflow (interrupt) flag macro function.
			 * @return    [bit] 标志位。Flag.
			**/			
			#define PCA1_GET_FLAG()           (CCF1)
			
			
			/**
			 * @brief     获取PCA2计数器溢出（中断）标志位。
			 * @details   Get the PCA2 overflow (interrupt) flag macro function.
			 * @return    [bit] 标志位。Flag.
			**/			
			#define PCA2_GET_FLAG()           (CCF2)
			
			
			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
				/**
				 * @brief     获取PCA3计数器溢出（中断）标志位。
				 * @details   Get the PCA0 overflow (interrupt) flag macro function.
				 * @return    [bit] 标志位。Flag.
				**/			
				#define PCA3_GET_FLAG()           (CCF3)
				
			#endif
			
			/**
			 * @brief     清除PCA0计数器溢出（中断）标志位。
			 * @details   Clear the PCA0 overflow (interrupt) flag macro function.
			**/						
			#define PCA0_CLEAR_FLAG()     do{CCF0 = 0;}while(0)
			
			
			/**
			 * @brief     清除PCA1计数器溢出（中断）标志位。
			 * @details   Clear the PCA1 overflow (interrupt) flag macro function.
			**/			
			#define PCA1_CLEAR_FLAG()     do{CCF1 = 0;}while(0)
			
			
			/**
			 * @brief     清除PCA2计数器溢出（中断）标志位。
			 * @details   Clear the PCA2 overflow (interrupt) flag macro function.
			**/			
			#define PCA2_CLEAR_FLAG()     do{CCF2 = 0;}while(0)
			
			
			#if (PER_LIB_MCU_MUODEL == STC8Ax)
			
			
				/**
				 * @brief     清除PCA3计数器溢出（中断）标志位。
				 * @details   Clear the PCA3 overflow (interrupt) flag macro function.
				**/			
				#define PCA3_CLEAR_FLAG()     do{CCF3 = 0;}while(0)
				
			#endif

            /**
             * @brief     PCA计数器中断控制宏函数。
             * @details   PCA interrupt switch control macro function.
             * @param[in] run  使能控制位。Enable control bit.
            **/
			#define    NVIC_PCA_CNT_CTRL(run)    \
			do{                                  \
				CMOD = (CMOD & 0xFE) | run;      \
			}while(0)
			
			
			/**
			 * @brief      PCA选择中断优先级宏函数。
			 * @details    PCA select interrupt priority macro function.
			 * @param[in]  pri 中断优先级. Priority of interrupt.
			***/
			#define NVIC_PCA_PRI(pri)                     \
			do{                                           \
				IPH = (IPH & 0x7F) | ((pri & 0x02) << 6); \
				IP  = (IP  & 0x7F) | ((pri & 0x01) << 7); \
			}while(0)
			
			
            /**
             * @brief     PCA0中断控制宏函数。
             * @details   PCA0 interrupt switch control macro function.
             * @param[in] run  使能控制位。Enable control bit.
            **/
			#define    NVIC_PCA0_CTRL(run)          \
			do{                                     \
				CCAPM0 = (CCAPM0 & 0xFE) | (run);   \
			}while(0)
			
			
            /**
             * @brief     PCA1中断控制宏函数。
             * @details   PCA1 TIM / POP interrupt switch control macro function.
             * @param[in] run  使能控制位。Enable control bit.
            **/
			#define    NVIC_PCA1_CTRL(run)           \
			do{                                      \
				CCAPM1 = (CCAPM1 & 0xFE) | (run);    \
			}while(0)
			
			
            /**
             * @brief     PCA2中断控制宏函数。
             * @details   PCA2 interrupt switch control macro function.
             * @param[in] run  使能控制位。Enable control bit.
            **/
			#define    NVIC_PCA2_CTRL(run)           \
			do{                                      \
				CCAPM2 = (CCAPM2 & 0xFE) | (run);    \
			}while(0)

			#if (PER_LIB_MCU_MUODEL == STC8Ax)

				/**
				 * @brief     PCA3中断控制宏函数。
				 * @details   PCA3 interrupt switch control macro function.
				 * @param[in] run  使能控制位。Enable control bit.
				**/
				#define    NVIC_PCA3_CTRL(run)           \
				do{                                      \
					CCAPM3 = (CCAPM3 & 0xFE) | (run);    \
				}while(0)
				
			#endif

		#endif
		
	#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
