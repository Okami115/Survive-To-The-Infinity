#include <iostream>
#include "../LIB/INCLUDE/raylib.h"


const int screenWidth = 1920;
const int screenHeight = 1080;

int velocity = 500;

const int maxGrounds = 9;

void playerUpdate();
void playerDraw(); 
void backgroundMove();

struct point
{
    int x;
    int y;
};

Rectangle player {screenWidth / 2 - 10, screenHeight / 2 - 10, 20, 20 };
Rectangle camera {0, 0, screenWidth, screenHeight };

point topLeft{ -screenWidth, -screenHeight };
point bottomRight{ screenWidth, screenHeight };

Rectangle Background1{ 0, 0, screenWidth, screenHeight };
Rectangle Background2{ Background1.x, -Background1.height, screenWidth, screenHeight };
Rectangle Background3{ Background1.x, Background1.height, screenWidth, screenHeight };
Rectangle Background4{ -Background1.width, Background1.y, screenWidth, screenHeight };
Rectangle Background5{ Background1.width, Background1.y, screenWidth, screenHeight };
Rectangle Background6{ -Background1.width, -Background1.height, screenWidth, screenHeight };
Rectangle Background7{ Background1.width, -Background1.height, screenWidth, screenHeight };
Rectangle Background8{ -Background1.width, Background1.height, screenWidth, screenHeight };
Rectangle Background9{ Background1.width, Background1.height, screenWidth, screenHeight };


int main()
{

    InitWindow(screenWidth, screenHeight, "Survive To The Infinity - Okami Industries - V0.1");
           
    while (!WindowShouldClose())    
    {
       
        playerUpdate();

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

        BeginDrawing();

        ClearBackground(BLACK);
        
        DrawText("V0.1", 0, 0, 5, RED);

        playerDraw();

        EndDrawing();
        
    }


    CloseWindow();       
}

void playerUpdate()
{
    int count;


    backgroundMove();

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
}

void playerDraw()
{
    DrawRectangle(Background1.x, Background1.y, Background1.width, Background1.height, LIME);
    DrawRectangle(Background2.x, Background2.y, Background2.width, Background2.height, YELLOW);
    DrawRectangle(Background3.x, Background3.y, Background3.width, Background3.height, GRAY);
    DrawRectangle(Background4.x, Background4.y, Background4.width, Background4.height, BROWN);
    DrawRectangle(Background5.x, Background5.y, Background5.width, Background5.height, BLUE);
    DrawRectangle(Background6.x, Background6.y, Background6.width, Background6.height, SKYBLUE);
    DrawRectangle(Background7.x, Background7.y, Background7.width, Background7.height, PINK);
    DrawRectangle(Background8.x, Background8.y, Background8.width, Background8.height, VIOLET);
    DrawRectangle(Background9.x, Background9.y, Background9.width, Background9.height, RAYWHITE);
    DrawRectangle(player.x, player.y, player.width, player.height, RED);

}

void backgroundMove()
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

}
