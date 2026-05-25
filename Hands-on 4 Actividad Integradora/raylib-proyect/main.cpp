#include "raylib.h"
#include <cmath>

int main() {

    InitWindow(1000, 700, "Transformaciones");
    SetTargetFPS(60);

    int mode = 0;

    float x = 100;
    float y = 350;

    float vx = 4;
    float vy = 4;

    float angle = 0;
    float time = 0;

    float orbitAngle = 0;

    while (!WindowShouldClose()) {

        // CAMBIO DE MODOS
        if (IsKeyPressed(KEY_ONE)) mode = 1;
        if (IsKeyPressed(KEY_TWO)) mode = 2;
        if (IsKeyPressed(KEY_THREE)) mode = 3;
        if (IsKeyPressed(KEY_FOUR)) mode = 4;
        if (IsKeyPressed(KEY_FIVE)) mode = 5;
        if (IsKeyPressed(KEY_SIX)) mode = 6;

        // TRASLACION
        if (mode == 1) {

            x += 3;

            if (x > 1050) {
                x = -50;
            }
        }

        // ROTACION
        else if (mode == 2) {

            angle += 1;
        }

        // REBOTE
        else if (mode == 3) {

            x += vx;
            y += vy;

            if (x > 970 || x < 30) vx *= -1;
            if (y > 670 || y < 30) vy *= -1;
        }

        // SENOIDAL
        else if (mode == 4) {

            time += 0.05f;

            x += 2;

            y = 350 + sin(time) * 100;

            if (x > 1050) {
                x = -50;
            }
        }

        // TRAYECTORIA PARABOLICA
        else if (mode == 5) {

            x += vx;

            y += vy;

            vy += 0.2f;

            if (y > 670) {

                x = 100;
                y = 350;

                vx = 5;
                vy = -10;
            }
        }

        // ORBITA
        else if (mode == 6) {

            orbitAngle += 0.02f;

            x = 500 + cos(orbitAngle) * 150;

            y = 350 + sin(orbitAngle) * 150;
        }

        // Dibujar
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("1 = Traslacion", 20, 20, 20, GREEN);
        DrawText("2 = Rotacion", 20, 50, 20, SKYBLUE);
        DrawText("3 = Rebote", 20, 80, 20, RED);
        DrawText("4 = Senoidal", 20, 110, 20, ORANGE);
        DrawText("5 = Trayectoria", 20, 140, 20, PURPLE);
        DrawText("6 = Orbita", 20, 170, 20, GOLD);

        // Dibujos
        if (mode == 1) {

            DrawCircle(x, 350, 30, GREEN);
        }

        else if (mode == 2) {

            Rectangle rect = {450, 300, 100, 100};

            DrawRectanglePro(
                rect,
                {50, 50},
                angle,
                SKYBLUE
            );
        }

        else if (mode == 3) {

            DrawCircle(x, y, 30, RED);
        }

        else if (mode == 4) {

            DrawCircle(x, y, 30, ORANGE);
        }

        else if (mode == 5) {

            DrawCircle(x, y, 30, PURPLE);
        }

        else if (mode == 6) {

            DrawCircle(500, 350, 40, YELLOW);

            DrawCircle(x, y, 20, GOLD);

            DrawCircleLines(500, 350, 150, GRAY);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}