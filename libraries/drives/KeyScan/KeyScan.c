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
KeyScan_object Key;

/**
  * @brief   Define key handling callback function
***/
static KeyScan_FunCallBack KeyScan_CallBack;

/**
  * @brief   Define key read pin callback function
***/
KeyScan_ReadPin_Func KeyScan_ReadPin;
/**
  * @brief	 Define key to return key value
***/

static struct
{
  Sem_Click ClickMode[KEY_NUM_MAX];  
  Sem_Tri TriMode[KEY_NUM_MAX];
  uint8 ReadValue[KEY_NUM_MAX];
  uint8 KeyNum;
  uint8 Trg[KEY_NUM_MAX];
  uint8 Cont[KEY_NUM_MAX];
}KeyScan;


/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

static void KeyScan_Scan(void);
static void KeyScan_Run(void);
static void KeyScan_Attach(KeyScan_FunCallBack BCallBack);
static void Key_Mode_config(Sem_Click click,Sem_Tri tri);
static void KeyScan_ReadPin_Attach(KeyScan_FunCallBack readPin);

/**
  * @name    KeyScan_Init
  * @brief   Init
  * @param   None
  * @return  None
***/
void KeyScan_Init(void)
{
  Key.ReadPin = KeyScan_ReadPin_Attach;
  Key.Config = Key_Mode_config;
	Key.Attach = KeyScan_Attach;
	Key.Scan = KeyScan_Scan;
	Key.Run = KeyScan_Run;
  KeyScan.KeyNum = 0;
}

/**
  * @name    KeyScan_Init
  * @brief   Init
  * @param   None
  * @return  None
***/
void Key_Mode_config(Sem_Click click,Sem_Tri tri)
{
  KeyScan.ClickMode[KeyScan.KeyNum] = click;
  KeyScan.TriMode[KeyScan.KeyNum] = tri;
  KeyScan.KeyNum = (KeyScan.KeyNum + 1) % KEY_NUM_MAX;
}


/**
  * @name    KeyScan_Attach
  * @brief   KeyScan callback function register function
  * @param   BCallBack : KeyScan_FunCallBack
  * @return  None
***/
static void KeyScan_Attach(KeyScan_FunCallBack BCallBack)
{
	KeyScan_CallBack = BCallBack;
}

/**
  * @name    KeyScan_ReadPin_Attach
  * @brief   KeyScan readPin callbackfunction
  * @param   KeyScan_ReadPin readPin
  * @return  None
***/
void KeyScan_ReadPin_Attach(KeyScan_FunCallBack readPin)
{
  KeyScan_ReadPin = readPin;
}
/**
  * @name    KeyScan_Run
  * @brief   None
  * @param   None
  * @return  None
***/
static void KeyScan_Run(void)
{
  uint8 num;
  for(num=0;num < KeyScan.KeyNum;num++)
  {
    if(KeyScan.ClickMode[num] == Click_Short)
    {
      if(KeyScan.Trg[num])
      {
        KeyScan_CallBack(&KeyScan.ClickMode[num]);
        KeyScan.Trg[num] = 0;
      }
    }
    else if (KeyScan.ClickMode[num] == Click_Long)
    {
      if(KeyScan.Cont[num])
      {
        KeyScan_CallBack(&KeyScan.ClickMode[num]);
        KeyScan.Cont[num] = 0;
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
static void KeyScan_Scan(void)
{
  uint8 num;
  for(num=0;num < KeyScan.KeyNum;num++)
  {
    KeyScan_ReadPin(KeyScan.ReadValue);
    if(KeyScan.TriMode[num] == Tri_Low_level)
    {
        KeyScan.ReadValue[num] = KeyScan.ReadValue[num] ^ 0x01;
    }
    else if (KeyScan.TriMode[num] == Tri_High_level)
    {
        KeyScan.ReadValue[num] = KeyScan.ReadValue[num] ^ 0x00;
    }
    KeyScan.Trg[num]  = (KeyScan.ReadValue[num] ^ KeyScan.Cont[num] ) & KeyScan.ReadValue[num];  
    KeyScan.Cont[num] = KeyScan.ReadValue[num];
   
  }
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  | 
-----------------------------------------------------------------------*/



