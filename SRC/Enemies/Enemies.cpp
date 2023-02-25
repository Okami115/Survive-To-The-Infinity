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

Texture BigEnemy;
Texture MediumEnemy;
Texture LittleEnemy;

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

	    enemies[i].pos.x -= enemies[i].trayectory.x * enemies[i].velocity * GetFrameTime();
	    enemies[i].pos.y -= enemies[i].trayectory.y * enemies[i].velocity * GetFrameTime();

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

            if (Bullets[j].isTravelling && CheckCollisionCircleRec(BulletsPos,Bullets[j].radius, enemies[i].dest))
            {

                Bullets[j].x = player.pos.x;
                Bullets[j].y = player.pos.y;
                Bullets[j].isTravelling = false;
                
                enemies[i].lives--;


                if (enemies[i].lives <= 0)
                {
                    enemiesSpawn(enemies[i]);
                    player.currentExperience = player.currentExperience + enemies[i].id + 1;
                    player.score = player.score + (i + 1) * 100;
                }

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
        //DrawRectangle(enemies[i].dest.x, enemies[i].dest.y, enemies[i].dest.width, enemies[i].dest.height, RED);
        Vector2 EnemiesOrigin{ 0, 0};
        DrawTexturePro(enemies[i].currentTexture, enemies[i].source, enemies[i].dest, EnemiesOrigin, 0, WHITE);
    }
}

void initEnemies()
{

    for (int i = 0; i < maxEnemies; i++)
    {
        enemiesSpawn(enemies[i]);
    }
}

void enemiesSpawn(Enemy& enemy)
{
    int selectPos = rand()% 4;

    enemy.id = rand() % 3;

    if (enemy.id == 0)
    {
        enemy.lives = 1;
        enemy.velocity = 500;
        enemy.currentTexture = LittleEnemy;
        enemy.source = { 0, 0, 20, 20 };
        enemy.damage = 5;

        enemy.dest.width = 40;
        enemy.dest.height = 40;
    }
    if (enemy.id == 1)
    {
        enemy.lives = 2;
        enemy.velocity = 300;
        enemy.currentTexture = MediumEnemy;
        enemy.source = { 0, 0, 20, 30 };
        enemy.damage = 7;

        enemy.dest.width = 40;
        enemy.dest.height = 60;
    }
    if (enemy.id == 2)
    {
        enemy.lives = 3;
        enemy.velocity = 100;
        enemy.currentTexture = BigEnemy;
        enemy.source = { 0, 0, 40, 40 };
        enemy.damage = 10;

        enemy.dest.width = 80;
        enemy.dest.height = 80;
    }


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