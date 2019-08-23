#ifndef __ANGRYKID_H__
#define __ANGRYKID_H__
#include "kid.hpp"
#include <iostream>


class angryKid : public kid{
    public:
        angryKid(int id, kid::type kidType, bool fragile, float posX, float posY,
        float velocityX, float velocityY, float radius, float anger, float charisma, float courage);
        void react(kid*);
        void fight();
        void negotiate(kid*);
        kid::type getType();
};



#endif