#ifndef S3C2451_LED_H
#define S3C2451_LED_H

#define GPACON (*(volatile unsigned long *)0x56000000)//定义GPACON标识符为指针
#define GPADAT (*(volatile unsigned long *)0x56000004)
	
#define GPBCON (*(volatile unsigned long *)0x56000010)
#define GPBDAT (*(volatile unsigned long *)0x56000014)
#define GPBUDP (*(volatile unsigned long *)0x56000018)
#define GPBSEL (*(volatile unsigned long *)0x5600001C)
	
#define LEDA_ON(i) GPADAT &=~(0X1<<i)//i=25,则DPA25 = 0
#define LEDA_OFF(i) GPADAT |= (0X1<<i)//i=25,则DPA25 = 1

#define LEDB_ON(i) GPBDAT &=~(0X1<<i)//i=5,则DPB5 = 0
#define LEDB_OFF(i) GPBDAT |= (0X1<<i)//i=5,则DPB5 = 1

#define BEEPGPB_ON(i) GPBDAT |= (0X01<<i);
#define BEEPGPB_OFF(i) GPBDAT &= (0XFE<<i);

#include "delay.h"

extern void led_init(void);
extern void beep_init(void);

extern void liushuideng(void);//LED1->LED4循环点亮
extern void led_2(void);//LED1->LED4依次点亮,然后全熄灭，2s后再次依次点亮
extern void System_led(void);

#endif
