/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_ADC.c
  - Author        : zeweni
  - Update date   : 2020.04.23
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
#include "STC8x_ADC.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

#if (PER_LIB_ADC_CTRL == 1)

	#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)

		/**
		 * @brief	空延时函数，帮助稳定ADC外设切换工作状态。
		 * @details Working wait nop function.
		 * @param   None
		 * @return  None
		***/
		static void nop(void)
		{
			uint8_t i = 255;
			while(i--);
		}
		
		#if (PER_LIB_ADC_INIT_CTRL == 1)
		
			/**
			 * @brief		ADC外设初始化函数。
			 * @details	    This is a ADC peripheral init function. 
			 * @param[in]	adcx  ADC结构体句柄，初始化时请定义该句柄，并用其地址来传参。
			 *                    ADC structure handle. When initializing, 
			 *                    please define the handle and use its address
			 *                    to pass parameters.
             * @return      FSC_SUCCESS 返回成功。Return to success.
             * @return      FSC_FAIL    返回失败。Return to fail.
			**/
			FSCSTATE ADC_Init(const ADC_InitType* adcx)
			{
				if(adcx -> Speed <= 0x0F) 
				{
					EAXFR_ENABLE();
					ADCTIM = 0x3F;
					EAXFR_DISABLE();
					ADC_CONTR = (ADC_CONTR & 0x70)|(adcx -> Power << 7)|(adcx -> Channel);
					nop();
					ADCCFG = (ADCCFG & 0xF0) | (adcx -> Speed);	
					ADCCFG = (ADCCFG & 0xDF) | (adcx -> Align << 5);	
					ADC_CONTR = (ADC_CONTR & 0xBF) | (adcx -> Run << 6);
					return FSC_SUCCESS;
				}
				else return FSC_FAIL;
			}
			
		#endif
		
		#if (PER_LIB_ADC_WORK_CTRL == 1)
			
			/**
			 * @brief	   ADC获取采集结果函数（查询法）。
			 * @details	   This is a ADC get sample function. 
			 * @param[in]  channel  ADC采集通道,不同的芯片型号，通道有所不同，请查看头文件的宏定义。
			 *                      ADC acquisition accuracy, different chip models, 
			 *                      the highest accuracy is different, 
			 *                      please check the macro definition of the header file.
			 * @param[in]  acc      ADC采集精度，不同的芯片型号，最高精度有所不同，请查看头文件的宏定义。
			 *                      ADC acquisition accuracy, different chip models, 
			 *                      the highest accuracy is different, 
			 *                      please check the macro definition of the header file.
			 * @return	   uint16_t 返回采集到的ADC值。Returns the collected ADC value.
			 * @note        默认使用的是右对齐操作，如果读取的数据是左对齐，需要开发者自己处理。
			**/
			uint16_t ADC_Get_Sample(uint8_t channel, ADCAcc_Type acc)
			{	
				uint16_t value;
				ADC_RES = 0;
				ADC_RESL = 0;
				ADC_CONTR = (ADC_CONTR & 0xF0) | ADC_POWER | (channel);
				while (!(ADC_CONTR & 0x20));  //Query ADC completion flag
				ADC_CONTR &= 0xDF;  //Completion mark
				value = (uint16_t)(ADC_RES << 8) | ADC_RESL;  
				value >>= acc; //Selection accuracy
				ADC_CONTR |= 0x40; //Restart
				return value;
			}

			
			/**
			 * @brief	   ADC获取采集结果函数（中断法）。
			 * @details	   This is a ADC get sample function in interrupt. 
			 * @param[in]  acc      ADC采集精度，不同的芯片型号，最高精度有所不同，请查看头文件的宏定义。
			 *                      ADC acquisition accuracy, different chip models, 
			 *                      the highest accuracy is different, 
			 *                      please check the macro definition of the header file.
			 * @return	   uint16_t 返回采集到的ADC值。Returns the collected ADC value.
			 * @note        默认使用的是右对齐操作，如果读取的数据是左对齐，需要开发者自己处理。
			**/
			uint16_t ADC_Get_Sample_Interrupt(ADCAcc_Type acc)
			{	
				uint16_t value;
				ADC_RES = 0;
				ADC_RESL = 0;
				ADC_CONTR &= 0xDF;  //Completion mark
				value = (uint16_t)(ADC_RES << 8) | ADC_RESL;  
				value >>= acc; //Selection accuracy
				ADC_CONTR |= 0x40; //Restart
				return value;
			}
			
		#endif
			

		#if (PER_LIB_ADC_WORK_CTRL == 1)
			
            /**
             * @brief	   ADC中断初始化函数。
             * @details	   ADC interrupt initialization function.
             * @param[in]  pri 中断优先级。Interrupt priority.
             * @param[in]  run 中断运行控制位。Interrupt operation control bit.
             * @return     FSC_SUCCESS 返回成功。Return to success.
             * @return     FSC_FAIL    返回失败。Return to fail.
            **/
            FSCSTATE NVIC_ADC_Init(NVICPri_Type pri,BOOL run)
            {
                EADC = run;
                NVIC_ADC_PRI(pri);
                return FSC_SUCCESS;
            }

        #endif

	#endif
		
#endif	
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

