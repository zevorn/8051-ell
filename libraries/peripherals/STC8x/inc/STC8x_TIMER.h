/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_TIMER.h
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
  *  2020.12.20         zeweni       Wrote TIMER chip internal peripheral 
  *                                  related driver, support stc8a series 
  *                                  model.
  *  2020.01.11         zeweni       Update code comment format. 
  *  2020.01.29         zeweni       Optimize library architecture.
  *  2020.02.06         zeweni       Update code style.
  *
***/

#ifndef __STC8x_TIMER_H_
#define __STC8x_TIMER_H_
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
| @Description: TIMER number                             |
--------------------------------------------------------*/
/*
TIMER0: 16 Bit timer has four working modes
TIMER1: Same as timer 0, but invalid in 16 bit auto reload 
        mode without maskable interrupt, stop counting
TIMER2: The working mode is fixed in 16 bit auto reload mode
TIMER3: The working mode is fixed in 16 bit auto reload mode
TIMER4: The working mode is fixed in 16 bit auto reload mode
*/
/*--------------------------------------------------------
| @Description: TIMER type                               |
--------------------------------------------------------*/
typedef enum
{
    TIMER_Type_Timer   = 0x00, 
    TIMER_Type_Counter = 0x01
}   TIMERType_Type;

/*--------------------------------------------------------
| @Description: TIMER mode enum                          |
--------------------------------------------------------*/
/*
Mode 0: 16 Bit auto reload timer
Mode 1: 16 Bit non auto reload timer
Mode 2:  8 Bit auto reload timer
Mode 3: 16 Bit auto reload non maskable interrupt
*/
typedef enum
{
	TIMER_16BitAutoReload       = 0x00, 
	TIMER_16Bit                 = 0x01, 
	TIMER_8BitAutoReload        = 0x02,  
	TIMER_16BitAutoReloadNoMask = 0x03 
}	TIMERMode_Type;

/*--------------------------------------------------------
| @Description: TIME Clock mode enum                     |
--------------------------------------------------------*/
/*
Timing 12t mode: The machine executes 12 cycles
Timing  1t mode: The machine executes 1 cycles
*/
typedef enum
{
	TIMER_TCY_1T  = 0x00,	
	TIMER_TCY_12T = 0x01
}	TIMERTCycle_Type;

/**
  * @name    TIMER_InitType
  * @brief   TIME Init structure
  * @param   SysClokDiv  system clock division to timer use
  * @param   Type        timer type
  * @param   Mode        Working mode
  * @param   TCycle      Instruction cycle
  * @param   ClkOut      Programmable clock output
  * @param   Value       Loading initial value
  * @param   Run         Operation control bit
***/
typedef struct 
{
#if  (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Gx)
    uint8_t SysClkDiv;   /* just STC8G、STC8H */
#endif
    TIMERType_Type Type;       
    TIMERMode_Type Mode;
    TIMERTCycle_Type TCycle;   
    FUNSTATE ClkOut;           
    uint16_t Value;              
    FUNSTATE Run;              
}   TIMER_InitType;

/*-----------------------------------------------------------------------
|                             API FUNCTION                              |
-----------------------------------------------------------------------*/

/*--------------------------------------------------------
| @Description: TIMER5 peripheral Drivice function       |
--------------------------------------------------------*/

FSCSTATE TIMER5_Wake_Up_Power(uint16 value,FUNSTATE run);

/*--------------------------------------------------------
| @Description: TIMER peripheral init function           |
--------------------------------------------------------*/

FSCSTATE TIMER0_Init(const TIMER_InitType *timerx);
FSCSTATE TIMER1_Init(const TIMER_InitType *timerx);
FSCSTATE TIMER2_Init(const TIMER_InitType *timerx);
FSCSTATE TIMER3_Init(const TIMER_InitType *timerx);
FSCSTATE TIMER4_Init(const TIMER_InitType *timerx);

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

