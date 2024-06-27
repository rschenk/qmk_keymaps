// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_vallium.h"
#include "swapper.h"

#define _DEF 0
#define _SYM 1
#define _NAV 2
#define _NUM 3
#define _SYS 4

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define UNDO LGUI(VM_Z)
#define CUT LGUI(VM_X)
#define COPY LGUI(VM_C)
#define PASTE LGUI(VM_V)

enum keycodes {
    SW_WIN = SAFE_RANGE // Switch to next window (cmd-tab)
};

enum combos {

    CMB_LBKT,
    CMB_LPAR,
    CMB_LBRC,
    CMB_RBRC,
    CMB_RPAR,
    CMB_RBKT,

    CMB_ENT,
    CMB_ESC,
    CMB_TAB,
    CMB_BSP,
    CMB_SYS_LAYER,

    CMB_SEL_ALL
};

const uint16_t PROGMEM lbkt_combo[] = {VM_L, VM_R, COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {VM_D, VM_T, COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {VM_W, VM_S, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {VM_F, VM_H, COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {VM_O, VM_E, COMBO_END};
const uint16_t PROGMEM rbkt_combo[] = {VM_U, VM_I, COMBO_END};

const uint16_t PROGMEM ent_combo[] = {VM_F, VM_O, VM_U, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {VM_L, VM_D, VM_W, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {VM_X, VM_M, VM_C, COMBO_END};
const uint16_t PROGMEM bsp_combo[] = {VM_P, VM_COMM, VM_DOT, COMBO_END};
const uint16_t PROGMEM sys_layer_combo[] = {KC_SPC, OSM_SFT, COMBO_END};

const uint16_t PROGMEM sel_all_combo[] = {CUT, COPY, COMBO_END};

combo_t key_combos[] = {
    [CMB_LBKT] = COMBO(lbkt_combo, VM_LBRC),
    [CMB_LPAR] = COMBO(lpar_combo, VM_LPRN),
    [CMB_LBRC] = COMBO(lbrc_combo, VM_LCBR),
    [CMB_RBRC] = COMBO(rbrc_combo, VM_RCBR),
    [CMB_RPAR] = COMBO(rpar_combo, VM_RPRN),
    [CMB_RBKT] = COMBO(rbkt_combo, VM_RBRC),

    [CMB_ENT] = COMBO(ent_combo, KC_ENT),
    [CMB_ESC] = COMBO(esc_combo, KC_ESC),
    [CMB_TAB] = COMBO(tab_combo, KC_TAB),
    [CMB_BSP] = COMBO(bsp_combo, KC_BSPC),
    [CMB_SYS_LAYER] = COMBO(sys_layer_combo, MO(_SYS)),

    [CMB_SEL_ALL] = COMBO(sel_all_combo, LGUI(VM_A))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_split_3x5_2(
        VM_Q,    VM_L,    VM_D,    VM_W,    VM_B,                               VM_Z,    VM_F,    VM_O,    VM_U,    VM_QUOT,
        VM_N,    VM_R,    VM_T,    VM_S,    VM_G,                               VM_Y,    VM_H,    VM_E,    VM_I,    VM_A,
        VM_J,    VM_X,    VM_M,    VM_C,    VM_V,                               VM_K,    VM_P,    VM_COMM, VM_DOT,  VM_SLSH,
                                            MO(_NAV), KC_SPC,          OSM_SFT, MO(_SYM)
    ),

    [_SYM] = LAYOUT_split_3x5_2(
        _______, VM_HASH, VM_PERC, VM_AT,   VM_PLUS,                            VM_TILD, _______, VM_ASTR, _______, VM_GRV,
        VM_COLN, VM_EXLM, VM_EQL,  VM_UNDS, VM_PIPE,                            VM_BSLS, OSM_SFT, OSM_GUI, OSM_ALT, OSM_CTL,
        VM_AMPR, VM_CIRC, VM_DLR,  VM_MINS, _______,                            _______, VM_SLSH, VM_LABK, VM_RABK, _______,
                                            _______, _______,          _______, _______
    ),

    [_NAV] = LAYOUT_split_3x5_2(
        _______, SW_WIN,  _______, _______, KC_TAB,                             _______, _______, _______, _______, _______,
        OSM_CTL, OSM_ALT, OSM_GUI, OSM_SFT, KC_BSPC,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        UNDO,    CUT,     COPY,    PASTE,   KC_ENT,                             KC_ENT,  KC_BSPC, KC_TAB,  _______, _______,
                                            _______, _______,          _______, _______
    ),

    [_NUM] = LAYOUT_split_3x5_2(
        _______, VM_7,    VM_8,    VM_9,    _______,                            _______, _______, _______, _______, VM_DQUO,
        VM_SCLN, VM_1,    VM_2,    VM_3,    VM_0,                               _______, OSM_SFT, OSM_GUI, OSM_ALT, OSM_CTL,
        _______, VM_4,    VM_5,    VM_6,    _______,                            _______, VM_SLSH, VM_COMM, VM_DOT,  _______,
                                            _______, _______,          _______, _______
    ),

    [_SYS] = LAYOUT_split_3x5_2(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                            KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______,          _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN, OSM_SFT,
        keycode, record
    );

    return true;
}
