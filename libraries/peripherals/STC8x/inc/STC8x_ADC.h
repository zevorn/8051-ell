/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_ADC.h
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
#ifndef __STC8x_ADC_H_
#define __STC8x_ADC_H_

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/

#include "Lib_CFG.h"

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
| @Description: ELL library core                         |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/


#ifndef PER_LIB_MCU_MUODEL   
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif


#ifndef PER_LIB_ADC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_ADC_CTRL 1
#endif


#ifndef PER_LIB_ADC_INIT_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_ADC_INIT_CTRL 1
#endif


#ifndef PER_LIB_ADC_NVIC_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_ADC_NVIC_CTRL 1
#endif


#ifndef PER_LIB_ADC_WORK_CTRL
    /** 如果没有定义这个宏，默认为1。
        If the mirco is undefined，select to "1" */
    #define PER_LIB_ADC_WORK_CTRL 1
#endif


/** ADC通道15，测量内部参考电压。ADC channel 15 is internal refv voltage. */
#define    ADC_Channel_REV    0x0F	   

/* STC8Ax */
#define    ADC_Channel_P10_8Ax    0x00  /*!< STC8A: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8Ax    0x01  /*!< STC8A: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P12_8Ax    0x02  /*!< STC8A: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P13_8Ax    0x03  /*!< STC8A: ADC通道3。ADC channel 3. */
#define    ADC_Channel_P14_8Ax    0x04  /*!< STC8A: ADC通道4。ADC channel 4. */
#define    ADC_Channel_P15_8Ax    0x05  /*!< STC8A: ADC通道5。ADC channel 5. */
#define    ADC_Channel_P16_8Ax    0x06  /*!< STC8A: ADC通道6。ADC channel 6. */
#define    ADC_Channel_P17_8Ax    0x07  /*!< STC8A: ADC通道7。ADC channel 7. */
#define    ADC_Channel_P00_8Ax    0x08  /*!< STC8A: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P01_8Ax    0x09  /*!< STC8A: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P02_8Ax    0x0A  /*!< STC8A: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P03_8Ax    0x0B  /*!< STC8A: ADC通道11。ADC channel 11. */
#define    ADC_Channel_P04_8Ax    0x0C  /*!< STC8A: ADC通道12。ADC channel 12. */
#define    ADC_Channel_P05_8Ax    0x0D  /*!< STC8A: ADC通道13。ADC channel 13. */
#define    ADC_Channel_P06_8Ax    0x0E  /*!< STC8A: ADC通道14。ADC channel 14. */

/* STC8G1K08A 8Pin */
#define    ADC_Channel_P30_8G1K08A    0x00 /*!< 8G1K08A: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P31_8G1K08A    0x01 /*!< 8G1K08A: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P32_8G1K08A    0x02 /*!< 8G1K08A: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P33_8G1K08A    0x03 /*!< 8G1K08A: ADC通道3。ADC channel 3. */      
#define    ADC_Channel_P54_8G1K08A    0x04 /*!< 8G1K08A: ADC通道4。ADC channel 4. */
#define    ADC_Channel_P55_8G1K08A    0x05 /*!< 8G1K08A: ADC通道5。ADC channel 5. */

/* STC8G1K08 16Pin and 20Pin / STC8G1K08T 20Pin */
#define    ADC_Channel_P10_8G1K08_T    0x00  /*!< 8G1K08: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8G1K08_T    0x01  /*!< 8G1K08: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P12_8G1K08_T    0x02  /*!< 8G1K08: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P13_8G1K08_T    0x03  /*!< 8G1K08: ADC通道3。ADC channel 3. */
#define    ADC_Channel_P14_8G1K08_T    0x04  /*!< 8G1K08: ADC通道4。ADC channel 4. */
#define    ADC_Channel_P15_8G1K08_T    0x05  /*!< 8G1K08: ADC通道5。ADC channel 5. */
#define    ADC_Channel_P16_8G1K08_T    0x06  /*!< 8G1K08: ADC通道6。ADC channel 6. */
#define    ADC_Channel_P17_8G1K08_T    0x07  /*!< 8G1K08: ADC通道7。ADC channel 7. */
#define    ADC_Channel_P30_8G1K08_T    0x08  /*!< 8G1K08: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P31_8G1K08_T    0x09  /*!< 8G1K08: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P32_8G1K08_T    0x0A  /*!< 8G1K08: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P33_8G1K08_T    0x0B  /*!< 8G1K08: ADC通道11。ADC channel 11. */
#define    ADC_Channel_P34_8G1K08_T    0x0C  /*!< 8G1K08: ADC通道12。ADC channel 12. */
#define    ADC_Channel_P35_8G1K08_T    0x0D  /*!< 8G1K08: ADC通道13。ADC channel 13. */
#define    ADC_Channel_P36_8G1K08_T    0x0E  /*!< 8G1K08: ADC通道14。ADC channel 14. */

