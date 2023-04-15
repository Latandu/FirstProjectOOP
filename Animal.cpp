//
// Created by Latandu on 13/04/2023.
//

#include "Animal.h"
#define nullSpace '*'
void Animal::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled) == 0) return;
    while(true){
        int randIndex = (int)std::rand() % 3;
        if(isNotFilled[randIndex]){
            ChangePositionOfOrganism(randIndex);
            break;
        }
    }
}
void Animal::Collision(){
    if(world->ReturnSymbol(point.getX(), point.getY()) == getSymbol()){
        //create new specie
        int isNotFilled[4] = {0, 0, 0, 0};
        if(CheckForFilling(isNotFilled) == 0) return;
        while(true){
            int randIndex = (int)std::rand() % 3;
            if(isNotFilled[randIndex]){
                ChangePositionOfOrganism(randIndex);
                break;
            }
        }
    }
    else{
        //fight

    }
}
int Animal::CheckForFilling(int* isNotFilled) {
    int x = point.getX();
    int y = point.getY();
    if(world->ReturnSymbol(x - 1, y) == nullSpace) isNotFilled[0] = true;
    else if(world->ReturnSymbol(x + 1, y) == nullSpace) isNotFilled[1] = true;
    else if(world->ReturnSymbol(x, y - 1) == nullSpace) isNotFilled[2] = true;
    else if(world->ReturnSymbol(x, y + 1) == nullSpace) isNotFilled[3] = true;
    for(int i = 0; i < 4; i++){
        if(isNotFilled[i] == 0) return 0;
    }
    return 1;

}
void Animal::ChangePositionOfOrganism(int randIndex){
    if(randIndex == 0){
        world->DeleteOrganism(point.getX(), point.getY());
        point.setX(point.getX()-1);
        point.setY(point.getY());
        world->AddOrganism(point.getX(),point.getY(),symbol);
    } if(randIndex == 1){
        world->DeleteOrganism(point.getX(), point.getY());
        point.setX(point.getX()+1);
        point.setY(point.getY());
        world->AddOrganism(point.getX(),point.getY(),symbol);
    } if(randIndex == 2){
        world->DeleteOrganism(point.getX(), point.getY());
        point.setX(point.getX());
        point.setY(point.getY() - 1);
        world->AddOrganism(point.getX(),point.getY(),symbol);
    } if(randIndex == 3){
        world->DeleteOrganism(point.getX(), point.getY());
        point.setX(point.getX());
        point.setY(point.getY() + 1);
        world->AddOrganism(point.getX(),point.getY(),symbol);
    }

}