#ifndef MODEL_H
#define MODEL_H

#include "file/file.h"
#include "fileValidator/fileValidator.h"
#include "fileParser/fileParser.h"
#include "maze/maze.h"

#include <iostream>
#include <string>


class Model { // Facade для Facade'ов
public:
    Model(){};

    ~Model() {
        if (file_) delete file_;
    }

    bool FileProcessing(const std::string& path){

        file_ = new File(path);
        FileValidator file_validator;
        FileParser file_parser;

        file_->OpenFile();

        if(!file_->GetStream()->is_open() || !file_validator.IsValid(file_)){
            return false;
        } 

        maze_ = new Maze;
        *maze_ = file_parser.Parsing(file_);
        file_->CloseFile();

        return true;
    }

    Maze* GetMaze(){
        return maze_;
    } 

    
    
private:
    File* file_;
    Maze* maze_;
    // FileValidator* file_validator_;
};

#endif // MODEL_H
