#include "s3c2451_lcd.h"
#include "s3c2451_gpio.h"
#include "s3c2451_led.h"

unsigned int FRAME_BUFFER[LCD_Y][LCD_X];
extern unsigned int choose_mode;

void lcd_init(void)
{
    //端口复用设置
	GPCCON = 0xaaaaaaaa;//使其初始化为RGB
	GPDCON = 0xaaaaaaaa;
	 //背光控制
	GPBCON &= ~(0x3 << 2);				 //打开LCD背光，设置GPB1为输出，并设置为高电平
	GPBCON |=	(0x1 << 2);
	GPBDAT |= (0x1 << 1);

    //电源控制
	GPGCON &= ~(0x3<<4);
	GPGCON |= (1<<4);
	GPGDAT |= (1<<2);
	// 配置VIDCONx，设置接口类型、时钟、极性和使能LCD控制器等
	VIDCON0 = 0;
	VIDCON0 |= (0x0 << 22) | (0x0 << 13) | (9 << 6) | (1 << 5) | (1 << 4) |(0 << 2)| (0x3 << 0);
	
	VIDCON1 = 0;
	VIDCON1 |= (1 << 6) | (1 << 5);
		// 配置VIDTCONx，设置时序和长宽等
	// 设置时序
	VIDTCON0 = 0;
	VIDTCON1 = 0;
	VIDTCON0 |= (VBPD << 16) | (VFPD << 8) | (VSPW << 0);
	VIDTCON1 |= (HBPD << 16) | (HFPD << 8) | (HSPW << 0);
	// 设置长宽
	VIDTCON2 = 0;
	VIDTCON2 |= (LINEVAL << 11) | (HOZVAL << 0);
	 	// 配置WINCON0，设置window0的数据格式
	WINCON0 = 0;
	WINCON0 |= (0xb << 2) | (1 << 0);

		// 配置VIDOSD0A/B/C,设置window0的坐标系
	VIDOSD0A = 0;
	VIDOSD0A |= (LeftTopX << 11) | (LeftTopY << 0);
	VIDOSD0B = 0;
	VIDOSD0B |= (RightBotX << 11) | (RightBotY << 0);
	// 置VIDW00ADD0B0和VIDW00ADD1B0，设置framebuffer的地址
	VIDW00ADD0B0 = (unsigned long)FRAME_BUFFER;	
	VIDW00ADD1B0 = (unsigned long)FRAME_BUFFER + sizeof(FRAME_BUFFER);
	//VIDW00ADD2B0 = (unsigned long)sizeof(FRAME_BUFFER);
}

void LCD_putpixe(U32 x, U32 y,U32 c)//x列y行
{
	if(x >= LCD_X||y>=LCD_Y)
	{return;}
	LCD_BUFFER[y][x] = c;//y行x列
}

void LCD_clear(U32 c)
{
	U32 x,y;
//	LCD_GPIO_Init();
	lcd_init();
	
	for(y = 0;y<LCD_Y;y++)
	{
		for(x = 0;x<LCD_X;x++)
		{
			LCD_BUFFER[y][x] = c;
		}
	}
}

void LCD_rectangle_8_16(U32 x0,U32 y0)//
{
	int i,j;
//	LCD_clear(0);
	
	for(i = 0;i<8;i++)//内部填充
	{
		for(j = 0;j<16;j++)
		{
			LCD_putpixe(x0+i,y0+j,BLACK);
		}
	}
}

void LCD_rectangle()//长方形，只有外部框架，内部不填充
{
	int i,j;
	LCD_clear(0);
	
//	for(i = 200;i<300;i++)//内部填充
//	{
//		for(j = 50;j<200;j++)
//		{
//			LCD_putpixe(i,j,BLUE);
//		}
//	}
	
	for(j = 50;j<200;j++)//在200列和299列各画一条从50行到199行的竖线
	{
		LCD_putpixe(200,j,BLUE);
		LCD_putpixe(299,j,BLUE);
	}
	
	for(i = 200;i<300;i++)//在50和199行各画一条从200列到299列的横线
	{
		LCD_putpixe(i,50,BLUE);
		LCD_putpixe(i,199,BLUE);
	}
}

