#ifndef __PEACEFUL_H__
#define __PEACEFUL_H__
#include "kid.hpp"
#include <iostream>


class peacefulKid : public kid{
    public:
        void react(kid*);
        peacefulKid(/* args */);
        ~peacefulKid();
        void negotiate(kid*);
        void unite(kid*);
        void chase(kid*);

};

#endif