#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);

    void cleanUp();
    void clear();
   // void render(Entity& p_entity);
    void display();

    void renderBackground(Background& p_bg);
    void renderPlayers(std::vector<Player>& p_player);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};