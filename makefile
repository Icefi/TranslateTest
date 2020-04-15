.PHONY: all clean

all:
		gcc -o g.exe main.c `pkg-config --cflags --libs gtk+-3.0`
clean:
		rm *.o