/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_EEPROM.c
  - Author        : zeweni
  - Update date   : 2020.02.06
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
#include "STC8x_EEPROM.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None. */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
 * @name    nop
 * @brief   空延时函数，帮助稳定EEPROM外设切换工作状态。
 *          Working wait nop function.
 * @param   None
 * @retval  None
***/
static void nop(void)
{
	uint8_t i = 255;
	while(i--);
}

/**
  * @name    EEPROM_WT_Time
  * @brief   EEPROM工作等待时间设置函数，仅限本文件内调用。
  *          EEPROM working wait time function.
  *          only this file call.
  * @param   None
  * @return  None 
***/
static void EEPROM_WT_Time(void)
{	
    extern uint32_t Get_SysClk_FRE(void);
    uint32_t sysClk_FRE;
	  /* Get system clock frequency */
  	sysClk_FRE = Get_SysClk_FRE();
    #if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
        IAP_CONTR &= 0xF8;
        if (sysClk_FRE >= 30000000UL) IAP_CONTR |= 0x00;	
        else if ((sysClk_FRE >= 24000000UL) && (sysClk_FRE < 30000000UL)) IAP_CONTR |= 0x01;
        else if ((sysClk_FRE >= 20000000UL) && (sysClk_FRE < 24000000UL)) IAP_CONTR |= 0x02;
        else if ((sysClk_FRE >= 12000000UL) && (sysClk_FRE < 20000000UL)) IAP_CONTR |= 0x03;
        else if ((sysClk_FRE >=  6000000UL) && (sysClk_FRE < 12000000UL)) IAP_CONTR |= 0x04;
        else if ((sysClk_FRE >=  3000000UL) && (sysClk_FRE <  6000000UL)) IAP_CONTR |= 0x05;
        else if ((sysClk_FRE >=  2000000UL) && (sysClk_FRE <  3000000UL)) IAP_CONTR |= 0x06;
        else if ((sysClk_FRE >=  1000000UL) && (sysClk_FRE <  2000000UL)) IAP_CONTR |= 0x07;
    #elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
        IAP_TPS = (0xC0 & IAP_TPS) | (sysClk_FRE/1000000UL);
    #endif
}

/**
  * @name    EEPROM_Init
  * @brief   EEPROM初始化函数。
  *          EEPROM initialization function.
  * @param   run  [IN] 运行控制位。Operation control bit.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Init(BOOL run)
{
	IAP_CONTR = (IAP_CONTR & 0x7F) | (run << 7);
    EEPROM_WT_Time();
	return FSC_SUCCESS;
}


/**
  * @name    EEPROM_Erase_Page
  * @brief   EEPROM 擦除扇区函数。
  *          EEPROM erase page function.
  * @param   addr [IN] 扇区首地址（512字节为一个扇区，地址要能被512整除）。
  *                    The first address of a sector (512 bytes is a sector, 
  *                    and the address should be divisible by 512).
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Erase_Page(uint16_t addr)
{
    IAP_CONTR |= 0x80;
	IAP_CMD = 3;            //Set IAP write command
	IAP_ADDRH = addr >> 8; 	//Set IAP high address
	IAP_ADDRL = addr; 		//Set IAP low address
	IAP_TRIG = 0x5A; 		//Write trigger command (0x5a)
	IAP_TRIG = 0xA5; 		//Write trigger command (0x5a)	
	nop();
    IAP_CONTR &= 0x7F;
	return FSC_SUCCESS;
}

/**
  * @name    EEPROM_Read_Byte
  * @brief   EEPROM读取一个字节函数。
  *          EEPROM reads a byte function.  
  * @param   addr [IN] flash地址。Falsh address.
  * @retval  [uint8_t] 一个字节的数据。Data of byte.  
***/
uint8_t EEPROM_Read_Byte(uint16_t addr)
{
	uint8_t dat;
    IAP_CONTR |= 0x80;
	IAP_CMD = 1;  //Set IAP read command
	IAP_ADDRH = addr >> 8; 	//Set IAP high address
	IAP_ADDRL = addr; 		//Set IAP low address
	IAP_TRIG  = 0x5A; 		//Write trigger command (0x5a)
	IAP_TRIG  = 0xA5; 		//Write trigger command (0xa5)
	dat = IAP_DATA;
	nop();
    IAP_CONTR &= 0x7F;
	return dat;
}


/**
  * @name    EEPROM_Read_Arry
  * @brief   EEPROM读取一个数组函数。
  *          EEPROM read a Arry function.  
  * @param   addr  [IN] Falsh地址。falsh address.
  * @param   *arry [OUT] 数组的首地址。The first address of the array.
  * @param   len   [IN] 数组长度。arry length. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Read_Arry(uint16_t addr,uint8_t *arry,uint8_t len)
{
	while(len--)
	{
		*arry++ = EEPROM_Read_Byte(addr++);
	}
	return FSC_SUCCESS;
}

/**
  * @name    EEPROM_Write_Byte
  * @brief   EEPROM写一个字节函数。
  *          EEPROM writes a byte function.  
  * @param   addr [IN] flash地址。Falsh address.
  * @param   byte [IN] 一个字节的数据。Data of byte.  
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Write_Byte(uint16_t addr,uint8_t byte)
{
    IAP_CONTR |= 0x80;
	IAP_CMD = 2;  //Set IAP write command
	IAP_ADDRH = addr >> 8; 	//Set IAP high address
	IAP_ADDRL = addr; 		//Set IAP low address
	IAP_DATA =  byte; 		//Read IAP data	
    IAP_TRIG  = 0x5A; 		//Write trigger command (0x5a)
	IAP_TRIG  = 0xA5; 		//Write trigger command (0xa5)
	nop();
    IAP_CONTR &= 0x7F;
	return FSC_SUCCESS;
}


/**
  * @name    EEPROM_Write_Str
  * @brief   EEPROM写一个字符串。
  *          EEPROM write string function .  
  * @param   addr  [IN] Falsh地址。falsh address.
  * @param   *arry [IN] 字符串的首地址。The first address of the string.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Write_Str(uint16_t addr,const uint8_t* str)
{
	while(*str != '\0')
	{
		EEPROM_Write_Byte(addr++,*str++);
	}
	return FSC_SUCCESS;
}

/**
  * @name    EEPROM_Write_Arry
  * @brief   EEPROM写一个数组函数。
  *          EEPROM write a Arry function.  
  * @param   addr  [IN] Falsh地址。falsh address.
  * @param   *arry [IN] 数组的首地址。The first address of the array.
  * @param   len   [IN] 数组长度。arry length. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Write_Arry(uint16_t addr,const uint8_t* arry,uint8_t len)
{
	while(len--)
	{
		EEPROM_Write_Byte(addr++,*arry++);
	}
	return FSC_SUCCESS;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/