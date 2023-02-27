#include "Credits.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"

namespace OkamiIndustries
{
	extern float screenWidth;
	extern float screenHeight;

	extern Rectangle baseMenu;

	extern int selectScreen;
	Texture CreditsBackground;

	const int maxCreditsButtons = 2;
	extern Button CreditsButtons[maxCreditsButtons];

	void creditsUpdate()
	{
		if (IsKeyReleased(KEY_ESCAPE))
		{
			selectScreen = 0;
		}

		Vector2 MousePos = GetMousePosition();

		for (int i = 0; i < maxCreditsButtons; i++)
		{

			if (CheckCollisionPointRec(MousePos, CreditsButtons[i].Box))
			{
				if (i == 0)
				{
					setButtonTexture(CreditsButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						OpenURL("https://youtu.be/ivDt-T0wjlY");
					}
				}
				else if (i == 1)
				{
					setButtonTexture(CreditsButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						OpenURL("https://youtu.be/QD2RnqiI3ng");
					}
				}
			}
			else
			{
				setButtonTexture(CreditsButtons[i], 0);
			}
		}
	}

	void creditsDraw()
	{
		DrawTexture(CreditsBackground, 0, 0, WHITE);

		int TextWidth = MeasureText("Credits", 60);
		DrawText("Credits", screenWidth / 2 - TextWidth / 2, baseMenu.height / 10, 60, WHITE);

		for (int i = 0; i < maxCreditsButtons; i++)
		{
			DrawTextureEx(CreditsButtons[i].currentTexture, CreditsButtons[i].Pos, CreditsButtons[i].Rotation, CreditsButtons[i].scale, WHITE);

			switch (i)
			{
			case 0:
			{
				int TextWidth = MeasureText("Menu Music", 15);
				DrawText("Menu Music", CreditsButtons[i].Box.x + (CreditsButtons[i].Box.width / 2 - TextWidth / 2), CreditsButtons[i].Box.y + (CreditsButtons[i].Box.height / 2) - 15 / 2, 15, BLACK);
				break;
			}
			case 1:
			{
				int TextWidth = MeasureText("Game Music", 15);
				DrawText("Game Music", CreditsButtons[i].Box.x + (CreditsButtons[i].Box.width / 2 - TextWidth / 2), CreditsButtons[i].Box.y + (CreditsButtons[i].Box.height / 2) - 15 / 2, 15, BLACK);
				break;
			}
			default:
				break;
			}


		}
		int TextWidthESC = MeasureText("ESC to return to the menu", 20);
		DrawText("ESC to return to the menu", screenWidth / 2 - TextWidthESC / 2, (screenHeight / 10) * 9, 20, WHITE);
	}
}