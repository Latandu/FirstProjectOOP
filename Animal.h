//
// Created by Latandu on 13/04/2023.
//

#ifndef FIRSTPROJECT_ANIMAL_H
#define FIRSTPROJECT_ANIMAL_H

#include "Organism.h"
class Animal : public Organism{
protected:
    void Action() override;
    bool SpecialAttack(Organism* organism) override{return false;};
    int Collision(Point& point) override;
    int CheckForFilling(int *isNotFilled, int change);


    int CheckForFillingWithAnimals(int *isNotFilled, Point point);

    int PositionAndCollision(int x, int y);

    Point AddNewOrganism(int randIndex, Point point, Organism *organism);
public:
    Animal() = default;


    Organism *CreateNewOrganism(char symbol);

    Organism *CreateNewAnimal(char symbol);
};


#endif //FIRSTPROJECT_ANIMAL_H
