;===========================================
; NAME: OPTION.A
; DESC: Configuration options for .S files
; HISTORY:
; 02.28.2002: ver 0.0
; 03.11.2003: ver 0.0	attached for 2440.
; jan E, 2004: ver0.03  modified for 2440A01.
;===========================================

;Start address of each stacks,
_STACK_BASEADDRESS	EQU 0x33ff8000
_MMUTT_STARTADDRESS	EQU 0x33ff8000
_ISR_STARTADDRESS	EQU 0x33ffff00

		GBLL 	PLL_ON_START
PLL_ON_START	SETL 	{TRUE}


		GBLL	ENDIAN_CHANGE
ENDIAN_CHANGE	SETL	{FALSE}

		GBLA	ENTRY_BUS_WIDTH
ENTRY_BUS_WIDTH	SETA	16


;BUSWIDTH = 16,32
		GBLA    BUSWIDTH	;max. bus width for the GPIO configuration
BUSWIDTH	SETA    32


	END

