#include "ChoiceMenu.h"

#include "../../LIB/INCLUDE/raylib.h"

extern bool isPaused;
extern bool isChoosing;

Rectangle baseMenu{ 60, 80, 480, 640};

void choiceMenuUpdate()
{
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
	{
		isChoosing = false;
		isPaused = false;
	}
}

void choiceMenuDraw()
{
	if (isChoosing)
	{
		DrawRectangle(baseMenu.x, baseMenu.y, baseMenu.width, baseMenu.height, BLACK);
	}
}