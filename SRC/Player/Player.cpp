#include "Player.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Ground/Ground.h"


extern int screenHeight;
extern int screenWidth;

extern Rectangle Background1;
extern Vector2 topLeft;
extern Vector2 bottomRight;

Texture playerTex;

int Rotation = 0;

Rectangle player{ screenWidth / 2 - 15, screenHeight / 2 - 15, 30, 30 };
Rectangle playerSource{ 0, 0, 30, 30 };
Rectangle camera{ 0, 0, screenWidth, screenHeight };

void playerUpdate()
{
    if (IsKeyDown(KEY_W))
    {
        Rotation = 0;
    }
    if (IsKeyDown(KEY_A))
    {
        Rotation = 90;
    }
    if (IsKeyDown(KEY_S))
    {
        Rotation = 180;
    }
    if (IsKeyDown(KEY_D))
    {
        Rotation = 270;
    }
}

void playerDraw()
{

    Vector2 PlayerPos{ player.width / 2, player.height / 2 };
    DrawTexturePro(playerTex, playerSource, player, PlayerPos, Rotation, WHITE);

}