/* STC8G2K64S4 16Pin / STC8G2K64S2 */
#define    ADC_Channel_P10_8G2K64S2_S4    0x00  /*!< 8G2K64: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8G2K64S2_S4    0x01  /*!< 8G2K64: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P12_8G2K64S2_S4    0x02  /*!< 8G2K64: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P13_8G2K64S2_S4    0x03  /*!< 8G2K64: ADC通道3。ADC channel 3. */
#define    ADC_Channel_P14_8G2K64S2_S4    0x04  /*!< 8G2K64: ADC通道4。ADC channel 4. */
#define    ADC_Channel_P15_8G2K64S2_S4    0x05  /*!< 8G2K64: ADC通道5。ADC channel 5. */
#define    ADC_Channel_P16_8G2K64S2_S4    0x06  /*!< 8G2K64: ADC通道6。ADC channel 6. */
#define    ADC_Channel_P17_8G2K64S2_S4    0x07  /*!< 8G2K64: ADC通道7。ADC channel 7. */
#define    ADC_Channel_P00_8G2K64S2_S4    0x08  /*!< 8G2K64: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P01_8G2K64S2_S4    0x09  /*!< 8G2K64: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P02_8G2K64S2_S4    0x0A  /*!< 8G2K64: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P03_8G2K64S2_S4    0x0B  /*!< 8G2K64: ADC通道11。ADC channel 11. */
#define    ADC_Channel_P04_8G2K64S2_S4    0x0C  /*!< 8G2K64: ADC通道12。ADC channel 12. */
#define    ADC_Channel_P05_8G2K64S2_S4    0x0D  /*!< 8G2K64: ADC通道13。ADC channel 13. */
#define    ADC_Channel_P06_8G2K64S2_S4    0x0E  /*!< 8G2K64: ADC通道14。ADC channel 14. */

/* STC8H1K28 */
#define    ADC_Channel_P10_8H1K28    0x00  /*!< 8H1K28: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8H1K28    0x01  /*!< 8H1K28: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P12_8H1K28    0x02  /*!< 8H1K28: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P13_8H1K28    0x03  /*!< 8H1K28: ADC通道3。ADC channel 3. */
#define    ADC_Channel_P14_8H1K28    0x04  /*!< 8H1K28: ADC通道4。ADC channel 4. */
#define    ADC_Channel_P15_8H1K28    0x05  /*!< 8H1K28: ADC通道5。ADC channel 5. */
#define    ADC_Channel_P16_8H1K28    0x06  /*!< 8H1K28: ADC通道6。ADC channel 6. */
#define    ADC_Channel_P17_8H1K28    0x07  /*!< 8H1K28: ADC通道7。ADC channel 7. */
#define    ADC_Channel_P00_8H1K28    0x08  /*!< 8H1K28: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P01_8H1K28    0x09  /*!< 8H1K28: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P02_8H1K28    0x0A  /*!< 8H1K28: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P03_8H1K28    0x0B  /*!< 8H1K28: ADC通道11。ADC channel 11. */

/* STC8H1K08 */
#define    ADC_Channel_P10_8H1K08    0x00  /*!< 8H1K28: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8H1K08    0x01  /*!< 8H1K28: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P30_8H1K08    0x08  /*!< 8H1K28: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P31_8H1K08    0x09  /*!< 8H1K28: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P32_8H1K08    0x0A  /*!< 8H1K28: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P33_8H1K08    0x0B  /*!< 8H1K28: ADC通道11。ADC channel 11. */
#define    ADC_Channel_P34_8H1K08    0x0C  /*!< 8H1K28: ADC通道12。ADC channel 12. */
#define    ADC_Channel_P35_8H1K08    0x0D  /*!< 8H1K28: ADC通道13。ADC channel 13. */
#define    ADC_Channel_P36_8H1K08    0x0E  /*!< 8H1K28: ADC通道14。ADC channel 14. */
									  
