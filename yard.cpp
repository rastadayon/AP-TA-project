#include "yard.hpp"

yard::yard(std::vector<std::string> map): rawMap(map){}

bool checkTop(std::vector<std::string> map, int i, int j){
    if(i == map.size()-1)
        return false;
    else if(map[i+1][j] == B)
        return true;
    return false;
}

bool checkBottom(std::vector<std::string> map, int i, int j){
    if(i == 0)
        return false;
    else if(map[i-1][j] == B)
        return true;
    return false;
}

bool checkRight(std::vector<std::string> map, int i, int j){
    if(j == map[i].size()-1)
        return false;
    else if(map[i][j+1] == B)
        return true;
    return false;
}

bool checkLeft(std::vector<std::string> map, int i, int j){
    if(j == 0)
        return false;
    else if(map[i][j-1] == B)
        return true;
    return false;
}

bool checkTopRight(std::vector<std::string> map, int i, int j){
    if(i == map.size()-1 || j == map[i].size()-1)
        return false;
    else if(map[i+1][j+1] == B)
        return true;
    return false;
}

bool checkTopLeft(std::vector<std::string> map, int i, int j){
    if(i == map.size()-1 || j == 0)
        return false;
    else if(map[i+1][j-1] == B)
        return true;
    return false;
}

bool checkBottomRight(std::vector<std::string> map, int i, int j){
    if(i == 0 || j == map[i].size()-1)
        return false;
    else if(map[i-1][j+1] == B)
        return true;
    return false;
}

bool checkBottomLeft(std::vector<std::string> map, int i, int j){
    if(i == 0 || j == 0)
        return false;
    else if(map[i-1][j-1] == B)
        return true;
    return false;
}

void yard::setBricks(){
    for (int i = 0; i < rawMap.size(); i++){
        for (int j = 0; j < rawMap[i].size(); j++){
            bool rightSideBrick, leftSideBrick, topSideBrick, bottomSideBrick, 
            topRightBrick, topLeftBrick, bottomRightBrick, bottomLeftBrick;;
            
            rightSideBrick = checkRight(rawMap, i,j);
            leftSideBrick = checkLeft(rawMap, i, j);
            topSideBrick = checkLeft(rawMap, i, j);
            bottomSideBrick = checkBottom(rawMap, i, j);
            topRightBrick = checkTopRight(rawMap, i, j);
            topLeftBrick = checkTopLeft(rawMap, i, j);
            bottomRightBrick = checkBottomRight(rawMap, i, j);
            bottomLeftBrick = checkBottomLeft(rawMap, i, j);

            brick* newBrick = new brick(rightSideBrick, leftSideBrick, topSideBrick, bottomSideBrick,
                    topRightBrick, topLeftBrick, bottomRightBrick, bottomLeftBrick, j, i);
            bricks.push_back(newBrick);
        }  
    }
}

void yard::specifyCorners(){
    for (int i = 0; i < bricks.size(); i++){
        
    }
    
}