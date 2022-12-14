#if defined (USE_RMS36_LAYOUT) && ! defined (RMS36_H_)
#define RMS36_H_

/*
 * RMS-36 is my layout based _heavily_ on Miryoku, but I wanted to make some
 * tweaks and it was easier to recreate my own keymap than figure out wtf magic
 * is going on in the latest versions of official Miryoku.
 *
 * _BASE_Q and _BASE_C are two base layers, to accommodate Mac's OS-level
 * handling of Colemak-DH. When MacOS is set to use Colemak-DH, it wants to
 * "see" keycodes from a qwerty keyboard, which are then translated into
 * Colemak-DH. Therefore when my keyboard is plugged into my Mac set to
 * Colemak, the keyboard needs to be set to the _BASE_Q layer. If using someone
 * else's computer, though, I would switch the keyboard to _BASE_C.
 *
 * Things get kinda gnarly when the keyboard is trying to send paste commands
 * though, because Colemak-DH but the V key where B is in qwerty. So to get
 * around this, I have to check which base layer we're in before sending a
 * paste. Yikes.
 */
enum layers { _BASE_Q, _BASE_C, _MEDIA, _NAV, _MOUSE, _SYM, _NUM, _FUN };

// Used to toggle between "qwerty" mode and Colemak-DH.
// "Qwerty" for compatibility with Mac's OS-level implementation of Colemak
enum meta_keycodes { QWERTY = SAFE_RANGE, COLEMAK, PASTE, SCLN, COLN };

// Ryan Custom keycodes that are used in rms36 layout below
#define ESC_MED LT(_MEDIA, KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_MSE LT(_MOUSE, KC_TAB)
#define ENT_SYM LT(_SYM, KC_ENT)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define DEL_FUN LT(_FUN, KC_DEL)
#define SCLN_Q KC_P
#define SCLN_C KC_SCLN
#define COLN_Q LSFT(KC_P)
#define COLN_C KC_COLN
#define U_COPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_PST_Q LCMD(KC_B)
#define U_PST_C LCMD(KC_V)
#define U_UNDO LCMD(KC_Z)
#define U_REDO LCMD(LSFT(KC_C))

uint16_t default_layer_aware_keycode(uint8_t layer, uint16_t keycode_enabled, uint16_t keycode_disabled);
bool process_record_rms36(uint16_t keycode, keyrecord_t *record);
uint16_t achordion_timeout_rms36(uint16_t tap_hold_keycode);

#endif
