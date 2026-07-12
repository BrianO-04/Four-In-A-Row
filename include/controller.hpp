#ifndef CON_H_
#define CON_H_

#include "board.hpp"

class Opponent{
    private:
        Board* board;
    public:
        Opponent(Board* b);
        int CalculateMove();
};

#endif //CON_H_