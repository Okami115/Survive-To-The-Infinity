#include "Cursor.h"

#include "../../LIB/INCLUDE/raylib.h"

namespace OkamiIndustries
{

	Vector2  cursorPos;

	Texture cursor;
	Texture cursorClicked;
	static Texture currentTexture;


	void cursorUpdate()
	{
		cursorPos = GetMousePosition();

		if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
		{
			currentTexture = cursor;
		}
		else
		{
			currentTexture = cursorClicked;
		}
	}

	void cursorDraw()
	{
		DrawTextureEx(currentTexture, cursorPos, 0, 0.05f, WHITE);
	}
}