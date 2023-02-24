#include "Buttons.h"

#include "../../LIB/INCLUDE/raylib.h"

extern float screenWidth;
extern float screenHeight;

Texture normalButton;
Texture SelectButton;
Texture BlockedButton;

Rectangle baseMenu{ screenWidth / 10, screenHeight / 10, (screenWidth / 10) * 8, (screenHeight / 10) * 8 };

const int maxChoiceMenuButtons = 4;
Button ChoiceMenuButtons[maxChoiceMenuButtons];

const int maxMainMenuButtons = 5;
Button MainMenuButtons[maxMainMenuButtons];

void initButtons()
{
	ChoiceMenuButtons[0].Box = { (baseMenu.x * 2), (baseMenu.y * 3), (float)normalButton.width * ChoiceMenuButtons[0].scale, (float)normalButton.height * ChoiceMenuButtons[0].scale };
	ChoiceMenuButtons[0].currentTexture = normalButton;
	ChoiceMenuButtons[0].Pos = { ChoiceMenuButtons[0].Box.x, ChoiceMenuButtons[0].Box.y };

	ChoiceMenuButtons[1].Box = { (baseMenu.x * 2), (baseMenu.y * 4.5f), (float)normalButton.width * ChoiceMenuButtons[1].scale, (float)normalButton.height * ChoiceMenuButtons[1].scale };
	ChoiceMenuButtons[1].currentTexture = normalButton;
	ChoiceMenuButtons[1].Pos = { ChoiceMenuButtons[1].Box.x, ChoiceMenuButtons[1].Box.y };

	ChoiceMenuButtons[2].Box = { (baseMenu.x * 2), (baseMenu.y * 6), (float)normalButton.width * ChoiceMenuButtons[2].scale, (float)normalButton.height * ChoiceMenuButtons[2].scale };
	ChoiceMenuButtons[2].currentTexture = normalButton;
	ChoiceMenuButtons[2].Pos = { ChoiceMenuButtons[2].Box.x, ChoiceMenuButtons[2].Box.y };

	ChoiceMenuButtons[3].Box = { (baseMenu.x * 2), (baseMenu.y * 7.5f), (float)normalButton.width * ChoiceMenuButtons[3].scale, (float)normalButton.height * ChoiceMenuButtons[3].scale };
	ChoiceMenuButtons[3].currentTexture = normalButton;
	ChoiceMenuButtons[3].Pos = { ChoiceMenuButtons[3].Box.x, ChoiceMenuButtons[3].Box.y };



	MainMenuButtons[0].Box = { baseMenu.x, baseMenu.y * 2, (float)normalButton.width * MainMenuButtons[0].scale, (float)normalButton.height * MainMenuButtons[0].scale };
	MainMenuButtons[0].currentTexture = normalButton;
	MainMenuButtons[0].Pos = { MainMenuButtons[0].Box.x, MainMenuButtons[0].Box.y };

	MainMenuButtons[1].Box = { baseMenu.x, baseMenu.y * 3.5f, (float)normalButton.width * MainMenuButtons[1].scale, (float)normalButton.height * MainMenuButtons[1].scale };
	MainMenuButtons[1].currentTexture = normalButton;
	MainMenuButtons[1].Pos = { MainMenuButtons[1].Box.x, MainMenuButtons[1].Box.y };

	MainMenuButtons[2].Box = { baseMenu.x, baseMenu.y * 5, (float)normalButton.width * MainMenuButtons[2].scale, (float)normalButton.height * MainMenuButtons[2].scale };
	MainMenuButtons[2].currentTexture = normalButton;
	MainMenuButtons[2].Pos = { MainMenuButtons[2].Box.x, MainMenuButtons[2].Box.y };

	MainMenuButtons[3].Box = { baseMenu.x, baseMenu.y * 6.5f, (float)normalButton.width * MainMenuButtons[3].scale, (float)normalButton.height * MainMenuButtons[3].scale };
	MainMenuButtons[3].currentTexture = normalButton;
	MainMenuButtons[3].Pos = { MainMenuButtons[3].Box.x, MainMenuButtons[3].Box.y };

	MainMenuButtons[4].Box = { baseMenu.x, baseMenu.y * 8, (float)normalButton.width * MainMenuButtons[4].scale, (float)normalButton.height * MainMenuButtons[4].scale };
	MainMenuButtons[4].currentTexture = normalButton;
	MainMenuButtons[4].Pos = { MainMenuButtons[4].Box.x, MainMenuButtons[4].Box.y };
}

void setButtonTexture(Button& button, int State)
{
	if (State == 0)
	{
		button.currentTexture = normalButton;
	}

	if (State == 1)
	{
		button.currentTexture = SelectButton;
	}

	if (State == 2)
	{
		button.currentTexture = BlockedButton;
	}
}