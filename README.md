# erasLEDjacket - extending the reach of your Pixmob wristband

This project allows you to read the color from a pixmob LED wristband (or any other, really) and replicate it to a set of WS2812 LEDs integrated into a jacket. The project uses an Arduino Nano, an ADS1115 analog-to-digital converter, and WS2812 LED strips.

## Table of Contents

- [Introduction](#introduction)
- [Components](#components)
- [Schematics](#schematics)
- [Installation](#installation)
- [Usage](#usage)
- [Calibration](#calibration)
- [Credits](#credits)

## Introduction

Hello, I'm Thorben. I'm a Swifty, and I made a special outfit for the Eras Tour. Inspired by a [Reddit post](https://www.reddit.com/r/TaylorSwift/comments/13e9qdt/i_hacked_the_led_wristbands_at_the_nashville_eras/), I created a jacket that mirrors the colors of the wristbands used in the show. This project reads the color from an LED wristband and replicates it on a WS2812 LED strip integrated into a jacket.

## Components

- **Arduino Nano**: The microcontroller used to read the voltages and control the LEDs.
- **ADS1115**: A precision analog-to-digital converter to read the voltages from the wristband LEDs.
- **WS2812 LED Strip**: The LED strip used to replicate the wristband colors.
- **Connecting Wires**: For making connections between the components.
- **Power Supply**: To power the Arduino Nano and the LED strip.

## Schematics

Please refer to the `schematics.png` file in this repository for a detailed wiring diagram.

## Installation

Follow these steps to set up the project on your Arduino Nano:

1. **Install Arduino IDE**: Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Install Required Libraries**: Open the Arduino IDE and install the following libraries:
   - `Adafruit_ADS1X15`
   - `FastLED`

   You can install these libraries by going to `Sketch` > `Include Library` > `Manage Libraries...`, and then searching for and installing each library.

3. **Clone this Repository**: Clone this repository to your local machine using:
   ```bash
   git clone https://github.com/thorbengrosser/erasLEDjacket.git
   ```

4. **Upload the Code**: Open the `erasledjacket.cpp` file in the Arduino IDE. Connect your Arduino Nano to your computer and upload the code by clicking the upload button in the Arduino IDE.

## Usage

1. **Connect the Components**: Follow the schematic to connect the ADS1115 to the Arduino Nano and the LED strip. Ensure that the connections are secure.

2. **Power the System**: Connect the power supply to the Arduino Nano and the LED strip.

3. **Run the System**: Once powered, the Arduino Nano will read the colors from the wristband and replicate them on the LED strip.

## Calibration

The voltage readings and mappings may vary slightly based on your setup. Follow these steps to calibrate the system:

1. **Read ADC Values**: Use a Flipper or another infrared sender to emulate the wristband signals and read the ADC values using the Arduino Serial Monitor.

2. **Adjust Mapping**: Modify the mapping in the code based on your readings. The code currently maps ADC values to RGB values based on specific thresholds. Adjust these thresholds to match your setup.

3. **Test and Iterate**: Test the setup by flashing different colors on the wristband and observing the LED strip. Adjust the mappings as needed to achieve accurate color reproduction.

## Credits
- gnewjay on reddit, who inspired me with [this post](https://www.reddit.com/r/TaylorSwift/comments/13e9qdt/i_hacked_the_led_wristbands_at_the_nashville_eras/)
- [Daniel Weideman](https://github.com/danielweidman/pixmob-ir-reverse-engineering), who is doing amazing work on reverse engineering the bracelet. Way too complex for me :)
 
If you see me at the Hamburg tour, come by and swap friendship bracelets! Thank you for checking out this project. Feel free to contribute or suggest improvements.
