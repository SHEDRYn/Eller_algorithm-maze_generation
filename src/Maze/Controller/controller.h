#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/model.h"

#include <iostream>
#include <string>

class Controller {
public:
    Controller(Model* m) :m_(m){};

    bool FileProcessing(const std::string& path){
        return m_->FileProcessing(path);
    }

    Maze* GetMaze(){
        return m_->GetMaze();
    }

private:
    Model* m_;
};

#endif // CONTROLLER_H
