#define RAYMATH_IMPLEMENTATION
#include <raylib.h>

#include <iostream>

#include "./classes/objects/ball.hpp"
#include "./classes/objects/player.hpp"
#include "./globals.hpp"

#define FPS 60
#define TITLE "PongGame"

int main() {
        std::cout << "Game starts !\n";
        SetTargetFPS(FPS);

        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
        InitAudioDevice();

        Player plr1(PLAYER_ONE);
        Player plr2(PLAYER_TWO);

        Ball ba(plr1, plr2);

        std::string path =
            std::string(application_dir).append("assets/Teko-SemiBold.ttf");
        Font teko_semibold = LoadFont(path.c_str());

        for (int i = 0; i < N_WALL; i++)
                std::cout << "x:" << wall[i].x << ", y:" << wall[i].y
                          << "; w:" << wall[i].width
                          << ", h: " << wall[i].height << '\n';
        bool rs_db = false;
        while (!WindowShouldClose()) {
                float dt = GetFrameTime();

                if (game_resetted && !rs_db) {
                        // Call reset
                        std::cout << "Reset!\n";
                        plr1.reset();
                        plr2.reset();
                        ba.reset();
                        rs_db = true;
                }

                if (IsKeyDown(KEY_SPACE)) {
                        game_resetted = false;
                        rs_db = false;
                }
                if (!game_resetted) {
                        plr1.update(dt);
                        plr2.update(dt);
                        ba.update(dt);
                        BeginDrawing();
                }

                ClearBackground(BLACK);

                for (Rectangle w : wall) DrawRectangleRec(w, WHITE);
                DrawRectangleRec(
                    (Rectangle){(SCREEN_WIDTH - WALL_OFFSET) / 2.0f,
                                (SCREEN_HEIGHT - (SCREEN_HEIGHT / 2.0f)) / 2.0f,
                                WALL_OFFSET, SCREEN_HEIGHT / 2.0f},
                    WHITE);

                std::string label1 = "PLR1: ";
                label1.append(std::to_string(plr1_score));
                DrawTextEx(teko_semibold, label1.c_str(),
                           (Vector2){(SCREEN_WIDTH / 4.0f) - WALL_OFFSET,
                                     4 * WALL_OFFSET},
                           teko_semibold.baseSize, 2, WHITE);
                std::string label2 = "PLR1: ";
                label2.append(std::to_string(plr2_score));
                DrawTextEx(
                    teko_semibold, label2.c_str(),
                    (Vector2){((SCREEN_WIDTH / 4.0f) * 3.0f) - WALL_OFFSET,
                              4 * WALL_OFFSET},
                    teko_semibold.baseSize, 2, WHITE);

                if (game_resetted)
                        DrawTextEx(
                            teko_semibold, "Press space to start game!",
                            (Vector2){(SCREEN_WIDTH / 2.0f) - 12 * WALL_OFFSET,
                                      WALL_OFFSET},
                            (float)teko_semibold.baseSize, 2.0f, WHITE);

                plr1.draw();
                plr2.draw();
                ba.draw();

                EndDrawing();
        }
        UnloadFont(teko_semibold);
        CloseAudioDevice();
        CloseWindow();
        return 0;
}
