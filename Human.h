//
// Created by Latandu on 13/04/2023.
//

#ifndef FIRSTPROJECT_HUMAN_H
#define FIRSTPROJECT_HUMAN_H


#include "Animal.h"

class Human: public Animal{
protected:
    void Action() override;
public:
    Human();
};


#endif //FIRSTPROJECT_HUMAN_H
