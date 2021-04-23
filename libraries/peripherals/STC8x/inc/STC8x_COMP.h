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
 * Apache-2.0 License License for more details.

 * You should have received a copy of the Apache-2.0 License.8051 ELL 
 * low-layer libraries. If not, see <http://www.apache.org/licenses/>.
**/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#ifndef __STC8Ax_COMP_H_
#define __STC8Ax_COMP_H_
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
| @Description: ELL library core                         |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: COMP Pin define                          |
--------------------------------------------------------*/

/* PEPin */
#define  COMP_PE_P37     0xF7

/* STC8Ax */
#define    COMP_PE_P10_8Ax    0x00
#define    COMP_PE_P11_8Ax    0x01
#define    COMP_PE_P12_8Ax    0x02
#define    COMP_PE_P13_8Ax    0x03
#define    COMP_PE_P14_8Ax    0x04
#define    COMP_PE_P15_8Ax    0x05
#define    COMP_PE_P16_8Ax    0x06
#define    COMP_PE_P17_8Ax    0x07
#define    COMP_PE_P00_8Ax    0x08
#define    COMP_PE_P01_8Ax    0x09
#define    COMP_PE_P02_8Ax    0x0A
#define    COMP_PE_P03_8Ax    0x0B
#define    COMP_PE_P04_8Ax    0x0C
#define    COMP_PE_P05_8Ax    0x0D
#define    COMP_PE_P06_8Ax    0x0E

/* STC8G1K08A 8Pin */
#define    COMP_PE_P30_8G1K08A    0x00
#define    COMP_PE_P31_8G1K08A    0x01
#define    COMP_PE_P32_8G1K08A    0x02
#define    COMP_PE_P33_8G1K08A    0x03        
#define    COMP_PE_P54_8G1K08A    0x04
#define    COMP_PE_P55_8G1K08A    0x05

/* STC8G1K08 16Pin and 20Pin / STC8G1K08T 20Pin */
#define    COMP_PE_P10_8G1K08_T    0x00
#define    COMP_PE_P11_8G1K08_T    0x01
#define    COMP_PE_P12_8G1K08_T    0x02
#define    COMP_PE_P13_8G1K08_T    0x03
#define    COMP_PE_P14_8G1K08_T    0x04
#define    COMP_PE_P15_8G1K08_T    0x05
#define    COMP_PE_P16_8G1K08_T    0x06
#define    COMP_PE_P17_8G1K08_T    0x07
#define    COMP_PE_P30_8G1K08_T    0x08
#define    COMP_PE_P31_8G1K08_T    0x09
#define    COMP_PE_P32_8G1K08_T    0x0A
#define    COMP_PE_P33_8G1K08_T    0x0B
#define    COMP_PE_P34_8G1K08_T    0x0C
#define    COMP_PE_P35_8G1K08_T    0x0D
#define    COMP_PE_P36_8G1K08_T    0x0E

/* STC8G2K64S4 16Pin / STC8G2K64S2 */
#define    COMP_PE_P10_8G2K64S2_S4    0x00
#define    COMP_PE_P11_8G2K64S2_S4    0x01
#define    COMP_PE_P12_8G2K64S2_S4    0x02
#define    COMP_PE_P13_8G2K64S2_S4    0x03
#define    COMP_PE_P14_8G2K64S2_S4    0x04
#define    COMP_PE_P15_8G2K64S2_S4    0x05
#define    COMP_PE_P16_8G2K64S2_S4    0x06
#define    COMP_PE_P17_8G2K64S2_S4    0x07
#define    COMP_PE_P00_8G2K64S2_S4    0x08
#define    COMP_PE_P01_8G2K64S2_S4    0x09
#define    COMP_PE_P02_8G2K64S2_S4    0x0A
#define    COMP_PE_P03_8G2K64S2_S4    0x0B
#define    COMP_PE_P04_8G2K64S2_S4    0x0C
#define    COMP_PE_P05_8G2K64S2_S4    0x0D
#define    COMP_PE_P06_8G2K64S2_S4    0x0E
   
/* STC8H1K28 */
#define    COMP_PE_P10_8H1K28    0x00
#define    COMP_PE_P11_8H1K28    0x01
#define    COMP_PE_P12_8H1K28    0x02
#define    COMP_PE_P13_8H1K28    0x03
#define    COMP_PE_P14_8H1K28    0x04
#define    COMP_PE_P15_8H1K28    0x05
#define    COMP_PE_P16_8H1K28    0x06
#define    COMP_PE_P17_8H1K28    0x07
#define    COMP_PE_P00_8H1K28    0x08
#define    COMP_PE_P01_8H1K28    0x09
#define    COMP_PE_P02_8H1K28    0x0A
#define    COMP_PE_P03_8H1K28    0x0B

