#include QMK_KEYBOARD_H

#define _DVORAK 0 // Base Dvorak layer
#define _CUSTOM 1 // My Custom layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT(
        // top function row: left hand                          | right hand
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8,        KC_F9,  KC_F10,  KC_F11,   KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS, KC_NO,       KC_1,
        // number row
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                               KC_6,   KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS,
        // top alpha row
        KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,                               KC_F,   KC_G,    KC_C,     KC_R,     KC_L,    KC_SLSH,
        // home row
        KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,                               KC_D,   KC_H,    KC_T,     KC_N,     KC_S,    KC_BSLS,
        // bottom alpha row
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,                               KC_B,   KC_M,    KC_W,     KC_V,     KC_Z,    KC_RSFT,
        // arrow row
                 KC_GRV,  KC_INS,  KC_LEFT, KC_RIGHT,                                           KC_UP,   KC_DOWN,  KC_LBRC,  KC_RBRC,

        // thumb clusters: top row (left pair, right pair)
                                            KC_NO,           KC_LCTL,        KC_RGUI,  RGUI_T(KC_ESC),
        // thumb clusters: middle row (left, right)
                                                             KC_PGUP,        KC_RALT,
        // thumb clusters: bottom row (left triple, right triple)
                                  RCTL_T(KC_BSPC), KC_DEL,   KC_PGDN,        KC_END,   HYPR_T(KC_ENT), RALT_T(KC_SPC)
    ),

[_CUSTOM] = LAYOUT(
        // top function row
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,     KC_NO,
        // number row
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,                              KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_PWR,
        // top alpha row (mirrors base)
        KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,                               KC_NO,  KC_VOLU, MS_UP,    KC_VOLD,  KC_NO,   KC_NO,
        // home row (numbers on left)
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                               KC_6,   KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS,
        // bottom alpha row
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,                               KC_NO,  KC_MPRV, KC_MPLY,  KC_MNXT,  KC_NO,   KC_NO,
        // arrow row
                 KC_GRV,  KC_INS,  KC_LEFT, KC_RIGHT,                                           MS_LEFT, MS_RGHT,  KC_NO,    KC_NO,

        // thumb clusters: top row
                                            KC_NO,           KC_NO,          KC_NO,    KC_NO,
        // thumb clusters: middle row
                                                             KC_NO,          KC_NO,
        // thumb clusters: bottom row
                                  KC_NO,   KC_NO,   KC_TRNS,                 KC_END,   KC_ENT, RSFT_T(KC_SPC)
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
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
