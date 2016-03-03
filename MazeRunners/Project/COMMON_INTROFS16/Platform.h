/*
 * Platform.h
 *
 *  Created on: 1 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_PLATFORM_H_
#define SOURCES_COMMON_INTROFS16_PLATFORM_H_

#include "Platform_Local.h"

void PL_Init(void);
void PL_Deinit(void);

#define PL_HAS_LED (0)

#ifdef PL_IS_ROBO
	#define PL_NOF_LED (2)
#elif defined(PL_IS_FRDM)
	#define PL_NOF_LED (3)
#else
	#error "Unknown board?"
#endif

#endif /* SOURCES_COMMON_INTROFS16_PLATFORM_H_ */