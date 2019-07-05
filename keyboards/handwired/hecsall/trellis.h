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

#pragma once
#include "i2c_master.h"

/* Initialization settings */

/* register defines -------------------------------------------------------- */
#define TRELLIS_BASE_ADDRESS        0x70	/* TRELLIS Base address */


void TRELLIS_init(void);
void TRELLIS_write(const uint8_t settings);
uint8_t TRELLIS_read(const uint8_t regaddress);
void setBrightness(uint8_t b);

#define MSG_OK 0
