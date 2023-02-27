#include "Pause.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"
#include "../Player/Player.h"

namespace OkamiIndustries
{

	extern float screenWidth;
	extern float screenHeight;

	extern Rectangle baseMenu;

	extern bool isPaused;

	const int maxPauseButtons = 2;
	extern Button PauseButtons[maxPauseButtons];

	extern Player player;

	void pauseUpdate()
	{
		Vector2 MousePos = GetMousePosition();

		if (IsKeyReleased(KEY_ESCAPE))
		{
			isPaused = false;
		}

		for (int i = 0; i < maxPauseButtons; i++)
		{

			if (CheckCollisionPointRec(MousePos, PauseButtons[i].Box))
			{
				if (i == 0)
				{
					setButtonTexture(PauseButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						isPaused = false;
					}
				}
				else if (i == 1)
				{

					setButtonTexture(PauseButtons[i], 2);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						isPaused = false;
						player.lives = 0;
					}
					
				}

			}
			else
			{
				setButtonTexture(PauseButtons[i], 0);
			}
		}
	}

	void pauseDraw()
	{
		int TextWidth = MeasureText("PAUSE", 50);
		DrawText("PAUSE", screenWidth / 2 - TextWidth / 2, baseMenu.height / 6, 50, WHITE);

		for (int i = 0; i < maxPauseButtons; i++)
		{
			DrawTextureEx(PauseButtons[i].currentTexture, PauseButtons[i].Pos, PauseButtons[i].Rotation, PauseButtons[i].scale, WHITE);

			switch (i)
			{
			case 0:
			{
				int TextWidth = MeasureText("Retrun", 30);
				DrawText("Return", PauseButtons[i].Box.x + (PauseButtons[i].Box.width / 2 - TextWidth / 2), PauseButtons[i].Box.y + (PauseButtons[i].Box.height / 2) - 15, 30, BLACK);
				break;
			}
			case 1:
			{
				int TextWidth = MeasureText("Give Up", 30);
				DrawText("Give Up", PauseButtons[i].Box.x + (PauseButtons[i].Box.width / 2 - TextWidth / 2), PauseButtons[i].Box.y + (PauseButtons[i].Box.height / 2) - 15, 30, BLACK);
				break;
			}

			default:
				break;
			}
		}
	}
}