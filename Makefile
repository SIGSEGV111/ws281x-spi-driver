.PHONY: all clean run check

all: example

check:  ws281x.cpp example.cpp Makefile
	g++ ws281x.cpp example.cpp -o example -O3 -flto -g -Wall -Wextra -Werror

example: ws281x.cpp example.cpp Makefile
	g++ ws281x.cpp example.cpp -o example -O3 -flto -g

run: example
	./example

clean:
	rm -vf example
