#include "Credits.h"

#include "../../LIB/INCLUDE/raylib.h"

extern float screenWidth;
extern float screenHeight;

extern Rectangle baseMenu;

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

	int TextWidth = MeasureText("Credits", 60);
	DrawText("Credits", screenWidth / 2 - TextWidth / 2, baseMenu.height / 10, 60, WHITE);

	int TextWidthESC = MeasureText("ESC to return to the menu", 20);
	DrawText("ESC to return to the menu", screenWidth / 2 - TextWidthESC / 2, (screenHeight / 10) * 9, 20, WHITE);
}