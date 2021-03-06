#ifndef BL_ESP_H
#define BL_ESP_H

#ifndef STM32F4XX_HAL
#define STM32F4XX_HAL
#include "stm32f4xx_hal.h"
#endif 


#define SSID    "BLPRO"
#define PASS		"123456"

#define ESPBASEADDR   ((uint32_t)0x080E0030)
#define ESPCONFINFOR_AU8 ((const volatile uint8_t) *ESPBASEADDR)
	
typedef enum{
	
	WAITINGRES,
	READY,
	
}ESPDataSendSta_en;

typedef enum{
		WAITING,
		STATE1,
		STATE2,
		STATE3,	
}Recheckstate_en;

typedef struct{
	uint8_t Header_u8;
	char Status_c[10];
	uint8_t Data[25];
	
}ESPMessage_st;


typedef struct{
			Datatype_en  Datatype;
			uint8_t Len;
			void *data;
}ESPDatadef_st;

typedef struct{	
	
	char SsId[10];	
	char Pass[10];	
	
}ESPInfor_st;

uint8_t InitESp8266(void);

uint8_t bl_esp_InitESPSys(void);

void ESPOperationCyclic(void);

uint8_t SendMessagetoESP(ESPDatadef_st Data, ESPDataSendSta_en EspSendSta);

#endif
