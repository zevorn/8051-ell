/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_SYSCLK.c
  - Author        : zeweni
  - Update date   : 2020.05.03
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
#include "STC8x_SYSCLK.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/*None.*/
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

#if (PER_LIB_SYSCLK_CTRL == 1)

	#if (PER_LIB_SYSCLK_INIT_CTRL == 1)
	
		/**
		 * @brief     系统时钟初始化函数。 
		 * @details   System clock init function.
		 * @param[in] sysClkn 系统时钟初始化结构体句柄，需要在初始化时定义它，并用其地址传参。
							  The system clock initializes the structure handle, 
							  which needs to be defined during initialization and its 
							  address is used to pass parameters.
		 * @return      FSC_SUCCESS 返回成功。Return to success.
		 * @return      FSC_FAIL    返回失败。Return to fail.
		**/
		FSCSTATE SYSCLK_Init(const SYSCLK_InitType* sysClkn)
		{
			EAXFR_ENABLE(); /* Enable access to the internal extended RAM area */
			
			#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
			{
				if(sysClkn -> MCLKSrc != AUTO)
				{
					SYSCLK.IRC24MCR_REG &= 0xFE; /* Since power on defaults to internal HIRC,
												  the control bit (the highest bit) cannot be cleared*/
					SYSCLK.IRC32KCR_REG &= 0x7E;
					SYSCLK.XOSCCR_REG &= 0x1E;

					switch(sysClkn -> MCLKSrc) /* Select master clock source */
					{
						case HIRC: SYSCLK.CKSEL_REG = 0x00; SYSCLK.IRC24MCR_REG |= 0x80; break;
						case XOSC: SYSCLK.CKSEL_REG = 0x01; SYSCLK.XOSCCR_REG |= 0xC0;   break;
						case LIRC: SYSCLK.CKSEL_REG = 0x03; SYSCLK.IRC32KCR_REG |= 0x80; break;
					}
				
					/* Wait for the clock source switch to complete */
						while(!( (SYSCLK.IRC24MCR_REG & 0x01)   || 
								 (SYSCLK.IRC32KCR_REG & 0x01)   || 
								 (SYSCLK.XOSCCR_REG   & 0x01)  ));
				
					IRTRIM = sysClkn -> IRCTRIM;
					LIRTRIM = sysClkn -> LIRCTRIM;
					
					if(sysClkn -> MCLKDiv == 0) sysClkn -> MCLKDiv += 1;
					SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv;  /* Master clock frequency division */
				
				}
			
				SYSCLK.CKSEL_REG |= sysClkn -> SCLKDiv;   /* System clock frequency division */
				SYSCLK.CKSEL_REG |= sysClkn -> SCLKOutPin << 3;
			}			
			#elif ( PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx ) 		
			{		
				if(sysClkn -> MCLKSrc != AUTO)
				{
					SYSCLK.HIRCCR_REG &= 0xFE; /* Since power on defaults to internal HIRC,
												  the control bit (the highest bit) cannot be cleared */
					SYSCLK.IRC32KCR_REG &= 0x7E;
					SYSCLK.XOSCCR_REG &= 0x1E;

					switch(sysClkn -> MCLKSrc) /* Select master clock source */
					{
						case HIRC:   SYSCLK.CKSEL_REG = 0x00; SYSCLK.HIRCCR_REG |= 0x80;   break;
						case XOSC:   SYSCLK.CKSEL_REG = 0x01; SYSCLK.XOSCCR_REG |= 0xC0;   break;
						case LIRC:   SYSCLK.CKSEL_REG = 0x03; SYSCLK.IRC32KCR_REG |= 0x80; break;
					}
				
					/* Wait for the clock source switch to complete */
						while(!( (SYSCLK.HIRCCR_REG & 0x01)   || 
								 (SYSCLK.IRC32KCR_REG & 0x01) || 
								 (SYSCLK.XOSCCR_REG   & 0x01)));

					IRCBAND =  sysClkn -> IRCBand; /* Internal IRC adjust frequency band */
					IRTRIM = sysClkn -> IRCTRIM;  /* Internal IRC adjust frequency IRTRIM  */
					LIRTRIM = sysClkn -> LIRCTRIM; /* Internal IRC adjust frequency LIRTRIM */
					
					if(sysClkn -> MCLKDiv == 0) SYSCLK.CLKDIV_REG = 1;  /* Master clock frequency division */
					else SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv;
				}
			
				SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKDiv;   /* System clock frequency division */
				SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKOutPin << 7;
			}
			#elif ( PER_LIB_MCU_MUODEL == STC8Hx ) 		
			{		
				if(sysClkn -> MCLKSrc != AUTO)
				{
					SYSCLK.HIRCCR_REG &= 0xFE; /* Since power on defaults to internal HIRC,
												  the control bit (the highest bit) cannot be cleared*/
					SYSCLK.IRC32KCR_REG &= 0x7E;
					SYSCLK.XOSCCR_REG &= 0x1E;
					SYSCLK.X32KCR_REG &= 0x3E;
					switch(sysClkn -> MCLKSrc) /* Select master clock source */
					{
						case HIRC:   SYSCLK.CKSEL_REG = 0x00; SYSCLK.HIRCCR_REG |= 0x80;   break;
						case XOSC:   SYSCLK.CKSEL_REG = 0x01; SYSCLK.XOSCCR_REG |= 0xC0;   break;
						case X32KSC: SYSCLK.CKSEL_REG = 0x02; SYSCLK.X32KCR_REG |= 0xC0;   break;
						case LIRC:   SYSCLK.CKSEL_REG = 0x03; SYSCLK.IRC32KCR_REG |= 0x80; break;
					}
				
					/* Wait for the clock source switch to complete */
						while(!( (SYSCLK.HIRCCR_REG & 0x01)   || 
								 (SYSCLK.IRC32KCR_REG & 0x01) || 
								 (SYSCLK.XOSCCR_REG   & 0x01) ||
								 (SYSCLK.X32KCR_REG   * 0X01)));
					
					SYSCLK.XOSCCR_REG |=  sysClkn -> XOSCFilter << 4;  /* External crystal filter */

					IRCBAND =  sysClkn -> IRCBand; /* Internal IRC adjust frequency band */
					IRTRIM = sysClkn -> IRCTRIM;  /* Internal IRC adjust frequency IRTRIM  */
					LIRTRIM = sysClkn -> LIRCTRIM; /* Internal IRC adjust frequency LIRTRIM */
					
					if(sysClkn -> MCLKDiv == 0) SYSCLK.CLKDIV_REG = 1;  /* Master clock frequency division */
					else SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv;
				}
			
				SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKDiv;   /* System clock frequency division */
				SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKOutPin << 7;

			}
			#endif
			
			EAXFR_DISABLE(); /* Disable access to the internal extended RAM area */

			return FSC_SUCCESS; /* Function self checking succeeded */
		}
		
	#endif
		
		
	#if (PER_LIB_SYSCLK_WORK_CTRL == 1)
		
		/**
		 * @brief   获取系统时钟频率函数，用于定时器、串口、EEPROM等进行时钟计算。
		 *          这个函数只能获取内部IRC做时钟源时的系统频率，如果你使用的是外部晶振，
		 *          请在Lib_CFG.h中配置PER_LIB_SYSCLK_VALUE宏，填写你的系统时钟频率。
		 * @details Get System clock frequendy function.
		 * @param   None
		 * @return  [uint32_t] 时钟频率。value of system clock frequenction. 
		**/
		uint32_t Get_SysClk_FRE(void)
		{
			#if (PER_LIB_SYSCLK_VALUE == 0)
			{
				uint32_t count;
				#if  (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Fx)
				{
					/* Frequency deviation, calculate the approximate data */
					count = 24000000UL + ((int32_t)((int32_t)IRTRIM - (int32_t)IRC_24M) * 0xD2F0UL);
				}
				#elif (PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
				{
					/* Frequency deviation, calculate the approximate data */
					if(IRCBAND) count = 36000000UL + ((int32_t)((int32_t)IRTRIM - (int32_t)IRC_22_1184M) * 0x128E0UL); 
					else        count = 24000000UL + ((int32_t)((int32_t)IRTRIM - (int32_t)IRC_24M) * 0xBB80UL); 
				}
				#endif
				
				count /= SYSCLK.CLKDIV_REG;  /*Divide by division value */
				return count;
			}
			#else
			{
				return PER_LIB_SYSCLK_VALUE;
			}
			#endif
		}
		
	#endif
		
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

