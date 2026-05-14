#include <raylib.h>

#include <iostream>

#include "./classes/objects/player.hpp"
#include "./globals.hpp"

#define FPS 60
#define TITLE "PongGame"

int main() {
        std::cout << "Game starts !\n";
        SetTargetFPS(FPS);

        Player plr1(PLAYER_ONE);
        Player plr2(PLAYER_TWO);

        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
        while (!WindowShouldClose()) {
                float dt = GetFrameTime();
                plr1.update(dt);
                plr2.update(dt);

                BeginDrawing();

                ClearBackground(BLACK);
                plr1.draw();
                plr2.draw();
                for (Rectangle w : wall) DrawRectangleRec(w, WHITE);

                EndDrawing();
        }
        CloseWindow();
        return 0;
}
