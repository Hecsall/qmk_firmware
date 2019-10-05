#include "hecsall.h"
#include "i2c_master.h"

#include <stdint.h>
#include <stdbool.h>
#include <print.h>
#include <stdlib.h>
#include "string.h"

/************** TRELLIS *************/

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

#define i2c_addr 0x70

#define LED_ON  1
#define LED_OFF 0

#define HT16K33_BLINK_OFF    0
#define HT16K33_BLINK_2HZ    1
#define HT16K33_BLINK_1HZ    2
#define HT16K33_BLINK_HALFHZ 3


void begin(void);
void setBrightness(uint8_t b);
void blinkRate(uint8_t b);
void writeDisplay(void);
void clear(void);
bool isKeyPressed(uint8_t k);
bool wasKeyPressed(uint8_t k);
bool isLED(uint8_t x);
void setLED(uint8_t x);
void clrLED(uint8_t x);
bool readSwitches(void);
bool justPressed(uint8_t k);
bool justReleased(uint8_t k);
uint8_t displaybuffer[8];
void init(uint8_t a);

uint8_t keys[6], lastkeys[6];

#define HT16K33_BLINK_CMD       0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_CMD_BRIGHTNESS  0xE0

/*
These are the lookup tables that convert the LED/button #
to the memory address in the HT16K33 - don't mess with them :)
*/

static const uint8_t PROGMEM
  ledLUT[16] =
    { 0x3A, 0x37, 0x35, 0x34,
      0x28, 0x29, 0x23, 0x24,
      0x16, 0x1B, 0x11, 0x10,
      0x0E, 0x0D, 0x0C, 0x02 },
  buttonLUT[16] =
    { 0x07, 0x04, 0x02, 0x22,
      0x05, 0x06, 0x00, 0x01,
      0x03, 0x10, 0x30, 0x21,
      0x13, 0x12, 0x11, 0x31 };

uint8_t buffer[2];

void begin(void) {
    i2c_init();
    buffer[0] = 0x21;
    i2c_transmit(i2c_addr << 1, buffer, 1, 100); // turn on oscillator
    i2c_stop();

    blinkRate(HT16K33_BLINK_OFF);

    setBrightness(15);  // max brightness

    i2c_init();
    buffer[0] = 0xA1;
    i2c_transmit(i2c_addr << 1, buffer, 1, 100);  // turn on interrupt, active low
    i2c_stop();
}


void setBrightness(uint8_t b) {
    i2c_init();
    if (b > 15) b = 15;
    buffer[0] = HT16K33_CMD_BRIGHTNESS | b;
    i2c_transmit(i2c_addr << 1, buffer, 1, 100);
    i2c_stop();
}

void blinkRate(uint8_t b) {
    i2c_init();
    if (b > 3) b = 0; // turn off if not sure
    buffer[0] = HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON | (b << 1);
    i2c_transmit(i2c_addr << 1, buffer, 1, 100);
    i2c_stop();
}

/************************************/





void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts upSS
    begin();

	matrix_init_user();
}
