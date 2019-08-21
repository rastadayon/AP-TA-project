//#include "interface.hpp"
#include <iostream>

int main(int argc, char** argv){
    for (int i = 0; i < argc; i++){
        std::cout << typeid(argv[i]).name() << " ";
    }
    
}