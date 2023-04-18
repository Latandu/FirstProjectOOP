//
// Created by Latandu on 15/04/2023.
//

#include "Fox.h"
#define foxSymbol 'F'
Fox::Fox() {
    this->strength = 3;
    this->initiative = 7;
    this->setSymbol(foxSymbol);
    this->setAnimalName("Fox");
}

void Fox::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled, point) != 0) {
        return;
    }
    int randNum = std::rand() % 4;
    if (randNum < 3) {
        return;
    }
    int i = 0;
    while(true){
        int randIndex = (int)std::rand() % 4;
        if(isNotFilled[randIndex]){
            if()
            ChangePositionOfOrganism( randIndex, point);
            break;
        }
        i++;
    }
}