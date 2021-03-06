/*
 * Key.h
 *
 *  Created on: 14 Mar 2016
 *      Author: troopa
 */

#ifndef SOURCES_COMMON_INTROFS16_KEY_H_
#define SOURCES_COMMON_INTROFS16_KEY_H_

#include "Platform.h"
#if PL_CONFIG_HAS_KEY

typedef enum
{
#if PL_CONFIG_NOF_KEYS >= 1
	KEY_BTN1,
#endif
#if PL_CONFIG_NOF_KEYS >= 2
	KEY_BTN2,
#endif
#if PL_CONFIG_NOF_KEYS >= 3
	KEY_BTN3,
#endif
#if PL_CONFIG_NOF_KEYS >= 4
	KEY_BTN4,
#endif
#if PL_CONFIG_NOF_KEYS >= 5
	KEY_BTN5,
#endif
#if PL_CONFIG_NOF_KEYS >= 6
	KEY_BTN6,
#endif
#if PL_CONFIG_NOF_KEYS >= 7
	KEY_BTN7,
#endif
	KEY_BTN_LAST
}KEY_BUTTON;

#if PL_CONFIG_NOF_KEYS >= 1
	#include "SW1.h"
	#define Key1_Get() (!(SW1_GetVal()))
#else
	#define Key1_Get() FALSE
#endif

#if PL_CONFIG_NOF_KEYS >= 2
	#include "SW2.h"
	#define Key2_Get() (!(SW2_GetVal()))
#else
	#define Key2_Get() FALSE
#endif

#if PL_CONFIG_NOF_KEYS >= 3
	#include "SW3.h"
	#define Key3_Get() (!(SW3_GetVal()))
#else
	#define Key3_Get() FALSE
#endif

#if PL_CONFIG_NOF_KEYS >= 4
	#include "SW4.h"
	#define Key4_Get() (!(SW4_GetVal()))
#else
	#define Key4_Get() FALSE
#endif

#if PL_CONFIG_NOF_KEYS >= 5
	#include "SW5.h"
	#define Key5_Get() (!(SW5_GetVal()))
#else
	#define Key5_Get() FALSE
#endif

#if PL_CONFIG_NOF_KEYS >= 6
	#include "SW6.h"
	#define Key6_Get() (!(SW6_GetVal()))
#else
	#define Key6_Get() FALSE
#endif

#if PL_CONFIG_NOF_KEYS >= 7
	#include "SW7.h"
	#define Key7_Get() (!(SW7_GetVal()))
#else
	#define Key7_Get() FALSE
#endif

void Key_Scan();

void Key_Open();

void Key_Close();

void KEY_Init();

void KEY_Deinit();

#endif
#endif /* SOURCES_COMMON_INTROFS16_KEY_H_ */
