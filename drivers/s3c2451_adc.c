#include "s3c2451_adc.h"
#include "s3c2451_vector.h"

void ADC_init(AIN_typedef ainx,U8 res)
{
	ADC_BASE_PTR->ADCCON |= 1<<14;//Ԥ��Ƶʹ��
	
	ADC_BASE_PTR->ADCCON &=~(0xff<<6);
	ADC_BASE_PTR->ADCCON |= 19<<6;//Ԥ��ƵֵΪ20
	
	if(res == ADC_10bit_mode)
	{
		ADC_BASE_PTR->ADCCON &= ~(1<<3);//�ֱ���Ϊ10λ
	}
	if(res == ADC_12bit_mode)
	{
		ADC_BASE_PTR->ADCCON |= (1<<3);//�ֱ���Ϊ12λ
	}
	
	ADC_BASE_PTR->ADCDLY = 50000;//ת��ʱ������
	
	ADC_BASE_PTR->ADCMUX = ainx;//ͨ��ѡ��
	
	ADC_BASE_PTR->ADCCON &= ~(1<<2);//�л�����״̬Ϊ��������ģʽ���Ǵ���ģʽ
}

U16 ADC_get_value(AIN_typedef ainx)
{
	ADC_BASE_PTR->ADCCON |= 0X01;//����ADת��
	while((ADC_BASE_PTR->ADCCON & 0x01)==0x01);//�ȴ�AD������ɣ���ɺ��Զ���0��1��ʾ��������
	while((ADC_BASE_PTR->ADCCON & 0x8000)==0);//�ȴ�ת����ɣ�1����ת������
	return (ADC_BASE_PTR->ADCDAT0 &0xfff );
}

void ADC_interrupt_init(AIN_typedef ainx,U32 addr)
{
	//if(ainx == AIN_ch0)
		pISR_ADC = addr;
}
