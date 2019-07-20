#include "main.h"
	
	int flag = 0;
//	int n_lcd = 0;
	extern const unsigned char gImage_439_126_24[165942];
extern	const unsigned char gImage_407_89_24[108669];
extern const unsigned char gImage_474_88_24[125136];
extern const unsigned char  gImage_198_198_24[117612];
extern const unsigned char gImage_272_272_24[221952];
extern const unsigned char gImage_198_187_24[111078];
extern const unsigned char gImage_480_272_24[391680];
extern const unsigned char gImage_214_206_24[132252];
	int n_lcd;
	int rtc_flag = 0;
	int display_time_flag = 0;
	unsigned char fun = 0;
	unsigned char mode;//mode = 1:���ģʽ   mode = 2��ʱ��ģʽ
	int shift_time = 1;//�ֻ�ʱ��
//void delay(volatile int count)
//{
//	while (count--);
//}

//void delay_ms(unsigned long xms)
//{
//	unsigned long j;
//	for(;xms>0;xms--)
//	{
//		for(j=500;j>0;j--);
//	}
//}
void Interface(void)
{
	LCD_clear(WHITE);	
	LCD_displaypicture_24(20,2,439, 126,gImage_439_126_24);
	
	
	LCD_Display_16x16(65, 150,BLACK,hanzi[7]);
	LCD_Display_16x16(85, 150,BLACK,hanzi[8]);
	LCDDisplay_String(105, 150, BLACK, "1");
	LCDDisplay_String(115, 150, BLACK, ":");
	LCD_Display_16x16(125, 150,RED,hanzi[9]);
	LCD_Display_16x16(145, 150,RED,hanzi[10]);
	
	LCD_Display_16x16(65+250, 150,BLACK,hanzi[7]);
	LCD_Display_16x16(85+250, 150,BLACK,hanzi[8]);
	LCDDisplay_String(105+250, 150, BLACK, "2");
	LCDDisplay_String(115+250, 150, BLACK, ":");
	LCD_Display_16x16(125+250, 150,RED,hanzi[11]);
	LCD_Display_16x16(145+250, 150,RED,hanzi[12]);
//	
	LCD_Display_16x16(65+230, 220,BLACK,hanzi[13]);
	LCD_Display_16x16(85+230, 220,BLACK,hanzi[14]);
	LCD_Display_16x16(105+230, 220,BLACK,hanzi[15]);
	LCDDisplay_String(125+230,220,BLACK,":");
	LCD_Display_16x16(135+230, 220,BLACK,hanzi[0]);
	LCD_Display_16x16(155+230, 220,BLACK,hanzi[1]);
	LCD_Display_16x16(175+230, 220,BLACK,hanzi[2]);
	
}
void Main(void)
{
	const unsigned char *picture= NULL;
	int k1_default_flag =0;
	int k3_default_flag = 0;unsigned char keyvalue;
//	int pic_start_flag=0;
	static int n_com = 0;
//	char tt[50];
	//static int n_com_jian = 6;
//	U32 ADC_temp;
	
	UART_init_typedef uart_init_typedef;
	TIM_init_typedef tim_init_typedef;
//	TIM_init_typedef tim1_init_typedef;
	GPIO_Init_Typedef gpio_init_typedef;
	RTC_struct_init rtc_struct_init,pre_time;
	lcd_init();
//	led_init();//������Ƴ�ʼ������
//=================���ư����ĳ�ʼ������===============
	gpio_init_typedef.mode = GPIO_MODE_IN;
	GPIO_INIT(GPIOF,GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3,gpio_init_typedef);//��GPF0��Ϊ����ģʽ
//=====================================================
	
//===========GPIO����led��˸��ʼ������===============
	gpio_init_typedef.udp = GPIO_UDP_UP;
	gpio_init_typedef.mode = GPIO_MODE_OUT;
	//gpio_init_typedef.pinx=GPIO_PIN25|GPIO_PIN26;
	GPIO_INIT(GPIOA,GPIO_PIN25|GPIO_PIN26,gpio_init_typedef);
//	gpio_init_typedef.pinx=GPIO_PIN5|GPIO_PIN6;
	GPIO_INIT(GPIOB,GPIO_PIN5|GPIO_PIN6,gpio_init_typedef);
//===========================================
	
//===============��������ʼ��===================
	gpio_init_typedef.mode = GPIO_MODE_OUT;
	//gpio_init_typedef.pinx = GPIO_PIN0;
	GPIO_INIT(GPIOB,GPIO_PIN0,gpio_init_typedef);
//==============================================

//=============���ڳ�ʼ��=====================
	uart_init_typedef.baudrate = 115200;
	uart_init_typedef.mode=mode_rx_tx;
	uart_init_typedef.wordwidth = wordwidth_8bit;
	uart_init_typedef.stop =stop_one;
	uart_init_typedef.parity=parity_no;
	uart_init(UART0,uart_init_typedef);
	
	UART_interrupt_init(UART0,(U32)UART0_IRQ);
	IRQ_INTMask_init(INT_UART0,ENABLE);
	IRQ_INTSUBMask_init(SUB_INT_RXD0,ENABLE);
//==========================================

//==============��ʱ��0��ʼ������============
	TIM0_init(time_ch0,tim_init_typedef);
	TIM_interrupt_init(time_ch0,(U32)TIMER0_IRQ);
	IRQ_INTMask_init(INT_TIMER0,ENABLE);
//==========================================

//==============��ʱ��1��ʼ������============
//	TIM1_init(time_ch1,tim1_init_typedef);
//	TIM_interrupt_init(time_ch1,(U32)TIMER1_IRQ);
//	IRQ_INTMask_init(INT_TIMER1,ENABLE);
//==========================================
	LCD_clear(0);
	
//=========ADC��ʼ������====================
//	ADC_init(AIN_ch0,ADC_10bit_mode);
//	ADC_interrupt_init(AIN_ch0,(U32)ADC_IRQ);
//	IRQ_INTMask_init(INT_ADC,ENABLE);
//	IRQ_INTSUBMask_init(SUBINT_ADC,ENABLE);
//==========================================
	
//=============RTC��ʼ������===============
//	rtc_struct_init.year = 0x17;
//	rtc_struct_init.month = 0x8;
//	rtc_struct_init.day = 0x2;
//	rtc_struct_init.date = 0x8;
//	rtc_struct_init.hour = 0x19;
//	rtc_struct_init.minute =0x05;
//	rtc_struct_init.second = 0x10;
//	RTC_set_time(rtc_struct_init);
//	
	RTC_interrupt_init(63,ENABLE);
	TICK_IRQ_init((U32)TICK_IRQ);
	IRQ_INTMask_init(INT_TICK,ENABLE);//
//=========================================
	Interface();
	
	if(shift_time == -1) shift_time = 1;
	while(1)
	{
		keyvalue = key_scan();
//		if(keyvalue == KEY4)
//		{
//			Interface();
//			mode = 0;
//		}
		
		if(keyvalue == KEY1)
		{
			mode = 1;
		}
		else if(keyvalue == KEY2)
		{
			mode = 2;
		}
		
		if(mode == 1)
		{
			LCD_clear(WHITE);	
			LCD_displaypicture_24(25,50,407,89,gImage_407_89_24);
			KEY_LCD(&flag,&k1_default_flag,&k3_default_flag,&picture,keyvalue);
		}
		if(mode == 2)//����������ģʽ����ȴ�5s���ҽ���ʱ��ģʽ
		{
			//pic_start_flag = 0;
				if(fun == 4)
				{
					fun = 0;
				}
				display_time_flag = 1;LCD_clear(BLACK);
				while(display_time_flag)
				{
					if(mode == 3&&fun == 1)//�������������˳�ʱ��ģʽ
					{
						//mode = 0;
						break;
					}
						if(rtc_flag == -1)
						{
							//uart_printf("\n\rrtc_flag = %d\n\r",rtc_flag);
							pre_time.year = 0x00;
							pre_time.month = 0x00;
							pre_time.date = 0x00;
							pre_time.day = 0x00;
							
							pre_time.hour = 0x25;
							pre_time.minute = 0x61;
							pre_time.second = 0x61;
							
							rtc_flag = 0;
						}
						//gettime��ȡ��Ҫʱ�䣬���Գ�ʼ����ʱ����63��Լ�δ��ж�һ����Ҫ0.5s����127��1s������gettime��оƬ2451RTC��ȡ���ݵ�ʱ�䣬���1sһ���ж�
						RTC_get_time(&rtc_struct_init);

						LCDDisplay_String(100,100,BLUE,"20");
						if(pre_time.year != rtc_struct_init.year)
						{
							LCD_rectangle_8_16(120,100);
							LCD_rectangle_8_16(130,100);
						}
						disply_num(0,rtc_struct_init.year/16,rtc_struct_init.year%16);
						pre_time.year = rtc_struct_init.year;
						LCDDisplay_String(140,100,BLUE,"-");
						
						if(pre_time.month != rtc_struct_init.month)
						{
							LCD_rectangle_8_16(150,100);
							LCD_rectangle_8_16(160,100);
						}
						disply_num(1,rtc_struct_init.month/16,rtc_struct_init.month%16);//��
						pre_time.month = rtc_struct_init.month;
						LCDDisplay_String(175,100,BLUE,"-");
						
						if(pre_time.date != rtc_struct_init.date)
						{
							LCD_rectangle_8_16(190,100);
							LCD_rectangle_8_16(200,100);
						}
						disply_num(3,rtc_struct_init.date/16,rtc_struct_init.date%16);//��
						pre_time.date = rtc_struct_init.date;
						LCDDisplay_String(210,100,BLACK," ");
						
						if(pre_time.hour != rtc_struct_init.hour)
						{
							LCD_rectangle_8_16(220,100);
							LCD_rectangle_8_16(230,100);
						}
						disply_num(4,rtc_struct_init.hour/16,rtc_struct_init.hour%16);//ʱ
						pre_time.hour = rtc_struct_init.hour;
						LCDDisplay_String(240,100,BLUE,":");
						
						if(pre_time.minute != rtc_struct_init.minute)
						{
							LCD_rectangle_8_16(250,100);
							LCD_rectangle_8_16(260,100);
						}
						disply_num(5,rtc_struct_init.minute/16,rtc_struct_init.minute%16);//��
						pre_time.minute = rtc_struct_init.minute;
						LCDDisplay_String(270,100,BLUE,":");
						
						if(pre_time.second != rtc_struct_init.second)
						{
							LCD_rectangle_8_16(280,100);
							LCD_rectangle_8_16(290,100);
						}
						disply_num(6,rtc_struct_init.second/16,rtc_struct_init.second%16);//��
						pre_time.second = rtc_struct_init.second;
				}
				
				if(mode == 2)
				{
				Interface();mode = 0;
				}
		}
		
		if(mode == 3)//����ģʽ
		{
			mode = 0;
			if(fun == 1)//�������
			{
				fun = 0;//pic_start_flag =1;
				LCD_clear(WHITE);	
				LCD_displaypicture_24(25,50,407,89,gImage_407_89_24);
			}
			if(fun == 2)//��һ��
			{
				//pic_start_flag = 0;
				fun = 0;
				(n_com)++;
					if(n_com ==6)
					{
						n_com = 1;
					}
					switch(n_com)
					{
						case 1:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "1");LCD_displaypicture_24(150,50,198,187,gImage_198_187_24);		
						break;
						
						case 2:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "2");LCD_displaypicture_24(150,50,198,198,gImage_198_198_24);					
						break;
						
						case 3:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "3");LCD_displaypicture_24(103,0,272,272,gImage_272_272_24);
						break;
						
						case 4:LCD_clear(YELLOW);LCD_displaypicture_24(0,0,480,272,gImage_480_272_24);LCDDisplay_String(0, 0, YELLOW, "4");
						break;
						
						case 5:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "5");LCD_displaypicture_24(150,30,214,206,gImage_214_206_24);
						break;
						default:break;
					}
			//	LCD_clear(WHITE);	
			//	LCDDisplay_String(105, 150, BLACK, "MODE OF PICTURE IS OPENED");
			}
			if(fun == 3)//��һ��
			{
				//pic_start_flag = 0;
				fun = 0;
				(n_com)--;
					if(n_com ==0)
					{
						n_com = 5;
					}
					switch(n_com)
					{
						case 1:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "1");LCD_displaypicture_24(150,50,198,187,gImage_198_187_24);
								
						break;
						
						case 2:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "2");LCD_displaypicture_24(150,50,198,198,gImage_198_198_24);
									
						break;
						
						case 3:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "3");LCD_displaypicture_24(103,0,272,272,gImage_272_272_24);
								
						break;
						
						case 4:LCD_clear(YELLOW);LCDDisplay_String(0, 0, YELLOW, "4");LCD_displaypicture_24(0,0,480,272,gImage_480_272_24);
						break;
						
						case 5:LCD_clear(YELLOW);LCDDisplay_String(0, 0, BLUE, "5");LCD_displaypicture_24(150,30,214,206,gImage_214_206_24);
						break;
						
						default:break;
					}
			//	LCD_clear(WHITE);	
		//		LCDDisplay_String(105, 150, BLACK, "MODE OF PICTURE IS OPENED");
			}
			
			if(fun == 5)//�ֻ�
			{
				//LCD_clear(WHITE);	
				fun = 0;
//				sprintf(tt, "%02x",shift_time);
//				LCDDisplay_String(100,100,BLUE,tt);
				while(flag)
				{
					if(flag)
					{
						LCD_clear(0);LCDDisplay_String(0, 0, 0xff, "1");
						LCD_displaypicture_24(150,50,198,187,gImage_198_187_24);
						
						delay_ms(1500);
					}
					
					if(flag)
					{
						LCD_clear(0);LCD_clear(0);LCDDisplay_String(0, 0, 0xff, "2");
						LCD_displaypicture_24(150,50,198,198,gImage_198_198_24);
						
						delay_ms(1500);
					}
					
					if(flag)
					{
						LCD_clear(0);LCD_clear(0);LCDDisplay_String(0, 0, 0xff, "3");
						LCD_displaypicture_24(103,0,272,272,gImage_272_272_24);
						
						delay_ms(1500);
					}
				}
//				LCD_displaypicture_24(10,50,474,88,gImage_474_88_24);
			}
		}
	//	LCD_rectangle_8_16(280,100);
		//========ADC����===========
