#ifndef S3C2451_TIME_H
#define S3C2451_TIME_H
#include "typedef.h"
#include "s3c2451_vector.h"
typedef struct{
	U32 TCFG0;
	U32 TCFG1;
	U32 TCON;
	U32 TCNTB0;
	U32 TCMPB0;
	U32 TCNTO0;
	U32 TCNTB1;
	U32 TCMPB1;
	U32 TCNTO1;
}volatile *TIM_MemMapPtr;

#define TIM_BASE_PTR ((TIM_MemMapPtr)0X51000000)

typedef enum{
	time_ch0 = 0,
	time_ch1,
	time_ch2,
	time_ch3,
	time_ch4
}TIM_typedef;

typedef struct{
	unsigned int TIM_prescale;//Ô¤·ÖÆµ
	unsigned int TIM_scale;
	unsigned int TIM_countval;
	unsigned int TIM_compareval;
}TIM_init_typedef;

extern void TIM0_init(TIM_typedef timx,TIM_init_typedef tim_init_typedef);
extern void TIM1_init(TIM_typedef timx,TIM_init_typedef tim_init_typedef);

extern U16 TIM_getcount(TIM_typedef timx);
extern void TIM_interrupt_init(TIM_typedef timx,U32 addr);

#endif
