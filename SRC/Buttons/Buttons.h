#pragma once
#include "../../LIB/INCLUDE/raylib.h"

struct Button
{
	Vector2 Pos;
	Rectangle Box;
	Texture currentTexture;
	float scale = 0.2f;
	float Rotation = 0;
};

void initButtons();
void setButtonTexture(Button& button, int State);