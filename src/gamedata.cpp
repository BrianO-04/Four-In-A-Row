#include "gamedata.hpp"
#include <chrono>
#include <string>
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