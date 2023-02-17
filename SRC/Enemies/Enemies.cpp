#include "Enemies.h"

#include <iostream>
#include "../../LIB/INCLUDE/raylib.h"
#include "../../LIB/INCLUDE/raymath.h"
#include "../Bullets/Bullets.h"

extern Rectangle player;
extern int velocity;

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

Rectangle enemies[maxEnemies];
Rectangle enemiesSource[maxEnemies];
Vector2 enemiesTrayectory[maxEnemies];

void enemiesUpdate()
{

	for (int i = 0; i < currentEnemies; i++)
	{
		Vector2 normalDir = { 0,0 };
		Vector2 Dif = { 0,0 };

		Dif.x = enemies[i].x - player.x;
		Dif.y = enemies[i].y - player.y;


	    float Module = static_cast <float>(sqrt(pow(Dif.x, 2) + pow(Dif.y, 2)));

	    normalDir = { Dif.x / Module, Dif.y / Module };

	    enemiesTrayectory[i] = normalDir;


        for (int j = 0; j < maxEnemies; j++)
        {
            if (i != j && CheckCollisionRecs(enemies[i], enemies[j]))
            {
            
            }
        }

	    enemies[i].x -= enemiesTrayectory[i].x * EnemiesVelocity * GetFrameTime();
	    enemies[i].y -= enemiesTrayectory[i].y * EnemiesVelocity * GetFrameTime();

        if (IsKeyDown(KEY_W) && !isInTheTop)
        {
            enemies[i].y = enemies[i].y + velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_A) && !isInTheLeft)
        {
            enemies[i].x = enemies[i].x + velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_S) && !isInTheBottom)
        {
            enemies[i].y = enemies[i].y - velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_D) && !isInTheRight)
        {
            enemies[i].x = enemies[i].x - velocity * GetFrameTime();
        }
        

        for (int j = 0; j < maxBullets; j++)
        {
            Vector2 BulletsPos = { Bullets[j].x, Bullets[j].y };

            if (CheckCollisionCircleRec(BulletsPos,Bullets[j].radius, enemies[i]))
            {
                enemiesSpawn(enemies[i]);

                Bullets[j].x = player.x + player.width / 2;
                Bullets[j].y = player.y + player.height / 2;
                Bullets[j].isTravelling = false;

                if (currentEnemies < maxEnemies)
                {
                   currentEnemies++;
                }
            }
        }
	}
}

void enemiesDraw()
{
    for (int i = 0; i < currentEnemies; i++)
    {
        //DrawRectangle(enemies[i].x, enemies[i].y, enemies[i].width, enemies[i].height, RED);
        Vector2 EnemiesOrigin{ 0, 0};
        DrawTexturePro(EnemyBig, enemiesSource[i], enemies[i], EnemiesOrigin, 0, WHITE);
    }
}

void initEnemies()
{

    for (int i = 0; i < maxEnemies; i++)
    {
        enemiesSpawn(enemies[i]);

        enemiesSource[i] = { 0, 0, 40, 40 };

        enemies[i].width = 80;
        enemies[i].height = 80;
    }
}

void enemiesSpawn(Rectangle& enemy)
{
    int selectPos = rand()% 4;

    if (selectPos == 0)
    {
        enemy.x = (static_cast <float>(rand() % GetScreenWidth()));
        enemy.y = GetScreenHeight() + (enemy.height * 2);

    }

    if (selectPos == 1)
    {
        enemy.x = (static_cast <float>(rand() % GetScreenWidth()));
        enemy.y = 0 - (enemy.height * 2);

    }

    if (selectPos == 2)
    {
        enemy.x = GetScreenWidth() + (enemy.width * 2);
        enemy.y = (static_cast <float>(rand() % GetScreenHeight()));

    }

    if (selectPos == 3)
    {
        enemy.x = 0 - (enemy.width * 2);
        enemy.y = (static_cast <float>(rand() % GetScreenHeight()));

    }
}