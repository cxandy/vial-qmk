# QMK / VIA 基础核心功能开关
VIA_ENABLE = yes
LTO_ENABLE = no

# Vial 专用核心开关
VIAL_ENABLE = yes
VIAL_MACRO_ENABLE = yes

MOUSEKEY_ENABLE = yes

# Planck 风格需要额外的功能键支持
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = no

# WS2812 灯带 (PA10 = TIM1_CH3, 2 颗, 标准 PWM 驱动 + DMA)
# 走 rgblight / Vial 灯光层控制 (RGBLIGHT_DRIVER 默认 ws2812, 自动引入 PWM 驱动)
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = pwm
WS2812_DRIVER_REQUIRED = yes