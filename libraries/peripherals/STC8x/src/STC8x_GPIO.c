/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_GPIO.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_GPIO.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    GPIO_UART1_SWPort
  * @brief   UART1 switch port control function    
  * @param   port    SW_Port1: RXD/P3.0 TXD/P3.1
  *                  SW_Port2: RXD/P3.6 TXD/P3.7
  *                  SW_Port3: RXD/P1.6 TXD/P1.7
  *                  SW_Port4: RXD/P4.3 TXD/P4.4
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_UART1_SWPort(GPIOSWPort_Type port)
{
	P_SW1 = (P_SW1 & 0x3F) | (port << 6);
	return FSC_SUCCESS;
}

/**
  * @name    GPIO_UART2_SWPort
  * @brief   UART2 switch port control function    
  * @param   port    SW_Port1: RXD/P1.0 TXD/P1.1
  *                  SW_Port2: RXD/P4.1 TXD/P4.2
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_UART2_SWPort(GPIOSWPort_Type port)
{
	if(port < SW_Port3)
	{
		P_SW2 = (P_SW2 & 0xFE) | (port);
		return FSC_SUCCESS;
	}
	else return FSC_FAIL;
}

/**
  * @name    GPIO_UART3_SWPort
  * @brief   UART3 switch port control function    
  * @param   port    SW_Port1: RXD/P0.0 TXD/P0.1
  *                  SW_Port2: RXD/P5.0 TXD/P5.1
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_UART3_SWPort(GPIOSWPort_Type port)
{
	if(port < SW_Port3)
	{
		P_SW2 = (P_SW2 & 0xFD) | (port << 1);
		return FSC_SUCCESS;
	}
	else return FSC_FAIL;
}

/**
  * @name    GPIO_UART4_SWPort
  * @brief   UART4 switch port control function    
  * @param   port    SW_Port1: RXD/P0.2 TXD/P0.3
  *                  SW_Port2: RXD/P5.2 TXD/P5.3
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_UART4_SWPort(GPIOSWPort_Type port)
{
	if(port < SW_Port3)
	{
		P_SW2 = (P_SW2 & 0xFB) | (port << 2);
		return FSC_SUCCESS;
	}
	else return FSC_FAIL;
}

/**
  * @name    GPIO_COMP_SWPort
  * @brief   COMP switch out port control function   
  * @param   port    SW_Port1: P3.4
  *                  SW_Port2: P4.1
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_COMP_SWPort(GPIOSWPort_Type port)
{
	if(port < SW_Port3)
	{
		P_SW2 = (P_SW2 & 0xF7) | (port << 3);
		return FSC_SUCCESS;
	}
	else return FSC_FAIL;
}

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Gx)

#if(PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    GPIO_PCA_SWPort
  * @brief   PCA switch port control function  
  * @param   port    SW_Port1: ECI/P1.2 CCP0/P1.7 CCP1/P1.6 CCP2/P1.5 CCP3/P1.4
  *                  SW_Port2: ECI/P2.2 CCP0/P2.3 CCP1/P2.4 CCP2/P2.5 CCP3/P2.6
  *                  SW_Port3: ECI/P7.4 CCP0/P7.0 CCP1/P7.1 CCP2/P7.2 CCP3/P7.3
  *                  SW_Port4: ECI/P3.5 CCP0/P3.3 CCP1/P3.2 CCP2/P3.1 CCP3/P3.0
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
#elif (PER_LIB_MCU_MUODEL == STC8Gx)
/**
  * @name    GPIO_PCA_SWPort
  * @brief   PCA switch port control function  
  * @param   port    SW_Port1: ECI/P1.2 CCP0/P1.1 CCP1/P1.0 CCP2/P3.7 
  *                  SW_Port2: ECI/P3.4 CCP0/P3.5 CCP1/P3.6 CCP2/P3.7 
  *                  SW_Port3: ECI/P2.4 CCP0/P2.5 CCP1/P2.6 CCP2/P2.7 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
#endif
FSCSTATE GPIO_PCA_SWPort(GPIOSWPort_Type port)
{
    #if (PER_LIB_MCU_MUODEL == STC8Gx)
    if(port > SW_Port3) return FSC_FAIL;
    #endif
	P_SW1 = (P_SW1 & 0xCF) | (port << 4);
	return FSC_SUCCESS;
}
#endif

#if (PER_LIB_MCU_MUODEL == STC8Ax)
/**
  * @name    GPIO_PWM0_SWPort
  * @brief   PWM0 switch port control function 
  * @param   port    SW_Port1: P2.0
  *                  SW_Port2: P1.0
  *                  SW_Port3: P6.0
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
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
***/
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
***/
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
***/
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
***/
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
***/
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
***/
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
***/
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
/**
  * @name    GPIO_SPI_SWPort
  * @brief   SPI switch port control function 
  * @param   port    SW_Port1: SS/P1.2 MOSI/P1.3 MISO/P1.4 SCLK/P1.5
  *                  SW_Port2: SS/P2.2 MOSI/P2.3 MISO/P2.4 SCLK/P2.5
  *                  SW_Port3: SS/P7.4 MOSI/P7.5 MISO/P7.6 SCLK/P7.7
  *                  SW_Port4: SS/P3.5 MOSI/P3.4 MISO/P3.3 SCLK/P3.2
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_SPI_SWPort(GPIOSWPort_Type port)
{
	P_SW1 = (P_SW1 & 0xF3) | (port << 2);
	return FSC_FAIL;
}

/**
  * @name    GPIO_I2C_SWPort
  * @brief   I2C switch port control function   
  * @param   port    SW_Port1: SCL/P1.5 SDA/P1.4 
  *                  SW_Port2: SCL/P2.5 SDA/P2.4 
  *                  SW_Port3: SCL/P7.7 SDA/P7.6 
  *                  SW_Port4: SCL/P3.2 SDA/P3.3 
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/
FSCSTATE GPIO_I2C_SWPort(GPIOSWPort_Type port)
{
	P_SW2 = (P_SW2 & 0xC0) | (port << 4);
	return FSC_FAIL;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



