#include "cowardKid.hpp"

kid::type cowardKid::getType(){ return kidType;}

void cowardKid::react(kid *opponent){
    addAnger(FIVE);
    if(opponent->getAnger() > ANGER_THRESHOLD)
        die();
}
