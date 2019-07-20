/*
整个工程的中断处理函数-_it代表interrupt的意思
*/

#include "s3c2451_it.h"
#include "main.h"
#include "s3c2451_adc.h"
#include "s3c2451_uart.h"
#include "s3c2451_lcd.h"
#include "stdio.h"
#include "typedef.h"
#include <string.h>

char temp[20];
U8 R_buffer[20]={0};
extern unsigned char fun;
extern unsigned char mode;
char str[20];

U8 hextobcd(U8 buf)
{
	if(buf > 0 && buf < 10)
	{
		return buf;
	}
	else if(buf >= 10 && buf < 20)
	{
		return buf+0x6;
	}
	else if(buf >= 20 && buf < 30)
	{
		return buf+0x6+0x6;
	}
	else if(buf >= 30 && buf < 40)
	{
		return buf+0x6+0x6+0x6;
	}
	else if(buf >= 40 && buf < 50)
	{
		return buf+0x6+0x6+0x6+0x6;
	}
	else if(buf >= 50)
	{
		return buf+0x6+0x6+0x6+0x6+0x6;
	}
	return 0;
}

void disply_num(int model,int num_shi,int num_ge)
{
	switch(model)
	{
		case 0://年
		{
			LCD_Display_char(120,100,BLUE,'0'+num_shi);
			LCD_Display_char(130,100,BLUE,'0'+num_ge);
		}break;
		case 1://月
		{
			LCD_Display_char(150,100,BLUE,'0'+num_shi);
			LCD_Display_char(160,100,BLUE,'0'+num_ge);
		}break;
		
		case 3://日
		{
			LCD_Display_char(190,100,BLUE,'0'+num_shi);
			LCD_Display_char(200,100,BLUE,'0'+num_ge);
		}break;
		
		case 4://时
		{
			LCD_Display_char(220,100,BLUE,'0'+num_shi);
			LCD_Display_char(230,100,BLUE,'0'+num_ge);
		}break;
		
		case 5://分
		{
			LCD_Display_char(250,100,BLUE,'0'+num_shi);
			LCD_Display_char(260,100,BLUE,'0'+num_ge);
		}break;
		
		case 6://秒
		{
			LCD_Display_char(280,100,BLUE,'0'+num_shi);
			LCD_Display_char(290,100,BLUE,'0'+num_ge);
		}break;
	}
	
}

