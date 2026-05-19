#include "./ball.hpp"

#include <raymath.h>

#include <iostream>
#include <random>

#include "../../globals.hpp"

#define MIN_V 0
#define MAX_V 1

static std::random_device rd;
static std::mt19937 generator(rd());
static std::uniform_int_distribution<> distr(MIN_V, MAX_V);

static inline void check(Vector2& vec) {
        std::cout << vec.x << ", " << vec.y << '\n';
}

float Ball::random_and_reseed() {
        int ran = distr(generator);
        generator.seed(rd());

        float result = 0;
        if (ran == MIN_V)
                result = this->speed;
        else if (ran == MAX_V)
                result = -this->speed;
        return result;
}
Ball::Ball(Player& plr1, Player& plr2) : Object(), plr1(plr1), plr2(plr2) {
        this->geometry = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

        this->velocity = {this->random_and_reseed(), this->random_and_reseed()};
        this->velocity = Vector2Normalize(this->velocity);
        this->velocity = Vector2Scale(this->velocity, this->speed);
        // check(this->velocity);
}
void Ball::update(float dt) {
        Vector2 c_pos = {this->geometry.x, this->geometry.y};

        if (CheckCollisionCircleRec(c_pos, this->radius, wall[WALL_TOP]) ||
            CheckCollisionCircleRec(c_pos, this->radius, wall[WALL_BOTTOM]))
                this->velocity.y = -this->velocity.y;
        if (CheckCollisionCircleRec(c_pos, this->radius, wall[WALL_LEFT]) ||
            CheckCollisionCircleRec(c_pos, this->radius, wall[WALL_RIGHT]) ||
            CheckCollisionCircleRec(c_pos, this->radius, this->plr1.geometry) ||
            CheckCollisionCircleRec(c_pos, this->radius, this->plr2.geometry))
                this->velocity.x = -this->velocity.x;

        Vector2 new_pos = Vector2Add(c_pos, Vector2Scale(this->velocity, dt));
        this->geometry.x = new_pos.x;
        this->geometry.y = new_pos.y;
}
void Ball::draw() {
        DrawCircleV((Vector2){this->geometry.x, this->geometry.y}, this->radius,
                    WHITE);
}
