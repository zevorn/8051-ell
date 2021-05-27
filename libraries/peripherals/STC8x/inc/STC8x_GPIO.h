/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_GPIO.h
  - Author        : zeweni
  - Update date   : 2020.04.24
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
#ifndef __STC8x_GPIO_H_
#define __STC8x_GPIO_H_

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


#ifndef PER_LIB_GPIO_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_GPIO_CTRL 1
#endif


#ifndef PER_LIB_GPIO_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_GPIO_INIT_CTRL 1
#endif


#ifndef PER_LIB_GPIO_NVIC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_GPIO_NVIC_CTRL 1
#endif


#ifndef PER_LIB_GPIO_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_GPIO_WORK_CTRL 1
#endif


/*--------------------------------------------------------
| @Description: GPIO Pin define                          |
--------------------------------------------------------*/

/** 
 * @brief    GPIO组号，是GPIO宏操作函数的第一个参数，
 *           支持对这个宏进行再封装。
 * @details	 The GPIO group number is the first parameter of 
 *           the GPIO macro operation function,
 *           Support for repackaging this macro.
**/
#define	GPIO_P0      0 /*!< IO P0. */
#define	GPIO_P1      1 /*!< IO P1. */
#define	GPIO_P2      2 /*!< IO P2. */
#define	GPIO_P3      3 /*!< IO P3. */
#define	GPIO_P4      4 /*!< IO P4. */
#define	GPIO_P5      5 /*!< IO P5. */
#define	GPIO_P6      6 /*!< IO P6. */
#define	GPIO_P7      7 /*!< IO P7. */



/** 
 * @brief    GPIO端口号，是GPIO宏操作函数的第二个参数，
 *           支持多个宏进行或运算，以达到同时配置多个IO的效果。
 * @details	 The GPIO port number is the second parameter of 
 *           the GPIO macro operation function,
 *           Support multiple macros to perform OR operations to 
 *           achieve the effect of configuring multiple IOs at the same time.
**/
#define	Pin_0    0x01  /*!< IO Pin Px.0 . */
#define	Pin_1    0x02  /*!< IO Pin Px.1 . */
#define	Pin_2    0x04  /*!< IO Pin Px.2 . */
#define	Pin_3    0x08  /*!< IO Pin Px.3 . */
#define	Pin_4    0x10  /*!< IO Pin Px.4 . */
#define	Pin_5    0x20  /*!< IO Pin Px.5 . */
#define	Pin_6    0x40  /*!< IO Pin Px.6 . */
#define	Pin_7    0x80  /*!< IO Pin Px.7 . */
#define	Pin_Low  0x0F  /*!< IO Pin Px.0~3 . */
#define	Pin_High 0xF0  /*!< IO Pin Px.4~7 . */
#define	Pin_All  0xFF  /*!< IO Pin All . */

/** 
 * @brief    外部中断触发方式枚举体。
 * @details	 External interrupt Trigger enumerator.
**/
typedef enum
{
  EXTI_Tri_Edge    = 0x00,  /*!< 边沿触发。Both rising and falling edges triggered. */
  EXTI_Tri_Falling = 0x01    /*!< 下降沿触发。Falling edge trigger. */
} EXTITri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/




