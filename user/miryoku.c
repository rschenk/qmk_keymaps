#ifdef USE_MIRYOKU_LAYOUT

#include QMK_KEYBOARD_H
#include "rschenk.h"
#include "miryoku.h"

// copied from users/manna-harbour_miryoku/manna-harbour_miryoku.h
// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

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
  [_BASE_Q] = LAYOUT_miryoku(
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_QUOT,
    CTL_A,             ALT_S,             GUI_D,             SFT_F,             KC_G,              KC_H,              SFT_J,             GUI_K,             ALT_L,             CTL_SCLN,
    LT(_BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(_BUTTON, KC_SLSH),
    U_NP,              U_NP,              ESC_MEDIA,         SP_NAV,            TAB_MOUSE,         ENT_SYM,           BSP_NUM,           DEL_FUN,           U_NP,              U_NP
  ),
  [_BASE_C] = LAYOUT_miryoku(
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    CTL_A,             ALT_R,             GUI_S,             SHFT_T,            KC_G,              KC_M,              SFT_N,             GUI_E,             ALT_I,             CTL_O,
    LT(_BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(_BUTTON, KC_SLSH),
    U_NP,              U_NP,              ESC_MEDIA,         SP_NAV,            TAB_MOUSE,         ENT_SYM,           BSP_NUM,           DEL_FUN,           U_NP,              U_NP
  ),
  [_NAV] = LAYOUT_miryoku(
    QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, U_NA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CAPS_WORD,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [_MOUSE] = LAYOUT_miryoku(
    QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, U_NA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  ),
  [_MEDIA] = LAYOUT_miryoku(
    QK_BOOT, QWERTY,  COLEMAK, U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NP,    U_NP
  ),
  [_NUM] = LAYOUT_miryoku(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT,
    SCLN,    KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DOT,  KC_0,    KC_MINS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [_SYM] = LAYOUT_miryoku(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT,
    COLN,    KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [_FUN] = LAYOUT_miryoku(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, U_NA,    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [_BUTTON] = LAYOUT_miryoku(
    U_UND,   U_CUT,   U_CPY,   PASTE,   U_RDO,   U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    U_UND,   U_CUT,   U_CPY,   PASTE,   U_RDO,   U_RDO,   PASTE,   U_CPY,   U_CUT,   U_UND,
    U_NP,    U_NP,    KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  )
};

/****************************************************************************
 *
 * End official Miryoku config, start my configs below
 *
 ***************************************************************************/

bool process_record_miryoku(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE_Q);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE_C);
      }
      return false;
    case PASTE:
      if (record->event.pressed) {
        uint16_t cmd_v = default_layer_aware_keycode(_BASE_Q, U_PST_Q, U_PST_C);
        tap_code16(cmd_v);
      }
      return false;
    case SCLN: ;
      uint16_t semicolon = default_layer_aware_keycode(_BASE_Q, SCLN_Q, SCLN_C);
      if (record->event.pressed) {
        register_code(semicolon);
      } else {
        unregister_code(semicolon);
      }
      return false;
    case COLN: ;
      uint16_t colon = default_layer_aware_keycode(_BASE_Q, COLN_Q, COLN_C);
      if (record->event.pressed) {
        register_code16(colon);
      } else {
        unregister_code16(colon);
      }
      return false;
  }

  return process_record_keymap(keycode, record);
}

/*
 * Achordion config
 */
uint16_t achordion_timeout_miryoku(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case ESC_MEDIA:
    case SP_NAV:
    case TAB_MOUSE:
    case ENT_SYM:
    case BSP_NUM:
    case DEL_FUN:
      return 0;  // Bypass Achordion for all thumb keys.
  }

  return achordion_timeout_keymap(tap_hold_keycode);
}

/*
 * Returns keycode1 if given layer is the current default layer, keycode2 otherwise.
 * This is used for sending different keycodes when in "qwerty" mode vs colemak.
 */
uint16_t default_layer_aware_keycode(uint8_t layer, uint16_t keycode_enabled, uint16_t keycode_disabled) {
  return get_highest_layer(default_layer_state) == layer ? keycode_enabled : keycode_disabled;
}

#endif
