#ifndef MODEL_FILE_VALIDATOR_H
#define MODEL_FILE_VALIDATOR_H

#include <iostream>
#include <string>

#include "../file/file.h"


class FileValidator { // надо доделать. он сырой
public:
    FileValidator(){};

    bool IsValid(File* file){
        std::string line;
        std::string num_str;

        std::cout << "Я валидатор" << std::endl;
        std::getline(*file->GetStream(),line);



        
        while(std::getline(*file->GetStream(),line)){
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
    // bool CheckNums(File* file){
    //     std::getline(*file->GetStream(),line);
    //     if (line.lenght() = 0;){
    //         CheckNums(file);
    //     }
    // }
};



#endif // MODEL_FILE_VALIDATOR_H