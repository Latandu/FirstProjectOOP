//
// Created by Latandu on 13/04/2023.
//
#include "World.h"
#include <iostream>
#include <algorithm>
#include <fstream>

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
#include "Logs.h"
#include "Human.h"

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
int World::ReturnAge(int row, int column){
    if(row < 0 || column < 0 || row >= rows || column >= columns){
        return 0;
    }
    if(grid[row][column] == nullptr){
        return 0;
    }
    return grid[row][column]->getAge();
}
Organism* World::GetOrganism(int row, int column){
    if(row < 0 || column < 0 || row >= rows || column >= columns){
        return nullptr;
    }
    return grid[row][column];
}
int World::GetStrength(int row, int column){
    if(row < 0 || column < 0 || row >= rows || column >= columns){
        return 0;
    }
    if(grid[row][column] == nullptr){
        return 0;
    }
    return grid[row][column]->getStrength();
}
void World::FillBoardWithOrganisms(){
    srand(time(nullptr));
    Organism* human = new Human;
    AddRandomlyCharacter(human);
    for(int i = 0; i < rows / 5; i++) {
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
    if(!AliveHuman) return;
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
        if(i->getSymbol() == '@'){
            if(i->getCoolDown() > 0){
                i->setCoolDown(i->getCoolDown() - 1);
            }
            if(i->getStrength() > 5){
                i->setStrength(i->getStrength() - 1);
                if(i->getStrength() == 5){
                    i->setCoolDown(5);
                }
            }
        }
    }
    numberOfRounds++;

}
void World::SaveToFile(){
    std::ofstream ofs("data.txt");
    ofs << columns << " ";
    ofs << rows << "\n";
    ofs << numberOfRounds << " ";
    ofs << AliveHuman << " ";
    for(auto& i: organismVector){
        ofs << i->getAge() << " ";
        ofs << i->getStrength() << " ";
        ofs << i->getSymbol() << " ";
        ofs << i->getCoolDown() << " ";
        ofs << i->getPoint().getX() << " ";
        ofs << i->getPoint().getY() << " ";
        ofs << i->getAnimalName() << " ";
        ofs << i->getInitiative() << " ";
        ofs << i->isRoundDone() << " ";
    }
    ofs.close();
}
void World::ReadFromFile(){
    std::ifstream ifs("data.txt");
    if (ifs.is_open()) {
    ifs >> rows;
    ifs >> columns;
    ifs >> numberOfRounds;
    ifs >> AliveHuman;
    this->grid.resize(rows,vector<Organism*>(columns, nullptr));
    int age, strength, coolDown, initiative, pointX, pointY;
    char symbol;
    bool roundDone;
    std::string animalName;
    while (ifs >> age >> strength >> symbol >> coolDown >> pointX >> pointY >> animalName >> initiative >> roundDone) {
        InitializeOrganism(age, strength, coolDown, initiative, pointX, pointY, symbol, roundDone, animalName);
    }
    ifs.close();
    } else {
        cout << "Failed to retrieve from file! Exiting..." << endl;
        system("pause");
        exit(1);
    }
}

void World::InitializeOrganism(int age, int strength, int coolDown, int initiative, int pointX, int pointY, char symbol,
                               bool roundDone, const string &animalName){
    Organism* organism = nullptr;
    if(symbol == 'W'){
        organism = new class Wolf;
    }
    else if(symbol == 'A'){
        organism = new class Antelope;
    }
    else if(symbol == 'E'){
        organism = new class Sheep;
    }
    else if(symbol == 'T'){
        organism = new class Turtle;
    }
    else if(symbol == 'F'){
        organism = new class Fox;
    }
    else if(symbol == 'B'){
        organism = new class Belladonna;
    }
    else if(symbol == 'S'){
        organism = new class Sosnowsky;
    }
    else if(symbol == 'G'){
        organism = new class Guarana;
    }
    else if(symbol == 'R'){
        organism = new class Grass;
    }
    else if (symbol == 'O'){
        organism = new class SowThistle;
    }
    else if(symbol == '@'){
        organism = new class Human;
    }
    if(organism == nullptr) return;
    organism ->setAge(age);
    organism ->setStrength(strength);
    organism ->setInitiative(initiative);
    organism ->setSymbol(symbol);
    organism ->setCoolDown(coolDown);
    organism ->setPoint(pointX, pointY);
    organism ->setRoundDone(roundDone);
    organism ->setAnimalName(animalName);
    organism ->setWorld(this);
    grid[pointX][pointY] = organism ;
    organismVector.push_back(organism);
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
    DrawWorld();
    while(AliveHuman){
        Logs::PrintLogs();
        Logs::ClearLogs();
        makeTurn();
        system("cls");
        DrawWorld();
        if(saveFile){
            SaveToFile();
            cout << "Saved file to data.txt" << endl;
        }
        if(!AliveHuman){
            Logs::PrintLogs();
            return;
        }
    }
}

World::World() {

}
