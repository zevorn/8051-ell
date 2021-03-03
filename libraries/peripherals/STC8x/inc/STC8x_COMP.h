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

