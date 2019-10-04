#include <SEGGER_RTT.h>

#include "asf.h"
#include "matrix.hpp"

extern int keyboard_enabled;

static void backlight_callback()
{
	// tcc_set_compare_value(&tcc_backlight_instance, CONF_BOARD_BACKLIGHT_TCC_CHANNEL, 10);
}

static void configure_extint_callbacks()
{
	extint_register_callback(backlight_callback, CONF_BOARD_BUTTON_PIN, EXTINT_CALLBACK_TYPE_DETECT);
	extint_chan_enable_callback(CONF_BOARD_BUTTON_PIN, EXTINT_CALLBACK_TYPE_DETECT);
}

static void configure_extint()
{
	struct extint_chan_conf config = {
	    .gpio_pin = CONF_BOARD_BUTTON_EIC_PIN,
	    .gpio_pin_mux = CONF_BOARD_BUTTON_EIC_MUX,
	    .gpio_pin_pull = EXTINT_PULL_UP,
	    .wake_if_sleeping = true,
	    .filter_input_signal = true,
	    .detection_criteria = EXTINT_DETECT_FALLING};

	extint_chan_set_config(CONF_BOARD_BUTTON_PIN, &config);
}

int main()
{
	system_init();
	delay_init();
	sleepmgr_init();

	matrix_init();
	configure_extint();
	configure_extint_callbacks();

	udc_start();
	cpu_irq_enable();

	while (true) {
		if (keyboard_enabled) {
			matrix_scan();
		}

		delay_ms(3);

		// sleepmgr_enter_sleep();
	}

	return 0;
}
