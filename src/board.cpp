#include "../include/board.hpp"
#include <cstdlib>
#include <iostream>

// Create a new board of size w x h
Board::Board(char w, char h){
    this->w = w;
    this->h = h;
    positions = (char*)malloc(sizeof(char) * w * h);
    for(int i = 0; i < w * h; i++){
        positions[i] = 0;
    }
}

Board::~Board(){
    free(positions);
}

// Insert a piece in the lowest possible row of a column
// Returns 1 if a piece cannot be placed
int Board::put(char piece, char col){
    if(col < 0 || col > w){
        return 1;
    }

    int row = h-1;
    char pieceAtPos = getPieceAt(row, col);
    while(pieceAtPos != 0){
        row -=1;
        if(row < 0) return 1;
        pieceAtPos = getPieceAt(row, col);
    }

    int finalPos = (row * w) + col;
    positions[finalPos] = piece;
    return 0;
}

// Check if a piece is part of a winning combination
bool Board::check(char row, char col){
    if(row < 0 || row > h || col < 0 || col > w){
        return 1;
    }

    return 0;
}

// Reset board
void Board::reset(){
    for(int i = 0; i < w * h; i++){
        positions[i] = 0;
    }
}

void Board::printBoard(){
    for(int i = 0; i < w * h; i++){
        if(i % w == 0 && i != 0){
            std::cout << std::endl;
        }
        std::cout << (int)positions[i];
    }
    std::cout << std::endl << std::endl;
}

char Board::getPieceAt(int row, int col){
    if(row < 0 || row > h || col < 0 || col > w){
        return -1;
    }

    int index = (row * w) + col;
    return positions[index];
}