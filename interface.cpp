#include "interface.hpp"

Interface::Interface(float timeStep, float totalTime){
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
    return correctMap;
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
    else
        throw MAP_DOESNT_EXIST;

    map = correctMap(map);
    unclesMadHouse->setMap(mapSize, map);
}

void Interface::dataLineParser(std::string data){
    
}

void Interface::cleanData(std::vector<std::string> &uncleanedData){
    for (int i = 0; i < uncleanedData.size(); i++){
        if(uncleanedData[i][uncleanedData[i].size()-1] == COMMA){
           uncleanedData[i].pop_back();
        }
    }
}

void Interface::readData(){
    std::string lineOfData;
    std::string token;
    while (std::getline (std::cin,lineOfData)){
        std::vector<std::string> tokenizedData;
        std::stringstream chek1(lineOfData);
        while (std::getline (chek1, token, ' ')){
            tokenizedData.push_back(token);
        }  
        cleanData(tokenizedData);
    }
    
}

void Interface::runMadHouse(){
    unclesMadHouse->runMadHouse();
}