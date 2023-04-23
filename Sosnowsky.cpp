//
// Created by Latandu on 16/04/2023.
//

#include "Sosnowsky.h"
#include "Logs.h"

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
        if(organism->getSymbol() == '@'){
            world->AliveHuman = false;
        }
        Logs::AddComment("Killed organism "+ organism->getAnimalName()+ " by Sosnowsky at point " + std::to_string(organism->getPoint().getX()) +" "
                         +std::to_string(organism->getPoint().getX()));
        world->DeleteOrganism(organism, organism->getPoint().getX(), organism->getPoint().getY());
        delete organism;
        return true;
    }
}
void Sosnowsky::Action() {
    Organism* organism1 = world->GetOrganism(point.getX()-1, point.getX());
    Organism* organism2 = world->GetOrganism(point.getX()+1, point.getX());
    Organism* organism3 = world->GetOrganism(point.getX(), point.getX()+1);
    Organism* organism4 = world->GetOrganism(point.getX(), point.getX()-1);
    if(organism1 != nullptr && organism1->getInitiative() != 0){
        if(organism1->getSymbol() == '@') {
            world->AliveHuman = false;}
        Logs::AddComment("Killed Organism" + organism1->getAnimalName() + " by Sosnowsky at point" + std::to_string(point.getX()) +", " + std::to_string(point.getY()));
        world->DeleteOrganism(organism1,point.getX()-1, point.getX());
        delete organism1;

    }

    if(organism2 != nullptr &&  organism2->getInitiative() != 0){
        if(organism2->getSymbol() == '@')
            world->AliveHuman = false;
        Logs::AddComment("Killed Organism " + organism2->getAnimalName() + " by Sosnowsky at point" + std::to_string(point.getX()) +", " + std::to_string(point.getY()) );
        world->DeleteOrganism(organism2,point.getX()+1, point.getX());
        delete organism2;
    }


    if(organism3 != nullptr &&  organism3->getInitiative() != 0){
        if(organism3->getSymbol() == '@')
            world->AliveHuman = false;
        Logs::AddComment("Killed Organism " + organism3->getAnimalName() + " by Sosnowsky at point " + std::to_string(point.getX()) + ", " + std::to_string(point.getY()) );
        world->DeleteOrganism(organism3,point.getX(), point.getX()+1);
        delete organism3;

    }

    if(organism4 != nullptr && organism4->getInitiative() != 0){
        if(organism4->getSymbol() == '@')
            world->AliveHuman = false;
        Logs::AddComment("Killed Organism " + organism4->getAnimalName() + " by Sosnowsky at point " + std::to_string(point.getX()) +", " + std::to_string(point.getY()) );
        world->DeleteOrganism(organism4,point.getX(), point.getX()-1);
        delete organism4;
    }



}