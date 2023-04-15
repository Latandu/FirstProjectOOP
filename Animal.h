//
// Created by Latandu on 13/04/2023.
//

#ifndef FIRSTPROJECT_ANIMAL_H
#define FIRSTPROJECT_ANIMAL_H

#include "Organism.h"
class Animal : public Organism{
protected:
  void Action() override;
   void Collision() override;
private:
    int CheckForFilling(int *isNotFilled);
    void ChangePositionOfOrganism(int randIndex);
public:
    Animal() = default;
};


#endif //FIRSTPROJECT_ANIMAL_H
