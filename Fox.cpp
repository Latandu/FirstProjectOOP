//
// Created by Latandu on 15/04/2023.
//

#include "Fox.h"
#define foxSymbol '$'
Fox::Fox() {
    this->strength = 3;
    this->initiative = 7;
    this->setSymbol(foxSymbol);
    this->setAnimalName("Fox");
}
