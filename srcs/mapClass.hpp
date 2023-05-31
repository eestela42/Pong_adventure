#ifndef MAPCLASS_HPP
# define MAPCLASS_HPP

#include <iostream>
#include <vector>

class gameClass;
class mapClass{
public:
    std::vector<std::string> lines;
    int width;
    int height;
    int cote;

    mapClass(std::string filename);

    // void   setMap(std::string filename);
    void   render(gameClass &game);
    bool   collision(int x, int y);
};

#endif