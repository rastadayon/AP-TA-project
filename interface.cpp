#include "interface.hpp"

Interface::Interface(int timeStep, int totalTime){
    unclesMadHouse = new madHouse(timeStep, totalTime);
}

void Interface::readMap(){
    std::string line;
    std::vector<std::string> map;
    std::ifstream mapFile(FILE_NAME);
    int mapSize;
    if(mapFile.is_open()){
        while(getline(mapFile, line)){
            map.push_back(line);
        }
        mapFile.close();
    }
    if(map.size() > 0){
        mapSize = stoi(map[0]);
        map.erase(map.begin());
    }
    unclesMadHouse->setMap(mapSize, map);
}