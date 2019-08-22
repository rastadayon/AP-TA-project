#ifndef __ANGRYKID_H__
#define __ANGRYKID_H__
#include "kid.hpp"
#include <iostream>


class angryKid : public kid{
    public:
        void react(kid*);
        angryKid(/* args */);
        ~angryKid();
        void fight();
        void negotiate(kid*);
        kid::type getType();
};

angryKid::angryKid(/* args */)
{
}

angryKid::~angryKid()
{
}


#endif