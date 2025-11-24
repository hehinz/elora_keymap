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
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _GAME,
    _GALLIUM,
    _TYPING,
    _NAV,
    _SYM,
    _NUM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define BASE     DF(_QWERTY)
#define GAME     DF(_GAME)
#define GALL     DF(_GALLIUM)
#define TYPI     DF(_TYPING)

// COLEMAK_DH only as a temporary switch

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define NUM      MO(_NUM)
#define ADJUST   MO(_ADJUST)

#define NAV_TAB     LT(NAV, KC_TAB)
#define SYM_SPC     LT(SYM, KC_SPC)
#define NUM_ESC     LT(NUM, KC_ESC)

#define FUN_ENT     LT(FKEYS, KC_ENT)
#define SYM_BSPC    LT(SYM, KC_BSPC)
#define NAV_DEL     LT(NAV, KC_DEL)

// home row mods
#define LCTL_MINS   MT(MOD_LCTL, KC_MINS)
#define LGUI_A      MT(MOD_LGUI, KC_A)
#define LALT_S      MT(MOD_LALT, KC_S)
#define LSFT_D      MT(MOD_LSFT, KC_D)
#define LCTL_F      MT(MOD_LCTL, KC_F)

#define RCTL_J      MT(MOD_RCTL, KC_J)
#define RSFT_K      MT(MOD_RSFT, KC_K)
#define LALT_L      MT(MOD_LALT, KC_L)
#define RGUI_QUOT   MT(MOD_RGUI, KC_QUOT)

#define LGUI_N      MT(MOD_LGUI, KC_N)
#define LALT_R      MT(MOD_LALT, KC_R)
#define LSFT__T       MT(MOD_LSFT, KC_T)
#define LCTL_S      MT(MOD_LCTL, KC_S)

#define RCTL_H      MT(MOD_RCTL, KC_H)
#define RSFT_A      MT(MOD_RSFT, KC_A)
#define LALT_E      MT(MOD_LALT, KC_E)
#define RGUI_I      MT(MOD_RGUI, KC_I)

#define MEH_G       MEH(KC_G)
#define MEH_B       MEH(KC_B)
#define MEH_V       MEH(KC_V)
#define MEH_C       MEH(KC_C)
#define MEH_X       MEH(KC_X)
#define MEH_Z       MEH(KC_Z)


enum custom_keycodes {
    ASSIGN = SAFE_RANGE,
    UPDIR,
};

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] =
#include "layers/lay_qwerty_main.inl"
    [_GAME] =
#include "layers/lay_game.inl"
    [_GALLIUM] =
#include "layers/lay_gallium.inl"
    [_TYPING] =
#include "layers/lay_typing.inl"
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
#include "layers/encoders.inl"
    },
    [1] = {
#include "layers/encoders.inl"
    },
    [2] = {
#include "layers/encoders.inl"
    },
    [3] = {
#include "layers/encoders.inl"
    },
    [4] = {
#include "layers/encoders.inl"
    },
    [5] = {
#include "layers/encoders.inl"
    },
    [6] = {
#include "layers/encoders.inl"
    },
    [7] = {
#include "layers/encoders.inl"
    },
    [8] = {
#include "layers/encoders.inl"
    }
};
#endif


const key_override_t dot_key_override =
    ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_AT, 0x1);  // Shift . is ?
const key_override_t comm_key_override =
    ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_EXLM, 0x1); // Shift , is !

const key_override_t *key_overrides[] = {
    &dot_key_override,
    &comm_key_override,
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_A:
        case LALT_S:
        case LCTL_F:
        case RCTL_J:
        case LALT_L:
        case RGUI_QUOT:

        case LGUI_N:
        case LALT_R:
        case LCTL_S:
        case RCTL_H:
        case LALT_E:
        case RGUI_I:
        return QUICK_TAP_TERM;

        case LSFT_D:
        case RSFT_K:
        case LSFT__T:
        case RSFT_A:
        return 100;
        default:
        return 0;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ASSIGN:
            if (record->event.pressed) {
                SEND_STRING(" = ");
            }
            return false;
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
    }

    return true;
}

bool get_chordal_hold(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {


    switch (tap_hold_keycode) {
        case LGUI_A:
        if (other_keycode == KC_TAB) {return true; }
        break;

        case LCTL_F:
        case LCTL_S:
        if (other_keycode == KC_TAB
            || other_keycode == KC_SPC
            || other_keycode == KC_LALT
            || other_keycode == KC_LGUI
            || other_keycode == KC_Z
            || other_keycode == KC_X
            || other_keycode == KC_C) { return true; }
        break;

        case LCTL_MINS:

        case NAV_TAB:
        case SYM_SPC:
        case NUM_ESC:

        case FUN_ENT:
        case SYM_BSPC:
        case NAV_DEL:

        return true;
    }

    return get_chordal_hold_default(tap_hold_record, other_record);
}


