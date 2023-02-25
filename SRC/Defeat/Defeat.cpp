#include "Defeat.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"
#include "../Player/Player.h"
#include "../Enemies/Enemies.h"
#include "../Bullets/Bullets.h"
#include "../HUD/HUD.h"

extern float screenWidth;
extern float screenHeight;

extern Rectangle baseMenu;

extern Player player;

extern int currentEnemies;

extern int selectScreen;

extern bool isPaused;

const int maxDefeatButtons = 2;
Button DefeatButtons[maxDefeatButtons];


void defeatUpdate()
{
	Vector2 MousePos = GetMousePosition();

	isPaused = true;

	for (int i = 0; i < maxDefeatButtons; i++)
	{
		if (CheckCollisionPointRec(MousePos, DefeatButtons[i].Box))
		{
			if (i == 0)
			{
				setButtonTexture(DefeatButtons[i], 1);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					initPlayer();

					initEnemies();
					currentEnemies = 1;

					initBullets();

					initHUD();

					selectScreen = 1;
					isPaused = false;
				}
			}
			else if (i == 1)
			{

				setButtonTexture(DefeatButtons[i], 2);
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					initPlayer();

					initEnemies();
					currentEnemies = 1;

					initBullets();

					initHUD();

					selectScreen = 0;
					isPaused = false;
				}
			}
		}
		else
		{
			setButtonTexture(DefeatButtons[i], 0);
		}
	}
}

void defeatDraw()
{
	int TextWidth = MeasureText("DEFEAT", 50);
	DrawText("DEFEAT", screenWidth / 2 - TextWidth / 2, baseMenu.height / 6, 50, WHITE);

	for (int i = 0; i < maxDefeatButtons; i++)
	{
		DrawTextureEx(DefeatButtons[i].currentTexture, DefeatButtons[i].Pos, DefeatButtons[i].Rotation, DefeatButtons[i].scale, WHITE);

		switch (i)
		{
		case 0:
		{
			int TextWidth = MeasureText("try again", 30);
			DrawText("try again", DefeatButtons[i].Box.x + (DefeatButtons[i].Box.width / 2 - TextWidth / 2), DefeatButtons[i].Box.y + (DefeatButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 1:
		{
			int TextWidth = MeasureText("Return to Menu", 30);
			DrawText("Return to Menu", DefeatButtons[i].Box.x + (DefeatButtons[i].Box.width / 2 - TextWidth / 2), DefeatButtons[i].Box.y + (DefeatButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}

		default:
			break;
		}
	}
}