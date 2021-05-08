/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_EEPROM.h
  - Author        : zeweni
  - Update date   : 2020.04.23
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
 * Apache-2.0 License for more details.

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


#ifndef PER_LIB_MCU_MUODEL
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif


#ifndef PER_LIB_EEPROM_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_EEPROM_CTRL 1
#endif


#ifndef PER_LIB_EEPROM_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_EEPROM_INIT_CTRL 1
#endif


#ifndef PER_LIB_EEPROM_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_EEPROM_WORK_CTRL 1
#endif

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_EEPROM_CTRL == 1)

    #if (PER_LIB_EEPROM_INIT_CTRL == 1)

        /**
         * @brief     EEPROM初始化函数。
         * @details   EEPROM initialization function.
         * @param[in] run  运行控制位。Operation control bit.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE EEPROM_Init(BOOL run);

    #endif


    #if (PER_LIB_EEPROM_WORK_CTRL == 1)

        /**
         * @brief   EEPROM获取工作状态宏函数。
         * @details EEPROM gets working state macro functions.
        **/
        #define EEPROM_GET_STATE()  (IAP_CONTR & 0x01)


        /**
         * @brief     EEPROM运行控制宏函数。
         * @details   EEPROM runs control macro functions.
         * @param[in] run 运行控制位。Operation control bit.
        **/
        #define EEPROM_CTRL(run)  {IAP_CONTR = (IAP_CONTR & 0x7F) | (run << 7);}


        /**
         * @brief     EEPROM 擦除扇区函数。
         * @details   EEPROM erase page function.
         * @param[in] addr  扇区首地址（512字节为一个扇区，地址要能被512整除）。
         *                    The first address of a sector (512 bytes is a sector, 
         *                    and the address should be divisible by 512).
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE EEPROM_Erase_Page(uint16_t addr);


        /**
         * @brief     EEPROM写一个字节函数。
         * @details   EEPROM writes a byte function.  
         * @param[in] addr flash地址。Falsh address.
         * @param[in] byte  一个字节的数据。Data of byte.  
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE EEPROM_Write_Byte(uint16_t addr,uint8_t byte);


        /**
         * @brief     EEPROM写一个字符串。
         * @details   EEPROM write string function .  
         * @param[in] addr   Falsh地址。falsh address.
         * @param[in] str  字符串的首地址。The first address of the string.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE EEPROM_Write_Str(uint16_t addr,const uint8_t *str);


        /**
         * @brief      EEPROM写一个数组函数。
         * @details    EEPROM write a Arry function.  
         * @param[in]  addr  Falsh地址。falsh address.
         * @param[in]  arry  数组的首地址。The first address of the array.
         * @param[in]  len   数组长度。arry length. 
         * @return     FSC_SUCCESS 返回成功。Return to success.
         * @return     FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE EEPROM_Write_Arry(uint16_t addr,const uint8_t *arry,uint8_t len);


        /**
         * @brief     EEPROM读取一个字节函数。
         * @details   EEPROM reads a byte function.  
         * @param[in] addr flash地址。Falsh address.
         * @return    [uint8_t] 一个字节的数据。Data of byte.  
        **/
        uint8_t EEPROM_Read_Byte(uint16_t addr);


        /**
         * @brief       EEPROM读取一个数组函数。
         * @details     EEPROM read Arry function.  
         * @param[in]   addr   Falsh地址。falsh address.
         * @param[out]  arry   数组的首地址。The first address of the array.
         * @param[in]   len    数组长度。arry length. 
         * @return     FSC_SUCCESS 返回成功。Return to success.
         * @return     FSC_FAIL    返回失败。Return to fail.
        ***/
        FSCSTATE EEPROM_Read_Arry(uint16_t addr,uint8_t *arry,uint8_t len);

    #endif



#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/
#endif
