#include "madHouse.hpp"

madHouse::madHouse(int _timeStep, int _totalTime): timeStep(_timeStep), totalTime(_totalTime){}

void madHouse::setMap(int _mapSize, std::vector<std::string> _map){
    map = _map;
    mapSize = _mapSize;
}