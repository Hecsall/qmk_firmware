/* Copyright 2018 ishtob
 * Driver for Adafruit Trellis Monochrome written for QMK
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

#include "trellis.h"
#include "print.h"
#include <stdlib.h>
#include <stdio.h>

#define HT16K33_BLINK_CMD       0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF    0

uint8_t TRELLIS_transfer_buffer[2];
uint8_t TRELLIS_tx_register[0];
uint8_t TRELLIS_read_buffer[0];
uint8_t TRELLIS_read_register;

void TRELLIS_write(uint8_t settings) {
    // TRELLIS_transfer_buffer[0] = trellis_register;
    TRELLIS_transfer_buffer[0] = settings;
    i2c_transmit(TRELLIS_BASE_ADDRESS << 1, TRELLIS_transfer_buffer, 2, 100);
};

uint8_t TRELLIS_read(uint8_t regaddress) {
#ifdef __AVR__
    i2c_readReg(TRELLIS_BASE_ADDRESS << 1, regaddress, TRELLIS_read_buffer, 1, 100);
    TRELLIS_read_register = (uint8_t)TRELLIS_read_buffer[0];
#else
    TRELLIS_tx_register[0] = regaddress;
    if (MSG_OK != i2c_transmit_receive(TRELLIS_BASE_ADDRESS << 1, TRELLIS_tx_register, 1, TRELLIS_read_buffer, 1)) {
        printf("err reading reg \n");
    }
    TRELLIS_read_register = (uint8_t)TRELLIS_read_buffer[0];
#endif
    return TRELLIS_read_register;
};


void setBrightness(uint8_t b){
	if(b > 15) return;
    TRELLIS_write(0xE0 | b);
};


void TRELLIS_init(void) {
    i2c_init();
    TRELLIS_write(0x07);
    TRELLIS_write(HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON | (HT16K33_BLINK_OFF << 1));
    setBrightness(15);
    TRELLIS_write(0xA1);
};
