#ifndef __ANGRYKID_H__
#define __ANGRYKID_H__
#include "kid.hpp"
#include <iostream>

class angryKid{
    public:
        virtual void react(kid*);
        angryKid(/* args */);
        ~angryKid();
};

angryKid::angryKid(/* args */)
{
}

angryKid::~angryKid()
{
}


#endif