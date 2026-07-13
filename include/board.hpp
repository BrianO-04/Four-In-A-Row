#ifndef BOARD_H_
#define BOARD_H_

class Board {
    private:
        char* positions;
        int w, h;
        char getPieceAt(int row, int col);
    public:
        Board(int wid, int hei);
        ~Board();
        int put(char piece, char col);
        bool check(char row, char col);
        bool check(char row, char col, char check);
        void reset();
        void printBoard();
        int getWidth();
        bool full();
};

#endif // BOARD_H_