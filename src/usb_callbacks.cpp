#include "asf.h"

int keyboard_enabled = false;
void udi_keyboard_disable()
{
	keyboard_enabled = false;
	port_pin_set_output_level(CONF_BOARD_LED_TX_PIN, !keyboard_enabled);
}

int udi_keyboard_enable()
{
	keyboard_enabled = true;
	port_pin_set_output_level(CONF_BOARD_LED_TX_PIN, !keyboard_enabled);

	return keyboard_enabled;
}

void udi_keyboard_led(int enable)
{
	port_pin_set_output_level(CONF_BOARD_LED_RX_PIN, !enable);
}
