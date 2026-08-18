#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // Left
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_LBRC,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_LPRN,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_PWR,
                                             KC_LSFT, KC_DEL, KC_LCTL, KC_LALT,

        // Right
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,        KC_GRV,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_BSLS,
        KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT,
                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_RSFT,
        KC_ENT, KC_SPC, KC_INS, MO(1)
    )
};
