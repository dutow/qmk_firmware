#include QMK_KEYBOARD_H
#include "version.h"

// Originally was based on: Beakl Opted v2

enum layers { BASE, TOG1, TOG2, NAVI, SYMB };

// macros

enum macros {
    M_COPYPASTE = SAFE_RANGE,  //
    M_CTL_L1,
    M_CTL_R1,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   {    |   4  |   2  |   1  |   3  |   5  |      |           |      |   8  |   6  |   0  |   7  |   9  |   }    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   [    |   z  |   n  |   m  |   c  |   g  | copy |           |      |   '  |   o  |   i  |   u  |   j  |   ]    |
   * |--------+------+------+------+------+------| paste|           |      |------+------+------+------+------+--------|
   * |   ( SFT|   p  |   r  |   t  |   s  |   d  |------|           |------|   ?  |   a  |   e  |   h  |   k  |   ) SFT|
   * |--------+------+------+------+------+------|  esc |           |      |------+------+------+------+------+--------|
   * |   < CTR|   v  |   l  |   w  |   f  |   b  |      |           |      |   q  |   ,  |   "  |   y  |   x  |   > CTL|
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | shift| ctrl | alt  | Left | Right|                                       |  Up  | Down | alt  | ctrl | shift|
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      | WIN  |       |      |        |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | HOME |       |      |        |  /   |
   *                                 |------|------|------|       |------|--------|------|
   *                                 | L2   |  L1  |      |       | bksp |  Enter | Space|
   *                                 `--------------------'       `----------------------'
   */ 
  [BASE] = LAYOUT_ergodox_80(  // layer 0 : default
      // left hand
      KC_LCBR,        KC_4,           KC_2,           KC_1,           KC_3,           KC_5,           TG(NAVI),
      KC_MS_WH_UP,    KC_Z,           KC_N,           KC_M,           KC_C,           KC_G,           KC_COLON,
      LCTL(KC_PGUP),  KC_P,           KC_R,           KC_T,           KC_S,           KC_D,
      KC_PGUP,        KC_V,           KC_L,           KC_W,           KC_F,           KC_B,           KC_ESC,
      LCTL(KC_PGUP),  KC_MS_WH_UP,    KC_ESC,         SH_OS,          OSL(NAVI),

                      LCTL(KC_B),            OSM(MOD_LGUI),
      OSM(MOD_LALT),  OSM(MOD_LCTL),         OSM(MOD_LSFT),
      OSL(SYMB),      OSL(TOG1),             OSL(TOG2),

      // right hand
      KC_1,           KC_8,           KC_6,           KC_0,           KC_7,           KC_9,           KC_RCBR,
      KC_COLON,       KC_QUOTE,       KC_O,           KC_I,           KC_U,           KC_J,           KC_MS_WH_DOWN,
                      KC_DOT,         KC_A,           KC_E,           KC_H,           KC_K,           LCTL(KC_PGDN),
      KC_SLASH,       KC_Q,           KC_COMMA,       KC_DQUO,        KC_Y,           KC_X,           KC_PGDN,
                                      RCTL(KC_B),     OSM(MOD_LGUI),  KC_RALT,        KC_MS_WH_DOWN,  LCTL(KC_PGDN),

      KC_LALT,        CTL_T(KC_ESC),
      OSM(MOD_RSFT),  OSM(MOD_RCTL),  OSM(MOD_RALT),
      KC_BSPC,        KC_SPC,         KC_ENT
  ),
      /* Keymap 1: Symbol Layer
       *
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
       * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
       *   `----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      |      |       |      |      |
       *                                 ,------|------|------|       |------+------+------.
       *                                 |      |      |      |       |      |      |      |
       *                                 |------|------|------|       |------|------|------|
       *                                 |      |      |      |       |      |      |      |
       *                                 `--------------------'       `--------------------'
       */
      // "Shifty" - upper case chars and some extra
      [TOG1] = LAYOUT_ergodox_80(  // layer 0 : default
          // left hand
          KC_TRNS,        KC_DLR,         KC_AT,          KC_HASH,        KC_EXLM,        KC_PERC,        KC_TRNS,
          KC_TRNS,        S(KC_Z),        S(KC_N),        S(KC_M),        S(KC_C),        S(KC_G),        KC_TRNS,
          KC_AMPR,        S(KC_P),        S(KC_R),        S(KC_T),        S(KC_S),        S(KC_D),     
          KC_TILD,        S(KC_V),        S(KC_L),        S(KC_W),        S(KC_F),        S(KC_B),        KC_TRNS,
          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,

                          KC_TRNS,        KC_TRNS,
          KC_TRNS,        KC_TRNS,        KC_TRNS,
          KC_TRNS,        KC_TRNS,        KC_TRNS,        

          // right hand
          LALT(KC_F4),    KC_ASTR,        KC_MINUS,       KC_EQUAL,       KC_PLUS,        KC_CIRC,        KC_TRNS,
          KC_TRNS,        KC_COLON,       S(KC_O),        S(KC_I),        S(KC_U),        S(KC_J),        KC_TRNS,
                          KC_QUES,        S(KC_A),        S(KC_E),        S(KC_H),        S(KC_K),        KC_PIPE,
          KC_BSLASH,      S(KC_Q),        KC_UNDS,        KC_SCOLON,      S(KC_Y),        S(KC_X),        KC_GRAVE,
                                          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,

          KC_TRNS,        KC_TRNS,
          KC_TRNS,        KC_TRNS,        KC_TRNS,
          KC_DEL,         KC_TAB,         KC_TRNS
            ),
          /* Keymap 2: Media and mouse keys
           *
           * ,--------------------------------------------------.           ,--------------------------------------------------.
           * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
           * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
           * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
           * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
           * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
           * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
           * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
           * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
           *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
           *   `----------------------------------'                                       `----------------------------------'
           *                                        ,-------------.       ,-------------.
           *                                        |      |      |       |      |      |
           *                                 ,------|------|------|       |------+------+----------.
           *                                 |      |      |      |       |      |      |          |
           *                                 |------|------|------|       |------|------|----------|
           *                                 |      |      |      |       |      |      |BrwserBack|
           *                                 `--------------------'       `------------------------'
           */
          // MEDIA AND MOUSE
          [TOG2] = LAYOUT_ergodox_80(
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,     
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_F1,        	KC_F2,          KC_F3,          KC_F4,          KC_F5,

              KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        

              // right hand
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,

              KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS
                ),

          [NAVI] = LAYOUT_ergodox_80(
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_TRNS,     
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,

                              KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        

              // right hand
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                              KC_TRNS,        LCTL(KC_PGUP),  KC_PGUP,        KC_PGDN,        LCTL(KC_PGDN),  KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,

              KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS
                ),

          [SYMB] = LAYOUT_ergodox_80(
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_AMPR,        KC_TILD,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_LABK,       KC_LPRN,        KC_LBRACKET,    KC_LCBR,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,

                              KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,

              // right hand
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_PIPE,        KC_GRAVE,       KC_TRNS,        KC_TRNS,        KC_TRNS,
                              KC_TRNS,        KC_RCBR,        KC_RBRACKET,    KC_RPRN,        KC_RABK,        KC_TRNS,     
              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                              KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,

              KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS,
              KC_TRNS,        KC_TRNS,        KC_TRNS
                ),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_COPYPASTE:  // copy paste
        {
            static uint16_t key_timer;
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {  // released
                if (timer_elapsed(key_timer) > 250) {
                    SEND_STRING(SS_LCTL("c"));
                } else {
                    SEND_STRING(SS_LCTL("v"));
                }
            }
            break;
        }
        case M_CTL_L1:  // ctl-cadet at left bottom
        {
            static uint16_t key_timer;
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if (timer_elapsed(key_timer) < 250) {
                    SEND_STRING("<");
                }
            }
            break;
        }
        case M_CTL_R1:  // ctl-cadet at right bottom
        {
            static uint16_t key_timer;
            if (record->event.pressed) {
                key_timer = timer_read();
                register_code(KC_RCTL);
            } else {
                unregister_code(KC_RCTL);
                if (timer_elapsed(key_timer) < 250) {
                    SEND_STRING(">");
                }
            }
            break;
        }
    }
    return true;
};
