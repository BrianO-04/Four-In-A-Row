#include "../include/board.hpp"
#include <cstdlib>

// Create a new board of size w x h
Board::Board(char w, char h){
    positions = (char*)malloc(sizeof(char) * w * h);
}

Board::~Board(){
    free(positions);
}

// Insert a piece in the lowest possible row of a column
int Board::put(char piece, char col){
    return 0;
}

// Check if a piece is part of a winning combination
bool Board::check(char row, char col){
    return 0;
}