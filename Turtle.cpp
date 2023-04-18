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
