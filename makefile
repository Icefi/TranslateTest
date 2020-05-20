OUT = t.exe
CFLAGS =`pkg-config --cflags --libs gtk+-3.0` -Wall "-Wno-incompatible-pointer-types" -g
OBJS = main.o gui.o base.o

.PHONY: all clean

all: clean $(OUT)

%.o: %.c
		gcc $^ -c -o $@ $(CFLAGS)

$(OUT): $(OBJS)
		gcc $^ -o $(OUT) $(CFLAGS)

clean:
		rm -f *.o $(OUT)