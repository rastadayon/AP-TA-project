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

#define DATA_SIZE 11

class madHouse{
    std::vector<std::string> map;
    yard* madHouseYard; 
    int mapSize;
    float timeStep;
    float totalTime;
    float virtualTimeStep = 1/timeStep * 100;
    int runTimes = totalTime/timeStep;
    std::vector<kid *> kids;


    public:
        madHouse(float, float);
        void setMap(int, std::vector<std::string>);
        void useData(std::vector<std::string>);
        void runMadHouse();

    private:
        void makeKids(int id, std::string kidType, bool fragile, float posX, float posY,
        float velocityX, float velocityY, float radius, float anger, float charisma, float courage);
};

#endif