/* STC8H1K08 */
#define    COMP_PE_P10_8H1K08    0x00
#define    COMP_PE_P11_8H1K08    0x01
#define    COMP_PE_P30_8H1K08    0x08
#define    COMP_PE_P31_8H1K08    0x09
#define    COMP_PE_P32_8H1K08    0x0A
#define    COMP_PE_P33_8H1K08    0x0B
#define    COMP_PE_P34_8H1K08    0x0C
#define    COMP_PE_P35_8H1K08    0x0D
#define    COMP_PE_P36_8H1K08    0x0E

/* STC8H3K64S2 / STC8H3K64S4 */
#define    COMP_PE_P10_8H3K64S2_S4    0x00
#define    COMP_PE_P11_8H3K64S2_S4    0x01
#define    COMP_PE_P12_8H3K64S2_S4    0x02
#define    COMP_PE_P16_8H3K64S2_S4    0x06
#define    COMP_PE_P17_8H3K64S2_S4    0x07
#define    COMP_PE_P00_8H3K64S2_S4    0x08
#define    COMP_PE_P01_8H3K64S2_S4    0x09
#define    COMP_PE_P02_8H3K64S2_S4    0x0A
#define    COMP_PE_P03_8H3K64S2_S4    0x0B
#define    COMP_PE_P04_8H3K64S2_S4    0x0C
#define    COMP_PE_P05_8H3K64S2_S4    0x0D
#define    COMP_PE_P06_8H3K64S2_S4    0x0E

/* STC8H8K64U / STC8H2K64T */
#define    COMP_PE_P10_8H8K64U_2K64T    0x00
#define    COMP_PE_P11_8H8K64U_2K64T    0x01
#define    COMP_PE_P54_8H8K64U_2K64T    0x02
#define    COMP_PE_P13_8H8K64U_2K64T    0x03
#define    COMP_PE_P14_8H8K64U_2K64T    0x04
#define    COMP_PE_P15_8H8K64U_2K64T    0x05
#define    COMP_PE_P16_8H8K64U_2K64T    0x06
#define    COMP_PE_P17_8H8K64U_2K64T    0x07
#define    COMP_PE_P00_8H8K64U_2K64T    0x08
#define    COMP_PE_P01_8H8K64U_2K64T    0x09
#define    COMP_PE_P02_8H8K64U_2K64T    0x0A
#define    COMP_PE_P03_8H8K64U_2K64T    0x0B
#define    COMP_PE_P04_8H8K64U_2K64T    0x0C
#define    COMP_PE_P05_8H8K64U_2K64T    0x0D
#define    COMP_PE_P06_8H8K64U_2K64T    0x0E

/* NEPin */
#define  COMP_NE_P36     0x10

/* 
NEPin and PEPin :
Test the internal 1.344v refv voltage.
*/
#define	 COMP_IN_REV     0x0F


/**
  * @name    COMPDIRPut_Type
  * @brief   COMP输出方向枚举体。
  *          COMP output direction enumerator.
  * @param   COMP_DIR_Forward [uint8_t] 比较器结果正向输出，若结果为0，
  *                                     则对外输出低电平，反之输出高电平。
  *                                     The result of comparator is forward output, 
  *                                     if the result is 0,
  *                                     Output low level, otherwise output high level.
  * @param   COMP_DIR_Reverse [uint8_t] 比较器结果反向输出，若结果为0，
                                        则对外输出高电平，反之输出低电平。
  *                                     The result of comparator is Reverse output, 
  *                                     if the result is 0,
  *                                     Output low high, otherwise output low level.
***/
typedef enum
{
    COMP_DIR_Forward = 0x00, 
	COMP_DIR_Reverse = 0x01       
}   COMPDIRPut_Type;


