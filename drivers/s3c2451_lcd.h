#ifndef _S3C2451_LCD_H__
#define _S3C2451_LCD_H__
#include "typedef.h"
#define VIDCON0			(*(volatile unsigned *)0x4c800000)	
#define VIDCON1			(*(volatile unsigned *)0x4c800004)	
#define VIDTCON0		(*(volatile unsigned *)0x4c800008)	
#define VIDTCON1		(*(volatile unsigned *)0x4c80000C)	
#define VIDTCON2		(*(volatile unsigned *)0x4c800010)	
#define WINCON0			(*(volatile unsigned *)0x4c800014)	
#define WINCON1			(*(volatile unsigned *)0x4c800018)	
#define VIDOSD0A		(*(volatile unsigned *)0x4c800028)	
#define VIDOSD0B		(*(volatile unsigned *)0x4c80002C)
#define VIDOSD1A		(*(volatile unsigned *)0x4c800034)	
#define VIDOSD1B		(*(volatile unsigned *)0x4c800038)	
#define VIDOSD1C		(*(volatile unsigned *)0x4c80003C)	
#define VIDW00ADD0B0	(*(volatile unsigned *)0x4c800064)	
#define VIDW00ADD0B1	(*(volatile unsigned *)0x4c800068)	
#define VIDW01ADD0		(*(volatile unsigned *)0x4c80006C)	
#define VIDW00ADD1B0	(*(volatile unsigned *)0x4c80007C)	
#define VIDW00ADD1B1	(*(volatile unsigned *)0x4c800080)	
#define VIDW01ADD1		(*(volatile unsigned *)0x4c800084)	
#define VIDW00ADD2B0	(*(volatile unsigned *)0x4c800094)	
#define VIDW00ADD2B1	(*(volatile unsigned *)0x4c800098)	
#define VIDW01ADD2		(*(volatile unsigned *)0x4c80009C)	
#define VIDINTCON		(*(volatile unsigned *)0x4c8000AC)	
#define W1KEYCON0		(*(volatile unsigned *)0x4c8000B0)	
#define W1KEYCON1		(*(volatile unsigned *)0x4c8000B4)	
#define W2KEYCON0		(*(volatile unsigned *)0x4c8000B8)	
#define W2KEYCON1		(*(volatile unsigned *)0x4c8000BC)	
#define W3KEYCON0		(*(volatile unsigned *)0x4c8000C0)	
#define W3KEYCON1		(*(volatile unsigned *)0x4c8000C4)	
#define W4KEYCON0		(*(volatile unsigned *)0x4c8000C8)	
#define W4KEYCON1		(*(volatile unsigned *)0x4c8000CC)	
#define WIN0MAP			(*(volatile unsigned *)0x4c8000D0)	
#define WIN1MAP			(*(volatile unsigned *)0x4c8000D4)	
#define WPALCON			(*(volatile unsigned *)0x4c8000E4)	
#define SYSIFCON0		(*(volatile unsigned *)0x4c800130)	
#define SYSIFCON1		(*(volatile unsigned *)0x4c800134)	
#define DITHMODE1		(*(volatile unsigned *)0x4c800138)	
#define SIFCCON0		(*(volatile unsigned *)0x4c80013C)	
#define SIFCCON1		(*(volatile unsigned *)0x4c800140)	
#define SIFCCON2		(*(volatile unsigned *)0x4c800144)	
#define CPUTRIGCON1		(*(volatile unsigned *)0x4c80015C)	
#define CPUTRIGCON2		(*(volatile unsigned *)0x4c800160)	
#define VIDW00ADD0B1	(*(volatile unsigned *)0x4c800068)	
#define VIDW01ADD0		(*(volatile unsigned *)0x4c80006C)	
#define GPCCON			(*(volatile unsigned *)(0x56000020))	
#define GPCDAT			(*(volatile unsigned *)(0x56000024))	
#define GPCUDP			(*(volatile unsigned *)(0x56000028))	
#define GPDCON			(*(volatile unsigned *)(0x56000030))	
#define GPDDAT			(*(volatile unsigned *)(0x56000034))	
#define GPDUDP			(*(volatile unsigned *)(0x56000038))	
#define MISCCR			(*(volatile unsigned *)(0x56000080))	
#define GPLCON			(*(volatile unsigned *)(0x560000f0))	
#define GPLDAT			(*(volatile unsigned *)(0x560000f4))	
#define GPGCON 			(*(volatile unsigned long *)0x56000060)
#define GPGDAT 			(*(volatile unsigned long *)0x56000064)
#define FRAME_BUFFER   		LCD_BUFFER

#define LCD_X					480
#define LCD_Y					272
#define HSPW 				(30)
#define HBPD			 	(10)
#define HFPD 				(19)
#define VSPW				(8)
#define VBPD 				(2)
#define VFPD 				(4)
#define LINEVAL 			(LCD_Y-1)
#define HOZVAL				(LCD_X-1)
#define LeftTopX     0
#define LeftTopY     0
#define RightBotX   (LCD_X-1)
#define RightBotY   (LCD_Y-1)



#define GPFCON    (*(volatile unsigned long *)0x56000050)
#define GPFDAT    (*(volatile unsigned long *)0x56000054)
#define EXTINT0   (*(volatile unsigned long *)0x56000088)
#define SRCPND1   (*(volatile unsigned long *)0X4A000000)
#define INTPND1   (*(volatile unsigned long *)0X4A000010)
#define INTMSK1   (*(volatile unsigned long *)0X4A000008)

#define WHITE 0XFFFFFF	 //白色
#define BLACK 0					 //黑色

#define RED   0XFF0000   //红色
#define GREEN 0XFF00     //绿色
#define BLUE  0XFF       //蓝色
#define YELLOW 0XFFFF00  //黄色



//extern void LCD_GPIO_Init(void);  //初始化 LCD相关GPIO
extern void lcd_init(void);		//初始化LCD配置参数
extern void LCD_putpixe(U32 x, U32 y,U32 c);
extern void LCD_clear(U32 c);

extern void LCD_rectangle(void);
extern void LCD_rectangle_8_16(U32 x0,U32 y0);
extern void LED_circle(U32 x,U32 y,unsigned int r);
extern void LCD_displaypicture_32(int x0,int y0,int w, int h,const unsigned char *picture);
extern void LCD_displaypicture_24(int x0,int y0,int w, int h,const unsigned char *picture);//24位真彩色
extern void LCD_displaypicture_24_left_reverse_90(int x0,int y0,int w, int h,const unsigned char *picture);
extern void LCD_displaypicture_24_left_reverse_180(int x0,int y0,int w, int h,const unsigned char *picture);
extern void LCD_displaypicture_24_left_reverse_270(int x0,int y0,int w, int h,const unsigned char *picture);

extern const unsigned char ch[][16];
extern const unsigned char hanzi[][32];

extern void LCD_Display_8_16(U32 x,U32 y,U32 col,const unsigned char ch[]);
extern void LCD_Display_char(U32 x,U32 y,U32 col,char s);
extern void LCDDisplay_String(U32 x, U32 y, U32 col, char *s);//字符串显示函数
extern void LCD_Display_16x16(U32 x, U32 y, U32 col, const unsigned char ch[]);//汉字显示函数

#endif
