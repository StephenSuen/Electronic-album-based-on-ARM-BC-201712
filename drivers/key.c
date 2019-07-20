#include "key.h"
#include "s3c2451_lcd.h"
#include "s3c2451_uart.h"
extern const unsigned char  gImage_198_198_24[117612];
extern const unsigned char gImage_272_272_24[221952];
extern const unsigned char gImage_198_187_24[111078];
extern const unsigned char gImage_480_272_24[391680];
extern const unsigned char gImage_214_206_24[132252];

extern unsigned char fun;
int x0 = 0,y0 = 0,width,height;
static int Serial_number=0;
static int n_left = 0;//���ڼ�¼��ת���ڼ��Σ�ÿ����ת�ķ���Ϊ90��
extern int n_lcd;//���ڼ�¼�ò��ŵڼ���ͼƬ��
//====default_flag�����ڶ�n_lcd��������Զ�����if�����ʾ��һ��ͼƬ====
//static int k1_default_flag =0;
//static int k3_default_flag = 0;

unsigned char key_scan()
{
	unsigned char keyvalue;
	
	if(GPIO_readbit(GPIOF,GPIO_PIN0) == BIT_RESET)
	{
		delay_ms(10);//ȥ��ǰ�ض���
		if(GPIO_readbit(GPIOF,GPIO_PIN0) == BIT_RESET)
		{
			keyvalue = KEY1;
			//mode = 1;
			while((GPIO_readbit(GPIOF,GPIO_PIN0)) == BIT_RESET);
			delay_ms(10);
			while((GPIO_readbit(GPIOF,GPIO_PIN0)) == BIT_RESET);//����ȥ����
		}
	}
	else if(GPIO_readbit(GPIOF,GPIO_PIN1) == BIT_RESET)
	{
		delay_ms(10);//ȥ��ǰ�ض���
		if(GPIO_readbit(GPIOF,GPIO_PIN1) == BIT_RESET)
		{
			keyvalue = KEY2;
			//mode = 1;
			while((GPIO_readbit(GPIOF,GPIO_PIN1)) == BIT_RESET);
			delay_ms(10);
			while((GPIO_readbit(GPIOF,GPIO_PIN1)) == BIT_RESET);//����ȥ����
		}
	}
	else if(GPIO_readbit(GPIOF,GPIO_PIN2) == BIT_RESET)
	{
		delay_ms(10);//ȥ��ǰ�ض���
		if(GPIO_readbit(GPIOF,GPIO_PIN2) == BIT_RESET)
		{
			keyvalue = KEY3;
			//mode = 1;
			while((GPIO_readbit(GPIOF,GPIO_PIN2)) == BIT_RESET);
			delay_ms(10);
			while((GPIO_readbit(GPIOF,GPIO_PIN2)) == BIT_RESET);//����ȥ����
		}
	}
	else if(GPIO_readbit(GPIOF,GPIO_PIN3) == BIT_RESET)//����k4��������
	{
		delay_ms(10);//ȥ��ǰ�ض���
		if(GPIO_readbit(GPIOF,GPIO_PIN3) == BIT_RESET)//����k4�İ��£���ֹ�ఴ��Ҳ�������
		{
			keyvalue = KEY4;
			//mode = 1;
			while((GPIO_readbit(GPIOF,GPIO_PIN3)) == BIT_RESET);
			delay_ms(10);
			while((GPIO_readbit(GPIOF,GPIO_PIN3)) == BIT_RESET);//����ȥ����
		}
	}
	else//���4������û���£�ִ�����²���
	{
		keyvalue = 0;
		//mode = 0;
		//fun = 0;
		//return 0;
	}
	
	return keyvalue;
}

