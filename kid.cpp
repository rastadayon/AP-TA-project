#include "kid.hpp"

kid::kid(int id, type kidType, bool fragile, float posX, float posY,
    float velocityX, float velocityY, float radius, float anger, float charisma, float courage):
    id(id), kidType(kidType), fragile(fragile), posX(posX), posY(posY), velocityX(velocityX), 
    velocityY(velocityY),radius(radius), anger(anger), charisma(charisma), courage(courage) {}

kid::type kid::getType(){ return kidType;}

float kid::getAnger(){ return anger;}

float kid::getCharisma(){ return charisma;}

float kid::getCourage(){ return courage;}

float kid::getRadius(){ return radius;}

float kid::getVelocityX(){ return velocityX;}

float kid::getVelocityY(){ return velocityY;}

void kid::addAnger(float number){
    anger += number;
}

std::string kid::anounceDead(){
    if(!alive)
        return DEAD_ANOUNCEMENT + std::to_string(id);
}

void kid::die(){
    alive = false;
    std::cout << anounceDead() << std::endl;
}

void kid::addCourage(float number){
    courage += number;
}

void kid::changeVelocity(float Vx, float Vy){
    velocityX = Vx;
    velocityY = Vy;
}

void kid::addCharisma(float number){
    charisma += number;
}

void kid::negotiate(kid *apponent){}

float kid::getVelocitySize(){
    return sqrt(velocityX*velocityX + velocityY*velocityY);
}

void kid::moveTinyBit(){
    finalPosX += velocityX/getVelocitySize() * VIRTUAL_TIMESTEP;
    finalPosY += velocityY/getVelocitySize() * VIRTUAL_TIMESTEP;
    std::cerr<<"finalPosX = " << finalPosX <<std::endl;
    std::cerr<<"finalPosY = " << finalPosY <<std::endl;
}

bool kid::isMovingRight(){
    if(velocityX > 0)
        return true;
    return false;
}

bool kid::isMovingLeft(){
    if(velocityX < 0)
        return true;
    return false;
}

bool kid::isMovingUp(){
    if(velocityY > 0)
        return true;
    return false;
}

bool kid::isMovingDown(){
    if(velocityY < 0)
        return true;
    return false;
}

bool kid::isHorizontalWallClose(wall *w){
    brick *firstBrick = w->getFirstBrick();
    brick *lastBrick = w->getLastBrick();
    std::tuple<float,float> firstCords = firstBrick->getCoordinate();
    std::tuple<float,float> lastCords = lastBrick->getCoordinate();
    if(isMovingDown()) //only check top side 
        if(finalPosY - std::get<1>(firstCords)+1 <= radius + CLOSENESS_THRESHOLD)
            return true;
    if(isMovingUp())
        if(std::get<1>(firstCords) - finalPosY <= radius +CLOSENESS_THRESHOLD)
            return true;
    if(isMovingLeft())
        if(finalPosX - std::get<0>(lastCords)+1 <= radius + CLOSENESS_THRESHOLD)
            return true;
    if(isMovingRight())
        if(std::get<0>(firstCords) - finalPosX <= radius + CLOSENESS_THRESHOLD)
            return true;
    return false;
}

bool kid::isVerticalWallClose(wall *w){
    brick *firstBrick = w->getFirstBrick();
    brick *lastBrick = w->getLastBrick();
    std::tuple<float,float> firstCords = firstBrick->getCoordinate();
    std::tuple<float,float> lastCords = lastBrick->getCoordinate();
    if(isMovingDown())
        if(finalPosY - std::get<1>(lastCords)+1 <= radius + CLOSENESS_THRESHOLD)
            return true;
    if(isMovingUp())
        if(std::get<1>(firstCords) - finalPosY <= radius + CLOSENESS_THRESHOLD)
            return true;
    if(isMovingLeft())
        if(finalPosX - std::get<0>(firstCords)+1 <= radius + CLOSENESS_THRESHOLD)
            return true;
    if(isMovingRight())
        if(std::get<0>(firstCords) - finalPosX <= radius + CLOSENESS_THRESHOLD)
            return true;
    return false;
}

bool kid::isWallClose(wall *w){
    bool horizontalWallClose = false, verticalWallClose = false;
    if(w->getOrientation() == wall::Horizontal || w->getOrientation() == wall::oneBrick)
        horizontalWallClose = isHorizontalWallClose(w);
    if(w->getOrientation() == wall::Vertical)
        verticalWallClose = isVerticalWallClose(w);
    if(verticalWallClose || horizontalWallClose)
        return true;
    return false;
}