/**
  * @name    COMPTri_Type
  * @brief   COMP中断触发方式枚举体。
  *          COMP interrupt Trigger enum .
  * @param   COMP_Tri_Null    [uint8_t] 比较器无中断触发，不使能中断。
  *                                     The comparator is triggered 
  *                                     without interruption and can not be interrupted.
  * @param   COMP_Tri_Falling [uint8_t] 比较器下降沿触发中断，使能中断。
  *                                     The falling edge of the comparator triggers 
  *                                     he interrupt to enable the interrupt. 
  * @param   COMP_Tri_Rising  [uint8_t] 比较器上升沿触发中断，使能中断。
  *                                     The rising edge of the comparator triggers 
  *                                     he interrupt to enable the interrupt. 
  * @param   COMP_Tri_Edge    [uint8_t] 比较器边沿沿触发中断，使能中断。
  *                                     The edge edge of the comparator triggers 
  *                                     he interrupt to enable the interrupt. 
***/
typedef enum
{
  COMP_Tri_Null    = 0x00,
  COMP_Tri_Falling = 0x10,
  COMP_Tri_Rising  = 0x20,
  COMP_Tri_Edge    = 0x30
} COMPTri_Type;

/**
  * @name    COMP_InitType
  * @brief   COMP初始化结构体句柄，初始化时请定义该句柄，并用其地址来传参。
  *          The COMP initializes the structure handle. When initializing, 
  *          please define the handle and use its address to pass parameters.
  * @param   PEPin   [uint8_t] 负极输入脚。COMP positive input selection bit.
  * @param   NEPin   [uint8_t] 正极输入脚。COMP negative input selection bit.
  * @param   AC_FTW  [BOOL]    模拟滤波控制位。 COMP 0.1us analog filter control bit.
  * @param   DC_FTW  [uint16_t] 数字滤波控制时间参数，0为关闭数字滤波。
  *                             COMP digital filter clock number.
  * @param   DIRPut  [COMPDIRPut_Type] 比较结果输出方向。COMP output direction.
  * @param   Output  [BOOL]   比较结果输出控制位。COMP result output control bit.
  * @param   Run     [BOOL]   比较器运行控制位。 COMP operation control bit.
***/
typedef struct
{
    uint8_t PEPin;            
    uint8_t NEPin;	          
    BOOL AC_FTW;        
    uint16_t DC_FTW;          
    COMPDIRPut_Type DIRPut; 
    BOOL Output;        
    BOOL Run;           
}   COMP_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
/**
  * @name    COMP_Init
  * @brief   COMP初始化函数
  *          COMP init function
  * @param   *compx [IN] COMP结构体句柄，初始化时请定义该句柄，并用其地址来传参。
  *                      COMP structure handle. When initializing, 
  *                      please define the handle and use its address 
  *                      to pass parameters.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE COMP_Init(const COMP_InitType *compx);


/**
  * @name    NVIC_COMP_Init
  * @brief   COMP中断初始化函数
  *          COMP interrupt initialization function.
  * @param   priority [IN] 优先级。Priority.
  * @param   triMode  [IN] 触发模式。Trigger mode.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE NVIC_COMP_Init(NVICPri_Type priority,COMPTri_Type triMode);


/**
  * @name    COMP_GET_FLAG
  * @brief   获取比较完成（中断）标志位宏函数
  *          Comp gets compare complete (interrupt) 
  *          flag bit macro function.
  * @retval  [bit] 完成（中断）标志位。Completion (interrupt) flag bit.
***/
#define COMP_GET_FLAG()        (CMPCR1 & 0x40)


/**
  * @name    COMP_CLEAR_FLAG
  * @brief   COMP清除比较完成（中断）标志位宏函数
  *          Comp clears compare complete (interrupt) 
  *          flag bit macro function.
***/
#define COMP_CLEAR_FLAG()      {CMPCR1 &= 0xBF;}


/**
  * @name    COMP_GET_RESULT
  * @brief   COMP获取比较结果宏函数
  *          Comp gets the macro function of the comparison result.
  * @retval  [bit] 比较结果。Comparison result.
***/
#define COMP_GET_RESULT()         (CMPCR1 & 0x01)


/**
  * @name    NVIC_COMP_CTRL
  * @brief   COMP中断开关控制宏函数。
  *          COMP interrupt switch control macro function.
  * @param   run [BOOL] 使能控制位。Enable control bit.
***/
#define NVIC_COMP_CTRL(run)    { CMPCR1 = (CMPCR1 & 0xCF)|(run << 4); }


/**
  * @name    GPIO_COMP_SWPort
  * @brief   COMP切换复用IO函数。
  *          COMP switch out port control function.  
  * @param   port [IN] 复用IO枚举体。IO switch enumerator.
  * @retval  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_COMP_SWPort(GPIOSWPort_Type port);


#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

