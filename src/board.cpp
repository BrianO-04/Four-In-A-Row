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
// Returns 1 upon win
bool Board::check(char row, char col){
    if(row < 0 || row > h || col < 0 || col > w){
        return 1;
    }
    char piece = getPieceAt(row, col);
    if(piece == 0) return 0;

    // Vertical check
    {
        int total = 1;
        // Down
        if(row <= 2){
            int curr = row+1;
            while(row < h){
                char tmp = getPieceAt(curr, col);
                if(tmp == piece) total++;
                else break;
                row += 1;
            }
        }
        // Up
        if(row > 0){
            int curr = row-1;
            while(row < h){
                char tmp = getPieceAt(curr, col);
                if(tmp == piece) total++;
                else break;
                row -= 1;
            }
        }
        if(total >= 4) return 1;
    }
    

    // Horizontal check
    {
        int total = 1;
        // Left check
        if(col > 0){
            int curr = col-1;
            while(curr >= 0){
                char tmp = getPieceAt(row, curr);
                if(tmp == piece) total++;
                else break;
                curr -= 1;
            }
            if(total >= 4) return 1;
        }
        // Right check
        if(col < w){
            int curr = col+1;
            while(curr < w){
                char tmp = getPieceAt(row, curr);
                if(tmp == piece) total++;
                else break;
                curr += 1;
            }
            if(total >= 4) return 1;
        }
    }

    // Diagonal Up-Left/Down-Right Check
    // TODO

    // Diagonal Up-Right/Down-Left Check
    // TODO

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