#include "Enemies.h"

#include <iostream>
#include "../../LIB/INCLUDE/raylib.h"
#include "../../LIB/INCLUDE/raymath.h"

extern Rectangle player;
extern int velocity;

const int maxEnemies = 3;

int EnemiesVelocity = 100;

Rectangle enemies[maxEnemies];
Vector2 enemiesTrayectory[maxEnemies];

void enemiesUpdate()
{

	for (int i = 0; i < maxEnemies; i++)
	{
		Vector2 normalDir = { 0,0 };
		Vector2 Dif = { 0,0 };

		Dif.x = enemies[i].x - player.x;
		Dif.y = enemies[i].y - player.y;

		float arcTan = static_cast <float>(atan(Dif.y / Dif.x));

		float Module = static_cast <float>(sqrt(pow(Dif.x, 2) + pow(Dif.y, 2)));

		normalDir = { Dif.x / Module, Dif.y / Module };

		enemiesTrayectory[i] = normalDir;

		enemies[i].x -= enemiesTrayectory[i].x * EnemiesVelocity * GetFrameTime();
		enemies[i].y -= enemiesTrayectory[i].y * EnemiesVelocity * GetFrameTime();

        if (IsKeyDown(KEY_W))
        {
            enemies[i].y = enemies[i].y + velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_A))
        {
            enemies[i].x = enemies[i].x + velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_S))
        {
            enemies[i].y = enemies[i].y - velocity * GetFrameTime();
        }
        if (IsKeyDown(KEY_D))
        {
            enemies[i].x = enemies[i].x - velocity * GetFrameTime();
        }
	}

}

void enemiesDraw()
{
    for (int i = 0; i < maxEnemies; i++)
    {
        DrawRectangle(enemies[i].x, enemies[i].y, enemies[i].width, enemies[i].height, RED);
    }
}

void enemiesSpawn()
{

    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i].x = (static_cast <float>(rand() % GetScreenWidth())) * 2;
        enemies[i].y = (static_cast <float>(rand() % GetScreenHeight())) * 2;

        enemies[i].width = 60;
        enemies[i].height = 60;
    }
}