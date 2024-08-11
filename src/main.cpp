#include <raylib.h>
#include <iostream>
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

int main()
{
    InitWindow(500, 620, "My first Tetris! - Fabrizio");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/Minecraftia-Regular.ttf", 64, 0, 0);

    Game game = Game();
    
    // True if you press 'X' window button or escape
    while (WindowShouldClose() == false)
    {   
        game.HandleInput();
        
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        // Creates a blank canvas so we can draw our game objects
        BeginDrawing();

        // Paints the screen of the given color
        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
            DrawTextEx(font, "Press any", {320, 510}, 38, 2, WHITE);
            DrawTextEx(font, "key to", {350, 540}, 38, 2, WHITE);
            DrawTextEx(font, "restart...", {325, 570}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.Draw();

        // Ends the canvas drawing
        EndDrawing();
    }

    CloseWindow();

    return 0;
}