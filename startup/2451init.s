;=========================================
; NAME: 2440INIT.S
; DESC: C start up codes
;       Configure memory, ISR ,stacks//Æô¶¯´úÂë£¬ÅäÖÃISR£¬ÄÚ´æ£¬Õ»
;	Initialize C-variables
; HISTORY:
; 2002.02.25:kwtark: ver 0.0
; 2002.03.20:purnnamu: Add some functions for testing STOP,Sleep mode
; 2003.03.14:DonGo: Modified for 2440.
;=========================================

	GET option.inc
	GET memcfg.inc
	GET 2451addr.inc

BIT_SELFREFRESH EQU	(1<<22)


;DDR INIT VALUE
CFG_BANK_CFG_VAL		EQU     0x0004920d
CFG_BANK_CON1_VAL		EQU     0x04000040
CFG_BANK_CON2_VAL		EQU     0x0057003a
CFG_BANK_CON3_VAL		EQU     0x80000030
CFG_BANK_REFRESH_VAL	EQU     0x00000313

;Pre-defined constants
USERMODE    EQU 	0x10
FIQMODE     EQU 	0x11
IRQMODE     EQU 	0x12
SVCMODE     EQU 	0x13
ABORTMODE   EQU 	0x17
UNDEFMODE   EQU 	0x1b
MODEMASK    EQU 	0x1f
NOINT       EQU 	0xc0

;The location of stacks
UserStack	EQU	(_STACK_BASEADDRESS-0x3800)	;0x33ff4800 ~
SVCStack	EQU	(_STACK_BASEADDRESS-0x2800)	;0x33ff5800 ~
UndefStack	EQU	(_STACK_BASEADDRESS-0x2400)	;0x33ff5c00 ~
AbortStack	EQU	(_STACK_BASEADDRESS-0x2000)	;0x33ff6000 ~
IRQStack	EQU	(_STACK_BASEADDRESS-0x1000)	;0x33ff7000 ~
FIQStack	EQU	(_STACK_BASEADDRESS-0x0)	;0x33ff8000 ~

	MACRO
	MOV_PC_LR
	    bx lr
	MEND

	MACRO
	MOVEQ_PC_LR
 		[ THUMBCODE
        bxeq lr
 		|
	    moveq pc,lr
 		]
	MEND

	MACRO
$HandlerLabel HANDLER $HandleLabel

