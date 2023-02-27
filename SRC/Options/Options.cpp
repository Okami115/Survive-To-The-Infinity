#include "Options.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"

namespace OkamiIndustries
{

	extern int selectScreen;

	extern float screenWidth;
	extern float screenHeight;

	extern Rectangle baseMenu;

	extern Texture Background;

	const int maxOptionsButtons = 3;
	extern Button OptionsButtons[maxOptionsButtons];

	static float volumen = 0.1f;

	void optionsUpdate()
	{
		if (IsKeyReleased(KEY_ESCAPE))
		{
			selectScreen = 0;
		}

		Vector2 MousePos = GetMousePosition();

		SetMasterVolume(volumen);

		for (int i = 0; i < maxOptionsButtons; i++)
		{
			if (CheckCollisionPointRec(MousePos, OptionsButtons[i].Box))
			{
				if (i == 0)
				{
					setButtonTexture(OptionsButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						volumen = volumen + 0.1f;
					}
				}
				else if (i == 1)
				{

					setButtonTexture(OptionsButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						volumen = volumen - 0.1f;
					}
				}
				else if (i == 2)
				{
					setButtonTexture(OptionsButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{

						if (volumen != 0)
						{
							volumen = 0;
						}
						else
						{
							volumen = 0.1f;
						}
					}
				}
			}
			else
			{
				setButtonTexture(OptionsButtons[i], 0);
			}
		}

	}

	void optionsDraw()
	{
		DrawTexture(Background, 0, 0, WHITE);

		int TextWidth = MeasureText("Volumen", 50);
		DrawText("Volumen", screenWidth / 2 - TextWidth / 2, baseMenu.height / 10, 50, WHITE);	
	
		int TextWidthESC = MeasureText("ESC to return to the menu", 20);
		DrawText("ESC to return to the menu", screenWidth / 2 - TextWidthESC / 2, (screenHeight / 10) * 9, 20, WHITE);

		for (int i = 0; i < maxOptionsButtons; i++)
		{
			DrawTextureEx(OptionsButtons[i].currentTexture, OptionsButtons[i].Pos, OptionsButtons[i].Rotation, OptionsButtons[i].scale, WHITE);

			switch (i)
			{
			case 0:
			{
				int TextWidth = MeasureText("+", 30);
				DrawText("+", OptionsButtons[i].Box.x + (OptionsButtons[i].Box.width / 2 - TextWidth / 2), OptionsButtons[i].Box.y + (OptionsButtons[i].Box.height / 2) - 15, 30, BLACK);
				break;
			}
			case 1:
			{
				int TextWidth = MeasureText("-", 30);
				DrawText("-", OptionsButtons[i].Box.x + (OptionsButtons[i].Box.width / 2 - TextWidth / 2), OptionsButtons[i].Box.y + (OptionsButtons[i].Box.height / 2) - 15, 30, BLACK);
				break;
			}

			case 2:
			{
				int TextWidth = MeasureText("MUTE", 30);
				DrawText("MUTE", OptionsButtons[i].Box.x + (OptionsButtons[i].Box.width / 2 - TextWidth / 2), OptionsButtons[i].Box.y + (OptionsButtons[i].Box.height / 2) - 15, 30, BLACK);
				break;
			}

			default:
				break;
			}
		}
	}
}