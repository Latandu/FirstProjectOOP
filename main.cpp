#include <iostream>
#include "World.h"
#include "Wolf.h"
#include "Animal.h"
int main() {
    auto* world = new World(5,5);
    world->FillBoardWithOrganisms();
    world->DrawWorld();
    delete world;
    return 0;
}