$HandlerLabel
	sub		sp,sp,#4			;decrement sp(to store jump address)
	stmfd	sp!,{r0}			;PUSH the work register to stack(lr does not push because it return to original address)
	ldr     r0,=$HandleLabel	;load the address of HandleXXX to r0
	ldr     r0,[r0]	 			;load the contents(service routine start address) of HandleXXX
	str     r0,[sp,#4]      	;store the contents(ISR) of HandleXXX to stack
	ldmfd   sp!,{r0,pc}    	 	;POP the work register and pc(jump to ISR)
	MEND

	IMPORT  |Image$$ER_ROM1$$Base|	;Base of ROM code
	IMPORT  |Image$$ER_ROM1$$Limit|	;End of ROM code (=start of ROM data)
	IMPORT  |Image$$RW_RAM1$$Base|	;Base of RAM to initialise
	IMPORT  |Image$$RW_RAM1$$Base|	;Base and limit of area
	IMPORT  |Image$$RW_RAM1$$Limit|	;to zero initialise

	IMPORT	MMU_SetAsyncBusMode
	IMPORT	MMU_SetFastBusMode

	IMPORT  Main    			;The main entry of mon program

	AREA    RESET,CODE,READONLY

    PRESERVE8
    
	ENTRY
	
	EXPORT	__ENTRY
__ENTRY
start
ResetEntry
	;1)The code, which converts to Big-endian, should be in little endian code.
	;2)The following little endian code will be compiled in Big-Endian mode.
	;  The code byte order should be changed as the memory bus width.
	;3)The pseudo instruction,DCD can not be used here because the linker generates error.
	ASSERT	:DEF:ENDIAN_CHANGE
	[ ENDIAN_CHANGE
	    ASSERT  :DEF:ENTRY_BUS_WIDTH
	    [ ENTRY_BUS_WIDTH=32
		b	ChangeBigEndian	    	;DCD 0xea000007
	    ]

	    [ ENTRY_BUS_WIDTH=16
		andeq	r14,r7,r0,lsl #20   ;DCD 0x0007ea00
	    ]

	    [ ENTRY_BUS_WIDTH=8
		streq	r0,[r0,-r10,ror #1] ;DCD 0x070000ea
	    ]
	|
	    b	ResetHandler
    ]
	b	HandlerUndef	;handler for Undefined mode
	b	HandlerSWI		;handler for SWI interrupt
	b	HandlerPabort	;handler for PAbort
	b	HandlerDabort	;handler for DAbort
	b	.				;reserved
	b	HandlerIRQ		;handler for IRQ interrupt
	b	HandlerFIQ		;handler for FIQ interrupt

;@0x20
	b	EnterPWDN	; Must be @0x20.
ChangeBigEndian
;@0x24
	[ ENTRY_BUS_WIDTH=32
	    DCD	0xee110f10	;0xee110f10 => mrc p15,0,r0,c1,c0,0
	    DCD	0xe3800080	;0xe3800080 => orr r0,r0,#0x80;  //Big-endian
	    DCD	0xee010f10	;0xee010f10 => mcr p15,0,r0,c1,c0,0
	]
	[ ENTRY_BUS_WIDTH=16
	    DCD 0x0f10ee11
	    DCD 0x0080e380
	    DCD 0x0f10ee01
	]
	[ ENTRY_BUS_WIDTH=8
	    DCD 0x100f11ee
	    DCD 0x800080e3
	    DCD 0x100f01ee
    ]
	DCD 0xffffffff  ;swinv 0xffffff is similar with NOP and run well in both endian mode.
	DCD 0xffffffff
	DCD 0xffffffff
	DCD 0xffffffff
	DCD 0xffffffff
	b ResetHandler
	
HandlerFIQ      HANDLER HandleFIQ
HandlerIRQ      HANDLER HandleIRQ
HandlerUndef    HANDLER HandleUndef
HandlerSWI      HANDLER HandleSWI
HandlerDabort   HANDLER HandleDabort
HandlerPabort   HANDLER HandlePabort

IsrIRQ
	sub		sp,sp,#4 		;reserved for PC
	stmfd	sp!,{r8-r9}

	ldr		r9,=INTOFFSET
	ldr		r9,[r9]
	ldr		r8,=HandleEINT0
	add		r8,r8,r9,lsl #2
	ldr		r8,[r8]
	str		r8,[sp,#8]
	ldmfd	sp!,{r8-r9,pc}

	LTORG

;=======
; ENTRY
;=======
ResetHandler
	ldr	r0,=WTCON       ;watch dog disable
	ldr	r1,=0x0
	str	r1,[r0]

	ldr	r0,=INTMSK
	ldr	r1,=0xffffffff  ;all interrupt disable
	str	r1,[r0]

	ldr	r0,=INTSUBMSK
	ldr	r1,=0x7fff		;all sub interrupt disable
	str	r1,[r0]
	
	ldr sp, =0x40002000
	;clock_init
    IMPORT clock_init
    bl clock_init


    ;DDR INIT
    ;DDR´æ´¢Æ÷³õÊ¼»¯

    ;IMPORT  sdr_ctrl_asm_init
    ;ldr r0, =sdram_bank_set_val
    ;bl sdr_ctrl_asm_init
    


 	;Initialize stacks
	bl	InitStacks

;===========================================================
	
	
;===========================================================

;===========================================================

	
;===========================================================
  	; Setup IRQ handler
	ldr	r0,=HandleIRQ       ;This routine is needed
	ldr	r1,=IsrIRQ	  ;if there is not 'subs pc,lr,#4' at 0x18, 0x1c
	str	r1,[r0]



on_ddr 
   	b Main


;function initializing stacks
InitStacks
	;Do not use DRAM,such as stmfd,ldmfd......
	;SVCstack is initialized before
	;Under toolkit ver 2.5, 'msr cpsr,r1' can be used instead of 'msr cpsr_cxsf,r1'
	mrs	r0,cpsr
	bic	r0,r0,#MODEMASK
	orr	r1,r0,#UNDEFMODE:OR:NOINT
	msr	cpsr_cxsf,r1		;UndefMode
	ldr	sp,=UndefStack		; UndefStack=0x33FF_5C00

	orr	r1,r0,#ABORTMODE:OR:NOINT
	msr	cpsr_cxsf,r1		;AbortMode
	ldr	sp,=AbortStack		; AbortStack=0x33FF_6000

	orr	r1,r0,#IRQMODE:OR:NOINT
	msr	cpsr_cxsf,r1		;IRQMode
	ldr	sp,=IRQStack		; IRQStack=0x33FF_7000

	orr	r1,r0,#FIQMODE:OR:NOINT
	msr	cpsr_cxsf,r1		;FIQMode
	ldr	sp,=FIQStack		; FIQStack=0x33FF_8000

	bic	r0,r0,#MODEMASK:OR:NOINT
	orr	r1,r0,#SVCMODE
	msr	cpsr_cxsf,r1		;SVCMode
	ldr	sp,=SVCStack		; SVCStack=0x33FF_5800

	;USER mode has not be initialized.

	bx lr
	;The LR register will not be valid if the current mode is not SVC mode.
	
;===========================================================
loop 
    b loop

;===========================================================

	LTORG

;GCS0->SST39VF1601
;GCS1->16c550
;GCS2->IDE
;GCS3->CS8900
;GCS4->DM9000
;GCS5->CF Card
;GCS6->SDRAM
;GCS7->unused

SMRDATA DATA
; Memory configuration should be optimized for best performance
; The following parameter is not optimized.
; Memory access cycle parameter strategy
; 1) The memory settings is  safe parameters even at HCLK=75Mhz.
; 2) SDRAM refresh period is for HCLK<=75Mhz.

