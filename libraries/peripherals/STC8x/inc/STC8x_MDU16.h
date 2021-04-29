/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_MDU16.h
  - Author        : zeweni
  - Update date   : 2020.04.27
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
#ifndef __STC8x_MDU16_H_
#define __STC8x_MDU16_H_

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/
#include "Lib_CFG.h"

#ifndef PER_LIB_MCU_MUODEL   
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

#ifndef PER_LIB_MDU16_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MDU16_CTRL 1
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
#if (PER_LIB_MDU16_CTRL == 1)

	#if (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

		/**
		 * @brief      16位乘法宏函数。
		 * @details    16 bit multiplier macro functions.
		 * @param[in]  mul1 乘数1。multiplier 1.
		 * @param[in]  mul2 乘数2。multiplier 2.
		 * @param[out] pro  乘积。product.
		**/
		#define MUL_16_BIT(mul1, mul2, pro) \
		do{                                 \
			EAXFR_ENABLE();                 \
			MD1U16 = mul1; MD5U16 = mul2;   \
			ARCON = 0x04 << 5; OPCON = 1;   \
			while((OPCON & 0x01) != 0);     \
			pro = MD3U32;                   \
			EAXFR_DISABLE();                \
		}while(0)

		
		/**
		 * @brief      16位除法宏函数。
		 * @details    16 bit division macro functions.
		 * @param[in]  mol 分子。molecule.
		 * @param[in]  den 分母。denominator.
		 * @param[out] quo 商。quotient.
		 * @param[out] rem 余数。remainder.
		**/
		#define DIV_16_BIT(mol, den, quo, rem) 	\
		do{ 							        \
			EAXFR_ENABLE();                     \
			MD1U16 = mol;   MD5U16 = den;       \
			ARCON = 0x06 << 5; OPCON = 1;       \
			while((OPCON & 0x01) != 0);         \
			quo = MD1U16;   mol = MD5U16;       \
			EAXFR_DISABLE();                    \
		}while (0)

		/**
		 * @brief      32位除法宏函数。
		 * @details    32 bit division macro functions.
		 * @param[in]  mol 分子。molecule.
		 * @param[in]  den 分母。denominator.
		 * @param[out] quo 商。quotient.
		 * @param[out] rem 余数。remainder.
		**/
		#define DIV_32_BIT(mol, den, quo, rem) \
		do{                                    \
			EAXFR_ENABLE();                    \
			MD3U32 = mol;   MD5U16 = den;      \
			ARCON = 0x06 << 5; OPCON = 1;      \
			while((OPCON & 0x01) != 0);        \
			quo = MD3U32;   mod = MD5U16;      \
			EAXFR_DISABLE();                   \
		}while (0)

		
		/**
		 * @brief      左移宏函数。
		 * @details    Move data to the left functions.
		 * @param[in]  mdata  需要被左移的数据。Data that needs to be moved.
		 * @param[in]  digits 被左移的位数。Number of digits moved.
		 * @param[out] result 左移完的结果。Data of result.
		**/
		#define MOVE_LEFT_SHIFT(mdata, digits, result) 	\
		do{                                             \
			EAXFR_ENABLE();                             \
			ARCON = (0x02 << 5) + digits;               \
			MD3U32  = mdata; OPCON = 1;                 \
			while((OPCON & 0x01) != 0);                 \
			result = MD3U32;                            \
			EAXFR_DISABLE();                            \
		}while (0) 

		
		/**
		 * @brief      右移宏函数。
		 * @details    Move data to the left functions.
		 * @param[in]  mdata  需要被右移的数据。Data that needs to be moved.
		 * @param[in]  digits 被右移的位数。Number of digits moved.
		 * @param[out] result 右移完的结果。Data of result.
		**/
		#define MOVE_RIGHT_SHIFT(mdata, digits, result)  \
		do{                                              \
			EAXFR_ENABLE();                              \
			ARCON = (0x01 << 5) + digits;                \
			MD3U32  = mdata; OPCON = 1;                  \
			while((OPCON & 0x01) != 0);                  \
			result = MD3U32;                             \
			EAXFR_DISABLE();                             \
		}while (0) 

	#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/
#endif
