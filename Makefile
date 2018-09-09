.PHONY: all clean

all: example

example: ws281x.cpp example.cpp Makefile
	g++ ws281x.cpp example.cpp -o example -O3 -flto -g

clean:
	rm -vf example
