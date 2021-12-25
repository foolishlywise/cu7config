/*
Copyright 2021 CapsUnlocked

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
             KC_MUTE,
    KC_MPRV,    KC_MPLY,    KC_MNXT,
    KC_BRID,    X_TEAMSMUTE,    KC_BRIU
  ),
  [1] = LAYOUT(
             RESET,
    KC_MPRV,    KC_MPLY,    KC_MNXT,
    KC_BRID,    MO(1),    KC_BRIU
  ),
};

void keyboard_post_init_user(void) {
rgblight_enable_noeeprom(); // enables Rgb, without saving settings
rgblight_sethsv_noeeprom(HSV_WHITE); rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); }

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code_delay(KC_VOLU, 10);
  }
  else {
    tap_code_delay(KC_VOLD, 10);
  }

  return true;
}
enum custom_keycodes {
    TEAMSMUTE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TEAMSMUTE:
        if (record->event.pressed) {
            // when keycode TEAMSMUTE is pressed
            SEND_STRING(LCTL(LSFT(KC_M)));
        } else {
            // when keycode TEAMSMUTE is released
        }
        break;
    }
    return false;
};
