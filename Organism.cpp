//
// Created by Latandu on 13/04/2023.
//

#include "Organism.h"
Organism::Organism(int strength, int initiative, Point point, World* world){
    this->strength = strength;
    this->initiative = initiative;
    this->point = point;
    this->world = world;
}

char Organism::Draw() {
    return symbol;
}
void Organism::setStrength(int strength) {
    this->strength = strength;
}

void Organism::setInitiative(int initiative) {
    this->initiative = initiative;
}

void Organism::setSymbol(char symbol) {
    this->symbol = symbol;
}
char Organism::getSymbol() const{
    return symbol;
}
void Organism::setPoint(int x, int y) {
    this->point.setX(x);
    this->point.setY(y);
}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

const Point &Organism::getPoint() const {
    return point;
}

const string &Organism::getAnimalName() const {
    return animalName;
}

void Organism::setAnimalName(const string &animalName) {
    Organism::animalName = animalName;
}
