#ifndef OPP_H_
#define OPP_H_

#include "board.hpp"

class Opponent{
    private:
        Board* board;
    public:
        Opponent(Board* b);
        int CalculateMove();
};

#endif //OPP_H_