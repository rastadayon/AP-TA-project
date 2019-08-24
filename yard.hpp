#ifndef __YARD_H__
#define __YARD_H__

#include <iostream>
#include "brick.hpp"
#include <vector>
#include <string>
#include <tuple>
#define B 'b'

class yard{
    public:
        yard(std::vector<std::string>);
        ~yard();
        void addCornerCords(float, float);
        void setBricks();
    private:
        std::vector<std::string> rawMap;
        std::vector<brick*> bricks;
        std::vector<std::tuple<float,float> > cornerCoordinates;
        void specifyCorners();
    
};


#endif