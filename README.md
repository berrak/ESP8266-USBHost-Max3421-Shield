![esp8266-usbhost-shield](./images/3d-view-max3421e-esp8266-shield-v1_0.png)

[![GitHub version](https://img.shields.io/github/release/berrak/ESP8266-USBHost-Max3421-Shield.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/ESP8266-USBHost-Max3421-Shield/releases/latest)
[![GitHub Release Date](https://img.shields.io/github/release-date/berrak/ESP8266-USBHost-Max3421-Shield.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/ESP8266-USBHost-Max3421-Shield/releases/latest)
[![GitHub stars](https://img.shields.io/github/stars/berrak/ESP8266-USBHost-Max3421-Shield.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/ESP8266-USBHost-Max3421-Shield/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/berrak/ESP8266-USBHost-Max3421-Shield.svg?logo=github&logoColor=ffffff)](https://github.com/berrak/ESP8266-USBHost-Max3421-Shield/issues)
![Badge Hit Counter](https://visitor-badge.laobi.icu/badge?page_id=berrak_ESP8266-USBHost-Max3421-Shield)

# The ESP8266 USB Host Shield

The `ESP8266 USB Host Shield` contains all the digital logic necessary to implement a full-speed USB 2.0 host controller with your ESP8266 microcontroller. There is no need to spend hours writing complicated code to decode various USB descriptors. Instead, the [USB Host Shield library 2.0](https://github.com/felis/USB_Host_Shield_2.0/) does all the heavy lifting for you with the capabilities of the ESP8266, and maybe you may create a new game, control robots or implement DIY intelligent home automation with an old unused controller laying around.

## Client Device Control Using UDP from the USB Host Device

![esp8266-usbhost-shield](./images/client-control-using-udp.png)

Add USB host capabilities with the `ESP8266 USB Host Shield` and control network devices wireless with standard USB HID devices like a keyboard, mouse, and game controller. Adding the shield board on top of the `ESP8266 D1-mini` will let you control other WiFi devices wireless without being forced to dedicate an entire computer for such tasks.

Install the Arduino library in the IDE; within minutes, the library recognizes your HID device. Then, use the host shield and, for example, a `gaming joystick` to interface with and remotely control any microcontroller-based device with WiFi. It is indeed a plug-and-play solution.

## Board main features

The host controller MAX4321E chip uses a four-wire serial interface to communicate with ESP8266. A USB type A female connector supplies 5V as any regular USB port would do. The SPI of 26MHz is fast; forget any sluggish UART communication.

- The shield supplies any attached devices with +5V (VBUS) via the connected ESP8266 USB connector.
- With the ESP8266 USB host shield, there is no risk of wiring it up incorrectly.
- This device comes fully assembled, and there is no need to program the shield itself.
- SPI bus voltage levels are 3.3V, thus compatible with modern microcontrollers.
- The host complies with USB Specification Revision 2.0, i.e., full-/low-Speed 12Mbps/1.5Mbps USB communication.
- The ESP8266 board power the shield and the MAX3421E with 3.3V.

The additional unnecessary built-in GPIO pins from MAX3421E are not connected, and some other signals with the limited availability of pins on the ESP8266 D1-mini. See the `schematic` for all details. 

## Planned Improvements/Changes
The Arduino host shield library is for the `Arduino Host shield` implementation with `MAX3421E`. However, we have found that USB devices are generally recognized with the `ESP8266 USB Host Shield` since it also uses the `MAX3421E`. For planned changes, improvements, and possible encountered issues, please visit the [Github issues tracker](https://github.com/berrak/ESP8266-USBHost-Max3421-Shield/issues).

## Suggested items to add to the board

- Wemos/Lolin ESP8266 D1-mini microcontroller.
- Female headers for ESP8266 D1-mini.
- HID devices such as keyboards, mice, gaming joysticks, etc.

Various sellers sell ESP8266 cloned boards on `AliExpress` and `Amazon`. Alternatively, buy the original version of ESP8266 D1-mini at [Lolin](https://lolin.aliexpress.com/store/1331105) official shop.

## Usage

![esp8266-usbhost-shield](./images/ESP8266-usbhost-shield-on-breadboard.jpg)

Add the shield board on top of the ESP8266 D1-mini such that both USB connectors are above each other. 

- Confirm that the shield cut-out is above the ESP8266 `RESET button` before connecting power! 

Please, see the [Arduino library installation documentation](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries), and how-to install the Arduino library [USB Host Shield 2.0](https://github.com/felis/USB_Host_Shield_2.0/).

Verify that the USB host shield library can use the device with the Arduino sketch `USBHID_desc`, found among the many examples.

![esp8266-usbhost-shield](./images/ESP8266-client.png)

To remotely control ESP8266 with UDP broadcasts, see the example `ESP8266RemoteWiFiClientServer` for a start. Furthermore, you can get confirmation of the actions from [Packet Sender](https://packetsender.com). There is no need to create web interfaces or any other complex cloud solution if your goal is to control devices in your home and within WiFi reach. Instead, a minimal number of lines of code is required to accomplish that task.

![packet sender](./images/packetsender-log.png)

## Specification for the `ESP8266 USB Host Shield v1.0`

* Operating voltage: 3.3V - (via ESP8266)
* The shield size is 26.5 x 31.5 mm (1.04" x 1.24") and fabricated as a `four-layer board for superior signal integrity`.
* Board thickness: 1.6 mm (63 mils).
* Formfactor and pinout: Wemos/Lolin ESP8266 D1-mini.
* Weight: 6 gram (0.21 ounce).
* Height: 17.5 mm (0.69")

## Purchase the board

The `ESP8266 USB Host Shield` board is available only fully assembled. [Tindie](https://www.tindie.com/products/28192/) has all the latest designed boards.

[![Tindie](./images/tindie-small.png)](https://www.tindie.com/products/28192/)

I appreciate your support.

## Credits

`Router` image by [Freepik](https://www.freepik.com/free-psd/3d-rendering-graphic-design-element_26433059.htm#query=wifi&position=16&from_view=search&track=sph) by Freepik. `Keyboard` image by [rawpixel.com](https://www.freepik.com/free-vector/illustration-computer-keyboard_2606087.htm#query=computer%20keyboard&position=0&from_view=search&track=sph) on Freepik.
