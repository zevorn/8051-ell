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
#include "ELL_CORE.h"
#include "STC8x_SPI.h"
#include "PreDelay.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: OLED transmission state define           |
--------------------------------------------------------*/

typedef enum
{
  OLED_Tran_Cmd = 0x00,  /* OLED write cmd  */
  OLED_Tran_Data = 0x01  /* OLED write data */
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
#define OLED_SPI_HARDWARE        0  // 1 enable / 0 disable


/*--------------------------------------------------------
| @Description: OLED Software SPI init define            |
--------------------------------------------------------*/

/* Software SPI init contral */
#define OLED_SPI_SOFTWARE        1  // 1 enable / 0 disable

/*--------------------------------------------------------
| @Description: OLED PIN define                          |
--------------------------------------------------------*/

/*SPI init option */
#define   SPI_SPEED          SPI_SCLK_DIV_8
#define   SPI_PORT_SWITCH    SW_Port3 

#define OLED_GPIO                 GPIO_P3
#define OLED_GPIO_SCL             Pin_2
#define OLED_GPIO_SDA             Pin_4
#define OLED_GPIO_RST             Pin_7
#define OLED_GPIO_DC              Pin_6
#define OLED_GPIO_CS              Pin_5

/*
  SPI Port3:
  D0(SCL)  ->  P3.2
  D1(SDA)  ->  P3.4
  CS       ->  P3.5
  OLED Pin:
  DC       ->  P3.6
  RST      ->  P3.7
*/

#define   OLED_SCL      P32       
#define   OLED_SDA      P34       
#define   OLED_RST      P37
#define   OLED_DC       P36
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

uint8_t OLED_Write_Byte(uint8_t  Dat,OLEDTran_Type State);
void OLED_Fill(uint8_t  x1,uint8_t  y1,uint8_t  x2,uint8_t  y2,uint8_t  dot);
void OLED_Show_Char_1608(uint8_t  x,uint8_t  y,uint8_t  Chr);
void OLED_Show_String_1608(uint8_t  x,uint8_t  y,const uint8_t  *Str);
void OLED_Show_Num_1608(uint8_t  x,uint8_t  y,uint32_t  num,uint8_t  len);
void OLED_Show_Float_1608(uint8_t  x,uint8_t  y,float num,uint8_t  len,uint8_t  Acc);

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/

