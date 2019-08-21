#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#define FILE_NAME "map.dat"
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
        void readData();
};

#endif