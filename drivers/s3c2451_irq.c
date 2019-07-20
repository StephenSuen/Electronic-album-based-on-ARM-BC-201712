#include "s3c2451_irq.h"

IRQ_MemMapPtr const IRQ_BASE_PTR[2] = {IRQ1_BASE_PTR,IRQ2_BASE_PTR };

void IRQ_ClearSRCPND(unsigned int irqx)//�������־�Ĵ�������
{
	IRQ_BASE_PTR[0]->SRCPND |= irqx;//���ж���Ӧ��SRCPND�Զ���Ϊ1��ʾ����Ӧ�����κ��жϣ��ٴ���1���൱�����������жϲ���
	IRQ_BASE_PTR[0]->INTPND |= irqx;
}

void IRQ_ClearSUBSRCPND(unsigned int irqx)
{
	IRQ_BASE_PTR[0]->SUBSRCPND |= irqx;//����Ӧλ��1������������������ж�
}

void IRQ_INTMask_init(unsigned int irqx,Functionalstate newstate)//���Ĵ�������
{
	if(newstate == ENABLE)//���ã������Σ�����Ӧλ��0
	{
		IRQ_BASE_PTR[0]->INTMSK &=~irqx;
	}
	else
	{
		IRQ_BASE_PTR[0]->INTMSK |= irqx;//������1
	}
}

void IRQ_INTSUBMask_init(unsigned int irqx,Functionalstate newstate)//�ӼĴ�������
{
	if(newstate == ENABLE)//���ã������Σ�����Ӧλ��0
	{
		IRQ_BASE_PTR[0]->INTSUBMSK &=~irqx;
	}
	else
	{
		IRQ_BASE_PTR[0]->INTSUBMSK |= irqx;//������1
	}
}

Functionalstate IRQ_GetSRCPND(unsigned int irqx)//��ȡ����־�Ĵ�����û����Ӧ
{
	if((IRQ_BASE_PTR[0]->SRCPND & irqx) == irqx)//�����λΪ1�������ж�Դ�������ж�����Ӧ����1
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
	if((IRQ_BASE_PTR[0]->SUBSRCPND & irqx) == irqx)//�����λΪ1�������ж�Դ�������ж�����Ӧ����1
	{
		return ENABLE;//����1
	}
	else
	{
		return DISABLE;//����0
	}
}
