#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#define MAP_FILE_NAME "map.dat"
#include "madHouse.hpp"
#include "exception.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Interface{
    madHouse* unclesMadHouse;

    public:
        Interface(int, int);
        ~Interface();
        void readMap();
        std::vector<std::string> readMapFromFile();
        std::vector<std::string> correctMap(std::vector<std::string>);
        void readData();
        void dataLineParser(std::string);
};

#endif