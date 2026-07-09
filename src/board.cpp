#include "../include/board.hpp"
#include <cstdlib>

Board::Board(char w, char h){
    positions = (char*)malloc(sizeof(char) * w * h);
}

Board::~Board(){
    free(positions);
}

