#pragma once

/* Vial 唯一的 8 字节键盘识别安全密钥 (UID)
 * 取 sha256("keyboards/48key_rev") 的前 8 字节，保证全仓库唯一
 * (上游 util/ci_vial_verify_uid.py 会校验此项)
 */
#define VIAL_KEYBOARD_UID {0xA6, 0x8F, 0x8E, 0x03, 0x91, 0x57, 0x84, 0x44}

/* 为 Vial 客户端分配的层数 */
#define DYNAMIC_KEYMAP_LAYER_COUNT 10

/* Vial 安全解锁矩阵定义 */
#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

/* WS2812 灯带: PA10 (TIM1_CH3), 共 2 颗 LED (QMK 标准 PWM 驱动)
 * 由 rgblight / Vial 灯光层控制
 */
#define WS2812_DI_PIN A10
#define RGBLIGHT_LED_COUNT 2
/* 动画效果(替代已废弃的 RGBLIGHT_ANIMATIONS) */
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE

/* WS2812 PWM 驱动: TIM1 CH3 (PA10, AF2), TIM1_UP -> DMA1 通道 5 */
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_PWM_DMA_STREAM STM32_DMA1_STREAM5
#define WS2812_PWM_DMA_CHANNEL 5

/* ---- LED 优化 ----
 * 省电: 主机休眠(USB suspend)时自动关灯, 唤醒恢复
 */
#define RGBLIGHT_SLEEP

/* 限最大亮度(0~255), 2 颗 WS2812 全亮白约 120mA, 限一下更省电也更护眼 */
#define RGBLIGHT_LIMIT_VAL 200

/* 上电默认状态: 静态蓝光, 中等亮度, 避免一通电就乱闪/全白 */
#define RGBLIGHT_DEFAULT_ON true
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_DEFAULT_HUE 200
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 160
#define RGBLIGHT_DEFAULT_SPD 30

/* ---- 输入手感优化 (作用于 Mod-Tap / Layer-Tap / Tap-Dance 等 tap-hold 键) ---- */
#define TAPPING_TERM 175        // 点按/按住判定窗口(默认 200ms), 调小更跟手
#define PERMISSIVE_HOLD         // 先按 MT 再敲别的键也判定为"按住", 适合快速连打/滚动
#define QUICK_TAP_TERM 80       // 快速点一下 MT 后立刻敲字, 不再误触发"按住"