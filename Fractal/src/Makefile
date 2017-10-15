CC=g++

CFLAGS=-c -Wall -std=c++11

INCLUDES=-lSDL2 -lSDL2main

all: program

program: main.o FractalCreator.o Bitmap.o Mandelbrot.o RGB.o ZoomList.o Screen.o
		$(CC) main.o FractalCreator.o Bitmap.o Mandelbrot.o RGB.o ZoomList.o Screen.o -o MandelbrotGenerator $(INCLUDES)

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

FractalCreator.o: FractalCreator.cpp
		$(CC) $(CFLAGS) FractalCreator.cpp

Bitmap.o: Bitmap.cpp
		$(CC) $(CFLAGS) Bitmap.cpp

Mandelbrot.o: Mandelbrot.cpp
		$(CC) $(CFLAGS) Mandelbrot.cpp

RGB.o: RGB.cpp
		$(CC) $(CFLAGS) RGB.cpp

ZoomList.o: ZoomList.cpp
		$(CC) $(CFLAGS) ZoomList.cpp

Screen.o: SDL2/Screen.cpp
		$(CC) $(CFLAGS) SDL2/Screen.cpp


clean:
	rm -rf *o MandelbrotGenerator