//
// Created by Latandu on 13/04/2023.
//

#include "Animal.h"
#define nullSpace '*'
#define error 4
#define killedAnimal 0
#define killedAnimalAttacker 1
#define reproduction 2
#define NoCollision 3
void Animal::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled, point) != 0) {
        return;
    }
    int i = 0;
    while(true){
        int randIndex = (int)std::rand() % 4;
        if(isNotFilled[randIndex]){
          //  Organism* organism1 = world->GetOrganism(point.getX(), point.getY());
            ChangePositionOfOrganism( randIndex, point);
            break;
        }
        i++;
    }
}
int Animal::Collision(Point& pointDefender){
    char worldSymbol = world->ReturnSymbol(pointDefender.getX(), pointDefender.getY());
    if(worldSymbol == getSymbol()){
        //create new specie
        int isNotFilled[4] = {0, 0, 0, 0};
        if(CheckForFillingWithAnimals(isNotFilled, point) != 0){
            int isNotFilled2[4] = {0, 0, 0, 0};
            if(CheckForFillingWithAnimals(isNotFilled2, pointDefender) != 0) return error;
            while(true){
                int randIndex2 = (int)std::rand() % 4;
                if(isNotFilled[randIndex2]){
                    Organism* newFightingOrganism = world->GetOrganism(pointDefender.getX(), pointDefender.getY());
                    AddNewOrganism(randIndex2, pointDefender, newFightingOrganism);
                    return reproduction;
                }
            }
        }
        while(true){
            int randIndex2 = (int)std::rand() % 4;
            if(isNotFilled[randIndex2]){
                Organism* newFightingOrganism = world->GetOrganism(pointDefender.getX(), pointDefender.getY());
                AddNewOrganism(randIndex2, point, newFightingOrganism);
                return reproduction;
            }
        }
    }
    else if(worldSymbol != getSymbol() && worldSymbol != nullSpace && worldSymbol != '"'){
        Organism* newFightingOrganism = world->GetOrganism(pointDefender.getX(), pointDefender.getY());
        if(newFightingOrganism->getStrength() > getStrength()){
            world->DeleteOrganism(this, point.getX(), point.getY());
            return killedAnimalAttacker;
        }
        else if(newFightingOrganism->getStrength() <= getStrength()){
            world->DeleteOrganism(this,point.getX(), point.getY());
            world->DeleteOrganism(newFightingOrganism, pointDefender.getY(), pointDefender.getY());
            return killedAnimal;
        }
    }
    else{
        world->DeleteOrganism(this,point.getX(), point.getY());
        return NoCollision;
    }
        //fight
        return error;
}
int Animal::CheckForFilling(int* isNotFilled, Point point) {
    int x = point.getX();
    int y = point.getY();
    if(world->ReturnSymbol(x - 1, y) == nullSpace || world->ReturnSymbol(x - 1, y) != '"' ) isNotFilled[0] = true;
    if(world->ReturnSymbol(x + 1, y) == nullSpace || world->ReturnSymbol(x +1, y) != '"' ) isNotFilled[1] = true;
    if(world->ReturnSymbol(x, y - 1) == nullSpace || world->ReturnSymbol(x , y -1) != '"' ) isNotFilled[2] = true;
    if(world->ReturnSymbol(x, y + 1) == nullSpace || world->ReturnSymbol(x, y + 1) != '"' ) isNotFilled[3] = true;
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
Point Animal::ChangePositionOfOrganism( int randIndex, Point pointAlfa){
    if(randIndex == 0){
        if(PositionAndCollision(  -1, 0) == 0) return point;
        world->AddOrganism(this, point.getX(),point.getY());
        return point;
    } if(randIndex == 1){
        if(PositionAndCollision( 1, 0) == 0) return point;
       world->AddOrganism(this, point.getX(),point.getY());
        return point;
    } if(randIndex == 2){
        if(PositionAndCollision(   0, -1) == 0) return point;
        world->AddOrganism(this, point.getX(),point.getY());
        return point;
    } if(randIndex == 3){
        if(PositionAndCollision(  0, 1) == 0) return point;
        world->AddOrganism(this, point.getX(),point.getY());
        return point;
    }
    return point;
}

int Animal::PositionAndCollision( int x, int y) {
    Point pointDefender;
    int varX = point.getX() + x;
    int varY = point.getY() + y;
    pointDefender.setX(varX);
    pointDefender.setY(varY);
    int collisionReturn = Collision(pointDefender);
    if(collisionReturn == error) return error;
    else if(collisionReturn == NoCollision || collisionReturn== killedAnimal){
        point.setX(varX);
        point.setY(varY);
        return 1;
    }
    else if(collisionReturn == killedAnimalAttacker || collisionReturn == reproduction){
        return 0;
    }
    return 1;
}

Point Animal::AddNewOrganism(int randIndex, Point point, Organism* organism){
    if(randIndex == 0){
        point.setX(point.getX()-1);
        point.setY(point.getY());
        world->AddOrganism(organism, point.getX(),point.getY());
        return point;
    } else if(randIndex == 1){
        point.setX(point.getX()+1);
        point.setY(point.getY());
        world->AddOrganism(organism, point.getX(),point.getY());
        return point;
    } else if(randIndex == 2){
        point.setX(point.getX());
        point.setY(point.getY() - 1);
        world->AddOrganism(organism, point.getX(),point.getY());
        return point;
    } else if(randIndex == 3){
        point.setX(point.getX());
        point.setY(point.getY() + 1);
        world->AddOrganism(organism, point.getX(),point.getY());
        return point;
    }
    return point;
}
