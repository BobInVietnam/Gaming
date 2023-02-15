#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "math.hpp"

// class Entity {
// public:
//     Entity(Vector2f p_pos, SDL_Texture* p_tex, Vector2f p_size);
//     Vector2f getPos() {
//         return pos;
//     }
//     SDL_Texture* getTex();
//     SDL_Rect getCurrentFrame();
//     void changePos(Vector2f p_velocity);
//     void runAnimation(int p_frameNum);
    
// private:
//     Vector2f startingSize;
//     Vector2f pos;
//     SDL_Rect currentFrame;
//     SDL_Texture* texture;
//     int currentFrameNum = 0;
// };

class Background {
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
    int currentFrameNum = 0;
public:
    Background(SDL_Texture* p_tex);
    Vector2f getPos() {
        return pos;
    }
    SDL_Texture* getTex() {
        return texture;
    };
    SDL_Rect getCurrentFrame() {
        return currentFrame;
    };
    void runAnimation(int p_frameNum);   
};

class Player {  
private:
    Vector2f size;
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
    int currentFrameNum = 0;
public:
    Player(Vector2f p_pos, SDL_Texture* p_tex, Vector2f p_size);
    Vector2f getPos() {
        return pos;
    }
    Vector2f getSize() {
        return size;
    };
    SDL_Texture* getTex() {
        return texture;
    };
    SDL_Rect getCurrentFrame() {
        return currentFrame;
    };
    void changePos(Vector2f p_velocity);

    void changeTexture(SDL_Texture* p_tex);
    void runAnimation(int p_frameNum);
    void resetFrameNum() {
        currentFrameNum = 0;
    }
};