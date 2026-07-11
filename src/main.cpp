#include <iostream>
#include "../include/board.hpp"

int main(){
    Board b = Board(6,6);

    b.put(1, 3);
    b.put(1, 3);
    b.put(1, 3);
    b.put(2, 3);

    b.put(1, 2);
    b.put(1, 2);
    b.put(2, 2);

    b.put(1, 1);
    b.put(2, 1);

    b.put(2, 0);
    
    b.printBoard();

    std::cout << b.check(2, 3) << std::endl;
    std::cout << b.check(5, 0) << std::endl;

    return 0;
}