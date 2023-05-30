#include "ballClass.hpp"



ballClass::ballClass(gameClass *game, int id, float x, float y, float velo_x, float velo_y):
						game(game), id(id), x(x), y(y), velo_x(velo_x), velo_y(velo_y), radius(5)
{
}

ballClass::~ballClass()
{
}

void	ballClass::render()
{
	DrawCircle(x, y, radius*2, RED);
}

void	ballClass::move()
{
	x += velo_x;
	y += velo_y;
	if (x < 0 || x > game->screenWidth)
		velo_x *= -1;
	if (y < 0 || y > game->screenHeight)
		velo_y *= -1;
	if (y + radius > game->paddle->y - game->paddle->height/2 && y - radius < game->paddle->y + game->paddle->height/2
		&& x + radius > game->paddle->x - game->paddle->width/2 && x - radius < game->paddle->x + game->paddle->width/2)
		velo_y *= -1;
}
