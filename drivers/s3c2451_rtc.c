#include "s3c2451_rtc.h"
#include "s3c2451_vector.h"
void RTC_interrupt_init(U8 cnt,Functionalstate newstate)//RTC�жϳ�ʼ��
{
	if(newstate == ENABLE)
	{
		RTC_BASE_PTR->TICNT0 |= 0X80;
		RTC_BASE_PTR->TICNT0 &= ~0X7F;
		if(cnt >127)
			cnt = 127;
		RTC_BASE_PTR->TICNT0 |= cnt;//���õδ�ʱ�䣬�������ֵΪ127����cntֵΪ127Ҳ����1s�δ�һ��
	}
	else
	{
		RTC_BASE_PTR->TICNT0 &=~0x80;//DISABLE
	}
}


void RTC_set_time(RTC_struct_init rtc_struct_init)
{
	RTC_BASE_PTR->RTCCON |= 0X01;//����
	RTC_BASE_PTR->BCDYEAR = rtc_struct_init.year;
	RTC_BASE_PTR->BCDMON = rtc_struct_init.month;
	RTC_BASE_PTR->BCDDAY = rtc_struct_init.day;//�ܼ�
	RTC_BASE_PTR->BCDDATE = rtc_struct_init.date;//����
	RTC_BASE_PTR->BCDHOUR = rtc_struct_init.hour;
	RTC_BASE_PTR->BCDMIN = rtc_struct_init.minute;
	RTC_BASE_PTR->BCDSEC = rtc_struct_init.second;
	RTC_BASE_PTR->RTCCON &= ~0X01;//�ر�ʱ�����ù��ܣ���ֹ���������ĵ�ƽ�Ķ����������
}

void RTC_get_time(RTC_struct_init *rtc_struct_init)
{
	RTC_BASE_PTR->RTCCON |= 0X01;//����
	
	rtc_struct_init->year = 0x2000 + RTC_BASE_PTR->BCDYEAR;
	rtc_struct_init->month = RTC_BASE_PTR->BCDMON;
	rtc_struct_init->day = RTC_BASE_PTR->BCDDAY;//�ܼ�
	rtc_struct_init->date = RTC_BASE_PTR->BCDDATE;//����
	rtc_struct_init->hour = RTC_BASE_PTR->BCDHOUR;
	rtc_struct_init->minute = RTC_BASE_PTR->BCDMIN;
	rtc_struct_init->second = RTC_BASE_PTR->BCDSEC;
	
	RTC_BASE_PTR->RTCCON &= ~0X01;//�ر�ʱ�����ù��ܣ���ֹ���������ĵ�ƽ�Ķ����������
}

void TICK_IRQ_init(U32 addr)
{
	pISR_TICK = addr;
}
