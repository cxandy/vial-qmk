#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RAISE,
    _FN,
    _ADJUST,
    _L5,
    _L6,
    _L7,
    _L8,
    _L9,
    _L10,
};

#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_RSFT, KC_UP,   FN,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(_RAISE), KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_RAISE] = LAYOUT(
        KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LBRC, KC_RBRC, KC_SLSH, KC_BSLS,
        KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MINS, KC_EQL,  KC_UP,   MO(_ADJUST),
        KC_COMM, KC_DOT,  KC_SCLN, KC_QUOT, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_VOLD, KC_VOLU, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
        KC_MS_UP,   KC_MS_DOWN,  KC_MS_LEFT, KC_MS_RIGHT, _______, _______, KC_MPLY, KC_MNXT, KC_MPRV, KC_UP,   KC_MSTP,
        KC_MS_WH_UP, KC_MS_WH_DOWN, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_ADJUST] = LAYOUT(
        RGB_TOG, QK_CLEAR_EEPROM, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        RGB_MOD, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_L5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_L6] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_L7] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_L8] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_L9] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_L10] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______ 
    ),
};

#include "process_combo.h"

typedef struct {
    uint16_t k1, k2, out;
    bool k1_down, k2_down;
    uint32_t t;
    bool fired;
} paren_combo_t;

static paren_combo_t paren_combos[2] = {
    { KC_Z, KC_X, KC_LPRN, false, false, 0, false },
    { KC_C, KC_V, KC_RPRN, false, false, 0, false },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state) != 0) return true;

    for (int i = 0; i < 2; i++) {
        paren_combo_t *c = &paren_combos[i];

        if (keycode == c->k1) {
            if (record->event.pressed) {
                c->k1_down = true;
                c->t = timer_read32();
                return false;
            }
            c->k1_down = false;
            if (c->fired) {
                if (!c->k1_down && !c->k2_down) c->fired = false;
                return false;
            }
            tap_code16(c->k1);
            return false;
        }

        if (keycode == c->k2) {
            if (record->event.pressed) {
                c->k2_down = true;
                if (c->k1_down && timer_elapsed32(c->t) < COMBO_TERM) {
                    c->fired = true;
                    tap_code16(c->out);
                    return false;
                }
                return true;
            }
            c->k2_down = false;
            if (c->fired) {
                if (!c->k1_down && !c->k2_down) c->fired = false;
                return false;
            }
            return true;
        }
    }

    return true;
}

static bool caps_on = false;

static void update_status_leds(void) {
    if (caps_on) {
        rgblight_sethsv(0, 255, 255);
        return;
    }
    switch (get_highest_layer(layer_state)) {
        case _ADJUST:
            rgblight_sethsv(192, 255, 255);
            break;
        case _RAISE:
            rgblight_sethsv(96, 255, 255);
            break;
        case _FN:
            rgblight_sethsv(32, 255, 255);
            break;
        default:
            rgblight_sethsv(160, 255, 255);
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    update_status_leds();
    return state;
}

bool led_update_user(led_t led_state) {
    caps_on = led_state.caps_lock;
    update_status_leds();
    return false;
}