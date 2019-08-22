#ifndef __COWARD_H__
#define __COWARD_H__
#include "kid.hpp"
#include <iostream>


class cowardKid : public kid{
    public:
        void react(kid*);
        cowardKid(/* args */);
        ~cowardKid();
        kid::type getType();
};

#endif