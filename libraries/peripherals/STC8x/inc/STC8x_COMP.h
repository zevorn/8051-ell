/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8Ax_COMP.h
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote COMP chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8Ax_COMP_H_
#define __STC8Ax_COMP_H_
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

/*--------------------------------------------------------
| @Description: COMP Pin define                          |
--------------------------------------------------------*/

/* PEPin */
#define  COMP_PE_P37     0xF7

#define  COMP_PE_P10     0x00	   
#define  COMP_PE_P11     0x01
#define  COMP_PE_P12     0x02
#define  COMP_PE_P13     0x03
#define  COMP_PE_P14     0x04
#define  COMP_PE_P15     0x05
#define  COMP_PE_P16     0x06
#define  COMP_PE_P17     0x07
	   
#define	 COMP_PE_P00     0x08
#define	 COMP_PE_P01     0x09
#define	 COMP_PE_P02     0x0A
#define	 COMP_PE_P03     0x0B
#define	 COMP_PE_P04     0x0C
#define	 COMP_PE_P05     0x0D
#define	 COMP_PE_P06     0x0E

/* NEPin */
#define  COMP_NE_P36     0x10

/* 
NEPin and PEPin :
Test the internal 1.344v refv voltage.
*/
#define	 COMP_IN_REV     0x0F  

/*--------------------------------------------------------
| @Description: COMP output direction enumerator         |
--------------------------------------------------------*/

typedef enum
{
    COMP_DIR_Forward = 0x00, 
	COMP_DIR_Reverse = 0x01       
}   COMPDIRPut_Type;

/**
  * @name    COMP_InitType
  * @brief   COMP init struct
  * @param   PEPin   COMP positive input selection bit
  * @param   NEPin   COMP negative input selection bit
  * @param   AC_FTW  COMP 0.1us analog filter control bit
  * @param   DC_FTW  COMP digital filter clock number. 0 for off
  * @param   DIRPut  COMP output direction
  * @param   Output  COMP result output control bit
  * @param   Run     COMP operation control bit
***/
typedef struct
{
    uint8_t PEPin;            
    uint8_t NEPin;	          
    FUNSTATE AC_FTW;        
    uint16_t DC_FTW;          
    COMPDIRPut_Type DIRPut; 
    FUNSTATE Output;        
    FUNSTATE Run;           
}   COMP_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

FSCSTATE COMP_Init(const COMP_InitType *compx);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/

