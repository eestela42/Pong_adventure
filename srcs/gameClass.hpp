#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "ballClass.hpp"
#include "menuClass.hpp"
#include "paddleClass.hpp"
#include "mapClass.hpp"
#include <raylib.h>

class ballClass;

class paddleClass;

class gameClass
{
public:

    ballClass *ball;
    paddleClass *paddle;
    Texture2D background;
    menuClass *menu;

    int screenWidth;
    int screenHeight;
    mapClass map;

    float cam_y;

    gameClass(std::string filename);
    ~gameClass();
    void gameloop();
    void menuloop();
};





#endif