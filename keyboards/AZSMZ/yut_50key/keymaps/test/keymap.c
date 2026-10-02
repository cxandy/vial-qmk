#include QMK_KEYBOARD_H
#include "gpio.h"

#define DIN A13

/* 诊断固件: 按键翻页, 每阶段点亮指定 LED 的指定颜色, 用来判断
 * 1) 两颗灯各自的字节序 (GRB/RGB/BGR)
 * 2) 是否 RGBW (SK6812, 多一个 W 白通道)
 * 3) 两颗灯是否同型号
 * 时序用已验证的 t0h=1, t1h=12 (NOP 忙等, 常量会展开, 故用全局运行时变量) */
uint8_t t0h_loops = 1;
uint8_t t1h_loops = 12;

static inline void waste(uint8_t n) {
    while (n--) {
        __asm__ volatile("nop" ::: "memory");
    }
}

static void rawbit(bool one) {
    gpio_write_pin_high(DIN);
    waste(one ? t1h_loops : t0h_loops);
    gpio_write_pin_low(DIN);
}

/* GRB 字节序发送, 每颗灯正好 3 字节 (24bit), 不额外发 W 字节 */
static void send_led(bool on, uint8_t g, uint8_t r, uint8_t b) {
    for (int b7 = 7; b7 >= 0; b7--) rawbit(g & (1 << b7));
    for (int b7 = 7; b7 >= 0; b7--) rawbit(r & (1 << b7));
    for (int b7 = 7; b7 >= 0; b7--) rawbit(b & (1 << b7));
    (void)on;
}

/* 阶段定义: 0=全灭 1..N 为测试组合 */
typedef struct {
    uint8_t g0, r0, b0; /* LED0 */
    uint8_t g1, r1, b1; /* LED1 */
} phase_t;

static const phase_t phases[] = {
    {0, 0, 0, 0, 0, 0},        /* 0: 全灭 */
    {0, 255, 0, 0, 0, 0},      /* 1: 仅LED0 红 */
    {255, 0, 0, 0, 0, 0},      /* 2: 仅LED0 绿 */
    {0, 0, 255, 0, 0, 0},      /* 3: 仅LED0 蓝 */
    {255, 255, 255, 0, 0, 0},  /* 4: 仅LED0 白 */
    {0, 0, 0, 0, 255, 0},      /* 5: 仅LED1 红 */
    {0, 0, 0, 255, 0, 0},      /* 6: 仅LED1 绿 */
    {0, 0, 0, 0, 0, 255},      /* 7: 仅LED1 蓝 */
    {0, 0, 0, 255, 255, 255},  /* 8: 仅LED1 白 */
    {0, 255, 0, 0, 255, 0},    /* 9: 两灯都红 */
    {255, 0, 0, 255, 0, 0},    /* 10: 两灯都绿 */
    {0, 0, 255, 0, 0, 255},    /* 11: 两灯都蓝 */
    {255, 255, 255, 255, 255, 255}, /* 12: 两灯都白 */
};

#define N_PHASES (sizeof(phases) / sizeof(phases[0]))
#define BLANK_MS 500

static uint8_t  cur   = 0;
static uint16_t blink = 0;
static bool     lit   = false;

static void send_frame(const phase_t *p) {
    send_led(true, p->g0, p->r0, p->b0);
    send_led(true, p->g1, p->r1, p->b1);
    gpio_write_pin_low(DIN);
    waste(200);
}

void keyboard_post_init_user(void) {
    gpio_set_pin_output(DIN);
    gpio_write_pin_low(DIN);
    blink = timer_read();
}

/* 阶段变化: 先全灭 500ms 再点亮 */
static void set_phase(uint8_t p) {
    cur   = p % N_PHASES;
    lit   = false;
    gpio_write_pin_low(DIN);
    blink = timer_read();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode == KC_F1) set_phase(cur + 1);
        if (keycode == KC_F2) set_phase(cur + N_PHASES - 1);
        if (keycode == KC_F3) set_phase(0);
    }
    return false;
}

void matrix_scan_user(void) {
    if (!lit && timer_elapsed(blink) >= BLANK_MS) {
        lit = true;
        send_frame(&phases[cur]);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F3,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_RSFT, KC_F2,   KC_TRNS,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_F1,   KC_SPC,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
