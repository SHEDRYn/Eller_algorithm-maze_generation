#ifndef MODEL_FILE_CREATOR
#define MODEL_FILE_CREATOR

#include <string>
#include <fstream>
#include "../mazeGenerator/mazeGenerator.h"

class FileCreator{
public:
    void CreateFile(){
        std::ofstream out("generatedMaze.txt");
        MazeGenerator maze;
        maze.Generate(out);
        out.close();
    }

    // std::string GetPath(){
    //     return path_;
    // }
private:
    // std::string path_;
};

#endif //MODEL_FILE_CREATOR