#include "Ground.h"
#include "../../LIB/INCLUDE/raylib.h"

extern int screenHeight;
extern int screenWidth;
extern int velocity;

Texture ground;

Vector2 topLeft{ -screenWidth, -screenHeight };
Vector2 bottomRight{ screenWidth, screenHeight };

Rectangle Background1{ 0, 0, screenWidth, screenHeight };
Rectangle Background2{ Background1.x, -Background1.height, screenWidth, screenHeight };
Rectangle Background3{ Background1.x, Background1.height, screenWidth, screenHeight };
Rectangle Background4{ -Background1.width, Background1.y, screenWidth, screenHeight };
Rectangle Background5{ Background1.width, Background1.y, screenWidth, screenHeight };
Rectangle Background6{ -Background1.width, -Background1.height, screenWidth, screenHeight };
Rectangle Background7{ Background1.width, -Background1.height, screenWidth, screenHeight };
Rectangle Background8{ -Background1.width, Background1.height, screenWidth, screenHeight };
Rectangle Background9{ Background1.width, Background1.height, screenWidth, screenHeight };

void backgroundUpdate()
{
    if (IsKeyDown(KEY_W))
    {
        Background1.y = Background1.y + velocity * GetFrameTime();
    }
    if (IsKeyDown(KEY_A))
    {
        Background1.x = Background1.x + velocity * GetFrameTime();
    }
    if (IsKeyDown(KEY_S))
    {
        Background1.y = Background1.y - velocity * GetFrameTime();
    }
    if (IsKeyDown(KEY_D))
    {
        Background1.x = Background1.x - velocity * GetFrameTime();
    }


    if (topLeft.x > 0)
    {
        Background1.x = screenWidth;
    }

    if (topLeft.y > 0)
    {
        Background1.y = screenHeight;
    }

    if (bottomRight.x < screenWidth)
    {
        Background1.x = -screenWidth;
    }

    if (bottomRight.y < screenHeight)
    {
        Background1.y = -screenHeight;
    }

    topLeft.x = Background1.x - screenWidth;
    topLeft.y = Background1.y - screenHeight;

    bottomRight.x = Background1.x + Background1.width + screenWidth;
    bottomRight.y = Background1.y + Background1.height + screenHeight;

    Background2.x = Background1.x;
    Background2.y = Background1.y - Background1.height;

    Background3.x = Background1.x;
    Background3.y = Background1.y + Background1.height;

    Background4.x = Background1.x - Background1.width;
    Background4.y = Background1.y;

    Background5.x = Background1.x + Background1.width;
    Background5.y = Background1.y;

    Background6.x = Background1.x - Background1.width;
    Background6.y = Background1.y - Background1.height;

    Background7.x = Background1.x + Background1.width;
    Background7.y = Background1.y - Background1.height;

    Background8.x = Background1.x - Background1.width;
    Background8.y = Background1.y + Background1.height;

    Background9.x = Background1.x + Background1.width;
    Background9.y = Background1.y + Background1.height;

}

void backgroundDraw()
{
    DrawTexture(ground, Background1.x, Background1.y, WHITE);
    DrawTexture(ground, Background2.x, Background2.y, WHITE);
    DrawTexture(ground, Background3.x, Background3.y, WHITE);
    DrawTexture(ground, Background4.x, Background4.y, WHITE);
    DrawTexture(ground, Background5.x, Background5.y, WHITE);
    DrawTexture(ground, Background6.x, Background6.y, WHITE);
    DrawTexture(ground, Background7.x, Background7.y, WHITE);
    DrawTexture(ground, Background8.x, Background8.y, WHITE);
    DrawTexture(ground, Background9.x, Background9.y, WHITE);
}