CC=g++
CFLAGS=
BUILD=build
SDLFLAGS=`sdl2-config --cflags --libs`

main: $(BUILD)/main.o $(BUILD)/mandelbrot.o
	$(CC) -o $@ $^ $(SDLFLAGS)

$(BUILD)/main.o: main.cpp
	$(CC) -o $@ -c $^ $(SDLFLAGS)

$(BUILD)/mandelbrot.o: mandelbrot.cpp
	$(CC) -o $@ -c $^ $(SDLFLAGS)

