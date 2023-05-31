#include "gameClass.hpp"
#include <raylib.h>

int main(int ac, char **av)
{
	(void) ac;
	gameClass game(av[1]);

	game.menuloop();
	return 0;
}