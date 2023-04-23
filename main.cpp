#include <windows.h>
#include <iostream>
#include "World.h"
int main() {
    SetConsoleTitle("Jakub Andrunik 193166");
    auto* world = new World(15,15);
    world->WholeGame();
    delete world;
    system("pause");
    return 0;
}
