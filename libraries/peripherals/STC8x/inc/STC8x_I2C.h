/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_I2C.h
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
#ifndef __STC8x_I2C_H_
#define __STC8x_I2C_H_
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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
/*--------------------------------------------------------
| @Description: I2C type control enum                    |
--------------------------------------------------------*/

typedef enum
{
  I2C_Type_Master = 0x01,
  I2C_Type_Slave  = 0x00
} I2CType_Type;


/*--------------------------------------------------------
| @Description: I2C slave interrupt Trigger enum         |
--------------------------------------------------------*/

typedef enum
{
  I2C_STri_RevStart_Done  = 0x40,
  I2C_STri_RevData_Done   = 0x20,
  I2C_STri_SendData_Done  = 0x10,
  I2C_STri_RevStop_Done   = 0x80
} I2CSTri_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: I2C init function                        |
--------------------------------------------------------*/

FSCSTATE I2C_Init(I2CType_Type type, uint8_t wTime, BOOL state);

#define I2C_GET_MASTER_FLAG()           (I2CMSST & 0x40)
#define I2C_GET_REVSTART_FLAG()         (I2CMLST & 0x40)
#define I2C_GET_REVDATA_FLAG()          (I2CMLST & 0x20)
#define I2C_GET_SENDATA_FLAG()          (I2CMLST & 0x10)
#define I2C_GET_REVSTOP_FLAG()          (I2CMLST & 0x08)

#define I2C_CLEAR_MASTER_FLAG()          I2CMSST &= 0xBF
#define I2C_CLEAR_REVSTART_FLAG()        I2CMLST &= 0xBF
#define I2C_CLEAR_REVDATA_FLAG()         I2CMLST &= 0xDF
#define I2C_CLEAR_SENDATA_FLAG()         I2CMLST &= 0xEF
#define I2C_CLEAR_REVSTOP_FLAG()         I2CMLST &= 0xF7

FSCSTATE NVCI_I2C_Master_Init(NVICPri_Type priority,BOOL run);
FSCSTATE NVCI_I2C_Slave_Init(NVICPri_Type priority,I2CSTri_Type triMode);

#define    NVIC_I2C_MASTER_CTRL(run)    do{ EAXFR_ENABLE();	I2CMSCR = run << 7; EAXFR_DISABLE(); }while(0)
#define    NVIC_I2C_SLAVE_CTRL(run)     do{ EAXFR_ENABLE(); I2CSLCR &= (I2CSLCR & 0x01 )| (run << 6) | (run << 5) | (run << 4) | (run << 3); EAXFR_DISABLE(); }while(0)

/*--------------------------------------------------------
| @Description: I2C working control function             |
--------------------------------------------------------*/

FSCSTATE I2C_Start(void);
FSCSTATE I2C_Stop(void);
FSCSTATE I2C_Send_ACK(void);
FSCSTATE I2C_Send_NACK(void);
FSCSTATE I2C_Read_ACK(void);
FSCSTATE I2C_Send_Btye(uint8_t dat);
uint8_t I2C_Read_Byte(void);


/* I2C */
FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port);
	
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

