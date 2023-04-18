//
// Created by Latandu on 13/04/2023.
//

#include "Plant.h"
#include "SowThistle.h"
#define nullSpace '*'
void Plant::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled) != 0) {
        return;
    }
    int randomProbability = (int)std::rand() % 10;
    if(randomProbability == 0){
        while(true){
            int randIndex = (int)std::rand() % 4;
            if(isNotFilled[randIndex]){
                Organism* sowHog = new SowThistle;
                AddNewOrganism(randIndex, point, sowHog);
                break;
            }
        }
    }
}

int Plant::CheckForFilling(int* isNotFilled) {
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
Point Plant::AddNewOrganism(int randIndex, Point point, Organism* organism){
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