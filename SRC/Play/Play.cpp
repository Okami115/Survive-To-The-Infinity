#include "Play.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Player/Player.h"
#include "../Enemies/Enemies.h"
#include "../Ground/Ground.h"
#include "../Bullets/Bullets.h"
#include "../ChoiceMenu/ChoiceMenu.h"
#include "../Buttons/Buttons.h"
#include "../HUD/HUD.h"
#include "../Pause/Pause.h"
#include "../Defeat/Defeat.h"

extern bool isChoosing; 

extern Player player;

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
    
    if(isPaused && !isChoosing && player.lives > 0)
    {
        pauseUpdate();
    }

    if (isChoosing)
    {
        choiceMenuUpdate();
    }

    if (player.lives <= 0)
    {
        defeatUpdate();
    }

    if (IsKeyReleased(KEY_ESCAPE))
    {
        isPaused = true;
    }
}

void playDraw()
{
    ClearBackground(BLACK);

    backgroundDraw();

    bulletsDraw();

    playerDraw();

    enemiesDraw();

    if (isPaused && !isChoosing && player.lives > 0)
    {
        pauseDraw();
    }

    if (isChoosing)
    {
        choiceMenuDraw();
    }

    if (player.lives <= 0)
    {
        defeatDraw();
    }

    hudDraw();

}
