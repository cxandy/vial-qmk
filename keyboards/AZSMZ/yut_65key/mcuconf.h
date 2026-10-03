/*
 * AZSMZ yut-65key - MCU configuration overrides (STM32F072)
 *
 * Enable the TIM1 PWM driver used by the WS2812 PWM driver (PA10 = TIM1_CH3).
 * TIM1_UP is hardwired to DMA1 channel 5 on the STM32F072.
 */

#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE
