#include "../LIB/INCLUDE/raylib.h"
#include "../SRC/Player/Player.h"
#include "../SRC/Enemies/Enemies.h"
#include "../SRC/Ground/Ground.h"


int screenWidth = 600;
int screenHeight = 800;

extern Texture ground;
extern Texture playerFront;
extern Texture playerBack;
extern Texture playerSideLeft;
extern Texture playerSideRight;

int main()
{

    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.1");
           
    ground = LoadTexture("../RES/Ground.png");
    playerFront = LoadTexture("../RES/PlayerFront.png");
    playerBack = LoadTexture("../RES/PlayerBack.png");
    playerSideLeft = LoadTexture("../RES/PlayerSideleft.png");
    playerSideRight = LoadTexture("../RES/PlayerSideRight.png");

    enemiesSpawn();

    while (!WindowShouldClose())    
    {
        playerUpdate();

        backgroundUpdate();

        enemiesUpdate();


        BeginDrawing();

        ClearBackground(BLACK);
        
        backgroundDraw();

        playerDraw();

        enemiesDraw();

        DrawText("V0.1", 0, 0, 5, RED);

        EndDrawing();
        
    }


    CloseWindow();       
}




