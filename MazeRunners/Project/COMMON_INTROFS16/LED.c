/*
 * LED.c
 *
 *  Created on: 1 Mar 2016
 *      Author: Daniel Föhn
 */

#include "Platform.h"

#if PL_CONFIG_HAS_LED
	#include "LED.h"

void LED_Init() {
#if PL_CONFIG_NOF_LED >= 1
	LED1_Off();
#endif
#if PL_CONFIG_NOF_LED >= 2
	LED2_Off();
#endif
#if PL_CONFIG_NOF_LED >= 3
	LED3_Off();
#endif
}

void LED_Deinit(){
	LED_Init();
}
#endif
