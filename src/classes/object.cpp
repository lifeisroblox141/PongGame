#include "./object.hpp"

void Object::set_position(float x, float y) {
        this->position.x = x;
        this->position.y = y;
        this->hitbox.x = x;
        this->hitbox.y = y;
}
void Object::set_size(float w, float h) {
        this->size.x = w;
        this->size.y = h;
        this->hitbox.width = w;
        this->hitbox.height = h;
}