sdram_bank_set_val
	DCD	CFG_BANK_CFG_VAL
	DCD	CFG_BANK_CON1_VAL
	DCD	CFG_BANK_CON2_VAL
	DCD	CFG_BANK_CON3_VAL
	DCD	CFG_BANK_REFRESH_VAL 
	
BaseOfROM	DCD	|Image$$ER_ROM1$$Base|
TopOfROM	DCD	|Image$$ER_ROM1$$Limit|
BaseOfBSS	DCD	|Image$$RW_RAM1$$Base|
BaseOfZero	DCD	|Image$$RW_RAM1$$Base|
EndOfBSS	DCD	|Image$$RW_RAM1$$Limit|
bss_start   DCD |Image$$RW_RAM1$$Base|
bss_end     DCD |Image$$RW_RAM1$$Limit|

	ALIGN
	
;Function for entering power down mode
; 1. SDRAM should be in self-refresh mode.
; 2. All interrupt should be maksked for SDRAM/DRAM self-refresh.
; 3. LCD controller should be disabled for SDRAM/DRAM self-refresh.
; 4. The I-cache may have to be turned on.
; 5. The location of the following code may have not to be changed.

;void EnterPWDN(int CLKCON);
EnterPWDN
	mov r2,r0		;r2=rCLKCON
	tst r0,#0x8		;SLEEP mode?
	bne ENTER_SLEEP

ENTER_STOP
	ldr r0,=REFRESH
	ldr r3,[r0]		;r3=rREFRESH
	mov r1, r3
	orr r1, r1, #BIT_SELFREFRESH
	str r1, [r0]		;Enable SDRAM self-refresh

	mov r1,#16			;wait until self-refresh is issued. may not be needed.
