//
// Created by Latandu on 13/04/2023.
//

#ifndef FIRSTPROJECT_WORLD_H
#define FIRSTPROJECT_WORLD_H
#include "Organism.h"
#include <string>
#include <vector>

using namespace std;
class Organism;
class World {
protected:
    int rows;
    int columns;
    vector<vector<Organism*>> grid;
    Organism* organisms;
    vector<Organism*> organismVector;
public:
    World(int rows, int columns);
    void makeTurn();
    void DrawWorld();
    ~World();
    //void AddOrganism(Organism *organism, int row, int column);
    char ReturnSymbol(int row, int column);
    void AddOrganism(int row, int column, char symbol);
    void DeleteOrganism(int row, int column);
    void AddNewOrganism(Organism *organism, int row, int column);

    void FillBoardWithOrganisms();


    void AddRandomlyCharacter(Organism *organism, char symbol, const string &animalName);

    void AddRandomlyCharacter(Organism *organism);
};


#endif //FIRSTPROJECT_WORLD_H
