#include "asf.h"

struct tcc_module tcc_backlight_instance;

static void configure_leds()
{
	struct port_config config = {};

	port_get_config_defaults(&config);
	config.direction = PORT_PIN_DIR_OUTPUT;

	port_pin_set_config(CONF_BOARD_LED_TX_PIN, &config);
	port_pin_set_config(CONF_BOARD_LED_RX_PIN, &config);
	port_pin_set_output_level(CONF_BOARD_LED_TX_PIN, true);
	port_pin_set_output_level(CONF_BOARD_LED_RX_PIN, true);
}

static void configure_button()
{
	struct port_config config = {};

	port_get_config_defaults(&config);
	config.direction = PORT_PIN_DIR_INPUT;
	config.input_pull = PORT_PIN_PULL_UP;

	port_pin_set_config(CONF_BOARD_BUTTON_PIN, &config);
}

static void configure_drive_port_pins()
{
	struct port_config config = {};

	port_get_config_defaults(&config);
	config.direction = PORT_PIN_DIR_OUTPUT;

	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_0_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_1_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_2_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_3_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_4_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_5_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_6_PIN, &config);
	port_pin_set_config(CONF_BOARD_MATRIX_DRIVE_7_PIN, &config);
}

static void configure_sense_port_pins()
{
	struct port_config port_config = {};

	port_get_config_defaults(&port_config);
	port_config.direction = PORT_PIN_DIR_INPUT;
	port_config.input_pull = PORT_PIN_PULL_UP;

	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_0_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_1_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_2_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_3_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_4_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_5_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_6_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_7_PIN, &port_config);
	port_pin_set_config(CONF_BOARD_MATRIX_SENSE_8_PIN, &port_config);

	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_0_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_1_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_2_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_3_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_4_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_5_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_6_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_7_PIN, true);
	port_pin_set_output_level(CONF_BOARD_MATRIX_SENSE_8_PIN, true);
}

static void configure_backlight_pin()
{
	struct port_config port_config = {};

	port_get_config_defaults(&port_config);
	port_config.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(CONF_BOARD_BACKLIGHT_PIN, &port_config);
	port_pin_set_output_level(CONF_BOARD_BACKLIGHT_PIN, false);
}

static void configure_backlight_tcc()
{
	struct tcc_config tcc_config = {};

	tcc_get_config_defaults(&tcc_config, TCC1);
	tcc_config.counter.period = 100;
	tcc_config.counter.clock_source = GCLK_GENERATOR_1;
	tcc_config.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	tcc_config.compare.match[CONF_BOARD_BACKLIGHT_TCC_CHANNEL] = 0;
	tcc_config.pins.enable_wave_out_pin[CONF_BOARD_BACKLIGHT_TCC_CHANNEL] = true;
	tcc_config.pins.wave_out_pin[CONF_BOARD_BACKLIGHT_TCC_CHANNEL] = CONF_BOARD_BACKLIGHT_TCC_PIN;
	tcc_config.pins.wave_out_pin_mux[CONF_BOARD_BACKLIGHT_TCC_CHANNEL] = CONF_BOARD_BACKLIGHT_TCC_MUX;
	tcc_init(&tcc_backlight_instance, TCC1, &tcc_config);
	tcc_enable(&tcc_backlight_instance);
}

extern "C" void system_board_init()
{
	// Inputs
	configure_button();
	configure_sense_port_pins();

	// Outputs
	configure_leds();
	configure_drive_port_pins();

	configure_backlight_pin();
	configure_backlight_tcc();
}
