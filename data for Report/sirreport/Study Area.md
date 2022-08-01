# Study Area

## Servo Motors

Servo motors are geared DC motors that have an integrated servomechanism with a feedback loop to allow precise positioning of the motor shaft. A high gear ratio allows a small servo to have an impressive torque rating. Most servos are limited in rotation to either 180 or 270 degrees, with 180-degree servo motors being more common.   There are specially modified servo motors that can rotate beyond 360-degrees.

Servo motors come in a wide range of sizes and can be controlled either with an analog PWM signal or with a digital I/O signal

### Servo Motor Connections
Most analog servo motors like the MG90 use a 3-wire color-coded cable for interfacing. Although the color-coding is not an official standard many manufacturers use the same colored wires:

Orange – The PWM servo control input. This is a logic-level signal, and most servo motors can accept 3.3-volt logic as well as 5-volt logic.  Some models, especially 270-degree rotation servos,  use a White wire for this connection.
Red – The servo motor power supply input. Generally 5-6 volts DC, but be sure to check first.
Brown – The ground connection. On some servo motors, this is a Black wire.

### Servo Positioning
Analog servo motors use PWM, or Pulse Width Modulation, to control the motor shaft position. 

The PWM signal is usually about 50Hz, which is a period of 20ms. Within that period the pulse width is varied, a shorter pulse positions the servo towards the zero-degree mark while a longer one moves the motor shaft towards the 180 (or 270) degree position.

The pulse is continually applied to the control lead on the motor, locking the shaft into the desired position.

## ESP32 microcontroller

![alt](https://asset.conrad.com/media10/isa/160267/c1/-/en/1656367_LB_00_FB/image.jpg)

The ESP32 is actually a series of microcontroller chips produced by Espressif Systems in Shanghai.  It is available in a number of low-cost modules

### features of the ESP32

* 16 PWM outputs independently (pulse width modulation).
* WiFi 
* offers both Bluetooth and BLE (Bluetooth Low Energy)
* operating in an ultra-low-power mode
* Up to 18 12-bit Analog to Digital converters.
* Two 8-bit Digital to Analog converters.
* 10 capacitive touch switch sensors.
* Four SPI channels.
* Two I2C interfaces.
* Two I2S interfaces (for digital audio).
* Three UARTs for communications.
* Up to 8 channels of IR remote control.
* An integrated Hall-effect sensor.
* An ultra-low-power analog preamp.
* An internal low-dropout regulator.

### Programming the ESP32

The ESP32 can be programmed using many different development environments.  Code can be written in C++ (like the Arduino) or in MicroPython


Note:To make use of all of the ESP32 features Espressif provided the Espressif IoT Development Framework, or ESP-IDF



## Buck converter

![alt](https://cdn11.bigcommerce.com/s-yo2n39m6g3/images/stencil/1280x1280/products/466/3407/lm2596-dc-dc-buck-converter__03171.1571733582.jpg?c=2?imbypass=on)

LM2596 is a step-down voltage regulator, also known as buck convertor, mainly used to step down the voltage or to drive load under 3A. It carries the remarkable load and line regulation and is available in fixed output voltages including 3.3V, 5V, 12V. It also comes with a customized output version where you can set the output voltage as per your requirement.

### SPECIFICATIONS we need

* Adjustable output voltage
* Input Voltage	:3-20V
* Output Voltage Range	1.23-15V
* MaOutput Current	3 A

## Power supply(60W) 
input: 240V 1.6A
output: 12V 5A  