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

static int choiceButton = 0;

void choiceMenuUpdate()
{

	if (IsKeyReleased(KEY_UP))
	{
		choiceButton--;

		if (choiceButton < 0)
		{
			choiceButton = 4;
		}

	}

	if (IsKeyReleased(KEY_DOWN))
	{
		choiceButton++;

		if (choiceButton > 4)
		{
			choiceButton = 0;
		}

	}


	if(choiceButton == 1)
	{
		setButtonTexture(ChoiceMenuButtons[0], 1);
		if (IsKeyReleased(KEY_ENTER))
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
	else
	{
		setButtonTexture(ChoiceMenuButtons[0], 0);
	}

	if (choiceButton == 2)
	{
		if (player.velocity == 500)
		{
			setButtonTexture(ChoiceMenuButtons[1], 2);
		}
		else
		{
			setButtonTexture(ChoiceMenuButtons[1], 1);
			if (IsKeyReleased(KEY_ENTER))
			{
				player.velocity = player.velocity + 100;
				isChoosing = false;
				isPaused = false;
			}
		}
	}
	else
	{
		setButtonTexture(ChoiceMenuButtons[1], 0);
	}


	if (choiceButton == 3)
	{
		if (player.rateFire < 0.2f)
		{
			setButtonTexture(ChoiceMenuButtons[2], 2);
		}
		else
		{
			setButtonTexture(ChoiceMenuButtons[2], 1);
			if (IsKeyReleased(KEY_ENTER))
			{
				player.rateFire = player.rateFire - 0.1f;
				isChoosing = false;
				isPaused = false;
			}
		}
	}
	else
	{
		setButtonTexture(ChoiceMenuButtons[2], 0);
	}

	if (choiceButton == 4)
	{
		if (player.collisionRadius == 20)
		{
			setButtonTexture(ChoiceMenuButtons[3], 2);
		}
		else
		{
			setButtonTexture(ChoiceMenuButtons[3], 1);
			if (IsKeyReleased(KEY_ENTER))
			{
				player.collisionRadius = player.collisionRadius - 5;
				isChoosing = false;
				isPaused = false;
			}
		}
	}
	else
	{
		setButtonTexture(ChoiceMenuButtons[3], 0);
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