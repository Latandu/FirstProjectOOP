#include <windows.h>
#include <conio.h>
#include <iostream>
#include "World.h"
int main() {
    SetConsoleTitle("Jakub Andrunik 193166");
    std::cout << "Would you like to read from file? Y/N" << endl;
    int action = getch();
    auto* world2 = new World;
    switch(action){
        case 0x79:
            system("cls");
            world2->ReadFromFile();
            world2->WholeGame();
            system("pause");
            delete world2;
            return 0;
        case 0x6e:
            system("cls");
            break;
        default:
            cout << "Invalid key" << endl;
    }
    cout << "Input size (after space)";
    int row, column;
    cin >> row >> column;
    auto* world = new World(row,column);
    world->FillBoardWithOrganisms();
    world->WholeGame();
    delete world;
    system("pause");
    return 0;
}
