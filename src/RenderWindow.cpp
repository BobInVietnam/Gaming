#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) 
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED
                                        , SDL_WINDOWPOS_UNDEFINED, p_w , p_h
                                        , SDL_WINDOW_SHOWN);
    if (NULL == window) {
        std::cout << "Could not create window :(" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, 1920, 1080);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    return texture;
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}
void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}
// void RenderWindow::render(Entity& p_entity) {
//     SDL_Rect src;
//     src.x = p_entity.getCurrentFrame().x;
//     src.y = p_entity.getCurrentFrame().y;
//     src.w = p_entity.getCurrentFrame().w;
//     src.h = p_entity.getCurrentFrame().h;

//     SDL_Rect des;
//     des.x = p_entity.getPos().x;
//     des.y = p_entity.getPos().y;
//     des.w = p_entity.getCurrentFrame().w/5;
//     des.h = p_entity.getCurrentFrame().h/5;
//     SDL_RenderCopy(renderer, p_entity.getTex(), &src, &des);
// }

void RenderWindow::renderBackground(Background& p_bg) {
    SDL_Rect src;
    src.x = p_bg.getCurrentFrame().x;
    src.y = 0;
    src.w = 1920;
    src.h = 1080;

    SDL_Rect des;
    des.x = 0;
    des.y = 0;
    des.w = 1920;
    des.h = 1080;
    SDL_RenderCopy(renderer, p_bg.getTex(), &src, &des);
}
void RenderWindow::renderPlayers(std::vector<Player>& p_player) {
    for (auto i = p_player.begin(); i != p_player.end(); ++i) {
        Player subject = *i;
        SDL_Rect src;
        src.x = subject.getCurrentFrame().x;
        src.y = 0;
        src.w = subject.getSize().x;
        src.h = subject.getSize().y;

        SDL_Rect des;
        des.x = subject.getPos().x;
        des.y = subject.getPos().y;
        des.w = subject.getSize().x;
        des.h = subject.getSize().y;
        SDL_RenderCopy(renderer, subject.getTex(), &src, &des);
    }
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}
