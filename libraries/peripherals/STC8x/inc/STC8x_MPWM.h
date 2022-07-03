/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_MPWM.h
  - Author        : slipperstree
  - Update date   : 2020.07.25
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*------------------------------------------------------------------------
|                            COPYRIGHT NOTICE                            |
------------------------------------------------------------------------*/
/*
 * Copyright (C) 2021, zeweni (slipperstree@gmail.com)

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
#ifndef __STC8x_MPWM_H_
#define __STC8x_MPWM_H_

/*--------------------------------------------------------
| @Description: STC8x core                               |
--------------------------------------------------------*/
#include "ELL_CORE.h"

/*--------------------------------------------------------
| @Description: STC8x MCU Register                       |
--------------------------------------------------------*/

#if  (PER_LIB_MCU_MUODEL == STC8Gx)

    #include "STC8Gx_REG.h"
	
#endif

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

#ifndef PER_LIB_MCU_MUODEL 
    /** 如果没有定义这个宏，默认为STC8Ax。
        If the mirco is undefined，select to STC8Ax */  
    #define PER_LIB_MCU_MUODEL STC8Gx
#endif


#ifndef PER_LIB_MPWM_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_CTRL 1
#endif


#ifndef PER_LIB_MPWM_INIT_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_INIT_CTRL 1
#endif


#ifndef PER_LIB_MPWM_NVIC_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_NVIC_CTRL 1
#endif


#ifndef PER_LIB_MPWM_WORK_CTRL
    /** 如果没有定义这个宏，默认为0。
        If the mirco is undefined，select to "0" */
    #define PER_LIB_MPWM_WORK_CTRL 1
#endif


