#ifndef __IMPACT_H__
#define __IMPACT_H__
#include "kid.hpp"
#include "peacefulKid.hpp"

#define MIN_KIDS_NEEDED_FOR_UNION 3
#define FRAGILITY_THRESHOLD 20

class impact
{
    private:
        std::vector<std::vector<kid *>> kidsHit;
        void unite(std::vector<kid *>, int);
        void addKids(kid *, kid *);
        
    public:
        void setHitGroups(std::vector<kid *>);
        void ifUnionPossibleUnite();
        void clearImpacts();
        void handleImpacts(std::vector<kid *>);
        
};

#endif