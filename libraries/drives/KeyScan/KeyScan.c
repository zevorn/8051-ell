/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : drv_kscan.c
  - Author        : zeweni
  - Update date   : 2020.01.11                  
  -	Copyright(c)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "KeyScan.h"
#include "main.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/**
  * @brief   Define key scan object
***/
KeyScan_Struct KeyScan;

/**
  * @brief   Define key handling callback function
***/
static KeyScan_FunCallBack KeyScan_CallBack;

/**
  * @brief	 Define key to return key value
***/
typedef struct
{
  uint8_t (*ReadPin) (void);
  uint8_t ReadValue;
  uint8_t KeyNum;
  uint8_t Trg;
  uint8_t Cont;
  Sem_Click ClickMode;  
  Sem_Tri TriMode;
} KEY_COMPS;

/**
  * @brief	 Define key to return key value
***/
static struct
{
	KEY_COMPS Comps[KEY_NUM_MAX];
	uint8_t Number_Max;
} KeyScan_Object;

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

static void KeyScan_Scan_t(void);
static void KeyScan_Run_t(void);
static void KeyScan_Attach_t(KeyScan_FunCallBack BCallBack);
static void KeyScan_Add_t(uint8_t (*readPinFunc) (void),Sem_Click click,Sem_Tri tri);

/**
  * @name    KeyScan_Init
  * @brief   Init
  * @param   None
  * @return  None
***/
void KeyScan_Init(void)
{
    KeyScan.Add = KeyScan_Add_t;
	KeyScan.Attach = KeyScan_Attach_t;
	KeyScan.Scan = KeyScan_Scan_t;
	KeyScan.Run = KeyScan_Run_t;
    KeyScan_Object.Number_Max = 0;
}

/**
  * @name    KeyScan_Add_t
  * @brief   click
  * @param   click
  * @param   tri
  * @param   gpio_px
  * @param   gpio_pin
  * @return  None
***/
void KeyScan_Add_t(uint8_t (*readPinFunc) (void),Sem_Click click,Sem_Tri tri)
{
  static uint8_t number = 0;
	
  KeyScan_Object.Comps[number].ReadPin = readPinFunc;
  KeyScan_Object.Comps[number].ClickMode = click;
  KeyScan_Object.Comps[number].TriMode = tri;
  number += 1;
  KeyScan_Object.Number_Max = number;
}


/**
  * @name    KeyScan_Attach
  * @brief   KeyScan callback function register function
  * @param   BCallBack : KeyScan_FunCallBack
  * @return  None
***/
static void KeyScan_Attach_t(KeyScan_FunCallBack BCallBack)
{
	KeyScan_CallBack = BCallBack;
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
		if(KeyScan_Object.Comps[num].ClickMode == Click_Short)
		{
			if(KeyScan_Object.Comps[num].Trg)
			{
				KeyScan_CallBack(&KeyScan_Object.Comps[num].ClickMode);
				KeyScan_Object.Comps[num].Trg = 0;
			}
		}
		else if (KeyScan_Object.Comps[num].ClickMode == Click_Long)
		{
			if(KeyScan_Object.Comps[num].Cont)
			{
				KeyScan_CallBack(&KeyScan_Object.Comps[num].ClickMode);
				KeyScan_Object.Comps[num].Trg = 0;
			}
		}
	}
}

/**
  * @name    KeyScan_Scan
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_Scan_t(void)
{
	uint8_t num;
	for(num=0;num < KeyScan_Object.Number_Max; num++)
	{
		if(KeyScan_Object.Comps[num].TriMode == Tri_Low_level)
		{
			KeyScan_Object.Comps[num].ReadValue = KeyScan_Object.Comps[num].ReadPin() ^ 0x01;
		}
		else if (KeyScan_Object.Comps[num].TriMode == Tri_High_level)
		{
			KeyScan_Object.Comps[num].ReadValue = KeyScan_Object.Comps[num].ReadPin() ^ 0x00;
		}
		
		KeyScan_Object.Comps[num].Trg  = (KeyScan_Object.Comps[num].ReadValue ^ KeyScan_Object.Comps[num].Cont ) 
                                    	  &	KeyScan_Object.Comps[num].ReadValue; 
		
		KeyScan_Object.Comps[num].Cont = KeyScan_Object.Comps[num].ReadValue;
	}
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



