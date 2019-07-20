#include "s3c2451_led.h"


void led_init(void)
{
	GPACON &= ~(0X3<< 25);//��GPACON �ڵ�25/26λ��0����GPA25/GPA26��Ϊ���ģʽ
	GPBCON &=~(0XF<<10);//�Ƚ�B���ƿڵ�10-13λ��0
	GPBCON |= (0X5<<10);//ֻ�ı�GPB5/GPB6��Ӧ��10-13λ��ֵ����GPB5/GPB6��Ϊ���ģʽ
	
	//GPB0��Ӧ��������1�������죬0�رշ�����
	GPBCON &=~0X03;//��GPB0��Ӧ��0-1λ��Ϊ0
	GPBCON |= 0X01;//��GPB0��0-1λ��Ϊ01������GPB0��Ϊ���ģʽ
}
void liushuideng(void)//LED1->LED4ѭ������
{
	LEDB_ON(5);//����LED1
	delay_ms(1000);
	LEDB_OFF(5);//Ϩ��LED1
	
	
	LEDB_ON(6);//����LED2
	delay_ms(1000);
	LEDB_OFF(6);//Ϩ��LED2
	
	
	LEDA_ON(25);//����LED3
	delay_ms(1000);
	LEDA_OFF(25);//Ϩ��LED3
	
	
	LEDA_ON(26);//����LED4
	delay_ms(1000);
	LEDA_OFF(26);//Ϩ��LED4
	
	
}

void led_2(void)//LED1->LED4���ε���,Ȼ��ȫϨ��2s���ٴ����ε���
{
	LEDB_ON(5);//����LED1
	delay_ms(1000);
	
	LEDB_ON(6);//����LED2
	delay_ms(1000);
	
	LEDA_ON(25);//����LED3
	delay_ms(1000);
	
	LEDA_ON(26);//����LED4
	delay_ms(1000);
	
	LEDB_OFF(5);//Ϩ��LED1
	LEDB_OFF(6);//Ϩ��LED2
	LEDA_OFF(25);//Ϩ��LED3
	LEDA_OFF(26);//Ϩ��LED4
	delay_ms(2000);
	
}

void System_led(void)//LED1->LED4���ε���,Ȼ��ȫϨ��2s���ٴ����ε���
{
	LEDB_ON(5);//��LED1
	delay_ms(200);
	
	LEDB_OFF(5);
	delay_ms(200);
	
	LEDB_ON(5);
	delay_ms(200);
	
	LEDB_OFF(5);
	delay_ms(600);
}

void beep_init(void)
{
	BEEPGPB_ON(0);//OPEN BEEP
	delay_ms(100);//��ĳS
	BEEPGPB_OFF(0);//CLOSE BEEP
	delay_ms(1000);//�� ĳS

}
