# Arduino-DataWriteRead
This program will read and write the data to/from SD card

# Hardware Setup
SD card attached to SPI bus as follows:
3V3  - 5V  - Black     (3V3 to 5V connection)
CS   - 49  - Yellow    (pin 49 is selected as chip select - can be used any other pin)
MOSI - 51  - Green     (pin 51 belongs  to SPI- master out slave in)
CLK  - 52  - Blue      (pin 50 belongs to SPI - Clock)
MISO - 50  - Red       (pin 50 belongs to SPI - master in slave out) 
GND  - GND - Off-white (GND)

# Installation
include <SPI.h> // SPI library added for SD-card communication protocol
include <SD.h>  // SD library added for SD-card feature
include <Wire.h> // supports wiring

# Build and Compile
Connect arduino to PC, then compile the project
