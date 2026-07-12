#include "../include/controller.hpp"
#include "../include/input.hpp"
#include "board.hpp"
#include <iostream>
#include <string>

Controller::Controller(Board* b){
    board = b;
}

bool Player::Move(){
    board->printBoard();
    std::cout << "Player " + std::to_string(number) + ", input column: ";
    int col = getNumberInput();

    int row = board->put(piece, col);
    while(row == -1){ // Invalid input loop
        board->printBoard();
        std::cout << "Invalid input!" << std::endl << "Player " + std::to_string(number) + ", input column: ";
        col = getNumberInput();
        row = board->put(piece, col);
    }

    return board->check(row, col);
}

Player::Player(Board* b, char p, int n) : Controller(b){
    piece = p;
    number = n;
}