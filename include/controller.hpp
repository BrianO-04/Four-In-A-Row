#ifndef CON_H_
#define CON_H_

#include "board.hpp"
#include <random>
#include "gamedata.hpp"
#include "network.hpp"

class Controller{
    protected:
        Board* board;
        char piece;
        int number;
    public:
        virtual ~Controller() = default;
        Controller(Board* b, char p, int n);
        virtual bool Move(Data* data) = 0; // Returns true on winning move
};

class Player : public Controller{
    public:
        using Controller::Controller;
        bool Move(Data* data);
};

class RandomComp : public Controller{
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> distrib;
    public:
        RandomComp(Board* b, char p, int n);
        bool Move(Data* data);
};

class SimpleComp : public Controller{
    private:
        std::mt19937 gen;
        std::uniform_int_distribution<int> distrib;
    public:
        SimpleComp(Board* b, char p, int n);
        bool Move(Data* data);
};

class NNAI : public Controller{
    private:
        NeuralNetwork* nn;
    public:
        NNAI(Board* b, char p, int n, std::string weightFile);
        bool Move(Data* data);
};

#endif //CON_H_