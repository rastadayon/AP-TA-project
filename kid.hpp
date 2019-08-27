#ifndef __KID_H__
#define __KID_H__
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <tuple>
#include "yard.hpp"


#define ANGER_THRESHOLD 70
#define COURAGE_THRESHOLD 30
#define CHARISMA_THRESHOLD 50
#define TWENTY 20
#define FIVE 5
#define TWO 2
#define TWOHUNDRED 200
#define POINT_EIGHT 0.8
#define VIRTUAL_TIMESTEP 0.02
#define DEAD_ANOUNCEMENT "kid died with number: "
#define PEACEFUL "Peaceful"
#define ANGRY "Angry"
#define COWARD "Coward"
#define TRUE "true"
#define FALSE "false"
#define CLOSENESS_THRESHOLD 1


//---------------------->
// angry = anger >= 70 -- charisma = 20 -- courage >= 50
// peaceful = anger <= 30 -- charisma >= 50 -- courage <= 30
// coward = anger >= 0 -- charisma = 0 -- courage = 0
class kid{

    public:
        enum type {Angry, Peaceful, Coward};
        kid(int id, type kidType, bool fragile, float posX, float posY,
        float velocityX, float velocityY, float radius, float anger, float charisma, float courage);
        virtual void react(kid *) = 0;
        virtual void negotiate(kid *);
        virtual type getType();
        float getAnger();
        float getCharisma();
        float getCourage();
        float getRadius();
        float getVelocityX();
        float getVelocityY();
        float getPosX();
        float getPosY();
        std::vector<kid *> getHitKids();
        void die();
        void move(float, int, std::vector<wall *>);
        void ifHitWall();
        std::string anounceDead();
        void changeVelocity(float, float); //------------------------->is this supposed to be in protected?
        float getVelocitySize();
        void changePos(float newPosX, float newPosY);
        void addHitKid(kid *);
        bool isKidClose(kid *);

    protected:
        bool alive = true;
        float courage;
        float anger;
        float charisma;
        float radius;
        float posX;
        float posY;
        float finalEstimatedX;
        float finalEstimatedY;
        float velocityX;
        float velocityY;
        int id;
        bool fragile;
        type kidType;
        std::vector<wall *> closestwalls;
        std::vector<kid *> hitKids;
        void addAnger(float);
        void addCourage(float);
        void addCharisma(float);
        bool ifHitWall(float initialPosX, float initialPosY, float estimatedPosX, float estimatedPosY);
        bool isWallClose(wall *);
        bool isMovingRight();
        bool isMovingLeft();
        bool isMovingUp();
        bool isMovingDown();
        wall* hittingWall();
        bool isGonnaHitWall(wall *, float);
        bool isGonnaHitHorizontal(wall *, float);
        bool isGonnaHitVertical(wall *, float);
        std::tuple<float, float> getTangentPoint(wall *);
        void reflect45Degree(std::tuple<float,float>, wall *);
        void reflect90Degree(std::tuple<float,float>);
        
};

#endif