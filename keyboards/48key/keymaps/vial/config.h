#pragma once

/* Vial 唯一的 8 字节键盘识别安全密钥 (UID)
 * 取 sha256("keyboards/48key") 的前 8 字节，保证全仓库唯一
 * (上游 util/ci_vial_verify_uid.py 会校验此项)
 */
#define VIAL_KEYBOARD_UID {0x5F, 0x5B, 0xEC, 0x9B, 0x9A, 0x67, 0x21, 0xEC}

/* 为 Vial 客户端分配的层数 */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* Vial 安全解锁矩阵定义 */
#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

/* WS2812 LED 引脚与数量 */
#define WS2812_PIN PA10
#define WS2812_NUM_PIXELS 2