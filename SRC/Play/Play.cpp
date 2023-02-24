#include "Play.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Player/Player.h"
#include "../Enemies/Enemies.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../ChoiceMenu/ChoiceMenu.h"
#include "../Buttons/Buttons.h"
#include "../HUD/HUD.h"

extern bool isChoosing;

bool isPaused = false;

void playUpdate()
{
    if (!isPaused)
    {
        playerUpdate();

        backgroundUpdate();

        enemiesUpdate();

        bulletsUpdate();

        hudUpdate();
    }

    if (isChoosing)
    {
        choiceMenuUpdate();
    }

    if (IsKeyReleased(KEY_ESCAPE) && !isChoosing)
    {
        if (isPaused)
        {
            isPaused = false;
        }
        else
        {
            isPaused = true;
        }
    }
}

void playDraw()
{
    ClearBackground(BLACK);

    backgroundDraw();

    bulletsDraw();

    playerDraw();

    enemiesDraw();

    choiceMenuDraw();

    hudDraw();

}
