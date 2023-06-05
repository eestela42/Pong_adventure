#ifndef MAPCLASS_HPP
# define MAPCLASS_HPP

#include <iostream>
#include <vector>

class gameClass;
class ballClass;
class mapClass{
public:
    gameClass *game;
    std::vector<std::string> lines;
    int width;
    int height;
    int cote;
    int zero;

    mapClass(std::string filename, gameClass *game);

    // void   setMap(std::string filename);
    void   render(gameClass &game);
    bool   collision(float x, float y, ballClass &ball);
    bool    hit(int x, int y);
};

#endif