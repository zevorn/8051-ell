/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_COMP.h
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
#ifndef __STC8Ax_COMP_H_
#define __STC8Ax_COMP_H_

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

/** 如果没有定义这个宏，默认为STC8Ax。
    If the mirco is undefined，select to STC8Ax */
#ifndef PER_LIB_MCU_MUODEL
    #define PER_LIB_MCU_MUODEL STC8Ax
#endif

/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_COMP_CTRL
    #define PER_LIB_COMP_CTRL 1
#endif

/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_COMP_INIT_CTRL
    #define PER_LIB_COMP_INIT_CTRL 1
#endif

/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_COMP_NVIC_CTRL
    #define PER_LIB_COMP_NVIC_CTRL 1
#endif

/** 如果没有定义这个宏，默认为1。
    If the mirco is undefined，select to "1" */
#ifndef PER_LIB_COMP_WORK_CTRL
    #define PER_LIB_COMP_WORK_CTRL 1
#endif


//** 正极引脚P37。PEPin. */
#define  COMP_PE_P37     0xF7

/* STC8Ax */
#define    COMP_PE_P10_8Ax    0x00   /*!< STC8A: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P11_8Ax    0x01   /*!< STC8A: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P12_8Ax    0x02   /*!< STC8A: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P13_8Ax    0x03   /*!< STC8A: 比较器正极复用ADC通道3。ADC channel 3. */
#define    COMP_PE_P14_8Ax    0x04   /*!< STC8A: 比较器正极复用ADC通道4。ADC channel 4. */
#define    COMP_PE_P15_8Ax    0x05   /*!< STC8A: 比较器正极复用ADC通道5。ADC channel 5. */
#define    COMP_PE_P16_8Ax    0x06   /*!< STC8A: 比较器正极复用ADC通道6。ADC channel 6. */
#define    COMP_PE_P17_8Ax    0x07   /*!< STC8A: 比较器正极复用ADC通道7。ADC channel 7. */
#define    COMP_PE_P00_8Ax    0x08   /*!< STC8A: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P01_8Ax    0x09   /*!< STC8A: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P02_8Ax    0x0A   /*!< STC8A: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P03_8Ax    0x0B   /*!< STC8A: 比较器正极复用ADC通道11。ADC channel 11. */
#define    COMP_PE_P04_8Ax    0x0C   /*!< STC8A: 比较器正极复用ADC通道12。ADC channel 12. */
#define    COMP_PE_P05_8Ax    0x0D   /*!< STC8A: 比较器正极复用ADC通道13。ADC channel 13. */
#define    COMP_PE_P06_8Ax    0x0E   /*!< STC8A: 比较器正极复用ADC通道14。ADC channel 14. */

/* STC8G1K08A 8Pin */
#define    COMP_PE_P30_8G1K08A    0x00  /*!< 8G1K08A: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P31_8G1K08A    0x01  /*!< 8G1K08A: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P32_8G1K08A    0x02  /*!< 8G1K08A: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P33_8G1K08A    0x03  /*!< 8G1K08A: 比较器正极复用ADC通道3。ADC channel 3. */       
#define    COMP_PE_P54_8G1K08A    0x04  /*!< 8G1K08A: 比较器正极复用ADC通道4。ADC channel 4. */
#define    COMP_PE_P55_8G1K08A    0x05  /*!< 8G1K08A: 比较器正极复用ADC通道5。ADC channel 5. */

