#pragma once

#include "ws281x.hpp"
#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace ws281x
{
	static void RunRing(const TWS2812B* const arr, const unsigned n_pixels, const unsigned delay)
	{
		// attach an instance of the SPI-driver to the first SPI device on the first bus (0.0)
		// set the transfer speed to 800000*4 Hz (required to drive NeoPixels)
		TSPIDriver spi_dev_1("/dev/spidev0.0", 800000*4);

		unsigned i = 0;
		for(;;)
		{
			spi_dev_1.SendData(arr + i, sizeof(TWS2812B) * n_pixels);
			usleep(delay);

			i++;
			if(i >= n_pixels)
				i = 0;
		}
	}
}