//		ADC_temp = ADC_get_value(AIN_ch0)*3300/1024;
//		uart_printf("%d.%d%d%dV\t",ADC_temp/1000,ADC_temp/100%10,ADC_temp/10%10,ADC_temp%10);
//		delay_ms(1000);
		//===========================
		
		
		
		
		//==============��ʱ������==================
//		if(TIM_getcount(time_ch0) == 20625)//0.5sִ��һ�β���,��41250����20625��Ҫ0.5s
//		{
//			GPIO_writebit(GPIOB,GPIO_PIN5,BIT_RESET);//����LED1
//			//GPIO_writebit(GPIOB,GPIO_PIN0,BIT_SET);//��
//		}
//		
//		if(TIM_getcount(time_ch0) == 0)//��20625����0��Ҫ0.5s����41250����0��Ҫ1s
//		{
//			GPIO_writebit(GPIOB,GPIO_PIN5,BIT_SET);//��LED1
//		//	GPIO_writebit(GPIOB,GPIO_PIN0,BIT_RESET);//����
//		}
		//==============================================
		
		//=======���ڷ���hello word===========
//		uart_printf("hello word\n");
//		delay_ms(500);
		//====================================
		
		//====�������==========
		//liushuideng();
		///led_2();	
		//beep_init();
		//======================
		
