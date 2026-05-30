#include <raylib.h>

#include "../../globals.hpp"
#include "../object.hpp"

#ifndef _PLAYER_H_
#define _PLAYER_H_

#define PLAYER_ONE 1
#define PLAYER_TWO 2

// #define PLR_SIZE_X 10.0f
// #define PLR_SIZE_Y 100.0f

class Player : public Object {
       public:
        Player(int plr_n);
        ~Player();
        void update(float dt);
        void draw();
        void reset();

        Rectangle geometry = {0.0f, 0.0f, 10.0f, 100.0f};

       private:
        const float speed = 400.0f;
        const int plr_n;
        KeyboardKey move_up;
        KeyboardKey move_down;
        Texture2D texture;
};

#endif
