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
extern void key_e(void);//������������ͬʱ���£�����һ������ֻ���ɿ��ü����ܰ��ڶ�����
extern void KEY_LCD(int *flag,int *k1_default_flag,int *k3_default_flag,const unsigned char **ppicture,unsigned char keyvalue);//Һ����ʾ��
extern unsigned char key_scan(void);
extern unsigned char mode;


#endif
