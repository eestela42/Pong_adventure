#ifndef BALLCLASS_HPP
#define BALLCLASS_HPP

#include <iostream>
#include <raylib.h>
#include "gameClass.hpp"

class gameClass;

class ballClass
{
public:
    gameClass *game;
    int id;
    float x;
    float y;
    float velo_x;
    float velo_y;
    float radius;
    
    ballClass(gameClass *game, int id, float x, float y, float velo_x, float velo_y);
    ~ballClass();
    void render();
    bool move();
};





#endif