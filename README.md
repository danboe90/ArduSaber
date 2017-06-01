# ArduSaber
This Readme is still under work, but will cover the following things:
- used hardware
- pinning of the hardware
- documentation of the software modules


## Used Hardware
- MPU6050 for swing and clash detection
- DFPlayer Mini for sound output
- SPI SD Card Adapter as alternative to DFPlayer Mini
- Arduino Nano
- 3W Single color LED (2.3V/700mAh)
- DCDC XL6009E1 Boost Converter
- ThorFire 3.7V BRC 18650 3000mAh LI-ion
- BC446B NPN Transistor
- BUK453 PowerMOS
- 1 kOhm Resistor
- 100 Ohm Resistor
- 2k7 Ohm Resistor

The hardware will be placed onto a designed PCB after prototyping.

## Pinning

 -------------------------------------------------------------------------
 |    ARDUINO PIN        |       PIN         |       HARDWARE            |
 -------------------------------------------------------------------------
 |         D2            |       /\/         |       /\/                 |
 |         D3            |       pB1         |       PushButton          |
 |         D4            |       CS          |       SD-Card Adapter     |
 |         D5            |       G           |       BUK453              |
 |         D6            |       /\/         |       /\/                 |
 |         D7            |       /\/         |       /\/                 |
 |         D8            |       /\/         |       /\/                 |
 |         D9            |       R1          |       In to 2k7 resistor  |
 |         D10           |       /\/         |       /\/                 |
 |         D11           |       MOSI        |       SD-Card Adapter     |
 |         D12           |       MISO        |       SD-Card Adapter     |
 |         D13           |       SCK         |       SD-Card Adapter     |
 -------------------------------------------------------------------------
 |         A0            |       /\/         |       /\/                 |
 |         A1            |       /\/         |       /\/                 |
 |         A2            |       /\/         |       /\/                 |
 |         A3            |       /\/         |       /\/                 |
 |         A4            |       SDA         |       MPU6050             |
 |         A5            |       SCL         |       MPU6050             |
 |         A6            |       /\/         |       /\/                 |
 |         A7            |       /\/         |       /\/                 |
 -------------------------------------------------------------------------
 |         RST           |       /\/         |       /\/                 |
 -------------------------------------------------------------------------
 |         +5V           |       VCC         |       MPU6050             |
 |                       |       VCC         |       SD-Card Adapter     |
 -------------------------------------------------------------------------
 |         GND           |       GND         |       MPU6050             |
 |                       |       GND         |       SD-Card Adapter     |
 |                       |       pB2         |       PushButton          |
 -------------------------------------------------------------------------