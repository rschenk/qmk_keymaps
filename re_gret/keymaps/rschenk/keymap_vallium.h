// Copyright 2024 Ryan Schenk (@rschenk)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
 * Key bindings for the Vallium layout mapped in the OS
 * See: https://docs.qmk.fm/reference_keymap_extras 
 */

#pragma once
#include "keycodes.h"
// clang-format off

// Aliases
#define VM_GRV  KC_GRV  // `
#define VM_1    KC_1    // 1
#define VM_2    KC_2    // 2
#define VM_3    KC_3    // 3
#define VM_4    KC_4    // 4
#define VM_5    KC_5    // 5
#define VM_6    KC_6    // 6
#define VM_7    KC_7    // 7
#define VM_8    KC_8    // 8
#define VM_9    KC_9    // 9
#define VM_0    KC_0    // 0
#define VM_MINS KC_MINS // -
#define VM_EQL  KC_EQL  // =
#define VM_Q    KC_Q    // Q
#define VM_W    KC_R    // W
#define VM_F    KC_U    // F
#define VM_P    KC_M    // P
#define VM_G    KC_G    // G
#define VM_J    KC_Z    // J
#define VM_L    KC_W    // L
#define VM_U    KC_O    // U
#define VM_Y    KC_H    // Y
#define VM_SCLN KC_P    // ;
#define VM_LBRC KC_LBRC // [
#define VM_RBRC KC_RBRC // ]
#define VM_BSLS KC_BSLS // (backslash)
#define VM_A    KC_SCLN // A
#define VM_R    KC_S    // R
#define VM_S    KC_F    // S
#define VM_T    KC_D    // T
#define VM_D    KC_E    // D
#define VM_H    KC_J    // H
#define VM_N    KC_A    // N
#define VM_E    KC_K    // E
#define VM_I    KC_L    // I
#define VM_O    KC_I    // O
#define VM_QUOT KC_QUOT // '
#define VM_Z    KC_Y    // Z
#define VM_X    KC_X    // X
#define VM_C    KC_V    // C
#define VM_V    KC_B    // V
#define VM_B    KC_T    // B
#define VM_K    KC_N    // K
#define VM_M    KC_C    // M
#define VM_COMM KC_COMM // ,
#define VM_DOT  KC_DOT  // .
#define VM_SLSH KC_SLSH // /
#define VM_TILD S(VM_GRV)  // ~
#define VM_EXLM S(VM_1)    // !
#define VM_AT   S(VM_2)    // @
#define VM_HASH S(VM_3)    // #
#define VM_DLR  S(VM_4)    // $
#define VM_PERC S(VM_5)    // %
#define VM_CIRC S(VM_6)    // ^
#define VM_AMPR S(VM_7)    // &
#define VM_ASTR S(VM_8)    // *
#define VM_LPRN S(VM_9)    // (
#define VM_RPRN S(VM_0)    // )
#define VM_UNDS S(VM_MINS) // _
#define VM_PLUS S(VM_EQL)  // +
#define VM_COLN S(VM_SCLN) // :
#define VM_LCBR S(VM_LBRC) // {
#define VM_RCBR S(VM_RBRC) // }
#define VM_PIPE S(VM_BSLS) // |
#define VM_DQUO S(VM_QUOT) // "
#define VM_LABK S(VM_COMM) // <
#define VM_RABK S(VM_DOT)  // >
#define VM_QUES S(VM_SLSH) // ?

