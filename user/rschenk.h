#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#include "miryoku.h"
#include "features/achordion.h"

/* Home row mods for Qwerty layer */
// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

/* Home row mods for Colemak layer */
// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define GUI_S LGUI_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define GUI_E RGUI_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define CTL_O RCTL_T(KC_O)

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
__attribute__((weak)) void matrix_scan_keymap(void);
__attribute__((weak)) uint16_t achordion_timeout_keymap(uint16_t tap_hold_keycode);
__attribute__((weak)) bool get_permissive_hold_keymap(uint16_t keycode, keyrecord_t *record);
__attribute__((weak)) uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record);

#endif
