#include "../LIB/INCLUDE/raylib.h"

#include "../SRC/Player/Player.h"
#include "../SRC/Enemies/Enemies.h"
#include "../SRC/Ground/Ground.h"
#include "../SRC/Bullets/Bullets.h"
#include "../SRC/ChoiceMenu/ChoiceMenu.h"
#include "../SRC/Buttons/Buttons.h"
#include "../SRC/HUD/HUD.h"


float screenWidth = 600;
float screenHeight = 800;

extern bool isChoosing;

extern Texture ground;

extern Player player;

extern Texture playerFront;
extern Texture playerBack;
extern Texture playerSideLeft;
extern Texture playerSideRight;

extern Texture BigEnemy;
extern Texture MediumEnemy;
extern Texture LittleEnemy;

extern Texture normalButton;
extern Texture SelectButton;
extern Texture BlockedButton;

bool isPaused = false;


int main()
{
    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.5");

    SetExitKey(KEY_NULL);

    ground = LoadTexture("../RES/Ground.png");
    player.currentTexture = LoadTexture("../RES/PlayerFront.png");
    playerFront = LoadTexture("../RES/PlayerFront.png");
    playerBack = LoadTexture("../RES/PlayerBack.png");
    playerSideLeft = LoadTexture("../RES/PlayerSideleft.png");
    playerSideRight = LoadTexture("../RES/PlayerSideRight.png");

    BigEnemy = LoadTexture("../RES/big_enemy.png");
    MediumEnemy = LoadTexture("../RES/medium_enemy.png");
    LittleEnemy = LoadTexture("../RES/little_enemy.png");

    normalButton = LoadTexture("../RES/Button.png");
    SelectButton = LoadTexture("../RES/GreenButton.png");
    BlockedButton = LoadTexture("../RES/RedButton.png");

    initPlayer();
    initEnemies();
    initBullets();
    initButtons();
    initHUD();

    while (!WindowShouldClose())    
    {
        if (!isPaused)
        {
            playerUpdate();

            backgroundUpdate();

            enemiesUpdate();

            bulletsUpdate();
        }

        if (IsKeyReleased(KEY_ESCAPE) && !isChoosing)
        {
            if (isPaused)
            {
                isPaused = false;
            }
            else
            {
                isPaused = true;
            }
        }

        choiceMenuUpdate();

        hudUpdate();

        BeginDrawing();

        ClearBackground(BLACK);
        
        backgroundDraw();

        bulletsDraw();

        playerDraw();

        enemiesDraw();

        choiceMenuDraw();

        hudDraw();

        EndDrawing();
        
    }


    CloseWindow();       
}




