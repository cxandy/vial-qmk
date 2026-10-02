#pragma once

/* Vial 唯一的 8 字节键盘识别安全密钥 (UID) */
#define VIAL_KEYBOARD_UID {0xBE, 0xEF, 0x30, 0xAA, 0x55, 0x12, 0x34, 0x56}

/* 为 Vial 客户端分配的层数 */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* Vial 安全解锁矩阵定义 */
#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

/* WS2812 LED 引脚与数量 */
#define WS2812_PIN PA10
#define WS2812_NUM_PIXELS 2