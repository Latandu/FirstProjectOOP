//
// Created by Latandu on 13/04/2023.
//

#ifndef FIRSTPROJECT_ANIMAL_H
#define FIRSTPROJECT_ANIMAL_H

#include "Organism.h"
class Animal : public Organism{
protected:
    void Action() override;
    int Collision(Point& point) override;

    int CheckForFilling(int *isNotFilled, Point point);

    Point ChangePositionOfOrganism(int randIndex, Point point);
public:
    Animal() = default;
    int PositionAndCollision(int randIndex, Point &point, Point point1, int x, int y);

    int CheckForFillingWithAnimals(int *isNotFilled);

    int CheckForFillingWithAnimals(int *isNotFilled, Point point);

    int PositionAndCollision(Point &point, int x, int y);

    int PositionAndCollision(int x, int y);

    Point AddNewOrganism(int randIndex, Point point, Organism *organism);

    Point ChangePositionOfOrganism(Organism *organism, int randIndex, Point pointAlfa);
};


#endif //FIRSTPROJECT_ANIMAL_H
