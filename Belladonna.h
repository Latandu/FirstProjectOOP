//
// Created by Latandu on 16/04/2023.
//

#ifndef FIRSTPROJECT_BELLADONNA_H
#define FIRSTPROJECT_BELLADONNA_H

#include "Plant.h"
class Belladonna : public Plant{
protected:
    bool SpecialAttack(Organism* organism) override;
public:
    Belladonna();
};


#endif //FIRSTPROJECT_BELLADONNA_H
