#include "../include/controller.hpp"
#include "../include/input.hpp"
#include "board.hpp"
#include <iostream>
#include <string>

Controller::Controller(Board* b, char p, int n){
    board = b;
    piece = p;
    number = n;
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

RandomComp::RandomComp(Board* b, char p, int n) : Controller(b, p, n){
    std::random_device rd;
    gen = std::mt19937(rd());
    distrib = std::uniform_int_distribution<int>(0, b->getWidth()-1);
}

bool RandomComp::Move(){
    board->printBoard();
    int col = distrib(gen);
    std::cout << "Player " << number << ", input column: " << std::to_string(col) << std::endl;

    int row = board->put(piece, col);
    while(row == -1){ // Invalid input loop
        board->printBoard();
        col = distrib(gen);
        std::cout << "Invalid input!" << std::endl << "Player " << number << ", input column: " << std::to_string(col) << std::endl;;
        row = board->put(piece, col);
    }

    return board->check(row, col);
}