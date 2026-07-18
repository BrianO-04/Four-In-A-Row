#include "gamedata.hpp"
#include <chrono>
#include <iostream>
#include <fstream>

int Data::saveData(){
    auto now = std::chrono::floor<std::chrono::seconds>(std::chrono::system_clock::now());
    std::string fileName = std::format("data/{:%H-%M-%S}.bin", now);

    std::ofstream outFile(fileName, std::ios::out | std::ios::binary);

    if (!outFile) {
        std::cerr << "Error creating data file!" << std::endl;
        return 1;
    }

    outFile.write(reinterpret_cast<const char*>(&moves), sizeof(moves));

    outFile.close();
    return 0;
}

void Data::addMove(int move){
    if(moveNum < 7*6) moves[moveNum++] = move;
}

int Data::loadData(const std::string &fileName){
    std::ifstream inFile(fileName, std::ios::in | std::ios::binary);

    if (!inFile) {
        std::cerr << "Error opening data file!" << std::endl;
        return 1;
    }

    inFile.read(reinterpret_cast<char*>(&moves), sizeof(moves));

    if (!inFile) {
        std::cerr << "Error reading data!" << std::endl;
        return 1;
    }

    return 0;
}

void Data::printMoves(){
    for(int i = 0; i < 7*6; i++){
        std::cout << moves[i];
    }
    std::cout << std::endl;
}