#ifndef PADDLECLASS_HPP
#define PADDLECLASS_HPP

#include <iostream>
#include <raylib.h>
#include "gameClass.hpp"

class gameClass;

class paddleClass
{
	
public:
	gameClass *game;
	int 	width;
	int coef_width;
	int 	height;
	float	block_y;

	float 	speed;
	float	x;
	float	y;
	paddleClass(gameClass *game);
	~paddleClass();
	void render();
	void move();
};





#endif