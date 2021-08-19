//
// Created by quentin on 17/08/2021.
//

#include "mandelbrot.h"

void InitMandelbrot(SDL_Renderer* r){
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_Delay(100);
    SDL_RenderPresent(r);
    SDL_Delay(100);
}

bool belongsToMandelbrotSet(std::complex<double> c, int* z_return){
    std::complex<double> z = 0;
    *z_return = 0;

    for(int i = 0; i < 20; i++){
        z = z*z + c;
        *z_return +=1;
        if(std::norm(z) > 2) return false;
    }

    return true;
}

void DrawMandelbrotSet(SDL_Renderer* r, int w, int h, double x, double y){
    SDL_RenderClear(r);

    int ir = 0, jr = 0;

    for(double i = -x; i <= x; i+=2*x/w, ir++){
        for(double j = -y; j <= y; j += 2*y/h, jr++){

            if(ir > w || jr > h) break;

            std::complex<double> c = std::complex<double>(i, j);
            int z = 0;

            if (belongsToMandelbrotSet(c, &z)) SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
            else {

                int colors[3] = {0};

                ColorFunctionMandelbrot(z, colors);

                SDL_SetRenderDrawColor(r, colors[0], colors[1], colors[2], 255);
            }

            SDL_RenderDrawPoint(r, ir, jr);
        }
        jr = 0;
        render(r);
    }


    /*
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++) {

            double xscale, yscale;


            xscale = x*i/w -1.0;
            yscale = y*j/h -1.0;



            std::complex<double> c = std::complex<double>(xscale, yscale);
            int z = 0;

            if (belongsToMandelbrotSet(c, &z)) SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
            else {

                int colors[3] = {0};
                ColorFunctionMandelbrot(z, colors); // Color the orbits
                SDL_SetRenderDrawColor(r, colors[0], colors[1], colors[2], 255);
            }

            SDL_RenderDrawPoint(r, i, j);

        }

        render(r);

    }
     */


    SDL_RenderPresent(r);


}

/**
 * Renders each x frames => allows better rendering and performance
 * @param r
 */
void render(SDL_Renderer *r){
    static int render_counter = 0;

    if(render_counter == 100){
        render_counter = 0;
        SDL_RenderPresent(r);
    }else render_counter++;
}

/**
 * Colors the orbits
 * @param z orbit
 * @param color reference to color array
 */
void ColorFunctionMandelbrot(int z, int* color){
    const int r[16u] = {245, 40, 52, 107, 159, 143, 58, 129, 154, 108, 154, 96, 61, 60, 14, 115};
    const int g[16u] = {85, 50, 147, 249, 244, 25, 19, 196, 230, 61, 206, 38, 226, 98, 111, 40};
    const int b[16u] = {15, 191, 46, 107, 23, 83, 32, 231, 126, 4, 48, 34, 104, 209, 46, 90};

    color[0] = r[z%16];
    color[1] = g[z%16];
    color[2] = b[z%16];
}