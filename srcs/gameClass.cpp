#include "gameClass.hpp"

gameClass::gameClass(): screenWidth(1200), screenHeight(900)
{
	menu = new menuClass();
    InitWindow(screenWidth, screenHeight, "BorderClone");
    SetTargetFPS(60);
    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
    background = LoadTexture("sprites/background.png");
}

gameClass::~gameClass()
{
}

void	gameClass::loop()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
		ClearBackground(BLACK);
		// DrawTexture(background, 0, 0, WHITE);
		
		if (!menu->render())
			return ;
		if (menu->render() == 1)
			this->render();
		EndDrawing();
    }
}

void	gameClass::render()
{
	ball = new ballClass(this, 0, screenWidth/2, screenHeight/2, 4, -9.5);
	paddle = new paddleClass(this);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		ball->move();
		ball->render();
		if (IsKeyDown(KEY_RIGHT))
			paddle->move(paddle->speed);
		if (IsKeyDown(KEY_LEFT))
			paddle->move(-paddle->speed);
		paddle->render();
		EndDrawing();
	}
}