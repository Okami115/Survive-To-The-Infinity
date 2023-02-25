#include "Ground.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Player/Player.h"

extern float screenHeight;
extern float screenWidth;

extern Player player;

bool isInTheLeft = false;
bool isInTheTop = false;
bool isInTheRight = false;
bool isInTheBottom = false;

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

Rectangle Line1{ 0, 0, 5, screenHeight * 2 };
Rectangle Line2{ 0, 0, screenWidth * 2, 5};
Rectangle Line3{ 0, 0, 5, screenHeight * 2 };
Rectangle Line4{ 0, 0, screenWidth * 2, 5};

void backgroundUpdate()
{
    if (IsKeyDown(KEY_W))
    {
        Background1.y = Background1.y + player.velocity * GetFrameTime();
    }
    if (IsKeyDown(KEY_A))
    {
        Background1.x = Background1.x + player.velocity * GetFrameTime();
    }
    if (IsKeyDown(KEY_S))
    {
        Background1.y = Background1.y - player.velocity * GetFrameTime();
    }
    if (IsKeyDown(KEY_D))
    {
        Background1.x = Background1.x - player.velocity * GetFrameTime();
    }

    if (topLeft.x < 0)
    {
        isInTheLeft = false;
    }
    if (topLeft.y < 0)
    {
        isInTheTop = false;
    }
    if (bottomRight.x != screenWidth)
    {
        isInTheRight = false;
    }
    if (bottomRight.y != screenHeight)
    {
        isInTheBottom = false;
    }

    if (topLeft.x > 0)
    {
        Background1.x = screenWidth;
        isInTheLeft = true;
    }
    if (topLeft.y > 0)
    {
        Background1.y = screenHeight;
        isInTheTop = true;
    }
    if (bottomRight.x < screenWidth)
    {
        Background1.x = -screenWidth;
        isInTheRight = true;
    }
    if (bottomRight.y < screenHeight)
    {
        Background1.y = -screenHeight;
        isInTheBottom = true;
    }



    topLeft.x = Background1.x - screenWidth;
    topLeft.y = Background1.y - screenHeight;

    bottomRight.x = Background1.x + Background1.width + screenWidth;
    bottomRight.y = Background1.y + Background1.height + screenHeight;

    Line1.x = topLeft.x + screenWidth / 2;
    Line1.y = topLeft.y + screenHeight / 2;

    Line2.x = topLeft.x + screenWidth / 2;
    Line2.y = topLeft.y + screenHeight / 2;

    Line3.x = topLeft.x + screenWidth * 2.5f;
    Line3.y = topLeft.y + screenHeight / 2;    
    
    Line4.x = topLeft.x + screenWidth / 2;
    Line4.y = topLeft.y + screenHeight * 2.5f;

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

    DrawRectangle(Line1.x, Line1.y, Line1.width, Line1.height, RED);
    DrawRectangle(Line2.x, Line2.y, Line2.width, Line2.height, RED);
    DrawRectangle(Line3.x, Line3.y, Line3.width, Line3.height, RED);
    DrawRectangle(Line4.x, Line4.y, Line4.width, Line4.height, RED);
}

void initGround()
{
    Background1 = { 0, 0, screenWidth, screenHeight };
    Background2 = { Background1.x, -Background1.height, screenWidth, screenHeight };
    Background3 = { Background1.x, Background1.height, screenWidth, screenHeight };
    Background4 = { -Background1.width, Background1.y, screenWidth, screenHeight };
    Background5 = { Background1.width, Background1.y, screenWidth, screenHeight };
    Background6 = { -Background1.width, -Background1.height, screenWidth, screenHeight };
    Background7 = { Background1.width, -Background1.height, screenWidth, screenHeight };
    Background8 = { -Background1.width, Background1.height, screenWidth, screenHeight };
    Background9 = { Background1.width, Background1.height, screenWidth, screenHeight };

}