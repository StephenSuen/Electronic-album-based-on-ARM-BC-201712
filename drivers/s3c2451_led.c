#include "s3c2451_led.h"


void led_init(void)
{
	GPACON &= ~(0X3<< 25);//将GPACON 口的25/26位置0，将GPA25/GPA26设为输出模式
	GPBCON &=~(0XF<<10);//先将B控制口的10-13位置0
	GPBCON |= (0X5<<10);//只改变GPB5/GPB6对应的10-13位的值，将GPB5/GPB6设为输出模式
	
	//GPB0对应蜂鸣器，1蜂鸣器响，0关闭蜂鸣器
	GPBCON &=~0X03;//将GPB0对应的0-1位置为0
	GPBCON |= 0X01;//将GPB0的0-1位置为01，设置GPB0口为输出模式
}
void liushuideng(void)//LED1->LED4循环点亮
{
	LEDB_ON(5);//点亮LED1
	delay_ms(1000);
	LEDB_OFF(5);//熄灭LED1
	
	
	LEDB_ON(6);//点亮LED2
	delay_ms(1000);
	LEDB_OFF(6);//熄灭LED2
	
	
	LEDA_ON(25);//点亮LED3
	delay_ms(1000);
	LEDA_OFF(25);//熄灭LED3
	
	
	LEDA_ON(26);//点亮LED4
	delay_ms(1000);
	LEDA_OFF(26);//熄灭LED4
	
	
}

void led_2(void)//LED1->LED4依次点亮,然后全熄灭，2s后再次依次点亮
{
	LEDB_ON(5);//点亮LED1
	delay_ms(1000);
	
	LEDB_ON(6);//点亮LED2
	delay_ms(1000);
	
	LEDA_ON(25);//点亮LED3
	delay_ms(1000);
	
	LEDA_ON(26);//点亮LED4
	delay_ms(1000);
	
	LEDB_OFF(5);//熄灭LED1
	LEDB_OFF(6);//熄灭LED2
	LEDA_OFF(25);//熄灭LED3
	LEDA_OFF(26);//熄灭LED4
	delay_ms(2000);
	
}

void System_led(void)//LED1->LED4依次点亮,然后全熄灭，2s后再次依次点亮
{
	LEDB_ON(5);//亮LED1
	delay_ms(200);
	
	LEDB_OFF(5);
	delay_ms(200);
	
	LEDB_ON(5);
	delay_ms(200);
	
	LEDB_OFF(5);
	delay_ms(600);
}

void beep_init(void)
{
	BEEPGPB_ON(0);//OPEN BEEP
	delay_ms(100);//响某S
	BEEPGPB_OFF(0);//CLOSE BEEP
	delay_ms(1000);//静 某S

}
