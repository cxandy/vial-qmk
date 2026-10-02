#include QMK_KEYBOARD_H

// 层切换键（点按 = 功能，长按 = 切换层）
#define SP_L1   LT(1, KC_SPC)    // 空格 / 层1（数字符号）
#define BS_L2   LT(2, KC_BSPC)   // 退格 / 层2（功能·标点·导航）
#define C_L3    LT(3, KC_C)      // C    / 层3（媒体·系统）

// 底部行左右侧（点按 = 字母，长按 = 修饰键），保住全部 26 个字母
#define CTL_Z   CTL_T(KC_Z)
#define ALT_X   ALT_T(KC_X)
#define ALT_N   ALT_T(KC_N)
#define CTL_M   CTL_T(KC_M)
#define SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // 层 0：基础 QWERTY
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
        CTL_Z,   ALT_X,   C_L3,    KC_V,    BS_L2,   SP_L1,   KC_B,    ALT_N,   CTL_M,   SFT_ENT
    ),

    // 层 1：数字与符号（按住空格进入）
    [1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    // 层 2：功能键、标点与导航（按住退格进入）
    [2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12,  KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_COMM, KC_DOT
    ),

    // 层 3：媒体与系统功能（按住 C 进入）
    [3] = LAYOUT(
        KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU, KC_VOLD, KC_MUTE, KC_PSCR, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
