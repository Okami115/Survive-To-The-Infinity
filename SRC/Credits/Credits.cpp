#include "Credits.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;
extern Texture Background;

void creditsUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}
}

void creditsDraw()
{
	DrawTexture(Background, 0, 0, WHITE);
}