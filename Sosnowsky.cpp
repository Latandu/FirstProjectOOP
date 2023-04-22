//
// Created by Latandu on 16/04/2023.
//

#include "Sosnowsky.h"
#define sosnowskySymbol 'S'
Sosnowsky::Sosnowsky() {
    this->strength = 10;
    this->initiative = 0;
    this->setAnimalName("Sosnowsky");
    this->setSymbol(sosnowskySymbol);
}

bool Sosnowsky::SpecialAttack(Organism *organism) {
    if(organism == this){
        return false;
    }
    else{
        world->DeleteOrganism(organism, organism->getPoint().getX(), organism->getPoint().getY());
        return true;
    }
}
void Sosnowsky::Action() {
    Organism* organism1 = world->GetOrganism(point.getX()-1, point.getX());
    Organism* organism2 = world->GetOrganism(point.getX()+1, point.getX());
    Organism* organism3 = world->GetOrganism(point.getX(), point.getX()+1);
    Organism* organism4 = world->GetOrganism(point.getX(), point.getX()-1);
    if(organism1 != nullptr && initiative != 0)
        world->DeleteOrganism(organism1,point.getX()-1, point.getX());
    if(organism2 != nullptr && initiative != 0)
        world->DeleteOrganism(organism2,point.getX()+1, point.getX());
    if(organism3 != nullptr && initiative != 0)
        world->DeleteOrganism(organism3,point.getX(), point.getX()+1);
    if(organism4 != nullptr && initiative != 0)
        world->DeleteOrganism(organism4,point.getX(), point.getX()-1);


}