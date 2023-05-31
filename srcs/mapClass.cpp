#include "mapClass.hpp"
#include "gameClass.hpp"
#include <fstream>
#include <iostream>
#include "raylib.h"

using namespace std;

mapClass::mapClass(string filename)
{
    fstream map(filename);
    if (map.is_open())
    {
        string line;
        while (getline(map, line))
        {
            cout << line << endl;
            lines.push_back(line);
            // if (line.find("w") != string::npos)
            // {
            //     px = line.find("w");
            //     py = lines.size() - 1;
            //     lines[py][px] = ' ';
            // }
        }
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    map.close();
    width = lines[0].size();
    height = lines.size();
}

void mapClass::render(gameClass &game)
{
    int zero = lines.size() * cote - game.screenHeight + game.cam_y;
    cote = game.screenWidth / width;

    for (uint y = 0; y < lines.size(); y++)
    {
        for (uint x = 0; x < lines[y].size(); x++)
        {
            if (lines[y][x] == '1')
                DrawRectangle(x * cote, y * cote - zero, cote, cote, WHITE);
            else if (lines[y][x] == '=')
                DrawRectangle(x * cote, y * cote - zero, cote, cote, GRAY);
        }
    }
}

bool mapClass::collision(int x, int y)
{
    y += height * cote;
    x /= cote;
    y /= cote;
    if (x < 0 || y < 0 || x >= width || y >= height)
        return false;
    cout << "x: " << x << " y: " << y << endl;
    cout << lines[y][x] << endl;
    if (lines[y][x] == '1')
        return true;
    return false;
}