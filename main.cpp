#include <SDL2/SDL.h>
#include "mandelbrot.h"

#define WIDTH 800
#define HEIGHT 800

int main(int argc, char *argv[])
{

	if(SDL_Init(SDL_INIT_VIDEO) == -1){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
	}

	SDL_Window* w = SDL_CreateWindow("First SDL Project", 50, 50, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if(!w){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
	}

	SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);

    if(!r){
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    InitMandelbrot(r);
    DrawMandelbrotSet(r, WIDTH, HEIGHT, 2.0, 2.0);

    int i = 0;

    while(1){
        SDL_RenderPresent(r);
        SDL_Delay(300);

        i += 1;
        if(i == 20) break;

    }

	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
    SDL_Quit();

    return EXIT_SUCCESS;
}
