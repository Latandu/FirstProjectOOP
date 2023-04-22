//
// Created by Latandu on 16/04/2023.
//

#include "Guarana.h"
#define guaranaSymbol 'G'
Guarana::Guarana() {
    this->setSymbol(guaranaSymbol);
    this->strength = 0;
    this->initiative = 0;
    this->setAnimalName("Guarana");
}

bool Guarana::SpecialAttack(Organism *organism) {
    organism->setStrength(5);
    Organism* newPositionOrganism = organism;
    world->DeleteOrganism(this,point.getX(), point.getY());
    world->DeleteOrganism(organism, organism->getPoint().getX(), organism->getPoint().getY());
    world->AddOrganism(newPositionOrganism, point.getX(), point.getY());
    return true;
}
