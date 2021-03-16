/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_ADC.h
  - Author        : zeweni
  - Update date   : 2020.03.01
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                      Note
  * ------------   ---------------   ----------------------------------
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.03.01         zeweni       Update code style.
  *
***/

#ifndef __STC8x_MDU16_H_
#define __STC8x_MDU16_H_
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
#include "STC8x_CORE.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

/**
  * @name    MUL_16_BIT
  * @brief   16 bit multiplication
  * @param   mul1  multiplier
  * @param   mul2  multiplier 
  * @param   pro  product
  * @return  none
***/
#define MUL_16_BIT(mul1, mul2, pro) 		do{ \
                                                EAXFR_ENABLE();  \
                                                MD1U16 = mul1; MD5U16 = mul2; \
                                                ARCON = 0x04 << 5; OPCON = 1; \
                                                while((OPCON & 0x01) != 0);   \
                                                pro = MD3U32;    \
                                                EAXFR_DISABLE(); \
                                            }   while (0)

/**
  * @name    DIV_16_BIT
  * @brief   16 bit Division
  * @param   mol  molecule
  * @param   den  denominator 
  * @param   quo  quotient
  * @param   rem  remainder
  * @return  none
***/
#define DIV_16_BIT(mol, den, quo, rem) 		do{ \
                                                EAXFR_ENABLE();  \
                                                MD1U16 = mol;   MD5U16 = den; \
                                                ARCON = 0x06 << 5; OPCON = 1; \
                                                while((OPCON & 0x01) != 0);   \
                                                quo = MD1U16;   mod = MD5U16; \
                                                EAXFR_DISABLE(); \
                                            }   while (0)

/**
  * @name    DIV_32_BIT
  * @brief   32 bit Division
  * @param   mol  molecule
  * @param   den  denominator 
  * @param   quo  quotient
  * @param   rem  remainder
  * @return  none
***/
#define DIV_32_BIT(mol, den, quo, rem) 		do{ \
                                                EAXFR_ENABLE();  \
                                                MD3U32 = mol;   MD5U16 = den; \
                                                ARCON = 0x06 << 5; OPCON = 1; \
                                                while((OPCON & 0x01) != 0);   \
                                                quo = MD3U32;   mod = MD5U16; \
                                                EAXFR_DISABLE(); \
                                            }   while (0)

/**
  * @name    SHIFT_LEFT
  * @brief   Move data to the left
  * @param   mdata  Data that needs to be moved
  * @param   digits  Number of digits moved
  * @param   result   Number of result move
  * @return  none
***/
#define MOVE_LEFT_SHIFT(mdata, digits, result) 	do{ \
                                                    EAXFR_ENABLE();  \
                                                    ARCON = (0x02 << 5) + digits; \
                                                    MD3U32  = mdata; OPCON = 1;   \
                                                    while((OPCON & 0x01) != 0);   \
                                                    result = MD3U32;   \
                                                    EAXFR_DISABLE(); \
                                                }   while (0) 

/**
  * @name    SHIFT_RIGHT
  * @brief   Move data to the right
  * @param   mdata  Data that needs to be moved
  * @param   digits  Number of digits moved
  * @param   result   Number of result move
  * @return  none
***/
#define MOVE_RIGHT_SHIFT(mdata, digits, result) 	do{ \
                                                    EAXFR_ENABLE();  \
                                                    ARCON = (0x01 << 5) + digits; \
                                                    MD3U32  = mdata; OPCON = 1;   \
                                                    while((OPCON & 0x01) != 0);   \
                                                    result = MD3U32;   \
                                                    EAXFR_DISABLE(); \
                                                }   while (0) 

#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

