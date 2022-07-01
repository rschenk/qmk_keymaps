/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "rschenk.h"

enum planck_layers {
  _QWERTY,
  _COLEMAK_DH,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVIGATION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  BACKLIT,
  EXT_PLV,
  ERB_TAG
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAVIGATION)
#define SP_NAV LT(_NAVIGATION, KC_SPC)
#define CTL_ESC LCTL_T(KC_ESC)
#define ENT_SFT RSFT_T(KC_ENT)
#define CMD_BSL LCMD(KC_BSLASH)
#define CMD_0   LCMD(KC_0)
#define CMD_1   LCMD(KC_1)

/* Tapdance declarations */
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    EX_PIPE,  // |> and ||=
    ARROW_OP, // -> and <-
    FAT_ARROW // =>
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void pipe_finished(qk_tap_dance_state_t *state, void *user_data);
void pipe_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, CTL_A,   ALT_S,   GUI_D,   SFT_F,   KC_G,    KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SCLN,KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT,
    NAV,     KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SP_NAV,  SP_NAV,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_DH] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    CTL_ESC, CTL_A,   ALT_R,   GUI_S,   SHFT_T,  KC_G,    KC_M,    SFT_N,   GUI_E,   ALT_I,   CTL_O,   KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT,
    NAV,     KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SP_NAV,  SP_NAV,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ | <%=  | Home |  End |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Play | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, TD(EX_PIPE),
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), ERB_TAG,    KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MPLY,    KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Play | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,         KC_8,           KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   TD(ARROW_OP), TD(FAT_ARROW),  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS,      KC_NUBS,        KC_PGDN, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,      KC_MPLY,        KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Vim style navigation keys */
[_NAVIGATION] = LAYOUT_planck_grid(
    CMD_0,   CMD_1,   _______, _______, DT_UP,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, DT_PRNT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, CMD_BSL,
    _______, _______, _______, _______, DT_DOWN, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

 enum combo_events {
  CAPS_COMBO_QWERTY,
  CAPS_COMBO_COLEMAK,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_combo_querty[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM caps_combo_colemak[] = {KC_D, KC_H, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO_QWERTY] = COMBO_ACTION(caps_combo_querty),
  [CAPS_COMBO_COLEMAK] = COMBO_ACTION(caps_combo_colemak),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    switch(combo_index) {
      case CAPS_COMBO_QWERTY:
      case CAPS_COMBO_COLEMAK:
        caps_word_set(true);  // Activate Caps Word.
        break;
    }
  }
}

void caps_word_set_user(bool active) {
  rgblight_set_layer_state(3, active);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _NAVIGATION));
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DH);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case ERB_TAG:
      if (record->event.pressed) {
        SEND_STRING("<%=  %>");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_keymap(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

/* LED layers for raise and lower */
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // { start index, number of leds to light, color }
    {1, 1,  85, 255, 255},   // HSV_GREEN = 85, 255, 255
    {2, 1,  95, 255, 255},
    {3, 1, 105, 255, 255},
    {4, 1, 115, 255, 255}
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, 183, 255, 255},
    {6, 1, 193, 255, 255},
    {7, 1, 203, 255, 255},
    {8, 1, 213, 255, 255} // HSV_MAGENTA = 213, 255, 255
);

const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1,  10, 255, 255},
    {4, 1,   0, 255, 255},
    {5, 1, 245, 255, 255},
    {6, 1, 235, 255, 255}
);

const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, 255, 255, 255},
    {4, 1, 255, 255, 255},
    {5, 1, 255, 255, 255},
    {6, 1, 255, 255, 255}
);


// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_raise_layer,
    my_lower_layer,    // Overrides other layers
    my_nav_layer,
    my_caps_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

uint16_t achordion_timeout_keymap(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case SP_NAV:
      return 0;  // Bypass Achordion for these keys.
  }

  return ACHORDION_TIMEOUT; // Otherwise use this timeout
}


/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the tap dance.
static td_tap_t current_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void pipe_finished(qk_tap_dance_state_t *state, void *user_data) {
    current_tap_state.state = cur_dance(state);
    switch (current_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_PIPE); break;
        case TD_SINGLE_HOLD: SEND_STRING("|> "); break;
        case TD_DOUBLE_TAP: SEND_STRING("||"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("||= "); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE); break;
        case TD_TRIPLE_HOLD:
        case TD_TRIPLE_TAP: SEND_STRING("|||"); break;
        default: register_code16(KC_PIPE);
    }
}

void pipe_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (current_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE);
        case TD_TRIPLE_HOLD: break;
        case TD_TRIPLE_TAP: break;
        default: unregister_code16(KC_PIPE);
    }
    current_tap_state.state = TD_NONE;
}

void dash_finished(qk_tap_dance_state_t *state, void *user_data) {
    current_tap_state.state = cur_dance(state);
    switch (current_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_MINUS); break;
        case TD_SINGLE_HOLD: SEND_STRING("->"); break;
        case TD_DOUBLE_TAP: SEND_STRING("--"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("<-"); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case TD_TRIPLE_HOLD:
        case TD_TRIPLE_TAP: SEND_STRING("---"); break;
        default: register_code16(KC_MINUS);
    }
}

void dash_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (current_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS);
        case TD_TRIPLE_HOLD: break;
        case TD_TRIPLE_TAP: break;
        default: unregister_code16(KC_MINUS);
    }
    current_tap_state.state = TD_NONE;
}

void eq_finished(qk_tap_dance_state_t *state, void *user_data) {
    current_tap_state.state = cur_dance(state);
    switch (current_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_EQUAL); break;
        case TD_SINGLE_HOLD: SEND_STRING("=>"); break;
        case TD_DOUBLE_TAP: SEND_STRING("=="); break;
        case TD_DOUBLE_HOLD: SEND_STRING("=="); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case TD_TRIPLE_HOLD:
        case TD_TRIPLE_TAP: SEND_STRING("==="); break;
        default: register_code16(KC_EQUAL);
    }
}

void eq_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (current_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL);
        case TD_TRIPLE_HOLD: break;
        case TD_TRIPLE_TAP: break;
        default: unregister_code16(KC_EQUAL);
    }
    current_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [EX_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pipe_finished, pipe_reset),
    [ARROW_OP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dash_finished, dash_reset),
    [FAT_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, eq_finished, eq_reset),
};

uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SP_NAV:
            return TAPPING_TERM + TAPPING_TERM_OFFSET__SPACE;
        default:
            return TAPPING_TERM;
    }
}
