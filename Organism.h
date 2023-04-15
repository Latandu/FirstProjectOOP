//
// Created by Latandu on 13/04/2023.
//

#ifndef FIRSTPROJECT_ORGANISM_H
#define FIRSTPROJECT_ORGANISM_H
#include "World.h"
#include "Point.h"
#include <iostream>
class World;
class Organism {
  //  friend class Animal;
protected:
    Organism(int strength, int initiative, Point point, World *world);
    int strength = 0;
    int initiative = 0;
    char symbol = '*';
    Point point;
    std::string animalName;
public:
    const std::string &getAnimalName() const;

    void setAnimalName(const std::string &animalName);

protected:
    World* world;
public:
    Organism() = default;
    virtual ~Organism() = default;
    virtual void Action() = 0;
    virtual void Collision() = 0;
    virtual char Draw();
    virtual char getSymbol() const;
    int getStrength() const;

    int getInitiative() const;

    const Point &getPoint() const;

    void setStrength(int strength);

    void setInitiative(int initiative);

    void setSymbol(char symbol);

    void setPoint(int x, int y);
};


#endif //FIRSTPROJECT_ORGANISM_H
