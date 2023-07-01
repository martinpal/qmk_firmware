 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE - WHITE (QWERTY with home row mods)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | GESC |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |MO(1) | /Enter  /       \Space \  |MO(2) | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
   QK_GESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
KC_TAB,LGUI_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D),LSFT_T(KC_F),KC_G,     KC_H,RSFT_T(KC_J),RALT_T(KC_K),RCTL_T(KC_L),KC_SCLN,KC_QUOT,
   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,     KC_NO, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        KC_LGUI,LALT_T(KC_LBRC),KC_LCTL, MO(2),LSFT_T(KC_ENT),          KC_SPC,MO(3), KC_RCTL,RALT_T(KC_RBRC), KC_APP
),
/* GAME - CYAN (QWERTY)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | GESC |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |MO(1) | /Enter  /       \Space \  |MO(2) | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
   QK_GESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
    KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,     KC_NO, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        KC_LGUI,LALT_T(KC_LBRC),KC_LCTL, MO(2),LSFT_T(KC_ENT),          KC_SPC,MO(3), KC_RCTL,RALT_T(KC_RBRC), KC_APP
),
/*
 * LOWER - RED (numbers, symbols with home row mods)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | GESC |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | LS(  |   =  |   -  |   +  |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | RS)  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | RGUI | TRNS | TRNS | TRNS | /Space  /       \ TRNS \  |MO(4) | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[2] = LAYOUT(
    KC_GRV, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
   QK_GESC, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
KC_TAB,LGUI_T(KC_1),LCTL_T(KC_2),LALT_T(KC_3),LSFT_T(KC_4),KC_5,       KC_6,RSFT_T(KC_7),RALT_T(KC_8),RCTL_T(KC_9),KC_0,KC_F12,
   SC_LSPO,KC_EQL,KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_MUTE,     KC_NO, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, SC_RSPC,
                KC_RGUI,KC_LALT,KC_LCTL,KC_TRNS,LSFT_T(KC_SPC),          KC_SPC,MO(5), KC_RCTL, KC_RALT, KC_APP
),
/* RAISE - BLUE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | INS  | PRNT |      |      | SCRL |                    |  PGUP| CLFT |  UP  | CRGT |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |      |      |      |      | CAPS |-------.    ,-------|  PGDN| LEFT | DOWN | RGHT | DEL  | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | LS(  | UNDO | CUT  | COPY | PASTE| NLCK |-------|    |-------|      | HOME |      |  END |      | RS)  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS |MO(3) | / TRNS  /       \Enter \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    KC_ESC, KC_INS,KC_PSCR,  KC_NO,   KC_NO, KC_SCRL,                      KC_PGUP,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_NO,  KC_F12,
    KC_TAB,  KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_CAPS,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
   SC_LSPO,KC_UNDO, KC_CUT,KC_COPY,KC_PASTE,  KC_NUM, KC_MUTE,      KC_NO,   KC_NO, KC_HOME,   KC_NO,  KC_END,   KC_NO, SC_RSPC,
                KC_TRNS, KC_TRNS, KC_TRNS,   MO(4),LSFT_T(KC_ENT),          KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* ADJUST - GREEN
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  M0  |  M1  |  M2  |  M3  |  M4  |  M5  |                    |  M6  |  M7  |  M8  |  M9  | M10  | M11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGBM-|      |SYSREQ|      | BACK | FWD  |                    |      |      |      |      |      | M12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG| HUE+ | SAT+ |BRGHT+|      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      | M13  |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * | RGBM+| HUE- | SAT- |BRGHT-| CALC |      |--------|   |-------|      | PRVS | PLAY | NEXT | M15  | M14  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | /Space  /       \Enter \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[4] = LAYOUT(
      MC_0,    MC_1,    MC_2,    MC_3,     MC_4,    MC_5,                            MC_6,    MC_7,    MC_8,    MC_9,   MC_10,   MC_11,
  RGB_RMOD,   KC_NO, KC_PSCR,   KC_NO,    KC_NO,   KC_NO,                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MC_12,
   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,    KC_NO,   KC_NO,                           KC_NO, KC_VOLD, KC_MUTE, KC_VOLU,   KC_NO,   MC_13,
   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,  KC_CALC,   KC_NO,   KC_NO,         KC_NO,   KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,   MC_15,   MC_14,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT_T(KC_ENT),                KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* MOUSE - YELLOW
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | F13  | F14  | F15  | F16  | F17  | F18  |                    | F19  | F20  | F21  | F22  | F23  | F24  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BLDR |      |      |      |      |      |                    | WH U | BTN1 |  UP  | BTN2 | BTN3 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RBT  |      |      |      |      |      |-------.    ,-------| WH D | LEFT | DOWN | RGHT | BTN4 |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|   |-------|      | WH L |      | WH R | BTN5 |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | / TRNS  /       \ TRNS \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[5] = LAYOUT(
    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                           KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
   QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,   KC_NO,
    QK_RBT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4,   KC_NO,
QK_CLEAR_EEPROM,KC_NO, KC_NO,   KC_NO,   KC_NO,   DF(0),   KC_NO,          KC_NO,   DF(1), KC_WH_L,   KC_NO, KC_WH_R, KC_BTN5,   KC_NO,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,LSFT_T(KC_ENT),                 KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* EXTRA - MAGENTA
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|   |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[6] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
)
};

#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {
};
#endif





const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {32, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {33, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {34, 1, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 7, HSV_CYAN},
    {15, 2, HSV_CYAN},
    {25, 2, HSV_CYAN},
    {36, 7, HSV_CYAN},
    {51, 2, HSV_CYAN},
    {61, 2, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 7, HSV_RED},
    {15, 2, HSV_RED},
    {25, 2, HSV_RED},
    {36, 7, HSV_RED},
    {51, 2, HSV_RED},
    {61, 2, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 7, HSV_BLUE},
    {15, 2, HSV_BLUE},
    {25, 2, HSV_BLUE},
    {36, 7, HSV_BLUE},
    {51, 2, HSV_BLUE},
    {61, 2, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 7, HSV_GREEN},
    {15, 2, HSV_GREEN},
    {25, 2, HSV_GREEN},
    {36, 7, HSV_GREEN},
    {51, 2, HSV_GREEN},
    {61, 2, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 7, HSV_ORANGE},
    {15, 2, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {36, 7, HSV_ORANGE},
    {51, 2, HSV_ORANGE},
    {61, 2, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 7, HSV_MAGENTA},
    {15, 2, HSV_MAGENTA},
    {25, 2, HSV_MAGENTA},
    {36, 7, HSV_MAGENTA},
    {51, 2, HSV_MAGENTA},
    {61, 2, HSV_MAGENTA}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_scrolllock_layer,
    my_capslock_layer,
    my_numlock_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer,
    my_layer5_layer,
    my_layer6_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.scroll_lock);
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.num_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    for (int layer=0;layer<7;layer++) {
        rgblight_set_layer_state(layer, 0);
    }
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, 1));
    rgblight_set_layer_state(4, layer_state_cmp(state, 2));
    rgblight_set_layer_state(5, layer_state_cmp(state, 3));
    rgblight_set_layer_state(6, layer_state_cmp(state, 4));
    rgblight_set_layer_state(7, layer_state_cmp(state, 5));
    rgblight_set_layer_state(8, layer_state_cmp(state, 6));
    return state;
}

__attribute__((weak)) bool peek_matrix(uint8_t row_index, uint8_t col_index, bool raw);

uint8_t ledmap_left[MATRIX_ROWS][MATRIX_COLS] = {
    { 10, 11, 20, 21, 30, 31 },
    {  9, 12, 19, 22, 29, 32 },
    {  8, 13, 18, 23, 28, 33 },
    {  7, 14, 17, 24, 27, 34 },
    {  6, 15, 16, 25, 26, 35 }
};

uint8_t ledmap_right[MATRIX_ROWS][MATRIX_COLS] = {
    { 46, 47, 56, 57, 66, 67 },
    { 45, 48, 55, 58, 65, 68 },
    { 44, 49, 54, 59, 64, 69 },
    { 43, 50, 53, 60, 63, 70 },
    { 42, 51, 52, 61, 62, 71 }
};

typedef struct {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} rgb_t;

rgb_t colors_left[MATRIX_ROWS][MATRIX_COLS] = {
  { {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_RED      } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_RED      } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_YELLOW   } , {HSV_BLUE     } , {HSV_RED      } , {HSV_GREEN    } , {HSV_RED      }, {HSV_WHITE    } }
};

rgb_t colors_right[MATRIX_ROWS][MATRIX_COLS] = {
  { {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    } , {HSV_WHITE    }, {HSV_WHITE    } },
  { {HSV_WHITE    } , {HSV_CYAN     } , {HSV_PURPLE   } , {HSV_ORANGE   } , {HSV_BLUE     }, {HSV_WHITE    } }
};

void rgb_light_update_user() {
    if (is_keyboard_left()) {
        for (int c = 0; c < MATRIX_COLS; c++) {
            for (int r = 0; r < MATRIX_ROWS; r++) {
                if (peek_matrix(r, c, true)) {
                    sethsv(colors_left[r][c].h, colors_left[r][c].s, colors_left[r][c].v, (LED_TYPE *)&led[ledmap_left[r][c]]);
                }
            }
        }
    } else {
        for (int c = 0; c < MATRIX_COLS; c++) {
            for (int r = 0; r < MATRIX_ROWS; r++) {
                if (peek_matrix(r, c, true)) {
                    sethsv(colors_right[r][c].h, colors_right[r][c].s, colors_right[r][c].v, (LED_TYPE *)&led[ledmap_right[r][c]]);
                }
            }
        }
    }
    rgblight_set();
}
