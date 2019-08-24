#ifndef __WALL_H__
#define __WALL_H__

#include <iostream>
#include "brick.hpp"
#include <vector>
#include <string>
#include <tuple>

class wall
{
    public:
        enum orientation {Horizontal, Vertical};
        wall(brick*, brick*, orientation);
        ~wall();
    private:
        brick *start;
        brick *finish;
        orientation wallOrientation;
};




#endif