/* STC8H3K64S2 / STC8H3K64S4 */
#define    ADC_Channel_P10_8H3K64S2_S4    0x00   /*!< 8H3K64: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8H3K64S2_S4    0x01   /*!< 8H3K64: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P12_8H3K64S2_S4    0x02   /*!< 8H3K64: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P16_8H3K64S2_S4    0x06   /*!< 8H3K64: ADC通道6。ADC channel 6. */
#define    ADC_Channel_P17_8H3K64S2_S4    0x07   /*!< 8H3K64: ADC通道7。ADC channel 7. */
#define    ADC_Channel_P00_8H3K64S2_S4    0x08   /*!< 8H3K64: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P01_8H3K64S2_S4    0x09   /*!< 8H3K64: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P02_8H3K64S2_S4    0x0A   /*!< 8H3K64: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P03_8H3K64S2_S4    0x0B   /*!< 8H3K64: ADC通道11。ADC channel 11. */
#define    ADC_Channel_P04_8H3K64S2_S4    0x0C   /*!< 8H3K64: ADC通道12。ADC channel 12. */
#define    ADC_Channel_P05_8H3K64S2_S4    0x0D   /*!< 8H3K64: ADC通道13。ADC channel 13. */
#define    ADC_Channel_P06_8H3K64S2_S4    0x0E   /*!< 8H3K64: ADC通道14。ADC channel 14. */

/* STC8H8K64U / STC8H2K64T */
#define    ADC_Channel_P10_8H8K64U_2K64T    0x00  /*!< 8H8K/2K: ADC通道0。ADC channel 0. */
#define    ADC_Channel_P11_8H8K64U_2K64T    0x01  /*!< 8H8K/2K: ADC通道1。ADC channel 1. */
#define    ADC_Channel_P54_8H8K64U_2K64T    0x02  /*!< 8H8K/2K: ADC通道2。ADC channel 2. */
#define    ADC_Channel_P13_8H8K64U_2K64T    0x03  /*!< 8H8K/2K: ADC通道3。ADC channel 3. */
#define    ADC_Channel_P14_8H8K64U_2K64T    0x04  /*!< 8H8K/2K: ADC通道4。ADC channel 4. */
#define    ADC_Channel_P15_8H8K64U_2K64T    0x05  /*!< 8H8K/2K: ADC通道5。ADC channel 5. */
#define    ADC_Channel_P16_8H8K64U_2K64T    0x06  /*!< 8H8K/2K: ADC通道6。ADC channel 6. */
#define    ADC_Channel_P17_8H8K64U_2K64T    0x07  /*!< 8H8K/2K: ADC通道7。ADC channel 7. */
#define    ADC_Channel_P00_8H8K64U_2K64T    0x08  /*!< 8H8K/2K: ADC通道8。ADC channel 8. */
#define    ADC_Channel_P01_8H8K64U_2K64T    0x09  /*!< 8H8K/2K: ADC通道9。ADC channel 9. */
#define    ADC_Channel_P02_8H8K64U_2K64T    0x0A  /*!< 8H8K/2K: ADC通道10。ADC channel 10. */
#define    ADC_Channel_P03_8H8K64U_2K64T    0x0B  /*!< 8H8K/2K: ADC通道11。ADC channel 11. */
#define    ADC_Channel_P04_8H8K64U_2K64T    0x0C  /*!< 8H8K/2K: ADC通道12。ADC channel 12. */
#define    ADC_Channel_P05_8H8K64U_2K64T    0x0D  /*!< 8H8K/2K: ADC通道13。ADC channel 13. */
#define    ADC_Channel_P06_8H8K64U_2K64T    0x0E  /*!< 8H8K/2K: ADC通道14。ADC channel 14. */


/** 
 * @brief		ADC采集精度枚举体。
 * @details	    This is the ADC acquisition accuracy enumeration.
**/
typedef enum
{
	#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Hx )
		ADC_Acc_12Bits = 0x00,    /*!< ADC12位采集精度。ADC12 bit acquisition accuracy. */
		ADC_Acc_11Bits = 0x01,    /*!< ADC11位采集精度。ADC 11 bit acquisition accuracy. */
		ADC_Acc_10Bits = 0x02,    /*!< ADC10位采集精度。ADC 10 bit acquisition accuracy. */
		ADC_Acc_9Bits  = 0x03,    /*!< ADC9位采集精度。ADC 9 bit acquisition accuracy. */
		ADC_Acc_8Bits  = 0x04     /*!< ADC8位采集精度。ADC 8 bit acquisition accuracy. */
	#elif (PER_LIB_MCU_MUODEL == STC8Gx )
		ADC_Acc_10Bits = 0x00,   
		ADC_Acc_09Bits = 0x01,    
		ADC_Acc_08Bits = 0x02     
	#endif
} ADCAcc_Type;


/** 
 * @brief		ADC输出结果对齐方向枚举体。
 * @details	    The ADC output is aligned with the direction enumerator.
**/
typedef enum
{
	ADC_Left  = 0x00,  /*!< ADC采集数据左对齐。The data is aligned to the left. */ 
	ADC_Right = 0x01   /*!< ADC采集数据右对齐。The data is aligned to the right. */ 
}   ADCAlign_Type;


