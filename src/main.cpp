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

    Controller* p1;
    Controller* p2;

    std::cout << "Select player 1 type" << std::endl;
    std::cout << "1) Player controlled (Default)" << std::endl;
    std::cout << "2) Random columns" << std::endl;
    std::cout << "3) Simple AI" << std::endl;
    std::cout << "Input: ";
    int p1Choice = getNumberInput();
    if(p1Choice == 2){
        p1 = new RandomComp(b, '1', 1);
    }else if(p1Choice == 3){
        p1 = new SimpleComp(b, '1', 1);
    }
    else{
        p1 = new Player(b, '1', 1);
    }

    std::cout << "Select player 2 type" << std::endl;
    std::cout << "1) Player controlled (Default)" << std::endl;
    std::cout << "2) Random columns" << std::endl;
    std::cout << "3) Simple AI" << std::endl;
    std::cout << "Input: ";
    int p2Choice = getNumberInput();
    if(p2Choice == 2){
        p2 = new RandomComp(b, '2', 2);
    }else if(p2Choice == 3){
        p2 = new SimpleComp(b, '2', 2);
    }else{
        p2 = new Player(b, '2', 2);
    }

    while(1){
        // Player 1 input
        if(p1->Move()){
            b->printBoard();
            std::cout << "Player 1 win!" << std::endl;
            break;
        }

        // Player 2 input
        if(p2->Move()){
            b->printBoard();
            std::cout << "Player 2 win!" << std::endl;
            break;
        }

        if(b->full()){
            b->printBoard();
            std::cout << "Draw!" << std::endl;
            break;
        }
    }

    delete b;
    delete p1;
    delete p2;

    return 0;
}