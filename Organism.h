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

protected:
    int strength = 0;
    int initiative = 0;
    int age = 0;
    bool roundDone = false;
    char symbol = '*';
    int coolDown = 0;
    Point point;
    std::string animalName;
    virtual int Collision(Point& point) = 0;
    virtual char Draw();

public:
    World* world{};
    int getCoolDown() const;
    void setCoolDown(int coolDown);
    Organism(int strength, int initiative, Point point, bool roundDone, int age);
    const std::string &getAnimalName() const;
    World *getWorld() const;
    void setWorld(World *world);
    int getStrength() const;
    void setAge(int age);
    Organism() = default;
    virtual char getSymbol() const;
    virtual ~Organism() = default;
    virtual void Action() = 0;
    void setRoundDone(bool roundDone);
    int getAge() const;
    int getInitiative() const;
    bool isRoundDone() const;
    void setPoint(int x, int y);
    virtual bool SpecialAttack(Organism* organism) = 0;
    void setStrength(int strength);
    const Point &getPoint() const;

    void setInitiative(int initiative);

    void setSymbol(char symbol);

    void setAnimalName(const std::string &animalName);
};


#endif //FIRSTPROJECT_ORGANISM_H