/** 
 * @brief		ADC初始化结构体句柄，初始化时请定义该句柄，并用其地址来传参。
 * @details	    The ADC initializes the structure handle. When initializing,
 *              please define the handle and use its address to pass parameters.
**/
typedef struct 
{
	BOOL Power;           /*!< ADC电源控制位。  ADC power control bit. */
	uint8_t Channel;     /*!< ADC采集通道选择。ADC channel selection. */
	uint8_t Speed;       /*!< ADC采集速度,最大速度0x0F，如果大于这个值，将初始化失败。
							  he maximum ADC conversion speed (working clock frequency) is 0x0F.*/
	ADCAlign_Type Align;  /*!< ADC采样结果对齐方式。ADC data format alignment. */
	BOOL Run;             /*!< ADC运行控制位。ADC conversion operation control bit. */
}   ADC_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
		
#if (PER_LIB_ADC_CTRL == 1)

	#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
		
		#if (PER_LIB_ADC_INIT_CTRL == 1)
		
			/**
			 * @brief		ADC外设初始化函数。
			 * @details	    This is a ADC peripheral init function. 
			 * @param[in]	adcx          ADC结构体句柄，初始化时请定义该句柄，并用其地址来传参。
			 *                            ADC structure handle. When initializing, 
			 *                            please define the handle and use its address
			 *                            to pass parameters.
			 * @return		FSC_SUCCESS	  成功。success.
			 * @return		FSC_FAIL	  失败。fail.
			**/
			FSCSTATE ADC_Init(const ADC_InitType* adcx);
		
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
			uint16_t ADC_Get_Sample(uint8_t channel, ADCAcc_Type acc);
		

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
			uint16_t ADC_Get_Sample_Interrupt(ADCAcc_Type acc);

            /**
             * @brief   ADC获取当前采集通道宏函数。
             * @details ADC obtains the macro function of 
             *          the current acquisition channel.
            **/
            #define ADC_GET_CHANNEL()        (ADC_CONTR & 0x0F)


            /**
             * @brief     ADC改变采集通道宏函数。
             * @details   ADC change the macro function of 
             *            the current acquisition channel.
             * @param[in] channel ADC采集通道,不同的芯片型号，通道有所不同，请查看头文件的宏定义。
             *                    ADC acquisition channel, different chip models, 
             *                    the channel is different, 
             *                    please check the macro definition of the header file
            **/
            #define ADC_CHANGE_CHANNEL(channel)              \
			do{                                              \
				ADC_CONTR = (ADC_CONTR & 0xF0) | (channel);  \
			}while(0)
			
		#endif
		
		#if (PER_LIB_ADC_NVIC_CTRL == 1)		
		
            /**
             * @brief	   ADC中断初始化函数。
             * @details	   This is a ADC priority initialization function. 
             * @param[in]  pri 中断优先级。Interrupt priority.
             * @param[in]  run 中断运行控制位。Interrupt operation control bit.
             * @return     FSC_SUCCESS 返回成功。Return to success.
             * @return     FSC_FAIL    返回失败。Return to fail.
            **/
            FSCSTATE NVIC_ADC_Init(NVICPri_Type pri,BOOL run);


            /**
             * @brief   ADC获取采集完成（中断）标志位宏函数。
             * @details ADC obtains macro function of acquisition 
             *          completion (interrupt) flag bit.
             * @return  [bit] 完成（中断）标志位。Completion (interrupt) flag bit.
            **/
            #define ADC_GET_FLAG()       (ADC_CONTR & 0x20)


            /**
             * @brief   ADC清除采集完成（中断）标志位宏函数。
             * @details ADC clears macro function of acquisition 
             *          completion (interrupt) flag bit.
            **/
            #define ADC_CLEAR_FLAG()      do{ADC_CONTR &= 0xDF;}while(0)


            /**
             * @brief     ADC中断开关控制宏函数。
             * @details   ADC interrupt switch control macro function.
             * @param[in] run  使能控制位。Enable control bit.
            **/
            #define NVIC_ADC_CTRL(run)     do{EADC = run;}while(0)

			
			/**
			 * @brief      ADC选择中断优先级宏函数。
			 * @details    ADC select interrupt priority macro function.
			 * @param[in]  pri 中断优先级。 Priority of interrupt.
			**/
			#define NVIC_ADC_PRI(pri)                     \
			do{                                           \
				IPH = (IPH & 0xDF) | ((pri & 0x02) << 4); \
				IP  = (IP  & 0xDF) | ((pri & 0x01) << 5); \
			}while(0)
			
        #endif

	#endif

#endif


/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/
#endif