void __irq UART0_IRQ()
{
	U8 rev_data;//char tt[50];int i;
	static int r_count = 0;
	int j,num = 0;;
	
	if(r_count == -1) r_count = 0;
	
	rev_data=uart_revdata(UART0);
	if(rev_data == 0xfe)
	{
		r_count = 0;
	}
	if(rev_data != 0xFE && rev_data != 0xEF)//代表接受到的不是包头也不是包尾
	{
		R_buffer[r_count]=rev_data;
		r_count++;
	}
	if(rev_data == 0XEF)//如果收到包尾就代表这一条指令已经接受完成，可以执行相应操作了
	{
		r_count = 0;
//		LCD_clear(0);
//		sprintf(tt, "%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x", 
//					R_buffer[0], R_buffer[1], R_buffer[2], R_buffer[3], R_buffer[4], R_buffer[5], R_buffer[6], R_buffer[7], R_buffer[8],
//					R_buffer[9], R_buffer[10], R_buffer[11], R_buffer[12], R_buffer[13], R_buffer[14], R_buffer[15], R_buffer[16], R_buffer[17], R_buffer[18], R_buffer[19]);
//		LCDDisplay_String(100,100,WHITE,tt);
//		
//		uart_printf("%s",tt);//00 03 00 f1 00 04 00 00 00 ff ff ff ff ff ff ff ff ff ff ff//数据位，不包括包头包尾
		
			if(R_buffer[1] == 0x3 && R_buffer[3] == 0xf1 && R_buffer[5] == 0x1 && R_buffer[7] == 0x1)
			{
				fun = 1;      	//开相册		
				mode = 3;
			}
			else if(R_buffer[1] == 0x3 && R_buffer[3] == 0xf1 && R_buffer[5] == 0x4 && R_buffer[7] == 0x1)
			{
				fun = 2;  //下一张
				mode = 3;
			}
			else if(R_buffer[1] == 0x3 && R_buffer[3] == 0xf1 && R_buffer[5] == 0x4 && R_buffer[7] == 0x0)
			{
				fun = 3;       //上一张
				mode = 3;
			}
			else if(R_buffer[1] == 0x3 && R_buffer[3] == 0xf1 && R_buffer[5] == 0x1 && R_buffer[7] == 0)
			{
				fun = 4;         //关相册
				mode = 2;
			}
			else if(R_buffer[1] == 0x7 && R_buffer[3] == 0xf0)
			{				
				RTC_struct_init rtc_struct_init;
				rtc_struct_init.year = hextobcd(R_buffer[5]);			
				rtc_struct_init.month = hextobcd(R_buffer[7]);
				rtc_struct_init.date = hextobcd(R_buffer[9]);
				rtc_struct_init.hour = hextobcd(R_buffer[11]);
				rtc_struct_init.minute = hextobcd(R_buffer[13]);
				rtc_struct_init.second = hextobcd(R_buffer[15]);
				RTC_set_time(rtc_struct_init);//设置时间
			}
			else if(R_buffer[1] == 0x3 && R_buffer[3] == 0xf1 && R_buffer[5] == 0x2)
			{
				shift_time = R_buffer[7];
				fun = 5;       //轮换
				mode = 3;
			}
			else if(R_buffer[1] == 0x03 && R_buffer[3] == 0xF2 && R_buffer[5] == 0x01)
			{
				if (R_buffer[7] == 0x01)
				{
					fun = 6;    //开字幕
					mode = 3;
					uart_printf("open zimu\r\n");
				}
				
				else if (R_buffer[7] == 0x00)
				{
					fun = 7;    //闭字幕
					mode = 3;
					
					uart_printf("close zimu\r\n");
				}
				
			}

			else if(R_buffer[3] == 0xf2 && R_buffer[5] == 0x3)
			{
				fun = 8;         //修改字幕
				mode = 3;
				
				num = (hextobcd(R_buffer[1])/16)*10 + (hextobcd(R_buffer[1])%16);
				for (j = 0; j < num; j++)
				{
					temp[j] = R_buffer[7+j*2];
				}
				
				temp[j] = '\0';
				sprintf(str, "%s", temp);
				memset(R_buffer, 0,sizeof(R_buffer));
				uart_printf("revise zimu\r\n");
			}
			
			else if(R_buffer[1] == 0x03 && R_buffer[3] == 0xF2 && R_buffer[5] == 0x02)
			{
				if (R_buffer[7] == 0x01)
				{
					fun = 9;    //右移
					mode = 3;
					uart_printf("right move\r\n");
				}
				
				else if (R_buffer[7] == 0x00)
				{
					fun = 10;    //左移
					mode = 3;
					uart_printf("left move\r\n");
				}
			}
			
//		for(i = 0;i<20;i++)
//		{
//			R_buffer[i] = 0;
//		}
		
		
	}
	
	UFCON0 |= 0X1;//使能FIFO
		UFCON0 |= 0X2;//Rx FIFO 复位
		UFCON0 &= ~0X2;//Rx FIFO 正常
		
	
	IRQ_ClearSRCPND(INT_UART0);//当中断响应后，SRCPND自动置为1表示不响应其余任何中断，再次置1后相当于允许接收下一次中断
	IRQ_ClearSUBSRCPND(SUB_INT_RXD0);//只要RXD0,TXD0,ERR0三个任何一个清除状态，UART0都会接收下一次中断
}

void __irq TIMER0_IRQ()
{
	BIT_typedef key1;
	
		key1 = GPIO_readbit(GPIOF,GPIO_PIN0);
		if(key1 == BIT_RESET)
		{
			flag = 0;
		}
		if(GPIO_readbit(GPIOF,GPIO_PIN3) == BIT_RESET)
		{
			display_time_flag = 0;
		}
		
		
	//
	
	//	uart_printf("hello word\t");
		IRQ_ClearSRCPND(INT_TIMER0);
//	}
}

void __irq TIMER1_IRQ()
{
	//
	
}

