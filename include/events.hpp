#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "math.hpp"
#include "entity.hpp"

void MovePlayerTo(Player& p_player, Vector2f p_des, Vector2f p_velocity);