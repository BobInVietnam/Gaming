#include "math.hpp"

Vector2f Velocity(Vector2f p_A, Vector2f p_B, float p_speed) {
    Vector2f velocity;

    float veloX = p_B.x - p_A.x;
    float veloY = p_B.y - p_A.y;
    float veloXY = SDL_sqrt(veloX * veloX + veloY * veloY);

    velocity.x = p_speed * (veloX / veloXY);
    velocity.y = p_speed * (veloY / veloXY);
    return velocity;
}

bool VectorsEqual(Vector2f p_A, Vector2f p_B) {
    return (p_A.x == p_B.x && p_A.y == p_B.y);
}