/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : drv_kscan.c
  - Author        : zeweni
  - Update date   : 2020.01.11                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
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
#include "KeyScan.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/
#if (DRV_LIB_KEYSCAN_CTRL == 1)
/**
  * @brief   Define key scan object
***/
KeyScan_Object_Type KeyScan;

/**
  * @brief	 Define key to return key value
***/
typedef struct
{
	KeyHandle_Func keyHandle;
	uint8_t GPIO;
	uint8_t Pin;
	uint8_t Flag;
	uint8_t ReadValue;
	uint8_t Trg;
	uint8_t Cont;
	Sem_Effect EffMode;	
	Sem_Tri    TriMode;
} KEY_COMPS;

/**
  * @brief	 Define key to return key value
***/
struct
{
    /*pritive*/
	KEY_COMPS Comps[KEY_NUM_MAX];
	uint8_t Number_Max;

    /*pubilc*/
    KeyScan_Object_Type KeyScan;
} KeyScan_Object;

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

static void KeyScan_ReadPin_P0_t(void);
static void KeyScan_ReadPin_P1_t(void);
static void KeyScan_ReadPin_P2_t(void);
static void KeyScan_ReadPin_P3_t(void);
static void KeyScan_ReadPin_P4_t(void);
static void KeyScan_ReadPin_P5_t(void);

#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Hx )

static void KeyScan_ReadPin_P6_t(void);
static void KeyScan_ReadPin_P7_t(void);

#endif

static void KeyScan_Run_t(void);

/**
  * @name    KeyScan_Init
  * @brief   KeyScan init function.
  * @param   *keyScan KeyScan_Type
  * @return  FSCSTATE SUCCESS(1) / FAIL(0)
***/
FSCSTATE KeyScan_Init(KeyScan_Type *keyScan)
{
	static uint8_t number = 0;
    
    KeyScan_Object.KeyScan = keyScan;

	if(number>= 0 && number < KEY_NUM_MAX)
	{
		KeyScan_Object.Comps[number].GPIO = KeyScan_Object.KeyScan -> GPIO;
		KeyScan_Object.Comps[number].Pin = KeyScan_Object.KeyScan -> Pin;
		KeyScan_Object.Comps[number].keyHandle = KeyScan_Object.KeyScan -> HandleFunc;
		KeyScan_Object.Comps[number].TriMode = KeyScan_Object.KeyScan -> TriMode;
		KeyScan_Object.Comps[number].EffMode = KeyScan_Object.KeyScan -> EffMode;
		
		KeyScan_Object.KeyScan.ReadPin_P0 = KeyScan_ReadPin_P0_t;
		KeyScan_Object.KeyScan.ReadPin_P1 = KeyScan_ReadPin_P1_t;
		KeyScan_Object.KeyScan.ReadPin_P2 = KeyScan_ReadPin_P2_t;
		KeyScan_Object.KeyScan.ReadPin_P3 = KeyScan_ReadPin_P3_t;
		KeyScan_Object.KeyScan.ReadPin_P4 = KeyScan_ReadPin_P4_t;
		KeyScan_Object.KeyScan.ReadPin_P5 = KeyScan_ReadPin_P5_t;
		
		#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Hx )
				KeyScan_Object.KeyScan.ReadPin_P6 = KeyScan_ReadPin_P6_t;
				KeyScan_Object.KeyScan.ReadPin_P7 = KeyScan_ReadPin_P7_t;
		#endif
		
		KeyScan.Run = KeyScan_Run_t;
		number += 1;
		KeyScan_Object.Number_Max = number;	
		
		return FSC_SUCCESS;
	}
	else 
	{
		return FSC_FAIL;
	}

}	


/**
  * @name    KeyScan_Run
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_Run_t(void)
{
	uint8_t num;
	for(num=0;num < KeyScan_Object.Number_Max;num++)
	{	
		if(KeyScan_Object.Comps[num].Flag == 1)
		{
			KeyScan_Object.Comps[num].Trg = 0;
			KeyScan_Object.Comps[num].Flag = 0;
			KeyScan_Object.Comps[num].keyHandle();
		}
	}
}

/**
  * @name    KeyScan_ReadPin_P0_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P0_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P0)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P0 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
/**
  * @name    KeyScan_ReadPin_P1_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P1_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P1)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P1 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
/**
  * @name    KeyScan_ReadPin_P2_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P2_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P2)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P2 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
/**
  * @name    KeyScan_ReadPin_P3_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P3_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P3)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P3 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
/**
  * @name    KeyScan_ReadPin_P4_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P4_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P4)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P4 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
/**
  * @name    KeyScan_ReadPin_P5_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P5_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P5)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P5 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
#if (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Hx )
/**
  * @name    KeyScan_ReadPin_P6_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P6_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P6)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P6 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}
/**
  * @name    KeyScan_ReadPin_P7_t
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_ReadPin_P7_t(void)
{
	uint8_t num;

	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].GPIO == GPIO_P7)
		{
			
			KeyScan_Object.Comps[num].ReadValue = P7 ^ (0xFF * ( KeyScan_Object.Comps[num].TriMode 
			                                                 | KeyScan_Object.Comps[num].EffMode));

			KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont) 
											  &	KeyScan_Object.Comps[num].ReadValue; 
			
			KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
			
		    if(KeyScan_Object.Comps[num].Pin == KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_Object.Comps[num].Flag = 1;
			}
		}
	}

}

#endif

#endif
/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



