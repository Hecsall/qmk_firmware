#include QMK_KEYBOARD_H

#define _QWERTY 0


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_0,    KC_1 \
  )
};
