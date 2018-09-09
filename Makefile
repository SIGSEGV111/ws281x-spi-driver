.PHONY: all clean

all: example

example: ws281x.cpp Makefile
	g++ ws281x.cpp -o example -O3 -Os -fwhole-program -flto
	strip example

clean:
	rm -vf example
