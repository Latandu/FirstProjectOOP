//
// Created by Latandu on 13/04/2023.
//

#include <conio.h>
#include "Human.h"
#include "Logs.h"

void Human::Action() {
    int isNotFilled[4] = {0, 0, 0, 0};
    if(CheckForFilling(isNotFilled, 1) != 0) {
        return;
    }
    int positionReturnCode;
    while(true){
        cout << "Enter Key:" << endl;
        int action = getch();
        switch (action) {
            case 0x48:
               if(isNotFilled[0]){
                   positionReturnCode = PositionAndCollision(  -1, 0);
                   if(positionReturnCode == 0 ) return;
                   world->AddOrganism(this, point.getX(),point.getY());
                   return;
               }
                cout << "Cannot go there" << endl;
                break;
            case 0x50:
                if(isNotFilled[1]){
                    positionReturnCode = PositionAndCollision(  1, 0);
                    if(positionReturnCode == 0 ) return;
                    world->AddOrganism(this, point.getX(),point.getY());
                    return;
                }
                cout << "Cannot go there" << endl;
                break;
            case 0x4b:
                if(isNotFilled[2]){
                    positionReturnCode = PositionAndCollision(  0, -1);
                    if(positionReturnCode == 0 ) return;
                    world->AddOrganism(this, point.getX(),point.getY());
                    return;
                }
                cout << "Cannot go there" << endl;
                break;
            case 0x4d:
                if(isNotFilled[3]){
                    positionReturnCode = PositionAndCollision(  0, 1);
                    if(positionReturnCode == 0 ) return;
                    world->AddOrganism(this, point.getX(),point.getY());
                    return;
                }
                cout << "Cannot go there" << endl;
                break;
            case 0x70:
                if(coolDown == 0){
                    this->setStrength(10);
                    Logs::AddComment("Activated human superpower - set strength to 10");
                    cout << "Activated superPower" << endl;
                }
                break;
            case 0x73:
                this->setRoundDone(false);
                world->saveFile = true;
                cout << "File will be saved after the round finishes";
                break;
            case 0x1b:
                delete world;
                cout << "Exited game" << endl;
                system("pause");
                exit(0);
            default:
                break;
        }
    }
}
Human::Human(){
    this->setStrength(5);
    this->setInitiative(4);
    this->setSymbol('@');
    this->setAnimalName("Human");
}
