#include "gameClass.hpp"

gameClass::gameClass(std::string filename): screenWidth(1200), screenHeight(900), map(filename, this), cam_y(0)
{
	menu = new menuClass();
    InitWindow(screenWidth, screenHeight, "BorderClone");
    SetTargetFPS(120);
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
			break;
    }
	this->gameloop();
}

void gameClass::update()
{
	tick++;
	if (cam_y > - map.zero)
		cam_y -= 0.02 + 0.1 * IsKeyDown(KEY_LEFT_SHIFT);

	paddle->move();
	std::list<std::list<ballClass>::iterator> to_delete;
	for (auto it = balls.begin(); it != balls.end(); it++)
		if (it->move())	{
			to_delete.push_back(it);
			if (balls.size() == 1)
				return ;
		}
	for (auto it = to_delete.begin(); it != to_delete.end(); it++)
		balls.erase(*it);
	if (IsKeyPressed(KEY_SPACE))
		balls.push_back(ballClass(this, 0, paddle->x, paddle->y, 0, 0.5));
}

void	gameClass::gameloop()
{
	tick = 0;
	for (int i = -3; i < 4; i++)
		balls.push_back(ballClass(this, i, screenWidth/2, screenHeight/2, (float)i / 5, -0.5));
	paddle = new paddleClass(this);
	while (!WindowShouldClose())
	{
		for (int i = 0; i < 5; i++)
			update();
		
		BeginDrawing();
		ClearBackground(BLACK);
		
		map.render(*this);
		for (auto &ball : balls)
			ball.render();
		paddle->render();
		
		EndDrawing();
	}
	delete paddle;
}