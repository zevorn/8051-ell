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

/*--------------------------------------------------------
| @Description: I2C priority define function             |
--------------------------------------------------------*/

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
  * @brief   I2C delay function
  * @param   nus   us (uint8_t)
  * @return  None 
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
  * @brief   I2C wait time function 
  * @param   None
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
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
  * @brief   I2C init function
  * @param   type  I2C_Type_Master | I2C_Type_Slave
  * @param   wTime value of wait time (uint8_t)
  * @param   run   ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
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
  * @brief   I2C Master init NVIC function
  * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
  * @param   run        ENABLE | DISABLE
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
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


/**
  * @name    I2C_Start
  * @brief   I2C signal of start function 
  * @param   None
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE I2C_Start(void)
{
  I2CMSCR = 0x01;    
  return I2C_Wait();
}

/**
  * @name    I2C_Stop
  * @brief   I2C signal of stop function 
  * @param   None
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE I2C_Stop(void)
{
  I2CMSCR = 0x06;                          
  return I2C_Wait();
}

/**
  * @name    I2C_Send_ACK
  * @brief   I2C send signal of ACK function 
  * @param   None
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE I2C_Send_ACK(void)
{
  I2CMSST = 0x00;                            
  I2CMSCR = 0x05;    
  return I2C_Wait();
}

/**
  * @name    I2C_Send_NACK
  * @brief   I2C send signal of NACK function 
  * @param   None
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
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
  * @brief   I2C read signal of ACK function 
  * @param   None
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE I2C_Read_ACK(void)
{
  I2CMSCR = 0x03;                             
  return I2C_Wait();
}

/**
  * @name    I2C_Send_Btye
  * @brief   I2C send data function
  * @param   dat byte data
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE I2C_Send_Btye(uint8_t dat)
{
  I2CTXD = dat;
  I2CMSCR = 0x02;
  return I2C_Wait();
}

/**
  * @name    I2C_Read_byte
  * @brief   I2C read data function
  * @param   None
  * @return  data of recive
***/
uint8_t I2C_Read_Byte(void)       
{
    I2CMSCR = 0x04;     //发送RECV命令
    I2C_Wait();
    return I2CRXD;
}


/**
  * @name    GPIO_I2C_SWPort
  * @brief   I2C switch port control function   
  * @param   port    SW_Port1: SCL/P1.5 SDA/P1.4 
  *                  SW_Port2: SCL/P2.5 SDA/P2.4 
  *                  SW_Port3: SCL/P7.7 SDA/P7.6 
  *                  SW_Port4: SCL/P3.2 SDA/P3.3 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port)
{
	P_SW2 = (P_SW2 & 0xC0) | (port << 4);
	return FSC_FAIL;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



