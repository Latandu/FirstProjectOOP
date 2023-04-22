//
// Created by Latandu on 16/04/2023.
//

#ifndef FIRSTPROJECT_SOSNOWSKY_H
#define FIRSTPROJECT_SOSNOWSKY_H

#include "Plant.h"
class Sosnowsky : public Plant {
    void Action() override;
    bool SpecialAttack(Organism* organism) override;

public:
    Sosnowsky();
};


#endif //FIRSTPROJECT_SOSNOWSKY_H
