/*-----------------------------------------------------------------------
|                            FILE DESCRIPTION                           |
-----------------------------------------------------------------------*/
/*----------------------------------------------------------------------
  - File name     : STC8x_SYSCLK.c
  - Author        : zeweni
  - Update date   : 2020.01.29
  -	Copyright(C)  : 2020-2021 zeweni. All rights reserved.
-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
|                               INCLUDES                                |
-----------------------------------------------------------------------*/
#include "STC8x_SYSCLK.h"
/*-----------------------------------------------------------------------
|                                 DATA                                  |
-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
|                               FUNCTION                                |
-----------------------------------------------------------------------*/

/**
  * @name    SYSCLK_Init
  * @brief   System clock init function
  * @param   *sysClkn : SYSCLK_InitType
  * @return  FSC_SUCCESS(1) / FSC_FAIL(0) 
***/

FSCSTATE SYSCLK_Init(const SYSCLK_InitType *sysClkn)
{
		EAXFR_ENABLE(); /* Enable access to the internal extended RAM area */
#if    (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Fx)

		    if(sysClkn -> MCLKSrc != AUTO)
		    {
				SYSCLK.IRC24MCR_REG &= 0xFE; /* Since power on defaults to internal HIRC,
				                              the control bit (the highest bit) cannot be cleared*/
			    SYSCLK.IRC32KCR_REG &= 0x7E;
			    SYSCLK.XOSCCR_REG &= 0x1E;

		        switch(sysClkn -> MCLKSrc) /* Select master clock source */
		        {
			    	case HIRC: SYSCLK.CKSEL_REG = 0x00; SYSCLK.IRC24MCR_REG |= 0x80; break;
                    case XOSC: SYSCLK.CKSEL_REG = 0x01; SYSCLK.XOSCCR_REG |= 0xC0;   break;
			    	case LIRC: SYSCLK.CKSEL_REG = 0x03; SYSCLK.IRC32KCR_REG |= 0x80; break;
		        }
			
			    /* Wait for the clock source switch to complete */
			    	while(!( (SYSCLK.IRC24MCR_REG & 0x01)   || 
							 (SYSCLK.IRC32KCR_REG & 0x01)   || 
							 (SYSCLK.XOSCCR_REG   & 0x01)  ));
			
			    IRTRIM = sysClkn -> IRCTRIM;
                LIRTRIM = sysClkn -> LIRCTRIM;
			    
			    if(sysClkn -> MCLKDiv == 0) sysClkn -> MCLKDiv += 1;
			    SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv;  /* Master clock frequency division */
			
	        }
		
		    SYSCLK.CKSEL_REG |= sysClkn -> SCLKDiv;   /* System clock frequency division */
		    SYSCLK.CKSEL_REG |= sysClkn -> SCLKOutPin << 3;
#elif ( PER_LIB_MCU_MUODEL == STC8Gx ) 		
		
		    if(sysClkn -> MCLKSrc != AUTO)
		    {
				SYSCLK.HIRCCR_REG &= 0xFE; /* Since power on defaults to internal HIRC,
				                              the control bit (the highest bit) cannot be cleared */
			    SYSCLK.IRC32KCR_REG &= 0x7E;
			    SYSCLK.XOSCCR_REG &= 0x1E;

		        switch(sysClkn -> MCLKSrc) /* Select master clock source */
		        {
			    	case HIRC:   SYSCLK.CKSEL_REG = 0x00; SYSCLK.HIRCCR_REG |= 0x80;   break;
                    case XOSC:   SYSCLK.CKSEL_REG = 0x01; SYSCLK.XOSCCR_REG |= 0xC0;   break;
			    	case LIRC:   SYSCLK.CKSEL_REG = 0x03; SYSCLK.IRC32KCR_REG |= 0x80; break;
		        }
			
			    /* Wait for the clock source switch to complete */
			    	while(!( (SYSCLK.HIRCCR_REG & 0x01)   || 
							 (SYSCLK.IRC32KCR_REG & 0x01) || 
							 (SYSCLK.XOSCCR_REG   & 0x01)));

				IRCBAND =  sysClkn -> IRCBand; /* Internal IRC adjust frequency band */
			    IRTRIM = sysClkn -> IRCTRIM;  /* Internal IRC adjust frequency IRTRIM  */
                LIRTRIM = sysClkn -> LIRCTRIM; /* Internal IRC adjust frequency LIRTRIM */
			    
			    if(sysClkn -> MCLKDiv == 0) SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv + 1;  /* Master clock frequency division */
				else SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv;
	        }
		
		    SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKDiv;   /* System clock frequency division */
		    SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKOutPin << 7;

#elif ( PER_LIB_MCU_MUODEL == STC8Hx ) 		
		
		    if(sysClkn -> MCLKSrc != AUTO)
		    {
				SYSCLK.HIRCCR_REG &= 0xFE; /* Since power on defaults to internal HIRC,
				                              the control bit (the highest bit) cannot be cleared*/
			    SYSCLK.IRC32KCR_REG &= 0x7E;
			    SYSCLK.XOSCCR_REG &= 0x1E;
			    SYSCLK.X32KCR_REG &= 0x3E;
		        switch(sysClkn -> MCLKSrc) /* Select master clock source */
		        {
			    	case HIRC:   SYSCLK.CKSEL_REG = 0x00; SYSCLK.HIRCCR_REG |= 0x80;   break;
                    case XOSC:   SYSCLK.CKSEL_REG = 0x01; SYSCLK.XOSCCR_REG |= 0xC0;   break;
					case X32KSC: SYSCLK.CKSEL_REG = 0x02; SYSCLK.X32KCR_REG |= 0xC0;   break;
			    	case LIRC:   SYSCLK.CKSEL_REG = 0x03; SYSCLK.IRC32KCR_REG |= 0x80; break;
		        }
			
			    /* Wait for the clock source switch to complete */
			    	while(!( (SYSCLK.HIRCCR_REG & 0x01)   || 
							 (SYSCLK.IRC32KCR_REG & 0x01) || 
							 (SYSCLK.XOSCCR_REG   & 0x01) ||
							 (SYSCLK.X32KCR_REG   * 0X01)));
			    
				SYSCLK.XOSCCR_REG |=  sysClkn -> XOSCFilter << 4;  /* External crystal filter */

				IRCBAND =  sysClkn -> IRCBand; /* Internal IRC adjust frequency band */
			    IRTRIM = sysClkn -> IRCTRIM;  /* Internal IRC adjust frequency IRTRIM  */
                LIRTRIM = sysClkn -> LIRCTRIM; /* Internal IRC adjust frequency LIRTRIM */
			    
			    if(sysClkn -> MCLKDiv == 0) SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv + 1;  /* Master clock frequency division */
				else SYSCLK.CLKDIV_REG = sysClkn -> MCLKDiv;
	        }
		
		    SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKDiv;   /* System clock frequency division */
		    SYSCLK.MCLKOCR_REG |= sysClkn -> SCLKOutPin << 7;
#endif
		EAXFR_DISABLE(); /* Disable access to the internal extended RAM area */

		return FSC_SUCCESS; /* Function self checking succeeded */
}

