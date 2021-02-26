#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
class RenderWindow{
public:
    RenderWindow(const char* p_title, int p_w, int p_h, int p_s);
    void cleanUp();
    SDL_Texture* loadTexture(const char* p_filePath);
    void clear();
    void render(Entity& p_entity);
    void display();
    void getScaledSize(int* w, int* h);
    int getRefreshRate();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int scale;
};