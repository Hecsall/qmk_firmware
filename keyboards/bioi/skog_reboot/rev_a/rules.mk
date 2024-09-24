F_CPU = 8000000
ARCH = AVR8
F_USB = $(F_CPU)

BOOTLOADER_SIZE = 8192

OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

SRC +=  ../usart.c  \
        ../ble.c    \
        ../main.c

OPT_DEFS += -DPROTOCOL_BLE
OPT_DEFS += -DUART_RX1_BUFFER_SIZE=16 -DUART_TX1_BUFFER_SIZE=16
OPT_DEFS += -DUSART1_ENABLED

# Build Options
# EXTRAKEY_ENABLE = yes
# CONSOLE_ENABLE = no
# COMMAND_ENABLE = yes
# NKRO_ENABLE = yes
# BACKLIGHT_ENABLE = no
# AUDIO_ENABLE = no
# UNICODE_ENABLE = no
# BLUETOOTH_ENABLE = no
# RGBLIGHT_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
# SLEEP_LED_ENABLE = no
# ENCODER_ENABLE= yes
VIA_ENABLE = yes
