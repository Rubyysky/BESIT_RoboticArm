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


To make use of all of the ESP32 features Espressif provided the Espressif IoT Development Framework, or ESP-IDF



## Power


Electronic devices like ESP32’s require “logic level” voltages to function. These “logic level” voltages come in two flavors – the traditional 5 volts DC that is also known as “TTL level” voltage and the power-saving 3.3 volt DC supply that is used in many low-powered devices. In both cases the voltages need to be regulated fairly precisely to avoid damaging components

### Voltage Requirements

There are several standard voltage levels that our robot might require 

1. 3.3 Volts DC – This is a common voltage used in low-powered digital devices
2. 5 Volts DC – This is the standard TTL (Transistor Transistor Logic) voltage used by digital devices
3. 6-8 Volts DC – Often used for DC and servo motors.
4. 12 Volts DC – Also used with DC motors as well as many stepper motors
5. 48 Volts DC – Used in professional audio gear as a “phantom supply” for microphones

### Voltage Regulation
Logic level voltages need to be very precisely regulated. For example for TTL logic to function correctly the supply voltage needs to be between 4.75 and 5.25 volts, any lower will cause the logic components to stop working correctly and any higher can literally destroy them.

other supply voltage requirements are less stringent. Power supplied to motors, LEDS.
Voltage regulation for line powered devices is not that difficult as the input voltage to the regulator circuitry is fairly constant. However battery powered designs provide a much greater challenge as battery voltage levels will fluctuate as the battery discharges.  

Devices that can be powered by both line voltages and batteries often have additional circuitry for charging the batteries when the device is being line powered. Depending upon the battery technology employed in the design this can range from a simple to very complex charging circuit.

### Current Requirements

The power supply voltage level is not the only specification that must be taken into account when designing a power supply for your project.  Just as important is to determine the current requirements of the project.

Unlike voltage requirements the current that a project consumes is not always a static value.  Motors, LED and other displays, speakers and other transducers can cause the current draw to fluctuate and you need to design your power supply to accommodate the “worst case” situation where every motor, indicator and sounder is being operated at full capacity.

### Efficiency
Another important aspect of voltage regulator design is efficiency. The regulator or voltage convertor itself will consume some electricity that could otherwise have been used to power up your project.

Efficiency goes hand in hand with heat production, an inefficient regulator design will dissipate its excess energy as heat. Unless you’re deliberately trying to heat up your circuitry this is not a good thing!  Heat is one of the greatest enemies of electronic components and if your regulator gives off a lot of heat you’ll need to workout ventilation and perhaps heat sinking into your design.

No design is 100% efficient so some heat production is to be expected. By overrating the components in your design you can keep this minimized.

## Power Supply Basics
The function of a power supply is, of course, to supply power at the correct voltage and current levels to meet the requirements of your project. The energy to run the power supply can come from a number of sources – batteries, solar cells, AC power and others.

The voltages we need for our little robotic arm is DC or Direct Current.
# AC-DC

As our robot require DC current at much lower voltages you’ll need to do two things before you can employ the power from your wall outlet:

1. Reduce the voltage to a lower level.
2. Convert it from AC to DC.
   
In a conventional linear power supply the AC voltage is first passed through a transformer which lowers it substantially, it is then converted to DC.

In a modern switching power supply (like the one in your desktop computer) AC voltage is directly converted to high-voltage DC and this is used to drive a high-frequency oscillator. The high-frequency AC produced by this oscillator is then passed through a small transformer and the low voltage output from that is converted to DC.

Either way at one point we need to convert the AC into DC. 

### Switching power supply (60W) 

input: 240V 1.6A
output: 12V 5A  

### Regulators and Converters

Regardless as to whether your DC voltage was derived from AC or whether it is from a battery chances are that it won’t be the correct voltage for your application.  You’ll need to change the voltage to the desired level (i.e. 5 volts and 7volts) and you need to ensure it stays at that level even if the input voltage changes.

We can do this a few ways using either regulators or convertors.


### Buck converter

Buck work using something called a “flywheel circuit”.  In operation a transistor is switched on and off and its output is fed through an inductor (coil) and then to a capacitor.  As the transistor is switched on and off the capacitor charges and discharges the energy that is stored in the coil. The period or frequency that the switching occurs at determines the output voltage. buck converter is used in situations where the desired output voltage is lower than the input voltage.

![alt](https://cdn11.bigcommerce.com/s-yo2n39m6g3/images/stencil/1280x1280/products/466/3407/lm2596-dc-dc-buck-converter__03171.1571733582.jpg?c=2?imbypass=on)

## LM2596 
is a step-down voltage regulator, also known as buck convertor, mainly used to step down the voltage or to drive load under 3A. It carries the remarkable load and line regulation and is available in fixed output voltages including 3.3V, 5V, 12V. It also comes with a customized output version where you can set the output voltage as per your requirement.

#### SPECIFICATIONS

* Adjustable output voltage
* Input Voltage	:3-20V
* Output Voltage Range	1.23-15V
* Output current:Rated current is 2A,maximum 3A(Additional heatsink is required)