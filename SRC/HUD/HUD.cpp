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

static int timerSec;
static int timerMin;
static float timerMilli;

float currentLives = player.maxLives;
float currentXP = player.currentExperience;

void hudUpdate()
{
	currentLives = (player.lives * screenWidth) / player.maxLives;
	currentXP = (player.currentExperience * screenWidth) / player.maxExperience;

	playerLiveCurrent.width = currentLives;
	playerXPCurrent.width = currentXP;

	timerMilli = timerMilli + GetFrameTime();

	if (timerMilli > 1)
	{
		timerSec++;
		timerMilli = 0;
	}

	if (timerSec > 59)
	{
		timerSec = 0;
		timerMin++;

	}

}


void hudDraw()
{
	DrawText("V0.5", 0, screenHeight - 30, 20, RED);

	DrawText(TextFormat("%02i", timerSec), 50, 15, 30, RED);
	DrawText(":", 43, 15, 30, RED);
	DrawText(TextFormat("%02i", timerMin), 5, 15, 30, RED);

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
	playerXPCurrent = { 0, screenHeight - 5, currentLives, 5 };

	timerSec = 0;
	timerMin = 0;
	timerMilli = 0;
}