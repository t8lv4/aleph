/* switches.c
 * aleph
 */

// asf
#include "compiler.h"
#include "gpio.h"
// #include "print_funcs.h"
// aleph
#include "aleph_board.h"
#include "events.h"
#include "event_types.h"
#include "global.h"
#include "switches.h"
#include "types.h"

//////
//// debug crazy oscillation on sw4
//u8 sw4State = 0;
////

static const U8 kSwitchPins[1] = {
  SW0_PIN,
  // SW1_PIN,
  // SW2_PIN,
  // SW3_PIN,
  // SW_MODE_PIN,
  // SW_POWER_PIN,
};

static const eEventType kSwitchEvents[1][2] = {
  { kEventSwitchDown0, kEventSwitchUp0 },
  // { kEventSwitchDown1, kEventSwitchUp1 },
  // { kEventSwitchDown2, kEventSwitchUp2 },
  // { kEventSwitchDown3, kEventSwitchUp3 },
  // { kEventSwitchDown4, kEventSwitchUp4 },
  // { kEventSwitchDown5, kEventSwitchUp5 },
};


// generate events from switch interrupts
void process_sw( const U8 swIdx )  {
  static event_t e;   
    e.eventType = kSwitchEvents[swIdx][gpio_get_pin_value(kSwitchPins[swIdx])];
    post_event(&e);
}








////////
///////////////////
//////////////////////
/////////////////


#if 0
//-----------------
// TEST: polling IO for switches until we get hardware deboucing
// debounce counters
static u32 swCount[NUM_SW];
// debounced results
static u8 swDebounce[NUM_SW] = { 0, 0, 0, 0, };
     //    // print_dbg("\r\n sw changed, count: ");
    //    // print_dbg_hex(swCount[idx]);
    if(swCount[idx]-- == 0) {
      // timer expired, accept change
      swDebounce[idx] = state;
      changed = 1;
      // reset timer
      if(swDebounce[idx]) {
	swCount[idx] = SW_RELEASE_TICKS;
      } else {
	swCount[idx] = SW_PRESS_TICKS;
      }
    }
  }
  if(changed) {
    // spawn event
    e.eventType = kSwitchEvents[idx][state];
    post_event(&e);

    //// print_dbg("\r\n posting SWITCH event, type: ");
    /* // print_dbg_hex(e.eventType); */

  }
}
#endif
