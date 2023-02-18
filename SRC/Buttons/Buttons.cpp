#include "Buttons.h"

#include "../../LIB/INCLUDE/raylib.h"

extern Rectangle baseMenu;

Texture normalButton;
Texture SelectButton;
Texture BlockedButton;

const int maxChoiceMenuButtons = 4;
Button ChoiceMenuButtons[maxChoiceMenuButtons];


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