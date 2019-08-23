
#include "exception.hpp"

exception::exception(std::string error): error(error){}

std::string exception::what(){
    return error;
}
