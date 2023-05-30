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
	DrawRectangle(x - width/2, y - height/2, width, height, RED);
}

void	paddleClass::move(float movement)
{
	if (x - width/2 - movement < 0 && movement < 0)
		return ;
	else if ( x + width/2 + movement > game->screenWidth && movement > 0)
		return ;
	x += movement;

}