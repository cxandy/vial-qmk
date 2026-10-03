#include QMK_KEYBOARD_H

/*  65 键 (5 行 x 14 列，其中 5 个位置没有开关)，传统四层
 *
 *  物理排布（每行 14u 宽）
 *      row0 (14):  `  1  2  3  4  5  6  7  8  9  0  -  =  Bksp
 *      row1 (14):  Tab  Q  W  E  R  T  Y  U  I  O  P  [  ]  \
 *      row2 (13):  Caps  A  S  D  F  G  H  J  K  L  ;  '  Enter(1.75u)
 *      row3 (13):  Shft  Z  X  C  V  B  N  M  ,  .  Shft(1.25u)  Up  /
 *      row4 (11):  Ctl(1.25) Win(1.25) Alt(1.25)  Space(2u) Fn Space(2u)  <-  v(1.25)  ->  Sym  Ctrl
 *
 *  没有装开关的矩阵位置（0 基）：[2,13] [3,8] [4,3] [4,7] [4,8]
 *  引脚：行 A0-A4，列 B0-B13
 *
 *  分层
 *      _BASE   字母 + 数字行；方向键在右手，空格分体两段
 *      _SYM    F1-F12 + 符号 + 导航，右手小指 [4,12] 触发
 *      _FN     Esc / 媒体 / 鼠标 / 灯光，左手拇指 [4,5] 触发
 *      _ADJUST 灯光 + 刷写，从 _SYM 的 [4,12] / _FN 的 [3,13] 进
 *
 *  主页字母双键组合（见下方 combo_defs），让 ()[]{}\_ 不必切层
 */

enum layers {
    _BASE,
    _SYM,
    _FN,
    _ADJUST,
    _L5,
    _L6,
    _L7,
    _L8,
    _L9,
    _L10
};

#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, KC_UP, KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, FN, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, MO(_SYM), KC_RCTL
    ),
    [_SYM] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_BSPC,
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_UNDS,
        KC_TRNS, KC_TAB, KC_LCBR, KC_RCBR, KC_BSLS, KC_COLN, KC_DQUO, KC_QUOT, KC_GRV, KC_MINS, KC_EQL, KC_TRNS, KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_BSLS, KC_TRNS, KC_UP, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_SPC, KC_HOME, KC_PGDN, KC_END, MO(_ADJUST), KC_TRNS
    ),
    [_FN] = LAYOUT(
        KC_ESC, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_BRIU, KC_BRID, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS,
        KC_TAB, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_UP, KC_MS_DOWN, KC_MS_LEFT, KC_MS_RIGHT, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_TRNS, KC_HOME, KC_PGUP, KC_END,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_RMOD, RGB_SPD, RGB_SPI, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, MO(_ADJUST),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_ADJUST] = LAYOUT(
        RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPD, RGB_SPI, QK_DEBUG_TOGGLE, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_CLEAR_EEPROM, RESET, QK_BOOTLOADER, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_L5] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_L6] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_L7] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_L8] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_L9] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_L10] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* ------------------------------------------------------------------ *
 *  主页双键组合
 *
 *  同一时刻按下组合里的两个字母 -> 输出 out; 否则各自当作普通字母。
 *  两个方向都认 (Z+X 和 X+Z 等价), 一个字母可以出现在多条组合里。
 *
 *  实现方式: 按下时先 "吞掉" 这个字母不注册, 一直等到松开时才知道
 *  有没有配成组合 —— 没配成就用 tap_code16() 补打出来。
 *  代价: 字母要等松手才上屏, 长按不会自动重复; 极速连打组合键里的
 *  两个相邻字母 (如 zc) 有小概率被识别成组合。
 * ------------------------------------------------------------------ */

typedef struct {
    uint16_t a, b, out;
} combo_def_t;

static const combo_def_t combo_defs[] = {
    {KC_Z, KC_X, KC_LPRN},   /* Z + X = ( */
    {KC_C, KC_V, KC_RPRN},   /* C + V = ) */
    {KC_X, KC_C, KC_LBRC},   /* X + C = [ */
    {KC_V, KC_B, KC_RBRC},   /* V + B = ] */
    {KC_Z, KC_C, KC_LCBR},   /* Z + C = { */
    {KC_B, KC_N, KC_RCBR},   /* B + N = } */
    {KC_N, KC_M, KC_BSLS},   /* N + M = \ */
    {KC_X, KC_V, KC_UNDS},   /* X + V = _ */
};
#define PAREN_COMBO_COUNT (sizeof(combo_defs) / sizeof(combo_defs[0]))

/* 参与组合的字母, 状态按这个顺序存 */
static const uint16_t combo_kcs[] = {KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M};
#define PAREN_COMBO_KEY_COUNT (sizeof(combo_kcs) / sizeof(combo_kcs[0]))

#ifndef COMBO_TERM
#    define PAREN_COMBO_TERM 50
#else
#    define PAREN_COMBO_TERM COMBO_TERM
#endif

static struct {
    bool     down;      /* 按下未松 */
    bool     consumed;  /* 已被某条组合吃掉 */
    uint32_t t;         /* 按下时刻 */
} combo_keys[PAREN_COMBO_KEY_COUNT];

static int8_t combo_key_index(uint16_t kc) {
    for (uint8_t i = 0; i < PAREN_COMBO_KEY_COUNT; i++) {
        if (combo_kcs[i] == kc) return (int8_t)i;
    }
    return -1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state) != 0) return true;  /* 只在主页生效 */

    const int8_t self = combo_key_index(keycode);
    if (self < 0) return true;

    if (record->event.pressed) {
        const uint32_t now = timer_read32();

        combo_keys[self].down     = true;
        combo_keys[self].t        = now;
        combo_keys[self].consumed = false;

        for (uint8_t i = 0; i < PAREN_COMBO_COUNT; i++) {
            const combo_def_t *d = &combo_defs[i];
            int8_t partner;

            if (d->a == keycode) {
                partner = combo_key_index(d->b);
            } else if (d->b == keycode) {
                partner = combo_key_index(d->a);
            } else {
                continue;
            }
            if (partner < 0) continue;

            if (combo_keys[partner].down && !combo_keys[partner].consumed &&
                (now - combo_keys[partner].t) <= PAREN_COMBO_TERM) {
                combo_keys[self].consumed     = true;
                combo_keys[partner].consumed = true;
                tap_code16(d->out);
                break;
            }
        }
        return false;  /* 先吞掉, 松手时再决定出字母还是出组合 */
    }

    combo_keys[self].down = false;
    if (combo_keys[self].consumed) return false;

    tap_code16(keycode);  /* 没配成组合, 把字母补打出来 */
    return false;
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
        case _SYM:
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