#include "s3c2451_adc.h"
#include "s3c2451_vector.h"

void ADC_init(AIN_typedef ainx,U8 res)
{
	ADC_BASE_PTR->ADCCON |= 1<<14;//预分频使能
	
	ADC_BASE_PTR->ADCCON &=~(0xff<<6);
	ADC_BASE_PTR->ADCCON |= 19<<6;//预分频值为20
	
	if(res == ADC_10bit_mode)
	{
		ADC_BASE_PTR->ADCCON &= ~(1<<3);//分辨率为10位
	}
	if(res == ADC_12bit_mode)
	{
		ADC_BASE_PTR->ADCCON |= (1<<3);//分辨率为12位
	}
	
	ADC_BASE_PTR->ADCDLY = 50000;//转化时间设置
	
	ADC_BASE_PTR->ADCMUX = ainx;//通道选择
	
	ADC_BASE_PTR->ADCCON &= ~(1<<2);//切换工作状态为正常操作模式，非待机模式
}

U16 ADC_get_value(AIN_typedef ainx)
{
	ADC_BASE_PTR->ADCCON |= 0X01;//启动AD转化
	while((ADC_BASE_PTR->ADCCON & 0x01)==0x01);//等待AD启动完成，完成后自动清0，1表示正在启动
	while((ADC_BASE_PTR->ADCCON & 0x8000)==0);//等待转化完成，1代表转化结束
	return (ADC_BASE_PTR->ADCDAT0 &0xfff );
}

void ADC_interrupt_init(AIN_typedef ainx,U32 addr)
{
	//if(ainx == AIN_ch0)
		pISR_ADC = addr;
}
