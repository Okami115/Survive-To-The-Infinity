#include "ChoiceMenu.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Buttons/Buttons.h"
#include "../Player/Player.h"


extern float screenWidth;
extern float screenHeight;

extern bool isPaused;
extern bool isChoosing;

extern Player player;

extern const int maxChoiceMenuButtons = 4;
extern Button ChoiceMenuButtons[maxChoiceMenuButtons];

extern Rectangle baseMenu;

void choiceMenuUpdate()
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
					player.lives = player.lives + player.maxLives / 2;

					if (player.lives > player.maxLives)
					{
						player.lives = player.maxLives;
					}

					isChoosing = false;
					isPaused = false;
				}
			}
			else if (i == 1)
			{
				if (player.velocity == 500)
				{
					setButtonTexture(ChoiceMenuButtons[i], 2);
				}
				else
				{
					setButtonTexture(ChoiceMenuButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						player.velocity = player.velocity + 100;
						isChoosing = false;
						isPaused = false;
					}
				}
			}
			else if (i == 2)
			{
				if (player.rateFire < 0.2f)
				{
					setButtonTexture(ChoiceMenuButtons[i], 2);
				}
				else
				{
					setButtonTexture(ChoiceMenuButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						player.rateFire = player.rateFire - 0.1f;
						isChoosing = false;
						isPaused = false;
					}
				}

			}
			else if (i == 3)
			{
				if (player.collisionRadius == 20)
				{
					setButtonTexture(ChoiceMenuButtons[i], 2);
				}
				else
				{
					setButtonTexture(ChoiceMenuButtons[i], 1);
					if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
					{
						player.collisionRadius = player.collisionRadius - 5;
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

void choiceMenuDraw()
{
	int TextWidth = MeasureText("Pick Upgrades", 50);
	DrawText("Pick Upgrades", screenWidth / 2 - TextWidth / 2, baseMenu.height / 6, 50, WHITE);

	for (int i = 0; i < maxChoiceMenuButtons; i++)
	{
		DrawTextureEx(ChoiceMenuButtons[i].currentTexture, ChoiceMenuButtons[i].Pos, ChoiceMenuButtons[i].Rotation, ChoiceMenuButtons[i].scale, WHITE);

		switch (i)
		{
		case 0:
		{
			int TextWidth = MeasureText("More Lives", 30);
			DrawText("More Lives", ChoiceMenuButtons[i].Box.x + (ChoiceMenuButtons[i].Box.width / 2 - TextWidth / 2), ChoiceMenuButtons[i].Box.y + (ChoiceMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 1:
		{
			int TextWidth = MeasureText("More Speed", 30);
			DrawText("More Speed", ChoiceMenuButtons[i].Box.x + (ChoiceMenuButtons[i].Box.width / 2 - TextWidth / 2), ChoiceMenuButtons[i].Box.y + (ChoiceMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 2:
		{
			int TextWidth = MeasureText("More Fire Rate", 30);
			DrawText("More Fire Rate", ChoiceMenuButtons[i].Box.x + (ChoiceMenuButtons[i].Box.width / 2 - TextWidth / 2), ChoiceMenuButtons[i].Box.y + (ChoiceMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
			break;
		}
		case 3:
		{
			int TextWidth = MeasureText("Less Size", 30);
			DrawText("Less Size", ChoiceMenuButtons[i].Box.x + (ChoiceMenuButtons[i].Box.width / 2 - TextWidth / 2), ChoiceMenuButtons[i].Box.y + (ChoiceMenuButtons[i].Box.height / 2) - 15, 30, BLACK);
		}

		default:
			break;
		}
	}
	
}