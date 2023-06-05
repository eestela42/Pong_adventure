#include "ballClass.hpp"
#include <cmath>



ballClass::ballClass(gameClass *game, int id, float x, float y, float velo_x, float velo_y):
						game(game), id(id), x(x), y(y), velo_x(velo_x), velo_y(velo_y), radius(5)
{
}

ballClass::~ballClass()
{
}

void	ballClass::render()
{
	DrawCircle(x, y - game->cam_y, radius, RED);
}

// void get_normale()

bool	ballClass::move()
{
	x += velo_x;
	y += velo_y;
	if (x - radius < 0 || x + radius > game->screenWidth)
		velo_x *= -1;

	if (y - radius < game->cam_y){
		velo_y = fabs(velo_y);
		y = radius + game->cam_y;
	}
	else if (y + radius > game->screenHeight + game->cam_y)
		return true;

	if (x + radius > game->paddle->x - game->paddle->width/2 && x - radius < game->paddle->x + game->paddle->width/2)
		if (y + radius > game->paddle->y - game->paddle->height/2) {
			velo_y = -fabs(velo_y);
			velo_x = (x - game->paddle->x) / (game->paddle->width/2);
		}

	if (game->map.collision(x, (y - radius), *this))
		velo_y = fabs(velo_y);
	else if (game->map.collision(x, (y + radius), *this))
		velo_y = -fabs(velo_y);
	else if (game->map.collision((x - radius), y, *this))
		velo_x = fabs(velo_x);
	else if (game->map.collision((x + radius), y, *this))
		velo_x = -fabs(velo_x);

	return false;
}
