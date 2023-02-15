#pragma once
#include <vector>
#include <string>
enum Animation{
    Idle,
    Move,
    Attack,
    Defeat,
};

std::vector<const char*> animationList = { "res/gfx/p_player_idle.png", 
                                        "res/gfx/p_player_move.png", 
                                        "res/gfx/p_player_attack.png", 
                                        "res/gfx/p_player_defeat.png"};