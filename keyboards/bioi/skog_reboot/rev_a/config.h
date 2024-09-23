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

#pragma once

#define BLE_NAME        "SKOG REBOOT BLE"

#define MATRIX_ROW_PINS { B7, A3, A4, A5, A6, A7 }
#define MATRIX_COL_PINS { F0, F1, F2, F3, F4, F5, F6, F7, A0, A1, A2, E1, E0, D7, D6, D5, D4 }

#define DIODE_DIRECTION COL2ROW

#define ENCODER_HALFSTEP

#define ENCODERS_PAD_A { C0 }
#define ENCODERS_PAD_B { C1 }

#define ENCODER_RESOLUTION  4

#define RGB_BL_CONTROL_PIN C4
#define RGB_UG_CONTROL_PIN C3

#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
#define RGBLIGHT_DISABLE_KEYCODES
#define RGBLIGHT_LAYERS
#define RGB_DI_PIN C2
#define RGBLED_NUM 10
#define RGBLIGHT_DEFAULT_SPD 2
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 127
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define DRIVER_ADDR_1 0b1011111
#define DRIVER_ADDR_2 0b1010000

#define ISSI_GLOBALCURRENT 0x07
#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 44
#define DRIVER_2_LED_TOTAL 48
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

#define RGB_MATRIX_KEYRELEASES
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define KEYBOARD_LOCK_ENABLE
#define MAGIC_KEY_LOCK L
#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))