void LED_circle(U32 x,U32 y,unsigned int r)//在x列y行画一个半径为r的圆
{
	int i,j,m2,r2;
	LCD_clear(0);
	LCD_putpixe(x,y,WHITE);
	
	for(i = 0;i<LCD_X;i++)
	{
		for(j =0;j<LCD_Y;j++)
		{
			m2 = ((i-x)*(i-x))+((j-y)*(j-y));
			r2 = r*r;
			
			if((m2>(r2*0.979))&&(m2<(r2*1.015)))
			{
				LCD_putpixe(i,j,YELLOW);
			}
		}
	}
}

void LCD_displaypicture_32(int x0,int y0,int w, int h,const unsigned char *picture)//32位真彩色
{
	U32 x,y,c,i=0;
	
	for(y = 0;y<h;y++)
	{
		for(x = 0;x<w;x++)
		{
			c = picture[i]<<24|picture[i+1]<<16|picture[i+2]<<8|picture[i+3];
			LCD_putpixe(x0+x,y0+y,c);
			i+=4;
		}
	}
}

void LCD_displaypicture_24(int x0,int y0,int w, int h,const unsigned char *picture)//24位真彩色
{
	U32 x,y,c,i=0;
	
	for(y = 0;y<h;y++)
	{
		for(x = 0;x<w;x++)
		{
			c = picture[i]<<16|picture[i+1]<<8|picture[i+2];
			LCD_putpixe(x0+x,y0+y,c);
			i+=3;
		}
	}
}

//24位真彩色反转-左转90度
void LCD_displaypicture_24_left_reverse_90(int x0,int y0,int w, int h,const unsigned char *picture)
{
	U32 x,y,c,i=0;
	
	for(y = 0;y<h;y++)
	{
		for(x = 0;x<w;x++)
		{
			c = picture[i]<<16|picture[i+1]<<8|picture[i+2];
			LCD_putpixe(x0+y,y0+w-x-1,c);
			i+=3;
		}
	}
}

//左转180度
void LCD_displaypicture_24_left_reverse_180(int x0,int y0,int w, int h,const unsigned char *picture)
{
	U32 x,y,c,i=0;
	
	for(y = 0;y<h;y++)
	{
		for(x = 0;x<w;x++)
		{
			c = picture[i]<<16|picture[i+1]<<8|picture[i+2];
			LCD_putpixe(x0+w-x-1,y0+h-y-1,c);
			i+=3;
		}
	}
}

//左转270度或者右转90度
void LCD_displaypicture_24_left_reverse_270(int x0,int y0,int w, int h,const unsigned char *picture)
{
	U32 x,y,c,i=0;
	
	for(y = 0;y<h;y++)
	{
		for(x = 0;x<w;x++)
		{
			c = picture[i]<<16|picture[i+1]<<8|picture[i+2];
			LCD_putpixe(x0+h-y-1,y0+x,c);
			i+=3;
		}
	}
}

void LCD_Display_8_16(U32 x,U32 y,U32 col,const unsigned char ch[])//8*16的字符显示
{
	unsigned int i,j;
	unsigned int mask,tem;
	
	for(j = 0;j<16;j++)
	{
		mask = 0x80;
		tem = ch[j];
		for(i = 0;i<8;i++)
		{
			if(mask&tem)
			{
				LCD_putpixe(x+i,y+j,col);
			}
			mask = mask>>1;
		}
	}
}

void LCD_Display_char(U32 x,U32 y,U32 col,char s)
{
//	LCD_clear(0);
	LCD_Display_8_16(x,y,col,ch[s-' ']);
}
void LCDDisplay_String(U32 x, U32 y, U32 col, char *s)//字符串显示函数
{
	U16 xpos =x;
	while(*s != '\0')
	{
			LCD_Display_char(xpos,y, col, *s);
			xpos+=8;
		s++;
	}
}

void LCD_Display_16x16(U32 x, U32 y, U32 col, const unsigned char ch[])//汉字显示函数
{
    unsigned short i, j ;
    unsigned char mask, tem ;
    for(i=0; i<16; i++)
    {
        mask= 0x80 ;
        tem    = ch[i*2] ;    //俩个字节一组16位，取第一个字节
        for(j=0; j<8; j++)
        {
            if(tem & mask)
            {
                LCD_putpixe(x+j, y+i, col) ;
            }
            mask = mask >> 1 ;
        }
       
        mask = 0x80 ;
        tem = ch[i*2 + 1] ;
        for(j=0; j<8; j++)
        {
            if(tem & mask)
            {
                LCD_putpixe(x+j+8, y+i, col) ;//奇偶写的不一样，有一个要加8
            }
            mask = mask >> 1 ;
        }
    }
}
