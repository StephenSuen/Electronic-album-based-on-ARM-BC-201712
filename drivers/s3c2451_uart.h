#ifndef S3C2451_UART_H
#define S3C2451_UART_H

#include "typedef.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "s3c2451_vector.h"
//#define ULCON0 (*(volatile unsigned long *)0x50000000)
//#define ULCON1 (*(volatile unsigned long *)0x50004000)
//#define ULCON2 (*(volatile unsigned long *)0x50008000)
//#define ULCON3 (*(volatile unsigned long *)0x5000C000)
	
#define UCON0 (*(volatile unsigned long *)0x50000004)
#define UCON1 (*(volatile unsigned long *)0x50004004)
#define UCON2 (*(volatile unsigned long *)0x50008004)
#define UCON3 (*(volatile unsigned long *)0x5000C004)
#define UFCON0 (*(volatile unsigned long *)0x50000008)
#define UMCON0 (*(volatile unsigned long *)0x5000000C)
#define UTRSTAT0 (*(volatile unsigned long *)0x50000010)	//发送状态，0代表发送缓冲区不空，1代表发送缓冲区为空即数据还没传到该缓冲区，需等待数据传过来，当有数据传过来，该值变为0代表不空
#define UERSTAT0 (*(volatile unsigned long *)0x50000014)	
#define UFSTAT0 (*(volatile unsigned long *)0x50000018)
#define UMSTAT0 (*(volatile unsigned long *)0x5000001C)		
#define UTXH0 (*(volatile unsigned long *)0x50000020)	//发送缓冲区
#define URXH0 (*(volatile unsigned long *)0x50000024)			//接收缓冲区
#define UBRDIV0 (*(volatile unsigned long *)0x50000028)
#define UDIVSLOT0 (*(volatile unsigned long *)0x5000002C)

typedef struct{
	U32 ULCON;
	U32 UCON;
	U32 UFCON;
	U32 UMCON;
	U32 UTRSTAT;
	U32 UERSTAT;
	U32 UFSTAT;
	U32 UMSTAT;
	U32 UTXH;
	U32 URXH;
	U32 UBRDIV;
	U32 UDIVSLOT;
}volatile *UART_MemMapPtr;

#define UART0_BASE_PTR ((UART_MemMapPtr)0x50000000)
#define UART1_BASE_PTR ((UART_MemMapPtr)0x50004000)
#define UART2_BASE_PTR ((UART_MemMapPtr)0x50008000)
#define UART3_BASE_PTR ((UART_MemMapPtr)0x5000C000)

typedef enum{
	UART0 = 0,
	UART1,
	UART2,
	UART3
						}UART_typedef;

typedef enum{
	wordwidth_5bit = 0,
	wordwidth_6bit,
	wordwidth_7bit,
	wordwidth_8bit
}WORDWIDTH_typedef;

typedef enum{
	stop_one = 0,
	stop_two
}STOP_typedef;

typedef enum{//校验位
	parity_no = 0,
	parity_odd = 4,
	parity_even = 5,
	parity_one = 6,
	parity_zero = 7
}PARITY_typedef;

typedef enum{
	mode_rx=0x1,
	mode_tx = 0x4,
	mode_rx_tx = 0x5
}MODE_typedef;

typedef struct{
	U32 baudrate;
	WORDWIDTH_typedef wordwidth;
	STOP_typedef stop;
	PARITY_typedef parity;
	MODE_typedef mode;
}UART_init_typedef;

extern void uart_init(UART_typedef uartx,UART_init_typedef uart_init_typedef);
extern void uart_senddata(UART_typedef uartx, U8 data);
extern U8 uart_revdata(UART_typedef uartx);
extern void uart_string(UART_typedef uartx,unsigned char *string);
extern void uart_printf(char *fmt,...);
extern void UART_interrupt_init(UART_typedef uartx,U32 addr);
#endif
