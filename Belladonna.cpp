//
// Created by Latandu on 16/04/2023.
//

#include "Belladonna.h"
#include "Logs.h"

#define belladonnaSymbol 'B'
Belladonna::Belladonna() {
    this->strength = 99;
    this->initiative = 0;
    this->setAnimalName("Belladonna");
    this->setSymbol(belladonnaSymbol);
}

bool Belladonna::SpecialAttack(Organism *organism) {
    if(organism == this){
        return false;
    }
    else{
        if(organism->getSymbol() == '@')
            world->AliveHuman = false;
        Logs::AddComment("Deleted organism "+ organism->getAnimalName()+ " by Belladonna at point " + std::to_string(organism->getPoint().getX()) +", "
        +std::to_string(organism->getPoint().getY()));
        world->DeleteOrganism(organism, organism->getPoint().getX(), organism->getPoint().getY());
        delete organism;
        return true;
    }
}
