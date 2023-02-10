#include "Player.h"

#include "../../LIB/INCLUDE/raylib.h"
#include "../Ground/Ground.h"


extern int screenHeight;
extern int screenWidth;

extern Rectangle Background1;
extern Vector2 topLeft;
extern Vector2 bottomRight;

Texture playerCurrentTexture;

Texture playerFront;
Texture playerBack;

int Rotation = 0;

Rectangle player{ screenWidth / 2, screenHeight / 2, 60, 60 };
Rectangle playerSource{ 0, 0, 30, 30 };
Rectangle camera{ 0, 0, screenWidth, screenHeight };

void playerUpdate()
{
    if (IsKeyDown(KEY_W))
    {
        playerCurrentTexture = playerBack;
    }
    if (IsKeyDown(KEY_A))
    {
        
    }
    if (IsKeyDown(KEY_S))
    {
        playerCurrentTexture = playerFront;
    }
    if (IsKeyDown(KEY_D))
    {
        
    }

}

void playerDraw()
{

    Vector2 PlayerPos{ player.width / 2, player.height / 2 };
    DrawTexturePro(playerCurrentTexture, playerSource, player, PlayerPos, Rotation, WHITE);

}