#include <iostream>
#include <ostream>
#include "../include/board.hpp"
#include "../include/input.hpp"
#include "../include/controller.hpp"
#include "gamedata.hpp"

int main(){
    Board* b = new Board(7,6);

    Controller* p1 = new Player(b, '1', 1);
    Controller* p2;

    std::cout << "Select player 2 type" << std::endl;
    std::cout << "(Player 1 is always player controlled)" << std::endl;
    std::cout << "1) Player controlled (Default)" << std::endl;
    std::cout << "2) Random columns" << std::endl;
    std::cout << "3) Simple AI (Recommended)" << std::endl;
    std::cout << "4) NN AI" << std::endl;
    std::cout << "Input: ";
    int pChoice = getNumberInput();
    if(pChoice == 2){
        p2 = new RandomComp(b, '2', 2);
    }else if(pChoice == 3){
        p2 = new SimpleComp(b, '2', 2);
    }else if(pChoice == 4){
        p2 = new NNAI(b, '2', 2, "weights/Weights.bin");
    }
    else{
        p2 = new Player(b, '2', 2);
    }

    Data* game = new Data();

    while(1){
        // Player 1 input
        if(p1->Move(game)){
            b->printBoard();
            game->saveData();
            std::cout << "Player 1 win!" << std::endl;
            break;
        }

        // Player 2 input
        if(p2->Move(game)){
            b->printBoard();
            if(dynamic_cast<Player*>(p2)) game->saveData();
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
    delete game;

    return 0;
}