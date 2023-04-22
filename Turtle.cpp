//
// Created by Latandu on 15/04/2023.
//

#include "Turtle.h"
#define turtleSymbol 'T'
Turtle::Turtle() {
    this->strength = 2;
    this->initiative = 1;
    this->setSymbol(turtleSymbol);
    this->setAnimalName("Turtle");
}

void Turtle::Action() {
    int randNum = std::rand() % 4;
    if (randNum < 3) {
        return;
    }
    Animal::Action();
}
bool Turtle::SpecialAttack(Organism* organism) {
    if(this == organism){
        return false;
    }
    if(organism->getStrength() > 5){
        return true;
    }
    else return false;
}