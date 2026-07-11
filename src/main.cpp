#include <iostream>
#include "../include/board.hpp"

int main(){
    Board b = Board(6,6);

    for(int i = 0; i < 4; i ++){
        b.put(1, i);
    }
    for(int i = 0; i < 3; i ++){
        b.put(1, 2);
    }
    
    b.printBoard();

    std::cout << b.check(5, 0) << std::endl;
    std::cout << b.check(5, 1) << std::endl;
    std::cout << b.check(5, 2) << std::endl;
    std::cout << b.check(5, 3) << std::endl;
    std::cout << b.check(2, 2) << std::endl;
    std::cout << b.check(5, 2) << std::endl;

    return 0;
}