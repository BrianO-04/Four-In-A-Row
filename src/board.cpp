#include "../include/board.hpp"
#include <iostream>

// Create a new board of size w x h
Board::Board(char w, char h){
    this->w = w;
    this->h = h;
    positions = new char[w * h];
    for(int i = 0; i < w * h; i++){
        positions[i] = 0;
    }
}

Board::~Board(){
    delete[] positions;
}

// Insert a piece in the lowest possible row of a column
// Returns -1 if a piece cannot be placed
// Returns final row if successful
int Board::put(char piece, char col){
    if(col < 0 || col > w){
        return -1;
    }

    int row = h-1;
    char pieceAtPos = getPieceAt(row, col);
    while(pieceAtPos != 0){
        row -=1;
        if(row < 0) return -1;
        pieceAtPos = getPieceAt(row, col);
    }

    int finalPos = (row * w) + col;
    positions[finalPos] = piece;
    return row;
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
            while(curr < h){
                char tmp = getPieceAt(curr, col);
                if(tmp == piece) total++;
                else break;
                curr += 1;
            }
            if(total >= 4) return 1;
        }
        // Up
        if(row > 0){
            int curr = row-1;
            while(curr < h){
                char tmp = getPieceAt(curr, col);
                if(tmp == piece) total++;
                else break;
                curr -= 1;
            }
            if(total >= 4) return 1;
        }
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
    {
        int total = 1;
        // Up-Left
        if(col > 0 && row > 0){
            int currCol = col-1;
            int currRow = row-1;
            while(currCol >= 0 && currRow >= 0){
                char tmp = getPieceAt(currRow, currCol);
                if(tmp == piece) total++;
                else break;
                currCol -= 1;
                currRow -= 1;
            }
            if(total >= 4) return 1;
        }
        // Down-Right
        if(col < w && row < h){
            int currCol = col+1;
            int currRow = row+1;
            while(currCol < w && currRow < h){
                char tmp = getPieceAt(currRow, currCol);
                if(tmp == piece) total++;
                else break;
                currCol += 1;
                currRow += 1;
            }
            if(total >= 4) return 1;
        }
    }

    // Diagonal Up-Right/Down-Left Check
    {
        int total = 1;
        // Up-Right
        if(col < w && row > 0){
            int currCol = col+1;
            int currRow = row-1;
            while(currCol <w && currRow >= 0){
                char tmp = getPieceAt(currRow, currCol);
                if(tmp == piece) total++;
                else break;
                currCol += 1;
                currRow -= 1;
            }
            if(total >= 4) return 1;
        }
        // Down-Left
        if(col < w && row < h){
            int currCol = col-1;
            int currRow = row+1;
            while(currCol >= 0 && currRow < h){
                char tmp = getPieceAt(currRow, currCol);
                if(tmp == piece) total++;
                else break;
                currCol -= 1;
                currRow += 1;
            }
            if(total >= 4) return 1;
        }
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
    for(int i = 0; i < w; i++){
        std::cout << i;
    }
    std::cout << std::endl;
    for(int i = 0; i < w * h; i++){
        if(i % w == 0 && i != 0){
            std::cout << std::endl;
        }
        if(positions[i] == 0) std::cout << '_';
        else if(positions[i] == 1) std::cout << 'X';
        if(positions[i] == 2) std::cout << 'O';
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