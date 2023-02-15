#pragma once
#include <iostream>
#include <SDL2/SDL.h>

struct Vector2f {
    Vector2f()
    :x(0.0f), y(0.0f)
    {}
    Vector2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}

    void print() {
        std::cout << x << "," << y << std::endl;
    }

    float x, y;
};

Vector2f Velocity(Vector2f p_A, Vector2f p_B, float p_speed);
bool VectorsEqual(Vector2f p_A, Vector2f p_B);
