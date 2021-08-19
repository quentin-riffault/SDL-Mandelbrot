//
// Created by quentin on 17/08/2021.
//

#ifndef TEST_MANDELBROT_H
#define TEST_MANDELBROT_H

#include <SDL2/SDL.h>
#include <complex>

void InitMandelbrot(SDL_Renderer*);
bool BelongsToMandelbrotSet(std::complex<double> c, int*);
void DrawMandelbrotSet(SDL_Renderer*, int, int, double, double);
void ColorFunctionMandelbrot(int z, int*);
void render(SDL_Renderer *r);

#endif //TEST_MANDELBROT_H
