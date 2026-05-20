#include <raylib.h>

#include "../object.hpp"
#include "./player.hpp"
#ifndef _BALL_H_
#define _BALL_H_

class Ball : public Object {
       public:
        Ball(const Player& plr1, const Player& plr2);
        void update(float dt) override;
        void draw() override;

       private:
        const Player& plr1;
        const Player& plr2;
        const float speed = 250.0f;
        const float radius = 20.0f;
        Rectangle hitbox = {0.0f, 0.0f, 10.0f, 50.0f};
        Vector2 velocity = {0.0f, 0.0f};

        void set_position(Vector2& pos);
};

#endif
