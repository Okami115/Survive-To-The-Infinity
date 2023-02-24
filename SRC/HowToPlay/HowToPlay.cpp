#include "HowToPlay.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;

void howToPlayUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}
}

void howToPlayDraw()
{

}