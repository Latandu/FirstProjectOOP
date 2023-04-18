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
    int numberOfRounds = 0;
    World(int rows, int columns);
    void makeTurn();

    const vector<Organism *> &getOrganismVector() const;

    void setOrganismVector(const vector<Organism *> &organismVector);

    void setGrid(const vector<vector<Organism *>> &grid);

    void DrawWorld();
    ~World();
    //void AddOrganism(Organism *organism, int row, int column);
    char ReturnSymbol(int row, int column);

    void FillBoardWithOrganisms();


    void AddRandomlyCharacter(Organism *organism, char symbol, const string &animalName);

    void AddRandomlyCharacter(Organism *organism);

    void AddOrganism(Organism *organism, int row, int column);

    Organism *GetOrganism(int row, int column);

    void WholeGame();

    void DeleteOrganism(Organism *organism, int row, int column);
};


#endif //FIRSTPROJECT_WORLD_H
