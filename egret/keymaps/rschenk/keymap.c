/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "rschenk.h"

/* Per-layer LED effects
 * .-----------.    .-----------.
 * |  2  1  0  |    | 11 10  9  |
 * |           |    |           |
 * |  3  4  5  |    |  6  7  8  |
 * '-----------'    '-----------'
 */
const rgblight_segment_t PROGMEM rgb_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
//{ start index, number of leds to light, color }
  {2, 1, 253, 255, 255}, {1, 1, 243, 255, 255}, {0, 1, 233, 255, 255},
  {3, 1, 243, 255, 255}, {4, 1, 233, 255, 255}, {5, 1, 223, 255, 255}
);
const rgblight_segment_t PROGMEM rgb_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
  {11, 1, 233, 255, 255}, {10, 1, 243, 255, 255}, {9, 1, 253, 255, 255},
  { 6, 1, 223, 255, 255}, { 7, 1, 233, 255, 255}, {8, 1, 243, 255, 255}
);
const rgblight_segment_t PROGMEM rgb_layer_bottom[] = RGBLIGHT_LAYER_SEGMENTS(
  {4, 4, 255, 255, 255},
  {0, 1, 255, 255, 255},
  {11, 1, 255, 255, 255}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_right,
    rgb_layer_left,
    rgb_layer_bottom
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

  bool bottom_active = is_caps_word_on();

  rgblight_set_layer_state(0, right_active);
  rgblight_set_layer_state(1, left_active);
  rgblight_set_layer_state(2, bottom_active);
  return state;
}

void caps_word_set_user(bool active) {
  rgblight_set_layer_state(2, active);
}
