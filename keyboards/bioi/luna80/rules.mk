MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
F_USB = $(F_CPU)

BOOTLOADER = qmk-dfu
BOOTLOADER_SIZE = 4096


OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Build Options
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = yes
NKRO_ENABLE = yes
BACKLIGHT_ENABLE = no
AUDIO_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
RGBLIGHT_ENABLE = yes
SLEEP_LED_ENABLE = no
VIA_ENABLE = yes
LTO_ENABLE = yes