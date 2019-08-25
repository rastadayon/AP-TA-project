#ifndef __BRICK_H__
#define __BRICK_H__

#include <iostream>
#include <tuple>
#define BRICK_SIZE 1


class brick
{
    public:
        enum brickType {TOPBRICK, FILE};
        brick(bool, bool, bool, bool, bool, bool, bool, bool, float, float);
        brick(float, float);
        bool isRightBrick();
        bool isLeftBrick();
        bool isTopBrick();
        bool isBottomBrick();
        bool isTopRightBrick();
        bool isTopLeftBrick();
        bool isBottomRightBrick();
        bool isBottomLeftBrick();
        std::tuple<float,float> getCoordinate();

    private:
        bool rightSideBrick;
        bool leftSideBrick;
        bool topSideBrick;
        bool bottomSideBrick;
        bool topRightBrick;
        bool topLeftBrick;
        bool bottomRightBrick;
        bool bottomLeftBrick;
        std::tuple<float, float> coordinate;
};


#endif