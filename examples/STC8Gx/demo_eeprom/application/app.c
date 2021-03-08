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
  SystemParam_Write.LastInputChannel = 'A';
  SystemParam_Write.motor_position = 'B';
  
  EEPROM_Write_Byte(0x0010,SystemParam_Write.LastInputChannel);
  EEPROM_Write_Byte(0x0011,SystemParam_Write.motor_position);
	
  SystemParam_Read.LastInputChannel = EEPROM_Read_Byte(0x0010);
  SystemParam_Read.motor_position = EEPROM_Read_Byte(0x0011);	
	
  printf("%c \r\n",SystemParam_Read.LastInputChannel);
  printf("%c \r\n",SystemParam_Read.motor_position);
	
}
	

	
	
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



