#include <raylib.h>

#include "../object.hpp"
#include "./player.hpp"
#ifndef _BALL_H_
#define _BALL_H_

class Ball : public Object {
       public:
        Ball(const Player& plr1, const Player& plr2);
        ~Ball();
        void update(float dt);
        void draw();
        void reset();

       private:
        const Player& plr1;
        const Player& plr2;
        const int given_score = 1;
        // const float min_speed = 300.0f;
        // const float max_speed = 500.0f;
        // const float dt_speed = 50.0f;
        // bool resetted = false;
        Sound pop_sound;
        const float speed = 300.0f;
        const float radius = 20.0f;
        Rectangle hitbox = {0.0f, 0.0f, 10.0f, 50.0f};
        Vector2 velocity = {0.0f, 0.0f};

        void set_position(Vector2& pos);
};

#endif
