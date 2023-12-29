#ifndef MODEL_FILE_H
#define MODEL_FILE_H

#include <iostream>
#include <fstream>


class File {
public:
    File(const std::string& path) : path_(path){};

    void OpenFile(){
        in_ = new std::ifstream(path_);
    }

    void CloseFile(){
        in_->close();
    }

    std::ifstream* GetFile(){
        return in_;
    }

private:
    const std::string path_;
    // bool is_valid_;
    std::ifstream* in_;
};



#endif // MODEL_FILE_H