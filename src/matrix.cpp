#include "matrix.hpp"
#include "asf.h"

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))
#define BIT_VALUE_U32(x) (static_cast<uint32_t>(1) << x)

static const uint32_t rows[] = {
    CONF_BOARD_MATRIX_DRIVE_0_PIN,
    CONF_BOARD_MATRIX_DRIVE_1_PIN,
    CONF_BOARD_MATRIX_DRIVE_2_PIN,
    CONF_BOARD_MATRIX_DRIVE_3_PIN,
    CONF_BOARD_MATRIX_DRIVE_4_PIN,
    CONF_BOARD_MATRIX_DRIVE_5_PIN,
    CONF_BOARD_MATRIX_DRIVE_6_PIN,
    CONF_BOARD_MATRIX_DRIVE_7_PIN};

static const uint32_t columns[] = {
    CONF_BOARD_MATRIX_SENSE_0_PIN,
    CONF_BOARD_MATRIX_SENSE_1_PIN,
    CONF_BOARD_MATRIX_SENSE_2_PIN,
    CONF_BOARD_MATRIX_SENSE_3_PIN,
    CONF_BOARD_MATRIX_SENSE_4_PIN,
    CONF_BOARD_MATRIX_SENSE_5_PIN,
    CONF_BOARD_MATRIX_SENSE_6_PIN,
    CONF_BOARD_MATRIX_SENSE_7_PIN,
    CONF_BOARD_MATRIX_SENSE_8_PIN};

static uint32_t column_pin_mask = 0;
static uint32_t column_state[ARRAY_LENGTH(rows)] = {0};

static uint32_t read_column_state(uint32_t r_idx)
{
	uint32_t c;

	port_pin_set_output_level(rows[r_idx], false);
	delay_us(1);

	c = port_group_get_input_level(&PORTA, column_pin_mask);

	port_pin_set_output_level(rows[r_idx], true);
	delay_us(1);

	return c;
}

void matrix_init()
{
	for (uint32_t column : columns) {
		column_pin_mask |= BIT_VALUE_U32(column);
	}
}

void matrix_scan()
{
	static uint32_t new_column_state[ARRAY_LENGTH(rows)] = {};

	for (uint32_t r_idx = 0; r_idx < ARRAY_LENGTH(rows); r_idx++) {
		new_column_state[r_idx] = read_column_state(r_idx);
	}

	bool fn_key_pressed = false;

	/*
	 * Check if FN is pressed (FN or CAPS_LOCK)
	 */
	if (~new_column_state[7] & BIT_VALUE_U32(columns[0])) {
		fn_key_pressed = true;
	}

	for (uint32_t r_idx = 0; r_idx < ARRAY_LENGTH(rows); r_idx++) {
		for (uint32_t c_idx = 0; c_idx < ARRAY_LENGTH(columns); c_idx++) {
			const matrix_key_t *key;

			uint32_t key_idx = (r_idx * ARRAY_LENGTH(columns)) + c_idx;

			if (fn_key_pressed) {
				key = &keymap_fn[key_idx];
			} else {
				key = &keymap[key_idx];
			}

			int32_t old_key_state = column_state[r_idx] & BIT_VALUE_U32(columns[c_idx]);
			int32_t new_key_state = new_column_state[r_idx] & BIT_VALUE_U32(columns[c_idx]);

			if (old_key_state > new_key_state) {
				key->modifier ? udi_hid_kbd_modifier_down(key->scancode)
				              : udi_hid_kbd_down(key->scancode);
				column_state[r_idx] &= ~BIT_VALUE_U32(columns[c_idx]);
			} else if (old_key_state < new_key_state) {
				key->modifier ? udi_hid_kbd_modifier_up(key->scancode)
				              : udi_hid_kbd_up(key->scancode);
				column_state[r_idx] |= BIT_VALUE_U32(columns[c_idx]);
			}
		}
	}
}
