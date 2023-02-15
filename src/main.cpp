#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "utilities.hpp"

#include "aniList.hpp"

int main(int argc, char *argv[]) {
    //SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_Init HAS FAILED. ERROR: " << SDL_GetError() << std::endl;
    }
    std::cout << "End of warning..." << std::endl;
//--------------------------------------------------------------------------------------------------------
    //Window & entities initialization 
    RenderWindow window("Hello!", 1920, 1080);

    Background Bg(window.loadTexture("res/gfx/bg.png"));
    std::vector<Player> players = {Player(Vector2f(100, 100), window.loadTexture("res/gfx/p_player_idle.png"), Vector2f(100, 100))};
//--------------------------------------------------------------------------------------------------------
    //Creating time loop
    SDL_Event event;
    // const float timeStep = 0.02f;
    // float accumulator = 0.0f;
    //float currentTime = utils::hireTime();
    const int frameDelay = 1000 / 15;

    //Running the game
    bool gameRunning = true;
    int aniID = 0;
    while (gameRunning) {
        int startTick = SDL_GetTicks();
        // float newTime = utils::hireTime();
        // float frameTime = newTime - currentTime;

        // currentTime = newTime;
        // accumulator += frameTime;

        //Dealing with events
        //while (accumulator >= timeStep) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_s:
                        std::cout << animationList[aniID];
                        players[0].changeTexture(window.loadTexture(animationList[aniID]));
                        ++aniID;
                        if (aniID > 3) aniID = 0;
                        break;
                    case SDLK_ESCAPE:
                        gameRunning = false;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == SDL_QUIT) gameRunning = false;
            SDL_ResetKeyboard();
        }
        
        //Run graphics
        window.clear();

        window.renderBackground(Bg);
        window.renderPlayers(players);
        players[0].runAnimation(5);

        std::cout << utils::hireTime() << std::endl;

        window.display();

        //for framerate
        int frameTick = SDL_GetTicks() - startTick;
        if (frameDelay > frameTick) SDL_Delay(frameDelay - frameTick);
    }
//--------------------------------------------------------------------------------------------------------
    //It's the end
    std::cout << "End of terminal..." << std::endl;
    window.cleanUp();
    SDL_Quit();
    
    return EXIT_SUCCESS;
}