#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "ballClass.hpp"
#include "menuClass.hpp"
#include "paddleClass.hpp"
#include "mapClass.hpp"
#include <raylib.h>
#include <list>

class ballClass;

class paddleClass;

class gameClass
{
public:

    std::list<ballClass> balls;
    paddleClass *paddle;
    Texture2D background;
    menuClass *menu;

    int screenWidth;
    int screenHeight;
    mapClass map;

    float cam_y;
    int tick;

    gameClass(std::string filename);
    ~gameClass();
    void gameloop();
    void update();
    void menuloop();
};





#endif