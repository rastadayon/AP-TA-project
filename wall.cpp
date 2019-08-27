#include "wall.hpp"

wall::wall(brick *firstBrick, brick *lastBrick, orientation wallOrientation): firstBrick(firstBrick), lastBrick(lastBrick)
    ,wallOrientation(wallOrientation){
    setFourWallCorners();
    setRealWallCorners();
}

bool checkTopRightCorner(brick *b){
    if(!(b->isTopBrick()) && !(b->isTopRightBrick()) && !(b->isRightBrick()))
        return true;
    return false;
}

bool checkTopLeftCorner(brick *b){
    if(!(b->isTopBrick()) && !(b->isTopLeftBrick()) && !(b->isLeftBrick()))
        return true;
    return false;
}

bool checkBottomRightCorner(brick *b){
    if(!(b->isRightBrick()) && !(b->isBottomRightBrick()) && !(b->isBottomBrick()))
        return true;
    return false;
}

bool checkBottomLeftCorner(brick *b){
    if(!(b->isLeftBrick()) && !(b->isBottomLeftBrick()) && !(b->isBottomBrick()))
        return true;
    return false;
}

void wall::setFourWallCorners(){
    std::tuple<float,float> firstPoint = firstBrick->getCoordinate();
    std::tuple<float,float> lastPoint = lastBrick->getCoordinate();
    fourWallCorners.push_back(firstPoint);
    if(wallOrientation == Horizontal || wallOrientation == oneBrick){
        fourWallCorners.push_back(std::make_tuple(std::get<0>(firstPoint), std::get<1>(firstPoint) + 1));
        fourWallCorners.push_back(std:: make_tuple(std::get<0>(lastPoint) + 1, std::get<1>(lastPoint) + 1));
        fourWallCorners.push_back(std:: make_tuple(std::get<0>(lastPoint) + 1, std::get<1>(lastPoint)));
    }
    else if(wallOrientation == Vertical){
        fourWallCorners.push_back(std:: make_tuple(std::get<0>(lastPoint), std::get<1>(lastPoint) + 1));
        fourWallCorners.push_back(std::make_tuple(std::get<0>(lastPoint) + 1, std::get<1>(lastPoint) + 1));
        fourWallCorners.push_back(std:: make_tuple(std::get<0>(lastPoint) + 1, std::get<1>(firstPoint)));
    }
}

void wall::setRealCornerForBrick(brick *b){
    bool topRightCorner, topLeftCorner, bottomRightCorner, bottomLeftCorner;
    topRightCorner = checkTopRightCorner(b);
    topLeftCorner = checkTopLeftCorner(b);
    bottomRightCorner = checkBottomRightCorner(b);
    bottomLeftCorner = checkBottomLeftCorner(b);
    if(topRightCorner)
        realWallCorners.push_back(std:: make_tuple(std::get<0>(b->getCoordinate()) + 1, std::get<1>(b->getCoordinate()) + 1));
    if(topLeftCorner)
        realWallCorners.push_back(std:: make_tuple(std::get<0>(b->getCoordinate()) , std::get<1>(b->getCoordinate()) + 1));
    if(bottomRightCorner)
        realWallCorners.push_back(std:: make_tuple(std::get<0>(b->getCoordinate()) + 1, std::get<1>(b->getCoordinate())));
    if(bottomLeftCorner)
        realWallCorners.push_back(std:: make_tuple(std::get<0>(b->getCoordinate()), std::get<1>(b->getCoordinate())));
}

void wall::setRealWallCorners(){
    setRealCornerForBrick(firstBrick);
    setRealCornerForBrick(lastBrick);
}

brick* wall::getFirstBrick() { return firstBrick;}

brick* wall::getLastBrick() { return lastBrick;}

wall::orientation wall::getOrientation() { return wallOrientation;}

bool wall::ifCorner(std::tuple<float, float> coord){
    for (int i = 0; i < realWallCorners.size(); i++){
        if(coord == realWallCorners[i])
            return true;
    }
    return false;
}