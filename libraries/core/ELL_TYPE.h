/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TYPE.h
  - Author        : zeweni
  - Update date   : 2020.04.28
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
#ifndef __STC8x_TYPE_H_
#define __STC8x_TYPE_H_

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/*
 * If there is a conflict between the redefinition of RTOS and this, 
 * you can call the redefinition header file of RTO to replace it, 
 * or add this header file to RTOS and comment out the conflict.
**/

/*--------------------------------------------------------
| @Description: Exact width signed integer types         |
--------------------------------------------------------*/
						
typedef  signed char  int8_t;	//  8 bits 
typedef  signed int  int16_t;	// 16 bits 
typedef  signed long int32_t;	// 32 bits 
						
typedef  signed char  int8;	//  8 bits 
typedef  signed int  int16;	// 16 bits 
typedef  signed long int32;	// 32 bits

/*--------------------------------------------------------
| @Description: Volatile width signed integer types      |
--------------------------------------------------------*/

typedef  volatile int8_t    vint8_t; //  8 bits 
typedef  volatile int16_t  vint16_t; // 16 bits 
typedef  volatile int32_t  vint32_t; // 32 bits 

typedef  volatile int8_t    vint8; //  8 bits 
typedef  volatile int16_t  vint16; // 16 bits 
typedef  volatile int32_t  vint32; // 32 bits 

/*--------------------------------------------------------
| @Description: Exact width unsigned integer types       |
--------------------------------------------------------*/

typedef  unsigned char   uint8_t; //  8 bits 
typedef  unsigned int   uint16_t; // 16 bits 
typedef  unsigned long  uint32_t; // 32 bits 

typedef  unsigned char   u8; //  8 bits 
typedef  unsigned int   u16; // 16 bits 
typedef  unsigned long  u32; // 32 bits 

typedef  unsigned char   uint8; //  8 bits 
typedef  unsigned int   uint16; // 16 bits 
typedef  unsigned long  uint32; // 32 bits 

/*--------------------------------------------------------
| @Description: Volatile width unsigned integer types    |
--------------------------------------------------------*/

typedef  volatile uint8_t    vuint8_t; //  8 bits 
typedef  volatile uint16_t  vuint16_t; // 16 bits 
typedef  volatile uint32_t  vuint32_t; // 32 bits 

typedef  volatile uint8_t    vu8; //  8 bits 
typedef  volatile uint16_t  vu16; // 16 bits 
typedef  volatile uint32_t  vu32; // 32 bits 

typedef  volatile uint8_t    vuint8; //  8 bits 
typedef  volatile uint16_t  vuint16; // 16 bits 
typedef  volatile uint32_t  vuint32; // 32 bits 

/*--------------------------------------------------------
| @Description: IO definitions                           |
--------------------------------------------------------*/

#define    __I    volatile   // 'read only' permissions 
#define    __O    volatile   // 'write only'  permissions 
#define    __IO   volatile   // 'read / write' permissions 


#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/