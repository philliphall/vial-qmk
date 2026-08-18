#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // Left
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_LBRC,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_LPRN,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_PWR,
                                             KC_LSFT, LT(2, KC_DEL), KC_LCTL, KC_LALT,

        // Right
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,        KC_GRV,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_BSLS,
        KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT,
                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_RSFT,
        LT(1, KC_ENT), KC_SPC, KC_INS, MO(1)
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// Rev4-style "super encoder" actions.
// These are assigned as the factory/default encoder actions,
// but Vial can replace them in the dynamic encoder map.
enum peterdroge_keycodes {
    ENC_SUPER_CCW = QK_KB_0,
    ENC_SUPER_CW,
};

static uint16_t encoder_timer = 0;
static const uint16_t encoder_timeout = 900;

static bool is_alt_tab_active = false;
static bool is_backspace_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case ENC_SUPER_CW:
            // If we were doing backspaces, clockwise becomes Undo.
            if (is_backspace_active) {
                tap_code16(C(KC_Z));
            }

            // Continue Alt-Tab.
            else if (is_alt_tab_active) {
                tap_code16(KC_TAB);
            }

            // Start Alt-Tab.
            else {
                is_alt_tab_active = true;
                register_code(KC_LALT);
                tap_code16(KC_TAB);
            }

            encoder_timer = timer_read();
            return false;

        case ENC_SUPER_CCW:
            // If Alt is already held, go backward through Alt-Tab.
            if (is_alt_tab_active) {
                tap_code16(S(KC_TAB));
            }

            // Otherwise enter/continue backspace mode.
            else {
                is_backspace_active = true;
                tap_code16(KC_BSPC);
            }

            encoder_timer = timer_read();
            return false;
    }

    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active &&
        timer_elapsed(encoder_timer) > encoder_timeout) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }

    if (is_backspace_active &&
        timer_elapsed(encoder_timer) > encoder_timeout) {
        is_backspace_active = false;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(ENC_SUPER_CCW, ENC_SUPER_CW),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS) // This right encoder doesn't exist, but QMK thinks it does.
    },
    [1] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [2] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [3] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    }
};
#endif
