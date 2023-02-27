#include "Bullets.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../../LIB/INCLUDE/raymath.h"
#include "../Player/Player.h"

extern Player player;

extern bool isInTheLeft;
extern bool isInTheTop;
extern bool isInTheRight;
extern bool isInTheBottom;

const int maxBullets = 100;

float timerBullets = 0;

bool isShooting = false;

int currentBullets = 0;
int bulletsVelocity = 2000;

Bullet Bullets[maxBullets];

Texture textureBullet;

Sound Shoot;


void bulletsUpdate()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (Bullets[i].isTravelling) 
		{
			Bullets[i].x -= Bullets[i].bulletsTrayectory.x * bulletsVelocity * GetFrameTime();
			Bullets[i].y -= Bullets[i].bulletsTrayectory.y * bulletsVelocity * GetFrameTime();

			if (IsKeyDown(KEY_W) && !isInTheTop)
			{
				Bullets[i].y = Bullets[i].y + player.velocity * GetFrameTime();
			}
			if (IsKeyDown(KEY_A) && !isInTheLeft)
			{
				Bullets[i].x = Bullets[i].x + player.velocity * GetFrameTime();
			}
			if (IsKeyDown(KEY_S) && !isInTheBottom)
			{
				Bullets[i].y = Bullets[i].y - player.velocity * GetFrameTime();
			}
			if (IsKeyDown(KEY_D) && !isInTheRight)
			{
				Bullets[i].x = Bullets[i].x - player.velocity * GetFrameTime();
			}

			if (Bullets[i].x < 0 || Bullets[i].y < 0 || Bullets[i].x > GetScreenWidth() || Bullets[i].y > GetScreenHeight())
			{
				Bullets[i].x = player.pos.x;
				Bullets[i].y = player.pos.y;
				Bullets[i].isTravelling = false;

				isShooting = false;
			}
		}
	}
}

void bulletsDraw()
{
	for (int i = 0; i < maxBullets; i++)
	{
		DrawTexture(textureBullet, Bullets[i].x - Bullets[i].radius, Bullets[i].y - Bullets[i].radius, WHITE);
	}
}


void shoot()
{
	
	timerBullets = timerBullets + GetFrameTime();

	if (timerBullets > player.rateFire)
	{
		if (IsKeyDown(KEY_UP))
		{
			Bullets[currentBullets].bulletsTrayectory = { 0.0f, 1.0f };
			Bullets[currentBullets].isTravelling = true;

			isShooting = true;
			PlaySound(Shoot);

			currentBullets++;
		}
		else if (IsKeyDown(KEY_LEFT))
		{
			Bullets[currentBullets].bulletsTrayectory = { 1.0f, 0.0f };
			Bullets[currentBullets].isTravelling = true;

			isShooting = true;
			PlaySound(Shoot);

			currentBullets++;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			Bullets[currentBullets].bulletsTrayectory = { 0.0f, -1.0f };
			Bullets[currentBullets].isTravelling = true;

			isShooting = true;
			PlaySound(Shoot);

			currentBullets++;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			Bullets[currentBullets].bulletsTrayectory = { -1.0f, 0.0f };
			Bullets[currentBullets].isTravelling = true;

			isShooting = true;
			PlaySound(Shoot);

			currentBullets++;
		}

		timerBullets = 0;
	}

	if (currentBullets == 100)
	{
		currentBullets = 0;
	}

}


void initBullets()
{
	for (int i = 0; i < maxBullets; i++)
	{
		Bullets[i].radius = 5;
		Bullets[i].x = player.pos.x;
		Bullets[i].y = player.pos.y;
		Bullets[i].isTravelling = false;
	}
}