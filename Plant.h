//
// Created by Latandu on 16/04/2023.
//

#ifndef FIRSTPROJECT_PLANT_H
#define FIRSTPROJECT_PLANT_H

#include "Organism.h"
class Plant : public Organism{
protected:
    void Action() override;
    bool SpecialAttack(Organism* organism) override {return false;};
    int Collision(Point& point) override{return 0;};
    int CheckForFilling(int *isNotFilled);
    Point AddNewOrganism(int randIndex, Point point, Organism *organism);
    Organism *CreateNewPlant(char symbol);
public:
    Plant() = default;

};


#endif //FIRSTPROJECT_PLANT_H
