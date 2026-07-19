#include <vector>
#include "funcs.hpp"
#include "network.hpp"
#include "gamedata.hpp"
#include <filesystem>

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

    for(int i = 0; i < dataFiles.size(); i++){
        dataFiles[i].printMoves();
    }

    return 0;
}