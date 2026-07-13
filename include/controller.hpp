#ifndef CON_H_
#define CON_H_

#include "board.hpp"
#include <random>

class Controller{
    protected:
        Board* board;
        char piece;
        int number;
    public:
        virtual ~Controller() = default;
        Controller(Board* b, char p, int n);
        virtual bool Move() = 0; // Returns true on winning move
};

class Player : public Controller{
    public:
        using Controller::Controller;
        bool Move();
};

class RandomComp : public Controller{
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> distrib;
    public:
        RandomComp(Board* b, char p, int n);
        bool Move();
};

class SimpleComp : public Controller{
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> distrib;
    public:
        SimpleComp(Board* b, char p, int n);
        bool Move();
};

#endif //CON_H_