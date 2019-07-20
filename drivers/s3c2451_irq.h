#ifndef S3C2451_IRQ_H
#define S3C2451_IRQ_H
#include "typedef.h"

typedef struct{
	U32 SRCPND;
	U32 INTMOD;
	U32 INTMSK;
	U32 NOREGISTER;//此处可自己定义名称
	U32 INTPND;
	U32 INTOFFSET;
	U32 SUBSRCPND;
	U32 INTSUBMSK;
}volatile *IRQ_MemMapPtr;

#define IRQ1_BASE_PTR ((IRQ_MemMapPtr)0x4A000000)
#define IRQ2_BASE_PTR ((IRQ_MemMapPtr)0x4A000040)
//#define SRCPND1 (*(volatile unsigned long*)0x4A000000)
//#define INTMOD1 (*(volatile unsigned long*)0x4A000004)
//#define INTMSK1 (*(volatile unsigned long*)0X4A000008)
//#define INTPND1 (*(volatile unsigned long*)0X4A000010)
//#define INTOFFSET1 (*(volatile unsigned long*)0X4A000014)
//#define SUBSRCPND (*(volatile unsigned long*)0X4A000018)
//#define INTSUBMSK (*(volatile unsigned long*)0X4A00001C)
//#define PRIORITY_MODE1 (*(volatile unsigned long*)0x4A000030)
//#define PRIORITY_UPDATE1 (*(volatile unsigned long*)0x4A000034)
	
#define SRCPND2 (*(volatile unsigned long*)0X4A000040)
#define INTMOD2 (*(volatile unsigned long*)0X4A000044)
#define INTMSK2 (*(volatile unsigned long*)0X4A000048)
#define INTPND2 (*(volatile unsigned long*)0X4A000050)
#define INTOFFSET2 (*(volatile unsigned long*)0X4A000054)
#define PRIORITY_MODE2 (*(volatile unsigned long*)0x4A000070)
#define PRIORITY_UPDATE2 (*(volatile unsigned long*)0x4A000074)


//主寄存器位内容-SRCPND
#define INT_ADC (unsigned int)(1<<31)
#define INT_RTC (1<<30)
#define INT_SPI1 (1<<29)
#define INT_UART0 (1<<28)
#define INT_IIC0 (1<<27)
#define INT_USBH (1<<26)
#define INT_USBD (1<<25)
#define INT_NAND (1<<24)
#define INT_UART1 (1<<23)
#define INT_SPI0 (1<<22)
#define INT_SDI0 (1<<21)
#define INT_SDI1 (1<<20)
#define INT_CFCON (1<<19)
#define INT_UART3 (1<<18)
#define INT_DMA (1<<17)
#define INT_LCD (1<<16)
#define INT_UART2 (1<<15)
#define INT_TIMER4 (1<<14)
#define INT_TIMER3 (1<<13)
#define INT_TIMER2 (1<<12)
#define INT_TIMER1 (1<<11)
#define INT_TIMER0 (1<<10)
#define INT_WDT_AC97 (1<<9)
#define INT_TICK (1<<8)
#define nBATT_FLT (1<<7)
#define INT_CAM (1<<6)
#define EINT8_23 (1<<5)
#define EINT4_7 (1<<4)
#define EINT3 (1<<3)
#define EINT2 (1<<2)
#define EINT1 (1<<1)
#define EINT0 (1<<0)


//子寄存器位内容
#define SUBINT_ADC (1<<10)
#define SUBINT_TC (1<<9)
#define SUBINT_ERR2 (1<<8)
#define SUBINT_TXD2 (1<<7)
#define SUBINT_RXD2 (1<<6)
#define SUBINT_ERR1 (1<<5)
#define SUBINT_TXD1 (1<<4)
#define SUBINT_RXD1 (1<<3)
#define SUBINT_ERR0 (1<<2)
#define SUB_INT_TXD0 (1<<1)
#define SUB_INT_RXD0 (1<<0)

typedef enum{
	DISABLE = 0,
	ENABLE
}Functionalstate;


extern void IRQ_ClearSRCPND(unsigned int irqx);//清楚主标志寄存器内容
extern void IRQ_ClearSUBSRCPND(unsigned int irqx);//清楚子标志寄存器内容
extern void IRQ_INTMask_init(unsigned int irqx,Functionalstate newstate);//主屏蔽寄存器开启或关闭
extern void IRQ_INTSUBMask_init(unsigned int irqx,Functionalstate newstate);//子屏蔽寄存器开启或关闭

extern Functionalstate IRQ_GetSRCPND(unsigned int irqx);//获取主标志寄存器有没有响应
extern Functionalstate IRQ_GetSUBSRCPND(unsigned int irqx);//获取子标志寄存器有没有响应



#endif
