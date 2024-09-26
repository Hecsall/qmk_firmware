/* Copyright 2022 Basic I/O Instruments (@scottywei)
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

#include "../../../ble.h"
#include QMK_KEYBOARD_H

ble_led_stat ble_led;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    // 0: Base Layer
    [0] = LAYOUT(
        KC_ESC,         KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,  KC_BSPC, KC_BSLS,  KC_INS,  KC_HOME,  KC_PGUP,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                KC_MUTE,   KC_VOLU,
        KC_LSFT,  KC_NUBS,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, MO(1),               KC_UP,         KC_VOLD,
        KC_LCTL,  KC_LWIN,  KC_LALT,                       KC_SPC,                KC_RALT,  KC_RWIN,  KC_APP,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RIGHT),

    // 1: Function Layer
    [1] = LAYOUT(
        _______,         KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,                _______, _______,
        _______,  _______,  _______,                       _______,                _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [2] = LAYOUT(
        _______,         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,                _______, _______,
        _______,  _______,  _______,                       _______,                _______,  _______,  _______,  _______,  _______,  _______,  _______),

    [3] = LAYOUT(
        _______,         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,               _______, _______,
        _______,  _______,  _______,                       _______,                _______,  _______,  _______,  _______,  _______,  _______,  _______),
    // clang-format on
};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 5, HSV_WHITE});

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 5, HSV_SPRINGGREEN});
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 5, HSV_PURPLE});
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 5, HSV_MAGENTA});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_capslock_layer, my_layer1_layer, my_layer2_layer, my_layer3_layer);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, 0) && !rgblight_is_enabled()) {
        rgblight_enable_noeeprom();
        writePinLow(RGB_UG_CONTROL_PIN);
    }

    if (ble_on && layer_state_cmp(state, 0)) {
        rgblight_reload_from_eeprom();
        if (!rgblight_is_enabled()) {
            writePinHigh(RGB_UG_CONTROL_PIN);
            rgblight_disable_noeeprom();
        } else {
            writePinLow(RGB_UG_CONTROL_PIN);
            rgblight_enable_noeeprom();
        }
    }

    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}

// TODO review this
void led_set_user(led_t led_state) {
    if (!ble_on) {
        rgblight_set_layer_state(0, led_state.caps_lock);
        if (led_state.caps_lock) {
            ble_led.caplck = true;
        } else {
            ble_led.caplck = false;
        }
        if (led_state.caps_lock) {
            rgblight_enable_noeeprom();
        }
        if (!led_state.caps_lock && layer_state_is(0)) {
            rgblight_reload_from_eeprom();
            if (!rgblight_is_enabled()) {
                writePinHigh(RGB_UG_CONTROL_PIN);
                rgblight_disable_noeeprom();
            } else {
                writePinLow(RGB_UG_CONTROL_PIN);
                rgblight_enable_noeeprom();
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F21:
            if (record->event.pressed) {
                module_reset();
            } else {
            }
            break;
        case KC_F13:
            if (record->event.pressed) {
                rgb_matrix_toggle();
            }
            break;
        case KC_F14:
            if (record->event.pressed) {
                rgb_matrix_step();
            }
            break;
        case KC_F15:
            if (record->event.pressed) {
                rgb_matrix_step_reverse();
            }
            break;
        case KC_F16:
            if (record->event.pressed) {
                rgb_matrix_increase_hue();
            }
            break;
        case KC_F17:
            if (record->event.pressed) {
                rgblight_reload_from_eeprom();
                rgblight_toggle();
            }
            break;
        case KC_F18:
            if (record->event.pressed) {
                rgblight_step();
            }
            break;
        case KC_F19:
            if (record->event.pressed) {
                rgblight_step_reverse();
            }
            break;
        case KC_F20:
            if (record->event.pressed) {
                rgblight_increase_hue();
            }
            break;
        case KC_CAPS:
            if (record->event.pressed) {
                if (ble_on) {
                    rgblight_reload_from_eeprom();
                    ble_led.caplck = !ble_led.caplck;

                    rgblight_set_layer_state(0, ble_led.caplck);

                    if (ble_led.caplck && !rgblight_is_enabled()) {
                        rgblight_enable_noeeprom();
                    }
                    if (!ble_led.caplck && !rgblight_is_enabled()) {
                        rgblight_disable_noeeprom();
                    }
                }
            }
            break;
        default:
            return true;
    }
    return true;
};
