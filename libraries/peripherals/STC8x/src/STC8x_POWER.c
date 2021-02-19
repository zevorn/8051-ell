/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_POWER.c
  - Author        : zeweni
  - Update date   : 2020.02.06
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_POWER.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
/* None */
/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    POWER_Mode_Ctrl
  * @brief   Power mode configure function
  * @param   mode   POWER_Mode_Normal | POWER_Mode_Down | POWER_Mode_Idle
  * @return  None
***/
FSCSTATE POWER_Mode_Ctrl(POWERMode_Type mode)
{
  PCON = (PCON & 0xFC) | mode;
  return FSC_SUCCESS;
}

/**
  * @name    Get_POWER_State
  * @brief   Get power state function
  * @param   None
  * @return  POWER state (uint8)
***/
uint8 Get_POWER_State(void)
{
  return (PCON & 0x10);
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/



