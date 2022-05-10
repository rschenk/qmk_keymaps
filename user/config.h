
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

#define ACHORDION_TIMEOUT 500

#define CAPS_WORD_IDLE_TIMEOUT 5000  // Turn off Caps Word after 5 seconds.

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // enable _only_ rainbow swirl
  #define RGBLIGHT_SLEEP                  // turn off LEDs when host sleeps
  #define RGBLIGHT_LAYERS                 // per-layer LED effects
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
  #define RGBLIGHT_DEFAULT_HUE 220        // purple rain
#endif

#ifdef USE_MIRYOKU_LAYOUT
// copied from users/manna-harbour_miryoku/config.h
// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

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
