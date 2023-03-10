#pragma once
#include "../../LIB/INCLUDE/raylib.h"



namespace OkamiIndustries
{

	struct Player
	{
		int maxLives;
		int lives;

		int maxExperience;
		int currentExperience;

		int velocity;

		int score;

		float rateFire;

		int collisionRadius;

		int rotation;

		Texture currentTexture;

		Vector2 pos;

		Rectangle source;
		Rectangle dest;
		Rectangle camera;
	};

	void playerUpdate();
	void playerDraw(); 
	void levelUp();
	void initPlayer();
}