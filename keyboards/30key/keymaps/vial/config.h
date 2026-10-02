#pragma once

/* Vial 唯一的 8 字节键盘识别安全密钥 (UID) */
#define VIAL_KEYBOARD_UID {0xBE, 0xEF, 0x30, 0xAA, 0x55, 0x12, 0x34, 0x56}

/* 为 Vial 客户端分配的层数（30 键小键盘通常建议 4 层） */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* * Vial 安全解锁矩阵定义 
 * 默认留空，意味着不需要特殊按键组合即可在客户端解锁键盘
 */
#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

/* 新增：去抖动时间设置为 20 毫秒，用于解决矮轴连击问题 */
#define DEBOUNCE 50