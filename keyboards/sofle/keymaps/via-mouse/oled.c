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

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

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

//    switch (get_highest_layer(layer_state)) {
//        case 0:
//            oled_write_ln_P(PSTR("Qwrt"), false);
//            break;
//        case 1:
//            oled_write_ln_P(PSTR("Clmk"), false);
//            break;
//        default:
//            oled_write_P(PSTR("Mod\n"), false);
//            break;
//    }
//    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    //oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("Extra"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("SCRLK"), led_usb_state.scroll_lock);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
    oled_write_P(PSTR("\n"), false);
    render_logo();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

#endif
