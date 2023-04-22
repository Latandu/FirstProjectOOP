//
// Created by Latandu on 15/04/2023.
//

#ifndef FIRSTPROJECT_TURTLE_H
#define FIRSTPROJECT_TURTLE_H

#include "Animal.h"
class Turtle : public Animal {
protected:
    void Action() override;
    bool SpecialAttack(Organism *organism) override;
public:
    Turtle();


};


#endif //FIRSTPROJECT_TURTLE_H
