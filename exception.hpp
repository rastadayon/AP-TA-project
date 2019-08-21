#include <iostream>
#include <string>
#define MAP_DOESNT_EXIST "Map doesn't exits."
#define INVALID_INPUT_FORMAT "Input format is invalid."

class exception{
    std::string error;
    public:
        exception(std::string );
        std::string what();
};



