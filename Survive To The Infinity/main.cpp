#include "../LIB/INCLUDE/raylib.h"
#include "../SRC/Player/Player.h"
#include "../SRC/Ground/Ground.h"


int screenWidth = 600;
int screenHeight = 800;

int velocity = 500;

extern Texture ground;
extern Texture playerTex;

int main()
{

    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.1");
           
    ground = LoadTexture("../RES/Ground.png");
    playerTex = LoadTexture("../RES/Player.png");

    while (!WindowShouldClose())    
    {
        playerUpdate();

        backgroundUpdate();


        BeginDrawing();

        ClearBackground(BLACK);
        
        backgroundDraw();

        playerDraw();

        DrawText("V0.1", 0, 0, 5, RED);

        EndDrawing();
        
    }


    CloseWindow();       
}




