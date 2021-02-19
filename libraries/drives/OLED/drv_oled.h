/*----------------------------------------------------------------------
  - File name      : drv_oled.h
  - Author         : Quark Team
  - Update date    : 2020-12-20                 
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Header file of oled drive.
-----------------------------------------------------------------------*/
#ifndef __DEV_OLED_H_
#define __DEV_OLED_H_
/*
 * Update note:
 * ------------   ---------------   ------------------------------------
 *     Date            Author                         Note
 * ------------   ---------------   ------------------------------------
 *  2020.12.20         zeweni       Wrote OLED device driver.
 * 
 */

/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_GPIO.h"
#include "STC8x_TYPE.h"
#include "STC8x_CORE.h"
#include "STC8x_SPI.h"
#include "STC8x_NVIC.h"
#include "com_pre_delay.h"
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
#define   SPI_PORT_SWITCH    SW_PORT4  

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

