#include "HUD.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Player/Player.h"

extern float screenWidth;
extern float screenHeight;

extern Player player;

Rectangle playerLiveMax;
Rectangle playerLiveCurrent;

Rectangle playerXPMax;
Rectangle playerXPCurrent;

float currentLives = player.maxLives;
float currentXP = 0;

void hudUpdate()
{
	currentLives = (player.lives * screenWidth) / player.maxLives;
	currentXP = (player.currentExperience * screenWidth) / player.maxExperience;

	playerLiveCurrent.width = currentLives;
	playerXPCurrent.width = currentXP;
}


void hudDraw()
{
	DrawText("V0.4", 0, screenHeight - 10, 10, RED);
	DrawRectangle(playerLiveMax.x, playerLiveMax.y, playerLiveMax.width, playerLiveMax.height, RED);
	DrawRectangle(playerLiveCurrent.x, playerLiveCurrent.y, playerLiveCurrent.width, playerLiveCurrent.height, GREEN);

	DrawRectangle(playerXPMax.x, playerXPMax.y, playerXPMax.width, playerXPMax.height, GRAY);
	DrawRectangle(playerXPCurrent.x, playerXPCurrent.y, playerXPCurrent.width, playerXPCurrent.height, BLUE);
}

void initHUD()
{
	playerLiveMax = {0, 0, screenWidth, 5};
	playerLiveCurrent = {0, 0, currentLives, 5};

	playerXPMax = {0, screenHeight - 5, screenWidth, 5};
	playerXPCurrent = { 0, screenHeight - 5, currentLives, 5 };;
}