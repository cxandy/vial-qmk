#pragma once

/* Vial 唯一的 8 字节键盘识别安全密钥 (UID)
 * 取 sha256("keyboards/30key") 的前 8 字节，保证全仓库唯一
 * (上游 util/ci_vial_verify_uid.py 会校验此项)
 */
#define VIAL_KEYBOARD_UID {0xD7, 0xC4, 0x52, 0x6E, 0xA4, 0xB6, 0x56, 0x9F}

/* 为 Vial 客户端分配的层数（30 键小键盘通常建议 4 层） */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* * Vial 安全解锁矩阵定义 
 * 默认留空，意味着不需要特殊按键组合即可在客户端解锁键盘
 */
#define VIAL_UNLOCK_COMBO_ROWS { 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0 }

/* 新增：去抖动时间设置为 20 毫秒，用于解决矮轴连击问题 */
#define DEBOUNCE 50