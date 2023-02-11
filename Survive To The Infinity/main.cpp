#include "../LIB/INCLUDE/raylib.h"
#include "../SRC/Player/Player.h"
#include "../SRC/Enemies/Enemies.h"
#include "../SRC/Ground/Ground.h"


int screenWidth = 600;
int screenHeight = 800;

extern Texture ground;

extern Texture playerCurrentTexture;
extern Texture playerFront;
extern Texture playerBack;
extern Texture playerSideLeft;
extern Texture playerSideRight;

extern Texture EnemyBig;

int main()
{

    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.1");
           
    ground = LoadTexture("../RES/Ground.png");
    playerCurrentTexture = LoadTexture("../RES/PlayerFront.png");
    playerFront = LoadTexture("../RES/PlayerFront.png");
    playerBack = LoadTexture("../RES/PlayerBack.png");
    playerSideLeft = LoadTexture("../RES/PlayerSideleft.png");
    playerSideRight = LoadTexture("../RES/PlayerSideRight.png");
    EnemyBig = LoadTexture("../RES/EnemyBig.png");

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




