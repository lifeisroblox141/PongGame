#include <raylib.h>

#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object {
       public:
        // virtual void input() = 0;
        virtual void update(float dt) = 0;
        virtual void draw() = 0;
        virtual void reset() = 0;

       protected:
        /*Vector2 position = {0.0f, 0.0f};
        Vector2 size = {0.0f, 0.0f};*/
        Rectangle geometry = {0.0f, 0.0f};
};

#endif
