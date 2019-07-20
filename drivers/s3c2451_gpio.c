#include "s3c2451_gpio.h"
GPIO_MemMapPtr const PORT_BASE_PTR[7] = {GPIOA_BASE_PTR,GPIOB_BASE_PTR,GPIOC_BASE_PTR,\
															GPIOD_BASE_PTR,GPIOE_BASE_PTR,GPIOF_BASE_PTR,GPIOG_BASE_PTR};


void GPIO_INIT(GPIO_typedef portx,U32 pinx,GPIO_Init_Typedef gpio_init_typedef)
{
	int i;
	for(i =0; i < 32; i++)
	{
		if((pinx & (1<<i)) == (1<<i))//主要是确定i的值，并且是一位一位的确定i值    
		{
			if(portx == GPIOA)//判断需操作的是否为A口，因为A口与其他口的模式不同：A口输出模式需置位0，并且用一位控制，其他口为两位控制
			{
				if(gpio_init_typedef.mode==GPIO_MODE_OUT)
				{
					PORT_BASE_PTR[portx]->GPCON &=~(1<<i);
				}
				else if(gpio_init_typedef.mode == GPIO_MODE_ALT1)
				{
					PORT_BASE_PTR[portx]->GPCON |= (1<<i);
				}
				
			}
			else
			{
				PORT_BASE_PTR[portx]->GPCON &= ~(0x03<<2*i);//先清零
				PORT_BASE_PTR[portx]->GPCON |=(gpio_init_typedef.mode<<(2*i));//再将con对应位 置MODE代表的数
				PORT_BASE_PTR[portx]->GPUDP &=~(0x03<<2*i);
				PORT_BASE_PTR[portx]->GPUDP |=(gpio_init_typedef.udp<<(2*i));
			}
		}	
	}
}
void GPIO_writebit(GPIO_typedef portx,U32 pinx,BIT_typedef bit)
{
	if(bit == BIT_SET)
	{
		PORT_BASE_PTR[portx]->GPDAT |= pinx;
	}
	else
	{
		PORT_BASE_PTR[portx]->GPDAT &= ~pinx;
	}

}
//GPIO_readbit(GPIOF,GPIO_PIN0);
BIT_typedef GPIO_readbit(GPIO_typedef portx, U32 pinx)
{
	if((PORT_BASE_PTR[portx]->GPDAT & pinx) == pinx)//检测针脚是否为高
	{
		return BIT_SET;//为高返回1
	}
	else
	{
		return BIT_RESET;//为低返回0
	}
}

