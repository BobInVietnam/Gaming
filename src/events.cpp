#include "events.hpp"

void MovePlayerTo(Player p_player, Vector2f p_des, Vector2f p_velocity) {
    Vector2f velocity;
    velocity.x = p_des.x - p_player.getPos().x < p_velocity.x ? p_des.x - p_player.getPos().x : p_velocity.x;
    velocity.y = p_des.y - p_player.getPos().y < p_velocity.y ? p_des.y - p_player.getPos().y : p_velocity.y;
    p_player.changePos(velocity);
}