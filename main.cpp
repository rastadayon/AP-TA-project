#include "interface.hpp"
#include <iostream>


int main(int argc, char** argv){
    Interface interface(std::stof(argv[1]), std::stof(argv[2]));
    interface.readMap();
    try{
        interface.readData();
    }
    catch(exception e){
        std::cout << e.what() << std::endl;
    }
}