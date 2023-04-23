//
// Created by Latandu on 16/04/2023.
//

#include "Guarana.h"
#include "Logs.h"

#define guaranaSymbol 'G'
Guarana::Guarana() {
    this->setSymbol(guaranaSymbol);
    this->strength = 0;
    this->initiative = 0;
    this->setAnimalName("Guarana");
}

bool Guarana::SpecialAttack(Organism *organism) {
    organism->setStrength(organism->getStrength() + 3);
    Logs::AddComment("Added 3 strength to:" + organism->getAnimalName());
    Organism* newPositionOrganism = organism;
    world->DeleteOrganism(this,point.getX(), point.getY());
    world->DeleteOrganism(organism, organism->getPoint().getX(), organism->getPoint().getY());
    world->AddOrganism(newPositionOrganism, point.getX(), point.getY());
    return true;
}
