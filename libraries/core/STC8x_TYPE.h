/*-----------------------------------------------------------------------
  - File name      : STC8x_TYPE.h
  - Author         : Quark Team
  - Update date    : 2020-12-20                   
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Header file of MCU type.
-----------------------------------------------------------------------*/
#ifndef __STC8x_TYPE_H_
#define __STC8x_TYPE_H_
/*
 * Update note:
 * ------------   ---------------   ------------------------------------
 *     Date            Author                         Note
 * ------------   ---------------   ------------------------------------
 *  2020.12.20         zeweni       Wrote STC8 type redefinition.
 * 
 */

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Exact width signed integer types         |
--------------------------------------------------------*/

#ifndef INT8_T
    #define INT8_T
    typedef    signed char     int8_t;	    //  8 bits 
#endif

#ifndef INT16_T
    #define INT16_T
    typedef    signed int      int16_t;	// 16 bits 
#endif

#ifndef INT32_T
    typedef    signed long     int32_t;	// 32 bits 
#endif

/*--------------------------------------------------------
| @Description: Volatile width signed integer types      |
--------------------------------------------------------*/

#ifndef VINT8_T
    #define VINT8_T
    typedef    volatile int8_t     vint8_t;	//  8 bits 
#endif

#ifndef VINT16_T
    #define VINT16_T
    typedef    volatile int16_t    vint16_t;	// 16 bits 
#endif

#ifndef VINT32_T
    #define VINT32_T
    typedef    volatile int32_t    vint32_t;	// 32 bits 
#endif

/*--------------------------------------------------------
| @Description: Exact width unsigned integer types       |
--------------------------------------------------------*/

#ifndef UINT8_T
    #define UINT8_T
    typedef     unsigned char    uint8_t;	//  8 bits 
#endif

#ifndef UINT16_T
    #define UINT16_T
    typedef     unsigned int     uint16_t;	// 16 bits 
#endif

#ifndef UINT32_T
    #define UINT32_T
    typedef     unsigned long    uint32_t;	// 32 bits 
#endif

/*--------------------------------------------------------
| @Description: Volatile width unsigned integer types    |
--------------------------------------------------------*/

#ifndef VUINT8_T
    #define VUINT8_T
    typedef volatile uint8_t    vuint8_t;	//  8 bits 
#endif

#ifndef VUINT16_T
    #define VUINT16_T
    typedef volatile uint16_t   vuint16_t;	// 16 bits 
#endif

#ifndef VUINT32_T
    #define VUINT32_T
    typedef volatile uint32_t   vuint32_t;	// 32 bits 
#endif

/*--------------------------------------------------------
| @Description: IO definitions                           |
--------------------------------------------------------*/

#ifndef __I
    #define     __I    volatile   // 'read only' permissions 
#endif

#ifndef __O
    #define     __O    volatile   // 'write only'  permissions 
#endif

#ifndef __IO
    #define    __IO    volatile   // 'read / write' permissions 
#endif

#endif
/*-----------------------------------------------------------------------
|          END OF FLIE        (C) COPYRIGHT Gevico Electronics          | 
-----------------------------------------------------------------------*/
