#include "ChoiceMenu.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"


extern int screenWidth;
extern int screenHeight;

extern bool isPaused;
extern bool isChoosing;

extern int playerLives;
extern int playerVelocity;
extern float rateFire;
extern int collisionRadius;

extern const int maxChoiceMenuButtons = 4;
extern Button ChoiceMenuButtons[maxChoiceMenuButtons];

Rectangle baseMenu{ screenWidth / 10, screenHeight / 10, (screenWidth / 10) * 8, (screenHeight / 10) * 8 };


void choiceMenuUpdate()
{
	if (isChoosing)
	{
		Vector2 MousePos = GetMousePosition();

		for (int i = 0; i < maxChoiceMenuButtons; i++)
		{

			if (CheckCollisionPointRec(MousePos, ChoiceMenuButtons[i].Box))
			{
				if (i == 0)
				{
					setButtonTexture(ChoiceMenuButtons[i], 1);
					if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						playerLives++;
						isChoosing = false;
						isPaused = false;
					}
				}
				else if (i == 1)
				{
					if (playerVelocity == 500)
					{
						setButtonTexture(ChoiceMenuButtons[i], 2);
					}
					else
					{
						setButtonTexture(ChoiceMenuButtons[i], 1);
						if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
						{
							playerVelocity = playerVelocity + 100;
							isChoosing = false;
							isPaused = false;
						}
					}
				}
				else if (i == 2)
				{
					if (rateFire < 0.2f)
					{
						setButtonTexture(ChoiceMenuButtons[i], 2);
					}
					else
					{
						setButtonTexture(ChoiceMenuButtons[i], 1);
						if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
						{
							rateFire = rateFire - 0.1f;
							isChoosing = false;
							isPaused = false;
						}
					}

				}
				else if (i == 3)
				{
					if (collisionRadius == 30)
					{
						setButtonTexture(ChoiceMenuButtons[i], 3);
					}
					else
					{
						setButtonTexture(ChoiceMenuButtons[i], 1);
						if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
						{
							collisionRadius = collisionRadius - 10;
							isChoosing = false;
							isPaused = false;
						}
					}
				}
				
			}
			else
				{
					setButtonTexture(ChoiceMenuButtons[i], 0);
				}
		}

	}
}

void choiceMenuDraw()
{
	if (isChoosing)
	{
		DrawText("Pick Upgrades", baseMenu.x * 2, baseMenu.y * 1.5f, 50, BLACK);

		for (int i = 0; i < maxChoiceMenuButtons; i++)
		{
			DrawTextureEx(ChoiceMenuButtons[i].currentTexture, ChoiceMenuButtons[i].Pos, ChoiceMenuButtons[i].Rotation, ChoiceMenuButtons[i].scale, WHITE);

			switch (i)
			{
			case 0:
			{
				int TextWidth = MeasureText("More Lives", 30);
				DrawText("More Lives", ChoiceMenuButtons[i].Box.x / 2 + TextWidth - 15, ChoiceMenuButtons[i].Box.y + ChoiceMenuButtons[i].Box.height / 2 - 15, 30, BLACK);
				break;
			}
			case 1:
			{
				int TextWidth = MeasureText("More Speed", 30);
				DrawText("More Speed", ChoiceMenuButtons[i].Box.x / 2 + TextWidth - 30, ChoiceMenuButtons[i].Box.y + ChoiceMenuButtons[i].Box.height / 2 - 15, 30, BLACK);
				break;
			}
			case 2:
			{
				int TextWidth = MeasureText("More Fire Rate", 30);
				DrawText("More Fire Rate", ChoiceMenuButtons[i].Box.x / 2 + TextWidth / 2, ChoiceMenuButtons[i].Box.y + ChoiceMenuButtons[i].Box.height / 2 - 15, 30, BLACK);
				break;
			}
			case 3:
			{
				int TextWidth = MeasureText("Less Size", 30);
				DrawText("Less Size", ChoiceMenuButtons[i].Box.x / 2 + TextWidth, ChoiceMenuButtons[i].Box.y + ChoiceMenuButtons[i].Box.height / 2 - 15, 30, BLACK);
				break;
			}

			default:
				break;
			}
		}
	}
}