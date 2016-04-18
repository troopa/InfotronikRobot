#include "Platform.h"
#include "Application.h"
#include "LED.h"
#include "Event.h"
#include "WAIT1.h"
#include "Key.h"
#include "CLS1.h"
#include "Buzzer.h"
#include "Tunes.h"
#include "FRTOS1.h"
#include "Shell.h"
static int tune_counter = 0;

 void APP_HandleEvent(EVNT_Handle event)
  {
  	switch(event)
  	{
  	case EVNT_STARTUP:
  		LED1_On();//nothing;
#if PL_CONFIG_HAS_BUZZER
  		BUZ_Beep(400,200);
#endif
  		break;
  	case EVENT_LED_HEARTBEAT:
  		//LED1_Neg();
  		break;
  	case EVENT_SW1_PRESSED:
  		LED2_Neg();
#if PL_CONFIG_HAS_BUZZER && 0
  		BUZ_PlayTune(MARIO);
#endif
#if PL_CONFIG_HAS_SHELL
  		//CLS1_SendStr("SW1_Pressed\n\r", CLS1_GetStdio()->stdOut);
  		SHELL_SendString("SW1 Pressed\n\r");
#endif
  		break;
  	case EVENT_SW2_PRESSED:
  	  	LED1_Off();
  	  	break;
  	case EVENT_SW1_LPRESSED:
#if PL_CONFIG_HAS_BUZZER
  		if(tune_counter < NOF_TUNES)
  		{
  			BUZ_PlayTune(tune_counter);
  			tune_counter++;
  		}
  		else
  		{
  			tune_counter = 0;
  		}
#endif
  	default:
  		//do nothing
  		break;
  	}
  }

void APP_Start(void) {
  PL_Init();
#if PL_CONFIG_HAS_RTOS
  FRTOS1_vTaskStartScheduler();
#endif
}


