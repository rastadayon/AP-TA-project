#include "interface.hpp"

Interface::Interface(int timeStep, int totalTime){
    unclesMadHouse = new madHouse(timeStep, totalTime);
}

std::vector<std::string> Interface::correctMap(std::vector<std::string> map){
    std::vector<std::string> correctMap;
    if(map.size() > 0){
        map.erase(map.begin());
        for (int i = map.size()-1; i >= 0; i--){
            correctMap.push_back(map[i]);
        }
    }
}

std::vector<std::string> Interface::readMapFromFile(){
    std::string line;
    std::vector<std::string> map;
    std::ifstream mapFile(MAP_FILE_NAME);
    if(mapFile.is_open()){
        while(getline(mapFile, line)){
            map.push_back(line);
        }
        mapFile.close();
    }
    return map;
}

void Interface::readMap(){
    std::vector<std::string> map;
    int mapSize;
    
    map = readMapFromFile();
    if(map.size() > 0)
        mapSize = stoi(map[0]);
    map = correctMap(map);
    unclesMadHouse->setMap(mapSize, map);
}

void Interface::readData(){
    // while (std::cin)
    // {
    //     /* code */
    // }
    
}