/* STC8G1K08 16Pin and 20Pin / STC8G1K08T 20Pin */
#define    COMP_PE_P10_8G1K08_T    0x00  /*!< 8G1K08: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P11_8G1K08_T    0x01  /*!< 8G1K08: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P12_8G1K08_T    0x02  /*!< 8G1K08: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P13_8G1K08_T    0x03  /*!< 8G1K08: 比较器正极复用ADC通道3。ADC channel 3. */
#define    COMP_PE_P14_8G1K08_T    0x04  /*!< 8G1K08: 比较器正极复用ADC通道4。ADC channel 4. */
#define    COMP_PE_P15_8G1K08_T    0x05  /*!< 8G1K08: 比较器正极复用ADC通道5。ADC channel 5. */
#define    COMP_PE_P16_8G1K08_T    0x06  /*!< 8G1K08: 比较器正极复用ADC通道6。ADC channel 6. */
#define    COMP_PE_P17_8G1K08_T    0x07  /*!< 8G1K08: 比较器正极复用ADC通道7。ADC channel 7. */
#define    COMP_PE_P30_8G1K08_T    0x08  /*!< 8G1K08: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P31_8G1K08_T    0x09  /*!< 8G1K08: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P32_8G1K08_T    0x0A  /*!< 8G1K08: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P33_8G1K08_T    0x0B  /*!< 8G1K08: 比较器正极复用ADC通道11。ADC channel 11. */
#define    COMP_PE_P34_8G1K08_T    0x0C  /*!< 8G1K08: 比较器正极复用ADC通道12。ADC channel 12. */
#define    COMP_PE_P35_8G1K08_T    0x0D  /*!< 8G1K08: 比较器正极复用ADC通道13。ADC channel 13. */
#define    COMP_PE_P36_8G1K08_T    0x0E  /*!< 8G1K08: 比较器正极复用ADC通道14。ADC channel 14. */

/* STC8G2K64S4 16Pin / STC8G2K64S2 */
#define    COMP_PE_P10_8G2K64S2_S4    0x00  /*!< 8G2K64: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P11_8G2K64S2_S4    0x01  /*!< 8G2K64: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P12_8G2K64S2_S4    0x02  /*!< 8G2K64: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P13_8G2K64S2_S4    0x03  /*!< 8G2K64: 比较器正极复用ADC通道3。ADC channel 3. */
#define    COMP_PE_P14_8G2K64S2_S4    0x04  /*!< 8G2K64: 比较器正极复用ADC通道4。ADC channel 4. */
#define    COMP_PE_P15_8G2K64S2_S4    0x05  /*!< 8G2K64: 比较器正极复用ADC通道5。ADC channel 5. */
#define    COMP_PE_P16_8G2K64S2_S4    0x06  /*!< 8G2K64: 比较器正极复用ADC通道6。ADC channel 6. */
#define    COMP_PE_P17_8G2K64S2_S4    0x07  /*!< 8G2K64: 比较器正极复用ADC通道7。ADC channel 7. */
#define    COMP_PE_P00_8G2K64S2_S4    0x08  /*!< 8G2K64: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P01_8G2K64S2_S4    0x09  /*!< 8G2K64: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P02_8G2K64S2_S4    0x0A  /*!< 8G2K64: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P03_8G2K64S2_S4    0x0B  /*!< 8G2K64: 比较器正极复用ADC通道11。ADC channel 11. */
#define    COMP_PE_P04_8G2K64S2_S4    0x0C  /*!< 8G2K64: 比较器正极复用ADC通道12。ADC channel 12. */
#define    COMP_PE_P05_8G2K64S2_S4    0x0D  /*!< 8G2K64: 比较器正极复用ADC通道13。ADC channel 13. */
#define    COMP_PE_P06_8G2K64S2_S4    0x0E  /*!< 8G2K64: 比较器正极复用ADC通道14。ADC channel 14. */

/* STC8H1K28 */
#define    COMP_PE_P10_8H1K28    0x00  /*!< 8H1K28: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P11_8H1K28    0x01  /*!< 8H1K28: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P12_8H1K28    0x02  /*!< 8H1K28: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P13_8H1K28    0x03  /*!< 8H1K28: 比较器正极复用ADC通道3。ADC channel 3. */
#define    COMP_PE_P14_8H1K28    0x04  /*!< 8H1K28: 比较器正极复用ADC通道4。ADC channel 4. */
#define    COMP_PE_P15_8H1K28    0x05  /*!< 8H1K28: 比较器正极复用ADC通道5。ADC channel 5. */
#define    COMP_PE_P16_8H1K28    0x06  /*!< 8H1K28: 比较器正极复用ADC通道6。ADC channel 6. */
#define    COMP_PE_P17_8H1K28    0x07  /*!< 8H1K28: 比较器正极复用ADC通道7。ADC channel 7. */
#define    COMP_PE_P00_8H1K28    0x08  /*!< 8H1K28: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P01_8H1K28    0x09  /*!< 8H1K28: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P02_8H1K28    0x0A  /*!< 8H1K28: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P03_8H1K28    0x0B  /*!< 8H1K28: 比较器正极复用ADC通道11。ADC channel 11. */

