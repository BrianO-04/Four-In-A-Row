#ifndef DATA_H_
#define DATA_H_

class Data{
private:
    int moves[7*6] = {0};
    int moveNum = 0;
public:
    void addMove(int move);
    int saveData();
};

#endif // DATA_H_