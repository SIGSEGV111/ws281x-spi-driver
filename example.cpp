#include "ws281x.hpp"

using namespace ws281x;

int main()
{
	// a small example

	// attach an instance of the SPI-driver to the first SPI device on the first bus (0.0)
	// set the transfer speed to 800000*4 Hz (required to drive NeoPixels)
	TSPIDriver spi_dev_1("/dev/spidev0.0", 800000*4);

	// our LED strip will have 64 LEDs
	const unsigned n_pixels = 64;
	TWS2812B arr_pixels[n_pixels];

	// and we want them to light up yellow [255,255,0] (red, green, blue)
	for(unsigned i = 0; i < n_pixels; i++)
		arr_pixels[i].RGB(255,255,0);

	// now we send the data to the LEDs:
	spi_dev_1.SendData(arr_pixels, sizeof(arr_pixels));

	// c++ destructors will take care of proper shutdown and release of resources...
	return 0;
}
