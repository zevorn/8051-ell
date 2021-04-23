/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : drv_KeyScan.h
  - Author        : zeweni
  - Update date   : 2020.01.11                  
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
#ifndef __drv_KeyScan_H_
#define __drv_KeyScan_H_
/*-----------------------------------------------------------------------
|                                INCLUDES                               |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"

#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#ifndef DRV_LIB_KEYSCAN_CTRL        
    #define DRV_LIB_KEYSCAN_CTRL   (1)
#endif

#ifndef DRV_LIB_KEYSCAN_NUM_MAX             
    #define DRV_LIB_KEYSCAN_NUM_MAX   (8)
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


#include "ELL_CORE.h"
#include "STC8x_GPIO.h"

/*-----------------------------------------------------------------------
|                                 CONFIG                                |
-----------------------------------------------------------------------*/
#if (DRV_LIB_KEYSCAN_CTRL == 1)

#define KEY_NUM_MAX  DRV_LIB_KEYSCAN_NUM_MAX

/*-----------------------------------------------------------------------
|                                  DATA                                 |
-----------------------------------------------------------------------*/

typedef void (* KeyHandle_Func)  (void);

/*--------------------------------------------------------
| @Description: Key state enum                           |
--------------------------------------------------------*/

typedef enum 
{
  Tri_High_level = 0x00,
  Tri_Low_level  = 0x01
} Sem_Tri;

/*--------------------------------------------------------
| @Description: Key state enum                           |
--------------------------------------------------------*/

typedef enum 
{
  Effect_Press   = 0x00,
  Effect_Release = 0x01
} Sem_Effect;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/**
  * @name    KeyScan_Type
  * @brief   KeyScan type struct.
  * @param   GPIO
  * @param   Pin
  * @param   EffMode     key scan effect mode
  * @param   TriMode     key scan trigger mode
  * @param   HandleFunc  key scan handle sth function
***/
typedef struct
{
	uint8_t        GPIO;
	uint8_t        Pin;
	Sem_Effect      EffMode;
	Sem_Tri         TriMode;
	KeyHandle_Func  HandleFunc;
}KeyScan_Type;

/**
  * @name    KeyScan_Init
  * @brief   KeyScan init function.
  * @param   *keyScan KeyScan_Type
  * @return  FSCSTATE SUCCESS(1) / FAIL(0)
***/
FSCSTATE KeyScan_Init(KeyScan_Type *keyScan);


/**
  * @name    KeyScan_Object_Type
  * @brief   KeyScan object type struct.
***/
typedef struct
{
	void (*         Run)  (void);
	void (*  ReadPin_P0)  (void);
	void (*  ReadPin_P1)  (void);
	void (*  ReadPin_P2)  (void);
	void (*  ReadPin_P3)  (void);
	void (*  ReadPin_P4)  (void);
	void (*  ReadPin_P5)  (void);
	#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Hx)
		void (*  ReadPin_P6)  (void);
		void (*  ReadPin_P7)  (void);
	#endif
}KeyScan_Object_Type;


/**
  * @name    KeyScan
  * @brief   KeyScan control function.
  * @param   KeyScan.Run()
  * @param   KeyScan.ReadPin_P0()
  * @param   KeyScan.ReadPin_P1()
  * @param   KeyScan.ReadPin_P2()
  * @param   KeyScan.ReadPin_P3()
  * @param   KeyScan.ReadPin_P4()
  * @param   KeyScan.ReadPin_P5()
  * @param   KeyScan.ReadPin_P6()
  * @param   KeyScan.ReadPin_P7()
***/
extern KeyScan_Object_Type KeyScan;

#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

