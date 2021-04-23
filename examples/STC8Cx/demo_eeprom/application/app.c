/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : app.c
  - Author        : zeweni
  - Update date   : 2020.01.11
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "main.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
typedef struct
{
    uint8_t LastInputChannel;
	uint8_t motor_position;
}   PRAM_Type;

PRAM_Type  SystemParam_Write;
PRAM_Type  SystemParam_Read;

static void Read_Flash(PRAM_Type *pRAM);
static void Write_Flash(PRAM_Type *pRAM);
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    eeprom_entry
  * @brief   flash twinkle function
  * @param   None
  * @return  None
***/
void eeprom_entry(void)
{
	EEPROM_Erase_Page(0x0010);
	EEPROM_Erase_Page(0x0011);
	
	SystemParam_Write.LastInputChannel = 'A';
	SystemParam_Write.motor_position = 'B';
  
	Write_Flash(&SystemParam_Write);
	Read_Flash(&SystemParam_Read);
	
	printf("%c \r\n",SystemParam_Read.LastInputChannel);
	printf("%c \r\n",SystemParam_Read.motor_position);
	
}

/**
  * @name    Read_Flash
  * @brief   read flash of device function
  * @param   *pRAM PRAM_Type
  * @return  None
***/
static void Read_Flash(PRAM_Type *pRAM)
{
	pRAM -> LastInputChannel = EEPROM_Read_Byte(0x0010);
	pRAM -> motor_position = EEPROM_Read_Byte(0x0011);		
}

/**
  * @name    Write_Flash
  * @brief   write flash of device function
  * @param   *pRAM PRAM_Type
  * @return  None
***/
static void Write_Flash(PRAM_Type *pRAM)
{
  EEPROM_Write_Byte(0x0010,pRAM -> LastInputChannel);
  EEPROM_Write_Byte(0x0011,pRAM -> motor_position);
}
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



