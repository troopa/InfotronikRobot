/**
 * \file
 * \brief Event driver interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements a generic event driver. We are using numbered events starting with zero.
 * EVNT_HandleEvent() can be used to process the pending events. Note that the event with the number zero
 * has the highest priority and will be handled first
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "Platform.h"
#include "stdbool.h"

#if PL_CONFIG_HAS_EVENTS

typedef enum EVNT_Handle {
  EVNT_STARTUP,            /*!< System startup Event */
  EVENT_LED_HEARTBEAT,     /*!< LED heartbeat */
  EVENT_SW1_PRESSED,
  EVENT_SW2_PRESSED,
  EVENT_SW3_PRESSED,
  EVENT_SW4_PRESSED,
  EVENT_SW5_PRESSED,
  EVENT_SW6_PRESSED,
  EVENT_SW7_PRESSED,
  EVENT_SW1_LPRESSED,
  EVENT_SW2_LPRESSED,
  EVENT_SW3_LPRESSED,
  EVENT_SW4_LPRESSED,
  EVENT_SW5_LPRESSED,
  EVENT_SW6_LPRESSED,
  EVENT_SW7_LPRESSED,
  EVENT_SW1_RELEASED,
  EVENT_SW2_RELEASED,
  EVENT_SW3_RELEASED,
  EVENT_SW4_RELEASED,
  EVENT_SW5_RELEASED,
  EVENT_SW6_RELEASED,
  EVENT_SW7_RELEASED,
  /*!< \todo Your events here */
  EVNT_NOF_EVENTS       /*!< Must be last one! */
} EVNT_Handle;

/*!
 * \brief Sets an event.
 * \param[in] event The handle of the event to set.
 */
void EVNT_SetEvent(EVNT_Handle event);

/*!
 * \brief Clears an event.
 * \param[in] event The event handle of the event to clear.
 */
void EVNT_ClearEvent(EVNT_Handle event);

/*!
 * \brief Returns the status of an event.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSet(EVNT_Handle event);

/*!
 * \brief Returns the status of an event. As a side effect, the event gets cleared.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSetAutoClear(EVNT_Handle event);

/*!
 * \brief Routine to check if an event is pending. If an event is pending, the event is cleared and the provided callback is called.
 * \param[in] callback Callback routine to be called. The event handle is passed as argument to the callback.
 * \param[in] clearEvent If TRUE, it will clear the event in the EVNT_HandleEvent(), otherwise not.
 */
void EVNT_HandleEvent(void (*callback)(EVNT_Handle), bool clearEvent);

/*! \brief Event module initialization */
void EVNT_Init(void);

/*! \brief Event module de-initialization */
void EVNT_Deinit(void);

#endif /* PL_HAS_EVENTS */


#endif /* EVENT_H_ */
