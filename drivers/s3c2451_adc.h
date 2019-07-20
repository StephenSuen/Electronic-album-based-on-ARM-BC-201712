#ifndef S3C2451_ADC_H
#define S3C2451_ADC_H
#include "typedef.h"

typedef struct{
	U32 ADCCON;
	U32 ADCTSC;//´¥ÃþÆÁ¿ØÖÆ¼Ä´æÆ÷
	U32 ADCDLY;
	U32 ADCDAT0;
	U32 ADCDAT1;
	U32 ADCUPDN;
	U32 ADCMUX;
}volatile *ADC_MemMapPtr;

#define ADC_BASE_PTR ((ADC_MemMapPtr)0x58000000)

typedef enum{
	AIN_ch0 = 0,
	AIN_ch1,
	AIN_ch2,
	AIN_ch3,
	AIN_ch4
}AIN_typedef;

#define ADC_10bit_mode 0
#define ADC_12bit_mode 1

extern void ADC_init(AIN_typedef ainx,U8 res);//resÎª·Ö±æÂÊ
extern U16 ADC_get_value(AIN_typedef ainx);
extern void ADC_interrupt_init(AIN_typedef ainx,U32 addr);

#endif
