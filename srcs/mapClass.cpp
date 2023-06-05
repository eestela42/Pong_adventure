#include "mapClass.hpp"
#include "gameClass.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include "raylib.h"

using namespace std;

mapClass::mapClass(string filename, gameClass *game) : game(game)
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
    zero = height * cote - game.screenHeight;
    cote = game.screenWidth / width;

    for (uint y = 0; y < lines.size(); y++)
    {
        for (uint x = 0; x < lines[y].size(); x++)
        {
            if (lines[y][x] == '1')
                DrawRectangle(x * cote, y * cote - zero - (int) game.cam_y, cote, cote, WHITE);
            else if (lines[y][x] == '=')
                DrawRectangle(x * cote, y * cote - zero - (int) game.cam_y, cote, cote, GRAY);
            else if (lines[y][x] == 'O')
                DrawRectangle(x * cote, y * cote - zero - (int) game.cam_y, cote, cote, BLUE);
            else if (lines[y][x] == 'G')
                DrawRectangle(x * cote, y * cote - zero - (int) game.cam_y, cote, cote, PURPLE);
            else if (lines[y][x] == '#')
                DrawRectangle(x * cote, y * cote - zero - (int) game.cam_y, cote, cote, RED);
        }
    }
}

bool mapClass::hit(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return false;
    if (string("23456789").find(lines[y][x]) != string::npos)   {
        lines[y][x]--;
        return true;
    }
    if (lines[y][x] == '1') {
        lines[y][x] = ' ';
        return true;
    }
    return false;
}

bool mapClass::collision(float x, float y, ballClass &ball)
{
    if (game->paddle->block_y - cote/2 < y && \
        game->paddle->block_y + cote/2 > y && \
        game->paddle->x - cote/2 < x && \
        game->paddle->x + cote/2 > x)
            return true;

    y += zero;
    x /= cote;
    y /= cote;
    if (x < 0 || y < 0 || x >= width || y >= height)
        return false;
    // cout << "x: " << x << " y: " << y << endl;
    // cout << lines[y][x] << endl;

    if (lines[y][x] == '#') {
        for (int i = -2; i < 3; i++)
            for (int j = i - 3; j < 3 - i +1; j++)
                hit(x + i, y + j);
        lines[y][x] = ' ';
        return true;
    }
    if (lines[y][x] == 'G')
        return true;
    if (lines[y][x] == 'O') {
        lines[y][x] = ' ';
        game->balls.push_back(ballClass(game, 0, ball.x, ball.y, \
            ball.velo_x + 0.1 * ball.velo_y, ball.velo_y - 0.1 * ball.velo_x));
        game->balls.push_back(ballClass(game, 0, ball.x, ball.y, \
            ball.velo_x - 0.1 * ball.velo_y, ball.velo_y + 0.1 * ball.velo_x));
        return false;
    }
    return hit(x, y);
}