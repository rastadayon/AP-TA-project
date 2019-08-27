#include "interface.hpp"
#include <iostream>


int main(int argc, char** argv){
    Interface interface(std::stof(argv[1]), std::stof(argv[2]));
    try{
        interface.readMap();
        interface.readData();
        interface.runMadHouse();
    }
    catch(exception e){
        std::cout << e.what() << std::endl;
    }
}