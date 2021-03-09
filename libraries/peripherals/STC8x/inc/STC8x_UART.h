/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_UART.h
  - Author        : zeweni
  - Update date   : 2020.01.29
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote UART chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *
  *  2020.01.11         zeweni       Update code comment format.
  * 
  *  2020.01.29         zeweni       Optimize library architecture.
  *
***/

#ifndef __STC8x_UART_H_
#define __STC8x_UART_H_
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
#include "STC8x_CORE.h"
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
	#if  (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
		uint8_t BRTGenClkDiv;   /* just STC8G、STC8H */
	#endif
	UART_BRTMode_Type BRTMode;
	FUNSTATE BRTDouble;
	uint32_t BaudRate;
	FUNSTATE MulitComm;
	FUNSTATE Relay;
	FUNSTATE RxEnable;
}	UART_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: UART busy flag of receive                |
--------------------------------------------------------*/

extern vuint8_t UART_BUSY_FLAG[4];		

#define      UART1_GET_BUSY_FLAG()    UART_BUSY_FLAG[0]
#define      UART2_GET_BUSY_FLAG()    UART_BUSY_FLAG[1]
#define      UART3_GET_BUSY_FLAG()    UART_BUSY_FLAG[2]
#define      UART4_GET_BUSY_FLAG()    UART_BUSY_FLAG[3]

#define      UART1_SET_BUSY_FLAG()    UART_BUSY_FLAG[0] = 1
#define      UART2_SET_BUSY_FLAG()    UART_BUSY_FLAG[1] = 1
#define      UART3_SET_BUSY_FLAG()    UART_BUSY_FLAG[2] = 1
#define      UART4_SET_BUSY_FLAG()    UART_BUSY_FLAG[3] = 1

#define    UART1_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG[0] = 0
#define    UART2_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG[1] = 0
#define    UART3_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG[2] = 0
#define    UART4_CLEAR_BUSY_FLAG()    UART_BUSY_FLAG[3] = 0

/*--------------------------------------------------------
| @Description: UART busy flag of receive                |
--------------------------------------------------------*/

#define     CHAR_MAX     64

/*--------------------------------------------------------
| @Description: UART init function                       |
--------------------------------------------------------*/

FSCSTATE UART1_Init(const UART_InitType *uartx);
FSCSTATE UART2_Init(const UART_InitType *uartx);
FSCSTATE UART3_Init(const UART_InitType *uartx);
FSCSTATE UART4_Init(const UART_InitType *uartx);

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

