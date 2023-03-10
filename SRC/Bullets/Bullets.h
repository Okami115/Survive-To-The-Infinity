#pragma once
#include "../../LIB/INCLUDE/raylib.h"

namespace OkamiIndustries
{

	struct Bullet
	{
		float x;
		float y;
		int radius;
		Vector2 bulletsTrayectory;
		bool isTravelling;
	};

	void bulletsUpdate();
	void bulletsDraw();

	void shoot();
	void initBullets();
}
