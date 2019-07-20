#include "s3c2451_time.h"

void TIM0_init(TIM_typedef timx,TIM_init_typedef tim_init_typedef)
{
	TIM_BASE_PTR->TCFG0 &= ~0XFF;//THE low 8bits put ZERO 
	TIM_BASE_PTR->TCFG0 |= 199;
	
	TIM_BASE_PTR->TCFG1 &= ~0x0f;
	TIM_BASE_PTR->TCFG1 |= 0x02;//8分频
	
	TIM_BASE_PTR->TCNTB0 = 4;//loading initial value
//	TIM_BASE_PTR->TCMPB0 = 2;//50%占空比,如果置0则永远为0，无高电平产生-20625
	
	TIM_BASE_PTR->TCON &= ~0xf;
	TIM_BASE_PTR->TCON |= (1<<3);//自动重载
	
	TIM_BASE_PTR->TCON |= (1<<1);//Update TCNTB0 & TCMPB0
	TIM_BASE_PTR->TCON |= (1<<0);//启动定时器0
	TIM_BASE_PTR->TCON &= ~(1<<1);//清除update位
}

void TIM1_init(TIM_typedef timx,TIM_init_typedef tim_init_typedef)
{
//	TIM_BASE_PTR->TCFG0 &= ~0XFF;//THE low 8bits put ZERO 
//	TIM_BASE_PTR->TCFG0 |= 199;
	
	TIM_BASE_PTR->TCFG1 &= ~(0xf0);
	TIM_BASE_PTR->TCFG1 |= 0x20;//8分频
	
	TIM_BASE_PTR->TCNTB1 = 41250;//loading initial value
//	TIM_BASE_PTR->TCMPB0 = 2;//50%占空比,如果置0则永远为0，无高电平产生-20625
	
	TIM_BASE_PTR->TCON &= ~(0x0f<<8);
	TIM_BASE_PTR->TCON |= (1<<11);//自动重载
	
	TIM_BASE_PTR->TCON |= (1<<9);//Update TCNTB1 & TCMPB1
	TIM_BASE_PTR->TCON |= (1<<8);//启动定时器1
	TIM_BASE_PTR->TCON &= ~(1<<9);//清除update位
}

U16 TIM_getcount(TIM_typedef timx)//得到TCNTB0减到哪个数值了，从41250减到0需要1s
{
	if(timx == time_ch0)
	{
		return TIM_BASE_PTR->TCNTO0 ;
	}
	if(timx == time_ch1)
	{
		return TIM_BASE_PTR->TCNTO1 ;
	}
	return 0;
}
void TIM_interrupt_init(TIM_typedef timx,U32 addr)
{
	switch(timx)
	{
		case time_ch0:pISR_TIMER0 = addr;break;
		case time_ch1:pISR_TIMER1 = addr;break;
		case time_ch2:pISR_TIMER2 = addr;break;
		case time_ch3:pISR_TIMER3 = addr;break;
		case time_ch4:pISR_TIMER4 = addr;break;
		default:break;
	}
}
