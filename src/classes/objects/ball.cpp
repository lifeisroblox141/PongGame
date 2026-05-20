#include "ball.hpp"

#include <raymath.h>

#include <random>

#include "../../globals.hpp"

#define MIN_V 0
#define MAX_V 3
static const Vector2 directions[4] = {
    {-1.0f, -1.0f}, {1.0f, -1.0f}, {1.0f, 1.0f}, {-1.0f, 1.0f}};

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> distrib(MIN_V, MAX_V);

void Ball::set_position(Vector2& pos) {
        this->geometry = {pos.x, pos.y};
        this->hitbox.x = pos.x - (this->hitbox.width / 2);
        this->hitbox.y = pos.y - (this->hitbox.height / 2);

        if (this->velocity.x > 0)
                this->hitbox.x += this->radius;
        else if (this->velocity.x < 0)
                this->hitbox.x -= this->radius;
}
Ball::Ball(const Player& plr1, const Player& plr2) : plr1(plr1), plr2(plr2) {
        Vector2 set_middle = {(float)SCREEN_WIDTH / 2,
                              (float)SCREEN_HEIGHT / 2};
        this->velocity = directions[distrib(gen)];
        this->set_position(set_middle);
}
void Ball::update(float dt) {
        if (CheckCollisionRecs(this->hitbox, wall[WALL_LEFT]) ||
            CheckCollisionRecs(this->hitbox, wall[WALL_RIGHT])) {
                Vector2 set_middle = {(float)SCREEN_WIDTH / 2,
                                      (float)SCREEN_HEIGHT / 2};
                this->velocity = directions[distrib(gen)];
                this->set_position(set_middle);
                return;
        }

        if (CheckCollisionRecs(this->hitbox, this->plr1.geometry) ||
            CheckCollisionRecs(this->hitbox, this->plr2.geometry))
                this->velocity.x *= -1;
        if (CheckCollisionRecs(this->hitbox, wall[WALL_TOP]) ||
            CheckCollisionRecs(this->hitbox, wall[WALL_BOTTOM]))
                this->velocity.y *= -1;

        Vector2 new_pos = Vector2Add(
            (Vector2){this->geometry.x, this->geometry.y},
            Vector2Scale(Vector2Scale(this->velocity, dt), this->speed));
        this->set_position(new_pos);
}
void Ball::draw() {
        DrawCircleV((Vector2){this->geometry.x, this->geometry.y}, this->radius,
                    WHITE);
        DrawRectangleRec(this->hitbox, GREEN);
}
