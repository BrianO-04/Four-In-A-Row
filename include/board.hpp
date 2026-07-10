#ifndef BOARD_H_
#define BOARD_H_

class Board {
    private:
        char* positions;
        char w, h;
        char getPieceAt(int row, int col);
    public:
        Board(char w, char h);
        ~Board();
        int put(char piece, char col);
        bool check(char row, char col);
        void reset();
        void printBoard();
};

#endif // BOARD_H_