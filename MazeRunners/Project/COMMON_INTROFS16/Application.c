#include "Platform.h"
#include "Application.h"
#include "LED.h"
#include "Event.h"
#include "WAIT1.h"
#include "Key.h"

 void APP_HandleEvent(EVNT_Handle event)
  {
  	switch(event)
  	{
  	case EVNT_STARTUP:
  		LED1_On();//nothing;
  		break;
  	case EVENT_LED_HEARTBEAT:
  		// do nothing;
  		break;
  	case EVENT_SW1_PRESSED:
  		LED1_On();
  		break;
  	case EVENT_SW2_PRESSED:
  	  	LED1_Off();
  	  	break;
  	default:
  		//do nothing
  		break;
  	}
  }

void APP_Start(void) {
  PL_Init();
  /* init: turn off */
#if PL_CONFIG_HAS_EVENTS
  EVNT_SetEvent(EVNT_STARTUP);
#endif

  CLS1_SendStr("Hello World\n",CLS1_GetStdIo()->StdOut);
  for(;;) {
#if PL_CONFIG_HAS_KEY
	  Key_Scan();
#endif
#if PL_CONFIG_HAS_EVENTS
    EVNT_HandleEvent(APP_HandleEvent,1);
#endif
  }

  for(;;) {
    /* wait */
  }
}