#if (PER_LIB_MCU_MUODEL == STC8Gx)

    /*--------------------------------------------------------
    | @Description: MPWM Register Macro                      |
    --------------------------------------------------------*/

    /*** 全体设置（PORT无关/CHANNEL无关） ************************************************/

    /* ENGLBSET:全局设置功能控制。 
        0:6 组 PWM 采用各自独立设置方式。
        每组 PWM 分别使用 PWMCFG01/PWMCFG23/PWMCFG45 相应的控制位就绪独立配置。
        1:6 组 PWM 采用统一设置方式。
        每组 PWM 均采用 PWMCFG01 中的 PWM0 的设置进行配置。
    */
    #define clrBitENGLBSET()    PWMSET&=(~ENGLBSET)
    #define setBitENGLBSET()    PWMSET|=( ENGLBSET)

    /* PWMRST:软件复位 6 组 PWM。
        0:无效
        1:复位所有 PWM 的 XFR 寄存器，但不复位 SFR。(需要软件清零)
    */
    #define clrBitPWMRST()      PWMSET&=(~PWMRST)
    #define setBitPWMRST()      PWMSET|=( PWMRST)

    /*** PORT单位设置（CHANNEL无关）*******************************************************/
    /* ENPWMn PWMn 使能位 (n=0~5) */
    #define PWM_ENABLE(PORT)     PWMSET|=(1<<PORT)
    #define PWM_DISABLE(PORT)    PWMSET&=(~(1<<PORT))


    /* PWMn 计数器归零中断标志位。(n=0~5)  
    当 15 位的 PWMn 计数器记满溢出归零时，硬件自动将此位置 1，
    并向 CPU 提出中断请求，此标志位需要软件清零。
    */
    #define clrBitPWMnCBIF(PORT)  {if(PORT==0){PWMCFG01&=(~PWMCBIF024);} \
                            else if(PORT==1){PWMCFG01&=(~PWMCBIF135);} \
                            else if(PORT==2){PWMCFG23&=(~PWMCBIF024);} \
                            else if(PORT==3){PWMCFG23&=(~PWMCBIF135);} \
                            else if(PORT==4){PWMCFG45&=(~PWMCBIF024);} \
                            else if(PORT==5){PWMCFG45&=(~PWMCBIF135);}}

    /* PWMn 计数器归零中断使能位。(n=0~5) */
    /* PWMn 计数器归零中断使能位。0:关闭 PWMn 计数器归零中断(PWMnCBIF 依然会被硬件置位) (n=0~5) */
    #define clrBitEPWMnCBI(PORT)  {if(PORT==0){PWMCFG01&=(~EPWMCBI024);} \
                            else if(PORT==1){PWMCFG01&=(~EPWMCBI135);} \
                            else if(PORT==2){PWMCFG23&=(~EPWMCBI024);} \
                            else if(PORT==3){PWMCFG23&=(~EPWMCBI135);} \
                            else if(PORT==4){PWMCFG45&=(~EPWMCBI024);} \
                            else if(PORT==5){PWMCFG45&=(~EPWMCBI135);}}
    /* PWMn 计数器归零中断使能位。1:使能 PWMn 计数器归零中断 (n=0~5) */
    #define setBitEPWMnCBI(PORT)  {if(PORT==0){PWMCFG01|=( EPWMCBI024);} \
                            else if(PORT==1){PWMCFG01|=( EPWMCBI135);} \
                            else if(PORT==2){PWMCFG23|=( EPWMCBI024);} \
                            else if(PORT==3){PWMCFG23|=( EPWMCBI135);} \
                            else if(PORT==4){PWMCFG45|=( EPWMCBI024);} \
                            else if(PORT==5){PWMCFG45|=( EPWMCBI135);}}

    /* PWMn 波形发生器是否开始计数。(n=0~5) */
    /* PWMn 波形发生器停止计数。(n=0~5) */
    #define clrBitPWMnCEN(PORT)   {if(PORT==0){PWMCFG01&=(~PWMCEN024);} \
                            else if(PORT==1){PWMCFG01&=(~PWMCEN135);} \
                            else if(PORT==2){PWMCFG23&=(~PWMCEN024);} \
                            else if(PORT==3){PWMCFG23&=(~PWMCEN135);} \
                            else if(PORT==4){PWMCFG45&=(~PWMCEN024);} \
                            else if(PORT==5){PWMCFG45&=(~PWMCEN135);}}
    /* PWMn 波形发生器开始计数。(n=0~5) */
    #define setBitPWMnCEN(PORT)   {if(PORT==0){PWMCFG01|=( PWMCEN024);} \
                            else if(PORT==1){PWMCFG01|=( PWMCEN135);} \
                            else if(PORT==2){PWMCFG23|=( PWMCEN024);} \
                            else if(PORT==3){PWMCFG23|=( PWMCEN135);} \
                            else if(PORT==4){PWMCFG45|=( PWMCEN024);} \
                            else if(PORT==5){PWMCFG45|=( PWMCEN135);}}

    /* ENPWMnTA:PWMn 是否与 ADC 关联。(n=0、2、4) */
    /* ENPWMnTA:0:PWMn 与 ADC 不关联。 (n=0、2、4) */
    #define clrBitENPWMnTA(PORT)  {if(PORT==0){PWMCFG01&=(~ENPWMTA024);} \
                            else if(PORT==2){PWMCFG23&=(~ENPWMTA024);} \
                            else if(PORT==4){PWMCFG45&=(~ENPWMTA024);}}
    /* ENPWMnTA:1:PWMn 与 ADC 相关联。(n=0、2、4) */
    #define setBitENPWMnTA(PORT)  {if(PORT==0){PWMCFG01|=( ENPWMTA024);} \
                            else if(PORT==2){PWMCFG23|=( ENPWMTA024);} \
                            else if(PORT==4){PWMCFG45|=( ENPWMTA024);}}

    /* PWM 异常检测控制寄存器(PWMnFDCR) */
    #define setRegPWMnFDCR(PORT, VALUE)              ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x06))) = VALUE

    /* PWM 计数器寄存器(PWMnCH，PWMnCL) (n=0~5)
        可设定 1~32767 之间的任意值作为 PWMn 的周期。PWMn 波形发
        生器内部的计数器从 0 开始计数，每个 PWMn 时钟周期递增 1，
        当内部计数器的计数值达到 [PWMnCH，PWMnCL]所设定的 PWMn 周期时，
        PWMn 波形发生器内部的计数器将会从 0 重新开始计数，
        硬件会自动将 PWMn 归零中断中断标志位 PWMnCBIF 置 1，
        若 EPWMnCBI=1，程序将跳转到相应中断入口执行中断服务程序。
    */
    #define setRegPWMnC(PORT, VALUE)                 ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x00))) = VALUE

    /* PWM 时钟选择寄存器(PWMnCKS) (n=0~5) */
    #define setRegPWMnCKS(PORT, VALUE)               ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x02))) = VALUE

    /* PWM 触发 ADC 计数器寄存器(PWMnTADC) (n=0、2、4) */
    #define setRegPWMnTADC(PORT, VALUE)              ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x03))) = VALUE

    /*** CHANNEL单位设置 **************************************************************/
    /* PWM 电平输出设置计数值寄存器 第一个点(PWMnT2) (n=0~5;i=0~7) */
    #define setRegPWMniT1(PORT, CHANNEL, VALUE)      ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 0))) = VALUE
    #define setRegPWMniT1H(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 0))) = VALUE
    #define setRegPWMniT1L(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 1))) = VALUE
    /* PWM 电平输出设置计数值寄存器 第二个点(PWMnT2) (n=0~5;i=0~7) */
    #define setRegPWMniT2(PORT, CHANNEL, VALUE)      ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 2))) = VALUE
    #define setRegPWMniT2H(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 2))) = VALUE
    #define setRegPWMniT2L(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 3))) = VALUE

    /* PWM 通道控制寄存器(PWMnCR) (n=0~5;i=0~7) */
    #define setRegPWMniCR(PORT, CHANNEL, VALUE)      ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) = VALUE

    /* PWMnCR.ENO:PWMni 输出使能位。
        1:第 n 路 PWM 的 i 通道相应 PWMni 端口为 PWM 输出口，受 PWMn 波形发生器控制 */
    #define setBitPWMniEnableOut(PORT, CHANNEL)       ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENO)
    /* PWMnCR.ENO:PWMni 输出使能位。
        0:第 n 路 PWM 的 i 通道相应 PWMni 端口为 GPIO */
    #define clrBitPWMniEnableOut(PORT, CHANNEL)       ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENO)
    /* PWMnCR.INI:设置 PWMni 输出端口的初始电平。(n=0~5，i=0~7)
        1:第 n 路 PWM 的 i 通道初始电平为高电平
    */
    #define setBitPWMniStartLevel(PORT, CHANNEL)      ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( INI)
    /* PWMnCR.INI:设置 PWMni 输出端口的初始电平。(n=0~5，i=0~7) 
        0:第 n 路 PWM 的 i 通道初始电平为低电平 */
    #define clrBitPWMniStartLevel(PORT, CHANNEL)      ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~INI)
    /* PWMnCR.ENI:第 n 路 PWM 的 i 通道中断使能控制位。(n=0~5，i=0~7)
        1:使能第 n 路 PWM 的 i 通道的 PWM 中断
    */
    #define setBitPWMniEnableIntrupt(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENI)
    /* PWMnCR.ENI:第 n 路 PWM 的 i 通道中断使能控制位。(n=0~5，i=0~7)
        0:关闭第 n 路 PWM 的 i 通道的 PWM 中断
    */
    #define clrBitPWMniEnableIntrupt(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENI)
    /* PWMnCR.ENT2I:第 n 路 PWM 的 i 通道在第 2 个触发点中断使能控制位。(n=0~5，i=0~7)
        1:使能第 n 路 PWM 的 i 通道在第 2 个触发点中断
    */
    #define setBitPWMniEnableIntruptAtTrig2(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENT2I)
    /* PWMnCR.ENT2I:第 n 路 PWM 的 i 通道在第 2 个触发点中断使能控制位。(n=0~5，i=0~7)
        0:关闭第 n 路 PWM 的 i 通道在第 2 个触发点中断
    */
    #define clrBitPWMniEnableIntruptAtTrig2(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENT2I)
    /* PWMnCR.ENT1I:第 n 路 PWM 的 i 通道在第 1 个触发点中断使能控制位。(n=0~5，i=0~7)
        1:使能第 n 路 PWM 的 i 通道在第 1 个触发点中断
    */
    #define setBitPWMniEnableIntruptAtTrig1(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) |=( ENT1I)
    /* PWMnCR.ENT1I:第 n 路 PWM 的 i 通道在第 1 个触发点中断使能控制位。(n=0~5，i=0~7)
        0:关闭第 n 路 PWM 的 i 通道在第 1 个触发点中断
    */
    #define clrBitPWMniEnableIntruptAtTrig1(PORT, CHANNEL)   ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x14) + 0))) &=(~ENT1I)

    /* PWM通道电平保持控制寄存器(PWMnHLD) (n=0~5，i=0~7) */
    #define setRegPWMniHLD(PORT, CHANNEL, VALUE)     ( *(__IO  uint8_t xdata *) ((0xFF-(PORT/3*3))<<8 | ((CHANNEL*0x08+PORT%3*0x50+0x10) + 5))) = VALUE

    /* PWM 中断标志寄存器(PWMnIF) PWMn 的第 i 通道中断标志位。(n=0~5;i=0~7) */
    #define clrBitPWMniIF(PORT, CHANNEL)             ( *(__IO uint16_t xdata *) ((0xFF-(PORT/3*3))<<8 | (PORT%3*0x50+0x05))) &= (~(1<<CHANNEL))

    /*--------------------------------------------------------
    | @Description: PWM clock source enum                    |
    --------------------------------------------------------*/

    /**
     * @brief     MPWM系统时钟选择枚举体。
     * @details   PWM clock source Enumerator.
     **/
    typedef enum
    {
        MPWM_SCLK_DIV_1  =  0x00,
        MPWM_SCLK_DIV_2  =  0x01,
        MPWM_SCLK_DIV_3  =  0x02,
        MPWM_SCLK_DIV_4  =  0x03,
        MPWM_SCLK_DIV_5  =  0x04,
        MPWM_SCLK_DIV_6  =  0x05,
        MPWM_SCLK_DIV_7  =  0x06,
        MPWM_SCLK_DIV_8  =  0x07,
        MPWM_SCLK_DIV_9  =  0x08,
        MPWM_SCLK_DIV_10 =  0x09,
        MPWM_SCLK_DIV_11 =  0x0A,
        MPWM_SCLK_DIV_12 =  0x0B,
        MPWM_SCLK_DIV_13 =  0x0C,
        MPWM_SCLK_DIV_14 =  0x0D,
        MPWM_SCLK_DIV_15 =  0x0E,
        MPWM_SCLK_DIV_16 =  0x0F,
        MPWM_TIMER2_PULSE = 0x1F
    }   MPWMCLKSrc_Type;

    /*--------------------------------------------------------
    | @Description: PWM road start level configure enum      |
    --------------------------------------------------------*/

    typedef enum
    {
        MPWM_Start_Low_Level  =  0x00,
        MPWM_Start_High_Level =  0x01  
    }   MPWMStartLevel_Type;

    /*--------------------------------------------------------
    | @Description: PWM port enum                            |
    --------------------------------------------------------*/
    typedef enum
	{
		MPWM_Port_0 = 0x00 , 
		MPWM_Port_1 = 0x01 ,
		MPWM_Port_2 = 0x02 ,
		MPWM_Port_3 = 0x03 ,
		MPWM_Port_4 = 0x04 ,
		MPWM_Port_5 = 0x05
	}   MPWMPort_Type;

    /*--------------------------------------------------------
    | @Description: PWM channel enum                         |
    --------------------------------------------------------*/

    typedef enum
    {
        MPWM_Channel_0 = 0x00 , 
        MPWM_Channel_1 = 0x01 ,
        MPWM_Channel_2 = 0x02 ,
        MPWM_Channel_3 = 0x03 ,
        MPWM_Channel_4 = 0x04 ,
        MPWM_Channel_5 = 0x05 ,
        MPWM_Channel_6 = 0x06 ,
        MPWM_Channel_7 = 0x07
    }   MPWMChannel_Type;


    /*-----------------------------------------------------------------------
    |                             API FUNCTION                              |
    -----------------------------------------------------------------------*/

    /**
     * @brief     PWM端口初始化函数。Init PWM port function.
     * @details   初始化指定端口(0-5)。Init the specified PWM port. (from 0 to 5)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @param[in] clkSrc PWM时钟源。PWM clock source.
     * @param[in] period PWM周期值（计数器重装载值）。PWM period value (counter reload value)
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Port_Init(MPWMPort_Type port, MPWMCLKSrc_Type clkSrc, uint16_t period);

    /**
     * @brief     PWM通道初始化函数。Init PWM channel function.
     * @details   初始化指定端口(0-5)的指定通道(0-7)。Init the specified port's channel (port from 0 to 5, channel from 0 to 7)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @param[in] ch   PWM通道枚举体。PWM channel enumerator.
     * @param[in] level    PWM开始电平。PWM start level.
     * @param[in] fValue   第一个电平翻转点。The value of the first reversal point.
     * @param[in] sValue   第二个电平翻转点。The value of the second reversal point.
     * @param[in] run     运行控制位。Run control bit.
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Channel_Init(MPWMPort_Type port, MPWMChannel_Type ch, MPWMStartLevel_Type level, uint16_t fValue, uint16_t sValue, BOOL run);

    /**
     * @brief     指定PWM端口开始工作。Run specified PWM port.
     * @details   指定PWM端口开始工作，输出PWM波形。Run specified PWM port. (Start PWM signal outputs)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Run(MPWMPort_Type port);

    /**
     * @brief     指定PWM端口停止工作。Stop specified PWM port working.
     * @details   指定PWM端口停止工作，停止输出PWM波形。Stop specified PWM port. (Stop PWM signal outputs)
     * @param[in] port PWM端口枚举体。PWM port enumerator.
     * @return    FSC_SUCCESS 返回成功。Return to success.
     * @return    FSC_FAIL    返回失败。Return to fail.
    **/
    FSCSTATE MPWMn_Stop(MPWMPort_Type port);

#endif

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/
#endif
