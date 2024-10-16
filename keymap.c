/* Copyright 2023 splitkb.com <support@splitkb.com>
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

#include <stdint.h>
#include "features/achordion.h"
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _QWERTY_STATIC,
    _NAV,
    _SYM,
    _NUM,
    _FUNCTION,
    _SYMR,
    _ADJUST,
};

// Aliases for readability
#define BASE     DF(_QWERTY)
#define GAME     DF(_QWERTY_STATIC)

// COLEMAK_DH only as a temporary switch

#define SYM      MO(_SYM)
#define SYMR     MO(_SYMR)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define NUM      MO(_NUM)
#define ADJUST   MO(_ADJUST)

#define NAV_ESC     LT(NAV, KC_ESC)
#define NUM_TAB     LT(NUM, KC_TAB)
#define NAV_BSPC    LT(NAV, KC_BSPC)
#define SYM_SPC     LT(SYM, KC_SPC)
#define FKEYS_ENT   LT(FKEYS, KC_ENT)

// home row mods
#define GUI_A       MT(MOD_LGUI, KC_A)
#define ALT_S       MT(MOD_LALT, KC_S)
#define SHFT_D      MT(MOD_LSFT, KC_D)
#define CTL_F       MT(MOD_LCTL, KC_F)

#define CTL_J       MT(MOD_RCTL, KC_J)
#define SHFT_K      MT(MOD_RSFT, KC_K)
#define ALT_L       MT(MOD_LALT, KC_L)
#define GUI_SCLN    MT(MOD_RGUI, KC_SCLN)



// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] =
#include "layers/lay_qwerty_main.inl"
    [_QWERTY_STATIC] =
#include "layers/lay_qwerty_static.inl"
    [_NAV] =
#include "layers/lay_nav.inl"
    [_SYM] =
#include "layers/lay_sym.inl"
    [_NUM] =
#include "layers/lay_num.inl"
    [_FUNCTION] =
#include "layers/lay_fun.inl"
    [_ADJUST] =
#include "layers/lay_adjust.inl"
    [_SYMR] =
#include "layers/lay_template.inl"
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
bool oled_task_user(void) {
  // Your code goes here
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Your code goes here
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

// Vial-specific encoder code

#if defined(ENCODER_MAP_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    return false;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [1] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [2] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [3] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [4] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [5] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [6] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [7] = {
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    }
};
#endif



uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_SPC:
        case NUM_TAB:
        case FKEYS_ENT:
        case NAV_ESC:
        case NAV_BSPC:

        case GUI_A:
        case ALT_S:
        case SHFT_D:
        case CTL_F:
        case CTL_J:
        case SHFT_K:
        case ALT_L:
        case GUI_SCLN:

        return QUICK_TAP_TERM;
        default:
        return 0;
    }
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {


    switch (tap_hold_keycode) {
        case CTL_F:
        if (other_keycode == KC_TAB
            || other_keycode == KC_SPC
            || other_keycode == KC_LALT
            || other_keycode == KC_LGUI
            || other_keycode == KC_Z
            || other_keycode == KC_X
            || other_keycode == KC_C) { return true; }
        break;

        case SYM_SPC:
        case NUM_TAB:
        case FKEYS_ENT:
        case NAV_ESC:
        case NAV_BSPC:

        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    // Macros....
    return true;
}

