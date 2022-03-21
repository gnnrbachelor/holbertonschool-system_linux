CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

all: hnm hobjdump

hnm: 0-readelf.c
	$(CC) $(CFLAGS) 0-readelf.c -o hnm
hobjdump: 1-readelf.c
	$(CC) $(CFLAGS) 1-readelf.c -o hobjdump
