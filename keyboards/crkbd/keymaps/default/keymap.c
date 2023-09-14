/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
   QK_GESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
KC_TAB,LGUI_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D),LSFT_T(KC_F),KC_G,     KC_H,RSFT_T(KC_J),RALT_T(KC_K),RCTL_T(KC_L),KC_SCLN,KC_QUOT,
KC_LSFT,LGUI_T(KC_Z),LCTL_T(KC_X),LALT_T(KC_C),LSFT_T(KC_V),KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                 KC_LGUI,MO(2),LSFT_T(KC_ENT),          KC_SPC,MO(3),  KC_APP
  ),

  [1] = LAYOUT_split_3x6_3(
   QK_GESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
    KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                 KC_LGUI,MO(2),LSFT_T(KC_ENT),          KC_SPC,MO(3), KC_APP
  ),

  [2] = LAYOUT_split_3x6_3(
    KC_GRV, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
KC_TAB,LGUI_T(KC_1),LCTL_T(KC_2),LALT_T(KC_3),LSFT_T(KC_4),KC_5,       KC_6,RSFT_T(KC_7),RALT_T(KC_8),RCTL_T(KC_9),KC_0,KC_F12,
SC_LSPO,LGUI_T(KC_EQL),LCTL_T(KC_MINS),LALT_T(KC_PLUS),LSFT_T(KC_LBRC),KC_RBRC,     KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, SC_RSPC,
                KC_RGUI,KC_TRNS,LSFT_T(KC_SPC),          KC_SPC,MO(5), KC_APP
  ),

  [3] = LAYOUT_split_3x6_3(
  KC_ESC, KC_INS,KC_PSCR,  KC_NO,LCTL(KC_R), KC_SCRL,                      KC_PGUP,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_NO,  KC_F12,
 KC_TAB,LCTL(KC_A),KC_LCTL,KC_LALT, KC_LSFT, KC_CAPS,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
SC_LSPO,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_NUM,                KC_NO, KC_HOME,   KC_NO,  KC_END,   KC_NO, SC_RSPC,
                                     KC_TRNS,MO(4),LSFT_T(KC_ENT),         KC_ENT, KC_TRNS, KC_TRNS
  ),

  [4] = LAYOUT_split_3x6_3(
  RGB_RMOD,   KC_NO, KC_PSCR,   KC_NO,    KC_NO,   KC_NO,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MC_12,
   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,    KC_NO,   KC_NO,                           KC_NO, KC_VOLD, KC_MUTE, KC_VOLU,   KC_NO,   MC_13,
   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,  KC_CALC,   KC_NO,                           KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,   MC_15,   MC_14,
                                   KC_TRNS,KC_TRNS, LSFT_T(KC_ENT),                KC_SPC, KC_TRNS, KC_TRNS
  ),

  [5] = LAYOUT_split_3x6_3(
   QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,   KC_NO,
    QK_RBT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4,   KC_NO,
QK_CLEAR_EEPROM,KC_NO, KC_NO,   KC_NO,   KC_NO,   DF(0),                            DF(1), KC_WH_L,   KC_NO, KC_WH_R, KC_BTN5,   KC_NO,
                                  KC_TRNS, KC_TRNS,LSFT_T(KC_ENT),                 KC_SPC, KC_TRNS, KC_TRNS
  ),

  [6] = LAYOUT_split_3x6_3(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                         KC_NO,   KC_NO,  KC_NO,            KC_NO,  KC_NO,   KC_NO
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,
        0xa0,0xa1,0xa2,0xa3,0xa4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0x00
    };
    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    //oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case 0:
            if (get_highest_layer(default_layer_state) == 0) {
                oled_write_P(PSTR("Base\n"), false);
            } else {
                oled_write_P(PSTR("Game\n"), false);
            }
            break;
        case 1:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 3:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 4:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case 5:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case 6:
            oled_write_P(PSTR("Extra"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("SCRLK"), led_usb_state.scroll_lock);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
    oled_write_P(PSTR("\n"), false);
    if (is_keyboard_master()) {
      oled_write_P(PSTR("DON'TPANIC"), false);
    } else {
      render_logo();
    }
    oled_write_P(PSTR("\n"), false);
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

void rgb_light_update_user() {
}
