/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_I2C.h
  - Author        : zeweni
  - Update date   : 2020.02.06                 
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
#ifndef __STC8x_I2C_H_
#define __STC8x_I2C_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
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


#ifndef PER_LIB_I2C_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_I2C_CTRL 1
#endif


#ifndef PER_LIB_I2C_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_I2C_INIT_CTRL 1
#endif


#ifndef PER_LIB_I2C_NVIC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_I2C_NVIC_CTRL 1
#endif


#ifndef PER_LIB_I2C_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_I2C_WORK_CTRL 1
#endif


/** 
 * @brief	 I2C工作类型枚举体。
 * @details	 I2C type control enumenumeration.
**/
typedef enum
{
	I2C_Type_Host  = 0x01,   /*!< I2C工作在主机类型。I2C works in the host type.*/
	I2C_Type_Slave = 0x00    /*!< I2C工作在从机类型。I2C works in the slave type.*/
} I2CType_Type;


/*--------------------------------------------------------
| @Description: I2C slave interrupt Trigger enum         |
--------------------------------------------------------*/

/** 
 * @brief    I2C从机中断触发方式枚举体。
 * @details	 I2C slave interrupt trigger mode enumeration body.
**/
typedef enum
{
	I2C_STri_RevStart_Done  = 0x40,  /*!< I2C从机接收START完成中断。I2C slave receives START completion interrupt. */
	I2C_STri_RevData_Done   = 0x20,  /*!< I2C从机接收数据完成中断。The I2C slave receives data and is interrupted. */
	I2C_STri_SendData_Done  = 0x10,  /*!< I2C从机发送数据完成中断。The I2C slave is interrupted when sending data. */
	I2C_STri_RevStop_Done   = 0x80   /*!< I2C从机接收STOP完成中断。The I2C slave receives the STOP completion interrupt.*/
} I2CSTri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_I2C_CTRL == 1)
	
	#if (PER_LIB_I2C_INIT_CTRL == 1)

		/**
		 * @brief     I2C初始化函数。
		 * @details   I2C initialization function.
		 * @param[in] type  I2C工作模式（主从机）。I2C working mode (master-slave).
		 * @param[in] wTime I2C等待时间。value of wait time.
		 * @param[in] run   运行控制位。Operation control bit.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Init(I2CType_Type type, uint8_t wTime, BOOL state);

	#endif

	#if (PER_LIB_I2C_NVIC_CTRL == 1)
	
		/**
		 * @brief     I2C主机中断初始化函数。
		 * @details   I2C Master init NVIC function.  
		 * @param[in] pri 中断优先级。interrupt priority.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type pri,BOOL run);
		
		
		/**
		 * @brief   I2C从机中断初始化函数。
		 * @details I2C Slave init NVIC function.  
		 * @param[in] pri      中断优先级。interrupt priority.
		 * @param[in] triMode  触发模式，可以选择多个，并用或运算符连接。
		 *                     Trigger mode, multiple can be selected 
		 *                     and connected with or operator.
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type pri,I2CSTri_Type triMode);
		

		/**
		 * @brief     I2C主机中断开关控制宏函数。
		 * @details   I2C host interrupt switch control macro function.
		 * @param[in] run 使能控制位。Enable control bit.
		**/
		#define    NVIC_I2C_HOST_CTRL(run)      \
		{                                       \
			EAXFR_ENABLE();	                    \
			I2CMSCR = run << 7;                 \
			EAXFR_DISABLE();                    \
		}

		/**
		 * @brief     I2C从机中断开关控制宏函数。
		 * @details   I2C slave interrupt switch control macro function.
		 * @param[in] run  使能控制位。Enable control bit.
		**/
		#define    NVIC_I2C_SLAVE_CTRL(run)     \
		{                                       \
			EAXFR_ENABLE();                     \
			I2CSLCR &= (I2CSLCR & 0x01 ) |      \
				 (run << 6) | (run << 5) |      \
				 (run << 4) | (run << 3) ;      \
			EAXFR_DISABLE();                    \
		}
		
		
		/**
		 * @brief      I2C选择中断优先级宏函数。
		 * @details    I2C select interrupt priority macro function.
		 * @param[in]  pri 中断优先级。 Priority of interrupt.
		***/
		#define NVIC_I2C_PRI(pri)                       \
		do{                                             \
			IP2H = (IP2H & 0xBF) | ((pri & 0x02) << 5); \
			IP2  = (IP2  & 0xBF) | ((pri & 0x01) << 6); \
		}while(0)		

		
		/**
		 * @brief   I2C获取主机中断请求标志位宏函数。
		 * @details I2C gets host interrupt request flag bit macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.  
		**/
		#define I2C_GET_HOST_FLAG()           (I2CMSST & 0x40)


		/**
		 * @brief   I2C获取主机忙/空闲状态宏函数。
		 * @details I2C get the host working state (busy / idle) macro function.
		 * @return  [bit] 0代表控制器处于空闲状态，1代表处于忙碌状态。
		 *                0 means the controller is idle and 1 means it is busy.
		**/
		#define I2C_GET_HOST_BUSY_STATE()           (I2CMSST & 0x80)


		/**
		 * @brief   I2C清除主机中断请求标志位宏函数。
		 * @details I2C clears host interrupt request flag bit macro function. 
		**/
		#define I2C_CLEAR_HOST_MASTER_FLAG()         {I2CMSST &= 0xBF;}


		/**
		 * @brief   I2C获取从机状态（忙/空闲）宏函数。
		 * @details I2C get the slave working state (busy / idle) macro function.
		 * @return  [bit] 0代表控制器处于空闲状态，1代表处于忙碌状态。
		 *                0 means the controller is idle and 1 means it is busy.
		**/
		#define I2C_GET_SLAVE_BUSY_STATE()           (I2CMSST & 0x80)


		/**
		 * @brief   I2C获取，从机接收开始信号中断请求标志位，宏函数。
		 * @details I2C acquisition, slave receives start signal, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_GET_SLAVE_REVSTART_FLAG()         (I2CSLST & 0x40)


		/**
		 * @brief   I2C获取，从机接收一字节数据中断请求标志位，宏函数。
		 * @details I2C acquisition, slave receives one byte data, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_GET_SLAVE_REVDATA_FLAG()          (I2CSLST & 0x20)


		/**
		 * @brief   I2C获取，从机发送一字节数据中断请求标志位，宏函数。
		 * @details I2C acquisition, slave sends one byte data, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_GET_SLAVE_SENDATA_FLAG()          (I2CSLST & 0x10)


		/**
		 * @brief   I2C获取，从机接收停止信号中断请求标志位，宏函数。
		 * @details I2C acquisition, slave receives stop signal, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_GET_SLAVE_REVSTOP_FLAG()          (I2CSLST & 0x08)


		/**
		 * @brief   I2C清除，从机接收开始信号中断请求标志位，宏函数。
		 * @details I2C clears the slave receives start signal, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_CLEAR_SLAVE_REVSTART_FLAG()       {I2CSLST &= 0xBF;}


		/**
		 * @brief   I2C清除，从机接收一字节数据中断请求标志位，宏函数。
		 * @details I2C clears the slave receives one byte data, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_CLEAR_SLAVE_REVDATA_FLAG()        {I2CSLST &= 0xDF;}


		/**
		 * @brief   I2C清除，从机发送一字节数据中断请求标志位，宏函数。
		 * @details I2C clears the slave sends one byte data, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_CLEAR_SLAVE_SENDATA_FLAG()        {I2CSLST &= 0xEF;}


		/**
		 * @brief   I2C清除，从机接收停止信号中断请求标志位，宏函数。
		 * @details I2C clears the slave receives stop signal, 
		 *          interrupt request flag bit, macro function.
		 * @return  [bit] （中断）标志位。(interrupt) flag bit.
		**/
		#define I2C_CLEAR_SLAVE_REVSTOP_FLAG()        {I2CSLST &= 0xF7;}

	#endif
	
	#if (PER_LIB_I2C_WORK_CTRL == 1)	
		
		/**
		 * @brief   I2C发送开始信号函数。
		 * @details I2C sends signal of start function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_Start(void);
			
		/**
		 * @brief   I2C发送停止信号函数。
		 * @details I2C sends signal of stop function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_Stop(void);
			
			
		/**
		 * @brief   I2C发送ACK信号函数。
		 * @details I2C sends signal of ACK function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_ACK(void);
			
			
		/**
		 * @brief   I2C发送NACK信号函数。
		 * @details I2C sends signal of NACK function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_NACK(void);
			
			
		/**
		 * @brief   I2C读取ACK信号函数。
		 * @details I2C reads signal of ACK function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Read_ACK(void);
			
			
		/**
		 * @brief     I2C发送一个字节函数。
		 * @details   I2C sends a byte data function.  
		 * @param[in] dat 字节数据。byte data.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_Btye(uint8_t dat);
			
			
		/**
		 * @brief   I2C读取一个字节函数。
		 * @details I2C reads a byte data function.  
		 * @param   None.
		 * @return  [uint8_t] data of recive.
		**/
		uint8_t I2C_Read_Byte(void);

			
		/**
		 * @brief     I2C切换复用IO函数。
		 * @details   I2C switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port);

	#endif
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
