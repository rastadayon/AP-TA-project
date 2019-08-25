#include "brick.hpp"

brick::brick(bool rightSideBrick, bool leftSideBrick, bool topSideBrick, bool bottomSideBrick,
bool topRightBrick, bool topLeftBrick, bool bottomRightBrick, bool bottomLeftBrick, float posX, float posY)
:rightSideBrick(rightSideBrick), leftSideBrick(leftSideBrick), topSideBrick(topSideBrick),
topRightBrick(topRightBrick), topLeftBrick(topLeftBrick), bottomRightBrick(bottomRightBrick), 
bottomLeftBrick(bottomLeftBrick){
    coordinate = std::make_tuple(posX, posY);
}

bool brick::isRightBrick() {return rightSideBrick;}
bool brick::isLeftBrick() {return leftSideBrick;}
bool brick::isTopBrick() {return topSideBrick;}
bool brick::isBottomBrick() {return bottomSideBrick;}
bool brick::isTopRightBrick() {return topRightBrick;}
bool brick::isTopLeftBrick() {return topLeftBrick;}
bool brick::isBottomRightBrick() {return bottomRightBrick;}
bool brick::isBottomLeftBrick() {return bottomLeftBrick;}

std::tuple<float,float> brick::getCoordinate(){ return coordinate;}