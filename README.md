# ws281x-spi-driver
A small C++ library to drive ws281x LEDs (aka "NeoPixels") via the SPI bus.  
It has next to no dependencies besides a proper a linux computer with an SPI bus supported by the running kernel (e.g. the Raspberry Pi).

## Cabling
Basically you just have to connect the SPI-MOSI PIN of your host to the input pin of your first LED.
All other pins are unused and can remain unconnected.
If you want to use the LED strip full-fledged SPI device and continue to use the SPI bus to drive other chips, youc an use a level-shifter with a chip-enable input like the "74AHCT1G125GW".
A level-shifter also has the advantage that you can drive the 5V LEDs from e.g. a 3.3V host like the Raspberry more reliably
Have a look here "https://easyeda.com/Neegu0Sh/neopixel-level-shifter" for how to wire everything up.

## Credits
This library was heavily inspired by Jeremy Garff (jgarff) library "rpi_ws281x". Have a look here "https://github.com/jgarff/rpi_ws281x". All creadits go to him for the idea to drive LEDs via PWM/SPI/etc.
