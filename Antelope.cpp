//
// Created by Latandu on 15/04/2023.
//

#include "Antelope.h"
#define antelopeSymbol '^'
Antelope::Antelope() {
    this->strength = 4;
    this->initiative = 4;
    this->setSymbol(antelopeSymbol);
    this->setAnimalName("Antelope");
}
