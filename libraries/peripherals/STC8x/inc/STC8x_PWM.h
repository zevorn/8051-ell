/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_PWM.h
  - Author        : zeweni
  - Update date   : 2020.05.06
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
#ifndef __STC8x_PWM_H_
#define __STC8x_PWM_H_

#include "Lib_CFG.h"
#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#if    (PER_LIB_MCU_MUODEL == STC8Ax)

    #include "STC8Ax_REG.h"
	
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


#ifndef PER_LIB_PWM_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PWM_CTRL 1
#endif


#ifndef PER_LIB_PWM_INIT_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PWM_INIT_CTRL 1
#endif


#ifndef PER_LIB_PWM_NVIC_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PWM_NVIC_CTRL 1
#endif


#ifndef PER_LIB_PWM_WORK_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_PWM_WORK_CTRL 1
#endif



/*--------------------------------------------------------
| @Description: PWM clock source enum                    |
--------------------------------------------------------*/

/**
 * @brief     RST复位方式选择枚举体。
 * @details   RST Reset Select Enumerator.
**/
typedef enum
{
	PWM_SCLK_DIV_1  =  0x00,
	PWM_SCLK_DIV_2  =  0x01,
	PWM_SCLK_DIV_3  =  0x02,
	PWM_SCLK_DIV_4  =  0x03,
	PWM_SCLK_DIV_5  =  0x04,
	PWM_SCLK_DIV_6  =  0x05,
	PWM_SCLK_DIV_7  =  0x06,
	PWM_SCLK_DIV_8  =  0x07,
	PWM_SCLK_DIV_9  =  0x08,
	PWM_SCLK_DIV_10 =  0x09,
	PWM_SCLK_DIV_11 =  0x0A,
	PWM_SCLK_DIV_12 =  0x0B,
	PWM_SCLK_DIV_13 =  0x0C,
	PWM_SCLK_DIV_14 =  0x0D,
	PWM_SCLK_DIV_15 =  0x0E,
	PWM_SCLK_DIV_16 =  0x0F,
	PWM_TIMER2_PULSE = 0x1F
}   PWMCLKSrc_Type;

/*--------------------------------------------------------
| @Description: PWM road start level configure enum      |
--------------------------------------------------------*/

typedef enum
{
	PWM_Start_Low_Level  =  0x00,
	PWM_Start_High_Level =  0x01  
}   PWMStartLevel_Type;

/*--------------------------------------------------------
| @Description: PWM Abnormal detection selection enum    |
--------------------------------------------------------*/

typedef enum
{
	PWM_ABD_P35  = 0x02,
	PWM_ABD_COMP = 0x04
}   PWMABDSignal_Type;

/*--------------------------------------------------------
| @Description: PWM Abnormal signal processing enum      |
--------------------------------------------------------*/

typedef enum
{
	PWM_COMP_Low_To_High = 0x00,
	PWM_COMP_High_To_Low = 0x80,
	PWM_P35_Low_To_High  = 0x00,
	PWM_P35_High_To_Low  = 0x40
}   PWMABDMode_Type;

/*--------------------------------------------------------
| @Description: PWM level hold configure enum            |
--------------------------------------------------------*/

typedef enum
{
	PWM_Hold_Normal_Level =  0x00,
	PWM_Hold_Low_Level    =  0x01,
	PWM_Hold_High_Level   =  0x02,  
}   PWMHoldLevel_Type;

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


