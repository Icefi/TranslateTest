.PHONY: all clean

all:
		gcc -o g.exe gui.c main.c -g `pkg-config --cflags --libs gtk+-3.0`
clean:
		rm *.o