/* STC8H1K08 */
#define    COMP_PE_P10_8H1K08    0x00  /*!< 8H1K28: 比较器正极复用ADC通道0。ADC channel 0. */ 
#define    COMP_PE_P11_8H1K08    0x01  /*!< 8H1K28: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P30_8H1K08    0x08  /*!< 8H1K28: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P31_8H1K08    0x09  /*!< 8H1K28: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P32_8H1K08    0x0A  /*!< 8H1K28: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P33_8H1K08    0x0B  /*!< 8H1K28: 比较器正极复用ADC通道11。ADC channel 11. */
#define    COMP_PE_P34_8H1K08    0x0C  /*!< 8H1K28: 比较器正极复用ADC通道12。ADC channel 12. */
#define    COMP_PE_P35_8H1K08    0x0D  /*!< 8H1K28: 比较器正极复用ADC通道13。ADC channel 13. */
#define    COMP_PE_P36_8H1K08    0x0E  /*!< 8H1K28: 比较器正极复用ADC通道14。ADC channel 14. */

/* STC8H3K64S2 / STC8H3K64S4 */
#define    COMP_PE_P10_8H3K64S2_S4    0x00  /*!< 8H3K64: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P11_8H3K64S2_S4    0x01  /*!< 8H3K64: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P12_8H3K64S2_S4    0x02  /*!< 8H3K64: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P16_8H3K64S2_S4    0x06  /*!< 8H3K64: 比较器正极复用ADC通道6。ADC channel 6. */
#define    COMP_PE_P17_8H3K64S2_S4    0x07  /*!< 8H3K64: 比较器正极复用ADC通道7。ADC channel 7. */
#define    COMP_PE_P00_8H3K64S2_S4    0x08  /*!< 8H3K64: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P01_8H3K64S2_S4    0x09  /*!< 8H3K64: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P02_8H3K64S2_S4    0x0A  /*!< 8H3K64: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P03_8H3K64S2_S4    0x0B  /*!< 8H3K64: 比较器正极复用ADC通道11。ADC channel 11. */
#define    COMP_PE_P04_8H3K64S2_S4    0x0C  /*!< 8H3K64: 比较器正极复用ADC通道12。ADC channel 12. */
#define    COMP_PE_P05_8H3K64S2_S4    0x0D  /*!< 8H3K64: 比较器正极复用ADC通道13。ADC channel 13. */
#define    COMP_PE_P06_8H3K64S2_S4    0x0E  /*!< 8H3K64: 比较器正极复用ADC通道14。ADC channel 14. */

