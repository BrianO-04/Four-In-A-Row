#include <Eigen/Core>
#include <Eigen/src/Core/Matrix.h>
#include <asm-generic/errno.h>
#include <iostream>
#include <ostream>
#include <vector>
#include "funcs.hpp"
#include "network.hpp"
#include "gamedata.hpp"
#include <filesystem>

void player1Data(std::vector<Eigen::VectorXd>* inputData, std::vector<Eigen::VectorXd>* targets, std::vector<Data> dataFiles, int i){
    // Set initial board state for first move
    Eigen::VectorXd boardState(BOARD_SIZE);
    boardState.setConstant(-1);

    Eigen::VectorXd targetMove(7);
    targetMove.setZero();
    targetMove[dataFiles[i].moves[0]] = 1.0;

    inputData->push_back(boardState);
    targets->push_back(targetMove);

    for(int j = 2; j < dataFiles[i].getTotalMoves(); j += 2){
        Eigen::VectorXd board(BOARD_SIZE);
        board.setConstant(-1);
        for(int k = 0; k < j; k++){ // Copy moves up to point into vector
            board[k] = dataFiles[i].moves[k];
            std::cout << "Phase " << j << " move " << dataFiles[i].moves[k] << std::endl;
        }

        Eigen::VectorXd target(7);
        target.setZero();
        target[dataFiles[i].moves[j]] = 1.0;

        std::cout << "Phase " << j << " target: " << dataFiles[i].moves[j] << std::endl;

        inputData->push_back(board);
        targets->push_back(target);
    }
}

void player2Data(std::vector<Eigen::VectorXd>* inputData, std::vector<Eigen::VectorXd>* targets, std::vector<Data> dataFiles, int i){
    // Set initial board state for first move
    Eigen::VectorXd boardState(BOARD_SIZE);
    boardState.setConstant(-1);
    boardState[0] = dataFiles[i].moves[0];

    Eigen::VectorXd targetMove(7);
    targetMove.setZero();
    targetMove[dataFiles[i].moves[1]] = 1.0;

    inputData->push_back(boardState);
    targets->push_back(targetMove);

    for(int j = 3; j < dataFiles[i].getTotalMoves(); j += 2){
        Eigen::VectorXd board(BOARD_SIZE);
        board.setConstant(-1);
        for(int k = 0; k < j; k++){ // Copy moves up to point into vector
            board[k] = dataFiles[i].moves[k];
            std::cout << "Phase " << j << " move " << dataFiles[i].moves[k] << std::endl;
        }

        Eigen::VectorXd target(7);
        target.setZero();
        target[dataFiles[i].moves[j]] = 1.0;

        std::cout << "Phase " << j << " target: " << dataFiles[i].moves[j] << std::endl;

        inputData->push_back(board);
        targets->push_back(target);
    }
}

int main(){
    
    std::string data_path = "data";

    std::vector<Data> dataFiles;

    if(std::filesystem::exists(data_path) && std::filesystem::is_directory(data_path)){
        for(const auto& entry : std::filesystem::directory_iterator(data_path)){
            if(std::filesystem::is_regular_file(entry.status())){
                Data newData = Data();
                newData.loadData(entry.path());
                dataFiles.push_back(newData);
            }
        }
    }

    Layer hidden_layer(BOARD_SIZE, 128, ReLU, ReLU_Derivative);
    Layer hidden_layer2(128, 64, ReLU, ReLU_Derivative);
    Layer hidden_layer3(64, 64, ReLU, ReLU_Derivative);
    Layer output_layer(64, 7, Identity, Identity_Derivative);

    std::vector<Eigen::VectorXd> inputData;
    std::vector<Eigen::VectorXd> targets;

    for(int i = 0; i < dataFiles.size(); i++){
        if(dataFiles[i].getWinnerNumber() == 1){
            player1Data(&inputData, &targets, dataFiles, i);
        }else{
            player2Data(&inputData, &targets, dataFiles, i);
        }

    }
    NeuralNetwork nn({hidden_layer, hidden_layer2, hidden_layer3, output_layer});

    nn.loadWeights("weights/Weights.bin");
    nn.train(inputData, targets, 0.001, 100);

    nn.exportWeights();

    return 0;
}

