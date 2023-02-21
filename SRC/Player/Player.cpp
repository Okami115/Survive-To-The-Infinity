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
extern Enemy enemies[maxEnemies];

extern bool isPaused;


bool isChoosing = false;

int maxExperience = 5;
float experienceEscalation = 1.3f;

Texture playerFront;
Texture playerBack;
Texture playerSideLeft;
Texture playerSideRight;

Player player;

void playerUpdate()
{
    shoot();

    if (player.currentExperience >= maxExperience)
    {
        levelUp();
    }

    if (IsKeyDown(KEY_W))
    {
        player.currentTexture = playerBack;
    }
    if (IsKeyDown(KEY_S))
    {
        player.currentTexture = playerFront;
    }
    if (IsKeyDown(KEY_A))
    {
        player.currentTexture = playerSideLeft;
    }
    if (IsKeyDown(KEY_D))
    {
        player.currentTexture = playerSideRight;
    }

    for (int i = 0; i < currentEnemies; i++)
    {
        if (CheckCollisionCircleRec(player.pos, player.collisionRadius, enemies[i].dest))
        {
            player.lives--;
            enemiesSpawn(enemies[i]);
        }
    }

    player.dest = { player.pos.x - (float)player.collisionRadius, player.pos.y - (float)player.collisionRadius, (float)player.collisionRadius * 2,  (float)player.collisionRadius * 2 };

}

void playerDraw()
{
    Vector2 originPlayerPos{ 0, 0 };
    DrawTexturePro(player.currentTexture, player.source, player.dest, originPlayerPos, player.rotation, WHITE);

}

void levelUp()
{
    player.currentExperience = 0;
    maxExperience = maxExperience * experienceEscalation;
    isPaused = true;
    isChoosing = true;

}

void initPlayer()
{
    player.currentExperience = 0;

    player.lives = 3;

    player.velocity = 300;

    player.rateFire = 0.5f;

    player.collisionRadius = 40;

    player.rotation = 0;

    player.currentTexture;

    player.camera = { 0, 0, (float)screenWidth, (float)screenHeight };

    player.source = { 0, 0, 30, 30};

    player.pos = { (float)screenWidth / 2, (float)screenHeight / 2};

    player.dest = { player.pos.x - (float)player.collisionRadius, player.pos.y - (float)player.collisionRadius, (float)player.collisionRadius * 2,  (float)player.collisionRadius * 2};
}