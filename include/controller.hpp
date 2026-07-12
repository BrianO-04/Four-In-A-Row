#ifndef CON_H_
#define CON_H_

#include "board.hpp"

class Controller{
    protected:
        Board* board;
    public:
        Controller(Board* b);
        virtual bool Move() = 0; // Returns true on winning move
};

class Player : public Controller{
    private:
        char piece;
        int number;
    public:
        Player(Board* b, char p, int n);
        bool Move();
};

#endif //CON_H_