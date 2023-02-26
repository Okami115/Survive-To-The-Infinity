#include "Options.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;

extern Texture Background;

void optionsUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}

}

void optionsDraw()
{
	DrawTexture(Background, 0, 0, WHITE);
}