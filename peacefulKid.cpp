#include "peacefulKid.hpp"
void peacefulKid::negotiate(kid *opponent){
    radius = (1 - ((opponent->getCourage() + opponent->getCharisma())/TWOHUNDRED))*POINT_EIGHT*(opponent->getRadius());
    addCourage(-FIVE);
    std::cout << "peaceful negotiate" << std::endl;
}

float mean(float first, float second){
    return (first+second)/TWO;
}

void peacefulKid::chase(kid* opponent){
    float newVelocityX = mean(velocityX, opponent->getVelocityX());
    float newVelocityY = mean(velocityY, opponent->getVelocityY());
    changeVelocity(newVelocityX, newVelocityY);
    opponent->changeVelocity(newVelocityX, newVelocityY);
}

void peacefulKid::unite(kid* opponent){
    chase(opponent);
    addCharisma(TWO);
    addCourage(TWO);
}

void peacefulKid::react(kid *opponent){
    if(opponent->getAnger() > ANGER_THRESHOLD && opponent->getCourage() > COURAGE_THRESHOLD)
        negotiate(opponent);
    if(opponent->getCourage() > COURAGE_THRESHOLD && opponent->getCharisma() > CHARISMA_THRESHOLD)
        unite(opponent);
}

kid::type peacefulKid::getType(){ return kidType;}