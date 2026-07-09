#ifndef BOARD_H_
#define BOARD_H_

class Board {
    private:
        char* positions;
    public:
        Board(char w, char h);
        ~Board();
        int put(char piece, char col);
        bool check(char row, char col);
        void reset();
};

#endif // BOARD_H_