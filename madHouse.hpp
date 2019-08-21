#ifndef __MAD_HOUSE_H__
#define __MAD_HOUSE_H__
#include <iostream>
#include <vector>
#include <string>

class madHouse{
    std::vector<std::string> map;
    int mapSize;
    int timeStep;
    int totalTime;

    public:
        madHouse(int, int);
        void setMap(int, std::vector<std::string>);
        ~madHouse();
};

#endif