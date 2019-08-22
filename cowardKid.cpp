#include "cowardKid.hpp"

void cowardKid::react(kid *opponent){
    addAnger(FIVE);
    if(opponent->getAnger() > ANGER_THRESHOLD)
        die();
}