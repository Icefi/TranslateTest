BS = build/src/
BT = build/test/

S = src/
T = test/

OG = bin/translate
OT = bin/test

CFLAGS =`pkg-config --cflags --libs gtk+-3.0` -Wall "-Wno-incompatible-pointer-types" -g

OBJS = $(BS)main.o $(BS)gui.o $(BS)base.o

#main

all: $(OG) $(OT) 
	
$(BS)main.o: $(S)main.c
	gcc $^ -c -o $@ $(CFLAGS)

$(BS)gui.o: $(S)gui.c
	gcc $^ -c -o $@ $(CFLAGS)
	
$(BS)base.o: $(S)base.c
	gcc $^ -c -o $@ $(CFLAGS)
	
$(OG): $(OBJS)
	gcc $^ -o $(OG) $(CFLAGS)

#test

build/test/main.o: test/main.c
	gcc -I src $^ -c -o $@ $(CFLAGS)
	
build/test/base.o: src/base.c
	gcc -I src $^ -c -o $@ $(CFLAGS)
	
build/test/ctest.o: test/ctest.c
	gcc -I src $^ -c -o $@ $(CFLAGS)
	
$(OT): build/test/main.o build/test/base.o build/test/ctest.o
	gcc -I src $^ -o $@ $(CFLAGS)
	


