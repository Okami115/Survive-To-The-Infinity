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
#include "../Fire/Fire.h"

extern bool isChoosing; 

extern Player player;

bool isPaused = false;

Sound Defeat;
Sound LevelUp;

bool playSound = false;

void playUpdate()
{
    if (!isPaused)
    {
        playerUpdate();

        backgroundUpdate();

        enemiesUpdate();

        bulletsUpdate();

        fireUpdate();

        hudUpdate();

    }
    
    if (isChoosing)
    {
        choiceMenuUpdate();
        if (playSound)
        {
            PlaySound(LevelUp);
            playSound = false;
        }
    }

    if (player.lives <= 0)
    {
        defeatUpdate();

        if (playSound)
        {
            PlaySound(Defeat);
            playSound = false;
        }

        
    }



    if(isPaused && !isChoosing && player.lives > 0)
    {
        pauseUpdate();
    }
    else
    {
        if (IsKeyReleased(KEY_ESCAPE))
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

    fireDraw();

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
