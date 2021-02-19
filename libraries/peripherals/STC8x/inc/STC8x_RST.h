/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_RST.h
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               UPDATE NOTE                             |
-----------------------------------------------------------------------*/
/**
  * Update note:
  * ------------   ---------------   ----------------------------------
  *     Date            Author                       Note
  * ------------   ---------------   ----------------------------------
  *  2020.12.20         zeweni       Wrote RST chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format.
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_RST_H_
#define __STC8x_RST_H_

/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
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
| @Description: Software reset selection enum            |
--------------------------------------------------------*/

typedef enum
{

	RST_USER_DATA_KEEP = 0x00,	/* After the software is reset,
                            the code is executed from the user program area, 
                            and the data in the user data area remains unchanged. */
	RST_USER_DATA_CLEAN 	/* After the software is reset,
                            the code is executed from the ISP area of the system,
                            and the data in the user data area is cleared. */
} RSTChoice_Type;

/*--------------------------------------------------------
| @Description: Low voltage reset Reset working mode enum|
--------------------------------------------------------*/

typedef enum
{
  LVD_RST_2_2V = 0x00,
  LVD_RST_2_4V = 0x01,
  LVD_RST_2_7V = 0x02,
  LVD_RST_3_0V = 0x03
} LVDRstDiv_Type;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: Reset  control functions                 |
--------------------------------------------------------*/

#define    RST_P54_ENABLE()      RSTCFG |= 0x10
#define    RST_P54_DISABLE()     RSTCFG &= 0xEF

/*--------------------------------------------------------
| @Description: Reset  control functions                 |
--------------------------------------------------------*/

FSCSTATE SFW_RST_Ctrl(RSTChoice_Type choice, FUNSTATE run);
FSCSTATE LVD_RST_Init(LVDRstDiv_Type lvDiv,FUNSTATE run);
void Auto_RST_download(void);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/