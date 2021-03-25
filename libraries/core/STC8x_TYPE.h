/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TYPE.h
  - Author        : zeweni
  - Update date   : 2020.03.02
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

 * You should have received a copy of the Apache-2.0 License.Ant Real Time
 * Operating System. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8x_TYPE_H_
#define __STC8x_TYPE_H_

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Exact width signed integer types         |
--------------------------------------------------------*/
						
typedef signed char     int8;	    //  8 bits 
typedef signed int      int16;	// 16 bits 
typedef signed long     int32;	// 32 bits 

typedef  int8    int8_t;	//  8 bits 
typedef  int16  int16_t;	// 16 bits 
typedef  int32  int32_t;	// 32 bits 

/*--------------------------------------------------------
| @Description: Volatile width signed integer types      |
--------------------------------------------------------*/

typedef volatile int8   vint8;	//  8 bits 
typedef volatile int16  vint16;	// 16 bits 
typedef volatile int32  vint32;	// 32 bits 

typedef  vint8    vint8_t; //  8 bits 
typedef  vint16  vint16_t; // 16 bits 
typedef  vint32  vint32_t; // 32 bits 

/*--------------------------------------------------------
| @Description: Exact width unsigned integer types       |
--------------------------------------------------------*/

typedef unsigned char   uint8;	//  8 bits 
typedef unsigned int    uint16;	// 16 bits 
typedef unsigned long   uint32;	// 32 bits 

typedef  uint8    uint8_t; //  8 bits 
typedef  uint16  uint16_t; // 16 bits 
typedef  uint32  uint32_t; // 32 bits 

/*--------------------------------------------------------
| @Description: Volatile width unsigned integer types    |
--------------------------------------------------------*/

typedef volatile uint8  vuint8;	//  8 bits 
typedef volatile uint16 vuint16;	// 16 bits 
typedef volatile uint32 vuint32;	// 32 bits 

typedef  vuint8    vuint8_t; //  8 bits 
typedef  vuint16  vuint16_t; // 16 bits 
typedef  vuint32  vuint32_t; // 32 bits 

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