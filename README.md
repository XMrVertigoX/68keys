# Custom Magicforce 68 Keyboard

## Requirements

- cmake/ninja
- `arm-none-eabi-*` toolchain available through $PATH variable

## Build

### Build with ninja

```bash
mkdir build && cd build
cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi.cmake ..
ninja uf2
```

### Build with make

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi.cmake ..
make uf2
```

## Install binary

Bootloader: [adafruit/uf2-samdx1](https://github.com/adafruit/uf2-samdx1)

- Double tap reset (within 500 ms) - The bootloader opens a usb drive
- Copy the newly generated `mf68.uf2` onto the drive
- Within one seconde the device should be operational again
