#include "s3c2451_rtc.h"
#include "s3c2451_vector.h"
void RTC_interrupt_init(U8 cnt,Functionalstate newstate)//RTC中断初始化
{
	if(newstate == ENABLE)
	{
		RTC_BASE_PTR->TICNT0 |= 0X80;
		RTC_BASE_PTR->TICNT0 &= ~0X7F;
		if(cnt >127)
			cnt = 127;
		RTC_BASE_PTR->TICNT0 |= cnt;//设置滴答时间，最大设置值为127，当cnt值为127也就是1s滴答一次
	}
	else
	{
		RTC_BASE_PTR->TICNT0 &=~0x80;//DISABLE
	}
}


void RTC_set_time(RTC_struct_init rtc_struct_init)
{
	RTC_BASE_PTR->RTCCON |= 0X01;//开启
	RTC_BASE_PTR->BCDYEAR = rtc_struct_init.year;
	RTC_BASE_PTR->BCDMON = rtc_struct_init.month;
	RTC_BASE_PTR->BCDDAY = rtc_struct_init.day;//周几
	RTC_BASE_PTR->BCDDATE = rtc_struct_init.date;//几号
	RTC_BASE_PTR->BCDHOUR = rtc_struct_init.hour;
	RTC_BASE_PTR->BCDMIN = rtc_struct_init.minute;
	RTC_BASE_PTR->BCDSEC = rtc_struct_init.second;
	RTC_BASE_PTR->RTCCON &= ~0X01;//关闭时钟设置功能，防止其余器件的电平改动导致误操作
}

void RTC_get_time(RTC_struct_init *rtc_struct_init)
{
	RTC_BASE_PTR->RTCCON |= 0X01;//开启
	
	rtc_struct_init->year = 0x2000 + RTC_BASE_PTR->BCDYEAR;
	rtc_struct_init->month = RTC_BASE_PTR->BCDMON;
	rtc_struct_init->day = RTC_BASE_PTR->BCDDAY;//周几
	rtc_struct_init->date = RTC_BASE_PTR->BCDDATE;//几号
	rtc_struct_init->hour = RTC_BASE_PTR->BCDHOUR;
	rtc_struct_init->minute = RTC_BASE_PTR->BCDMIN;
	rtc_struct_init->second = RTC_BASE_PTR->BCDSEC;
	
	RTC_BASE_PTR->RTCCON &= ~0X01;//关闭时钟设置功能，防止其余器件的电平改动导致误操作
}

void TICK_IRQ_init(U32 addr)
{
	pISR_TICK = addr;
}