void KEY_LCD(int *flag,int *k1_default_flag,int *k3_default_flag,const unsigned char **ppicture,unsigned char keyvalue)//Һ����ʾ����
{
	if(n_lcd==-1) n_lcd = 0;
	if(n_left==-1) n_left=0;
	
	if(Serial_number ==-1) Serial_number =0;
	
	while(1)
	{
			if(GPIO_readbit(GPIOF,GPIO_PIN0) == BIT_RESET)//����k1��������,default_flag�����ڶ�n_lcd��������Զ�����if�����ʾ��һ��ͼƬ
			{
				delay_ms(10);
				if(GPIO_readbit(GPIOF,GPIO_PIN0) == BIT_RESET)
				{
					(n_lcd)++;
					if(n_lcd ==6)
					{
						n_lcd = 1;
						n_left = 0;
					}
					switch(n_lcd)
					{
						case 1:LCD_clear(YELLOW);n_left = 0;LCDDisplay_String(0, 0, BLUE, "1");LCD_displaypicture_24(150,50,198,187,gImage_198_187_24);
									*ppicture = gImage_198_187_24;x0 = 150;y0 = 50;width = 198;height = 187;Serial_number = 1;
						break;
						
						case 2:LCD_clear(YELLOW);n_left = 0;LCDDisplay_String(0, 0, BLUE, "2");LCD_displaypicture_24(150,50,198,198,gImage_198_198_24);
									*ppicture = gImage_198_198_24;x0 = 150;y0 = 50;width = 198;height = 198;Serial_number = 2;
						break;
						
						case 3:LCD_clear(YELLOW);n_left = 0;LCDDisplay_String(0, 0, BLUE, "3");LCD_displaypicture_24(103,0,272,272,gImage_272_272_24);
									*ppicture = gImage_272_272_24;x0 = 103;y0 = 0;width = 272;height = 272;Serial_number = 3;
						break;
						
						case 4:LCD_clear(YELLOW);n_left = 0;LCDDisplay_String(0, 0, BLUE, "4");LCD_displaypicture_24(0,0,480,272,gImage_480_272_24);
									*ppicture = gImage_480_272_24;x0 = 0;y0 = 0;width = 480;height = 272;Serial_number = 4;
						break;
						
						case 5:LCD_clear(YELLOW);n_left = 0;LCDDisplay_String(0, 0, BLUE, "5");LCD_displaypicture_24(150,30,214,206,gImage_214_206_24);
									*ppicture = gImage_214_206_24;x0 = 150;y0 = 30;width = 214;height = 206;Serial_number = 5;
						break;
						
						default:break;
					}
				}
				while((GPIO_readbit(GPIOF,GPIO_PIN0)) == BIT_RESET);
				delay_ms(10);
				while((GPIO_readbit(GPIOF,GPIO_PIN0)) == BIT_RESET);
			}
	
			if(GPIO_readbit(GPIOF,GPIO_PIN1) == BIT_RESET)//����k2��������
			{
				//uart_printf("\r\n*flag = %dǰ\n\r",*flag);
				*flag = 1;
				//uart_printf("\r\n*flag = %d��\n\r",*flag);
				while(*flag)
				{
					if(*flag)
					{
						LCD_clear(0);LCDDisplay_String(0, 0, 0xff, "1");
						LCD_displaypicture_24(150,50,198,187,gImage_198_187_24);
						*ppicture = gImage_198_187_24;x0 = 150;y0 = 50;width = 198;height = 187;Serial_number = 1;
						delay_ms(1500);
					}
					
					if(*flag)
					{
						LCD_clear(0);LCD_clear(0);LCDDisplay_String(0, 0, 0xff, "2");
						LCD_displaypicture_24(150,50,198,198,gImage_198_198_24);
						*ppicture = gImage_198_198_24;x0 = 150;y0 = 50;width = 198;height = 198;Serial_number = 2;
						delay_ms(1500);
					}
					
					if(*flag)
					{
						LCD_clear(0);LCD_clear(0);LCDDisplay_String(0, 0, 0xff, "3");
						LCD_displaypicture_24(103,0,272,272,gImage_272_272_24);
						*ppicture = gImage_272_272_24;x0 = 103;y0 = 0;width = 272;height = 272;Serial_number = 3;
						delay_ms(1500);
					}
				}
			}
	
			if(GPIO_readbit(GPIOF,GPIO_PIN2) == BIT_RESET)//����k3��������
			{
				delay_ms(10);
				if(GPIO_readbit(GPIOF,GPIO_PIN2) == BIT_RESET)
				{
					LCD_clear(YELLOW);
					(n_left)++;

					if(n_left == 5)
					{
						n_left = 1;
					}
					switch(n_left)
					{
						case 1:
							if(*ppicture == NULL) 
							{
								uart_printf("if�ж���\t\r\n");
								n_left = 0;
								break;
							}
							uart_printf("n_DISPIC-ǰ\t");
							LCD_displaypicture_24_left_reverse_90(x0,y0,width,height,*ppicture);
							uart_printf("n_DISPIC-��\t\r\n");
						break;//��תһ��-90��
					
						case 2:LCD_displaypicture_24_left_reverse_180(x0,y0,width,height,*ppicture);break;//��ת����-180��
						case 3:LCD_displaypicture_24_left_reverse_270(x0,y0,width,height,*ppicture);break; //��ת����-270��
						case 4:LCD_displaypicture_24(x0,y0,width,height,*ppicture);break;//��ת�Ĵ�-360��
						default:break;
					}
					uart_printf("Serial_number=%d\t",Serial_number);
					switch(Serial_number)
					{
						case 1:LCDDisplay_String(0, 0, 0xff, "1");break;
						case 2:LCDDisplay_String(0, 0, 0xff, "2");break;
						case 3:LCDDisplay_String(0, 0, 0xff, "3");break;
						default:break;
					}
					while((GPIO_readbit(GPIOF,GPIO_PIN2)) == BIT_RESET);
					delay_ms(10);
					while((GPIO_readbit(GPIOF,GPIO_PIN2)) == BIT_RESET);//����ȥ����
						//			LCD_clear(0);
						//			LCD_Display_char(100,100,BLUE,'a');delay_ms(1000);
						//			LCDDisplay_String(200, 100, 0xff, "01234567890123456789");
				}
			}
	
			if(GPIO_readbit(GPIOF,GPIO_PIN3) == BIT_RESET)//����k4��������
			{
				delay_ms(10);//ȥ��ǰ�ض���
				if(GPIO_readbit(GPIOF,GPIO_PIN3) == BIT_RESET)//����k4�İ��£���ֹ�ఴ��Ҳ�������
				{
					Interface();
					mode = 0;
					while((GPIO_readbit(GPIOF,GPIO_PIN3)) == BIT_RESET);
					delay_ms(10);
					while((GPIO_readbit(GPIOF,GPIO_PIN3)) == BIT_RESET);//����ȥ����
					break;
//					LCD_Display_16x16(32, 100,0xff0000,hanzi[0]);
//					LCD_Display_16x16(50, 100,0xff0000,hanzi[1]);
//					LCD_Display_16x16(68, 100,0xff0000,hanzi[2]);
//					delay_ms(1000);
					
				}
			}
			//		LCD_Display_16x16(86, 100,0xff0000,hanzi[6]);
			//		LCD_Display_16x16(104, 100,0xff0000,hanzi[7]);
	
	}//while
}


