# Esp-Radio

An ESP32 FM radio experiment built on the **TEA5767** FM receiver module. The sketch tunes the module to a fixed frequency over I²C and prints the station information to the serial monitor.

> **Status:** early prototype. The sketch tunes once at startup and then does nothing; there are no buttons, display or audio handling yet.

## What the sketch does

On startup, [`Radio/Radio.ino`](Radio/Radio.ino):

1. Starts the serial port at **115200** baud and the I²C bus (`Wire.begin()`).
2. Tunes the TEA5767 to **91.8 MHz**.
3. Prints three lines to the serial monitor:
   * `Frequency:` the configured frequency, with two decimals (for example `91.80`)
   * `Stereo:` `1` if the station is received in stereo, `0` for mono
   * `Signal (0-15):` the signal level reported by the module

The `loop()` function is empty.

## Hardware

* An ESP32 development board.
* A TEA5767 FM radio module, connected over I²C: SDA and SCL to the ESP32's default I²C pins (GPIO 21 = SDA and GPIO 22 = SCL on classic ESP32 boards such as the DevKitC / WROOM-32), plus power and ground. The library author recommends powering the module from 5 V; 3.3 V can cause errors such as frequency shift.
* An antenna, and headphones or an amplifier on the module's audio output.

## Software

* [Arduino IDE](https://www.arduino.cc/en/software) or another Arduino-compatible toolchain, with ESP32 board support installed.
* The [big12boy/TEA5767](https://github.com/big12boy/TEA5767) library. It is not in the Arduino Library Manager: download it as a ZIP and add it with **Sketch → Include Library → Add .ZIP Library**. The Library Manager entry named "TEA5767" is a different library with the same header name and an incompatible API, so the sketch will not compile with it.

## Usage

1. Open `Radio/Radio.ino`.
2. Change `frequency` to a station you can receive, and `baud` if you want a different serial speed.
3. Select your ESP32 board and port, then upload.
4. Open the serial monitor at 115200 baud to see the frequency, stereo flag and signal level.

## Credits

The sketch is based on the `ReadStats` example from [big12boy/TEA5767](https://github.com/big12boy/TEA5767).

## License

[Apache License 2.0](LICENSE)
