#ifdef USE_RMS36_LAYOUT

/*
 * RMS-36 is my layout based _heavily_ on Miryoku, but I wanted to make some
 * tweaks and it was easier to recreate my own keymap than figure out wtf magic
 * is going on in the latest versions of official Miryoku.
 */

#include QMK_KEYBOARD_H
#include "rschenk.h"
#include "rms36.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_Q] = LAYOUT_rms36(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_QUOT,
    CTL_A,   ALT_S,   GUI_D,   SFT_F,   KC_G,    KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      ESC_MED, SPC_NAV, TAB_MSE, ENT_SYM, BSP_NUM, DEL_FUN
  ),
  [_BASE_C] = LAYOUT_rms36(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    CTL_A,   ALT_R,   GUI_S,   SHFT_T,  KC_G,    KC_M,    SFT_N,   GUI_E,   ALT_I,   CTL_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                      ESC_MED, SPC_NAV, TAB_MSE, ENT_SYM, BSP_NUM, DEL_FUN
  ),
  [_NAV] = LAYOUT_rms36(
    QK_BOOT, QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, U_REDO,  PASTE,   U_COPY,  U_CUT,   U_UNDO,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
                      XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_BSPC, KC_DEL
  ),
  [_MOUSE] = LAYOUT_rms36(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, U_REDO,  PASTE,   U_COPY,  U_CUT,   U_UNDO,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2
  ),
  [_MEDIA] = LAYOUT_rms36(
    QK_BOOT, QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE
  ),
  [_NUM] = LAYOUT_rms36(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX, XXXXXXX, COLEMAK, QWERTY,  QK_BOOT,
    SCLN,    KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_SLSH,
             KC_DOT,  KC_0,    KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_SYM] = LAYOUT_rms36(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, COLEMAK, QWERTY,  QK_BOOT,
    COLN,    KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_FUN] = LAYOUT_rms36(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, XXXXXXX, XXXXXXX, COLEMAK, QWERTY,  QK_BOOT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      KC_APP,  KC_SPC,  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX
  )
};

bool process_record_rms36(uint16_t keycode, keyrecord_t *record) {
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
 * Combos
 */
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case COLEMAK_RF_ARR:
        case COLEMAK_RS_ARR:
        case COLEMAK_LF_ARR:
        case COLEMAK_LS_ARR:
        case COLEMAK_PIPE:
        case COLEMAK_ESC_R:
        case COLEMAK_ESC_L:
          return IS_LAYER_ON_STATE(default_layer_state, _BASE_C);

        case QWERTY_RF_ARR:
        case QWERTY_RS_ARR:
        case QWERTY_LF_ARR:
        case QWERTY_LS_ARR:
        case QWERTY_PIPE:
        case QWERTY_ESC_R:
        case QWERTY_ESC_L:
          return IS_LAYER_ON_STATE(default_layer_state, _BASE_Q);
    }

    return true;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // or with combo index, i.e. its name from enum.
    switch (index) {
      case COMBO_CAPS_WORD:
            return COMBO_TERM_SLOW;
    }

    return COMBO_TERM;
}

/*
 * Achordion config
 */
uint16_t achordion_timeout_rms36(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case ESC_MED:
    case SPC_NAV:
    case TAB_MSE:
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
  return IS_LAYER_ON_STATE(default_layer_state, layer) ? keycode_enabled : keycode_disabled;
}

#endif
