#include "ECUModeManager.h"

#ifndef STM32F4XX_HAL
#define STM32F4XX_HAL
#include "stm32f4xx_hal.h"
#endif 

void SofResetSysem(void){
	
	NVIC_SystemReset();
}

void HardResetsystem(void){
	

	
}