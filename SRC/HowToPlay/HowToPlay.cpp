#include "HowToPlay.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;

extern float screenWidth;
extern float screenHeight;

extern Rectangle baseMenu;

Texture HowToPlayBackground;

void howToPlayUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}
}

void howToPlayDraw()
{
	DrawTexture(HowToPlayBackground, 0, 0, WHITE);

	int TextWidthTitle = MeasureText("How To Play", 50);
	DrawText("How To Play", screenWidth / 2 - TextWidthTitle / 2, baseMenu.height / 10, 50, WHITE);


	int TextWidthESC = MeasureText("ESC to return to the menu", 20);
	DrawText("ESC to return to the menu", screenWidth / 2 - TextWidthESC / 2, (screenHeight / 10) * 9 , 20, WHITE);
}