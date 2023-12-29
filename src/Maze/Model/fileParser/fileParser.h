#ifndef MODEL_FILE_PARSER_H
#define MODEL_FILE_PARSER_H

#include <iostream>
#include <string>

#include "../maze/maze.h"


class FileParser { // надо дописать
public:
    FileParser(){};

    Maze Parsing(File* file){
        std::string line;
        Maze maze;
        
        file->GetFile()->clear();
        file->GetFile()->seekg(0, file->GetFile()->beg);
        
        std::cout << "я парсер " << line << std::endl;
        while(std::getline(*file->GetFile(),line)){
            std::cout << line << std::endl;
        }
        
        return maze;
    };
private:

};



#endif // MODEL_FILE_PARSER_H