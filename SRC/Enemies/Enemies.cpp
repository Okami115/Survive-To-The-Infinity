#include "Enemies.h"

#include <iostream>
#include "../../LIB/INCLUDE/raylib.h"
#include "../../LIB/INCLUDE/raymath.h"

extern Rectangle player;
extern int velocity;

extern bool isInTheLeft;
extern bool isInTheTop;
extern bool isInTheRight;
extern bool isInTheBottom;


const int maxEnemies = 3;

int EnemiesVelocity = 300;

Texture EnemyBig;

Rectangle enemies[maxEnemies];
Rectangle enemiesSource[maxEnemies];
Vector2 enemiesTrayectory[maxEnemies];

void enemiesUpdate()
{

	for (int i = 0; i < maxEnemies; i++)
	{
		Vector2 normalDir = { 0,0 };
		Vector2 Dif = { 0,0 };

		Dif.x = enemies[i].x - player.x;
		Dif.y = enemies[i].y - player.y;

        if (Dif.x == 0 && Dif.y == 0)
        {
            enemies[i].x = (static_cast <float>(rand() % GetScreenWidth())) * 2;
            enemies[i].y = (static_cast <float>(rand() % GetScreenHeight())) * 2;
        } 
        else
        {

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
        }


        
	}

}

void enemiesDraw()
{
    for (int i = 0; i < maxEnemies; i++)
    {
        DrawRectangle(enemies[i].x, enemies[i].y, enemies[i].width, enemies[i].height, RED);
        Vector2 EnemiesOrigin{ 0, 0};
        DrawTexturePro(EnemyBig, enemiesSource[i], enemies[i], EnemiesOrigin, 0, WHITE);
    }
}

void enemiesSpawn()
{

    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i].x = (static_cast <float>(rand() % GetScreenWidth())) * 2;
        enemies[i].y = (static_cast <float>(rand() % GetScreenHeight())) * 2;

        enemiesSource[i] = { 0, 0, 40, 40 };

        enemies[i].width = 80;
        enemies[i].height = 80;
    }
}