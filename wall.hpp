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
        enum orientation {Horizontal, Vertical, oneBrick};
        wall(brick*, brick*, orientation);
        brick* getFirstBrick();
        brick* getLastBrick();
        orientation getOrientation();
    private:
        brick *firstBrick;
        brick *lastBrick;
        orientation wallOrientation;
        std::vector<std::tuple<float, float>> fourWallCorners;
        std::vector<std::tuple<float, float>> realWallCorners;
        void setFourWallCorners();
        void setRealWallCorners();
        void setRealCornerForBrick(brick *);

};




#endif