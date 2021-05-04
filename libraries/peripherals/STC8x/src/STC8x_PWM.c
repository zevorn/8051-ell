/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_PWM.c
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
#include "STC8x_PWM.h"
/*-----------------------------------------------------------------------
|                             DECLARATION                               |
-----------------------------------------------------------------------*/
/*--------------------------------------------------------
| @Description: PWM priority define function             |
--------------------------------------------------------*/


/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

	#if (PER_LIB_MCU_MUODEL == STC8Ax)

		/**
		 * @brief   PWM counter init function,it must be initialized last
		 * @param   clkSrc   PWM_SCLK_DIV_1  | PWM_SCLK_DIV_2  | PWM_SCLK_DIV_3  | PWM_SCLK_DIV_4
		 *                   PWM_SCLK_DIV_5  | PWM_SCLK_DIV_6  | PWM_SCLK_DIV_7  | PWM_SCLK_DIV_8
		 *                   PWM_SCLK_DIV_9  | PWM_SCLK_DIV_10 | PWM_SCLK_DIV_11 | PWM_SCLK_DIV_12
		 *                   PWM_SCLK_DIV_13 | PWM_SCLK_DIV_14 | PWM_SCLK_DIV_15 | PWM_SCLK_DIV_16
		 * @param   period    Counter load value (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM_CNT_Init(PWMCLKSrc_Type clkSrc,uint16_t period,BOOL run)
		{
		  if(period <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMCKS = clkSrc;
			PWMC = period;
			PWMCR = (PWMCR & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM0_Init
		 * @brief   PWM0 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point (uint16_t)
		 * @param   sValue   The value of the second reversal point (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM0_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM0T1_ADDRESS) = fValue;
			PWMxT2(PWM0T2_ADDRESS) = sValue;
			PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM1_Init
		 * @brief   PWM1 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point (uint16_t)
		 * @param   sValue   The value of the second reversal point (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM1_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM1T1_ADDRESS) = fValue;
			PWMxT2(PWM1T2_ADDRESS) = sValue;
			PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM2_Init
		 * @brief   PWM2 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point (uint16_t)
		 * @param   sValue   The value of the second reversal point (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM2_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM2T1_ADDRESS) = fValue;
			PWMxT2(PWM2T2_ADDRESS) = sValue;
			PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM3_Init
		 * @brief   PWM3 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point (uint16_t)
		 * @param   sValue   The value of the second reversal point (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM3_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM3T1_ADDRESS) = fValue;
			PWMxT2(PWM3T2_ADDRESS) = sValue;
			PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM4_Init
		 * @brief   PWM4 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point (uint16_t)
		 * @param   sValue   The value of the second reversal point (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM4_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM4T1_ADDRESS) = fValue;
			PWMxT2(PWM4T2_ADDRESS) = sValue;
			PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM5_Init
		 * @brief   PWM5 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point , change to low level (uint16_t)
		 * @param   sValue   The value of the second reversal point, change to high level (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM5_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM5T1_ADDRESS) = fValue;
			PWMxT2(PWM5T2_ADDRESS) = sValue;
			PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM6_Init
		 * @brief   PWM6 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point , change to low level (uint16_t)
		 * @param   sValue   The value of the second reversal point, change to high level (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM6_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM6T1_ADDRESS) = fValue;
			PWMxT2(PWM6T2_ADDRESS) = sValue;
			PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM7_Init
		 * @brief   PWM7 road init function,it is best to initialize before the counter
		 * @param   level    PWM_Start_Low_Level  | PWM_Start_High_Level 
		 * @param   fValue   The value of the first reversal point , change to low level (uint16_t)
		 * @param   sValue   The value of the second reversal point, change to high level (uint16_t)
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM7_Init(PWMStartLevel_Type level,uint16_t fValue,uint16_t sValue,BOOL run)
		{
		  if(fValue <= 0x7FFF && sValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			PWMxT1(PWM7T1_ADDRESS) = fValue;
			PWMxT2(PWM7T2_ADDRESS) = sValue;
			PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xBF) | (level << 6);
			PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0x7F) | (run << 7);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;
		}

		/**
		 * @name    PWM_ABD_Init
		 * @brief   PWM abnormal detection init function
		 * @param   mode     PWM_ADS_P35  | PWM_ADS_COMP 
		 * @param   signal   PWM_COMP_Low_To_High | PWM_COMP_High_To_Low
		 *                   PWM_P35_Low_To_High  | PWM_P35_High_To_Low
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM_ABD_Init(PWMADSMode_Type mode,PWMABSignal_Type signal,BOOL run)
		{
		  EAXFR_ENABLE();
		  PWMFDCR = (PWMFDCR & 0xF9) | (mode);
		  PWMFDCR = (PWMFDCR & 0x3F) | (signal);
		  PWMFDCR = (PWMFDCR & 0xF7) | (run);
		  EAXFR_DISABLE();
		  return FSC_SUCCESS;
		}

		/**
		 * @name    PWM_ETADC_Init
		 * @brief   PWM trigger associated ADC init function
		 * @param   tValue   The value of trigger associated ADC
		 * @param   run      ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE PWM_ETADC_Init(uint16_t tValue,BOOL run)
		{
		  if(tValue <= 0x7FFF)
		  {
			EAXFR_ENABLE();
			TADCP = tValue;
			PWMCFG = (PWMCFG & 0xBF) | (run << 6);
			EAXFR_DISABLE();  
			return FSC_SUCCESS;
		  }
		  else return FSC_FAIL;  
		}

		/**
		 * @name    NVIC_PWM_CNT_Init
		 * @brief   PWM CNT return to zero NVIC function 
		 * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
		 * @param   run        ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM_CNT_Init(NVICPri_Type pri,BOOL run)
		{
			NVIC_PWM_CNT_PRI(pri);
			PWMCR = (PWMCR & 0xBF) | (run << 6);
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM_ABD_Init
		 * @brief   PWM abnormal detection NVIC function 
		 * @param   priority   NVIC_PR0 | NVIC_PR1 | NVIC_PR2 | NVIC_PR3
		 * @param   run        ENABLE | DISABLE
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM_ABD_Init(NVICPri_Type pri,BOOL run)
		{
			EAXFR_ENABLE();
			NVIC_PWM_ABD_PRI(pri);
			PWMFDCR = (PWMFDCR & 0xF7) | (run << 3);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM0_Init
		 * @brief   PWM0 road flip NVIC function 
		 * @param   flipMode    PWM_Flip_None   | PWM_Flip_First
		 *                      PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM0_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM1_Init
		 * @brief   PWM1 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM1_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM2_Init
		 * @brief   PWM2 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM2_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM3_Init
		 * @brief   PWM3 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM3_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM4_Init
		 * @brief   PWM4 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM4_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM5_Init
		 * @brief   PWM5 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM5_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM6_Init
		 * @brief   PWM6 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM6_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    NVIC_PWM7_Init
		 * @brief   PWM7 road flip NVIC function 
		 * @param   flipMode     PWM_Flip_None   | PWM_Flip_First
		 *                       PWM_Flip_Second | PWM_Flip_Both
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE NVIC_PWM7_Init(PWMFlip_Type flipMode)
		{
			EAXFR_ENABLE();
			PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xF8) | (flipMode);
			EAXFR_DISABLE();
			return FSC_SUCCESS;
		}

		/**
		 * @name    GPIO_PWM0_SWPort
		 * @brief   PWM0 switch port control function 
		 * @param   port    SW_Port1: P2.0
		 *                  SW_Port2: P1.0
		 *                  SW_Port3: P6.0
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM0_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM0CR_ADDRESS) = (PWMxCR(PWM0CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}

		/**
		 * @name    GPIO_PWM1_SWPort
		 * @brief   PWM1 switch port control function 
		 * @param   port    SW_Port1: P2.1
		 *                  SW_Port2: P1.1
		 *                  SW_Port3: P6.1
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM1_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM1CR_ADDRESS) = (PWMxCR(PWM1CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}

		/**
		 * @name    GPIO_PWM2_SWPort
		 * @brief   PWM2 switch port control function 
		 * @param   port    SW_Port1: P2.2
		 *                  SW_Port2: P1.2
		 *                  SW_Port3: P6.2
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM2_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM2CR_ADDRESS) = (PWMxCR(PWM2CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}

		/**
		 * @name    GPIO_PWM3_SWPort
		 * @brief   PWM3 switch port control function 
		 * @param   port    SW_Port1: P2.3
		 *                  SW_Port2: P1.3
		 *                  SW_Port3: P6.3
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM3_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM3CR_ADDRESS) = (PWMxCR(PWM3CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}

		/**
		 * @name    GPIO_PWM4_SWPort
		 * @brief   PWM4 switch port control function 
		 * @param   port    SW_Port1: P2.4
		 *                  SW_Port2: P1.4
		 *                  SW_Port3: P6.4
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM4_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM4CR_ADDRESS) = (PWMxCR(PWM4CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}

		/**
		 * @name    GPIO_PWM5_SWPort
		 * @brief   PWM5 switch port control function 
		 * @param   port    SW_Port1: P2.5
		 *                  SW_Port2: P1.5
		 *                  SW_Port3: P6.5
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM5_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM5CR_ADDRESS) = (PWMxCR(PWM5CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}


		/**
		 * @name    GPIO_PWM6_SWPort
		 * @brief   PWM6 switch port control function 
		 * @param   port    SW_Port1: P2.6
		 *                  SW_Port2: P1.6
		 *                  SW_Port3: P6.6
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM6_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM6CR_ADDRESS) = (PWMxCR(PWM6CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}

		/**
		 * @name    GPIO_PWM7_SWPort
		 * @brief   PWM7 switch port control function 
		 * @param   port    SW_Port1: P2.7
		 *                  SW_Port2: P1.7
		 *                  SW_Port3: P6.7
		 * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
		**/
		FSCSTATE GPIO_PWM7_SWPort(GPIOSWPort_Type port)
		{
			if(port <= SW_Port3)
			{
				EAXFR_ENABLE();
				PWMxCR(PWM7CR_ADDRESS) = (PWMxCR(PWM7CR_ADDRESS) & 0xC7) | (port << 3);
				EAXFR_DISABLE();
				return FSC_SUCCESS;
			}
			else return FSC_FAIL;
		}


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



