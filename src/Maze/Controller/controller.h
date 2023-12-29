#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

#include <iostream>
#include <string>

class Controller {
public:
    Controller(Model* m) :m_(m){};

    void FileProcessing(const std::string& path){
        m_->FileProcessing(path);
    }

private:
    Model* m_;
};

#endif // CONTROLLER_H
