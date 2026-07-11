#include <iostream>
#include <ostream>
#include "../include/board.hpp"

int main(){
    int w, h;
    std::cout << "Input board width: ";
    std::cin >> w;
    std::cout << "Input board height: ";
    std::cin >> h;

    while(w < 4 && h < 4){
        std::cout << "Board must be at least four in one dimension!" << std::endl;
        std::cout << "Input board width: ";
        std::cin >> w;
        std::cout << "Input board height: ";
        std::cin >> h;
    }

    Board b = Board(w,h);

    b.printBoard();

    while(1){
        // Player 1 input
        std::cout << "Player 1, input column: ";
        int col;
        std::cin >> col;

        int row = b.put(1, col);
        while(row == -1){ // Invalid input loop
            b.printBoard();
            std::cout << "Invalid input!" << std::endl << "Player 1, input column: ";
            std::cin >> col;
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
        std::cin >> col;

        row = b.put(2, col);
        while(row == -1){ // Invalid input loop
            b.printBoard();
            std::cout << "Invalid input!" << std::endl << "Player 2, input column: ";
            std::cin >> col;
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