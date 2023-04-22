//
// Created by Latandu on 15/04/2023.
//

#ifndef FIRSTPROJECT_ANTELOPE_H
#define FIRSTPROJECT_ANTELOPE_H

#include "Animal.h"
class Antelope : public Animal {
protected:
    void Action() override;
    bool SpecialAttack(Organism* organism) override;
public:
    Antelope();
};


#endif //FIRSTPROJECT_ANTELOPE_H
