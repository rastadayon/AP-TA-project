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

float kid::getPosX(){ return posX;}

float kid::getPosY(){ return posY;}

bool kid::isAlive(){ return alive;}

bool kid::isFragile(){ return fragile;}

std::vector<kid *> kid::getHitKids(){ return hitKids;}

void kid::addAnger(float number){
    anger += number;
}

std::string kid::anounceDead(){
    if(!alive)
        return DEAD_ANOUNCEMENT + std::to_string(id);
}

void kid::die(){
    alive = false;
    if(anouncedDead != true)
        std::cout << anounceDead() << std::endl;
    anouncedDead = true;
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

void kid::changePos(float newPosX, float newPosY){
    posX = newPosX;
    posY = newPosY;
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

std::tuple<float, float> getVerticalTangentPoint(float height, float xi, float yi, float xf, float yf){
    if(xi == xf)
        return std::tuple<float,float>(xi, height);
    float m = (yf-yi)/(xf-xi);
    float x = (height - yi + m*xi)/m;
    return std::tuple<float,float>(x,height);
}

std::tuple<float, float> getHorizontalTangentPoint(float width, float xi, float yi, float xf, float yf){
    float m = (yf-yi)/(xf-xi);
    float y = m*width - m*xi + yi;
    return std::tuple<float, float>(width, y);
}

float getDistance(float x1, float x2, float y1, float y2){
    return(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)));
}

std::tuple<float, float> kid::getTangentPoint(wall *w){
    std::tuple<float, float> tangentPoint;
    if(w->getOrientation() == wall::Horizontal || w->getOrientation() == wall::oneBrick){
        if(isMovingDown())
            tangentPoint = getHorizontalTangentPoint(std::get<1>(w->getFirstBrick()->getCoordinate())+1+radius, 
            posX, posY, finalEstimatedX, finalEstimatedY);
        if(isMovingUp())
            tangentPoint = getHorizontalTangentPoint(std::get<1>(w->getFirstBrick()->getCoordinate())-radius,
            posX, posY, finalEstimatedX, finalEstimatedY);
    }
    if(w->getOrientation() == wall::Vertical || w->getOrientation() == wall::oneBrick){
        if(isMovingRight())
            tangentPoint = getVerticalTangentPoint(std::get<0>(w->getFirstBrick()->getCoordinate())-radius,
            posX, posY, finalEstimatedX, finalEstimatedY);
        if(isMovingLeft())
            tangentPoint = getVerticalTangentPoint(std::get<0>(w->getFirstBrick()->getCoordinate())+1+radius,
            posX, posY, finalEstimatedX, finalEstimatedY);
    }
    return tangentPoint;
}

wall* kid::hittingWall(){
    float leastDistance = INFINITY;
    float distance;
    std::tuple<float, float> tangentPoint;
    wall* hittingWall = NULL;
    for (int i = 0; i < closestwalls.size(); i++){
        tangentPoint = getTangentPoint(closestwalls[i]);    
        distance = getDistance(posX, std::get<0>(tangentPoint), posY, std::get<1>(tangentPoint));
        if(distance < leastDistance){
            leastDistance = distance;
            hittingWall = closestwalls[i];
        }
    }
    return hittingWall;
}

