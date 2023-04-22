//
// Created by Latandu on 16/04/2023.
//

#include "Belladonna.h"
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
        world->DeleteOrganism(organism, organism->getPoint().getX(), organism->getPoint().getY());
        return true;
    }
}
