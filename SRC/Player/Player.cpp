#include "Player.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../Enemies/Enemies.h"


extern int screenHeight;
extern int screenWidth;

extern Rectangle Background1;
extern Vector2 topLeft;
extern Vector2 bottomRight;

const int maxEnemies = 5;
extern int currentEnemies;
extern Rectangle enemies[maxEnemies];

extern bool isPaused;


int maxExperience = 5;
float experienceEscalation = 1.3f;

int playerLives = 3;
int currentExperience = 0;
int playerVelocity = 500;
float rateFire = 0.1f;
int collisionRadius = 30;

bool isChoosing = false;

Texture playerCurrentTexture;

Texture playerFront;
Texture playerBack;
Texture playerSideLeft;
Texture playerSideRight;

int Rotation = 0;

Rectangle player{ screenWidth / 2 - 30, screenHeight / 2 - 30, 60, 60 };
Rectangle playerSource{ 0, 0, 30, 30 };
Rectangle camera{ 0, 0, screenWidth, screenHeight };

void playerUpdate()
{
    shoot();

    if (currentExperience >= maxExperience)
    {
        levelUp();
    }

    if (IsKeyDown(KEY_W))
    {
        playerCurrentTexture = playerBack;
    }
    if (IsKeyDown(KEY_S))
    {
        playerCurrentTexture = playerFront;
    }
    if (IsKeyDown(KEY_A))
    {
        playerCurrentTexture = playerSideLeft;
    }
    if (IsKeyDown(KEY_D))
    {
        playerCurrentTexture = playerSideRight;
    }

    for (int i = 0; i < currentEnemies; i++)
    {
        if (CheckCollisionRecs(player, enemies[i]))
        {
            playerLives--;
            enemiesSpawn(enemies[i]);
        }
    }

}

void playerDraw()
{
    //DrawRectangle(player.x, player.y, player.width, player.height, BLUE);
    Vector2 PlayerPos{ 0, 0 };
    DrawTexturePro(playerCurrentTexture, playerSource, player, PlayerPos, Rotation, WHITE);

}

void levelUp()
{
    currentExperience = 0;
    maxExperience = maxExperience * experienceEscalation;
    isPaused = true;
    isChoosing = true;

}

