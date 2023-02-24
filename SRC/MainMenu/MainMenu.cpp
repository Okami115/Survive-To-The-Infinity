#include "MainMenu.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"

extern int selectScreen;

extern float screenWidth;
extern float screenHeight;

const int maxMainMenuButtons = 5;
extern Button MainMenuButtons[maxMainMenuButtons];

extern Rectangle baseMenu;

void menuUpdate()
{
	Vector2 MousePos = GetMousePosition();

	for (int i = 0; i < maxMainMenuButtons; i++)
	{

		if (CheckCollisionPointRec(MousePos, MainMenuButtons[i].Box))
		{
			if (i == 0)
			{
				setButtonTexture(MainMenuButtons[i], 1);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					selectScreen = i + 1;
				}
			}
			else if (i == 1)
			{
				setButtonTexture(MainMenuButtons[i], 1);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					selectScreen = i + 1;
				}
			}
			else if (i == 2)
			{

				setButtonTexture(MainMenuButtons[i], 1);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					selectScreen = i + 1;
				}

			}
			else if (i == 3)
			{
				setButtonTexture(MainMenuButtons[i], 1);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					selectScreen = i + 1;
				}
				
			}
			else if (i == 4)
			{
				setButtonTexture(MainMenuButtons[i], 2);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					selectScreen = i + 1;
				}

			}

		}
		else
		{
			setButtonTexture(MainMenuButtons[i], 0);
		}
	}
}

void menuDraw()
{
	int TextWidth = MeasureText("Survive To The Infinity", 30);
	DrawText("Survive To The Infinity", screenWidth / 2 - TextWidth / 2, baseMenu.height / 6, 30, WHITE);

	for (int i = 0; i < maxMainMenuButtons; i++)
	{
		DrawTextureEx(MainMenuButtons[i].currentTexture, MainMenuButtons[i].Pos, MainMenuButtons[i].Rotation, MainMenuButtons[i].scale, WHITE);

		switch (i)
		{
		case 0:
		{
			int TextWidth = MeasureText("Play", 30);
			DrawText("Play", MainMenuButtons[i].Box.x + (MainMenuButtons[i].Box.width / 2 - TextWidth / 2), MainMenuButtons[i].Box.y + (MainMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 1:
		{
			int TextWidth = MeasureText("Options", 30);
			DrawText("Options", MainMenuButtons[i].Box.x + (MainMenuButtons[i].Box.width / 2 - TextWidth / 2), MainMenuButtons[i].Box.y + (MainMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 2:
		{
			int TextWidth = MeasureText("How To Play", 30);
			DrawText("How To Play", MainMenuButtons[i].Box.x + (MainMenuButtons[i].Box.width / 2 - TextWidth / 2), MainMenuButtons[i].Box.y + (MainMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 3:
		{
			int TextWidth = MeasureText("Credits", 30);
			DrawText("Credits", MainMenuButtons[i].Box.x + (MainMenuButtons[i].Box.width / 2 - TextWidth / 2), MainMenuButtons[i].Box.y + (MainMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 4:
		{
			int TextWidth = MeasureText("Exit", 30);
			DrawText("Exit", MainMenuButtons[i].Box.x + (MainMenuButtons[i].Box.width / 2 - TextWidth / 2), MainMenuButtons[i].Box.y + (MainMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
		}

		default:
			break;
		}
	}
}