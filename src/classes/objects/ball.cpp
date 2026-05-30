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
Ball::~Ball() {
        UnloadSound(this->pop_sound);
        UnloadTexture(this->texture);
        // UnloadImage(this->ball_img);
}
void Ball::reset() {
        Vector2 set_middle = {(float)SCREEN_WIDTH / 2,
                              (float)SCREEN_HEIGHT / 2};
        this->velocity = directions[distrib(gen)];
        this->set_position(set_middle);
        // this->resetted = true;
}
Ball::Ball(const Player& plr1, const Player& plr2) : plr1(plr1), plr2(plr2) {
        // this->reset();
        game_resetted = true;

        std::string sound_path =
            std::string(application_dir).append("assets/Pop.ogg");
        this->pop_sound = LoadSound(sound_path.c_str());

        std::string tex_path =
            std::string(application_dir).append("assets/Ball.png");
        Image img = LoadImage(tex_path.c_str());
        ImageResize(&img, (int)this->img_wh, (int)this->img_wh);
        this->texture = LoadTextureFromImage(img);
        UnloadImage(img);
}
void Ball::update(float dt) {
        // bool collided = false;
        // if (IsKeyDown(KEY_SPACE)) game_resetted = false;

        bool touched_wall1 = CheckCollisionRecs(this->hitbox, wall[WALL_LEFT]);
        bool touched_wall2 = CheckCollisionRecs(this->hitbox, wall[WALL_RIGHT]);
        if (touched_wall1 || touched_wall2) {
                if (touched_wall1)
                        plr2_score += this->given_score;
                else if (touched_wall2)
                        plr1_score += this->given_score;
                game_resetted = true;
                return;
        }

        if (CheckCollisionRecs(this->hitbox, this->plr1.geometry) ||
            CheckCollisionRecs(this->hitbox, this->plr2.geometry)) {
                this->velocity.x *= -1;
                PlaySound(this->pop_sound);
        }

        if (CheckCollisionRecs(this->hitbox, wall[WALL_TOP]) ||
            CheckCollisionRecs(this->hitbox, wall[WALL_BOTTOM])) {
                this->velocity.y *= -1;
                PlaySound(this->pop_sound);
                // collided = true;
        }

        /*if (collided) {
                if (this->speed > this->max_speed)
                        this->speed = this->min_speed;
                else
                        this->speed += this->dt_speed;
        }*/

        Vector2 new_pos = Vector2Add(
            (Vector2){this->geometry.x, this->geometry.y},
            Vector2Scale(Vector2Scale(this->velocity, dt), this->speed));
        this->set_position(new_pos);
}
void Ball::draw() {
        /*DrawCircleV((Vector2){this->geometry.x, this->geometry.y},
           this->radius, GREEN);*/
        DrawTextureV(this->texture,
                     (Vector2){this->geometry.x - (this->img_wh / 2.0f),
                               this->geometry.y - (this->img_wh / 2.0f)},
                     WHITE);
        // DrawRectangleRec(this->hitbox, GREEN);
}
