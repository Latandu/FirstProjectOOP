//
// Created by Latandu on 13/04/2023.
//

#include "Animal.h"
#include "Wolf.h"
#include "Antelope.h"
#include "Turtle.h"
#include "Sheep.h"
#include "Fox.h"
#include "Logs.h"
#define nullSpace '*'
#define error 4
#define killedAnimal 0
#define killedAnimalAttacker 1
#define reproduction 2
#define NoCollision 3
void Animal::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled, 1) != 0) {
        return;
    }
    int positionReturnCode = 0;
    while(true){
        int randIndex = (int)rand() % 4;
        if(isNotFilled[randIndex]){
            if(randIndex == 0){
                positionReturnCode = PositionAndCollision(  -1, 0);
                if(positionReturnCode == 0 ) break;
                world->AddOrganism(this, point.getX(),point.getY());
                Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
                break;
            } if(randIndex == 1){
                positionReturnCode = PositionAndCollision(  1, 0);
                if(positionReturnCode == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
                break;
            } if(randIndex == 2){
                positionReturnCode = PositionAndCollision(  0, -1);
                if(positionReturnCode == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
                break;
            } if(randIndex == 3){
                positionReturnCode = PositionAndCollision(  0, 1);
                if(positionReturnCode == 0) break;
                world->AddOrganism(this, point.getX(),point.getY());
                Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
                break;
            }
        }
    }
}
Organism* Animal::CreateNewAnimal(char symbol){
    if(symbol == 'W'){
        Organism* wolf = new class Wolf;
        return wolf;
    }
    else if(symbol == 'A'){
        Organism* antelope = new class Antelope;
        return antelope;
    }
    else if(symbol == 'E'){
        Organism* sheep = new class Sheep;
        return sheep;
    }
    else if(symbol == 'T'){
        Organism* turtle = new class Turtle;
        return turtle;
    }
    else if(symbol == 'F'){
        Organism* fox = new class Fox;
        return fox;
    }
    return nullptr;
}
int Animal::Collision(Point& pointDefender){
    char worldSymbol = world->ReturnSymbol(pointDefender.getX(), pointDefender.getY());
    int getAgeDefender = world->ReturnAge(pointDefender.getX(), pointDefender.getY());
    if(worldSymbol == getSymbol() && getAgeDefender != 0){
        //create new specie
        int isNotFilled[4] = {0, 0, 0, 0};
        if(CheckForFillingWithAnimals(isNotFilled, point) != 0) return error;
        if(CheckForFillingWithAnimals(isNotFilled, point) != 0){
            int isNotFilled2[4] = {0, 0, 0, 0};
            if(CheckForFillingWithAnimals(isNotFilled2, pointDefender) != 0) return error;
            while(true){
                int randIndex2 = (int)rand() % 4;
                if(isNotFilled[randIndex2]){
                    AddNewOrganism(randIndex2, pointDefender, CreateNewAnimal(getSymbol()));
                    Logs::AddComment("Created new Organism at point" + std::to_string(pointDefender.getX())
                    +"," + std::to_string(pointDefender.getY()) + "\n");
                    return reproduction;
                }
            }
        }
        while(true){
            int randIndex2 = (int)rand() % 4;
            if(isNotFilled[randIndex2]){
                AddNewOrganism(randIndex2, pointDefender, CreateNewAnimal(getSymbol()));
                Logs::AddComment("Created new Organism at point" + std::to_string(pointDefender.getX())
                                 +"," + std::to_string(pointDefender.getY()) + "\n");
                return reproduction;
            }
        }
    }
    else if(worldSymbol != getSymbol() && worldSymbol != nullSpace && worldSymbol != '"'){
        Organism* newFightingOrganism = world->GetOrganism(pointDefender.getX(), pointDefender.getY());
        if(newFightingOrganism->SpecialAttack(this) || newFightingOrganism->SpecialAttack(newFightingOrganism)){
            return error;
        }
        if(newFightingOrganism->getStrength() > getStrength()){
            world->DeleteOrganism(this, point.getX(), point.getY());
            Logs::AddComment("Deleted Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
            return killedAnimalAttacker;
        }
        else if(newFightingOrganism->getStrength() <= getStrength()){
            world->DeleteOrganism(this,point.getX(), point.getY());
            Logs::AddComment("Deleted Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
            world->DeleteOrganism(newFightingOrganism, pointDefender.getY(), pointDefender.getY());
            Logs::AddComment("Deleted Organism at point" + std::to_string(pointDefender.getX())
                             +"," + std::to_string(pointDefender.getY()) + "\n");
            return killedAnimal;
        }
    }
    else {
    world->DeleteOrganism(this,point.getX(), point.getY());
     Logs::AddComment("Deleted Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
    return NoCollision;
    }
        //fight
        return error;
}
int Animal::CheckForFilling(int* isNotFilled, int change) {
    int x = point.getX();
    int y = point.getY();
    if(world->ReturnSymbol(x - change, y) == nullSpace || world->ReturnSymbol(x - change, y) != '"' ) isNotFilled[0] = true;
    if(world->ReturnSymbol(x + change, y) == nullSpace || world->ReturnSymbol(x +change, y) != '"' ) isNotFilled[change] = true;
    if(world->ReturnSymbol(x, y - change) == nullSpace || world->ReturnSymbol(x , y -change) != '"' ) isNotFilled[2] = true;
    if(world->ReturnSymbol(x, y + change) == nullSpace || world->ReturnSymbol(x, y + change) != '"' ) isNotFilled[3] = true;
    for(int i = 0; i < 4; i++){
        if(isNotFilled[i] == true) return 0;
    }
    return 1;

}
int Animal::CheckForFillingWithAnimals(int* isNotFilled, Point point) {
    int x = point.getX();
    int y = point.getY();
    if(world->ReturnSymbol(x - 1, y) == nullSpace) isNotFilled[0] = true;
    if(world->ReturnSymbol(x + 1, y) == nullSpace) isNotFilled[1] = true;
    if(world->ReturnSymbol(x, y - 1) == nullSpace) isNotFilled[2] = true;
    if(world->ReturnSymbol(x, y + 1) == nullSpace) isNotFilled[3] = true;
    for(int i = 0; i < 4; i++){
        if(isNotFilled[i] == true) return 0;
    }
    return 1;

}


int Animal::PositionAndCollision( int x, int y) {
    Point pointDefender;
    int varX = point.getX() + x;
    int varY = point.getY() + y;
    pointDefender.setX(varX);
    pointDefender.setY(varY);
    int collisionReturn = Collision(pointDefender);
    if(collisionReturn == NoCollision || collisionReturn== killedAnimal){
        point.setX(varX);
        point.setY(varY);
        return 1;
    }
    else if(collisionReturn == killedAnimalAttacker || collisionReturn == reproduction || collisionReturn == error){
        return 0;
    }
    return 1;
}

Point Animal::AddNewOrganism(int randIndex, Point point, Organism* organism){
    if(randIndex == 0){
        point.setX(point.getX()-1);
        point.setY(point.getY());
        world->AddOrganism(organism, point.getX(),point.getY());
        Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
        return point;
    } else if(randIndex == 1){
        point.setX(point.getX()+1);
        point.setY(point.getY());
        world->AddOrganism(organism, point.getX(),point.getY());
        Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
        return point;
    } else if(randIndex == 2){
        point.setX(point.getX());
        point.setY(point.getY() - 1);
        world->AddOrganism(organism, point.getX(),point.getY());
        Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
        return point;
    } else if(randIndex == 3){
        point.setX(point.getX());
        point.setY(point.getY() + 1);
        world->AddOrganism(organism, point.getX(),point.getY());
        Logs::AddComment("Created Organism at point" + std::to_string(point.getX()) +"," + std::to_string(point.getY()) + "\n");
        return point;
    }
    return point;
}
