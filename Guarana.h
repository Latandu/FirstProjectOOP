//
// Created by Latandu on 16/04/2023.
//

#ifndef FIRSTPROJECT_GUARANA_H
#define FIRSTPROJECT_GUARANA_H

#include "Plant.h"
class Guarana : public Plant {
    bool SpecialAttack(Organism* organism) override;
public:
    Guarana();
};


#endif //FIRSTPROJECT_GUARANA_H
