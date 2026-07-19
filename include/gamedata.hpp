#ifndef DATA_H_
#define DATA_H_

#include <string>

#define BOARD_SIZE 7*6

class Data{
private:
    int moves[BOARD_SIZE] = {-1};
    int moveNum = 0;
public:
    void addMove(int move);
    void printMoves();
    int saveData();
    int loadData(const std::string& fileName);
    int getTotalMoves();
    int getWinnerNumber();
};

#endif // DATA_H_