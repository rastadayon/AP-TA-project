#ifndef __COWARD_H__
#define __COWARD_H__
#include "kid.hpp"
#include <iostream>


class cowardKid : public kid{
    public:
        cowardKid(int id, type kidType, bool fragile, float posX, float posY,
            float velocityX, float velocityY, float radius, float anger, float charisma, float courage);
        void react(kid*);
        kid::type getType();
};

#endif