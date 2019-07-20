

//void delay_us(unsigned char t)  //2t+5(us)
//{
//	while(--t);
//}
//void delay_ms(unsigned int t)  //t(ms)
//{
//	while(t--)
//	{
//		delay_us(245);
//		delay_us(245);
//	}
//}

void delay_ms(unsigned long xms)
{
	unsigned long j;
	for(;xms>0;xms--)
	{
		for(j=500;j>0;j--);
	}
}
