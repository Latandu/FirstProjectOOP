//
// Created by Latandu on 13/04/2023.
//

#include "World.h"
#include <iostream>
#define nullSpace '*'
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

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
    return grid[row][column]->getSymbol();
}
void World::AddNewOrganism(Organism* organism, int row, int column){
    grid[row][column] = organism;

}
void World::FillBoardWithOrganisms(){
    srand(time(nullptr));
    auto* wolf = new Wolf;
    auto* sheep = new Sheep;
    auto* turtle = new Turtle;
    auto* fox = new Fox;
    auto* antelope = new Antelope;
    AddRandomlyCharacter(wolf);
    AddRandomlyCharacter(sheep);
    AddRandomlyCharacter(turtle);
    AddRandomlyCharacter(fox);
    AddRandomlyCharacter(antelope);

}

void World::AddRandomlyCharacter(Organism* organism) {
    for(int i = 0; i < rows * columns / 25; i++) {
        int rowRandom = rand() % rows;
        if(rowRandom == rows) rowRandom--;
        int columnRandom = rand() % columns;
        if(columnRandom == columns) columnRandom--;
        if(grid[rowRandom][columnRandom] != nullptr){
            i--;
            continue;
        }
        organism->setPoint(rowRandom, columnRandom);
        grid[rowRandom][columnRandom] = organism;
        organismVector.push_back(organism);
    }
}

void World::AddOrganism(int row, int column, char symbol){
    grid[row][column]->setSymbol(symbol);
}
void World::DeleteOrganism(int row, int column){
    grid[row][column]->setSymbol(nullSpace);
}
//void World::AddOrganism(Organism* organism, int row, int column){

//}
void World::makeTurn() {

}