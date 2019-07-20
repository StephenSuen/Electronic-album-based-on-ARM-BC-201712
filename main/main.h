#ifndef __MAIN_H__
#define __MAIN_H__
#include "stdio.h"
#include "string.h"
#include "typedef.h"
#include "s3c2451_led.h"
#include "s3c2451_gpio.h"
#include "key.h"
#include "delay.h"
#include "s3c2451_uart.h"
#include "s3c2451_it.h"
#include "s3c2451_irq.h"
#include "s3c2451_time.h"
#include "s3c2451_lcd.h"
#include "s3c2451_adc.h"
#include "s3c2451_rtc.h"
void Main(void);

extern void Interface(void);


#endif  // __MAIN_H__
