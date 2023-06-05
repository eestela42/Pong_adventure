#include "paddleClass.hpp"
#include <iostream>
#include <cmath>

using namespace std;

paddleClass::paddleClass(gameClass *game): game(game), width(100), height(20), speed(1)
{
	x = game->screenWidth/2;
	y = game->screenHeight - height*2;
	coef_width = 1;
}

paddleClass::~paddleClass()
{
}

void	paddleClass::render()
{
	Color color = GREEN;
	if (IsKeyDown(KEY_LEFT_SHIFT))
		color = RED;

	DrawLine(x, y - height/2 - game->cam_y, x, y - height/2 - game->cam_y - game->screenWidth / 2, DARKGRAY);
	DrawRectangle(x - game->map.cote / 2, block_y - game->map.cote / 2 - game->cam_y, game->map.cote, game->map.cote, DARKBLUE);
	DrawRectangle(x - width/2, y - height/2 - game->cam_y, width, height, color);
}

void	paddleClass::move()
{
	float movement = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);

	width /= coef_width;
	coef_width = IsKeyDown(KEY_SPACE) ? 1 : 2;
	cout << width << endl;
	width *= coef_width;
	y = game->screenHeight - height*2 + game->cam_y;

	movement *= speed * (IsKeyDown(KEY_LEFT_SHIFT) ? 2 : 1);
	if (x - width/2 - movement < 0 && movement < 0)
		return ;
	else if ( x + width/2 + movement > game->screenWidth && movement > 0)
		return ;
	x += movement;

	block_y = y - height/2 - game->screenWidth / 4 \
				- sin((float)game->tick / 200) * game->screenWidth / 6;
}