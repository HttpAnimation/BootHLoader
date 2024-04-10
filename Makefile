CC=gcc
CFLAGS=`pkg-config --cflags gtk+-3.0`
CLIBS=`pkg-config --libs gtk+-3.0`

all: main

main: main.c
    $(CC) -o main main.c $(CFLAGS) $(CLIBS)

clean:
    rm -f main
