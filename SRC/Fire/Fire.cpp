#include "Fire.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Player/Player.h"

namespace OkamiIndustries
{

	extern Player player;

	extern Texture playerFront;
	extern Texture playerBack;
	extern Texture playerSideLeft;
	extern Texture playerSideRight;

	extern bool isShooting;

	Texture fireFront;
	Texture fireBack;
	Texture fireLeft;
	Texture fireRight;

	static Texture currentTexture;

	void fireUpdate()
	{
		if (IsKeyDown(KEY_UP))
		{
			player.currentTexture = playerBack;
			currentTexture = fireBack;
		}
		else if (IsKeyDown(KEY_LEFT))
		{
			player.currentTexture = playerSideLeft;
			currentTexture = fireLeft;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			player.currentTexture = playerFront;
			currentTexture = fireFront;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			player.currentTexture = playerSideRight;
			currentTexture = fireRight;
		}
	}

	void fireDraw()
	{
		Vector2 origin = { 0, 0 };

		if (isShooting)
		{
			DrawTexturePro(currentTexture, player.source, player.dest, origin, 0, WHITE);
		}


	}
}