bool ifCollideWithHorizontalLine(float height, float xi, float yi, float xf, float yf, 
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

bool ifCollideWithVerticalLine(float width, float xi, float yi, float xf, float yf,
    float startPointY, float endPointY){
    float m = (yf-yi)/(xf-xi);
    float y = m*width - m*xi + yi;
    if(y >= startPointY && y <= endPointY)
        return true;
    return false;
}

bool kid::isGonnaHitHorizontal(wall *w, float timeStep){
    brick *firstBrick = w->getFirstBrick();
    brick *lastBrick = w->getLastBrick();
    std::tuple<float, float> firstBrcikCoord = firstBrick->getCoordinate();
    std::tuple<float, float> lastBrcikCoord = lastBrick->getCoordinate();
    float firstBrickX = std::get<0>(firstBrcikCoord); float firstBrickY = std::get<1>(firstBrcikCoord);
    float lastBrickX = std::get<0>(lastBrcikCoord); float lastBrickY = std::get<1>(lastBrcikCoord);
    if(isMovingDown()){
        if(firstBrickY+1 >= finalEstimatedY - radius && posY - radius >= firstBrickY+1 && ifCollideWithHorizontalLine(firstBrickY+1,
             posX, posY, finalEstimatedX, finalEstimatedY, firstBrickX, lastBrickX+1))
                return true;
    }
    if(isMovingUp()){
        if(posY + radius <= firstBrickY && finalEstimatedY + radius >= firstBrickY && ifCollideWithHorizontalLine(firstBrickY,
        posX, posY, finalEstimatedX, finalEstimatedY, firstBrickX, lastBrickX+1))
            return true;
    }
    return false;
}

bool kid::isGonnaHitVertical(wall *w, float timeStep){
    brick *firstBrick = w->getFirstBrick();
    brick *lastBrick = w->getLastBrick();
    std::tuple<float, float> firstBrcikCoord = firstBrick->getCoordinate();
    std::tuple<float, float> lastBrcikCoord = lastBrick->getCoordinate();
    float firstBrickX = std::get<0>(firstBrcikCoord); float firstBrickY = std::get<1>(firstBrcikCoord);
    float lastBrickX = std::get<0>(lastBrcikCoord); float lastBrickY = std::get<1>(lastBrcikCoord);
    if(isMovingRight()){
        if(posX + radius <= firstBrickX && finalEstimatedX + radius >= firstBrickX && ifCollideWithVerticalLine(firstBrickX,
        posX, posY, finalEstimatedX, finalEstimatedY, firstBrickY, lastBrickY+1))
            return true;
    }
    if(isMovingLeft()){
        if(posX - radius >= firstBrickX+1 && finalEstimatedX - radius <= finalEstimatedX && ifCollideWithVerticalLine(firstBrickX+1,
        posX, posY, finalEstimatedX, finalEstimatedY, firstBrickY, lastBrickY+1))
            return true;
    }
    return false;
}

bool kid::isGonnaHitWall(wall* w, float timeStep){
    finalEstimatedX = posX + velocityX*timeStep;
    finalEstimatedY = posY + velocityY*timeStep;
    if(w->getOrientation() == wall::Horizontal || w->getOrientation() == wall::oneBrick)
        return isGonnaHitHorizontal(w, timeStep);
    else if(w->getOrientation() == wall::Vertical)
        return isGonnaHitVertical(w, timeStep);
}

void kid::reflect45Degree(std::tuple<float,float> pointCoords, wall *w){
    // if(abs(velocityX) == abs(velocityY))
    // -----------------------------------------------------> do this in the night
}

void kid::reflect90Degree(std::tuple<float,float> pointCoords){
    if(isMovingDown() || isMovingUp()){
        velocityY = -velocityY;
        posX = finalEstimatedX;
        posY = 2*(std::get<1>(pointCoords)) - finalEstimatedY;
    }
    if(isMovingRight() || isMovingLeft()){
        velocityX = -velocityX;
        posY = finalEstimatedY;
        posX = 2*(std::get<0>(pointCoords)) - finalEstimatedX;
    }
}

void kid::addHitKid(kid * k){
    hitKids.push_back(k);
}

bool kid::isKidClose(kid *k){
    if(getDistance(posX, k->getPosX(), posY, k->getPosY()) <= radius + k->getRadius())
        return true;
    return false;
}

void kid::move(float timeStep, int mapSize, std::vector<wall *> walls){
    closestwalls.clear();
    wall* hitWall;
    bool willHit;
    bool hitCorner;
    for (int i = 0; i < walls.size(); i++){
        if(isGonnaHitWall(walls[i], timeStep))
            closestwalls.push_back(walls[i]);
    }
    hitWall = hittingWall();
    if(hitWall == NULL){
        posX = finalEstimatedX;
        posY = finalEstimatedY;
    }
    else{
        std::tuple<float,float> tangentPoint = getTangentPoint(hitWall);
        hitCorner = hitWall->ifCorner(tangentPoint);
        if(hitCorner)
            reflect45Degree(tangentPoint, hitWall);
        else
            reflect90Degree(tangentPoint);
    }
}

void kid::addCourage(int number){
    courage += number;
}

void kid::setVelocityX(float Vx){
    velocityX = Vx;
}

void kid::setVelocityY(float Vy){
    velocityY = Vy;
}

void kid::hit(kid * k){
    float r1 = radius;
    float r2 = k->getRadius();
    float u1x = velocityX;
    float u1y = velocityY;
    float u2x = k->getVelocityX();
    float u2y = k->getVelocityY();
    
    float v1x = ((pow(r1,2) - pow(r2,2))/(pow(r1,2) + pow(r2,2)))*u1x + ((2*pow(r2,2))/(pow(r1,2) + pow(r2,2)))*u2x;
    float v1y = ((pow(r1,2) - pow(r2,2))/(pow(r1,2) + pow(r2,2)))*u1y + ((2*pow(r2,2))/(pow(r1,2) + pow(r2,2)))*u2y;
    float v2x = ((pow(r2,2) - pow(r1,2))/(pow(r1,2) + pow(r2,2)))*u2x + ((2*pow(r1,2))/(pow(r1,2) + pow(r2,2)))*u1x;
    float v2y = ((pow(r2,2) - pow(r1,2))/(pow(r1,2) + pow(r2,2)))*u2y + ((2*pow(r1,2))/(pow(r1,2) + pow(r2,2)))*u1y;

    velocityX = v1x;
    velocityY = v1y;
    k->setVelocityX(v2x);
    k->setVelocityY(v2y);
}

bool kid::ifDied(){
    if(anger >= DEADLY_ANGER_LIMIT || radius <= DEADLY_RADIUS_LIMIT){
        die();
        return true;
    }
    return false;
}

void kid::_break(){
    if(radius <= DEADLY_RADIUS_LIMIT_FOR_BREAKING)
        die();
    
}

std::string kid::getTypeString(){
    std::string kidTypeStr;
    if(kidType == kid::Angry)
        kidTypeStr = ANGRY;
    else if(kidType == kid::Peaceful)
        kidTypeStr = PEACEFUL;
    else if(kidType == kid::Coward)
        kidTypeStr = COWARD;
    return kidTypeStr;
}