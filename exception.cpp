#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include "exception.hpp"
exception::exception(std::string _error): error(_error) {}

std::string exception::what(){
    return error;
}

#endif