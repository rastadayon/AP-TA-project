#ifndef __KID_H__
#define __KID_H__
#include <iostream>
#include <vector>
#include <string>


#define ANGER_THRESHOLD 70
#define COURAGE_THRESHOLD 30
#define CHARISMA_THRESHOLD 50
#define TWENTY 20
#define FIVE 5
#define TWO 2
#define TWOHUNDRED 200
#define POINT_EIGHT 0.8
#define DEAD_ANOUNCEMENT "kid died with number: "

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
        virtual void negotiate(kid*);
        virtual type getType();
        float getAnger();
        float getCharisma();
        float getCourage();
        float getRadius();
        float getVelocityX();
        float getVelocityY();
        void die();
        std::string anounceDead();
        void changeVelocity(float, float); //------------------------->is this supposed to be in protected?

        
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
        int id;
        bool fradgile; //i donno what this is
        type kidType;
        void addAnger(float);
        void addCourage(float);
        void addCharisma(float);
};

kid::kid(/* args */){
}

#endif