#include "impact.hpp"

void impact::addKids(kid *kid1, kid *kid2){
    for (int i = 0; i < kidsHit.size(); i++){
        for (int j = 0; j < kidsHit[i].size(); j++){
            if(kidsHit[i][j] == kid1){
                kidsHit[i].push_back(kid2);
                return;
            }
        }
    }
    std::vector<kid *> newGroup;
    newGroup.push_back(kid1);
    newGroup.push_back(kid2);
    kidsHit.push_back(newGroup);
}

void impact::clearImpacts(){
    std::vector<std::vector<kid *>> newHitKids;
    kidsHit = newHitKids;
}

void impact::setHitGroups(std::vector<kid *> kids){
    clearImpacts();
    for (int i = 0; i < kids.size(); i++){
        for (int j = 0; j < kids.size(); j++){
            if(i != j && kids[i]->isAlive()){
                addKids(kids[i],kids[j]);
            }
        }
    }
}

void impact::unite(std::vector<kid *> hitKidsGroup, int peacefulKidCount){
    for (int i = 0; i < hitKidsGroup.size(); i++){
        if(hitKidsGroup[i]->getType() == kid::Peaceful){
            hitKidsGroup[i]->addCourage(FIVE * peacefulKidCount);
        }
    }
}

void impact::ifUnionPossibleUnite(){
    for (int i = 0; i < kidsHit.size(); i++){
        if(kidsHit[i].size() >= MIN_KIDS_NEEDED_FOR_UNION){
            int j = 0, peacefulKidCount = 0;
            for (j = 0; j < kidsHit[i].size(); j++){
                if(kidsHit[i][j]->getType() == kid::Peaceful)
                    peacefulKidCount++;
                if(peacefulKidCount >= MIN_KIDS_NEEDED_FOR_UNION && j == kidsHit[i].size()-1)
                    unite(kidsHit[i], peacefulKidCount);
            }

        }
    }
    
}

void impact::handleImpacts(std::vector<kid *> kids){
    for (int i = 0; i < kids.size(); i++){
        for (int j = 0; j < kids.size(); j++){
            if(i != j && kids[i]->isAlive() && kids[i]->isAlive()){
                if(kids[i]->isKidClose(kids[j])){
                    kids[i]->react(kids[j]);
                    kids[i]->ifDied();
                }
            } 
        }
    }
    for (int i = 0; i < kids.size(); i++){
        for (int j = i; j < kids.size(); j++){
            if(i != j && kids[i]->isKidClose(kids[j]))
                kids[i]->hit(kids[j]);
        }   
    }
    
}
