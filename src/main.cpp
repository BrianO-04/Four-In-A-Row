#include <iostream>
#include <ostream>
#include "../include/board.hpp"

// Handles invalid inputs automatically
int getNumberInput(){
    int out;
    while(!(std::cin >> out)){
        std::cout << "Invalid input. Please enter a whole number: ";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    return out;
}

int main(){
    std::cout << "Input board width: ";
    int w = getNumberInput();
    std::cout << "Input board height: ";
    int h = getNumberInput();

    while(w < 4 && h < 4){
        std::cout << "Board must be at least four in one dimension!" << std::endl;
        std::cout << "Input board width: ";
        w = getNumberInput();
        std::cout << "Input board height: ";
        h = getNumberInput();
    }

    Board b = Board(w,h);

    b.printBoard();

    while(1){
        // Player 1 input
        std::cout << "Player 1, input column: ";
        int col = getNumberInput();

        int row = b.put(1, col);
        while(row == -1){ // Invalid input loop
            b.printBoard();
            std::cout << "Invalid input!" << std::endl << "Player 1, input column: ";
            col = getNumberInput();
            row = b.put(1, col);
        }
        b.printBoard();
        // Player 1 win check
        if(b.check(row, col)){
            std::cout << "Player 1 win!" << std::endl;
            break;
        }

        // Player 2 input
        std::cout << "Player 2, input column: ";
        col = getNumberInput();

        row = b.put(2, col);
        while(row == -1){ // Invalid input loop
            b.printBoard();
            std::cout << "Invalid input!" << std::endl << "Player 2, input column: ";
            col = getNumberInput();
            row = b.put(2, col);
        }
        b.printBoard();
        // Player 2 win check
        if(b.check(row, col)){
            std::cout << "Player 2 win!" << std::endl;
            break;
        }
    }

    return 0;
}