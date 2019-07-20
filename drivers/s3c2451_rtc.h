#ifndef S3C2451_RTC_H
#define S3C2451_RTC_H
#include "typedef.h"
#include "s3c2451_irq.h"

typedef struct{
	U32 RTCCON;
	U32 TICNT0;
	U32 TICNT2;
	U32 TICNT1;
	U32 RTCALM;
	U32 ALMSEC;
	U32 ALMMIN;
	U32 ALMHOUR;
	U32 ALMDATE;
	U32 ALMMON;
	U32 ALMYEAR;
	U32 NO_Register1;
	U32 BCDSEC;//��
	U32 BCDMIN;//��
	U32 BCDHOUR;//ʱ
	U32 BCDDATE;//���ţ�1-30/31��
	U32 BCDDAY;//�ܼ���1-7
	U32 BCDMON;//�£�1-12��
	U32 BCDYEAR;//��
	U32 NO_Register2;
	U32 TICKCNT;
}volatile *RTC_MemMapPtr;

#define RTC_BASE_PTR ((RTC_MemMapPtr)0X57000040)

typedef struct{
	U16 year;
	U16 month;
	U16 day;//�ܼ�
	U16 date;//����
	
	U16 hour;
	U16 minute;
	U16 second;
}RTC_struct_init;

extern void RTC_interrupt_init(U8 cnt,Functionalstate newstate);//RTC�жϳ�ʼ��
extern void RTC_set_time(RTC_struct_init rtc_struct_init);
extern void RTC_get_time(RTC_struct_init *rtc_struct_init);
extern void TICK_IRQ_init(U32 addr);//�β���д�жϷ����ַ

#endif