void key_e(void)//�����������ƽ�����˸
{
	GPIO_Init_Typedef gpio_init_typedef;
	BIT_typedef key1,key2,key3,key4;
	key1 = GPIO_readbit(GPIOF,GPIO_PIN0);
	key2 = GPIO_readbit(GPIOF,GPIO_PIN1);
	key3 = GPIO_readbit(GPIOF,GPIO_PIN2);
	key4 = GPIO_readbit(GPIOF,GPIO_PIN3);
	
	
	if(key1 == BIT_RESET)//����k1��������
	{
		gpio_init_typedef.mode = GPIO_MODE_OUT;
		gpio_init_typedef.udp = GPIO_UDP_UP;
		GPIO_INIT(GPIOB,GPIO_PIN5,gpio_init_typedef);
		
		GPIO_writebit(GPIOB,GPIO_PIN5,BIT_RESET);
		delay_ms(300);
		GPIO_writebit(GPIOB,GPIO_PIN5,BIT_SET);
	}
	else if(key2 == BIT_RESET)//����k2��������
	{
		gpio_init_typedef.mode = GPIO_MODE_OUT;
		gpio_init_typedef.udp = GPIO_UDP_UP;
		GPIO_INIT(GPIOB,GPIO_PIN6,gpio_init_typedef);
		
		GPIO_writebit(GPIOB,GPIO_PIN6,BIT_RESET);//����LED2
		delay_ms(300);
		GPIO_writebit(GPIOB,GPIO_PIN6,BIT_SET);
	}
	else if(key3 == BIT_RESET)//����k3��������
	{
		gpio_init_typedef.mode = GPIO_MODE_OUT;
		//gpio_init_typedef.udp = GPIO_UDP_UP;
		GPIO_INIT(GPIOA,GPIO_PIN25,gpio_init_typedef);
		
		GPIO_writebit(GPIOA,GPIO_PIN25,BIT_RESET);
		delay_ms(300);
		GPIO_writebit(GPIOA,GPIO_PIN25,BIT_SET);
	}
	else if(key4 == BIT_RESET)//����k4��������
	{
		gpio_init_typedef.mode = GPIO_MODE_OUT;
		//gpio_init_typedef.udp = GPIO_UDP_UP;
		GPIO_INIT(GPIOA,GPIO_PIN26,gpio_init_typedef);
		
		GPIO_writebit(GPIOA,GPIO_PIN26,BIT_RESET);
		delay_ms(300);
		GPIO_writebit(GPIOA,GPIO_PIN26,BIT_SET);
	}
}
