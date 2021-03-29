/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : drv_oled.h
  - Author        : zeweni
  - Update date   : 2020.12.20                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
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

#ifndef __DEV_OLED_H_
#define __DEV_OLED_H_

#include "STC8x_GPIO.h"
#include "STC8x_TYPE.h"
#include "STC8x_CORE.h"
#include "STC8x_SPI.h"
#include "STC8x_NVIC.h"
#include "PreDelay.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: OLED transmission state define           |
--------------------------------------------------------*/

typedef enum
{
  OLED_Tran_Cmd,  /* OLED write cmd  */
  OLED_Tran_Data  /* OLED write data */
} OLEDTran_Type;

#define X_WIDTH 	128
#define Y_WIDTH 	64

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: OLED Hardware SPI init define            |
--------------------------------------------------------*/

/* Hardware SPI init contral */
#define OLED_SPI_HARDWARE        1  // 1 enable / 0 disable

/* Hardware SPI init option */
#define   SPI_SPEED          SPI_SCLK_DIV_4
#define   SPI_PORT_SWITCH    SW_Port2 

/*--------------------------------------------------------
| @Description: OLED Software SPI init define            |
--------------------------------------------------------*/

/* Software SPI init contral */
#define OLED_SPI_SOFTWARE        0  // 1 enable / 0 disable

/*--------------------------------------------------------
| @Description: OLED PIN define                          |
--------------------------------------------------------*/
/*
  SPI Port2:
  DO(SCL)  ->  P3.2
  DI(SDA)  ->  P3.4
  CS       ->  P3.5
  OLED Pin:
  DC       ->  P2.5
  RST      ->  P2.7
*/
#define   OLED_RST      P27
#define   OLED_SCL      P32       
#define   OLED_SDA      P34       
#define   OLED_DC       P25         
#define   OLED_CS       P35

/*--------------------------------------------------------
| @Description: OLED control function                    |
--------------------------------------------------------*/

FSCSTATE OLED_Init(void);
void OLED_Refresh_Gram(void);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);

/*--------------------------------------------------------
| @Description: OLED working function                    |
--------------------------------------------------------*/

uint8 OLED_Write_Byte(uint8 Dat,OLEDTran_Type State);
void OLED_Fill(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 dot);
void OLED_Show_Char_1608(uint8 x,uint8 y,uint8 Chr);
void OLED_Show_String_1608(uint8 x,uint8 y,const uint8 *Str);
void OLED_Show_Num_1608(uint8 x,uint8 y,uint32 num,uint8 len);
void OLED_Show_Float_1608(uint8 x,uint8 y,float num,uint8 len,uint8 Acc);

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/

