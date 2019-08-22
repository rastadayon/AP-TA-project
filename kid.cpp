#include "kid.hpp"

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
        return DEAD_ANOUNCEMENT + std::to_string(number);
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