/**
  * @name    Get_Sysclk_FRE
  * @brief   Get System clock frequendy function
  * @param   None
  * @return  value of system clock frequenction (uint32_t_t)
***/
uint32_t Get_SysClk_FRE(void)
{
	uint32_t Count;
#if    (PER_LIB_MCU_MUODEL == STC8Ax || PER_LIB_MCU_MUODEL == STC8Cx || PER_LIB_MCU_MUODEL == STC8Fx)
	/* Frequency deviation, calculate the approximate data */
	Count = 24000000UL + ((int32_t)((int32_t)IRTRIM - (int32_t)IRC_24M) * 0xD2F0UL);
	Count /= SYSCLK.CLKDIV_REG;  /*Divide by division value */
#elif (PER_LIB_MCU_MUODEL == STC8Gx || PER_LIB_MCU_MUODEL == STC8Hx)
	/* Frequency deviation, calculate the approximate data */
    if(IRCBAND)    Count = 36000000UL + ((int32)((int32)IRTRIM - (int32)IRC_22_1184M) * 0x128E0UL); 
	else           Count = 24000000UL + ((int32)((int32)IRTRIM - (int32)IRC_24M) * 0xBB80UL); 
	Count /= SYSCLK.CLKDIV_REG;  /*Divide by division value */
#endif
	return Count;
}

/*-----------------------------------------------------------------------
|                   END OF FLIE.  (C) COPYRIGHT zeweni                  |
-----------------------------------------------------------------------*/

