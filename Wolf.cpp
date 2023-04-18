//
// Created by Latandu on 14/04/2023.
//
#define WolfChar 'W'
#include "Wolf.h"
 Wolf::Wolf() {
    this->strength = 9;
    this->initiative = 5;
    this->setSymbol(WolfChar);
    this->setAnimalName("Wolf");
}