//============GPIO����led��˸===============
//		GPIO_writebit(GPIOA,GPIO_PIN25,BIT_SET);
//		GPIO_writebit(GPIOA,GPIO_PIN26,BIT_SET);
		//GPIO_writebit(GPIOB,GPIO_PIN5,BIT_SET);//��LED1
//		GPIO_writebit(GPIOB,GPIO_PIN6,BIT_SET);//LED2
//		delay_ms(1000);
//		
//		GPIO_writebit(GPIOA,GPIO_PIN25,BIT_RESET);
//		GPIO_writebit(GPIOA,GPIO_PIN26,BIT_RESET);
//		GPIO_writebit(GPIOB,GPIO_PIN5,BIT_RESET);//����LED1
//		GPIO_writebit(GPIOB,GPIO_PIN6,BIT_RESET);
//		delay_ms(1000);
//==========================================
		
//===============������===================
//		GPIO_writebit(GPIOB,GPIO_PIN0,BIT_SET);//��
//		delay_ms(1000);
//		GPIO_writebit(GPIOB,GPIO_PIN0,BIT_RESET);//����
//		delay_ms(1000);
//========================================
		
		//key_e();
		
//		uart_senddata('a');
//		delay_ms(500);
//		uart_senddata('b');
//		delay_ms(500);

