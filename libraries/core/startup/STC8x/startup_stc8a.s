;-------------------------------------------------------------------------
;                            FILE DESCRIPTION                            ;
;-------------------------------------------------------------------------
;-------------------------------------------------------------------------
;  - File name     : startup_stc8a.s
;  - Author        : zeweni
;  - Update date   : 2021.03.25
;  - Copyright(C)  : 2021-2021 zeweni. All rights reserved.
;-------------------------------------------------------------------------
;-------------------------------------------------------------------------
;                            COPYRIGHT NOTICE                            ;
;-------------------------------------------------------------------------
;
; * Copyright (C) 2021, zeweni (17870070675@163.com)
;
; * This file is part of Ant Real Time Operating System.
;
; * Ant Real Time Operating System is free software: you can redistribute 
; * it and/or modify it under the terms of the Apache-2.0 License.
; 
; * Ant Real Time Operating System is distributed in the hope that it will 
; * be useful,but WITHOUT ANY WARRANTY; without even the implied warranty 
; * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
; * Apache-2.0 License License for more details.
; 
; * You should have received a copy of the Apache-2.0 License.Ant Real Time
; * Operating System. If not, see <http://www.apache.org/licenses/>.

;-------------------------------------------------------------------------
;                                CONFIG                                  ;
;-------------------------------------------------------------------------
$NOMOD51

;------------------------------------------------------------------------
;  用户上电初始化内存
;  值得注意的是，这里的设置主要是影响堆栈和可重入函数。
;  如果你想真正指明内存大小，请在Keil的配置页面Target右下方填写设置。
;  User-defined <h> Power-On Initialization of Memory.
;  The length of XDATA memory in bytes.
;  It is worth noting that the settings here mainly affect the stack and 
;  reentrant functions.
;  If you really want to indicate the memory size, please fill in the 
;  settings at the bottom right of target on keil's configuration page.
;
;  With the following EQU statements the initialization of memory
;  at processor reset can be defined:
;------------------------------------------------------------------------

; @name    IDATALEN
; @brief   IDATA的内存范围是<0x0-0x100>.
;          IDATA memory size <0x0-0x100>.
; @Note    IDATA内存的绝对起始地址始终为0,IDATA空间在物理上与数据和位区域重叠。
;          The absolute start-address of IDATA memory is always 0
;          The IDATA space overlaps physically the DATA and BIT areas.
IDATALEN        EQU     0EEH  /*注意：最后几个字节保存了MCU重要参数，不得清零！*/


; @name    XDATASTART
; @brief   XDATA的内存范围是<0x0-0xFFFF>.
;          XDATA memory start address <0x00-0xFFFF>.
; @Note    这里设置IDATA内存的绝对起始地址。
;          The absolute start address of XDATA memory.
XDATASTART      EQU     0     


; @name    XDATALEN
; @brief   XDATA的内存范围是<0x0-0x1FFF>.
;          XDATA memory size <0x0-0x1FFF>.
; @Note    设置XDATA内存的字节长度,根据你实际的芯片XRAM大小来确定。
;          target on keil's configuration page.
XDATALEN        EQU     01FFFH     


; @name    PDATASTART
; @brief   PDATA的内存范围是<0x0-0xFF>.
;          PDATA memory start address <0x00-0xFF>.
; @Note    这里设置IDATA内存的绝对起始地址。
;          The absolute start address of XDATA memory.
PDATASTART      EQU     0     


; @name    PDATALEN
; @brief   PDATA的内存范围是<0x0-0xFF>.
;          PDATA memory size <0x0-0xFF>.
; @Note    这里设置IDATA内存的字节长度。
;          The length of XDATA memory in bytes.
PDATALEN        EQU     0      
	
	
;-------------------------------------------------------------------------
;  用户上电初始化可重入仿真堆栈
;  值得注意的是，这里的设置主要是影响堆栈和可重入函数。
;  如果你想真正指明内存大小，请在Keil的配置页面Target右下方填写设置。
;  Reentrant Stack Initialization
;  The length of XDATA memory in bytes.
;  It is worth noting that the settings here mainly affect the stack and 
;  reentrant functions.
;  If you really want to indicate the memory size, please fill in the 
;  settings at the bottom right of target on keil's configuration page.
;
;  The following EQU statements define the stack pointer for reentrant
;  functions and initialized it:
;-------------------------------------------------------------------------

; @name    IBPSTACK
; @brief   使能小模型可重入堆栈。
;          Enable SMALL model reentrant stack.
; @Note    小模型内存中可重入函数的堆栈空间。
;          Stack space for reentrant functions in the SMALL model.
IBPSTACK        EQU     0   ; set to 1 if small reentrant is used.
	
	
; @name    IBPSTACKTOP
; @brief   小型模型堆栈的结束地址范围<0x0-0xFF>。
;          End address of SMALL model stack <0x0-0xFF>.
; @Note    将堆栈的顶部设置到最高位置。
;          Set the top of the stack to the highest location.
IBPSTACKTOP     EQU     0xFF +1     ; default 0FFH+1  


