/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : drv_oled.c
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
#include "drv_oled.h"
#include "drv_oled_font.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: OLED init function                       |
| @param      : None                                     |
| @return     : FSCSTATE : Success / Fail                |
--------------------------------------------------------*/

FSCSTATE OLED_Init(void)
{
	/* Hardware SPI init */
	#if   ((OLED_SPI_HARDWARE == 1) && ( OLED_SPI_SOFTWARE  == 0))
	{
		SPIInit_Type SPI_InitStruct = {0};

		GPIO_MODE_OUT_PP(GPIO_P3,OLED_GPIO_SCL | OLED_GPIO_SDA | OLED_GPIO_RST | OLED_GPIO_DC | OLED_GPIO_CS);
		
		GPIO_SPI_SWPort(SPI_PORT_SWITCH);
		
		SPI_InitStruct.Type = SPI_Type_Master;
		SPI_InitStruct.ClkSrc = SPI_SPEED;
		SPI_InitStruct.Mode = SPI_Mode_0;
		SPI_InitStruct.Tran = SPI_Tran_MSB;
		SPI_InitStruct.Run = ENABLE;
		SPI_Init(&SPI_InitStruct);
	}
	/* Software SPI init */
	#elif ((OLED_SPI_HARDWARE == 0) && ( OLED_SPI_SOFTWARE  == 1))
	{
		GPIO_MODE_OUT_PP(GPIO_P3,OLED_GPIO_SCL | OLED_GPIO_SDA | OLED_GPIO_RST | OLED_GPIO_DC | OLED_GPIO_CS); 
	}
	#endif

    delay_ms(10);
    OLED_CS=1;
	delay_ms(10);
	OLED_CS=0;

	OLED_RST=1;
	delay_ms(100);
	OLED_RST=0;
	delay_ms(100);
	OLED_RST=1; 
					  
	OLED_Write_Byte(0xAE,OLED_Tran_Cmd); //Turn off the display
	OLED_Write_Byte(0xD5,OLED_Tran_Cmd); //Set clock frequency division factor, oscillation frequency
	OLED_Write_Byte(80,OLED_Tran_Cmd);   //[3:0], frequency division factor; [7:4], oscillation frequency
	OLED_Write_Byte(0xA8,OLED_Tran_Cmd); //Set the number of driving routes
	OLED_Write_Byte(0X3F,OLED_Tran_Cmd); //Default 0x3f (1 / 64)
	OLED_Write_Byte(0xD3,OLED_Tran_Cmd); //Set display offset
	OLED_Write_Byte(0X00,OLED_Tran_Cmd); //The default is 0

	OLED_Write_Byte(0x40,OLED_Tran_Cmd); //Set display start line [5:0], line number
											
	OLED_Write_Byte(0x8D,OLED_Tran_Cmd); //Charge pump settings
	OLED_Write_Byte(0x14,OLED_Tran_Cmd); //Bit2, on / off
	OLED_Write_Byte(0x20,OLED_Tran_Cmd); //Set memory address mode
	OLED_Write_Byte(0x02,OLED_Tran_Cmd); //[1:0], 00, column address mode; 01, row address mode; 10, page address mode; default 10;
	OLED_Write_Byte(0xA1,OLED_Tran_Cmd); //Segment redefinition settings, bit0: 0,0 - > 0; 1,0 - > 127;
	OLED_Write_Byte(0xC0,OLED_Tran_Cmd); //Set com scanning direction; bit3:0, normal mode; 1, redefinition mode com [n-1] - > COM0; N: number of driving paths
	OLED_Write_Byte(0xDA,OLED_Tran_Cmd); //Set com hardware pin configuration
	OLED_Write_Byte(0x12,OLED_Tran_Cmd); //[5:4] configuration
		 
	OLED_Write_Byte(0x81,OLED_Tran_Cmd); //Contrast setting
	OLED_Write_Byte(0xEF,OLED_Tran_Cmd); //1 ~ 255; the default value is 0 x 7F (brightness setting, the larger the brightness)
	OLED_Write_Byte(0xD9,OLED_Tran_Cmd); //Set precharge cycle
	OLED_Write_Byte(0xf1,OLED_Tran_Cmd); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_Write_Byte(0xDB,OLED_Tran_Cmd); //Setting vcomh voltage multiplier
	OLED_Write_Byte(0x30,OLED_Tran_Cmd); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;
	OLED_Write_Byte(0xA4,OLED_Tran_Cmd); //Global display on; bit0:1, on; 0, off; (white / black screen)
	OLED_Write_Byte(0xA6,OLED_Tran_Cmd); //Set display mode; bit0:1, inverse display; 0, normal display
	OLED_Write_Byte(0xAF,OLED_Tran_Cmd); //Turn on the display
	OLED_Clear();

	return FSC_SUCCESS;
}