0	subs r1,r1,#1
	bne %B0

	ldr r0,=CLKCON		;enter STOP mode.
	str r2,[r0]

	mov r1,#32
0	subs r1,r1,#1	;1) wait until the STOP mode is in effect.
	bne %B0		;2) Or wait here until the CPU&Peripherals will be turned-off
			;   Entering SLEEP mode, only the reset by wake-up is available.

	ldr r0,=REFRESH ;exit from SDRAM self refresh mode.
	str r3,[r0]

	MOV_PC_LR

ENTER_SLEEP
	;NOTE.
	;1) rGSTATUS3 should have the return address after wake-up from SLEEP mode.

	ldr r0,=REFRESH
	ldr r1,[r0]		;r1=rREFRESH
	orr r1, r1, #BIT_SELFREFRESH
	str r1, [r0]		;Enable SDRAM self-refresh

	mov r1,#16			;Wait until self-refresh is issued,which may not be needed.
0	subs r1,r1,#1
	bne %B0

	ldr	r1,=MISCCR
	ldr	r0,[r1]
	orr	r0,r0,#(7<<17)  ;Set SCLK0=0, SCLK1=0, SCKE=0.
	str	r0,[r1]

	ldr r0,=CLKCON		; Enter sleep mode
	str r2,[r0]

	b .			;CPU will die here.


WAKEUP_SLEEP
	;Release SCLKn after wake-up from the SLEEP mode.
	ldr	r1,=MISCCR
	ldr	r0,[r1]
	bic	r0,r0,#(7<<17)  ;SCLK0:0->SCLK, SCLK1:0->SCLK, SCKE:0->=SCKE.
	str	r0,[r1]

	;Set memory control registers
 	ldr	r0,=SMRDATA	;be careful! 
	ldr	r1,=BWSCON	;BWSCON Address
	add	r2, r0, #52	;End address of SMRDATA
0
	ldr	r3, [r0], #4
	str	r3, [r1], #4
	cmp	r2, r0
	bne	%B0

	mov r1,#256
0	subs r1,r1,#1	;1) wait until the SelfRefresh is released.
	bne %B0

	ldr r1,=GSTATUS3 	;GSTATUS3 has the start address just after SLEEP wake-up
	ldr r0,[r1]

	bx lr
	
	ALIGN

	AREA RamData, DATA, READWRITE

	^   _ISR_STARTADDRESS		; _ISR_STARTADDRESS=0x33FFFF00
HandleReset 	#   4
HandleUndef 	#   4
HandleSWI		#   4
HandlePabort    #   4
HandleDabort    #   4
HandleReserved  #   4
HandleIRQ		#   4
HandleFIQ		#   4

;Do not use the label 'IntVectorTable',
;The value of IntVectorTable is different with the address you think it may be.
;IntVectorTable
;@0x33FF_FF20
HandleEINT0		#   4
HandleEINT1		#   4
HandleEINT2		#   4
HandleEINT3		#   4
HandleEINT4_7	#   4
HandleEINT8_23	#   4
HandleCAM		#   4		; Added for 2440.
HandleBATFLT	#   4
HandleTICK		#   4
HandleWDT		#   4
HandleTIMER0 	#   4
HandleTIMER1 	#   4
HandleTIMER2 	#   4
HandleTIMER3 	#   4
HandleTIMER4 	#   4
HandleUART2  	#   4
;@0x33FF_FF60
HandleLCD 		#   4
HandleDMA0		#   4
HandleUART3		#   4
HandleCFCON		#   4
HandleSDI1		#   4
HandleSDI0		#   4
HandleSPI0		#   4
HandleUART1		#   4
HandleNFCON		#   4		; Added for 2451.
HandleUSBD		#   4
HandleUSBH		#   4
HandleIIC		#   4
HandleUART0 	#   4
HandleSPI1 		#   4
HandleRTC 		#   4
HandleADC 		#   4
;@0x33FF_FFA0
	END
