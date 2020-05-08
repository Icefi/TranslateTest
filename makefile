OUT = t.exe
CFLAGS = "-Wno-incompatible-pointer-types"  -g `pkg-config --cflags --libs gtk+-3.0`
OBJS = main.o gui.o

.PHONY: all clean

all: clean $(OUT)

%.o: %.c
		gcc $^ -c $(CFLAGS) -o $@

$(OUT): $(OBJS)
		gcc `pkg-config --cflags --libs gtk+-3.0` -o $(OUT) $^

clean:
		rm -f *.o $(OUT)