; @name    XBPSTACK
; @brief   使能大模型可重入堆栈。
;          Enable LARGE model reentrant stack.
; @Note    大模型内存中可重入函数的堆栈空间。
;          Stack space for reentrant functions in the LARGE model.
XBPSTACK        EQU     0   ; set to 1 if large reentrant is used.
	
	
; @name    XBPSTACKTOP
; @brief   大模型堆栈的结束地址范围<0x0-0xFFFF>。
;          End address of SMALL model stack <0x0-0xFFFF>.
; @Note    将堆栈的顶部设置到最高位置。
;          Set the top of the stack to the highest location.
XBPSTACKTOP     EQU     0x400 + 1   ; default 0FFFFH+1 


; @name    PBPSTACK
; @brief   外部低256字节内存可重入堆栈。
;          The external low 256 byte out 
;          storage model can be reentered into the stack..
; @Note    外部低256字节内存中可重入函数的堆栈空间。
;          Stack space for reentrant functions in the LARGE model.
PBPSTACK        EQU     0   ; set to 1 is enable.
	
	
; @name    PBPSTACKTOP
; @brief   大模型堆栈的结束地址范围<0x0-0xFF>。
;          End address of SMALL model stack <0x0-0xFF>.
; @Note    将堆栈的顶部设置到最高位置。
;          Set the top of the stack to the highest location.
PBPSTACKTOP     EQU     0 + 1   ; default 0FFH+1 


; @name    PPAGEENABLE
; @brief   启用pdata内存页初始化
;          Enable pdata memory page initalization
; @Note    定义用于PDATA变量的扩展数据页。
;          内存页，用于使用具有64KB扩展数据RAM的紧凑型。
;          PPAGE必须与链接器调用中设置的PPAGE一致。
;          Stack space for reentrant functions in the LARGE model.
;          Memory Page for Using the Compact Model with 64 KByte xdata RAM.
;          PPAGE must conform with the PPAGE set in the linker invocation.
PPAGEENABLE     EQU     0       ; set to 1 if pdata object are used.


; @name    PPAGE
; @brief   内存页的范围<0x0-0xFF>。
;          PPAGE number <0x0-0xFF>.
; @Note    用于PDATA变量的页的最上面的256字节地址。
;          uppermost 256-byte address of the page used for PDATA variables.
PPAGE           EQU     0  


; @name    PPAGE_SFR
; @brief   提供最高地址字节<0x0-0xFF>的SFR地址。
;          SFR address which supplies uppermost address byte <0x0-0xFF>.
; @Note    大多数8051变体使用P2作为最高地址字节。
;          most 8051 variants use P2 as uppermost address byte.
PPAGE_SFR       DATA    0A0H


;-------------------------------------------------------------------------
;  配置硬件仿真需要占用的XDATA空间
;  值得注意的是，这里的设置主要是影响堆栈和可重入函数。
;  如果你想真正指明内存大小，请在Keil的配置页面Target右下方填写设置。
;  XDATA space for hardware emulation configuration
;  The length of XDATA memory in bytes.
;  It is worth noting that the settings here mainly affect the stack and 
;  reentrant functions.
;  If you really want to indicate the memory size, please fill in the 
;  settings at the bottom right of target on keil's configuration page.
;
;  如果你不需要硬件仿真，那么你可以忽略这部分代码。
;  If you don't need hardware emulation, 
;  you can ignore this part of the code.
;-------------------------------------------------------------------------

; @name    DEBUCTRL
; @brief   硬件仿真占用XDATA空间的开关。
;          Hardware simulation takes up XDATA space switch..
; @Note    如果你不配置它，编译器将不会为你预留出仿真需要的XDATA内存空间。
;          If you don't configure it, the compiler won't reserve 
;          XDATA memory for you.

DEBUCTRL        EQU     1   ; Set to 1 to reserve XDATA space for hardware simulation.


; @name    DEBUGXDATALEN
; @brief   硬件仿真debug需要占用XDATA的大小.
;          Hardware simulation debug needs to occupy the size of XDATA.
; @Note    这里设置denbug占用XDATA内存的字节长度。
;          一般是最后768个字节，如果有不同，请自己根据STC-ISP助手上的说明进行修改。
;          Set the byte length of XDATA memory occupied by debug.
;          Generally, it is the last 768 bytes. If it is different, 
;          please modify it according to the instructions on stc-isp assistant.

DEBUGXDATALEN    EQU    300H   
	
;-------------------------------------------------------------------------
;                          STARTUP FUNCTIONS                             ;
;-------------------------------------------------------------------------

