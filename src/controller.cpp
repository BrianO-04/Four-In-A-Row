#include "../include/controller.hpp"
#include "../include/input.hpp"
#include "board.hpp"
#include "network.hpp"
#include <asm-generic/errno.h>
#include <iostream>
#include <string>
#include "funcs.hpp"

Controller::Controller(Board* b, char p, int n){
    board = b;
    piece = p;
    number = n;
}

bool Player::Move(Data* data){
    board->printBoard();
    std::cout << "Player " + std::to_string(number) + ", input column: ";
    int col = getNumberInput();

    int row = board->put(piece, col);
    while(row == -1){ // Invalid input loop
        board->printBoard();
        std::cout << "Invalid input!" << std::endl << "Player " + std::to_string(number) + ", input column: ";
        col = getNumberInput();
        row = board->put(piece, col);
    }

    data->addMove(col);
    return board->check(row, col);
}

RandomComp::RandomComp(Board* b, char p, int n) : Controller(b, p, n){
    std::random_device rd;
    gen = std::mt19937(rd());
    distrib = std::uniform_int_distribution<int>(0, b->getWidth()-1);
}

bool RandomComp::Move(Data* data){
    int col = distrib(gen);
    
    int row = board->put(piece, col);
    while(row == -1){ // Invalid input loop
        col = distrib(gen);
        row = board->put(piece, col);
    }
    std::cout << "Player " << number << ", input column: " << std::to_string(col) << std::endl;

    data->addMove(col);
    return board->check(row, col);
}

SimpleComp::SimpleComp(Board* b, char p, int n) : Controller(b, p, n){
    std::random_device rd;
    gen = std::mt19937(rd());
    distrib = std::uniform_int_distribution<int>(0, b->getWidth()-1);
}

bool SimpleComp::Move(Data* data){

    // Check for winning spots
    for(int i = 0; i < board->getWidth(); i ++){
        if(board->check(0, i, piece)){
            int row = board->put(piece, i);
            std::cout << "Player " << number << ", input column: " << std::to_string(i) << std::endl;
            data->addMove(i);
            return board->check(row, i);
        }
    }

    // Check if opponent can win
    char check = (piece == '1') ? '2' : '1';
    for(int i = 0; i < board->getWidth(); i ++){
        if(board->check(0, i, check)){
            int row = board->put(piece, i);
            std::cout << "Player " << number << ", input column: " << std::to_string(i) << std::endl;
            data->addMove(i);
            return board->check(row, i);
        }
    }

    // Get spot ratings
    int* cols = new int[board->getWidth()];
    for(int i = 0; i < board->getWidth(); i ++){
        cols[i] = board->spotRating(i, piece);
    }

    // Choose highest rating
    int maxRating = -1;
    int maxIndex = -1;
    for(int i = 0; i < board->getWidth(); i++){
        if(cols[i] > maxRating){
            maxRating = cols[i];
            maxIndex = i;
        }
    }

    delete[] cols;

    if(maxRating > 0){
        int row = board->put(piece, maxIndex);
        std::cout << "Player " << number << ", input column: " << std::to_string(maxIndex) << std::endl;
        data->addMove(maxIndex);
        return board->check(row, maxIndex);
    }else{ // Random if there are no spots next to existing pieces
        int col = distrib(gen);
        
        int row = board->put(piece, col);
        while(row == -1){ // Invalid input loop
            col = distrib(gen);
            row = board->put(piece, col);
        }
        std::cout << "Player " << number << ", input column: " << std::to_string(col) << std::endl;
        data->addMove(col);
        return board->check(row, col);
    }
}

NNAI::NNAI(Board* b, char p, int n, std::string weightFile) : Controller(b, p, n){
    Layer hidden_layer(BOARD_SIZE, 128, ReLU, ReLU_Derivative);
    Layer hidden_layer2(128, 64, ReLU, ReLU_Derivative);
    Layer hidden_layer3(64, 64, ReLU, ReLU_Derivative);
    Layer output_layer(64, 7, Identity, Identity_Derivative);
    nn = new NeuralNetwork({hidden_layer, hidden_layer2, hidden_layer3, output_layer});

    nn->loadWeights(weightFile);
}

bool NNAI::Move(Data* data){
    Eigen::VectorXd moves(BOARD_SIZE);
    moves.setConstant(-1);
    for(int k = 0; k < BOARD_SIZE; k++){ // Copy moves up to point into vector
        moves[k] = data->moves[k];
    }
    nn->forwardPass(moves);

    Eigen::VectorXd output = nn->getOutput();

    int predicted_index;
    output.maxCoeff(&predicted_index);

    int row = board->put(piece, predicted_index);
    while(row == -1){ // Invalid input loop
        predicted_index += 1;
        predicted_index %= board->getWidth();
        row = board->put(piece, predicted_index);
    }
    data->addMove(predicted_index);
    return board->check(row, predicted_index);
}