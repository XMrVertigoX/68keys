#include "asf.h"

int keyboard_enabled = false;

void udc_start_of_frame()
{
	// uint16_t frame_number = udd_get_frame_number();
}

void udc_suspend()
{
}

void udc_resume()
{
}

void udc_remotewakeup_enable()
{
}

void udc_remotewakeup_disable()
{
}

int udi_keyboard_enable()
{
	keyboard_enabled = true;

	port_pin_set_output_level(CONF_BOARD_LED_TX_PIN, !keyboard_enabled);

	return keyboard_enabled;
}

void udi_keyboard_disable()
{
	keyboard_enabled = false;

	port_pin_set_output_level(CONF_BOARD_LED_TX_PIN, !keyboard_enabled);
}

void udi_keyboard_led(int enable)
{
	port_pin_set_output_level(CONF_BOARD_LED_RX_PIN, !enable);
}
