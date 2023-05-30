#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "ballClass.hpp"
#include "menuClass.hpp"
#include "paddleClass.hpp"
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

    gameClass();
    ~gameClass();
    void render();
    void loop();
};





#endif