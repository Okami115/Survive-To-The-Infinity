#include "Bullets.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../../LIB/INCLUDE/raymath.h"

extern Rectangle player;

extern int velocity;

extern bool isInTheLeft;
extern bool isInTheTop;
extern bool isInTheRight;
extern bool isInTheBottom;

const int maxBullets = 100;

float timer = 0;
float rateFire = 0.1f;

int currentBullets = 0;
int bulletsVelocity = 1000;


struct Bullet
{
	float x;
	float y;
	int radius;
	Vector2 bulletsTrayectory;
	bool isTravelling;
};

Bullet Bullets[maxBullets];

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
				Bullets[i].y = Bullets[i].y + velocity * GetFrameTime();
			}
			if (IsKeyDown(KEY_A) && !isInTheLeft)
			{
				Bullets[i].x = Bullets[i].x + velocity * GetFrameTime();
			}
			if (IsKeyDown(KEY_S) && !isInTheBottom)
			{
				Bullets[i].y = Bullets[i].y - velocity * GetFrameTime();
			}
			if (IsKeyDown(KEY_D) && !isInTheRight)
			{
				Bullets[i].x = Bullets[i].x - velocity * GetFrameTime();
			}

			if (Bullets[i].x < 0 || Bullets[i].y < 0 || Bullets[i].x > GetScreenWidth() || Bullets[i].y > GetScreenHeight())
			{
				Bullets[i].x = player.x + player.width / 2;
				Bullets[i].y = player.y + player.height / 2;
				Bullets[i].isTravelling = false;
			}
		}
	}
}

void bulletsDraw()
{
	for (int i = 0; i < maxBullets; i++)
	{
		DrawCircle(Bullets[i].x, Bullets[i].y, Bullets[i].radius, SKYBLUE);
	}
}


void shoot()
{
	
	timer = timer + GetFrameTime();
	if (timer > rateFire)
	{
		if (IsKeyDown(KEY_UP))
		{
			Bullets[currentBullets].bulletsTrayectory = { 0.0f, 1.0f };
			Bullets[currentBullets].isTravelling = true;

			currentBullets++;
		}
		else if (IsKeyDown(KEY_LEFT))
		{
			Bullets[currentBullets].bulletsTrayectory = { 1.0f, 0.0f };
			Bullets[currentBullets].isTravelling = true;

			currentBullets++;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			Bullets[currentBullets].bulletsTrayectory = { 0.0f, -1.0f };
			Bullets[currentBullets].isTravelling = true;

			currentBullets++;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			Bullets[currentBullets].bulletsTrayectory = { -1.0f, 0.0f };
			Bullets[currentBullets].isTravelling = true;

			currentBullets++;
		}

		timer = 0;
	}

	if (currentBullets == 100)
	{
		currentBullets = 0;
	}

}

void deleteBullets()
{

}

void initBullets()
{
	for (int i = 0; i < maxBullets; i++)
	{
		Bullets[i].radius = 5;
		Bullets[i].x = player.x + player.width / 2;
		Bullets[i].y = player.y + player.height / 2;
		Bullets[i].isTravelling = false;
	}
}