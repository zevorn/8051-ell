/*----------------------------------------------------------------------
  - File name      : com_pre_delay.h
  - Author         : Quark Team
  - Update date    : 2020-12-29                  
  -	Copyright      : Gevico Electronic studio   
  - Module comments: Printf redirection component.
-----------------------------------------------------------------------*/
#ifndef __COM_Pre_DELAY_H_
#define __COM_Pre_DELAY_H_
/*
 * Update note:
 * ------------   ---------------   ------------------------------------
 *     Date            Author                         Note
 * ------------   ---------------   ------------------------------------
 *  2020.12.20         zeweni       Wrote DELAY chip internal peripheral 
 *                                  related driver, support stc8a series 
 *                                  model.
 * 
 */

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
| @Description: STC8x MCU core                           |
--------------------------------------------------------*/
#include "STC8x_Core.h"

/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: delay function define                    |
--------------------------------------------------------*/
/*
 * note: If you want to get a precise delay, 
 * fine tune this macro parameter.
 */
#define DELAY_COUNT COM_LIB_PREDELAY_BASE



/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/
#if (COM_LIB_PREDELAY_CTRL == 1)
/*--------------------------------------------------------
| @Description: delay function define                    |
--------------------------------------------------------*/

	#define delay_init    Pre_Delay_init
	#define delay_ms      Pre_Delay_ms
	#define DELAY_POS     Pre_Delay_Pos
	
	FSCSTATE Pre_Delay_init(void);
	FSCSTATE Pre_Delay_Pos(void); 
	void Pre_Delay_ms(uint16 nms);
	
#endif
#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

