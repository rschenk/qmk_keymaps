// copied from users/manna-harbour_miryoku/manna-harbour_miryoku.h
// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "rschenk.h"

/* Per-layer LED effects
 * LED physical location index
 *   6 5 4 3
 *      0
 *   7 8 1 2
 */
const rgblight_segment_t PROGMEM rgb_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
//{ start index, number of leds to light, color }
  {1, 1, 223, 255, 255},
  {2, 1, 233, 255, 255},
  {3, 1, 243, 255, 255},
  {4, 1, 253, 255, 255}

);
const rgblight_segment_t PROGMEM rgb_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
  {8, 1, 223, 255, 255},
  {7, 1, 233, 255, 255},
  {6, 1, 243, 255, 255},
  {5, 1, 253, 255, 255} // HSV_MAGENTA = 213, 255, 255
);
const rgblight_segment_t PROGMEM rgb_layer_top[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 4, 255, 255, 255}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_right,
    rgb_layer_left,
    rgb_layer_top
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  bool right_active = layer_state_cmp(state, _NAV) ||
                      layer_state_cmp(state, _MOUSE) ||
                      layer_state_cmp(state, _MEDIA);

  bool left_active = layer_state_cmp(state, _NUM) ||
                     layer_state_cmp(state, _SYM) ||
                     layer_state_cmp(state, _FUN);

  rgblight_set_layer_state(0, right_active);
  rgblight_set_layer_state(1, left_active);
  rgblight_set_layer_state(2, layer_state_cmp(state, _BUTTON));
  return state;
}

void caps_word_set_user(bool caps_word_active) {
  rgblight_set_layer_state(2, caps_word_active);
}
