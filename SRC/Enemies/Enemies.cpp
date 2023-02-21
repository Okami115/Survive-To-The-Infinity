#include "Enemies.h"

#include <iostream>
#include "../../LIB/INCLUDE/raylib.h"
#include "../../LIB/INCLUDE/raymath.h"
#include "../Bullets/Bullets.h"
#include "../Player/Player.h"

extern Player player;

const int maxBullets = 100;
extern Bullet Bullets[maxBullets];

extern bool isInTheLeft;
extern bool isInTheTop;
extern bool isInTheRight;
extern bool isInTheBottom;

const int maxEnemies = 5;

int currentEnemies = 1;

int EnemiesVelocity = 300;

Texture EnemyBig;

Enemy enemies[maxEnemies];

void enemiesUpdate()
{

	for (int i = 0; i < currentEnemies; i++)
	{
		Vector2 normalDir = { 0,0 };
		Vector2 Dif = { 0,0 };

		Dif.x = enemies[i].pos.x - player.pos.x;
		Dif.y = enemies[i].pos.y - player.pos.y;


	    float Module = static_cast <float>(sqrt(pow(Dif.x, 2) + pow(Dif.y, 2)));

	    normalDir = { Dif.x / Module, Dif.y / Module };

	    enemies[i].trayectory = normalDir;

	    enemies[i].pos.x -= enemies[i].trayectory.x * EnemiesVelocity * GetFrameTime();
	    enemies[i].pos.y -= enemies[i].trayectory.y * EnemiesVelocity * GetFrameTime();

        if (IsKeyDown(KEY_W) && !isInTheTop)
        {
            enemies[i].pos.y = enemies[i].pos.y + player.velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_A) && !isInTheLeft)
        {
            enemies[i].pos.x = enemies[i].pos.x + player.velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_S) && !isInTheBottom)
        {
            enemies[i].pos.y = enemies[i].pos.y - player.velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_D) && !isInTheRight)
        {
            enemies[i].pos.x = enemies[i].pos.x - player.velocity * GetFrameTime();
        }

        for (int j = 0; j < maxBullets; j++)
        {
            Vector2 BulletsPos = { Bullets[j].x, Bullets[j].y };

            if (CheckCollisionCircleRec(BulletsPos,Bullets[j].radius, enemies[i].dest))
            {
                enemiesSpawn(enemies[i]);

                Bullets[j].x = player.pos.x;
                Bullets[j].y = player.pos.y;
                Bullets[j].isTravelling = false;
                player.currentExperience = player.currentExperience + 2;

                if (currentEnemies < maxEnemies)
                {
                   currentEnemies++;
                }
            }
        }

        enemies[i].dest.x = enemies[i].pos.x;
        enemies[i].dest.y = enemies[i].pos.y;

	}
}

void enemiesDraw()
{
    for (int i = 0; i < currentEnemies; i++)
    {
        DrawRectangle(enemies[i].dest.x, enemies[i].dest.y, enemies[i].dest.width, enemies[i].dest.height, RED);
        Vector2 EnemiesOrigin{ 0, 0};
        DrawTexturePro(enemies[i].currentTexture, enemies[i].source, enemies[i].dest, EnemiesOrigin, 0, WHITE);
    }
}

void initEnemies()
{

    for (int i = 0; i < maxEnemies; i++)
    {
        enemiesSpawn(enemies[i]);

        enemies[i].id = 0;

        if (enemies[i].id == 0)
        {
            enemies[i].currentTexture = EnemyBig;
            enemies[i].source = { 0, 0, 40, 40 };

            enemies[i].dest.width = 80;
            enemies[i].dest.height = 80;
        }
        if (enemies[i].id == 1)
        {
            enemies[i].currentTexture = EnemyBig;
            enemies[i].source = { 0, 0, 40, 40 };

            enemies[i].dest.width = 80;
            enemies[i].dest.height = 80;
        }
        if (enemies[i].id == 2)
        {
            enemies[i].currentTexture = EnemyBig;
            enemies[i].source = { 0, 0, 40, 40 };

            enemies[i].dest.width = 80;
            enemies[i].dest.height = 80;
        }
    }
}

void enemiesSpawn(Enemy& enemy)
{
    int selectPos = rand()% 4;

    if (selectPos == 0)
    {
        enemy.pos.x = (static_cast <float>(rand() % GetScreenWidth()));
        enemy.pos.y = GetScreenHeight() + (enemy.dest.height * 2);

    }

    if (selectPos == 1)
    {
        enemy.pos.x = (static_cast <float>(rand() % GetScreenWidth()));
        enemy.pos.y = 0 - (enemy.dest.height * 2);

    }

    if (selectPos == 2)
    {
        enemy.pos.x = GetScreenWidth() + (enemy.dest.width * 2);
        enemy.pos.y = (static_cast <float>(rand() % GetScreenHeight()));

    }

    if (selectPos == 3)
    {
        enemy.pos.x = 0 - (enemy.dest.width * 2);
        enemy.pos.y = (static_cast <float>(rand() % GetScreenHeight()));

    }
}