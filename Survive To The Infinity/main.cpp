#include "../LIB/INCLUDE/raylib.h"
#include "../SRC/Player/Player.h"
#include "../SRC/Enemies/Enemies.h"
#include "../SRC/Ground/Ground.h"
#include "../SRC/Bullets/Bullets.h"


int screenWidth = 600;
int screenHeight = 800;

extern Texture ground;

extern int playerLives;
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

    initEnemies();
    initBullets();

    while (!WindowShouldClose())    
    {
        playerUpdate();

        backgroundUpdate();

        enemiesUpdate();

        bulletsUpdate();


        BeginDrawing();

        ClearBackground(BLACK);
        
        backgroundDraw();

        playerDraw();

        enemiesDraw();

        bulletsDraw();

        DrawText("V0.1", 0, 0, 5, RED);
        DrawText(TextFormat("Lives: %i", playerLives), screenWidth - 100, 5, 25, RED);

        EndDrawing();
        
    }


    CloseWindow();       
}




