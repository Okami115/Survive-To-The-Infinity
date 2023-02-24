#include "CoreLoop.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Player/Player.h"
#include "../Enemies/Enemies.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../Buttons/Buttons.h"
#include "../HUD/HUD.h"

#include "../Play/Play.h"
#include "../MainMenu/MainMenu.h"

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

float screenWidth = 600;
float screenHeight = 800;

int selectScreen = 0;

void initWindow()
{
    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.5");

    SetExitKey(KEY_NULL);

    InitAudioDevice();
}

void initGame()
{
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
}

void game()
{
    initWindow();
    initGame();

    while (!WindowShouldClose())
    {
        switch (selectScreen)
        {
            case 0:
            {
                menuUpdate();
                break;
            }

            case 1:
            {
                playUpdate();
                break;
            }

            case 2:
            {
                break;
            }

            case 3:
            {
                break;
            }

            case 4:
            {
                break;
            }

            case 5:
            {
                break;
            }
        default:
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (selectScreen)
        {
        case 0:
        {
            menuDraw();
            break;
        }

        case 1:
        {
            playDraw();
            break;
        }

        case 2:
        {
            break;
        }

        case 3:
        {
            break;
        }

        case 4:
        {
            break;
        }

        case 5:
        {
            break;
        }
        default:
            break;
        }

        EndDrawing();
    }

    closeGame();
}

void closeGame()
{
    UnloadTexture(ground);
    UnloadTexture(player.currentTexture);
    UnloadTexture(playerFront);
    UnloadTexture(playerBack);
    UnloadTexture(playerSideLeft);
    UnloadTexture(playerSideRight);
    UnloadTexture(BigEnemy);
    UnloadTexture(MediumEnemy);
    UnloadTexture(LittleEnemy);
    UnloadTexture(normalButton);
    UnloadTexture(SelectButton);
    UnloadTexture(BlockedButton);

    CloseAudioDevice();
    CloseWindow();
}