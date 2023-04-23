//
// Created by Latandu on 16/04/2023.
//

#include "SowThistle.h"
#define sowthistleSymbol 'O'
SowThistle::SowThistle(){
    this->strength = 0;
    this->initiative = 0;
    this->setSymbol(sowthistleSymbol);
    this->setAnimalName("Sow Thistle");
}

void SowThistle::Action() {
    int randNum = std::rand() % 10;
    if (randNum == 0) {
        for(int i = 0; i < 3; i++) {

            Plant::Action();
        }
    } else Plant::Action();

}
