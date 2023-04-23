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
    bool saveFile = false;
    int numberOfRounds = 0;
    World(int rows, int columns);
    World();
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

    int GetStrength(int row, int column);

    int ReturnAge(int row, int column);

    bool AliveHuman = true;

    void SaveToFile();

    void ReadFromFile();

    void InitializeOrganism(int age, int strength, int coolDown, int initiative, int pointX, int pointY, char symbol,
                            bool roundDone, const string &animalName);
};


#endif //FIRSTPROJECT_WORLD_H
