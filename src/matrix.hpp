#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstdint>

#include "scancodes.hpp"

struct matrix_key_t {
	uint32_t scancode;
	uint32_t modifier;
};

const matrix_key_t keymap[] = {
    // R4
    {KEYBOARD_ESC, false},
    {KEYBOARD_1, false},
    {KEYBOARD_2, false},
    {KEYBOARD_3, false},
    {KEYBOARD_4, false},
    {KEYBOARD_5, false},
    {KEYBOARD_6, false},
    {KEYBOARD_7, false},
    {KEYBOARD_8, false},
    {KEYBOARD_9, false},
    {KEYBOARD_0, false},
    {KEYBOARD_MINUS, false},
    {KEYBOARD_EQUAL, false},
    {KEYBOARD_BACKSPACE, false},
    {KEYBOARD_HOME, false},
    {KEYBOARD_PAGEUP, false},
    // R3
    {KEYBOARD_TAB, false},
    {KEYBOARD_Q, false},
    {KEYBOARD_W, false},
    {KEYBOARD_E, false},
    {KEYBOARD_R, false},
    {KEYBOARD_T, false},
    {KEYBOARD_Y, false},
    {KEYBOARD_U, false},
    {KEYBOARD_I, false},
    {KEYBOARD_O, false},
    {KEYBOARD_P, false},
    {KEYBOARD_LEFTBRACE, false},
    {KEYBOARD_RIGHTBRACE, false},
    {KEYBOARD_BACKSLASH, false},
    {KEYBOARD_END, false},
    {KEYBOARD_PAGEDOWN, false},
    // R2
    {KEYBOARD_CAPSLOCK, false},
    {KEYBOARD_A, false},
    {KEYBOARD_S, false},
    {KEYBOARD_D, false},
    {KEYBOARD_F, false},
    {KEYBOARD_G, false},
    {KEYBOARD_H, false},
    {KEYBOARD_J, false},
    {KEYBOARD_K, false},
    {KEYBOARD_L, false},
    {KEYBOARD_SEMICOLON, false},
    {KEYBOARD_APOSTROPHE, false},
    {KEYBOARD_ENTER, false},
    // R1
    {MODIFIER_LSHIFT, true},
    {KEYBOARD_Z, false},
    {KEYBOARD_X, false},
    {KEYBOARD_C, false},
    {KEYBOARD_V, false},
    {KEYBOARD_B, false},
    {KEYBOARD_N, false},
    {KEYBOARD_M, false},
    {KEYBOARD_COMMA, false},
    {KEYBOARD_DOT, false},
    {KEYBOARD_SLASH, false},
    {MODIFIER_RSHIFT, true},
    {KEYBOARD_UP, false},
    // R0
    {MODIFIER_LCTRL, true},
    {MODIFIER_LMETA, true},
    {MODIFIER_LALT, true},
    {KEYBOARD_SPACEBAR, false},
    {MODIFIER_RALT, true},
    {NONE, true}, /* Keyboard FN, MODIFIER_RMETA */
    {MODIFIER_RCTRL, true},
    {KEYBOARD_LEFT, false},
    {KEYBOARD_DOWN, false},
    {KEYBOARD_RIGHT, false},
    {NONE, false}, /* Left over */
    {NONE, false}, /* Left over */
    {NONE, false}, /* Left over */
    {NONE, false}, /* Left over */
};

const matrix_key_t keymap_fn[] = {
    // R4
    {KEYBOARD_GRAVE, false},
    {KEYBOARD_F1, false},
    {KEYBOARD_F2, false},
    {KEYBOARD_F3, false},
    {KEYBOARD_F4, false},
    {KEYBOARD_F5, false},
    {KEYBOARD_F6, false},
    {KEYBOARD_F7, false},
    {KEYBOARD_F8, false},
    {KEYBOARD_F9, false},
    {KEYBOARD_F10, false},
    {NONE, false},
    {NONE, false},
    {KEYBOARD_DELETE, false},
    {NONE, false},
    {NONE, false},
    // R3
    {NONE, false},
    {KEYBOARD_F11, false},
    {KEYBOARD_F12, false},
    {KEYBOARD_F13, false},
    {KEYBOARD_F14, false},
    {KEYBOARD_F15, false},
    {KEYBOARD_F16, false},
    {KEYBOARD_F17, false},
    {KEYBOARD_F18, false},
    {KEYBOARD_F19, false},
    {KEYBOARD_F20, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    // R2
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    // R1
    {MODIFIER_LSHIFT, true},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {MODIFIER_RSHIFT, true},
    {NONE, false},
    // R0
    {MODIFIER_LCTRL, true},
    {MODIFIER_LMETA, true},
    {MODIFIER_LALT, true},
    {NONE, false},
    {MODIFIER_RALT, true},
    {NONE, true}, /* Keyboard FN, MODIFIER_RMETA */
    {MODIFIER_RCTRL, true},
    {NONE, false},
    {NONE, false},
    {NONE, false},
    {NONE, false}, /* Left over */
    {NONE, false}, /* Left over */
    {NONE, false}, /* Left over */
    {NONE, false}, /* Left over */
};

void matrix_init();
void matrix_scan();

#endif /* MATRIX_HPP */
