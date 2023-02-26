#include "Exit.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"

extern int selectScreen;
extern bool isRunning;

extern float screenWidth;
extern float screenHeight;

const int maxExitButtons = 2;
extern Button ExitButtons[maxExitButtons];

extern Rectangle baseMenu;

extern Texture Background;

void exitUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}

	Vector2 MousePos = GetMousePosition();

	for (int i = 0; i < maxExitButtons; i++)
	{

		if (CheckCollisionPointRec(MousePos, ExitButtons[i].Box))
		{
			if (i == 0)
			{
				setButtonTexture(ExitButtons[i], 2);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					isRunning = false;
				}
			}
			else if (i == 1)
			{
				setButtonTexture(ExitButtons[i], 1);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					selectScreen = 0;
				}
			}
		}
		else
		{
			setButtonTexture(ExitButtons[i], 0);
		}
	}
}

void exitDraw()
{
	DrawTexture(Background, 0, 0, WHITE);

	int TextWidth = MeasureText("EXIT ?", 60);
	DrawText("EXIT ?", screenWidth / 2 - TextWidth / 2, baseMenu.height / 6, 60, WHITE);

	for (int i = 0; i < maxExitButtons; i++)
	{
		DrawTextureEx(ExitButtons[i].currentTexture, ExitButtons[i].Pos, ExitButtons[i].Rotation, ExitButtons[i].scale, WHITE);

		switch (i)
		{
		case 0:
		{
			int TextWidth = MeasureText("Exit", 30);
			DrawText("Exit", ExitButtons[i].Box.x + (ExitButtons[i].Box.width / 2 - TextWidth / 2), ExitButtons[i].Box.y + (ExitButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 1:
		{
			int TextWidth = MeasureText("Return", 30);
			DrawText("Return", ExitButtons[i].Box.x + (ExitButtons[i].Box.width / 2 - TextWidth / 2), ExitButtons[i].Box.y + (ExitButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		default:
			break;
		}
	}
}