#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../poly/poly.h"


double evaluerPolynome(polynome p, double x);


void tracerPoints(SDL_Renderer* renderer, int screenWidth, int screenHeight, polynome p, int nombrePoints, double xMin, double xMax, double yMin, double yMax);


int tracerPolynome(polynome p);


#endif