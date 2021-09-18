#include QMK_KEYBOARD_H

#define _DVORAK 0 // Base Dvorak layer
#define _CUSTOM 1 // My Custom layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT(
        // left hand
        RESET,    KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8,
        KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,
        KC_ESC,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,
        KC_TAB,   KC_A,    KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,
                  KC_GRV,  KC_INS, KC_LEFT, KC_RIGHT,
        // left thumb
                            LGUI_T(KC_ESC), KC_LCTL,
                                     KC_PGUP,
                          RCTL_T(KC_BSPC), KC_DEL, KC_PGDN,
        // right hand
        KC_F9,  KC_F10,   KC_F11,   KC_F12,   KC_PSCR, KC_SLCK, KC_PAUS, KC_FN0, KC_1,
        KC_6,   KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,
        KC_F,   KC_G,     KC_C,     KC_R,     KC_L,    KC_SLSH,
        KC_D,   KC_H,     KC_T,     KC_N,     KC_S,    KC_BSLS,
        KC_B,   KC_M,     KC_W,     KC_V,     KC_Z,    KC_RSFT,
                          KC_UP,  KC_DOWN, KC_LBRC, KC_RBRC,
        // right thumb
        KC_RGUI, RGUI_T(KC_ESC),
        KC_RALT,
        KC_END, KC_ENT, RALT_T(KC_SPC)
    ),

[_CUSTOM] = LAYOUT(
       // left hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,
       KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
       KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,
                KC_GRV,  KC_INS,  KC_LEFT, KC_RIGHT,
        // left thumb
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_NO,   KC_NO,   KC_TRNS,
       // right hand
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_POWER,
       KC_NO,   KC_VOLU, KC_MS_U, KC_VOLD, KC_NO,   KC_NO,
       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
       KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,
                KC_MS_L, KC_MS_R, KC_NO,   KC_NO,
       // right thumb
       KC_NO, KC_NO,
       KC_NO,
       KC_END, KC_ENT, RSFT_T(KC_SPC)
)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case RSFT_T(KC_SPC):
        //    return TAPPING_TERM + 50;
        case LGUI_T(KC_ESC):
            //return TAPPING_TERM + 25;
            return TAPPING_TERM + 10000;
        case RSFT_T(KC_H):
            return TAPPING_TERM + 7500;
        case LSFT_T(KC_U):
            return TAPPING_TERM + 7500;
        case RCTL_T(KC_SPC):
            return TAPPING_TERM + 10;
        default:
            return TAPPING_TERM;
    }
}
