#include "Credits.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;

void creditsUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}
}

void creditsDraw()
{

}