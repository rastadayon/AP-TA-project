#ifndef __KID_H__
#define __KID_H__
#include <iostream>
#include <vector>
#include <string>
#include "wall.hpp"


#define ANGER_THRESHOLD 70
#define COURAGE_THRESHOLD 30
#define CHARISMA_THRESHOLD 50
#define TWENTY 20
#define FIVE 5
#define TWO 2
#define TWOHUNDRED 200
#define POINT_EIGHT 0.8
#define DEAD_ANOUNCEMENT "kid died with number: "
#define PEACEFUL "Peaceful"
#define ANGRY "Angry"
#define COWARD "Coward"
#define TRUE "true"
#define FALSE "false"


//---------------------->
// angry = anger >= 70 -- charisma = 20 -- courage >= 50
// peaceful = anger <= 30 -- charisma >= 50 -- courage <= 30
// coward = anger >= 0 -- charisma = 0 -- courage = 0
class kid{

    public:
        enum type {Angry, Peaceful, Coward};
        kid(int id, type kidType, bool fragile, float posX, float posY,
        float velocityX, float velocityY, float radius, float anger, float charisma, float courage);
        virtual void react(kid*) = 0;
        virtual void negotiate(kid*);
        virtual type getType();
        float getAnger();
        float getCharisma();
        float getCourage();
        float getRadius();
        float getVelocityX();
        float getVelocityY();
        void die();
        void move(int, int);
        void ifHitWall();
        std::string anounceDead();
        void changeVelocity(float, float); //------------------------->is this supposed to be in protected?

        
    protected:
        bool alive = true;
        float courage;
        float anger;
        float charisma;
        float radius;
        float posX;
        float posY;
        float velocityX;
        float velocityY;
        int id;
        bool fragile;
        type kidType;
        std::vector<wall*> closestwalls;
        void addAnger(float);
        void addCourage(float);
        void addCharisma(float);
};

#endif