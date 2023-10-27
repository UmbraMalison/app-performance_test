/*
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Performance Testing App
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

// For STM HAL/LL
#include <soc.h>
#include <stm32_ll_gpio.h>
// #include <stm32g0xx_hal.h>

// For STM HAL/LL
#define SIGNAL_GPIO_Port	GPIOA
#define SIGNAL_Pin			GPIO_PIN_8

// For Zephyr API
#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)
const struct gpio_dt_spec signal = GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, signal_gpios);

	

	// WRITE_REG(gpio->BSRR, pins);

int main(void)
{
	// const struct device *dev = &signal.port;
	// const struct gpio_stm32_config *cfg = dev->config;
	// GPIO_TypeDef *gpio = (GPIO_TypeDef *)cfg->base;

	/* Configure the pin */
	gpio_pin_configure_dt(&signal, GPIO_OUTPUT_INACTIVE);
	uint8_t state = 0;
	while (1)
	{
		state ^= 1;
		// ZEPHYR API
		// gpio_pin_set_dt(&signal, state);
		gpio_pin_toggle_dt(&signal);

		// LL
		// LL_GPIO_TogglePin(SIGNAL_GPIO_Port,SIGNAL_Pin);
		// LL_GPIO_WriteOutputPort(SIGNAL_GPIO_Port, state<<8);

		// HAL
		// HAL_GPIO_TogglePin(SIGNAL_GPIO_Port,SIGNAL_Pin);
		// HAL_GPIO_WritePin(SIGNAL_GPIO_Port, SIGNAL_Pin, state);

		// WRITE_REG(gpio->BSRR, pins); # not finished.
	
		// k_sleep(K_USEC(100000));
	}
	return 0;
}