/*--------------------------------------------------------
| @Description: OLED write byte function                 |
| @param      : uint8_t Dat,OLEDTran_Type State            |
| @return     : SPI data                                 |
--------------------------------------------------------*/

uint8_t OLED_Write_Byte(uint8_t dat,OLEDTran_Type state)
{
  	
	
	#if   ((OLED_SPI_HARDWARE == 1) && ( OLED_SPI_SOFTWARE  == 0))
	{
		OLED_DC = state;
		OLED_CS = 0;
		SPDAT = dat;
		while (!(SPI_GET_FLAG()));      
		SPI_CLEAR_FLAG();
		OLED_CS = 1;
	}
	/* Software SPI init */
	#elif ((OLED_SPI_HARDWARE == 0) && ( OLED_SPI_SOFTWARE  == 1))
	{
		uint8_t i;
		OLED_DC = state;
		OLED_CS = 0;
		
		for(i=0;i<8;i++)
		{			  
			OLED_SCL = 0;
			if(dat&0x80)
			{
				OLED_SDA = 1;
			}
			else
			{
				OLED_SDA = 0;
			}
			
			OLED_SCL = 1;
			dat<<=1;   		
		}
		OLED_CS = 1;
	}
	#endif

  	return SPDAT;
}

/*--------------------------------------------------------
| @Description: OLED refresh gram function               |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void OLED_Refresh_Gram(void)
{
	uint8_t i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_Write_Byte(0xB0+i,OLED_Tran_Cmd);    //Set page address (0 ~ 7)
		OLED_Write_Byte(0x00,OLED_Tran_Cmd);      //Set display position column low address
		OLED_Write_Byte(0x10,OLED_Tran_Cmd);      //Set display position column height address
		for(n=0;n<128;n++)OLED_Write_Byte(0,OLED_Tran_Data); 
	}   
}

/*--------------------------------------------------------
| @Description: OLED set pos function                    |
| @param      : uint8_t x, uint8_t y                         |
| @return     : None                                     |
--------------------------------------------------------*/

void OLED_Set_Pos(uint8_t x, uint8_t y) 
{ 
	OLED_Write_Byte(0xB0+y,OLED_Tran_Cmd);
	OLED_Write_Byte(((x&0xF0)>>4)|0x10,OLED_Tran_Cmd);
	OLED_Write_Byte((x&0x0F)|0x01,OLED_Tran_Cmd); 
}   

/*--------------------------------------------------------
| @Description: OLED display on function                 |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void OLED_Display_On(void)
{
	OLED_Write_Byte(0X8D,OLED_Tran_Cmd);  //SET DCDC
	OLED_Write_Byte(0X14,OLED_Tran_Cmd);  //DCDC ON
	OLED_Write_Byte(0XAF,OLED_Tran_Cmd);  //DISPLAY ON
}

/*--------------------------------------------------------
| @Description: OLED display off function                |
| @param      : None                                     |
| @return     : None                                     |
--------------------------------------------------------*/

void OLED_Display_Off(void)
{
	OLED_Write_Byte(0X8D,OLED_Tran_Cmd);  //SET DCDC
	OLED_Write_Byte(0X10,OLED_Tran_Cmd);  //DCDC OFF
	OLED_Write_Byte(0XAE,OLED_Tran_Cmd);  //DISPLAY OFF
}		   

/*--------------------------------------------------------
| @Description: OLED clear function                      |
| @param      : None                                     |
| @return     : None                                     |
| @note       : Clear the screen,the whole screen is     |
|              black!It's like not lighting up the screen|
--------------------------------------------------------*/

void OLED_Clear(void)  
{  
	uint8_t i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_Write_Byte(0xB0+i,OLED_Tran_Cmd);    //Set page address (0 ~ 7)
		OLED_Write_Byte(0x00,OLED_Tran_Cmd);      //Set display position column low address
		OLED_Write_Byte(0x10,OLED_Tran_Cmd);      //Set display position column height address
		for(n=0;n<128;n++)OLED_Write_Byte(0,OLED_Tran_Data); 
	}   
}

