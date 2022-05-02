// copied from users/manna-harbour_miryoku/manna-harbour_miryoku.h
// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "rschenk.h"

// Ryan Custom keycodes that are used in miryoku layout below
#define ESC_MEDIA LT(MEDIA, KC_ESC)
#define SP_NAV LT(NAV, KC_SPC)
#define TAB_MOUSE LT(MOUSE, KC_TAB)
#define ENT_SYM LT(SYM, KC_ENT)
#define BSP_NUM LT(NUM, KC_BSPC)
#define DEL_FUN LT(FUN, KC_DEL)
#define SCLN_Q KC_P
#define SCLN_C KC_SCLN
#define COLN_Q LSFT(KC_P)
#define COLN_C KC_COLN
#define U_PST_Q LCMD(KC_B)
#define U_PST_C LCMD(KC_V)
uint16_t default_layer_aware_keycode(uint8_t layer, uint16_t keycode_enabled, uint16_t keycode_disabled);

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

/* BASE_Q and BASE_C are two base layers, to accommodate Mac's OS-level
 * handling of Colemak-DH. When MacOS is set to use Colemak-DH, it wants to
 * "see" keycodes from a qwerty keyboard, which are then translated into
 * Colemak-DH. Therefore when my keyboard is plugged into my Mac set to
 * Colemak, the keyboard needs to be set to the BASE_Q layer. If using someone
 * else's computer, though, I would switch the keyboard to BASE_C.
 *
 * Things get kinda gnarly when the keyboard is trying to send paste commands
 * though, because Colemak-DH but the V key where B is in qwerty. So to get
 * around this, I have to check which base layer we're in before sending a
 * paste. Yikes.
 */

enum layers { BASE_Q, BASE_C, BUTTON, MEDIA, NAV, MOUSE, SYM, NUM, FUN };

// Used to toggle between "qwerty" mode and Colemak-DH.
// "Qwerty" for compatibility with Mac's OS-level implementation of Colemak
enum meta_keycodes { QWERTY = SAFE_RANGE, COLEMAK, PASTE, SCLN, COLN};

#define U_RDO SCMD(KC_Z)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

// copied from users/manna-harbour_miryoku/manna-harbour_miryoku.c
// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_Q] = LAYOUT_miryoku(
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_QUOT,
    CTL_A,             ALT_S,             GUI_D,             SFT_F,             KC_G,              KC_H,              SFT_J,             GUI_K,             ALT_L,             CTL_SCLN,
    LT(BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON, KC_SLSH),
    U_NP,              U_NP,              ESC_MEDIA,         SP_NAV,            TAB_MOUSE,         ENT_SYM,           BSP_NUM,           DEL_FUN,           U_NP,              U_NP
  ),
  [BASE_C] = LAYOUT_miryoku(
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    CTL_A,             ALT_R,             GUI_S,             SHFT_T,            KC_G,              KC_M,              SFT_N,             GUI_E,             ALT_I,             CTL_O,
    LT(BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON, KC_SLSH),
    U_NP,              U_NP,              ESC_MEDIA,         SP_NAV,            TAB_MOUSE,         ENT_SYM,           BSP_NUM,           DEL_FUN,           U_NP,              U_NP
  ),
  [NAV] = LAYOUT_miryoku(
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [MOUSE] = LAYOUT_miryoku(
    RESET,   U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  ),
  [MEDIA] = LAYOUT_miryoku(
    RESET,   QWERTY,  COLEMAK, U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NP,    U_NP
  ),
  [NUM] = LAYOUT_miryoku(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    SCLN,    KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DOT,  KC_0,    KC_MINS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [SYM] = LAYOUT_miryoku(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    COLN,    KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [FUN] = LAYOUT_miryoku(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,    U_NA,    U_NA,    U_NA,    RESET,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [BUTTON] = LAYOUT_miryoku(
    U_UND,   U_CUT,   U_CPY,   PASTE,   U_RDO,   U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_UND,   U_CUT,   U_CPY,   PASTE,   U_RDO,   U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    U_NP,    U_NP,    KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  )
};

/****************************************************************************
 *
 * End Miryoku config, start my configs below
 *
 ***************************************************************************/

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(BASE_Q);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(BASE_C);
      }
      return false;
    case PASTE:
      if (record->event.pressed) {
        uint16_t cmd_v = default_layer_aware_keycode(BASE_Q, U_PST_Q, U_PST_C);
        tap_code16(cmd_v);
      }
      return false;
    case SCLN: ;
      uint16_t semicolon = default_layer_aware_keycode(BASE_Q, SCLN_Q, SCLN_C);
      if (record->event.pressed) {
        register_code(semicolon);
      } else {
        unregister_code(semicolon);
      }
      return false;
    case COLN: ;
      uint16_t colon = default_layer_aware_keycode(BASE_Q, COLN_Q, COLN_C);
      if (record->event.pressed) {
        register_code16(colon);
      } else {
        unregister_code16(colon);
      }
      return false;
  }
  return true;
}

/* Per-layer LED effects
 * LED physical location index
 *   6 5 4 3
 *      0
 *   7 8 1 2
 */
const rgblight_segment_t PROGMEM rgb_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
//{ start index, number of leds to light, color }
  {1, 1, 223, 255, 255},
  {2, 1, 233, 255, 255},
  {3, 1, 243, 255, 255},
  {4, 1, 253, 255, 255}

);
const rgblight_segment_t PROGMEM rgb_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
  {8, 1, 223, 255, 255},
  {7, 1, 233, 255, 255},
  {6, 1, 243, 255, 255},
  {5, 1, 253, 255, 255} // HSV_MAGENTA = 213, 255, 255
);
const rgblight_segment_t PROGMEM rgb_layer_top[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 4, 255, 255, 255}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_right,
    rgb_layer_left,
    rgb_layer_top
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  bool right_active = layer_state_cmp(state, NAV) ||
                      layer_state_cmp(state, MOUSE) ||
                      layer_state_cmp(state, MEDIA);

  bool left_active = layer_state_cmp(state, NUM) ||
                     layer_state_cmp(state, SYM) ||
                     layer_state_cmp(state, FUN);

  rgblight_set_layer_state(0, right_active);
  rgblight_set_layer_state(1, left_active);
  rgblight_set_layer_state(2, layer_state_cmp(state, BUTTON));
  return state;
}

void caps_word_set_user(bool caps_word_active) {
  rgblight_set_layer_state(2, caps_word_active);
}

/*
 * Achordion config
 */
uint16_t achordion_timeout_keymap(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case ESC_MEDIA:
    case SP_NAV:
    case TAB_MOUSE:
    case ENT_SYM:
    case BSP_NUM:
    case DEL_FUN:
      return 0;  // Bypass Achordion for all thumb keys.
  }

  return ACHORDION_TIMEOUT; // Otherwise use this timeout
}

/*
 * Returns keycode1 if given layer is the current default layer, keycode2 otherwise.
 * This is useful for sending different keycodes when in "qwerty" mode vs colemak.
 */
uint16_t default_layer_aware_keycode(uint8_t layer, uint16_t keycode_enabled, uint16_t keycode_disabled) {
  return biton32(default_layer_state) == layer ? keycode_enabled : keycode_disabled;
}

