#include "Player.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../Enemies/Enemies.h"


extern float screenHeight;
extern float screenWidth;

extern Rectangle Background1;
extern Vector2 topLeft;
extern Vector2 bottomRight;

const int maxEnemies = 5;
extern int currentEnemies;
extern Enemy enemies[maxEnemies];

extern bool isPaused;

extern bool playSound;

static float timer = 0;
static int currentFrame = 1;

bool isChoosing = false;

float experienceEscalation = 1.3f;

Texture playerFront;
Texture playerBack;
Texture playerSideLeft;
Texture playerSideRight;

Sound Hurt;

Player player;

void playerUpdate()
{
    if (player.currentExperience >= player.maxExperience)
    {
        levelUp();
    }

    if (IsKeyDown(KEY_W))
    {
        player.currentTexture = playerBack;
        timer = timer + player.velocity * GetFrameTime();
    }
    else if (IsKeyDown(KEY_S))
    {
        player.currentTexture = playerFront;
        timer = timer + player.velocity * GetFrameTime();
    }
    else if (IsKeyDown(KEY_A))
    {
        player.currentTexture = playerSideLeft;
        timer = timer + player.velocity * GetFrameTime();
    }
    else if (IsKeyDown(KEY_D))
    {
        player.currentTexture = playerSideRight;
        timer = timer + player.velocity * GetFrameTime();
    }
    else
    {
        currentFrame = 0;
    }

    if (timer > 100)
    {
        timer = 0;
        currentFrame++;

        if (currentFrame > 4)
        {
            currentFrame = 1;
        }

    }

    for (int i = 0; i < currentEnemies; i++)
    {
        if (CheckCollisionCircleRec(player.pos, player.collisionRadius, enemies[i].dest))
        {
            player.lives = player.lives - enemies[i].damage;
            PlaySound(Hurt);
            enemiesSpawn(enemies[i]);
        }
    }

    if (player.lives <= 0)
    {
        playSound = true;
    }

    shoot();

    player.source.x = ((float)player.currentTexture.width / 4) * currentFrame;
    player.dest = { player.pos.x - (float)player.collisionRadius, player.pos.y - (float)player.collisionRadius, (float)player.collisionRadius * 2, (float)player.collisionRadius * 2 };

}

void playerDraw()
{
    Vector2 originPlayerPos{ 0, 0 };
    DrawTexturePro(player.currentTexture, player.source, player.dest, originPlayerPos, player.rotation, WHITE);

}

void levelUp()
{
    player.currentExperience = 0;
    player.maxExperience = player.maxExperience * experienceEscalation;
    isPaused = true;
    isChoosing = true;
    playSound = true;
}

void initPlayer()
{
    player.maxLives = 100;
    player.lives = player.maxLives;

    player.maxExperience = 5;
    player.currentExperience = 0;

    player.velocity = 300;

    player.rateFire = 0.5f;

    player.collisionRadius = 40;

    player.rotation = 0;

    player.score = 0;

    player.currentTexture;

    player.camera = { 0, 0, (float)screenWidth, (float)screenHeight };

    player.source = { 0, 0, (float)player.currentTexture.width / 4, 30};

    player.pos = { (float)screenWidth / 2, (float)screenHeight / 2};

    player.dest = { player.pos.x - (float)player.collisionRadius, player.pos.y - (float)player.collisionRadius, (float)player.collisionRadius * 2,  (float)player.collisionRadius * 2};
}