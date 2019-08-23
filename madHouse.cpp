#include "madHouse.hpp"

madHouse::madHouse(float _timeStep, float _totalTime): timeStep(_timeStep), totalTime(_totalTime){}

void madHouse::setMap(int _mapSize, std::vector<std::string> _map){
    map = _map;
    mapSize = _mapSize;
}

void madHouse::makeKids(int id, std::string kidType, bool fragile, float posX, float posY,
    float velocityX, float velocityY, float radius, float anger, float charisma, float courage){
        kid *newKid;
    if(kidType == ANGRY)
        newKid = new angryKid(id, kid::type::Angry, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage);
    else if(kidType == PEACEFUL)
        newKid = new peacefulKid(id, kid::type::Peaceful, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage);
    else if(kidType == COWARD)
        newKid = new cowardKid(id, kid::type::Coward, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage);
    kids.push_back(newKid);
}


void madHouse::useData(std::vector<std::string> data){
    if(data.size() != DATA_SIZE )
        throw exception(INVALID_INPUT_FORMAT);
    else{
        int id = stoi(data[0]);
        std::string kidType = data[1];
        bool fragile = data[2] == TRUE ? true : false;
        float posX = std::stof(data[3]);
        float posY = std::stof(data[4]);
        float velocityX = std::stof(data[5]);
        float velocityY = std::stof(data[6]);
        float radius = std::stof(data[7]);
        float anger = std::stof(data[8]);
        float charisma = std::stof(data[9]);
        float courage = std::stof(data[10]);
        makeKids(id, kidType, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage);
    }
}