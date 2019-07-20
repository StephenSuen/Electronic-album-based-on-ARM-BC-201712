#include "s3c2451_uart.h"

UART_MemMapPtr const UART_BASE_PTR[4] = {UART0_BASE_PTR,UART1_BASE_PTR,UART2_BASE_PTR,UART3_BASE_PTR};

void uart_init(UART_typedef uartx,UART_init_typedef uart_init_typedef)
{
	UART_BASE_PTR[uartx]->ULCON &=~(0x7f);//清零操作
	UART_BASE_PTR[uartx]->ULCON |= uart_init_typedef.wordwidth;//数据位
	UART_BASE_PTR[uartx]->ULCON |= (uart_init_typedef.stop<<2);//停止位
	UART_BASE_PTR[uartx]->ULCON |= (uart_init_typedef.parity<<3);//校验位
	
	if(uart_init_typedef.baudrate==9600)//波特率判断   9600
	 {
			 UART_BASE_PTR[uartx]->UBRDIV=428;//整数部分寄存器
			 UART_BASE_PTR[uartx]->UDIVSLOT=0xddd5;//小数部分寄存器
	 }
	
	if(uart_init_typedef.baudrate==115200)
	{
		UART_BASE_PTR[uartx]->UBRDIV = 35;
		UART_BASE_PTR[uartx]->UDIVSLOT = 0XDFDD;
	}
	
	UART_BASE_PTR[uartx]->UCON &=~(0xf);//先进行清零操作
	if(uart_init_typedef.mode==mode_rx) //模式判断1
	{
      UART_BASE_PTR[uartx]->UCON |=mode_rx;
  }
	if(uart_init_typedef.mode==mode_tx)//模式判断2
	{
      UART_BASE_PTR[uartx]->UCON |=mode_tx;
  }
	if(uart_init_typedef.mode==mode_rx_tx)//模式判断3
	{
      UART_BASE_PTR[uartx]->UCON |=mode_rx_tx;
  }
}
//void uart_init()
//{
//	ULCON0 |= 0X03;
//	ULCON0 &= ~(0X04);
//	ULCON0 &= ~(0X38);
//	
//	//设置波特率为115200
//	UBRDIV0 = 35;
//	UDIVSLOT0 = 0XDFDD;
//}

void uart_senddata(UART_typedef uartx, U8 data)//一个字节一个字节的发送
{
	UART_BASE_PTR[uartx]->UTXH = data;
	while((UART_BASE_PTR[uartx]-> UTRSTAT & 0X4 )!= 0);
}

void uart_sendbuf(UART_typedef uartx,unsigned char *data,unsigned char len)
{
	unsigned char i;
	for(i = 0;i<len;i++)
	{
		uart_senddata(uartx,data[i]);
	}
}

void uart_string(UART_typedef uartx,unsigned char *string)
{
	unsigned int len = strlen((char*)string);
	uart_sendbuf(uartx,string,len);
}

void uart_printf(char *fmt,...)
{
	va_list ap;
	char string[1024];
	va_start(ap,fmt);
	vsprintf(string,fmt,ap);
	va_end(ap);
	uart_string(UART0,(U8*)string);
}
unsigned char uart_revdata(UART_typedef uartx)//一个字节一个字节的接收
{
	return UART_BASE_PTR[uartx]->URXH;//8bit
}

void UART_interrupt_init(UART_typedef uartx,U32 addr)
{
	
	switch(uartx)
	{
		case UART0:pISR_UART0 = addr;break;
		case UART1:pISR_UART1 = addr;break;
		case UART2:pISR_UART2 = addr;break;
		case UART3:pISR_UART3 = addr;break;
		default:break;
	}
}
