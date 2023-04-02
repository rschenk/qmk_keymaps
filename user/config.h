
/* Home row mod configs.
 * see: https://precondition.github.io/home-row-mods
 */
#undef TAPPING_TERM
#undef IGNORE_MOD_TAP_INTERRUPT
#undef TAPPING_FORCE_HOLD
#undef PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM 190
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_OFFSET__SHIFT -15
#define TAPPING_TERM_OFFSET__CTRL 20
#define TAPPING_TERM_OFFSET__SPACE 85

#define COMBO_TERM 25
#define COMBO_TERM_SLOW 75
#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM_PER_COMBO

#define ACHORDION_TIMEOUT 500

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // enable _only_ rainbow swirl
  #define RGBLIGHT_SLEEP                  // turn off LEDs when host sleeps
  #define RGBLIGHT_LAYERS                 // per-layer LED effects
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
  #define RGBLIGHT_DEFAULT_HUE 220        // purple rain
#endif

#ifdef USE_RMS36_LAYOUT

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
#endif
