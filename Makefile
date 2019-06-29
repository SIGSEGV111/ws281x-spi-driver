.PHONY: all clean run check

all: simple firefly-ring random-ring off

off: ws281x.cpp off.cpp
	g++ -O3 -flto -fwhole-program -Wall -Wextra -g ws281x.cpp off.cpp -o off

simple: ws281x.cpp simple.cpp
	g++ -O3 -flto -fwhole-program -Wall -Wextra -g ws281x.cpp simple.cpp -o simple

firefly-ring: ws281x.cpp firefly-ring.cpp
	g++ -O3 -flto -fwhole-program -Wall -Wextra -g ws281x.cpp firefly-ring.cpp -o firefly-ring

random-ring: ws281x.cpp random-ring.cpp
	g++ -O3 -flto -fwhole-program -Wall -Wextra -g ws281x.cpp random-ring.cpp -o random-ring

clean:
	rm -vf simple firefly-ring random-ring off
