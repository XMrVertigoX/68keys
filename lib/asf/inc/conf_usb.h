#ifndef CONF_USB_H
#define CONF_USB_H

#include <compiler.h>
#include <udi_hid_kbd_conf.h>

// clang-format off

#define USB_DEVICE_ATTR          (USB_CONFIG_ATTR_BUS_POWERED)
#define USB_DEVICE_MAJOR_VERSION 0
#define USB_DEVICE_MINOR_VERSION 1
#define USB_DEVICE_POWER         500 // Consumption on Vbus line (mA)
#define USB_DEVICE_PRODUCT_ID    USB_PID_ATMEL_ASF_HIDKEYBOARD
#define USB_DEVICE_VENDOR_ID     USB_VID_ATMEL

// Optional
// #define USB_DEVICE_MANUFACTURE_NAME "Homebrew"
// #define USB_DEVICE_PRODUCT_NAME     "Magicforce 68"
// #define USB_DEVICE_SERIAL_NAME      "Homebrew Magicforce 68"

#define UDC_REMOTEWAKEUP_DISABLE()     udc_remotewakeup_disable()
#define UDC_REMOTEWAKEUP_ENABLE()      udc_remotewakeup_enable()
#define UDC_RESUME_EVENT()             udc_resume()
#define UDC_SOF_EVENT()                udc_start_of_frame()
#define UDC_SUSPEND_EVENT()            udc_suspend()
#define UDI_HID_KBD_CHANGE_LED(enable) udi_keyboard_led(enable)
#define UDI_HID_KBD_DISABLE_EXT()      udi_keyboard_disable()
#define UDI_HID_KBD_ENABLE_EXT()       udi_keyboard_enable()

// clang-format on

#endif // CONF_USB_H
