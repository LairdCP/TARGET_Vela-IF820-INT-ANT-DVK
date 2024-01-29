/*
 * Copyright 2016-2024, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */


#include "wiced_platform.h"

#define BTN_USER_config \
{\
    .gpio = (wiced_bt_gpio_numbers_t*)&platform_gpio_pins[PLATFORM_GPIO_0].gpio_pin, \
    .config = GPIO_INPUT_ENABLE | GPIO_PULL_UP | GPIO_INTERRUPT_ENABLE | GPIO_EN_INT_FALLING_EDGE, \
    .default_state = GPIO_PIN_OUTPUT_HIGH, \
    .button_pressed_value = GPIO_PIN_OUTPUT_LOW, \
}
#define LED2_config \
{\
    .gpio = (wiced_bt_gpio_numbers_t*)&platform_gpio_pins[PLATFORM_GPIO_4].gpio_pin, \
    .config = GPIO_OUTPUT_ENABLE | GPIO_INPUT_DISABLE, \
    .default_state = GPIO_PIN_OUTPUT_HIGH, \
 }
#define LED1_config \
{\
    .gpio = (wiced_bt_gpio_numbers_t*)&platform_gpio_pins[PLATFORM_GPIO_1].gpio_pin, \
    .config = GPIO_INPUT_ENABLE | GPIO_PULL_DOWN, \
    .default_state = GPIO_PIN_OUTPUT_LOW, \
 }

const wiced_platform_gpio_t platform_gpio_pins[] =
{
    [PLATFORM_GPIO_0] = {WICED_P00, WICED_GPIO},
    [PLATFORM_GPIO_1] = {WICED_P04, WICED_GPIO},
    [PLATFORM_GPIO_2] = {WICED_P10, WICED_UART_2_CTS},
    [PLATFORM_GPIO_3] = {WICED_P11, WICED_UART_2_RTS},
    [PLATFORM_GPIO_4] = {WICED_P27, WICED_GPIO},
    [PLATFORM_GPIO_5] = {WICED_P32, WICED_UART_2_TXD},
    [PLATFORM_GPIO_6] = {WICED_P37, WICED_UART_2_RXD},
};
const size_t platform_gpio_pin_count = (sizeof(platform_gpio_pins) / sizeof(wiced_platform_gpio_t));
const wiced_platform_led_config_t platform_led[] =
{
    [WICED_PLATFORM_LED_1] = LED1_config,
    [WICED_PLATFORM_LED_2] = LED2_config,
};
const size_t led_count = (sizeof(platform_led) / sizeof(wiced_platform_led_config_t));
const wiced_platform_button_config_t platform_button[] =
{
    [WICED_PLATFORM_BUTTON_1] = BTN_USER_config,
};
const size_t button_count = (sizeof(platform_button) / sizeof(wiced_platform_button_config_t));
const wiced_platform_gpio_config_t platform_gpio[] =
{
};
const size_t gpio_count = (sizeof(platform_gpio) / sizeof(wiced_platform_gpio_config_t));

void init_cycfg_all()
{
    extern UINT8 btrf_pwrRamAdLEVs_br[];
    extern UINT8 btrf_pwrRamAdLEVs_edr[];
    extern UINT8 btrf_pwrRamAdLEVs_le[];

    //RF table for Vela-IF820-INT-ANT
    btrf_pwrRamAdLEVs_edr[0] = 0x00;
    btrf_pwrRamAdLEVs_edr[1] = 0x02;
    btrf_pwrRamAdLEVs_edr[2] = 0x05;
    btrf_pwrRamAdLEVs_edr[3] = 0x08;
    btrf_pwrRamAdLEVs_edr[4] = 0x0C;
    btrf_pwrRamAdLEVs_edr[5] = 0x13;

    btrf_pwrRamAdLEVs_br[0] = 0x03;
    btrf_pwrRamAdLEVs_br[1] = 0x07;
    btrf_pwrRamAdLEVs_br[2] = 0x0B;
    btrf_pwrRamAdLEVs_br[3] = 0x11;
    btrf_pwrRamAdLEVs_br[4] = 0x15;
    btrf_pwrRamAdLEVs_br[5] = 0x19;

    btrf_pwrRamAdLEVs_le[0] = 0x02;
    btrf_pwrRamAdLEVs_le[1] = 0x05;
    btrf_pwrRamAdLEVs_le[2] = 0x09;
    btrf_pwrRamAdLEVs_le[3] = 0x0B;
    btrf_pwrRamAdLEVs_le[4] = 0x10;
    btrf_pwrRamAdLEVs_le[5] = 0x13;
    *((uint32_t*)0x60019c) = 0x02;
}