/* STC8H8K64U / STC8H2K64T */
#define    COMP_PE_P10_8H8K64U_2K64T    0x00  /*!< 8H8K/2K: 比较器正极复用ADC通道0。ADC channel 0. */
#define    COMP_PE_P11_8H8K64U_2K64T    0x01  /*!< 8H8K/2K: 比较器正极复用ADC通道1。ADC channel 1. */
#define    COMP_PE_P54_8H8K64U_2K64T    0x02  /*!< 8H8K/2K: 比较器正极复用ADC通道2。ADC channel 2. */
#define    COMP_PE_P13_8H8K64U_2K64T    0x03  /*!< 8H8K/2K: 比较器正极复用ADC通道3。ADC channel 3. */
#define    COMP_PE_P14_8H8K64U_2K64T    0x04  /*!< 8H8K/2K: 比较器正极复用ADC通道4。ADC channel 4. */
#define    COMP_PE_P15_8H8K64U_2K64T    0x05  /*!< 8H8K/2K: 比较器正极复用ADC通道5。ADC channel 5. */
#define    COMP_PE_P16_8H8K64U_2K64T    0x06  /*!< 8H8K/2K: 比较器正极复用ADC通道6。ADC channel 6. */
#define    COMP_PE_P17_8H8K64U_2K64T    0x07  /*!< 8H8K/2K: 比较器正极复用ADC通道7。ADC channel 7. */
#define    COMP_PE_P00_8H8K64U_2K64T    0x08  /*!< 8H8K/2K: 比较器正极复用ADC通道8。ADC channel 8. */
#define    COMP_PE_P01_8H8K64U_2K64T    0x09  /*!< 8H8K/2K: 比较器正极复用ADC通道9。ADC channel 9. */
#define    COMP_PE_P02_8H8K64U_2K64T    0x0A  /*!< 8H8K/2K: 比较器正极复用ADC通道10。ADC channel 10. */
#define    COMP_PE_P03_8H8K64U_2K64T    0x0B  /*!< 8H8K/2K: 比较器正极复用ADC通道11。ADC channel 11. */
#define    COMP_PE_P04_8H8K64U_2K64T    0x0C  /*!< 8H8K/2K: 比较器正极复用ADC通道12。ADC channel 12. */
#define    COMP_PE_P05_8H8K64U_2K64T    0x0D  /*!< 8H8K/2K: 比较器正极复用ADC通道13。ADC channel 13. */
#define    COMP_PE_P06_8H8K64U_2K64T    0x0E  /*!< 8H8K/2K: 比较器正极复用ADC通道14。ADC channel 14. */

/** 比较器负极。NEPin. */
#define  COMP_NE_P36     0x10

/** 正极和负极都可以接入,内部测试电压。NEPin and PEPin : Test the internal 1.344v refv voltage. */
#define	 COMP_IN_REV     0x0F


/**
 * @brief   COMP输出方向枚举体。
 * @details COMP output direction enumerator.
**/
typedef enum
{
	COMP_DIR_Forward = 0x00, /*!< 比较器结果正向输出，若结果为0，则对外输出低电平，反之输出高电平。
								  The result of comparator is forward output,if the result is 0,
								  Output low level, otherwise output high level. */
	COMP_DIR_Reverse = 0x01 /*!< 比较器结果反向输出，若结果为0，则对外输出高电平，反之输出低电平。
								  The result of comparator is Reverse output,if the result is 0,
								  Output high level, otherwise output low level. */       
}   COMPDIRPut_Type;


/**
 * @brief   COMP中断触发方式枚举体。
 * @details COMP interrupt Trigger enumerator.
**/
typedef enum
{
	COMP_Tri_Null    = 0x00, /*!< 比较器无中断触发，不使能中断。
								  The comparator is triggered without 
								  interruption and can not be interrupted.*/
	COMP_Tri_Falling = 0x10, /*!< 比较器下降沿触发中断，使能中断。
								  The falling edge of the comparator triggers，
								  enable the interrupt.*/
	COMP_Tri_Rising  = 0x20, /*!< 比较器上升沿触发中断，使能中断。
								  The rising edge of the comparator triggers 
								  enable the interrupt.*/
	COMP_Tri_Edge    = 0x30 /*!<  比较器边沿沿触发中断，使能中断。
								  The edge edge of the comparator triggers  
								  enable the interrupt.*/
} COMPTri_Type;

