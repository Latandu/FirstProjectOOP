//
// Created by Latandu on 16/04/2023.
//

#include "Grass.h"
#define grassSymbol 'R'

Grass::Grass() {
    this->setSymbol(grassSymbol);
    this->setAnimalName("Grass");
    this->strength = 0;
    this->initiative = 0;
}
