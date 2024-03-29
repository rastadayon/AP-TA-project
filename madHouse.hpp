#ifndef __MAD_HOUSE_H__
#define __MAD_HOUSE_H__
#include <iostream>
#include <vector>
#include <string>
#include "exception.hpp"
#include "kid.hpp"
#include "angryKid.hpp"
#include "peacefulKid.hpp"
#include "cowardKid.hpp"
#include "yard.hpp"
#include "impact.hpp"

#define DATA_SIZE 11
#define HUNDRED 100
#define THIRTY 30
#define BREAKING_PIECE_NUMBER 6


class madHouse{
    std::vector<std::string> map;
    yard* madHouseYard; 
    
    int mapSize;
    float timeStep;
    float totalTime;
    float virtualTimeStep = timeStep * HUNDRED;
    int runTimes = totalTime/timeStep;
    std::vector<kid *> kids;
    impact* _impact;


    public:
        madHouse(float, float);
        void setMap(int, std::vector<std::string>);
        void useData(std::vector<std::string>);
        void runMadHouse();
        void anounce(int);

    private:
        void makeKids(int id, std::string kidType, bool fragile, float posX, float posY,
        float velocityX, float velocityY, float radius, float anger, float charisma, float courage);
        void checkForImpact();
        void activateImpacts();
        bool ifKidsCanUnite(std::vector<kid *>);
        void handleBreakings();
        void breakKid(kid *);
};

#endif