#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h, int p_s):window(NULL), renderer(NULL), scale(p_s){
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if(window == NULL){
        std::cerr << "SDL_CreateWindow failed. Error:" << std::endl << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        std::cerr << "SDL_CreateRenderer failed. Error:" << std::endl << SDL_GetError() << std::endl;
    }
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    if(texture == NULL){
        std::cerr << "IMG_LoadTexture failed. Error:" << std::endl << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity){
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;
    SDL_Rect dst;
    dst.x = p_entity.getPos().x * scale;
    dst.y = p_entity.getPos().y * scale;
    dst.w = p_entity.getCurrentFrame().w * scale;
    dst.h = p_entity.getCurrentFrame().h * scale;
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

void RenderWindow::getScaledSize(int* w, int* h){
    SDL_GetWindowSize(window, w, h);
    *w/=scale;
    *h/=scale;
}

int RenderWindow::getRefreshRate(){
    int displayIdx = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIdx, 0, &mode);
    return mode.refresh_rate;
}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}