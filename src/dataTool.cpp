#include "gamedata.hpp"
#include <iostream>

int main(){

    Data d = Data();

    std::cout << "data file name: " << std::endl;
    std::string s;
    std::cin >> s;

    d.loadData(s);

    d.printMoves();
    
    return 0;
}