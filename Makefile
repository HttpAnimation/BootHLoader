CC=gcc
CFLAGS=$(shell pkg-config --cflags gtk+-3.0)
CLIBS=$(shell pkg-config --libs gtk+-3.0)
BUILD_DIR=$(shell date +%Y%m%d-%H%M%S)

all: main

main: main.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/main main.c $(CFLAGS) $(CLIBS)
	echo "Build Date: `date`" > $(BUILD_DIR)/data.conf

clean:
	rm -rf *-*/