/**
 * @brief   COMP初始化结构体句柄，初始化时请定义该句柄，并用其地址来传参。
 * @details The COMP initializes the structure handle. When initializing, 
 *          please define the handle and use its address to pass parameters.
**/
typedef struct
{
	uint8_t PEPin;            /*!< 负极输入脚。COMP positive input selection bit.*/         
	uint8_t NEPin;	          /*!< 正极输入脚。COMP negative input selection bit.*/   
	BOOL AC_FTW;              /*!< 模拟滤波控制位。 COMP 0.1us analog filter control bit.*/   
	uint16_t DC_FTW;          /*!< 数字滤波控制时间参数，0为关闭数字滤波。COMP digital filter clock number.*/   
	COMPDIRPut_Type DIRPut;   /*!< 比较结果输出方向。COMP output direction.*/   
	BOOL Output;              /*!< 比较结果输出控制位。COMP result output control bit.*/   
	BOOL Run;                 /*!< 比较器运行控制位。 COMP operation control bit.*/   
} COMP_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (PER_LIB_COMP_CTRL == 1)

    #if (PER_LIB_COMP_INIT_CTRL == 1)

        /**
         * @brief     COMP初始化函数。
         * @details   COMP initialization function.
         * @param[in] compx  COMP结构体句柄，初始化时请定义该句柄，并用其地址来传参。
         *                   COMP structure handle. When initializing, 
         *                   please define the handle and use its address 
         *                   to pass parameters.
         * @return    FSC_SUCCESS 返回成功。Return to success.
         * @return    FSC_FAIL    返回失败。Return to fail.
        ***/
        FSCSTATE COMP_Init(const COMP_InitType *compx);

    #endif


    #if (PER_LIB_COMP_NVIC_CTRL == 1)

        /**
         * @brief       COMP中断初始化函数。
         * @details     COMP interrupt initialization function.
         * @param[in]   pri 中断优先级。Interrupt priority.
         * @param[in]   triMode  触发模式。Trigger mode.
         * @return      FSC_SUCCESS 返回成功。Return to success.
         * @return      FSC_FAIL    返回失败。Return to fail.
        **/
        FSCSTATE NVIC_COMP_Init(NVICPri_Type pri,COMPTri_Type triMode);


        /**
         * @brief     COMP中断开关控制宏函数。
         * @details   COMP interrupt switch control macro function.
         * @param[in] run 使能控制位。Enable control bit.
        ***/
        #define NVIC_COMP_CTRL(run)    do{CMPCR1 = (CMPCR1 & 0xCF)|(run << 4);}while(0)
		
		
		/**
		 * @brief      COMP选择中断优先级宏函数。
		 * @details    COMP select interrupt priority macro function.
		 * @param[in]  pri 中断优先级。 Priority of interrupt.
		**/
		#define COMP_NVIC_PRI(pri)                      \
		do{                                             \
			IP2H = (IP2H & 0xEF) | ((pri & 0x02) << 3); \
			IP2  = (IP2  & 0xEF) | ((pri & 0x01) << 4); \
		}while(0)
		
    #endif


    #if (PER_LIB_COMP_WORK_CTRL == 1)

        /**
         * @brief   获取比较完成（也是中断）标志位宏函数。
         * @details Comp gets compare complete (interrupt) 
         *          flag bit macro function.
         * @return  [bit] 完成（也是中断）标志位。Completion (interrupt) flag bit.
        **/
        #define COMP_GET_FLAG()        (CMPCR1 & 0x40)


        /**
         * @brief   COMP清除比较完成（也是中断）标志位宏函数。
         * @details Comp clears compare complete (interrupt) 
         *          flag bit macro function.
        ***/
        #define COMP_CLEAR_FLAG()      do{CMPCR1 &= 0xBF;}while(0)


        /**
         * @brief   COMP切换复用IO函数。
         * @details COMP switch out port control function.  
         * @param   port [IN] 复用IO枚举体。IO switch enumerator.
         * @return  FSC_SUCCESS 返回成功。Return to success.
         * @return  FSC_FAIL    返回失败。Return to fail.
        ***/
        FSCSTATE GPIO_COMP_SWPort(GPIOSWPort_Type port);

        /**
         * @brief   COMP获取比较结果宏函数。
         * @details Comp gets the macro function of the comparison result.
         * @return  [bit] 比较结果。Comparison result.
        ***/
        #define COMP_GET_RESULT()         (CMPCR1 & 0x01)

    #endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/
#endif
