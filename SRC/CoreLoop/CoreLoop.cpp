#include "CoreLoop.h"

#include "../../LIB/INCLUDE/raylib.h"

#include "../Player/Player.h"
#include "../Enemies/Enemies.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../Buttons/Buttons.h"
#include "../HUD/HUD.h"

#include "../MainMenu/MainMenu.h"
#include "../Play/Play.h"
#include "../Options/Options.h"
#include "../HowToPlay/HowToPlay.h"
#include "../Credits/Credits.h"
#include "../Exit/Exit.h"

extern Texture ground;
extern Texture mainMenuBackground;

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

Texture Background;

float screenWidth = 600;
float screenHeight = 800;

int selectScreen = 0;
bool isRunning = true;

void initWindow()
{
    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.6");

    SetExitKey(KEY_NULL);

    InitAudioDevice();
}

void initGame()
{
    ground = LoadTexture("../RES/Ground.png");
    mainMenuBackground = LoadTexture("../RES/MainBackground.png");
    Background = LoadTexture("../RES/Background.png");

    player.currentTexture = LoadTexture("../RES/playerWalkFront.png");
    playerFront = LoadTexture("../RES/playerWalkFront.png");
    playerBack = LoadTexture("../RES/playerWalkBack.png");
    playerSideLeft = LoadTexture("../RES/playerWalkLeft.png");
    playerSideRight = LoadTexture("../RES/playerWalkRight.png");

    BigEnemy = LoadTexture("../RES/bigEnemy.png");
    MediumEnemy = LoadTexture("../RES/mediumEnemy.png");
    LittleEnemy = LoadTexture("../RES/littleEnemy.png");

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

    while (!WindowShouldClose() && isRunning)
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
                optionsUpdate();
                break;
            }

            case 3:
            {
                howToPlayUpdate();
                break;
            }

            case 4:
            {
                creditsUpdate();
                break;
            }

            case 5:
            {
                exitUpdate();
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
            optionsDraw();
            break;
        }

        case 3:
        {
            howToPlayDraw();
            break;
        }

        case 4:
        {
            creditsDraw();
            break;
        }

        case 5:
        {
            exitDraw();
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