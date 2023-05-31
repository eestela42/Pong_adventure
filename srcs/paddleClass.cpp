#include "paddleClass.hpp"

paddleClass::paddleClass(gameClass *game): game(game), width(100), height(20), speed(10)
{
	x = game->screenWidth/2;
	y = game->screenHeight - height*2;
}

paddleClass::~paddleClass()
{
}

void	paddleClass::render()
{
	DrawRectangle(x - width/2, y - height/2 - game->cam_y, width, height, RED);
}

void	paddleClass::move()
{
	float movement = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	y = game->screenHeight - height*2 + game->cam_y;

	movement *= speed;
	if (x - width/2 - movement < 0 && movement < 0)
		return ;
	else if ( x + width/2 + movement > game->screenWidth && movement > 0)
		return ;
	x += movement;

}