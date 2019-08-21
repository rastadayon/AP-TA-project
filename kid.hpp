#ifndef __KID_H__
#define __KID_H__
#include <iostream>
#include <vector>
#include <string>


//---------------------->
// angry = anger >= 70 -- charisma = 20 -- courage >= 50
// peaceful = anger <= 30 -- charisma >= 50 -- courage <= 30
// coward = anger >= 0 -- charisma = 0 -- courage = 0
class kid{
    private:
        /* data */
    public:
        kid(/* args */);
        ~kid();
        enum type {ANGRY, PEACEFUL, COWARD};
        virtual void react(kid*) = 0;
        type getType();
        float getAnger;
        float getCharisma;
        float getCourage;
        
    protected:
        bool alive;
        float courage;
        float anger;
        float charisma;
        float radius;
        float posX;
        float posY;
        float velocityX;
        float velocityY;
        int number;
        bool fradgile; //i donno what this is
        type kidType;
};

kid::kid(/* args */){
}

#endif