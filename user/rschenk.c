#include "rschenk.h"

/* Callback for Caps-Word, which I am overriding to make semicolon not break
 * the caps-word. The reason for this is how MacOS handles Colemak-DH, the
 * keyboard thinks it's in QWERTY mode, and "o" is ";"
 */
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_SCLN:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

/* Create a "keymap space" callback function to allow overriding of
 * process_record_user. See:
 * https://docs.qmk.fm/#/feature_userspace?id=customized-functions
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_caps_word(keycode, record)) { return false; }

  return process_record_keymap(keycode, record);
}

__attribute__((weak)) void matrix_scan_keymap(void) { }

void matrix_scan_user(void) {
  achordion_task();
  caps_word_task();

  matrix_scan_keymap();
}

/*
 * Customize Achordion
 * TODO may need to extract this out to _keymap callback
 */
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Allow same-hand holds when the other key is in the rows below the alpha
  bool other_in_bottom_row = other_record->event.key.row % (MATRIX_ROWS / 2) >= 3;
  if (other_in_bottom_row) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

/*
 * Reduce Achordion timeout for allowing same-hand holds
 * and also optionally disable Archordion entirely for some keys
 */
__attribute__((weak)) uint16_t achordion_timeout_keymap(uint16_t tap_hold_keycode) {
  return ACHORDION_TIMEOUT;
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return achordion_timeout_keymap(tap_hold_keycode);
}

/*
 * Eagerly apply achordion modifiers on the left hand
 */
bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
    case MOD_LALT:
    case MOD_LGUI:
      return true;  // Eagerly apply Shift, Ctrl, and all left hand mods.

    default:
      return false;
  }
}

/*
 * Permissive hold only on shift keys
 */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_F:
    case SFT_N:
    case SFT_J:
    case SHFT_T:
      // For shift keys, immediately select the hold action when another key is tapped.
      return true;

    default:
      // Do not select the hold action when another key is tapped.
      return false;
  }
}

/*
 * Define tapping term for various keys
 */
__attribute__((weak)) uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record) {
  return TAPPING_TERM;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_F:
        case SFT_J:
        case SHFT_T:
        case SFT_N:
            return TAPPING_TERM + TAPPING_TERM_OFFSET__SHIFT;
        case CTL_O:
        case CTL_SCLN:
        case CTL_A:
        default:
            return get_tapping_term_keymap(keycode, record);
    }
}