/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

	#if (PER_LIB_MCU_MUODEL == STC8Ax)
		
		
			

			FSCSTATE PWM_CNT_Init(PWMCLKSrc_Type clkSrc,uint16_t period,BOOL run);



			FSCSTATE PWM0_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM1_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM2_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM3_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM4_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM5_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM6_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);
			FSCSTATE PWM7_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run);

	

			FSCSTATE PWM_ABD_Init(PWMABDSignal_Type sigSrc,PWMABDMode_Type mode,BOOL run);



			FSCSTATE PWM_ETADC_Init(uint16_t tValue,BOOL run);

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

			FSCSTATE NVIC_PWM_CNT_Init(NVICPri_Type pri,BOOL run);
			FSCSTATE NVIC_PWM_ABD_Init(NVICPri_Type pri,BOOL run);
			
			
			/**
			 * @brief     PWM0中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM0 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM0_Init(PWMFlip_Type flipPoint);
			
			
			/**
			 * @brief     PWM1中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM1 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM1_Init(PWMFlip_Type flipPoint);


			/**
			 * @brief     PWM2中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM2 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM2_Init(PWMFlip_Type flipPoint);


			/**
			 * @brief     PWM3中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM3 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM3_Init(PWMFlip_Type flipPoint);


			/**
			 * @brief     PWM4中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM4 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM4_Init(PWMFlip_Type flipPoint);


			/**
			 * @brief     PWM5中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM5 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM5_Init(PWMFlip_Type flipPoint);
			
			
			/**
			 * @brief     PWM6中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM6 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM6_Init(PWMFlip_Type flipPoint);
			
			
			/**
			 * @brief     PWM7中断初始化函数，设置触发中断的电平翻转点。
			 * @details   PWM7 interrupt initialization function, 
			 *            set the level flip point that triggers the interrupt.
			 * @param[in] flipPoint 电平翻转点 Level flip point
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			 * @note      PWM0~7,与PWM计数器共用一个中断服务入口，如果设置的电平触发点为无，那么将关闭这个中断。
			 *            PWM0~7 share an interrupt service entry with the PWM counter. 
			 *            If the set level trigger point is none, then this interrupt will be closed.
			**/
			FSCSTATE NVIC_PWM7_Init(PWMFlip_Type flipPoint);


			#define NVIC_PWM_CNT_PRI(pri)                   \
			do{                                             \
				IP2H = (IP2H & 0xFB) | ((pri & 0x02) << 1); \
				IP2  = (IP2  & 0xFB) | ((pri & 0x01) << 2); \
			}while(0)


			#define NVIC_PWM_ABD_PRI(pri)                   \
			do{                                             \
				IP2H = (IP2H & 0xF7) | ((pri & 0x02) << 2); \
				IP2  = (IP2  & 0xF7) | ((pri & 0x01) << 3); \
			}while(0)

			#define    NVIC_PWM_CNT_CTRL(run)     do{ PWMCR = (PWMCR & 0xBF) | (run << 6); }while(0)	
			#define    NVIC_PWM_ABD_CTRL(run)     do{ PWMFDCR = (PWMFDCR & 0xF7) | (run << 3); }while(0)	
			#define    NVIC_PWM0_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)	
			#define    NVIC_PWM1_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM2_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM3_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM4_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM5_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM6_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM6_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		
			#define    NVIC_PWM7_CTRL(run)     do{ EAXFR_ENABLE(); PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xF8) | (run); EAXFR_DISABLE(); }while(0)		



			#define PWM0_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM0T1_ADDRESS) = fValue; PWMxT2(PWM0T2_ADDRESS) = sValue;}while(0)
			#define PWM1_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM1T1_ADDRESS) = fValue; PWMxT2(PWM1T2_ADDRESS) = sValue;}while(0)
			#define PWM2_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM2T1_ADDRESS) = fValue; PWMxT2(PWM2T2_ADDRESS) = sValue;}while(0)
			#define PWM3_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM3T1_ADDRESS) = fValue; PWMxT2(PWM3T2_ADDRESS) = sValue;}while(0)
			#define PWM4_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM4T1_ADDRESS) = fValue; PWMxT2(PWM4T2_ADDRESS) = sValue;}while(0)
			#define PWM5_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM5T1_ADDRESS) = fValue; PWMxT2(PWM5T2_ADDRESS) = sValue;}while(0)
			#define PWM6_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM6T1_ADDRESS) = fValue; PWMxT2(PWM6T2_ADDRESS) = sValue;}while(0)
			#define PWM7_DUTY_CTRL(fValue,sValue) do{PWMxT1(PWM7T1_ADDRESS) = fValue; PWMxT2(PWM7T2_ADDRESS) = sValue;}while(0)


			/**
			 * @brief     PWM0切换复用IO函数。
			 * @details   PWM0 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM0_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM1切换复用IO函数。
			 * @details   PWM1 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM1_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM2切换复用IO函数。
			 * @details   PWM2 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM2_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM3切换复用IO函数。
			 * @details   PWM3 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/			
			FSCSTATE GPIO_PWM3_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM4切换复用IO函数。
			 * @details   PWM4 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM4_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM5切换复用IO函数。
			 * @details   PWM5 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM5_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM6切换复用IO函数。
			 * @details   PWM6 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE GPIO_PWM6_SWPort(GPIOSWPort_Type port);
			
			
			/**
			 * @brief     PWM7切换复用IO函数。
			 * @details   PWM7 switch out port control function.  
			 * @param[in] port 复用IO枚举体。IO switch enumerator.
			 * @return    FSC_SUCCESS 返回成功。Return to success.
			 * @return    FSC_FAIL    返回失败。Return to fail.
			**/	
			FSCSTATE GPIO_PWM7_SWPort(GPIOSWPort_Type port);

	#endif


/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
