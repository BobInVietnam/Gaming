#include "entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Background functions definition
Background::Background(SDL_Texture* p_tex) 
    :texture(p_tex)
{
    currentFrame.x = 0;
}
void Background::runAnimation(int p_frameNum) {
    currentFrame.x = currentFrameNum * 1920;
    currentFrameNum++;
    if (currentFrameNum >= p_frameNum) currentFrameNum = 0;
}

//Player functions definitions
Player::Player(Vector2f p_pos, SDL_Texture* p_tex, Vector2f p_size)
    :size(p_size), pos(p_pos), texture(p_tex)
{
    currentFrame.x = 0;
}
void Player::changePos(Vector2f p_velocity) {
    pos.x += p_velocity.x;
    pos.y += p_velocity.y;
}
void Player::changeTexture(SDL_Texture* p_tex) {
    texture = p_tex;
    resetFrameNum();
}
void Player::runAnimation(int p_frameNum) {
    currentFrame.x = currentFrameNum * size.x;
    currentFrameNum++;
    if (currentFrameNum >= p_frameNum) currentFrameNum = 0;
}