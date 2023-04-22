//
// Created by Latandu on 15/04/2023.
//

#include "Fox.h"
#define foxSymbol 'F'
Fox::Fox() {
    this->strength = 3;
    this->initiative = 7;
    this->setSymbol(foxSymbol);
    this->setAnimalName("Fox");
}

void Fox::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled, 1) != 0) {
        return;
    }
    while(true){
        int randIndex = (int)std::rand() % 4;
        if(isNotFilled[randIndex]){
            if(randIndex == 0){
                if(world->GetStrength(point.getX()-1,point.getY()) > getStrength()) return;
                if(PositionAndCollision(  -1, 0) == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            } if(randIndex == 1){
                if(world->GetStrength(point.getX()-1,point.getY()) > getStrength()) return;
                if(PositionAndCollision( 1, 0) == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            } if(randIndex == 2){
                if(world->GetStrength(point.getX()-1,point.getY()) > getStrength()) return;
                if(PositionAndCollision(   0, -1) == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            } if(randIndex == 3){
                if(world->GetStrength(point.getX()-1,point.getY()) > getStrength()) return;
                if(PositionAndCollision(  0, 1) == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            }
        }
    }
}
