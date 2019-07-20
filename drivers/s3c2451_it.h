#ifndef S3C2451_IT_H
#define S3C2451_IT_H

#include "s3c2451_gpio.h"

extern void __irq UART0_IRQ(void);
extern void __irq TIMER0_IRQ(void);
extern void __irq ADC_IRQ(void);
extern void __irq TICK_IRQ(void);
extern void __irq TIMER1_IRQ(void);
extern int flag;
extern int display_time_flag;
extern int shift_time;
extern void disply_num(int model,int num_shi,int num_ge);

#endif
