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
    _ADJUST,
    _COLEMAK_DH,
};

// Aliases for readability
#define BASE     DF(_QWERTY)
#define GAME     DF(_QWERTY_STATIC)

// COLEMAK_DH only as a temporary switch
#define COLE     TG(_COLEMAK_DH)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define NUM      MO(_NUM)

#define NAV_SPC  LT(NAV, KC_SPC)
#define NUM_TAB  LT(NUM, KC_TAB)
// #define SYM_ENT  LT(SYM, KC_ENT)
#define SYM_BSPC LT(SYM, KC_BSPC)
// #define FUN_BSPC LT(FKEYS, KC_BSPC)
#define FUN_ENT  LT(FKEYS, KC_ENT)

#define ALT_S    MT(MOD_LALT, KC_S)
#define ALT_L    MT(MOD_LALT, KC_L)
#define CTL_F    MT(MOD_LCTL, KC_F)
#define CTL_J    MT(MOD_RCTL, KC_J)
#define SHFT_D   MT(MOD_LSFT, KC_D)
#define SHFT_K   MT(MOD_RSFT, KC_K)

// these will be allowed for same side usage
#define LALT_ESC MT(MOD_LALT, KC_ESC)
#define LALT_DEL MT(MOD_LALT, KC_DEL)
#define GUI_BSLS MT(MOD_LGUI, KC_BSLS)

// these are handled in process_user_record, however doesnt seem to work
// with the intended CW_TOGGLE and QK_REP
#define GUI_CW   MT(MOD_LGUI, KC_0)
#define GUI_REP  MT(MOD_RGUI, KC_1)
// #define GUI_J    MT(MOD_RGUI, KC_J)
// #define ALT_S    MT(MOD_LALT, KC_S)
// #define ALT_L    MT(MOD_LALT, KC_L)


