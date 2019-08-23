#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#define MAP_FILE_NAME "map.dat"
#define COMMA ','
#include "madHouse.hpp"
#include "exception.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 

class Interface{
    madHouse* unclesMadHouse;

    public:
        Interface(float, float);
        void readMap();
        std::vector<std::string> correctMap(std::vector<std::string>);
        void readData();
        void dataLineParser(std::string);
        void runMadHouse();
    private:
        void cleanData(std::vector<std::string> &);
        std::vector<std::string> readMapFromFile();
};

#endif