void kid::setCloseWalls(std::vector<wall *>walls){
    closestwalls.clear();
    for (int i = 0; i < walls.size(); i++){
        if(isWallClose(walls[i]))
            closestwalls.push_back(walls[i]);
    }
}

wall* kid::hittingWall(float stepsWent, float timeStep){
    wall* hittingWall = NULL;
    float leastDistance;
    float totalSteps = 1/VIRTUAL_TIMESTEP * timeStep * getVelocitySize();
    float finalDestX, finalDestY;
    for (int i = 0; i < closestwalls.size(); i++){
        if(isMovingDown()){
            
            if(isMovingRight()){

            }
        }
    }
    return hittingWall;
}

bool collideWithHorizontalLine(float height, float xi, float yi, float xf, float yf, 
    float startingPointX, float endingPointX){
    if(xf == xi)
        if((yi >= height && yf <= height) || (yi <= height && yf >= height))
            return true;
    float m = (yf-yi)/(xf-xi);
    float x = (height - yi + m*xi)/m;
    if(x >= startingPointX && x <= endingPointX)
        return true;
    return false;
}

bool collideWithVerticalLine(float width, float xi, float yi, float xf, float yf,
    float startPointY, float endPointY){
    float m = (yf-yi)/(xf-xi);
    float y = m*width - m*xi + yi;
    if(y >= startPointY && y <= endPointY)
        return true;
    return false;
}

bool kid::isGonnaHitHorizontal(wall *w, float timeStep){
    float finalEstimatedX, finalEstimatedY;
    finalEstimatedX += velocityX*timeStep;
    finalEstimatedY += velocityY*timeStep;
    brick *firstBrick = w->getFirstBrick();
    brick *lastBrick = w->getLastBrick();
    std::tuple<float, float> firstBrcikCoord = firstBrick->getCoordinate();
    std::tuple<float, float> lastBrcikCoord = lastBrick->getCoordinate();
    float firstBrickX = std::get<0>(firstBrcikCoord); float firstBrickY = std::get<1>(firstBrcikCoord);
    float lastBrickX = std::get<0>(lastBrcikCoord); float lastBrickY = std::get<1>(lastBrcikCoord);
    if(isMovingDown()){
        if(firstBrickY+1 >= finalEstimatedY - radius && posY - radius >= firstBrickY+1 && collideWithHorizontalLine(firstBrickY+1,
             posX, posY, finalEstimatedX, finalEstimatedY, firstBrickX, lastBrickX+1))
                return true;
        if(isMovingRight())
            if(posX + radius <= firstBrickX && finalEstimatedX + radius >= firstBrickX && collideWithVerticalLine(firstBrickX,
             posX, posY, finalEstimatedX, finalEstimatedY, firstBrickY, firstBrickY+1))
                return true;
        if(isMovingLeft())
            if(posX - radius >= lastBrickX+1 && lastBrickX+1 >= finalEstimatedX - radius && collideWithVerticalLine(lastBrickX+1,
             posX, posY, finalEstimatedX, finalEstimatedY, lastBrickY, lastBrickY+1))
                return true;
    }
    if(isMovingUp()){
        if(posY + radius <= firstBrickY && finalEstimatedY + radius >= firstBrickY && collideWithHorizontalLine(firstBrickY,
        posX, posY, finalEstimatedX, finalEstimatedY, firstBrickX, lastBrickX+1))
            return true;
        if(isMovingRight())
            if(posX + radius <= firstBrickX && finalEstimatedX + radius >= firstBrickX && collideWithVerticalLine(firstBrickX,
             posX, posY, finalEstimatedX, finalEstimatedY, firstBrickY, firstBrickY+1))
                return true;
        if(isMovingLeft())
            if(posX - radius >= lastBrickX+1 && lastBrickX+1 >= finalEstimatedX - radius && collideWithVerticalLine(lastBrickX+1,
             posX, posY, finalEstimatedX, finalEstimatedY, lastBrickY, lastBrickY+1))
                return true;
    }
    return false;
}

bool kid::isGonnaHitVertical(wall *w, float timeStep){
    
}

bool kid::isGonnaHitWall(wall* w, float timeStep){
    
    if(w->getOrientation == wall::Horizontal || w->getOrientation() == wall::oneBrick){
        
    }
}

void kid::move(float timeStep, int mapSize, std::vector<wall *> walls){
    wall* hittingWall;
    bool willHit;
    for (int i = 0; i < walls.size(); i++){
        willHit = isGonnaHitWall(walls[i]);
    }
    
}

