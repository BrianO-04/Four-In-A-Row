#include <iostream>
#include <ostream>
#include "../include/board.hpp"
#include "../include/input.hpp"
#include "../include/controller.hpp"

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

    Board* b = new Board(w,h);

    Player p1 = Player(b, 1, 1);
    Player p2 = Player(b, 2, 2);

    while(1){
        // Player 1 input
        if(p1.Move()){
            b->printBoard();
            std::cout << "Player 1 win!" << std::endl;
            break;
        }

        // Player 2 input
        if(p2.Move()){
            b->printBoard();
            std::cout << "Player 2 win!" << std::endl;
            break;
        }
    }

    delete b;

    return 0;
}