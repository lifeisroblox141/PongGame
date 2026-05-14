#include "./player.hpp"

Player::Player(int plr_n) : Object(), plr_n(plr_n) {
        // Sets position
        if (plr_n == PLAYER_ONE) {
                this->position.x = 0.0f + WALL_OFFSET;
                this->move_up = KEY_W;
                this->move_down = KEY_S;
        } else if (plr_n == PLAYER_TWO) {
                this->position.x = SCREEN_WIDTH - 2 * WALL_OFFSET;
                this->move_up = KEY_UP;
                this->move_down = KEY_DOWN;
        }
        this->position.y = (float)(SCREEN_HEIGHT - this->size.y) / 2;
        this->hitbox.x = this->position.x;
        this->hitbox.y = this->position.y;
}
void Player::update(float dt) {
        float accleration = this->speed * dt;
        if (IsKeyDown(this->move_up))
                this->set_position(this->position.x,
                                   this->position.y - accleration);
        else if (IsKeyDown(this->move_down))
                this->set_position(this->position.x,
                                   this->position.y + accleration);
}
void Player::draw() {
        Color color;
        if (this->plr_n == PLAYER_ONE)
                color = BLUE;
        else if (this->plr_n == PLAYER_TWO)
                color = RED;
        DrawRectangleV(this->position, this->size, color);
        // DrawRectangleRec(this->hitbox, GREEN);
}
