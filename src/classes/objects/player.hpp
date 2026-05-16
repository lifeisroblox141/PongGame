#include <raylib.h>

#include "../../globals.hpp"
#include "../object.hpp"

#ifndef _PLAYER_H_
#define _PLAYER_H_

#define PLAYER_ONE 1
#define PLAYER_TWO 2

#define PLR_SIZE_X 10.0f
#define PLR_SIZE_Y 100.0f

class Player : public Object {
       public:
        Player(int plr_n);
        void update(float dt);
        void draw();

       protected:
        const float speed = 400.0f;
        const int plr_n;
        Rectangle geometry = {0.0f, 0.0f, PLR_SIZE_X, PLR_SIZE_Y};
        KeyboardKey move_up;
        KeyboardKey move_down;
};

#endif
