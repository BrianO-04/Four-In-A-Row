#ifndef CON_H_
#define CON_H_

#include "board.hpp"

class Controller{
    protected:
        Board* board;
        char piece;
        int number;
    public:
        Controller(Board* b, char p, int n);
        virtual bool Move() = 0; // Returns true on winning move
};

class Player : public Controller{
    public:
        using Controller::Controller;
        bool Move();
};

class RandomComp : public Controller{

};

#endif //CON_H_