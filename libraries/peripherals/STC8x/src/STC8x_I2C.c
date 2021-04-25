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
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_I2C.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/

/**
 * @name    I2C_NVIC_PRI
 * @brief   I2C选择中断优先级宏函数，仅限本文件调用。
 *          I2C select interrupt priority macro function, 
 *          only this file call.
***/
#define I2C_NVIC_PRI(pri) { \
IP2H = (IP2H & 0xBF) | ((pri & 0x02) << 5); \
IP2  = (IP2  & 0xBF) | ((pri & 0x01) << 6); }

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @name    I2C_Delay_us
 * @brief   延时us函数，帮助稳定I2C外设切换工作状态。
 *          I2C delay us function.
 * @param   nus [IN] 延时us的时间。The time of delay.
 * @retval  None.
***/
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
 * @name    I2C_Wait
 * @brief   计算I2C等待时间函数。
 *          I2C wait time function .
 * @param   None.
 * @retval  [FSC_SUCCESS / FSC_FAIL].
***/
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


/**
 * @name    I2C_Init
 * @brief   I2C初始化函数。
 *          I2C initialization function.
 * @param   type  [IN] I2C工作模式（主从机）。I2C working mode (master-slave).
 * @param   wTime [IN] I2C等待时间。value of wait time.
 * @param   run   [IN] 运行控制位。Operation control bit.
 * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
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


/**
  * @name    NVCI_I2C_Master_Init
  * @brief   I2C主机中断初始化函数。
  *          I2C Master init NVIC function.  
  * @param   priority [IN] 中断优先级。interrupt priority.
  * @param   run      [IN] 使能控制位。enable control. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type priority,BOOL run)
{
	EAXFR_ENABLE();
	I2C_NVIC_PRI(priority);
	I2CMSCR = run << 7;
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}


/**
  * @name    NVCI_I2C_Slave_Init
  * @brief   I2C从机中断初始化函数。
  *          I2C Slave init NVIC function.  
  * @param   priority [IN] 中断优先级。interrupt priority.
  * @param   triMode  [IN] 触发模式，可以选择多个，并用或运算符连接。
  *                        Trigger mode, multiple can be selected 
  *                        and connected with or operator.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type priority,I2CSTri_Type triState)
{
	EAXFR_ENABLE();
	I2C_NVIC_PRI(priority);
	I2CSLCR &= (I2CSLCR & 0x01 )| (triState);
	EAXFR_DISABLE();
	return FSC_SUCCESS;
}


/**
  * @name    I2C_Send_Start
  * @brief   I2C发送开始信号函数。
  *          I2C sends signal of start function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_Start(void)
{
  I2CMSCR = 0x01;    
  return I2C_Wait();
}


/**
  * @name    I2C_Send_Stop
  * @brief   I2C发送停止信号函数。
  *          I2C sends signal of stop function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_Stop(void)
{
  I2CMSCR = 0x06;                          
  return I2C_Wait();
}


/**
  * @name    I2C_Send_ACK
  * @brief   I2C发送ACK信号函数。
  *          I2C sends signal of ACK function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_ACK(void)
{
  I2CMSST = 0x00;                            
  I2CMSCR = 0x05;    
  return I2C_Wait();
}

/**
  * @name    I2C_Send_NACK
  * @brief   I2C发送NACK信号函数。
  *          I2C sends signal of NACK function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_NACK(void)
{
  I2CMSST = 0x01;                          
  I2CMSCR = 0x05;                           
  I2C_Wait();
  return FSC_SUCCESS;
}

/**
  * @name    I2C_Read_ACK
  * @brief   I2C读取NACK信号函数。
  *          I2C reads signal of NACK function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Read_ACK(void)
{
  I2CMSCR = 0x03;                             
  return I2C_Wait();
}


/**
  * @name    I2C_Send_Btye
  * @brief   I2C发送一个字节函数。
  *          I2C sends a byte data function.  
  * @param   dat [IN] 字节数据。byte data.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_Btye(uint8_t dat)
{
  I2CTXD = dat;
  I2CMSCR = 0x02;
  return I2C_Wait();
}


/**
  * @name    I2C_Read_Byte
  * @brief   I2C读取一个字节函数。
  *          I2C reads a byte data function.  
  * @param   None.
  * @retval  [uint8_t]data of recive
***/
uint8_t I2C_Read_Byte(void)       
{
    I2CMSCR = 0x04;     //发送RECV命令
    I2C_Wait();
    return I2CRXD;
}


/**
  * @name    GPIO_I2C_SWPort
  * @brief   I2C切换复用IO函数。
  *          I2C switch out port control function.  
  * @param   port [IN] 复用IO枚举体。IO switch enumerator.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port)
{
	P_SW2 = (P_SW2 & 0xC0) | (port << 4);
	return FSC_FAIL;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



