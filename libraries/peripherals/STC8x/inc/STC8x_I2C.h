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
 * Apache-2.0 License License for more details.

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
#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

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
/*--------------------------------------------------------
| @Description: I2C type control enum                    |
--------------------------------------------------------*/

typedef enum
{
  I2C_Type_Host = 0x01,
  I2C_Type_Slave  = 0x00
} I2CType_Type;


/*--------------------------------------------------------
| @Description: I2C slave interrupt Trigger enum         |
--------------------------------------------------------*/

typedef enum
{
  I2C_STri_RevStart_Done  = 0x40,
  I2C_STri_RevData_Done   = 0x20,
  I2C_STri_SendData_Done  = 0x10,
  I2C_STri_RevStop_Done   = 0x80
} I2CSTri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/**
 * @name    I2C_Init
 * @brief   I2C初始化函数。
 *          I2C initialization function.
 * @param   type  [IN] I2C工作模式（主从机）。I2C working mode (master-slave).
 * @param   wTime [IN] I2C等待时间。value of wait time.
 * @param   run   [IN] 运行控制位。Operation control bit.
 * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Init(I2CType_Type type, uint8_t wTime, BOOL state);

/**
  * @name    NVCI_I2C_Master_Init
  * @brief   I2C主机中断初始化函数。
  *          I2C Master init NVIC function.  
  * @param   priority [IN] 中断优先级。interrupt priority.
  * @param   run      [IN] 使能控制位。enable control. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type priority,BOOL run);

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
FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type priority,I2CSTri_Type triMode);


/**
  * @name    NVIC_I2C_HOST_CTRL
  * @brief   I2C主机中断开关控制宏函数。
  *          I2C host interrupt switch control macro function.
  * @param   run [BOOL] 使能控制位。Enable control bit.
***/
#define    NVIC_I2C_HOST_CTRL(run)      \
{                                       \
	EAXFR_ENABLE();	                    \
	I2CMSCR = run << 7;                 \
	EAXFR_DISABLE();                    \
}

/**
  * @name    NVIC_I2C_SLAVE_CTRL
  * @brief   I2C从机中断开关控制宏函数。
  *          I2C slave interrupt switch control macro function.
  * @param   run [BOOL] 使能控制位。Enable control bit.
***/
#define    NVIC_I2C_SLAVE_CTRL(run)     \
{                                       \
	EAXFR_ENABLE();                     \
	I2CSLCR &= (I2CSLCR & 0x01 ) |      \
	     (run << 6) | (run << 5) |      \
	     (run << 4) | (run << 3) ;      \
	EAXFR_DISABLE();                    \
}


/**
  * @name    I2C_GET_HOST_FLAG
  * @brief   I2C获取主机中断请求标志位宏函数。
  *          I2C gets host interrupt request flag bit macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.  
***/
#define I2C_GET_HOST_FLAG()           (I2CMSST & 0x40)


/**
  * @name    I2C_GET_HOST_BUSY_STATE
  * @brief   I2C获取主机忙/空闲状态宏函数。
  *          I2C get the host working state (busy / idle) macro function.
  * @retval  [bit] 0代表控制器处于空闲状态，1代表处于忙碌状态。
  *                0 means the controller is idle and 1 means it is busy.
***/
#define I2C_GET_HOST_BUSY_STATE()           (I2CMSST & 0x80)


/**
  * @name    I2C_CLEAR_HOST_MASTER_FLAG
  * @brief   I2C清除主机中断请求标志位宏函数。
  *          I2C clears host interrupt request flag bit macro function. 
***/
#define I2C_CLEAR_HOST_MASTER_FLAG()         {I2CMSST &= 0xBF;}


/**
  * @name    I2C_GET_SLAVE_BUSY_STATE
  * @brief   I2C获取从机状态（忙/空闲）宏函数。
  *          I2C get the slave working state (busy / idle) macro function.
  * @retval  [bit] 0代表控制器处于空闲状态，1代表处于忙碌状态。
  *                0 means the controller is idle and 1 means it is busy.
***/
#define I2C_GET_SLAVE_BUSY_STATE()           (I2CMSST & 0x80)