// hotkeys for window management
//#define MEH_A    MEH_T(KC_A)
//#define MEH_F    MEH_T(KC_F)
#define LCA_A    LCA_T(KC_A)
#define LCA_F    LCA_T(KC_F)
#define MEH_B    MEH_T(KC_B)
#define MEH_V    MEH_T(KC_V)
#define MEH_C    MEH_T(KC_C)
#define MEH_X    MEH_T(KC_X)
#define MEH_Z    MEH_T(KC_Z)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: QWERTY
     */
    [_QWERTY] = LAYOUT_myr(
                           _______, KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,          KC_LSFT,     KC_RSFT,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , _______,
                           KC_MINS, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,          KC_LCTL,     KC_RCTL,          KC_Y ,  KC_U ,  KC_I ,   KC_O ,  KC_P , KC_UNDS,
                           KC_GRV , KC_A,   KC_S   ,  SHFT_D,   CTL_F,   KC_G ,          KC_LALT,     KC_RALT,          KC_H ,  CTL_J,  SHFT_K,  KC_L ,KC_SCLN, KC_EQL,
                           CW_TOGG ,KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LPRN, _______,     KC_LPRN, KC_RPRN, KC_N ,  KC_M ,KC_COMM, KC_DOT ,KC_SLSH, CW_TOGG,
                           ADJUST , LALT_ESC, NAV_SPC,NUM_TAB,KC_LGUI,    GUI_BSLS, FUN_ENT,SYM_BSPC,LALT_DEL, COLE,

                           KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                            KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
                           ),

    /*
     * Base Layer: Game
     */
    [_QWERTY_STATIC] = LAYOUT_myr(
                                  KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,         KC_LSFT,     KC_RSFT,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_MINS,
                                  KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,         KC_LCTL,     KC_RCTL,          KC_Y ,  KC_U ,  KC_I ,   KC_O ,  KC_P , KC_UNDS,
                                  KC_LCTL , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,         KC_LALT,     KC_RALT,          KC_H ,  KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_EQL,
                                  KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LGUI, NUM   ,     FKEYS  , _______, KC_N ,  KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  ADJUST , KC_LALT, KC_SPC,  KC_TAB , NAV   ,     SYM    , KC_BSPC,KC_ENT, KC_DOWN, KC_UP,

                                  KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                            KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
                                  ),

    /*
     * Nav Layer: Media, navigation
     */
    [_NAV] = LAYOUT_myr(
                        _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______,          _______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                        _______, LCA_A,   _______, _______, LCA_F,   _______,          _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
                        _______, MEH_Z,   MEH_X,   MEH_C,   MEH_V,   MEH_B,   _______, KC_SCRL, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_PSCR,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

                        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
                        ),

    /*
     * Sym Layer: Numbers and symbols
     */
    [_SYM] = LAYOUT_myr(
                        _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
                        _______, KC_HASH, KC_DQUO, KC_MINS, KC_GT,   KC_ASTR,          _______, _______,          _______, _______, _______, _______, _______, _______,
                        KC_GRV,  KC_PIPE, KC_QUOTE,KC_LPRN, KC_RPRN, KC_AMPR,          _______, _______,          KC_PERC, KC_LBRC, KC_RBRC, KC_DLR,  KC_COLN, _______,
                        _______, KC_AT,   KC_EXLM, KC_LCBR, KC_RCBR, KC_CIRC, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_QUES, _______,
                        _______, KC_TILD, _______, KC_BSLS, _______,   _______, _______, _______, _______, _______,

                        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
                        ),

    /* Numbers */
    [_NUM] = LAYOUT_myr(
                        _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______,          _______, _______,          KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC, _______,
                        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,          _______, _______,          KC_COLN, KC_4   , KC_5   , KC_6   , KC_EQL , KC_BSLS,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT , KC_1   , KC_2   , KC_3   , KC_MINS, _______,
                        _______, _______, _______, _______,  _______, _______, _______,KC_0   , KC_DOT , _______,

                        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
                        ),

    /*
     * Function Layer: Function keys
     */
    [_FUNCTION] = LAYOUT_myr(
                             _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
                             _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
                             _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,          _______, _______,          _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _______,
                             _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

                             _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
                             ),

    /*
     * Adjust Layer: Default layer settings, RGB
     */
    [_ADJUST] = LAYOUT_myr(
                           _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
                           _______, _______, _______, BASE   , _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
                           _______, _______, _______, GAME   , _______, _______,         _______, _______,          RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
                           _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                           _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,

                           _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______

                           ),
    /*
     * Colemak Layer: Default layer settings, RGB
     */
    [_COLEMAK_DH] = LAYOUT_myr(
                               _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
                               _______, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,         _______, _______,          KC_J   , KC_L   , KC_U   , KC_Y   ,  KC_SCLN, _______,
                               _______, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,         _______, _______,          KC_M   , KC_N   , KC_E   , KC_I   ,  KC_O   , _______,
                               _______, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,_______, _______, _______, _______, KC_K   , KC_H   , KC_COMM, KC_DOT ,  KC_SLSH, _______,
                               _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,

                               _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______

                               ),

    // /*
    //  * Layer template - LAYOUT
    //  *
    //  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        `----------------------------------'  `----------------------------------'
    //  */
    //     [_LAYERINDEX] = LAYOUT(
    //       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //     ),

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
        case CTL_F:
        case CTL_J:
        case SHFT_K:
        case SHFT_D:
        case SYM_BSPC:
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

        case SYM_BSPC:
        case NUM_TAB:
        case FUN_ENT:
        case NAV_SPC:
        case LALT_ESC:
        case LALT_DEL:
        case GUI_BSLS:
        case KC_LGUI:
        case KC_RGUI:
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
        case GUI_CW:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(CW_TOGG);
            }

            return false;
        }
        break;

        case GUI_REP:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_BSLS);
            }

            return false;
        }
        break;
    }

    // Macros....
    return true;
}

