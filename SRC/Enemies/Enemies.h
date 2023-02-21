#pragma once
#include "../../LIB/INCLUDE/raylib.h"
#include <iostream>


struct Enemy
{
	int velocity;

	int id;

	Vector2 pos;

	Texture currentTexture;

	Rectangle dest;
	Rectangle source;
	Vector2 trayectory;
};

void initEnemies();

void enemiesUpdate();
void enemiesDraw();
void enemiesSpawn(Enemy& enemy);
