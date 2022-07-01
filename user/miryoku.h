#if defined (USE_MIRYOKU_LAYOUT) && ! defined (MIRYOKU_H_)
#define MIRYOKU_H_

/* _BASE_Q and _BASE_C are two base layers, to accommodate Mac's OS-level
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
enum layers { _BASE_Q, _BASE_C, _BUTTON, _MEDIA, _NAV, _MOUSE, _SYM, _NUM, _FUN };

// Used to toggle between "qwerty" mode and Colemak-DH.
// "Qwerty" for compatibility with Mac's OS-level implementation of Colemak
enum meta_keycodes { QWERTY = SAFE_RANGE, COLEMAK, PASTE, SCLN, COLN };

// Ryan Custom keycodes that are used in miryoku layout below
#define ESC_MEDIA LT(_MEDIA, KC_ESC)
#define SP_NAV LT(_NAV, KC_SPC)
#define TAB_MOUSE LT(_MOUSE, KC_TAB)
#define ENT_SYM LT(_SYM, KC_ENT)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define DEL_FUN LT(_FUN, KC_DEL)
#define SCLN_Q KC_P
#define SCLN_C KC_SCLN
#define COLN_Q LSFT(KC_P)
#define COLN_C KC_COLN
#define U_PST_Q LCMD(KC_B)
#define U_PST_C LCMD(KC_V)

uint16_t default_layer_aware_keycode(uint8_t layer, uint16_t keycode_enabled, uint16_t keycode_disabled);
bool process_record_miryoku(uint16_t keycode, keyrecord_t *record);
uint16_t achordion_timeout_miryoku(uint16_t tap_hold_keycode);

#endif