/*--------------------------------------------------------
| @Description: OLED draw point function                 |
| @param      : uint8_t x,uint8_t y,uint8_t t                  |
| @return     : FSCSTATE : Success / Fail                |
--------------------------------------------------------*/

FSCSTATE OLED_Draw_Point(uint8_t x,uint8_t y,uint8_t t)
{
	if(x<=127 && y<=63)
	{
		OLED_Set_Pos(x,y);
		OLED_Write_Byte(t,OLED_Tran_Data);
		return FSC_SUCCESS;
	}
  	else return FSC_FAIL;
}

/*--------------------------------------------------------
| @Description: OLED Fill function                       |
| @param      : uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,     |
|               uint8_t dot                                |
| @return     : None                                     |
--------------------------------------------------------*/

void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot)  
{  
	uint8_t x,y;  
	for(x=x1;x<=x2;x++)
	{
		for(y=y1;y<=y2;y++)
		{ 	
			OLED_Draw_Point(x,y,dot);	
		}
	}													    
	OLED_Refresh_Gram();
}

/*--------------------------------------------------------
| @Description: OLED show char 1608 function             |
| @param      : uint8_t x,uint8_t y,uint8_t Chr                |
| @return     : None                                     |
--------------------------------------------------------*/

void OLED_Show_Char_1608(uint8_t x,uint8_t y,uint8_t Chr)
{
	uint8_t i;
	y = 6 - y;
	Chr = Chr - ' ';
	OLED_Set_Pos(x, y);
	for(i=0; i<8; i++) {OLED_Write_Byte(ASCII_16_08[Chr][i+8],OLED_Tran_Data);}
	OLED_Set_Pos(x, y+1);
	for(i=0; i<8; i++) {OLED_Write_Byte(ASCII_16_08[Chr][i],  OLED_Tran_Data);}	
}

/*--------------------------------------------------------
| @Description: OLED show string 1608 function           |
| @param      : uint8_t x,uint8_t y,uint8_t Chr                |
| @return     : FSCSTATE : Success / Fail                |
--------------------------------------------------------*/

void OLED_Show_String_1608(uint8_t x,uint8_t y,const uint8_t *Str)
{
	while (*Str != '\0')
	{
		OLED_Show_Char_1608(x,y,*(Str++));
		x += 8;
	}
}

/*--------------------------------------------------------
| @Description: OLED show number 1608 function           |
| @param      : uint8_t x,uint8_t y,uint8_t Chr                |
| @return     : FSCSTATE : Success / Fail                |
--------------------------------------------------------*/

void OLED_Show_Num_1608(uint8_t x,uint8_t y,uint32_t num,uint8_t len)
{         	
	uint8_t i,Dat;
	for(i=0;i<len;i++)
	{
		Dat = num % 10;
		if(num == 0 && i != 0)
		{
			OLED_Show_Char_1608( x-(8*i) + (len-1)*8, y, ' ' ); 
			continue;
		}
		num = num / 10;
		OLED_Show_Char_1608( x-(8*i) + (len-1)*8, y, Dat+'0') ;
	}
} 

/*--------------------------------------------------------
| @Description: OLED show float 1608 function            |
| @param      : uint8_t x,uint8_t y,uint8_t Chr,uint8_t Acc      |
| @return     : FSCSTATE : Success / Fail                |
--------------------------------------------------------*/

void OLED_Show_Float_1608(uint8_t x,uint8_t y,float num,uint8_t len,uint8_t acc)
{
	uint8_t i,Dat;
	uint32_t Num;
	for(i=0;i<acc;i++) num *= 10;
	Num = num;
	for(i=0;i<=len;i++)
	{
		Dat = Num % 10;
		if(i != acc)
		{
			if(Num == 0 && Dat != 0)
			{	
				OLED_Show_Char_1608( x-(8*i) + (len)*8, y, ' ' ); 
				continue;
			}
			Num = Num / 10;
			OLED_Show_Char_1608( x-(8*i) + (len)*8, y, Dat+'0') ;	
		}
		else OLED_Show_Char_1608( x-(8*i) + (len)*8, y, '.' );
	}
} 

/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/


