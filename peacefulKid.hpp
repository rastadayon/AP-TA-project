#ifndef __PEACEFUL_H__
#define __PEACEFUL_H__
#include "kid.hpp"
#include <iostream>


class peacefulKid : public kid{
    public:
        peacefulKid(int id, type kidType, bool fragile, float posX, float posY, float velocityX, 
            float velocityY, float radius, float anger, float charisma, float courage);
        void react(kid*);
        void negotiate(kid*);
        void unite(kid*);
        void chase(kid*);
        kid::type getType();

};

#endif