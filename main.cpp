#include <iostream>
#include "World.h"

int main() {
    auto* world = new World(10,10);
    world->WholeGame();
    delete world;
    return 0;
}
