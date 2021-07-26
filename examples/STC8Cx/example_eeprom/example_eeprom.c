/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : example_eeprom.c
  - Author        : zeweni
  - Update date   : 2020.07.26
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
#include "example_eeprom.h"
#include "ELL_LIB.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#define EXAMPLE_CTRL     (0)

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @brief      外部中断外设示例代码初始化。
 * @details    External interrupt peripheral sample code initialization.
 * @param      None.
 * @return     None.
 * @note       每种例程，只能调用一个初始化函数和运行函数，各例程之间并不兼容。
 *             Each routine can only call an initialization function and a run function, 
 *             and the routines are not compatible with each other.
**/
void Example_EEPROM_Init(void)
{
	EEPROM_Init(ENABLE);
}


/**
 * @brief      运行EEPROM外设示例代码。
 * @details    Run the EEPROM peripheral sample code.
 * @param      None.
 * @return     None.
**/
void Example_EEPROM_Run(void)
{
	if(EEPROM_Read_Byte(0x0010) != 'A')
	{  
		EEPROM_Erase_Page(0x0010);
        EEPROM_Write_Byte(0x0010,'A');
	}
	else
	{
		UART1_Isr_Send_Byte(0xFF);
		UART1_Isr_Send_Byte(EEPROM_Read_Byte(0x0010));
	}
}



/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



