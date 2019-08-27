#include "angryKid.hpp"

angryKid::angryKid(int id, kid::type kidType, bool fragile, float posX, float posY,
    float velocityX, float velocityY, float radius, float anger, float charisma, float courage)
    :kid(id, type::Angry, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage){}

kid::type angryKid::getType(){ return kidType;}

void angryKid::fight(){
    radius *= POINT_EIGHT;
    anger += FIVE;
}

void angryKid::negotiate(kid*opponent){
    radius = (1 - ((opponent->getCourage() + opponent->getCharisma())/TWOHUNDRED))*POINT_EIGHT*(opponent->getRadius());
}

void angryKid::react(kid *opponent){
    if(opponent -> getAnger() > ANGER_THRESHOLD)
        if(radius < opponent->getRadius())
            fight();
    if(opponent -> getCourage() > COURAGE_THRESHOLD && opponent ->getCharisma() > CHARISMA_THRESHOLD)
        negotiate(opponent);
}