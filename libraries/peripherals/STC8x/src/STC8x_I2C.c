/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_I2C.c
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
#include "STC8x_I2C.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/
#if (PER_LIB_I2C_CTRL == 1)

	/**
	 * @brief     延时us函数，帮助稳定I2C外设切换工作状态。
	 * @details   I2C delay us function.
	 * @param[in] nus 延时us的时间。The time of delay.
	 * @return    None.
	**/
	static void I2C_Delay_us(uint8_t nus)
	{
		uint8_t i;
		while(nus--)
		{
			i = 6;
			while (--i);
		}  
	}


	/**
	 * @brief   计算I2C等待时间函数。
	 * @details I2C wait time function.
	 * @param   None.
	 * @return  FSC_SUCCESS 返回成功。Return to success.
	 * @return  FSC_FAIL    返回失败。Return to fail.
	**/
	static FSCSTATE I2C_Wait(void)
	{
		uint8_t count = 0;
		while (!(I2CMSST & 0x40))
		{
			I2C_Delay_us(1);
			if(count++ >= 30) //等待超过30us，则退出等待。
			{
				count = 0;
				return FSC_FAIL;
			}
		}
		I2CMSST &= 0xBF;
		return FSC_SUCCESS;  
	}

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
		FSCSTATE I2C_Init(I2CType_Type type, uint8_t wTime, BOOL run)
		{
		  if(wTime <= 0x3F)
		  {
			EAXFR_ENABLE();
			I2CCFG = (I2CCFG & 0xBF) | (type << 6);
			I2CCFG = (I2CCFG & 0xC0) | (wTime);
			I2CCFG = (I2CCFG & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}
		
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
		FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type pri,BOOL run)
		{
			EAXFR_ENABLE();
			NVIC_I2C_PRI(pri);
			I2CMSCR = run << 7;
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}


		/**
		 * @brief     I2C从机中断初始化函数。
		 * @details   I2C Slave init NVIC function.  
		 * @param[in] pri      中断优先级。interrupt priority.
		 * @param[in] triMode  触发模式，可以选择多个，并用或运算符连接。
		 *                     Trigger mode, multiple can be selected 
		 *                     and connected with or operator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type pri,I2CSTri_Type triState)
		{
			EAXFR_ENABLE();
			NVIC_I2C_PRI(pri);
			I2CSLCR &= (I2CSLCR & 0x01 )| (triState);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}
	
	#endif
		
	#if (PER_LIB_I2C_WORK_CTRL == 1)	
		
		/**
		 * @brief   I2C发送开始信号函数。
		 * @details I2C sends signal of start function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_Start(void)
		{
		  I2CMSCR = 0x01;    
		  return I2C_Wait();
		}


		/**
		 * @brief   I2C发送停止信号函数。
		 * @details I2C sends signal of stop function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_Stop(void)
		{
		  I2CMSCR = 0x06;                          
		  return I2C_Wait();
		}


		/**
		 * @brief   I2C发送ACK信号函数。
		 * @details I2C sends signal of ACK function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_ACK(void)
		{
		  I2CMSST = 0x00;                            
		  I2CMSCR = 0x05;    
		  return I2C_Wait();
		}


		/**
		 * @brief   I2C发送NACK信号函数。
		 * @details I2C sends signal of NACK function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_NACK(void)
		{
		  I2CMSST = 0x01;                          
		  I2CMSCR = 0x05;                           
		  I2C_Wait();
		  return FSC_SUCCESS;
		}


		/**
		 * @brief   I2C读取ACK信号函数。
		 * @details I2C reads signal of ACK function.  
		 * @param   None. 
		 * @return  FSC_SUCCESS 返回成功。Return to success.
		 * @return  FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Read_ACK(void)
		{
		  I2CMSCR = 0x03;                             
		  return I2C_Wait();
		}


		/**
		 * @brief     I2C发送一个字节函数。
		 * @details   I2C sends a byte data function.  
		 * @param[in] dat 字节数据。byte data.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE I2C_Send_Btye(uint8_t dat)
		{
		  I2CTXD = dat;
		  I2CMSCR = 0x02;
		  return I2C_Wait();
		}


		/**
		 * @brief   I2C读取一个字节函数。
		 * @details I2C reads a byte data function.  
		 * @param   None.
		 * @return  [uint8_t] data of recive.
		**/
		uint8_t I2C_Read_Byte(void)       
		{
			I2CMSCR = 0x04;     //发送RECV命令
			I2C_Wait();
			return I2CRXD;
		}


		/**
		 * @brief     I2C切换复用IO函数。
		 * @details   I2C switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port)
		{
			P_SW2 = (P_SW2 & 0xC0) | (port << 4);
			return FSC_FAIL;
		}
	
	#endif
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



