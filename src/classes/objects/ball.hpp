#include "../object.hpp"
#include "./player.hpp"
#include "raylib.h"

#ifndef _BALL_H_
#define _BALL_H_

class Ball : public Object {
       public:
        Ball(Player& plr1, Player& plr2);
        void update(float dt);
        void draw();

       protected:
        const Player& plr1;
        const Player& plr2;
        // Rectangle geometry = {0.0f, 0.0f, 0.0f, 0.0f};
        // Vector2 velocity = {0.0f, 0.0f};
        Vector2 velocity;
        const float radius = 30.0f;
        const float speed = 400.0f;

        float random_and_reseed();
};

#endif
