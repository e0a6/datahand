#include QMK_KEYBOARD_H

#define _DVORAK 0 // Base Dvorak layer
#define _MODS   1 // Modifier-helper layer (held via left-thumb-top-outer key)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ┌─────────────────────────────────────────────────────────────────────────────┐
// │  _DVORAK — base layer                                                       │
// └─────────────────────────────────────────────────────────────────────────────┘
[_DVORAK] = LAYOUT(
    // ─── function row (9 left + 9 right) ──────────────────────────────────────
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,             KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS, KC_NO,   KC_1,

    // ─── main keywell (6 left + 6 right per row) ──────────────────────────────
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_BSLS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,

    // ─── arrow row (4 left + 4 right) ─────────────────────────────────────────
             KC_GRV,  KC_INS,  KC_LEFT, KC_RIGHT,                                                       KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,

    // ─── thumb clusters (left ┊ right; rows: top palm / middle / bottom) ──────
                                                MO(_MODS),       KC_LCTL,         KC_RGUI,           RGUI_T(KC_ESC),
                                                                 KC_PGUP,         KC_RALT,
                                LCTL_T(KC_BSPC), KC_DEL,         KC_PGDN,         KC_END,            HYPR_T(KC_ENT),  RALT_T(KC_SPC)
),


// ┌─────────────────────────────────────────────────────────────────────────────┐
// │  _MODS — held via left-thumb-top-outer; U position becomes Ctrl+Alt mod     │
// └─────────────────────────────────────────────────────────────────────────────┘
[_MODS] = LAYOUT(
    // ─── function row ─────────────────────────────────────────────────────────
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    // ─── main keywell (U position → LCA(KC_NO) = hold Ctrl+Alt) ───────────────
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, LCA(KC_NO), KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    // ─── arrow row ────────────────────────────────────────────────────────────
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    // ─── thumb clusters (left ┊ right; rows: top palm / middle / bottom) ──────
                                                KC_TRNS,         KC_TRNS,         KC_TRNS,           KC_TRNS,
                                                                 KC_TRNS,         KC_TRNS,
                                KC_TRNS,         KC_TRNS,        KC_TRNS,         KC_TRNS,           KC_TRNS,         KC_TRNS
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
