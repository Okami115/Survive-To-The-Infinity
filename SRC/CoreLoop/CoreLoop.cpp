#include "CoreLoop.h"

#include "../../LIB/INCLUDE/raylib.h"

#include "../Player/Player.h"
#include "../Enemies/Enemies.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../Buttons/Buttons.h"
#include "../HUD/HUD.h"
#include "../Cursor/Cursor.h"

#include "../MainMenu/MainMenu.h"
#include "../Play/Play.h"
#include "../Options/Options.h"
#include "../HowToPlay/HowToPlay.h"
#include "../Credits/Credits.h"
#include "../Exit/Exit.h"

extern Texture ground;
extern Texture mainMenuBackground;

extern Texture cursor;
extern Texture cursorClicked;

extern Player player;

extern Texture textureBullet;

extern Texture fireFront;
extern Texture fireLeft;
extern Texture fireRight;

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

Music mainMenuMusic;
Music gameMusic;

extern Sound Shoot;
extern Sound Defeat;
extern Sound LevelUp;
extern Sound Hurt;
extern Sound Kill;

float screenWidth = 600;
float screenHeight = 800;

int selectScreen = 0;
bool isRunning = true;

void initWindow()
{
    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.6");

    SetExitKey(KEY_NULL);

    HideCursor();

    InitAudioDevice();
}

void initGame()
{
    ground = LoadTexture("../RES/Assets/Ground.png");
    mainMenuBackground = LoadTexture("../RES/Assets/MainBackground.png");
    Background = LoadTexture("../RES/Assets/Background.png");

    cursor = LoadTexture("../RES/Assets/cursor.png");
    cursorClicked = LoadTexture("../RES/Assets/cursorClicked.png");

    textureBullet = LoadTexture("../RES/Assets/bullet.png");
    fireFront = LoadTexture("../RES/Assets/playerFireFront.png");
    fireLeft = LoadTexture("../RES/Assets/playerFireLeft.png");
    fireRight = LoadTexture("../RES/Assets/playerFireRight.png");

    player.currentTexture = LoadTexture("../RES/Assets/playerWalkFront.png");
    playerFront = LoadTexture("../RES/Assets/playerWalkFront.png");
    playerBack = LoadTexture("../RES/Assets/playerWalkBack.png");
    playerSideLeft = LoadTexture("../RES/Assets/playerWalkLeft.png");
    playerSideRight = LoadTexture("../RES/Assets/playerWalkRight.png");

    BigEnemy = LoadTexture("../RES/Assets/bigEnemy.png");
    MediumEnemy = LoadTexture("../RES/Assets/mediumEnemy.png");
    LittleEnemy = LoadTexture("../RES/Assets/littleEnemy.png");

    normalButton = LoadTexture("../RES/Assets/Button.png");
    SelectButton = LoadTexture("../RES/Assets/GreenButton.png");
    BlockedButton = LoadTexture("../RES/Assets/RedButton.png");

    mainMenuMusic = LoadMusicStream("../RES/Music/mainMenuMusic.mp3");
    gameMusic = LoadMusicStream("../RES/Music/gameMusic.mp3");

    Shoot = LoadSound("../RES/SFX/Shoot.wav");
    Defeat = LoadSound("../RES/SFX/defeat.wav");
    LevelUp = LoadSound("../RES/SFX/levelUp.wav");
    Hurt = LoadSound("../RES/SFX/hurt.wav");
    Kill = LoadSound("../RES/SFX/kill.wav");

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

    PlayMusicStream(mainMenuMusic);
    PlayMusicStream(gameMusic);
    SetMusicVolume(mainMenuMusic, 0.01f);
    SetMusicVolume(gameMusic, 0.01f);

    while (!WindowShouldClose() && isRunning)
    {
        cursorUpdate();

        if (selectScreen == 1)
        {
            PauseMusicStream(mainMenuMusic);
            PlayMusicStream(gameMusic);

        }
        else
        {
            PauseMusicStream(gameMusic);
            PlayMusicStream(mainMenuMusic);
        }

        UpdateMusicStream(gameMusic);
        UpdateMusicStream(mainMenuMusic);

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

        cursorDraw();
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