/**
  * @name    I2C_GET_SLAVE_REVSTART_FLAG
  * @brief   I2C获取，从机接收开始信号中断请求标志位，宏函数。
  *          I2C acquisition, slave receives start signal, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_GET_SLAVE_REVSTART_FLAG()         (I2CSLST & 0x40)


/**
  * @name    I2C_GET_SLAVE_REVDATA_FLAG
  * @brief   I2C获取，从机接收一字节数据中断请求标志位，宏函数。
  *          I2C acquisition, slave receives one byte data, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_GET_SLAVE_REVDATA_FLAG()          (I2CSLST & 0x20)


/**
  * @name    I2C_GET_SLAVE_SENDATA_FLAG
  * @brief   I2C获取，从机发送一字节数据中断请求标志位，宏函数。
  *          I2C acquisition, slave sends one byte data, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_GET_SLAVE_SENDATA_FLAG()          (I2CSLST & 0x10)


/**
  * @name    I2C_GET_SLAVE_REVSTART_FLAG
  * @brief   I2C获取，从机接收停止信号中断请求标志位，宏函数。
  *          I2C acquisition, slave receives stop signal, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_GET_SLAVE_REVSTOP_FLAG()          (I2CSLST & 0x08)


/**
  * @name    I2C_CLEAR_SLAVE_REVSTART_FLAG
  * @brief   I2C清除，从机接收开始信号中断请求标志位，宏函数。
  *          I2C clears the slave receives start signal, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_CLEAR_SLAVE_REVSTART_FLAG()       {I2CSLST &= 0xBF;}


/**
  * @name    I2C_CLEAR_SLAVE_REVDATA_FLAG
  * @brief   I2C清除，从机接收一字节数据中断请求标志位，宏函数。
  *          I2C clears the slave receives one byte data, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_CLEAR_SLAVE_REVDATA_FLAG()        {I2CSLST &= 0xDF;}


/**
  * @name    I2C_CLEAR_SLAVE_SENDATA_FLAG
  * @brief   I2C清除，从机发送一字节数据中断请求标志位，宏函数。
  *          I2C clears the slave sends one byte data, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_CLEAR_SLAVE_SENDATA_FLAG()        {I2CSLST &= 0xEF;}


/**
  * @name    I2C_CLEAR_SLAVE_REVSTOP_FLAG
  * @brief   I2C清除，从机接收停止信号中断请求标志位，宏函数。
  *          I2C clears the slave receives stop signal, 
  *          interrupt request flag bit, macro function.
  * @retval  [bit] （中断）标志位。(interrupt) flag bit.
***/
#define I2C_CLEAR_SLAVE_REVSTOP_FLAG()        {I2CSLST &= 0xF7;}


/**
  * @name    I2C_Send_Start
  * @brief   I2C发送开始信号函数。
  *          I2C sends signal of start function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_Start(void);
	
/**
  * @name    I2C_Send_Stop
  * @brief   I2C发送停止信号函数。
  *          I2C sends signal of stop function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_Stop(void);
	
	
/**
  * @name    I2C_Send_ACK
  * @brief   I2C发送ACK信号函数。
  *          I2C sends signal of ACK function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_ACK(void);
	
	
/**
  * @name    I2C_Send_NACK
  * @brief   I2C发送NACK信号函数。
  *          I2C sends signal of NACK function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_NACK(void);
	
	
/**
  * @name    I2C_Read_ACK
  * @brief   I2C读取NACK信号函数。
  *          I2C reads signal of NACK function.  
  * @param   None. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Read_ACK(void);
	
	
/**
  * @name    I2C_Send_Btye
  * @brief   I2C发送一个字节函数。
  *          I2C sends a byte data function.  
  * @param   dat [IN] 字节数据。byte data.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE I2C_Send_Btye(uint8_t dat);
	
	
/**
  * @name    I2C_Read_Byte
  * @brief   I2C读取一个字节函数。
  *          I2C reads a byte data function.  
  * @param   None.
  * @retval  [uint8_t]data of recive
***/
uint8_t I2C_Read_Byte(void)  ;

	
/**
  * @name    GPIO_I2C_SWPort
  * @brief   I2C切换复用IO函数。
  *          I2C switch out port control function.  
  * @param   port [IN] 复用IO枚举体。IO switch enumerator.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port);



#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

