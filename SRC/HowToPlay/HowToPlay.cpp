#include "HowToPlay.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;

extern Texture Background;

void howToPlayUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}
}

void howToPlayDraw()
{
	DrawTexture(Background, 0, 0, WHITE);
}