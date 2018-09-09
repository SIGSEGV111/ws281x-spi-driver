#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "ws281x.hpp"

#define SYSERR(expr) do { if((long)(expr) == -1L) { perror(#expr); exit(1); } } while(false)

using namespace ws281x;

int main()
{
	int fd_spi;
	SYSERR(fd_spi = open("/dev/spidev0.0", O_RDWR | O_CLOEXEC | O_NOCTTY));

	const unsigned n_pixels = 52;
	TWS2812B arr_pixels[n_pixels];

	for(unsigned i = 0; i < n_pixels; i++)
		arr_pixels[i].RGB(0,0,0);

	TBar arr_bar[4] = {TBar(arr_pixels,0,11),TBar(arr_pixels,11,15),TBar(arr_pixels,26,11),TBar(arr_pixels,37,15)};

	arr_bar[0].Set(31,31, 0);	// left side
	arr_bar[1].Set(15,15,15);	// behind camera
	arr_bar[2].Set( 0,31,31);	// right side
	arr_bar[3].Set(31, 0,31);	// rear side

	struct spi_ioc_transfer xfer_cmd = {};
	xfer_cmd.tx_buf = (uint64_t)arr_pixels;
	xfer_cmd.len = sizeof(arr_pixels);
	xfer_cmd.delay_usecs = 0;
	xfer_cmd.speed_hz = 800000*4;
	xfer_cmd.bits_per_word = 8;

	SYSERR(ioctl(fd_spi, SPI_IOC_MESSAGE(1), &xfer_cmd));

	SYSERR(close(fd_spi));

	return 0;
}
