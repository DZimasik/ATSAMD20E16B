/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_rtc_base.h>

struct spi_m_sync_descriptor SPI_0;
struct timer_descriptor      TIMER_0;

struct flash_descriptor FLASH_0;

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void EXTERNAL_IRQ_0_init(void)
{
	_gclk_enable_channel(EIC_GCLK_ID, CONF_GCLK_EIC_SRC);

	// Set pin direction to input
	gpio_set_pin_direction(PA00, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA00,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PA00, PINMUX_PA00A_EIC_EXTINT0);

	ext_irq_init();
}

void system_init(void)
{
	init_mcu();
        
        // Set pin direction to output
        gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);
        gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);
        
        gpio_set_pin_level(LED1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(LED1, GPIO_DIRECTION_OUT);
	gpio_set_pin_function(LED1, GPIO_PIN_FUNCTION_OFF);

	EXTERNAL_IRQ_0_init();

	delay_driver_init();
}
