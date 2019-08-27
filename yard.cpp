#include "yard.hpp"

yard::yard(std::vector<std::string> map): rawMap(map){
    setBricks();
    setWalls();
}

std::vector<wall *> yard::getWalls(){
    return walls;
}

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
            if(rawMap[i][j] == B){
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
}

brick* yard::getBrickByCoords(float posX, float posY){
    for (int i = 0; i < bricks.size(); i++){
        std::tuple<float, float> coord;
        coord = bricks[i]->getCoordinate();
        if(posX == std::get<0>(coord) && posY == std::get<1>(coord)){
            return bricks[i];
        }
    }
    return NULL;
}

void yard::setWalls(){
    for (int i = 0; i < rawMap.size(); i++){
        for (int j = 0; j < rawMap[i].size(); j++){
            if(rawMap[i][j] == B){
                brick* firstBrick = getBrickByCoords(j, i);
                brick* lastBrick;
                if(j != rawMap[i].size()-1 && rawMap[i][j+1] == B){
                    int k = j+1;
                    while(rawMap[i][k] == B){
                        lastBrick = getBrickByCoords(k, i);
                        k++;
                    }
                    if(lastBrick != NULL && firstBrick != NULL){
                        walls.push_back(new wall(firstBrick, lastBrick, wall::Horizontal));
                    }
                        
                }
                else if( i!= rawMap.size()-1 && rawMap[i][j+1] == B){
                    int l = i+1;
                    while(rawMap[l][j] == B){
                        lastBrick = getBrickByCoords(i, l);
                        l++;
                    }
                    if(firstBrick != NULL && lastBrick != NULL)
                        walls.push_back(new wall(firstBrick, lastBrick, wall::Vertical));
                }
                else if(i!= rawMap.size()-1 && j != rawMap[i].size()-1)
                    walls.push_back(new wall(firstBrick, firstBrick, wall::oneBrick));
            }
        }
    }
}

