/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_SPI.h
  - Author        : zeweni
  - Update date   : 2020.01.29
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
#ifndef __STC8x_SPI_H_
#define __STC8x_SPI_H_

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

/** 如果没有定义这个宏，默认为STC8Ax。
    If the mirco is undefined，select to STC8Ax */
#ifndef PER_LIB_MCU_MUODEL   
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif


/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_SPI_CTRL
    #define PER_LIB_SPI_CTRL 1
#endif


/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_SPI_INIT_CTRL
    #define PER_LIB_SPI_INIT_CTRL 1
#endif


/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_SPI_NVIC_CTRL
    #define PER_LIB_SPI_NVIC_CTRL 1
#endif


/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_SPI_WORK_CTRL
    #define PER_LIB_SPI_WORK_CTRL 1
#endif


/**
 * @brief     SPI工作类型枚举体。
 * @details   SPI type control enum.
**/
typedef enum
{
	SPI_Type_Master_Slave = 0x00,  /*!< SPI互为主从机模式。SPI is mutually master-slave mode. */
	SPI_Type_Master       = 0x90,  /*!< SPI互为主机模式。SPI is mutually master mode. */
	SPI_Type_Slave        = 0x80,  /*!< SPI互为主机模式。SPI is mutually slave mode. */
} SPIType_Type;


/**
 * @brief     SPI时钟源选择枚举体。
 * @details   SPI clock source select enum.
**/
typedef enum
{
	SPI_SCLK_DIV_4  = 0x00,  /*!< SPI系统时钟源4分频。SPI system clock source divided by 4. */
	SPI_SCLK_DIV_8  = 0x01,  /*!< SPI系统时钟源8分频。SPI system clock source divided by 8. */
	SPI_SCLK_DIV_16 = 0x02,  /*!< SPI系统时钟源16分频。SPI system clock source divided by 16. */
	SPI_SCLK_DIV_32 = 0x03   /*!< SPI系统时钟源32分频。SPI system clock source divided by 32. */
} SPIClkSrc_Type;


/**
 * @brief     SPI传输类型枚举体。
 * @details   SPI Transmission sequence enum.
**/
typedef enum
{
	SPI_Tran_MSB = 0x00,   /*!< 数据的最高位存放在字节的第0位。
	                            The highest bit of the data is stored in the 0th bit of the byte. */
	SPI_Tran_LSB = 0x01   /*!< 数据的最低位存放在字节的第0位。
	                           The lowest bit of the data is stored in the 0th bit of the byte. */
} SPITran_Type;


/**
 * @brief     SPI模式枚举体。
 * @details   SPI mode control enum .
**/
typedef enum
{
	SPI_Mode_0  = 0x00, /*!< 模式0。mode 0. */
	SPI_Mode_1  = 0x01, /*!< 模式1。mode 1. */
	SPI_Mode_2  = 0x02, /*!< 模式2。mode 2. */
	SPI_Mode_3  = 0x03  /*!< 模式3。mode 3. */
} SPIMode_Type;


/**
 * @brief   SPI初始化枚举体，需要你定义它，并用它的地址来传参给初始化函数。
 * @details SPI initializes the enumeration body, you need to define 
 *          it and use its address to pass parameters to the initialization function.
**/
typedef struct 
{
	SPIType_Type Type;     /*!< SPI工作类型。SPI working type. */
	SPIClkSrc_Type ClkSrc; /*!< SPI时钟源。SPI clock source. */
	SPIMode_Type Mode;     /*!< SPI工作模式。SPI working mode. */
	SPITran_Type Tran;     /*!< SPI传输类型。SPI transmission type. */
	BOOL Run;             /*!< SPI运行控制位。SPI operation control bit. */
} SPIInit_Type;


/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_SPI_CTRL == 1)

	#if (PER_LIB_SPI_INIT_CTRL == 1)

		/**
		 * @brief     SPI初始化函数。
		 * @details   SPI initialization function. 
		 * @param[in] spix  SPI初始化结构体句柄，你需要定义它，并其地址传参。  
		 *            you need to definean associated initialization handle,
		 *            And pass it by its address.  
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE SPI_Init(const SPIInit_Type *spix);
	
	#endif 
	
	#if (PER_LIB_SPI_NVIC_CTRL == 1)
	
		/**
		 * @brief     SPI中断初始化函数。
		 * @details   SPI init NVIC function.  
		 * @param[in] pri 中断优先级。interrupt priority.
		 * @param[in] run 使能控制位。enable control. 
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE NVIC_SPI_Init(NVICPri_Type pri,BOOL run);


		/**
		 * @brief     SPI中断开关控制宏函数。
		 * @details   SPI interrupt switch control macro function.
		 * @param[in] run  使能控制位。Enable control bit.
		**/
		#define    NVIC_SPI_CTRL(run)    do{ IE2 = (IE2 & 0xFD) | (run << 1); }while(0)

		/**
		 * @brief      SPI选择中断优先级宏函数。
		 * @details    SPI select interrupt pri macro function.
		 * @param[in]  pri 中断优先级。 pri of interrupt.
		**/
		#define NVIC_SPI_PRI(pri)                       \
		do{                                             \
			IP2H = (IP2H & 0xFD) |  (pri & 0x02);       \
			IP2  = (IP2  & 0xFD) | ((pri & 0x01) << 1); \
		}while(0)

	  
		/**
		 * @brief   SPI获取中断标志位宏函数。
		 * @details SPI gets the interrupt flag macro function.
		**/
		#define SPI_GET_FLAG()          (SPSTAT & 0x80)

		/**
		 * @brief   SPI清除中断标志位宏函数。
		 * @details SPI clears the interrupt flag macro function.
		**/
		#define SPI_CLEAR_FLAG()        do{SPSTAT = 0xC0;}while(0)

	#endif
		
	#if (PER_LIB_SPI_WORK_CTRL == 1)
	
		/**
		 * @brief     SPI发送数据（一个字节）函数。
		 * @details   SPI send data function 
		 * @param[in] dat   要发送的数据。 data of SPI.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE SPI_Send_Data(uint8_t dat);


		/**
		 * @brief     SPI接收数据（一个字节）函数。
		 * @details   SPI receive data function. 
		 * @param     None.
		 * @return    [uint8_t] 接收的数据。 receive data. 
		**/
		uint8_t SPI_Receive_Data(void);


		/**
		 * @brief     SPI切换复用IO函数。
		 * @details   SPI switch out port control function.  
		 * @param[in] port 复用IO枚举体。IO switch enumerator.
		 * @return    FSC_SUCCESS 返回成功。Return to success.
		 * @return    FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE GPIO_SPI_SWPort(GPIOSWPort_Type port);
		
	#endif
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
