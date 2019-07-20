#include "s3c2451_irq.h"

IRQ_MemMapPtr const IRQ_BASE_PTR[2] = {IRQ1_BASE_PTR,IRQ2_BASE_PTR };

void IRQ_ClearSRCPND(unsigned int irqx)//清楚主标志寄存器内容
{
	IRQ_BASE_PTR[0]->SRCPND |= irqx;//当中断相应后，SRCPND自动置为1表示不响应其余任何中断，再次置1后相当于允许其他中断产生
	IRQ_BASE_PTR[0]->INTPND |= irqx;
}

void IRQ_ClearSUBSRCPND(unsigned int irqx)
{
	IRQ_BASE_PTR[0]->SUBSRCPND |= irqx;//将相应位置1，代表允许接收其余中断
}

void IRQ_INTMask_init(unsigned int irqx,Functionalstate newstate)//主寄存器设置
{
	if(newstate == ENABLE)//可用，不屏蔽，将相应位置0
	{
		IRQ_BASE_PTR[0]->INTMSK &=~irqx;
	}
	else
	{
		IRQ_BASE_PTR[0]->INTMSK |= irqx;//屏蔽置1
	}
}

void IRQ_INTSUBMask_init(unsigned int irqx,Functionalstate newstate)//子寄存器设置
{
	if(newstate == ENABLE)//可用，不屏蔽，将相应位置0
	{
		IRQ_BASE_PTR[0]->INTSUBMSK &=~irqx;
	}
	else
	{
		IRQ_BASE_PTR[0]->INTSUBMSK |= irqx;//屏蔽置1
	}
}

Functionalstate IRQ_GetSRCPND(unsigned int irqx)//获取主标志寄存器有没有响应
{
	if((IRQ_BASE_PTR[0]->SRCPND & irqx) == irqx)//如果该位为1，代表中断源发出了中断请求，应返回1
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

Functionalstate IRQ_GetSUBSRCPND(unsigned int irqx)
{
	if((IRQ_BASE_PTR[0]->SUBSRCPND & irqx) == irqx)//如果该位为1，代表中断源发出了中断请求，应返回1
	{
		return ENABLE;//返回1
	}
	else
	{
		return DISABLE;//返回0
	}
}
