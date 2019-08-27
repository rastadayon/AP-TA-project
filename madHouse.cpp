#include "madHouse.hpp"

madHouse::madHouse(float _timeStep, float _totalTime): timeStep(_timeStep), totalTime(_totalTime){
    madHouseYard = new yard(map);
    _impact = new impact;
}

void madHouse::setMap(int _mapSize, std::vector<std::string> _map){
    map = _map;
    mapSize = _mapSize;
}

void madHouse::makeKids(int id, std::string kidType, bool fragile, float posX, float posY,
    float velocityX, float velocityY, float radius, float anger, float charisma, float courage){
        kid *newKid;
    if(kidType == ANGRY && anger >= ANGER_THRESHOLD && charisma == TWENTY && courage >= COURAGE_THRESHOLD)
        newKid = new angryKid(id, kid::type::Angry, fragile, posX, posY, velocityX, velocityY, radius, anger, charisma, courage);
    else if(kidType == PEACEFUL && anger <= THIRTY && charisma )
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

void madHouse::checkForImpact(){
    for (int i = 0; i < kids.size(); i++){
        for (int j = 0; j < kids.size(); j++){
            if(i == j)
                continue;
            if(kids[i]->isKidClose(kids[j]))
                kids[i]->addHitKid(kids[j]);
        }
    }
}

void madHouse::activateImpacts(){
    for (int i = 0; i < kids.size(); i++){
        std::vector<kid *> hitKids = kids[i]->getHitKids();
       for (int j = 0; j < hitKids.size(); j++){
           kids[i]->react(hitKids[i]);

       }
    }
}

void madHouse::breakKid(kid *k){
    float velocitySize = k->getVelocitySize()/6;
    int maxId = kids.size();
    float velocityX, velocityY;
    std::string kidType;
    kidType = k->getTypeString();
    for (int i = 0; i < BREAKING_PIECE_NUMBER; i++){
        maxId++;
        if(i == 0){
            velocityX = velocitySize;
            velocityY = 0;
        }
        if(i == 1){
            velocityX = velocitySize/2;
            velocityY = velocitySize*sqrt(3)/2;
        }
        if(i == 2){
            velocityX = -velocitySize/2;
            velocityY = velocitySize*sqrt(3)/2;
        }
        if(i == 3){
            velocityX = -velocitySize;
            velocityY = 0;
        }
        if(i == 4){
            velocityX = -velocitySize/2;
            velocityY = -velocitySize*sqrt(3)/2;
        }
        if(i == 5){
            velocityX = velocitySize/2;
            velocityY = -velocitySize*sqrt(3)/2;
        }
        makeKids(maxId, kidType, k->isFragile(), k->getPosX(), k->getPosY(), k->getVelocityX()
        ,k->getVelocityY(), k->getRadius()/3, k->getAnger(), k->getCharisma(), k->getCourage());
    }
    
}

void madHouse::handleBreakings(){
    for (int i = 0; i < kids.size(); i++){
        for (int j = i; j < kids.size(); j++){
            if(i != j && kids[i]->isAlive() && kids[j]->isAlive() && kids[i]->isKidClose(kids[j])){
                if(kids[i]->getRadius() + kids[j]->getRadius() >= FRAGILITY_THRESHOLD){
                    if(kids[i]->isFragile()){
                        kids[i]->_break();
                        if(kids[i]->isAlive())
                            breakKid(kids[i]);
                    }
                    if(kids[j]->isFragile()){
                        kids[j]->_break();
                        if(kids[j]->isAlive())
                            breakKid(kids[j]);
                    }
                }
            }
        }
    }
}

void madHouse::runMadHouse(){
    for (int i = 0; i < runTimes; i++){
        for (int j = 0; j < kids.size(); j++){
            if(kids[i]->isAlive())
                kids[j]->move(timeStep, mapSize, madHouseYard->getWalls());
        }
        _impact->setHitGroups(kids);
        _impact->handleImpacts(kids);
        handleBreakings();
    }
    std::cout<<"Game Over" << std::endl;
}