; Standard SFR Symbols 
ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    81H
DPL     DATA    82H
DPH     DATA    83H

                NAME    ?C_STARTUP
					
?C_C51STARTUP   SEGMENT   CODE
?STACK          SEGMENT   IDATA

                RSEG    ?STACK
                DS      1

                EXTRN CODE (?C_START)
                PUBLIC  ?C_STARTUP

;**
; * @name    C_STARTUP
; * @brief   启动文件的首地址段.
; *          The first address segment of the startup file.
;**
                CSEG    AT      0
?C_STARTUP:     LJMP    STARTUP1

                RSEG    ?C_C51STARTUP

STARTUP1:

IF IDATALEN <> 0
                MOV     R0,#IDATALEN - 1
                CLR     A
IDATALOOP:      MOV     @R0,A
                DJNZ    R0,IDATALOOP
ENDIF

;**
; * @name    DEBUCTRL
; * @brief   处理硬件仿真占用XDATA预留空间。
; *          Processing hardware simulation 
; *          takes up XDATA reserved space.
;**
IF DEBUCTRL <> 0
			XBPSTACK_ACTTOP EQU (XBPSTACKTOP - DEBUGXDATALEN)
			XDATA_ADCTLEN   EQU (XDATALEN - DEBUGXDATALEN)
ELSE
			XBPSTACK_ACTTOP EQU XBPSTACKTOP
			XDATA_ADCTLEN   EQU XDATALEN
ENDIF

;**
; * @name    XDATA_ADCTLEN
; * @brief   初始化XDATA空间,以用于仿真栈寻址。
; *          Initialize XDATA space for emulation stack addressing.
;**
IF XDATA_ADCTLEN <> 0
                MOV     DPTR,#XDATASTART
                MOV     R7,#LOW (XDATA_ADCTLEN)
  IF (LOW (XDATA_ADCTLEN)) <> 0
                MOV     R6,#(HIGH (XDATA_ADCTLEN)) +1
  ELSE
                MOV     R6,#HIGH (XDATA_ADCTLEN)
  ENDIF
                CLR     A
XDATALOOP:      MOVX    @DPTR,A
                INC     DPTR
                DJNZ    R7,XDATALOOP
                DJNZ    R6,XDATALOOP
ENDIF
	
;**
; * @name    PPAGEENABLE
; * @brief   初始化PDATA空间,以用于仿真栈寻址。
; *          Initialize PDATA space for emulation stack addressing.
;**
IF PPAGEENABLE <> 0
                MOV     PPAGE_SFR,#PPAGE
ENDIF

IF PDATALEN <> 0
                MOV     R0,#LOW (PDATASTART)
                MOV     R7,#LOW (PDATALEN)
                CLR     A
PDATALOOP:      MOVX    @R0,A
                INC     R0
                DJNZ    R7,PDATALOOP
ENDIF

;**
; * @name    IBPSTACK
; * @brief   初始化位于IDATA的仿真栈。
; *          Initialize the emulation stack at IDA TA.
;**
IF IBPSTACK <> 0
EXTRN DATA (?C_IBP)

                MOV     ?C_IBP,#LOW IBPSTACKTOP
ENDIF

;**
; * @name    XBPSTACK
; * @brief   初始化位于XDATA的仿真栈。
; *          Initialize the emulation stack at IDA TA.
;**
IF XBPSTACK <> 0
EXTRN DATA (?C_XBP)

                MOV     ?C_XBP,#HIGH XBPSTACK_ACTTOP
                MOV     ?C_XBP+1,#LOW XBPSTACK_ACTTOP
ENDIF

;**
; * @name    PBPSTACK
; * @brief   初始化位于PDATA的仿真栈。
; *          Initialize the emulation stack at IDA TA.
;**
IF PBPSTACK <> 0
EXTRN DATA (?C_PBP)
                MOV     ?C_PBP,#LOW PBPSTACKTOP
ENDIF

                MOV     SP,#?STACK-1

				
; This code is required if you use L51_BANK.A51 with Banking Mode 4
;<h> Code Banking
; <q> Select Bank 0 for L51_BANK.A51 Mode 4
#if 0   
;     <i> Initialize bank mechanism to code bank 0 when using L51_BANK.A51 with Banking Mode 4.
EXTRN CODE (?B_SWITCH0)
                CALL    ?B_SWITCH0      ; init bank mechanism to code bank 0
#endif

;-------------------------------------------------------------------------
;                              ISR FUNCTIONS                             ;
;-------------------------------------------------------------------------

;**
; * @name    TIMER0_ISRQ_Handler
; * @brief   MCU TIMER0 Interrupt request service function
; * @param   None
; * @return  None
;**


	
LJMP    ?C_START
END

/*------------------------------------------------------------------------
|                    END OF FLIE.  (C) COPYRIGHT zeweni                  |
------------------------------------------------------------------------*/




