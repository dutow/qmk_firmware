/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once

//#define IGNORE_MOD_TAP_INTERRUPT
//#define TAPPING_TERM 200

//#define ONESHOT_TAP_TOGGLE 3

//#define RGBLIGHT_SLEEP
//#undef RGBLIGHT_ANIMATIONS

#undef DEBOUNCE
#define DEBOUNCE 45
// Memory saving
#ifdef CONSOLE_ENABLE
#    define NO_DEBUG
#    define NO_PRINT
#endif

#define ONESHOT_TIMEOUT 2000
