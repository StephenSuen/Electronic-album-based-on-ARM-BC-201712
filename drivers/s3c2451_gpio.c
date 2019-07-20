#include "s3c2451_gpio.h"
GPIO_MemMapPtr const PORT_BASE_PTR[7] = {GPIOA_BASE_PTR,GPIOB_BASE_PTR,GPIOC_BASE_PTR,\
															GPIOD_BASE_PTR,GPIOE_BASE_PTR,GPIOF_BASE_PTR,GPIOG_BASE_PTR};


void GPIO_INIT(GPIO_typedef portx,U32 pinx,GPIO_Init_Typedef gpio_init_typedef)
{
	int i;
	for(i =0; i < 32; i++)
	{
		if((pinx & (1<<i)) == (1<<i))//��Ҫ��ȷ��i��ֵ��������һλһλ��ȷ��iֵ    
		{
			if(portx == GPIOA)//�ж���������Ƿ�ΪA�ڣ���ΪA���������ڵ�ģʽ��ͬ��A�����ģʽ����λ0��������һλ���ƣ�������Ϊ��λ����
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
				PORT_BASE_PTR[portx]->GPCON &= ~(0x03<<2*i);//������
				PORT_BASE_PTR[portx]->GPCON |=(gpio_init_typedef.mode<<(2*i));//�ٽ�con��Ӧλ ��MODE�������
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
	if((PORT_BASE_PTR[portx]->GPDAT & pinx) == pinx)//�������Ƿ�Ϊ��
	{
		return BIT_SET;//Ϊ�߷���1
	}
	else
	{
		return BIT_RESET;//Ϊ�ͷ���0
	}
}

