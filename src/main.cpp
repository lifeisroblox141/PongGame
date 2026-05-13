#include <iostream>

#include "raylib.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480
#define TITLE "PongGame"

int main() {
        std::cout << "Game starts !\n";
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
        while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(BLACK);
                EndDrawing();
        }
        CloseWindow();
        return 0;
}
