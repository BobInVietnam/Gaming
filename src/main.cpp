#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "utilities.hpp"
#include "events.hpp"

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

    SDL_Event gameEvent;
    Background Bg(window.loadTexture("res/gfx/bg.png"));
    std::vector<Player> players = {Player(Vector2f(100, 100), window.loadTexture("res/gfx/p_player_idle.png"), Vector2f(100, 100))};
//--------------------------------------------------------------------------------------------------------
    //Creating time loop
    const int frameDelay = 1000 / 15;

    //Initializing game stats
    Vector2f velocity;
    Vector2f MousePos;

    //Running the game
    bool gameRunning = true;
    while (gameRunning) {
        int startTick = SDL_GetTicks();

        //Dealing with events
        while (SDL_PollEvent(&gameEvent)) {
            if (gameEvent.type == SDL_MOUSEBUTTONDOWN) {
                MousePos.x = gameEvent.button.x;
                MousePos.y = gameEvent.button.y;
                velocity = Velocity(players[0].getPos(), MousePos, 20);
            }
            if (gameEvent.type == SDL_QUIT) gameRunning = false;
            SDL_ResetKeyboard();
        }
        if (!VectorsEqual(players[0].getPos(), MousePos)) MovePlayerTo(players[0], MousePos, velocity);
        
        //Run graphics
        window.clear();

        window.renderBackground(Bg);
        window.renderPlayers(players);
        players[0].runAnimation(5);

        std::cout << utils::hireTime() << std::endl;
        std::cout << "mouse pos:"; MousePos.print();
        std::cout << "obj velocity:"; velocity.print();
        std::cout << std::endl;


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