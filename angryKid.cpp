#include "angryKid.hpp"

kid::type angryKid::getType(){ return kidType;}

void angryKid::fight(){
    radius *= POINT_EIGHT;
    anger += FIVE;
}

void angryKid::negotiate(kid*opponent){
    radius = (1 - ((opponent->getCourage() + opponent->getCharisma())/TWOHUNDRED))*POINT_EIGHT*(opponent->getRadius());
    std::cout << "angry negotiate" << std::endl;
}

void angryKid::react(kid *opponent){
    if(opponent -> getAnger() > ANGER_THRESHOLD)
        if(radius < opponent->getRadius())
            fight();
    if(opponent -> getCourage() > COURAGE_THRESHOLD && opponent ->getCharisma() > CHARISMA_THRESHOLD)
        negotiate(opponent);
}