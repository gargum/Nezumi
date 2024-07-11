# Microcontroller selection
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
TAP_DANCE_ENABLE = yes      # Enable Tap Dance configurations
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight
WS2812_DRIVER = vendor		# Enable WS2812 functionality on the RP2040
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
AUDIO_ENABLE = no           # Audio output
MIDI_ENABLE = no            # MIDI output
COMBO_ENABLE = yes          # Enable key combos
SLEEP_LED_ENABLE = no
SPLIT_KEYBOARD = no
LTO_ENABLE = yes