void __irq ADC_IRQ()
{
	
//	uart_printf("%d.%d%d%dV\t",ADC_temp/1000,ADC_temp/100%10,ADC_temp/10%10,ADC_temp%10);
//	uart_printf("hello word\t");
//	IRQ_ClearSRCPND(INT_ADC);
//	IRQ_ClearSUBSRCPND(SUBINT_ADC);
}

/*
model:
0:year
1:month;
2:day;//周几
3:date;//几号
	
4:hour;
5:minute;
6:second;
*/
void __irq TICK_IRQ()//滴答中断
{
	//RTC_struct_init rtc_struct_init,pre_time;
	System_led();
//	if(rtc_flag == -1)
//	{
//		//uart_printf("\n\rrtc_flag = %d\n\r",rtc_flag);
//		pre_time.year = 0x00;
//		pre_time.month = 0x00;
//		pre_time.date = 0x00;
//		pre_time.day = 0x00;
//		
//		pre_time.hour = 0x25;
//		pre_time.minute = 0x61;
//		pre_time.second = 0x61;
//		
//		rtc_flag = 0;
//	}
//	//gettime读取需要时间，所以初始化的时候填63大约滴答中断一次需要0.5s，填127是1s，加上gettime从芯片2451RTC读取数据的时间，差不多1s一次中断
//	RTC_get_time(&rtc_struct_init);

////	uart_printf("%04x-%02x-%02x %02x:%02x:%02x,周%x\n",rtc_struct_init.year,rtc_struct_init.month,rtc_struct_init.date,rtc_struct_init.hour,rtc_struct_init.minute,rtc_struct_init.second,rtc_struct_init.day);
////	LCD_clear(0);

//	LCDDisplay_String(100,100,BLUE,"20");
//	
//	
//	if(pre_time.year != rtc_struct_init.year)
//	{
//		LCD_rectangle_8_16(120,100);
//		LCD_rectangle_8_16(130,100);
//	}
//	disply_num(0,rtc_struct_init.year/16,rtc_struct_init.year%16);
//	pre_time.year = rtc_struct_init.year;
//	LCDDisplay_String(140,100,BLUE,"-");
//	
//	if(pre_time.month != rtc_struct_init.month)
//	{
//		LCD_rectangle_8_16(150,100);
//		LCD_rectangle_8_16(160,100);
//	}
//	disply_num(1,rtc_struct_init.month/16,rtc_struct_init.month%16);//月
//	pre_time.month = rtc_struct_init.month;
//	LCDDisplay_String(175,100,BLUE,"-");
//	
//	if(pre_time.date != rtc_struct_init.date)
//	{
//		LCD_rectangle_8_16(190,100);
//		LCD_rectangle_8_16(200,100);
//	}
//	disply_num(3,rtc_struct_init.date/16,rtc_struct_init.date%16);//日
//	pre_time.date = rtc_struct_init.date;
//	LCDDisplay_String(210,100,BLACK," ");
//	
//	if(pre_time.hour != rtc_struct_init.hour)
//	{
//		LCD_rectangle_8_16(220,100);
//		LCD_rectangle_8_16(230,100);
//	}
//	disply_num(4,rtc_struct_init.hour/16,rtc_struct_init.hour%16);//时
//	pre_time.hour = rtc_struct_init.hour;
//	LCDDisplay_String(240,100,BLUE,":");
//	
//	if(pre_time.minute != rtc_struct_init.minute)
//	{
//		LCD_rectangle_8_16(250,100);
//		LCD_rectangle_8_16(260,100);
//	}
//	disply_num(5,rtc_struct_init.minute/16,rtc_struct_init.minute%16);//分
//	pre_time.minute = rtc_struct_init.minute;
//	LCDDisplay_String(270,100,BLUE,":");
//	
//	if(pre_time.second != rtc_struct_init.second)
//	{
//		LCD_rectangle_8_16(280,100);
//		LCD_rectangle_8_16(290,100);
//	}
//	disply_num(6,rtc_struct_init.second/16,rtc_struct_init.second%16);//秒
//	pre_time.second = rtc_struct_init.second;
	
	IRQ_ClearSRCPND(INT_TICK);
}
