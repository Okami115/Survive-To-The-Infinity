#include "Options.h"

#include "../../LIB/INCLUDE/raylib.h"

extern int selectScreen;

void optionsUpdate()
{
	if (IsKeyReleased(KEY_ESCAPE))
	{
		selectScreen = 0;
	}

}

void optionsDraw()
{

}