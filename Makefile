CC=gcc
CFLAGS=$(shell pkg-config --cflags gtk+-3.0)
CLIBS=$(shell pkg-config --libs gtk+-3.0)

all: main

main: main.c
	$(CC) -o main main.c $(CFLAGS) $(CLIBS)
	echo "Build Date: `date`" > data.conf

clean:
	rm -f main data.conf
