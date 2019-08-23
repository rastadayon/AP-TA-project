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