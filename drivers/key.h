#ifndef KEY_H_
#define KEY_H_


#include "s3c2451_gpio.h"
#include "delay.h"
#include "main.h"

#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4

//extern void key_r(void);
extern void key_e(void);//不允许两个键同时按下，按下一个键后，只有松开该键才能按第二个键
extern void KEY_LCD(int *flag,int *k1_default_flag,int *k3_default_flag,const unsigned char **ppicture,unsigned char keyvalue);//液晶显示屏
extern unsigned char key_scan(void);
extern unsigned char mode;


#endif
