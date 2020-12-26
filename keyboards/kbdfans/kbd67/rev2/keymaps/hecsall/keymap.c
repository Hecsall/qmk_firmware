/* Copyright 2019 'hecsall'
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
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Pscr|
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN| FN2|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [0] = LAYOUT_65_ansi(
    KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DELETE,  \
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCREEN, \
    KC_CLCK, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,    \
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,    \
    KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(1),   MO(2),   KC_LEFT, KC_DOWN, KC_RGHT),



  /* Keymap Fn 1 Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |RGB|RGB|RGB|RGB|   |   |   |PSc|SLk|Pau|Up |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |Hom|PUp|Lef|Rig|        |    |
   * |----------------------------------------------------------------|
   * |        |   |   | BD| BI| BT|NKRO|   |End|PDn|Dow|     |PUp|    |
   * |----------------------------------------------------------------|
   * |    |NOGUI|    |                      |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
  [1] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_INS, \
    _______, RGB_TOG,      RGB_MOD, RGB_HUD, RGB_HUI, _______, _______,           _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______, _______, \
    _______, _______,      _______, _______, _______, _______, _______,           _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          _______, _______, \
    _______, _______,      _______, BL_DEC,  BL_INC,  BL_TOGG, MAGIC_TOGGLE_NKRO, _______, KC_END,  KC_PGDN, KC_DOWN,          _______, KC_PGUP, _______, \
    _______, MAGIC_NO_GUI, _______,                            _______,                             _______, _______, _______, KC_HOME, KC_PGDN, KC_END),



  /* Keymap Fn 2 Layer
   * ,----------------------------------------------------------------.
   * |~ `|F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|       |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |UNNOGUI|    |                     |   |   |   |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
  [2] = LAYOUT_65_ansi(
    KC_GRV,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______, \
    _______, _______,  _______,  _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, \
     _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP, _______, \
    _______, MAGIC_UNNO_GUI, _______,                            _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_END),


};



void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 4); PORTD &= ~(1 << 4);
	} else {
		DDRD &= ~(1 << 4); PORTD &= ~(1 << 4);
	}
}
