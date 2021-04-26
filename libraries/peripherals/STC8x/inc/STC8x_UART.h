/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_UART.h
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
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_UART_H_
#define __STC8x_UART_H_

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
| @Description: ELL library core                         |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: UART mode enum                           |
--------------------------------------------------------*/

typedef enum
{
	UART_SyncShift       = 0x00, //Mode0：Synchronous shift serial
	UART_8bit_BRTx       = 0x01, //Mode1：8-bit data, variable baud rate
	UART_9bit_Fixed_BRTx = 0x02, //Mode2：9-bit data, fixed baud rate
	UART_9bit_BRTx       = 0x03  //Mode3：9-bit data, variable baud rate
}	UARTMode_Type;

/*--------------------------------------------------------
| @Description: UART Baud rate generatorenum             |
--------------------------------------------------------*/

typedef enum
{
	UART_BRT_TIM1 = 0x00,  //Timer 1 as baud rate generator
	UART_BRT_TIM2 = 0x01,	 //Timer 2 as baud rate generator
	UART_BRT_TIM3 = 0x02,	 //Timer 3 as baud rate generator
	UART_BRT_TIM4 = 0x03 	 //Timer 4 as baud rate generator
}	UART_BRTGen_Type;

/*--------------------------------------------------------
| @Description: UART Baud rate Clock mode enum           |
--------------------------------------------------------*/
/*
Timing  1T mode: CPU clock without frequency division
Timing 12T mode: CPU clock 12 frequency division
*/
typedef enum
{
    UART_BRT_1T  = 0x00,
	UART_BRT_12T = 0x01
}	UART_BRTMode_Type;

/**
  * @name    UART_InitType
  * @brief   UART init struct  
  * @param   Mode          Working mode
  * @param   BRTGen        Baud rate generator
  * @param   BRTGenClkDiv  Baud rate generator clock division
  * @param   BRTMode       Baud rate generator clock mode
  * @param   BRTDouble     Double baud rate
  * @param   BaudRate      BaudRate
  * @param   MulitComm     Multi mcu communication
  * @param   Relay         Relay broadcasting
  * @param   RxEnable      Receive enable 
***/
typedef struct 
{
	UARTMode_Type Mode;
	UART_BRTGen_Type BRTGen;
	#if  (PER_LIB_MCU_MUODEL == STC8Cx ||PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
		uint8_t BRTGenClkDiv;   /* just STC8G、STC8H */
	#endif
	UART_BRTMode_Type BRTMode;
	BOOL BRTDouble;
	uint32_t BaudRate;
	BOOL MulitComm;
	BOOL Relay;
	BOOL RxEnable;
}	UART_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: UART busy flag of receive                |
--------------------------------------------------------*/

extern uint8_t UART_BUSY_FLAG;		

#define      UART1_GET_BUSY_FLAG()    UART_BUSY_FLAG & 0x01
#define      UART2_GET_BUSY_FLAG()    UART_BUSY_FLAG & 0x02
#define      UART3_GET_BUSY_FLAG()    UART_BUSY_FLAG & 0x04
#define      UART4_GET_BUSY_FLAG()    UART_BUSY_FLAG & 0x08

#define      UART1_SET_BUSY_FLAG()    UART_BUSY_FLAG |= 0x01
#define      UART2_SET_BUSY_FLAG()    UART_BUSY_FLAG |= 0x02
#define      UART3_SET_BUSY_FLAG()    UART_BUSY_FLAG |= 0x04
#define      UART4_SET_BUSY_FLAG()    UART_BUSY_FLAG |= 0x08

#define    UART1_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG &= 0xFE
#define    UART2_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG &= 0xFD
#define    UART3_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG &= 0xFB
#define    UART4_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG &= 0xF7

/*--------------------------------------------------------
| @Description: UART init function                       |
--------------------------------------------------------*/

FSCSTATE UART1_Init(const UART_InitType *uartx);
FSCSTATE UART2_Init(const UART_InitType *uartx);
FSCSTATE UART3_Init(const UART_InitType *uartx);
FSCSTATE UART4_Init(const UART_InitType *uartx);


#define    UART1_GET_RX_FLAG()    (SCON  & 0x01)
#define    UART2_GET_RX_FLAG()    (S2CON & 0x01)
#define    UART3_GET_RX_FLAG()    (S3CON & 0x01)
#define    UART4_GET_RX_FLAG()    (S4CON & 0x01)
				   		    
#define    UART1_GET_TX_FLAG()    (SCON  & 0x02)
#define    UART2_GET_TX_FLAG()    (S2CON & 0x02)
#define    UART3_GET_TX_FLAG()    (S3CON & 0x02)
#define    UART4_GET_TX_FLAG()    (S4CON & 0x02)

#define	   UART1_CLEAR_RX_FLAG()  SCON  &= ~0x01
#define	   UART2_CLEAR_RX_FLAG()  S2CON &= ~0x01
#define	   UART3_CLEAR_RX_FLAG()  S3CON &= ~0x01
#define	   UART4_CLEAR_RX_FLAG()  S4CON &= ~0x01
   
#define	   UART1_CLEAR_TX_FLAG()  SCON  &= ~0x02
#define	   UART2_CLEAR_TX_FLAG()  S2CON &= ~0x02
#define	   UART3_CLEAR_TX_FLAG()  S3CON &= ~0x02
#define	   UART4_CLEAR_TX_FLAG()  S4CON &= ~0x02

FSCSTATE NVIC_UART1_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVIC_UART2_Init(NVICPri_Type priority,BOOL run);


#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)

	FSCSTATE NVIC_UART3_Init(BOOL run);
	FSCSTATE NVIC_UART4_Init(BOOL run);

#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

	FSCSTATE NVIC_UART3_Init(NVICPri_Type priority,BOOL run);
	FSCSTATE NVIC_UART4_Init(NVICPri_Type priority,BOOL run);

#endif

#define    NVIC_UART1_CTRL(run)     do{ ES = run; }while(0)
#define    NVIC_UART2_CTRL(run)     do{ IE2 = (IE2 & 0xFE) | (run); }while(0)
#define    NVIC_UART3_CTRL(run)     do{ IE2 = (IE2 & 0xF7) | (run << 3); }while(0)
#define    NVIC_UART4_CTRL(run)     do{ IE2 = (IE2 & 0xEF) | (run << 4); }while(0)

/* UART */
FSCSTATE GPIO_UART1_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_UART2_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_UART3_SWPort(GPIOSWPort_Type port);
FSCSTATE GPIO_UART4_SWPort(GPIOSWPort_Type port);

/*--------------------------------------------------------
| @Description: UART working function                    |
--------------------------------------------------------*/

void UART1_Send_Byte(uint8_t dat);
void UART2_Send_Byte(uint8_t dat);
void UART3_Send_Byte(uint8_t dat);
void UART4_Send_Byte(uint8_t dat);

uint8_t UART1_Rev_Byte(void);
uint8_t UART2_Rev_Byte(void);
uint8_t UART3_Rev_Byte(void);
uint8_t UART4_Rev_Byte(void);

void UART1_Send_String(const uint8_t *str);
void UART2_Send_String(const uint8_t *str);
void UART3_Send_String(const uint8_t *str);
void UART4_Send_String(const uint8_t *str);

void UART1_Send_Array(const uint8_t *str,uint16_t len);
void UART2_Send_Array(const uint8_t *str,uint16_t len);
void UART3_Send_Array(const uint8_t *str,uint16_t len);
void UART4_Send_Array(const uint8_t *str,uint16_t len);


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

