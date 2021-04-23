/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_EEPROM.h
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
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
#ifndef __STC8x_EEPROM_H_
#define __STC8x_EEPROM_H_

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
#include "ELL_CORE.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/**
  * @name    EEPROM_GET_STATE
  * @brief   EEPROM获取工作状态宏函数。
  *          EEPROM gets working state macro functions.
***/
#define EEPROM_GET_STATE()  (IAP_CONTR & 0x01)

/**
  * @name    EEPROM_Init
  * @brief   EEPROM初始化函数。
  *          EEPROM initialization function.
  * @param   run  [IN] 运行控制位。Operation control bit.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Init(BOOL run);

/**
  * @name    EEPROM_CTRL
  * @brief   EEPROM运行控制宏函数。
  *          EEPROM runs control macro functions.
  * @param   run  [IN] 运行控制位。Operation control bit.
***/
#define EEPROM_CTRL(run)  {IAP_CONTR = (IAP_CONTR & 0x7F) | (run << 7);}


/**
  * @name    EEPROM_Erase_Page
  * @brief   EEPROM 擦除扇区函数。
  *          EEPROM erase page function.
  * @param   addr [IN] 扇区首地址（64字节为一个扇区，地址要能被64整除）。
  *                    The first address of a sector (64 bytes is a sector, 
  *                    and the address should be divisible by 64).
  * @return  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Erase_Page(uint16_t addr);


/**
  * @name    EEPROM_Write_Byte
  * @brief   EEPROM写一个字节函数。
  *          EEPROM writes a byte function.  
  * @param   addr [IN] flash地址。Falsh address.
  * @param   byte [IN] 一个字节的数据。Data of byte.  
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Write_Byte(uint16_t addr,uint8_t byte);


/**
  * @name    EEPROM_Write_Str
  * @brief   EEPROM写一个字符串。
  *          EEPROM write string function .  
  * @param   addr  [IN] Falsh地址。falsh address.
  * @param   *arry [IN] 字符串的首地址。The first address of the string.
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Write_Str(uint16_t addr,const uint8_t *str);

/**
  * @name    EEPROM_Write_Arry
  * @brief   EEPROM写一个数组函数。
  *          EEPROM write a Arry function.  
  * @param   addr  [IN] Falsh地址。falsh address.
  * @param   *arry [IN] 数组的首地址。The first address of the array.
  * @param   len   [IN] 数组长度。arry length. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Write_Arry(uint16_t addr,const uint8_t *str,uint8_t len);

/**
  * @name    EEPROM_Read_Byte
  * @brief   EEPROM读取一个字节函数。
  *          EEPROM reads a byte function.  
  * @param   addr [IN] flash地址。Falsh address.
  * @return  [uint8_t] 一个字节的数据。Data of byte.  
***/
uint8_t EEPROM_Read_Byte(uint16_t addr);


/**
  * @name    EEPROM_Read_Arry
  * @brief   EEPROM读取一个数组函数。
  *          EEPROM read Arry function.  
  * @param   addr  [IN] Falsh地址。falsh address.
  * @param   *arry [OUT] 数组的首地址。The first address of the array.
  * @param   len   [IN] 数组长度。arry length. 
  * @retval  [FSC_SUCCESS / FSC_FAIL]
***/
FSCSTATE EEPROM_Read_Arry(uint16_t addr,uint8_t *str,uint8_t len);




#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

