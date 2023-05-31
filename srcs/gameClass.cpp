#include "gameClass.hpp"

gameClass::gameClass(std::string filename): screenWidth(1200), screenHeight(900), map(filename), cam_y(0)
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

void	gameClass::menuloop()
{
    while (!WindowShouldClose())
    {
		
		if (!menu->render())
			return ;
		if (menu->render() == 1)
			this->gameloop();
    }
}

void	gameClass::gameloop()
{
	ball = new ballClass(this, 0, screenWidth/2, screenHeight/2, 4, -9.5);
	paddle = new paddleClass(this);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		
		cam_y -= 0.3;
		ball->move(*this);
		paddle->move();
		
		map.render(*this);
		ball->render(*this);
		paddle->render();
		
		EndDrawing();
	}
}