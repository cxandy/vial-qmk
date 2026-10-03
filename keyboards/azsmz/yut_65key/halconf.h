/*
 * AZSMZ yut-65key - HAL configuration overrides (STM32F072)
 *
 * Enable the PWM HAL module used by the WS2812 PWM driver (PA10 = TIM1_CH3).
 */

#pragma once

#define HAL_USE_PWM TRUE

#include_next <halconf.h>