#if (PER_LIB_GPIO_CTRL == 1)

	#if (PER_LIB_GPIO_INIT_CTRL == 1)
		/**
		 * @brief       GPIO设置为准双向口（弱上拉）模式宏函数。
		 * @details	    GPIO is set as macro function in quasi 
		 *              bidirectional port (if pull-up) mode.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个， 用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/
		#define  GPIO_MODE_WEAK_PULL(gpio_x,pin)            \
		do{                                                 \
				Px_M1(gpio_x) &= ~(pin); Px_M0(gpio_x) &= ~(pin); \
		}while(0)

			
		/**
		 * @brief       GPIO设置为浮空输入模式宏函数。
		 * @details	    GPIO is set to float input mode macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/	
		#define  GPIO_MODE_IN_FLOATING(gpio_x,pin)          \
		do{                                                 \
				Px_M1(gpio_x) |=  (pin); Px_M0(gpio_x) &= ~(pin); \
		}while(0)

			
		/**
		 * @brief       GPIO设置为开漏输出模式宏函数。
		 * @details	    GPIO is set to open drain output mode macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/		
		#define  GPIO_MODE_OUT_OD(gpio_x,pin)               \
		do{                                                 \
				Px_M1(gpio_x) |=  (pin); Px_M0(gpio_x) |=  (pin); \
		}while(0)


		/**
		 * @brief       GPIO设置为推挽输出模式宏函数。
		 * @details	    GPIO is set to push-pull output mode macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		***/			
		#define  GPIO_MODE_OUT_PP(gpio_x,pin)                    \
		do{                                                       \
				Px_M1(gpio_x) &= ~(pin); Px_M0(gpio_x) |=  (pin); \
		}while(0)


		/**
		 * @brief       GPIO使能上拉电阻宏函数。
		 * @details	    GPIO enable pull-up resistor macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/		
		#define GPIO_PULL_UP_ENABLE(gpio_x,pin)         \
		do{                                             \
				EAXFR_ENABLE();                         \
				Px_PU(gpio_x) |=  (pin);                \
				EAXFR_DISABLE();                        \
		}while(0)


		/**
		 * @brief       GPIO不使能上拉电阻宏函数。
		 * @details	    GPIO disable pull-up resistor macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/		
		#define GPIO_PULL_UP_DISABLE(gpio_x,pin)        \
		do{                                             \
				EAXFR_ENABLE();                         \
				Px_PU(gpio_x) &= ~(pin);                \
				EAXFR_DISABLE();                        \
		}while(0)
																			

		/**
		 * @brief       GPIO使能施密特触发器宏函数。
		 * @details	    GPIO enable schmidt trigger macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/		
		#define GPIO_ST_ENABLE(gpio_x,pin)         \
		do{                                        \
			EAXFR_ENABLE();                        \
			Px_NCS(gpio_x) |=  (pin);              \
			EAXFR_DISABLE();                       \
		}while(0)


		/**
		 * @brief       GPIO不使能施密特触发器宏函数。
		 * @details	    GPIO disable schmidt trigger macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/	
		#define GPIO_ST_DISABLE(gpio_x,pin)        \
		do{                                        \
			EAXFR_ENABLE();                        \
			Px_NCS(gpio_x) &= ~(pin);              \
			EAXFR_DISABLE();                       \
		}while(0)


		/**
		 * @brief       GPIO电平低速翻转宏函数。
		 * @details	    GPIO level low speed flip macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/	
		#define GPIO_SPEED_LOW(gpio_x,pin)         \
		do{                                        \
			EAXFR_ENABLE();                        \
			Px_SR(gpio_x) |= (pin);                \
			EAXFR_DISABLE();                       \
		}while(0)


		/**
		 * @brief       GPIO电平高速翻转宏函数。
		 * @details	    GPIO level high speed flip macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/	
		#define GPIO_SPEED_HIGH(gpio_x,pin)        \
		do{                                        \
			EAXFR_ENABLE();                        \
			Px_SR(gpio_x) &= ~(pin);               \
			EAXFR_DISABLE();                       \
		}while(0)


		/**
		 * @brief       GPIO普通驱动电流宏函数。
		 * @details	    GPIO general drive current macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/	
		#define GPIO_DRIVE_MEDIUM(gpio_x,pin)     \
		do{                                       \
			EAXFR_ENABLE();                       \
			Px_DR(gpio_x) |=  (pin);              \
			EAXFR_DISABLE();                      \
		}while(0)


		/**
		 * @brief       GPIO高驱动电流宏函数。
		 * @details	    GPIO high drive current macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/	
		#define GPIO_DRIVE_HIGH(gpio_x,pin)       \
		do{                                       \
			EAXFR_ENABLE();                       \
			Px_DR(gpio_x) &= ~(pin);              \
			EAXFR_DISABLE();                      \
		}while(0)
		
	#endif	
		
	#if (PER_LIB_GPIO_WORK_CTRL == 1)

		/**
		 * @brief       GPIO翻转端口电平状态宏函数。
		 * @details	    GPIO flip port level state macro function.
		 * @param[in]   gpio_x   GPIO组，可以对这个宏的参数进行封装。
		 *                       The GPIO group can encapsulate the parameters 
         *                       of this macro.
		 * @param[in]   pin      端口号，可以同时传参多个，用或运算符号连接。
		 *                       Port number, which can transfer multiple 
		 *                       parameters at the same time and connect 
		 *                       with or operation symbol.
		**/		
		#define  GPIO_FLIP_PIN_LEVEL(gpio_x,pin)    \
		do{                                         \
				GPIO_Px(gpio_x) ^= pin;             \
		}while(0)		
		
	#endif
	
	#if (PER_LIB_GPIO_NVIC_CTRL == 1)
	
		/**
		 * @brief     外部中断0中断初始化函数。
		 * @details   EXTI0 NVIC function.
		 * @param[in] triMode  触发模式。Trigger mode. 
		 * @param[in] pri 中断优先级。interrupt priority.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI0_Init(EXTITri_Type triMode,NVICPri_Type pri,BOOL run);


		/**
		 * @brief      外部中断1中断初始化函数。
		 * @details    EXTI1 NVIC function.
		 * @param[in] triMode  触发模式。Trigger mode. 
		 * @param[in]  pri 中断优先级。interrupt priority.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI1_Init(EXTITri_Type triMode,NVICPri_Type pri,BOOL run);


		/**
		 * @brief      外部中断2中断初始化函数，固定下降沿触发。
		 * @details    EXTI2 NVIC function.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI2_Init(BOOL run);


		/**
		 * @brief      外部中断3中断初始化函数，固定下降沿触发。
		 * @details    EXTI3 NVIC function.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI3_Init(BOOL run);


		/**
		 * @brief      外部中断4中断初始化函数，固定下降沿触发。
		 * @details    EXTI4 NVIC function.
		 * @param[in]  pri 中断优先级。interrupt priority.
		 * @param[in]  run 使能控制位。enable control. 
		 * @return     FSC_SUCCESS 返回成功。Return to success.
		 * @return     FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_EXTI4_Init(NVICPri_Type pri,BOOL run);


		/**
		 * @brief    外部中断0控制中断开关宏函数。
		 * @details   External interrupt 0 controls interrupt switch macro function. 
		 * @param[in] run 使能控制位。enable control. 
		**/
		#define    NVIC_EXTI0_CTRL(run)     do{EX0 = run;}while(0)


		/**
		 * @brief      外部中断1控制中断开关宏函数。
		 * @details    External interrupt 1 controls interrupt switch macro function. 
		 * @param[in]  run 使能控制位。enable control. 
		**/
		#define    NVIC_EXTI1_CTRL(run)     do{EX1 = run;}while(0)


		/**
		 * @brief      外部中断2控制中断开关宏函数。
		 * @details    External interrupt 2 controls interrupt switch macro function. 
		 * @param[in]  run 使能控制位。enable control. 
		**/
		#define    NVIC_EXTI2_CTRL(run)     do{INTCLKO = (INTCLKO & 0xEF) | (run << 4);}while(0)


		/**
		 * @brief      EXTI0选择中断优先级宏函数。
		 * @details    EXTI0 select interrupt priority macro function.
		 * @param[in]  pri 中断优先级。 Priority of interrupt.
		**/
		#define NVIC_EXTI0_PRI(pri)                   \
		do{                                           \
			IPH = (IPH & 0xFE) | ((pri & 0x02) >> 1); \
			IP  = (IP  & 0xFE) | (pri & 0x01);        \
		}while(0)


		/**
		 * @brief      EXTI1选择中断优先级宏函数。
		 * @details    EXTI1 select interrupt priority macro function.
		 * @param[in]  pri 中断优先级。 Priority of interrupt.
		**/
		#define NVIC_EXTI1_PRI(pri)                   \
		do{                                           \
			IPH = (IPH & 0xFB) | ((pri & 0x02) << 1); \
			IP  = (IP  & 0xFB) | ((pri & 0x01) << 2); \
		}while(0)
		
		/**
		 * @brief      EXTI4选择中断优先级宏函数。
		 * @details    EXTI4 select interrupt priority macro function.
		 * @param[in]  pri 中断优先级。 Priority of interrupt.
		**/
		#define NVIC_EXTI4_PRI(pri)                    \
		do{                                            \
            IP2H = (IPH & 0xEF) | ((pri & 0x02) << 3); \
            IP2  = (IP  & 0xEF) | ((pri & 0x01) << 4); \
		}while(0)

		/**
		 * @brief      外部中断3控制中断开关宏函数。
		 * @details    External interrupt 3 controls interrupt switch macro function. 
		 * @param[in]  run 使能控制位。enable control. 
		**/
		#define    NVIC_EXTI3_CTRL(run)     do{INTCLKO = (INTCLKO & 0xDF) | (run << 5);}while(0)


		/**
		 * @brief      外部中断4控制中断开关宏函数。
		 * @details    External interrupt 4 controls interrupt switch macro function. 
		 * @param[in]  run 使能控制位。enable control. 
		**/
		#define    NVIC_EXTI4_CTRL(run)    do{INTCLKO = (INTCLKO & 0xBF) | (run << 6);}while(0)

	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/
#endif
