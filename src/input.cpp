#include "../include/input.hpp"
#include <iostream>

int getNumberInput(){
    int out;
    while(!(std::cin >> out)){
        std::cout << "Invalid input. Please enter a whole number: ";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    return out;
}