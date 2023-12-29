#ifndef MODEL_FILE_VALIDATOR_H
#define MODEL_FILE_VALIDATOR_H

#include <iostream>
#include <string>

#include "../file/file.h"


class FileValidator { // надо доделать
public:
    FileValidator(){};

    bool IsValid(File* file){
        std::string line;
        std::string num_str;

        std::cout << "Я валидатор" << std::endl;
        std::getline(*file->GetFile(),line);

        
        while(std::getline(*file->GetFile(),line)){
            for (char ch : line){
                if (ch != '1' && ch != '0' && ch != ' '){
                    std::cout << "Я провал валидатора" << std::endl;
                    return false;
                }
            }
        }
        
        return true;
    }

private:
        
};



#endif // MODEL_FILE_VALIDATOR_H