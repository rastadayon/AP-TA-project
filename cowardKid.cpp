#include "cowardKid.hpp"

cowardKid::cowardKid(int id, type kidType, bool fragile, float posX, float posY,
    float velocityX, float velocityY, float radius, float anger, float charisma, float courage)
    :kid(id, type::Coward, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage){}

kid::type cowardKid::getType(){ return kidType;}

void cowardKid::react(kid *opponent){
    addAnger(FIVE);
    if(opponent->getAnger() > ANGER_THRESHOLD)
        die();
}
