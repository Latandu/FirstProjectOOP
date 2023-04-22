//
// Created by Latandu on 15/04/2023.
//

#include "Antelope.h"
#define antelopeSymbol 'A'
Antelope::Antelope() {
    this->strength = 4;
    this->initiative = 4;
    this->setSymbol(antelopeSymbol);
    this->setAnimalName("Antelope");
}

void Antelope::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled, 2) != 0) {
        return;
    }
    int positionReturnCode = 0;
    while(true){
        int randIndex = (int)std::rand() % 4;
        if(isNotFilled[randIndex]){
            if(randIndex == 0){
                positionReturnCode = PositionAndCollision(  -2, 0);
                if(positionReturnCode == 0 || positionReturnCode == 4) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            } if(randIndex == 1){
                positionReturnCode = PositionAndCollision(  2, 0);
                if(positionReturnCode == 0 || positionReturnCode == 4) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            } if(randIndex == 2){
                positionReturnCode = PositionAndCollision(  0, -2);
                if(positionReturnCode == 0 || positionReturnCode == 4) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            } if(randIndex == 3){
                positionReturnCode = PositionAndCollision(  0, 2);
                if(positionReturnCode == 0 || positionReturnCode == 4) break;
                world->AddOrganism(this, point.getX(),point.getY());
                break;
            }
        }
    }
}
bool Antelope::SpecialAttack(Organism *organism) {

    int randomFightReturn = (int)std::rand() % 2;
    if(randomFightReturn){
        int isNotFilled[4] = {0, 0, 0, 0};
        if(CheckForFilling(isNotFilled, 2) != 0) {
            return true;
        }
        Organism* newOrganismPosition = world->GetOrganism(point.getX(), point.getY());
        while(true){
            int randIndex = (int)std::rand() % 4;
            if(isNotFilled[randIndex]){
                if(randIndex == 0){
                    world->DeleteOrganism(this, point.getX(), point.getY());
                    world->AddOrganism(newOrganismPosition, point.getX()-1,point.getY());
                    return true;
                } if(randIndex == 1){
                    world->DeleteOrganism(this, point.getX(), point.getY());
                    world->AddOrganism(newOrganismPosition, point.getX()+1,point.getY());
                    return true;
                } if(randIndex == 2){
                    world->DeleteOrganism(this, point.getX(), point.getY());
                    world->AddOrganism(newOrganismPosition, point.getX(),point.getY()-1);
                    return true;
                } if(randIndex == 3){
                    world->DeleteOrganism(this, point.getX(), point.getY());
                    world->AddOrganism(newOrganismPosition, point.getX(),point.getY()+1);
                    return true;
                }
            }
        }
    }return false;
}
