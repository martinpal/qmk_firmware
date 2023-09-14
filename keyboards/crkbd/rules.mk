# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
LTO_ENABLE = yes

# if firmware size over limit, try this option
# LTO_ENABLE = yes

DEFAULT_FOLDER = crkbd/rev1

RGBLIGHT_SUPPORTED = yes
RGB_MATRIX_SUPPORTED = yes

#CONVERT_TO=elite-pi
CONVERT_TO=promicro_rp2040
BOOTLOADER=rp2040

VIA_ENABLE = yes
SWAP_HANDS_ENABLE = yes
EE_HANDS = yes
LOCKING_SUPPORT_ENABLE = yes
SCROLL_LOCK_ENABLE = yes
CAPS_LOCK_ENABLE = yes

DYNAMIC_KEYMAP_ENABLE = yes
RGBLIGHT_SPLIT = yes

RGBLIGHT_LAYERS = yes
RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF = yes

SPLIT_LAYER_STATE_ENABLE = yes
SPLIT_LED_STATE_ENABLE = yes
SPLIT_MODS_ENABLE = yes
SPLIT_OLED_ENABLE = yes

USER_LIGHT_UPDATE = yes
