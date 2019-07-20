#ifndef S3C2351_GPIO_H
#define S3C2351_GPIO_H
#include "typedef.h"

typedef struct
{
	U32 GPCON;
	U32 GPDAT;
	U32 GPUDP;
	U32 GPSEL;
}volatile * GPIO_MemMapPtr;

#define GPIOA_BASE_PTR ((GPIO_MemMapPtr)0X56000000)
#define GPIOB_BASE_PTR ((GPIO_MemMapPtr)0X56000010)
#define GPIOC_BASE_PTR ((GPIO_MemMapPtr)0X56000020)
#define GPIOD_BASE_PTR ((GPIO_MemMapPtr)0X56000030)
#define GPIOE_BASE_PTR ((GPIO_MemMapPtr)0X56000040)
#define GPIOF_BASE_PTR ((GPIO_MemMapPtr)0X56000050)
#define GPIOG_BASE_PTR ((GPIO_MemMapPtr)0X56000060)


#define GPIO_PIN0 (1<<0)
#define GPIO_PIN1 (1<<1)
#define GPIO_PIN2 (1<<2)
#define GPIO_PIN3 (1<<3)
#define GPIO_PIN4 (1<<4)
#define GPIO_PIN5 (1<<5)
#define GPIO_PIN6 (1<<6)
#define GPIO_PIN7 (1<<7)
#define GPIO_PIN8 (1<<8)
#define GPIO_PIN9 (1<<9)
#define GPIO_PIN25 (1<<25)
#define GPIO_PIN26 (1<<26)
#define GPIO_PIN(i) (1<<i)

typedef enum{
	BIT_RESET = 0,BIT_SET
													}BIT_typedef;

typedef enum{
	GPIOA = 0,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG
																								}GPIO_typedef;

typedef enum{
	GPIO_MODE_IN = 0,
	GPIO_MODE_OUT,
	GPIO_MODE_ALT1,
	GPIO_MODE_ALT2
											}GPIO_MODE_typedef;

typedef enum{
	GPIO_UDP_DISABLE = 0,
	GPIO_UDP_DOWN,
	GPIO_UDP_UP,
	GPIO_UDP_NOAVAILABLE
												}GPIO_UDP_typedef;

typedef struct{
	U32 pinx;
	GPIO_MODE_typedef mode;
	GPIO_UDP_typedef udp;
													}GPIO_Init_Typedef;

extern void GPIO_INIT(GPIO_typedef portx,U32 pinx,GPIO_Init_Typedef gpio_init_typedef);
extern void GPIO_writebit(GPIO_typedef portx,U32 pinx,BIT_typedef bit);
extern BIT_typedef GPIO_readbit(GPIO_typedef portx, U32 pinx);

#endif

