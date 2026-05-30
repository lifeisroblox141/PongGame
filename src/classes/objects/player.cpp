#include "./player.hpp"

Player::~Player() { UnloadTexture(this->texture); }
Player::Player(int plr_n) : Object(), plr_n(plr_n) {
        // Sets position and img to load
        std::string img_path(application_dir);
        if (plr_n == PLAYER_ONE) {
                this->geometry.x = WALL_OFFSET;
                this->move_up = KEY_W;
                this->move_down = KEY_S;
                img_path.append("assets/Computer.png");
        } else if (plr_n == PLAYER_TWO) {
                this->geometry.x = SCREEN_WIDTH - 2 * WALL_OFFSET;
                this->move_up = KEY_UP;
                this->move_down = KEY_DOWN;
                img_path.append("assets/Player.png");
        }
        Image img = LoadImage(img_path.c_str());
        ImageResize(&img, (int)this->geometry.width * 1,
                    (int)this->geometry.height * 1);
        this->texture = LoadTextureFromImage(img);
        UnloadImage(img);
        // this->position.y = (float)(SCREEN_HEIGHT - this->size.y) / 2;
        // this->geometry.y = (float)(SCREEN_HEIGHT - this->geometry.height) /
        // 2;
}
void Player::reset() {
        this->geometry.y = (float)(SCREEN_HEIGHT - this->geometry.height) / 2;
}
void Player::update(float dt) {
        float accleration = this->speed * dt;
        if (IsKeyDown(this->move_up) &&
            !CheckCollisionRecs(this->geometry, wall[WALL_TOP]))
                this->geometry.y -= accleration;
        else if (IsKeyDown(this->move_down) &&
                 !CheckCollisionRecs(this->geometry, wall[WALL_BOTTOM]))
                this->geometry.y += accleration;
}
void Player::draw() {
        Color color;
        if (this->plr_n == PLAYER_ONE)
                color = BLUE;
        else if (this->plr_n == PLAYER_TWO)
                color = RED;
        // DrawRectangleRec(this->geometry, color);
        DrawTextureV(this->texture,
                     (Vector2){this->geometry.x, this->geometry.y}, WHITE);
        // DrawRectangleRec(this->hitbox, GREEN);
}
