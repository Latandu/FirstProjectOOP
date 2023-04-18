//
// Created by Latandu on 16/04/2023.
//

#ifndef FIRSTPROJECT_PLANT_H
#define FIRSTPROJECT_PLANT_H

#include "Organism.h"
class Plant : public Organism{
protected:
    void Action() override;
    int Collision(Point& point) override{return 0;};
private:
    int CheckForFilling(int *isNotFilled);
    void AddNewOrganism(int randIndex);
public:
    Plant() = default;

    int CheckForFilling(int *isNotFilled, Point point);

    Point AddNewOrganism(int randIndex, Point point, Organism *organism);
};


#endif //FIRSTPROJECT_PLANT_H
