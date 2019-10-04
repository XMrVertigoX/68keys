#ifndef SCANCODES_HPP
#define SCANCODES_HPP

enum modifier : unsigned int {
	MODIFIER_LCTRL = (1 << 0),  // Left CTRL
	MODIFIER_LSHIFT = (1 << 1), // Left SHIFT
	MODIFIER_LALT = (1 << 2),   // Left ALT
	MODIFIER_LMETA = (1 << 3),  // Left GUI/META/SUPER
	MODIFIER_RCTRL = (1 << 4),  // Right CTRL
	MODIFIER_RSHIFT = (1 << 5), // Right SHIFT
	MODIFIER_RALT = (1 << 6),   // Right ALT
	MODIFIER_RMETA = (1 << 7)   // Right GUI/META/SUPER
};

enum keys : unsigned int {
	NONE = 0x00,                      // No key pressed
	ERROR_ROLL_OVER = 0x01,           // Error Roll Over
	ERROR_POST_FAIL = 0x02,           // Error POST Fail
	ERROR_UNDEFINED = 0x03,           // Error Undefined
	KEYBOARD_A = 0x04,                // Keyboard a and A
	KEYBOARD_B = 0x05,                // Keyboard b and B
	KEYBOARD_C = 0x06,                // Keyboard c and C
	KEYBOARD_D = 0x07,                // Keyboard d and D
	KEYBOARD_E = 0x08,                // Keyboard e and E
	KEYBOARD_F = 0x09,                // Keyboard f and F
	KEYBOARD_G = 0x0a,                // Keyboard g and G
	KEYBOARD_H = 0x0b,                // Keyboard h and H
	KEYBOARD_I = 0x0c,                // Keyboard i and I
	KEYBOARD_J = 0x0d,                // Keyboard j and J
	KEYBOARD_K = 0x0e,                // Keyboard k and K
	KEYBOARD_L = 0x0f,                // Keyboard l and L
	KEYBOARD_M = 0x10,                // Keyboard m and M
	KEYBOARD_N = 0x11,                // Keyboard n and N
	KEYBOARD_O = 0x12,                // Keyboard o and O
	KEYBOARD_P = 0x13,                // Keyboard p and P
	KEYBOARD_Q = 0x14,                // Keyboard q and Q
	KEYBOARD_R = 0x15,                // Keyboard r and R
	KEYBOARD_S = 0x16,                // Keyboard s and S
	KEYBOARD_T = 0x17,                // Keyboard t and T
	KEYBOARD_U = 0x18,                // Keyboard u and U
	KEYBOARD_V = 0x19,                // Keyboard v and V
	KEYBOARD_W = 0x1a,                // Keyboard w and W
	KEYBOARD_X = 0x1b,                // Keyboard x and X
	KEYBOARD_Y = 0x1c,                // Keyboard y and Y
	KEYBOARD_Z = 0x1d,                // Keyboard z and Z
	KEYBOARD_1 = 0x1e,                // Keyboard 1 and !
	KEYBOARD_2 = 0x1f,                // Keyboard 2 and @
	KEYBOARD_3 = 0x20,                // Keyboard 3 and #
	KEYBOARD_4 = 0x21,                // Keyboard 4 and $
	KEYBOARD_5 = 0x22,                // Keyboard 5 and %
	KEYBOARD_6 = 0x23,                // Keyboard 6 and ^
	KEYBOARD_7 = 0x24,                // Keyboard 7 and &
	KEYBOARD_8 = 0x25,                // Keyboard 8 and *
	KEYBOARD_9 = 0x26,                // Keyboard 9 and (
	KEYBOARD_0 = 0x27,                // Keyboard 0 and )
	KEYBOARD_ENTER = 0x28,            // Keyboard RETURN/ENTER
	KEYBOARD_ESC = 0x29,              // Keyboard ESCAPE
	KEYBOARD_BACKSPACE = 0x2a,        // Keyboard BACKSPACE
	KEYBOARD_TAB = 0x2b,              // Keyboard TAB
	KEYBOARD_SPACEBAR = 0x2c,         // Keyboard SPACEBAR
	KEYBOARD_MINUS = 0x2d,            // Keyboard - and _
	KEYBOARD_EQUAL = 0x2e,            // Keyboard = and +
	KEYBOARD_LEFTBRACE = 0x2f,        // Keyboard [ and {
	KEYBOARD_RIGHTBRACE = 0x30,       // Keyboard ] and }
	KEYBOARD_BACKSLASH = 0x31,        // Keyboard \ and |
	KEYBOARD_HASHTILDE = 0x32,        // Keyboard # and ~ (Non-US)
	KEYBOARD_SEMICOLON = 0x33,        // Keyboard ; and :
	KEYBOARD_APOSTROPHE = 0x34,       // Keyboard ' and "
	KEYBOARD_GRAVE = 0x35,            // Keyboard ` and ~
	KEYBOARD_COMMA = 0x36,            // Keyboard , and <
	KEYBOARD_DOT = 0x37,              // Keyboard . and >
	KEYBOARD_SLASH = 0x38,            // Keyboard / and ?
	KEYBOARD_CAPSLOCK = 0x39,         // Keyboard Caps Lock
	KEYBOARD_F1 = 0x3a,               // Keyboard F1
	KEYBOARD_F2 = 0x3b,               // Keyboard F2
	KEYBOARD_F3 = 0x3c,               // Keyboard F3
	KEYBOARD_F4 = 0x3d,               // Keyboard F4
	KEYBOARD_F5 = 0x3e,               // Keyboard F5
	KEYBOARD_F6 = 0x3f,               // Keyboard F6
	KEYBOARD_F7 = 0x40,               // Keyboard F7
	KEYBOARD_F8 = 0x41,               // Keyboard F8
	KEYBOARD_F9 = 0x42,               // Keyboard F9
	KEYBOARD_F10 = 0x43,              // Keyboard F10
	KEYBOARD_F11 = 0x44,              // Keyboard F11
	KEYBOARD_F12 = 0x45,              // Keyboard F12
	KEYBOARD_SYSRQ = 0x46,            // Keyboard Print Screen
	KEYBOARD_SCROLLLOCK = 0x47,       // Keyboard Scroll Lock
	KEYBOARD_PAUSE = 0x48,            // Keyboard Pause
	KEYBOARD_INSERT = 0x49,           // Keyboard Insert
	KEYBOARD_HOME = 0x4a,             // Keyboard Home
	KEYBOARD_PAGEUP = 0x4b,           // Keyboard Page Up
	KEYBOARD_DELETE = 0x4c,           // Keyboard DELETE
	KEYBOARD_END = 0x4d,              // Keyboard End
	KEYBOARD_PAGEDOWN = 0x4e,         // Keyboard Page Down
	KEYBOARD_RIGHT = 0x4f,            // Keyboard Right Arrow
	KEYBOARD_LEFT = 0x50,             // Keyboard Left Arrow
	KEYBOARD_DOWN = 0x51,             // Keyboard Down Arrow
	KEYBOARD_UP = 0x52,               // Keyboard Up Arrow
	KEYBOARD_NUMLOCK = 0x53,          // Keyboard Num Lock and Clear
	KEYPAD_SLASH = 0x54,              // Keypad /
	KEYPAD_ASTERISK = 0x55,           // Keypad *
	KEYPAD_MINUS = 0x56,              // Keypad -
	KEYPAD_PLUS = 0x57,               // Keypad +
	KEYPAD_ENTER = 0x58,              // Keypad ENTER
	KEYPAD_1 = 0x59,                  // Keypad 1 and End
	KEYPAD_2 = 0x5a,                  // Keypad 2 and Down Arrow
	KEYPAD_3 = 0x5b,                  // Keypad 3 and PageDn
	KEYPAD_4 = 0x5c,                  // Keypad 4 and Left Arrow
	KEYPAD_5 = 0x5d,                  // Keypad 5
	KEYPAD_6 = 0x5e,                  // Keypad 6 and Right Arrow
	KEYPAD_7 = 0x5f,                  // Keypad 7 and Home
	KEYPAD_8 = 0x60,                  // Keypad 8 and Up Arrow
	KEYPAD_9 = 0x61,                  // Keypad 9 and Page Up
	KEYPAD_0 = 0x62,                  // Keypad 0 and Insert
	KEYPAD_DOT = 0x63,                // Keypad . and Delete
	KEYBOARD_102ND = 0x64,            // Keyboard Non-US \ and |
	KEYBOARD_COMPOSE = 0x65,          // Keyboard Application
	KEYBOARD_POWER = 0x66,            // Keyboard Power
	KEYPAD_EQUAL = 0x67,              // Keypad =
	KEYBOARD_F13 = 0x68,              // Keyboard F13
	KEYBOARD_F14 = 0x69,              // Keyboard F14
	KEYBOARD_F15 = 0x6a,              // Keyboard F15
	KEYBOARD_F16 = 0x6b,              // Keyboard F16
	KEYBOARD_F17 = 0x6c,              // Keyboard F17
	KEYBOARD_F18 = 0x6d,              // Keyboard F18
	KEYBOARD_F19 = 0x6e,              // Keyboard F19
	KEYBOARD_F20 = 0x6f,              // Keyboard F20
	KEYBOARD_F21 = 0x70,              // Keyboard F21
	KEYBOARD_F22 = 0x71,              // Keyboard F22
	KEYBOARD_F23 = 0x72,              // Keyboard F23
	KEYBOARD_F24 = 0x73,              // Keyboard F24
	KEYBOARD_OPEN = 0x74,             // Keyboard Execute
	KEYBOARD_HELP = 0x75,             // Keyboard Help
	KEYBOARD_PROPS = 0x76,            // Keyboard Menu
	KEYBOARD_FRONT = 0x77,            // Keyboard Select
	KEYBOARD_STOP = 0x78,             // Keyboard Stop
	KEYBOARD_AGAIN = 0x79,            // Keyboard Again
	KEYBOARD_UNDO = 0x7a,             // Keyboard Undo
	KEYBOARD_CUT = 0x7b,              // Keyboard Cut
	KEYBOARD_COPY = 0x7c,             // Keyboard Copy
	KEYBOARD_PASTE = 0x7d,            // Keyboard Paste
	KEYBOARD_FIND = 0x7e,             // Keyboard Find
	KEYBOARD_MUTE = 0x7f,             // Keyboard Mute
	KEYBOARD_VOLUMEUP = 0x80,         // Keyboard Volume Up
	KEYBOARD_VOLUMEDOWN = 0x81,       // Keyboard Volume Down
	KEYPAD_CAPS_LOCK = 0x82,          // Keyboard Locking Caps Lock
	KEYPAD_NUM_LOCK = 0x83,           // Keyboard Locking Num Lock
	KEYPAD_SCROLL_LOCK = 0x84,        // Keyboard Locking Scroll Lock
	KEYPAD_COMMA = 0x85,              // Keypad ,
	KEYPAD_EQUAL_SIGN = 0x86,         // Keypad Equal Sign
	KEYBOARD_RO = 0x87,               // Keyboard International1
	KEYBOARD_KATAKANAHIRAGANA = 0x88, // Keyboard International2
	KEYBOARD_YEN = 0x89,              // Keyboard International3
	KEYBOARD_HENKAN = 0x8a,           // Keyboard International4
	KEYBOARD_MUHENKAN = 0x8b,         // Keyboard International5
	KEYBOARD_KPJPCOMMA = 0x8c,        // Keyboard International6
	KEYBOARD_INT7 = 0x8d,             // Keyboard International7
	KEYBOARD_INT8 = 0x8e,             // Keyboard International8
	KEYBOARD_INT9 = 0x8f,             // Keyboard International9
	KEYBOARD_HANGEUL = 0x90,          // Keyboard LANG1
	KEYBOARD_HANJA = 0x91,            // Keyboard LANG2
	KEYBOARD_KATAKANA = 0x92,         // Keyboard LANG3
	KEYBOARD_HIRAGANA = 0x93,         // Keyboard LANG4
	KEYBOARD_ZENKAKUHANKAKU = 0x94,   // Keyboard LANG5
	KEYBOARD_LANG6 = 0x95,            // Keyboard LANG6
	KEYBOARD_LANG7 = 0x96,            // Keyboard LANG7
	KEYBOARD_LANG8 = 0x97,            // Keyboard LANG8
	KEYBOARD_LANG9 = 0x98,            // Keyboard LANG9
	KEYBOARD_ALT_ERASE = 0x99,        // Keyboard Alternate Erase
	KEYBOARD_SYSREQ_ATTENTION = 0x9a, // Keyboard SysReq/Attention
	KEYBOARD_CANCEL = 0x9b,           // Keyboard Cancel
	KEYBOARD_CLEAR = 0x9c,            // Keyboard Clear
	KEYBOARD_PRIOR = 0x9d,            // Keyboard Prior
	KEYBOARD_RETURN = 0x9e,           // Keyboard Return
	KEYBOARD_SEPARATOR = 0x9f,        // Keyboard Separator
	KEYBOARD_OUT = 0xa0,              // Keyboard Out
	KEYBOARD_OPER = 0xa1,             // Keyboard Oper
	KEYBOARD_CLEAR_AGAIN = 0xa2,      // Keyboard Clear/Again
	KEYBOARD_CRSEL_PROPS = 0xa3,      // Keyboard CrSel/Props
	KEYBOARD_EXSEL = 0xa4,            // Keyboard ExSel
	// 0xa5
	// 0xa6
	// 0xa7
	// 0xa8
	// 0xa9
	// 0xaa
	// 0xab
	// 0xac
	// 0xad
	// 0xae
	// 0xaf
	KEYPAD_00 = 0xb0,                  // Keypad 00
	KEYPAD_000 = 0xb1,                 // Keypad 000
	KEYPAD_THAUSANDS_SEPARATOR = 0xb2, // Thousands Separator
	KEYPAD_DECIMAL_SEPARATOR = 0xb3,   // Decimal Separator
	KEYPAD_CURRENCY_UNIT = 0xb4,       // Currency Unit
	KEYPAD_CURRENCY_SUB_UNIT = 0xb5,   // Currency Sub-unit
	KEYPAD_LEFTPAREN = 0xb6,           // Keypad (
	KEYPAD_RIGHTPAREN = 0xb7,          // Keypad )
	KEYPAD_LEFTBRACE = 0xb8,           // Keypad {
	KEYPAD_RIGHTBRACE = 0xb9,          // Keypad }
	KEYPAD_TAB = 0xba,                 // Keypad Tab
	KEYPAD_BACKSPACE = 0xbb,           // Keypad Backspace
	KEYPAD_A = 0xbc,                   // Keypad A
	KEYPAD_B = 0xbd,                   // Keypad B
	KEYPAD_C = 0xbe,                   // Keypad C
	KEYPAD_D = 0xbf,                   // Keypad D
	KEYPAD_E = 0xc0,                   // Keypad E
	KEYPAD_F = 0xc1,                   // Keypad F
	                                   // 0xc2 // Keypad XOR
	                                   // 0xc3 // Keypad ^
	                                   // 0xc4 // Keypad %
	                                   // 0xc5 // Keypad <
	                                   // 0xc6 // Keypad >
	                                   // 0xc7 // Keypad &
	                                   // 0xc8 // Keypad &&
	                                   // 0xc9 // Keypad |
	                                   // 0xca // Keypad ||
	                                   // 0xcb // Keypad :
	                                   // 0xcc // Keypad #
	                                   // 0xcd // Keypad Space
	                                   // 0xce // Keypad @
	                                   // 0xcf // Keypad !
	                                   // 0xd0 // Keypad Memory Store
	                                   // 0xd1 // Keypad Memory Recall
	                                   // 0xd2 // Keypad Memory Clear
	                                   // 0xd3 // Keypad Memory Add
	                                   // 0xd4 // Keypad Memory Subtract
	                                   // 0xd5 // Keypad Memory Multiply
	                                   // 0xd6 // Keypad Memory Divide
	                                   // 0xd7 // Keypad +/-
	                                   // 0xd8 // Keypad Clear
	                                   // 0xd9 // Keypad Clear Entry
	                                   // 0xda // Keypad Binary
	                                   // 0xdb // Keypad Octal
	                                   // 0xdc // Keypad Decimal
	                                   // 0xdd // Keypad Hexadecimal
	                                   // 0xde
	                                   // 0xdf
	KEYBOARD_LEFTCTRL = 0xe0,          // Keyboard Left CTRL
	KEYBOARD_LEFTSHIFT = 0xe1,         // Keyboard Left SHIFT
	KEYBOARD_LEFTALT = 0xe2,           // Keyboard Left ALT
	KEYBOARD_LEFTMETA = 0xe3,          // Keyboard Left META/SUPER
	KEYBOARD_RIGHTCTRL = 0xe4,         // Keyboard Right CTRL
	KEYBOARD_RIGHTSHIFT = 0xe5,        // Keyboard Right SHIFT
	KEYBOARD_RIGHTALT = 0xe6,          // Keyboard Right ALT
	KEYBOARD_RIGHTMETA = 0xe7,         // Keyboard Right META/SUPER
	MEDIA_PLAYPAUSE = 0xe8,
	MEDIA_STOPCD = 0xe9,
	MEDIA_PREVIOUSSONG = 0xea,
	MEDIA_NEXTSONG = 0xeb,
	MEDIA_EJECTCD = 0xec,
	MEDIA_VOLUMEUP = 0xed,
	MEDIA_VOLUMEDOWN = 0xee,
	MEDIA_MUTE = 0xef,
	MEDIA_WWW = 0xf0,
	MEDIA_BACK = 0xf1,
	MEDIA_FORWARD = 0xf2,
	MEDIA_STOP = 0xf3,
	MEDIA_FIND = 0xf4,
	MEDIA_SCROLLUP = 0xf5,
	MEDIA_SCROLLDOWN = 0xf6,
	MEDIA_EDIT = 0xf7,
	MEDIA_SLEEP = 0xf8,
	MEDIA_COFFEE = 0xf9,
	MEDIA_REFRESH = 0xfa,
	MEDIA_CALC = 0xfb,
	// 0xfc
	// 0xfd
	// 0xfe
	// 0xff
};

#endif // SCANCODES_HPP
