#ifndef BOARD_H_
#define BOARD_H_

class Board {
    private:
        char* positions;
    public:
        Board(char w, char h);
        ~Board();
};

#endif // BOARD_H_