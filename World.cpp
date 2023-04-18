//
// Created by Latandu on 13/04/2023.
//

#include "World.h"
#include <iostream>
#include <algorithm>
#define nullSpace '*'
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Sosnowsky.h"
#include "Guarana.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Belladonna.h"
using namespace std;
World::World(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    this->grid.resize(rows,vector<Organism*>(columns, nullptr));
}

 World::~World() {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            delete grid[i][j];
        }
    }
}
void World::DrawWorld() {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(grid[i][j] == nullptr){
                cout << '*';
            }
            else cout << grid[i][j]->getSymbol();
        }
        cout << endl;
    }
}
char World::ReturnSymbol(int row, int column) {
    if(row < 0 || column < 0 || row >= rows || column >= columns){
        return '"';
    }
    if(grid[row][column] == nullptr){
        return '*';
    }
    return grid[row][column]->getSymbol();
}
Organism* World::GetOrganism(int row, int column){
    return grid[row][column];
}
void World::FillBoardWithOrganisms(){
    srand(time(nullptr));
    for(int i = 0; i < rows * columns / 100; i++) {
        Organism* wolf = new Wolf;
        Organism* sheep = new Sheep;
        Organism* turtle = new Turtle;
        Organism* fox = new Fox;
        Organism* antelope = new Antelope;
        Organism* belladonna = new Belladonna;
        Organism* grass = new Grass;
        Organism* guarana = new Guarana;
        Organism* sosnowsky = new Sosnowsky;
        Organism* sowThistle = new SowThistle;
        AddRandomlyCharacter(wolf);
        AddRandomlyCharacter(sheep);
        AddRandomlyCharacter(turtle);
        AddRandomlyCharacter(fox);
        AddRandomlyCharacter(antelope);
        AddRandomlyCharacter(belladonna);
        AddRandomlyCharacter(grass);
        AddRandomlyCharacter(guarana);
        AddRandomlyCharacter(sosnowsky);
        AddRandomlyCharacter(sowThistle);
    }
}

void World::AddRandomlyCharacter(Organism* organism) {
        int rowRandom = rand() % rows;
        if(rowRandom == rows) rowRandom--;
        int columnRandom = rand() % columns;
        if(columnRandom == columns) columnRandom--;
        if(grid[rowRandom][columnRandom] != nullptr){
            AddRandomlyCharacter(organism);
        }
        if(grid[rowRandom][columnRandom] == nullptr) {
            organism->setPoint(rowRandom, columnRandom);
            organism->setWorld(this);
            grid[rowRandom][columnRandom] = organism;
            organismVector.push_back(organism);
        }

}

void World::DeleteOrganism(Organism* organism, int row, int column){
    grid[row][column] = nullptr;
    organismVector.erase(std::find(organismVector.begin(), organismVector.end(),organism));
}

void World::AddOrganism(Organism* organism, int row, int column){
    organism->setWorld(this);
    organism->setPoint(row, column);
    grid[row][column] = organism;
    organismVector.push_back(organism);

}

void World::makeTurn() {
    int organismVectorSize = (int)organismVector.size();
    while(organismVectorSize >= 0) {
        int highestInitiative = 0;
        Organism *currentOrganism = nullptr;
        for (auto & i : organismVector) {
            if (i->getInitiative() >= highestInitiative && !i->isRoundDone() && i->getAge() > 0) {
                highestInitiative = i->getInitiative();
                currentOrganism = i;
            }
        }
        int highestAge = 0;
        for (auto & i : organismVector) {
            if(i != currentOrganism) continue;
            if (highestAge > i->getAge() && !i->isRoundDone() && i->getAge() > 0) {
                highestAge = i->getAge();
                currentOrganism = i;
            }
        }
        if(currentOrganism!= nullptr){
            currentOrganism->setRoundDone(true);
            currentOrganism->Action();
        }
        organismVectorSize--;
    }
    for (auto & i : organismVector) {
        i->setRoundDone(false);
        i->setAge(i->getAge() + 1);
    }
    numberOfRounds++;
}

void World::setGrid(const vector<vector<Organism *>> &grid) {
    World::grid = grid;
}

const vector<Organism *> &World::getOrganismVector() const {
    return organismVector;
}

void World::setOrganismVector(const vector<Organism *> &organismVector) {
    World::organismVector = organismVector;
}
void World::WholeGame(){
    FillBoardWithOrganisms();
    while(numberOfRounds < 15){
        makeTurn();
        DrawWorld();
        std::cout << endl;
    }
}