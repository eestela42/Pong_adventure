#include "ballClass.hpp"
#include <cmath>



ballClass::ballClass(gameClass *game, int id, float x, float y, float velo_x, float velo_y):
						game(game), id(id), x(x), y(y), velo_x(velo_x), velo_y(velo_y), radius(10)
{
}

ballClass::~ballClass()
{
}

void	ballClass::render(gameClass &game)
{
	DrawCircle(x, y - game.cam_y, radius, RED);
}

// void get_normale()

void	ballClass::move(gameClass &game)
{
	x += velo_x;
	y += velo_y;
	if (x - radius < 0 || x + radius > game.screenWidth)
		velo_x *= -1;

	if (y - radius < game.cam_y){
		velo_y = fabs(velo_y);
		y = radius + game.cam_y;
	}
	else if (y + radius > game.screenHeight + game.cam_y)	{
		velo_y = - fabs(velo_y);
		y = game.screenHeight + game.cam_y - radius;
	}

	if (x + radius > game.paddle->x - game.paddle->width/2 && x - radius < game.paddle->x + game.paddle->width/2)
		if (y + radius > game.paddle->y - game.paddle->height/2 \
			&& y - radius < game.paddle->y + game.paddle->height/2)
			velo_y *= -1;

	if (game.map.collision(x, (y - radius))
		|| game.map.collision(x, (y + radius)))
		velo_y *= -1;
	else if (game.map.collision((x - radius), y)
		|| game.map.collision((x + radius), y))
		velo_x *= -1;
}
