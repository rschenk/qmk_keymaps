#pragma once

#define TAPPING_TERM 190

/*
 * Essential home row mod configs.
 * see: https://precondition.github.io/home-row-mods
 */
// Prevent normal rollover on alphas from accidentally triggering home row mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Allow some nested taps to be considered holds
#define PERMISSIVE_HOLD_PER_KEY
/*
* Custom home row mod configs
*/
// Allow timing of each key to be customized
#define TAPPING_TERM_PER_KEY

#define TAPPING_TERM_OFFSET__SHIFT -15
#define TAPPING_TERM_OFFSET__CTRL 20
#define TAPPING_TERM_OFFSET__SPACE 85

/*
* End home row mod config
*/

#define CAPS_WORD_IDLE_TIMEOUT 5000  // Turn off Caps Word after 5 seconds.

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

/* LED Animations!
 * Check out quantum/rgblight.h for animation defs
*/

// #define RGBLIGHT_ANIMATIONS          /* enable all animations (can be big) */
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL   /* enable _only_ rainbow swirl */
#define RGBLIGHT_SLEEP                  /* turn off LEDs when host sleeps */
#define RGBLIGHT_LAYERS                 /* per-layer LED effects */
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_HUE 220        /* purple rain */
