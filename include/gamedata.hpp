#ifndef DATA_H_
#define DATA_H_

#include <string>

class Data{
private:
    int moves[7*6] = {0};
    int moveNum = 0;
public:
    void addMove(int move);
    void printMoves();
    int saveData();
    int loadData(const std::string& fileName);
};

#endif // DATA_H_