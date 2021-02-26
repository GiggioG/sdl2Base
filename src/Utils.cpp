#include <SDL2/SDL.h>
#include "Utils.hpp"
float utils::hireTimeInSeconds(){
    float t = SDL_GetTicks();
    t*=0.001f;
    return t;
}