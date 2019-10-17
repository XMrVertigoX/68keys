# Custom Magicforce 68 Keyboard

## Requirements

- `arm-none-eabi-*` toolchain available through $PATH variable

## Build

### Build with make

```bash
mkdir build
cd build
cmake ..
make
```

## Install binary

Bootloader: [adafruit/uf2-samdx1](https://github.com/adafruit/uf2-samdx1)

- Double tap reset (within 500 ms) - The bootloader opens a usb drive
- Copy the newly generated `mf68.uf2` onto the drive
- Within one seconde the device should be operational again
