OUT = t.exe
CFLAGS = -Wall "-Wno-incompatible-pointer-types" `pkg-config --cflags --libs gtk+-3.0`
OBJS = main.o gui.o base.o

.PHONY: all clean

all: clean $(OUT)

%.o: %.c
		gcc $^ -c $(CFLAGS) -o $@

$(OUT): $(OBJS)
		gcc -g `pkg-config --cflags --libs gtk+-3.0` -o $(OUT) $^

clean:
		rm -f *.o $(OUT)