//===============���ڿ���LED====================pc����a/b/c/d�����Ӧ������e����������죬��д�������Ͳ���
//		temp = uart_revdata(UART0);
//		if(temp)
//		{
//			uart_senddata(UART0,temp);
//			delay_ms(500);
//		}
//		
//		switch(temp)
//		{
//			case 'a':{
//				GPIO_writebit(GPIOB,GPIO_PIN5,BIT_RESET);}break;
//			case 'b':{
//				GPIO_writebit(GPIOB,GPIO_PIN6,BIT_RESET);}break;
//			case 'c':{
//				GPIO_writebit(GPIOA,GPIO_PIN25,BIT_RESET);}break;
//			case 'd':{
//				GPIO_writebit(GPIOA,GPIO_PIN26,BIT_RESET);}break;
//			case 'e':{
//					GPIO_writebit(GPIOB,GPIO_PIN0,BIT_SET);}break;
//			
//			case 'A':{
//				GPIO_writebit(GPIOB,GPIO_PIN5,BIT_SET);}break;
//			case 'B':{
//				GPIO_writebit(GPIOB,GPIO_PIN6,BIT_SET);}break;
//			case 'C':{
//				GPIO_writebit(GPIOA,GPIO_PIN25,BIT_SET);}break;
//			case 'D':{
//				GPIO_writebit(GPIOA,GPIO_PIN26,BIT_SET);}break;
//			case 'E':{
//				GPIO_writebit(GPIOB,GPIO_PIN0,BIT_RESET);}break;
//		}
//===============================================================

			//delay_ms(500);
	}
}
