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

const int maxExitButtons = 2;
Button ExitButtons[maxExitButtons];

const int maxPauseButtons = 2;
Button PauseButtons[maxPauseButtons];

const int maxDefeatButtons = 2;
Button DefeatButtons[maxDefeatButtons];

const int maxOptionsButtons = 3;
Button OptionsButtons[maxOptionsButtons];

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



	MainMenuButtons[0].scale = 0.15f;
	MainMenuButtons[0].Box = { baseMenu.x, baseMenu.y * 3.5f, (float)normalButton.width * MainMenuButtons[0].scale, (float)normalButton.height * MainMenuButtons[0].scale };
	MainMenuButtons[0].currentTexture = normalButton;
	MainMenuButtons[0].Pos = { MainMenuButtons[0].Box.x, MainMenuButtons[0].Box.y };

	MainMenuButtons[1].scale = 0.15f;
	MainMenuButtons[1].Box = { baseMenu.x, baseMenu.y * 4.7f, (float)normalButton.width * MainMenuButtons[1].scale, (float)normalButton.height * MainMenuButtons[1].scale };
	MainMenuButtons[1].currentTexture = normalButton;
	MainMenuButtons[1].Pos = { MainMenuButtons[1].Box.x, MainMenuButtons[1].Box.y };

	MainMenuButtons[2].scale = 0.15f;
	MainMenuButtons[2].Box = { baseMenu.x, baseMenu.y * 5.9f, (float)normalButton.width * MainMenuButtons[2].scale, (float)normalButton.height * MainMenuButtons[2].scale };
	MainMenuButtons[2].currentTexture = normalButton;
	MainMenuButtons[2].Pos = { MainMenuButtons[2].Box.x, MainMenuButtons[2].Box.y };

	MainMenuButtons[3].scale = 0.15f;
	MainMenuButtons[3].Box = { baseMenu.x, baseMenu.y * 7.1f, (float)normalButton.width * MainMenuButtons[3].scale, (float)normalButton.height * MainMenuButtons[3].scale };
	MainMenuButtons[3].currentTexture = normalButton;
	MainMenuButtons[3].Pos = { MainMenuButtons[3].Box.x, MainMenuButtons[3].Box.y };

	MainMenuButtons[4].scale = 0.15f;
	MainMenuButtons[4].Box = { baseMenu.x, baseMenu.y * 8.3f, (float)normalButton.width * MainMenuButtons[4].scale, (float)normalButton.height * MainMenuButtons[4].scale };
	MainMenuButtons[4].currentTexture = normalButton;
	MainMenuButtons[4].Pos = { MainMenuButtons[4].Box.x, MainMenuButtons[4].Box.y };



	ExitButtons[0].Box = { (screenWidth / 2) - ((float)normalButton.width * ExitButtons[0].scale) / 2, (screenHeight / 3) , (float)normalButton.width * ExitButtons[0].scale, (float)normalButton.height * ExitButtons[0].scale};
	ExitButtons[0].currentTexture = normalButton;
	ExitButtons[0].Pos = { ExitButtons[0].Box.x, ExitButtons[0].Box.y };

	ExitButtons[1].Box = { (screenWidth / 2) - ((float)normalButton.width * ExitButtons[0].scale) / 2, (screenHeight / 3) * 2, (float)normalButton.width * ExitButtons[1].scale, (float)normalButton.height * ExitButtons[1].scale };
	ExitButtons[1].currentTexture = normalButton;
	ExitButtons[1].Pos = { ExitButtons[1].Box.x, ExitButtons[1].Box.y };



	PauseButtons[0].Box = { (baseMenu.x * 2), (baseMenu.y * 3), (float)normalButton.width * PauseButtons[0].scale, (float)normalButton.height * PauseButtons[0].scale };
	PauseButtons[0].currentTexture = normalButton;
	PauseButtons[0].Pos = { PauseButtons[0].Box.x, PauseButtons[0].Box.y };

	PauseButtons[1].Box = { (baseMenu.x * 2), (baseMenu.y * 6), (float)normalButton.width * PauseButtons[1].scale, (float)normalButton.height * PauseButtons[1].scale };
	PauseButtons[1].currentTexture = normalButton;
	PauseButtons[1].Pos = { PauseButtons[1].Box.x, PauseButtons[1].Box.y };



	DefeatButtons[0].Box = { (baseMenu.x * 2), (baseMenu.y * 3), (float)normalButton.width * DefeatButtons[0].scale, (float)normalButton.height * DefeatButtons[0].scale };
	DefeatButtons[0].currentTexture = normalButton;
	DefeatButtons[0].Pos = { DefeatButtons[0].Box.x, DefeatButtons[0].Box.y };

	DefeatButtons[1].Box = { (baseMenu.x * 2), (baseMenu.y * 6), (float)normalButton.width * DefeatButtons[1].scale, (float)normalButton.height * DefeatButtons[1].scale };
	DefeatButtons[1].currentTexture = normalButton;
	DefeatButtons[1].Pos = { DefeatButtons[1].Box.x, DefeatButtons[1].Box.y };



	OptionsButtons[0].scale = 0.1f;
	OptionsButtons[0].Box = { baseMenu.x, baseMenu.y * 4,  (float)normalButton.width * OptionsButtons[0].scale, (float)normalButton.height * OptionsButtons[0].scale };
	OptionsButtons[0].currentTexture = normalButton;
	OptionsButtons[0].Pos = { OptionsButtons[0].Box.x, OptionsButtons[0].Box.y };

	OptionsButtons[1].scale = 0.1f;
	OptionsButtons[1].Box = { baseMenu.width - ((float)normalButton.width * OptionsButtons[1].scale) / 1.5f, baseMenu.y * 4,  (float)normalButton.width * OptionsButtons[1].scale, (float)normalButton.height * OptionsButtons[1].scale };
	OptionsButtons[1].currentTexture = normalButton;
	OptionsButtons[1].Pos = { OptionsButtons[1].Box.x, OptionsButtons[1].Box.y };

	OptionsButtons[2].Box = { (screenWidth / 2) - ((float)normalButton.width * OptionsButtons[2].scale) / 2, baseMenu.y * 6,  (float)normalButton.width * OptionsButtons[2].scale, (float)normalButton.height * OptionsButtons[2].scale };
	OptionsButtons[2].currentTexture = normalButton;
	OptionsButtons[2].Pos = { OptionsButtons[2].Box.x, OptionsButtons[2].Box.y };
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