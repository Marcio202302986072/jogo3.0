#include <raylib.h>
#include "game.hpp"


int main()
{
    Color grey = {29,29,27,255};
    Color yellow = {243,216,63,255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth ,windowHeight,"lunaXmang");
    InitAudioDevice();
    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);
    Texture2D vidaImage = LoadTexture("vidac++luna.png");
    SetTargetFPS(60);

    game game;

    while(WindowShouldClose() == false){
        //UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        if(game.run){
        DrawTextEx(font, "Dificuldade: Luna", {0,0},34,2,yellow);
        }else{
            DrawTextEx(font, "GAME OVER", {0,0},34,2,yellow);
        }
        float x = 275.00;
        for (int i = 0; i < game.lives; i++) {
            DrawTextureV(vidaImage, {x, 0}, WHITE); 
            x += vidaImage.width + 10;
        }
        game.Draw();
        EndDrawing();
        
    }
    CloseAudioDevice();
    CloseWindow();
}