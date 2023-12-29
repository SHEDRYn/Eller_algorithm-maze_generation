#ifndef MODEL_FILE_PARSER_H
#define MODEL_FILE_PARSER_H

#include <iostream>
#include <string>
// #include <vector>

#include "../maze/maze.h"
#include "Model/file/file.h"

class FileParser {
public:
    FileParser(){};

    Maze Parsing(File* file){
        std::string line;
        Maze maze;
        
        file->GetStream()->clear();
        file->GetStream()->seekg(0, file->GetStream()->beg);
        
        std::cout << "я парсер " << line << std::endl;

        *(file->GetStream()) >> maze.cols_ >> maze.rows_;

        std::vector<std::vector<int>> maze_right(maze.cols_, std::vector<int>(maze.cols_));
        std::vector<std::vector<int>> maze_down(maze.rows_, std::vector<int>(maze.rows_));

        for (int i = 0; i < maze.rows_; ++i) {
            for (int j = 0; j < maze.cols_; ++j) {
                *(file->GetStream()) >> maze_right[i][j];
            }
        }

        for (int i = 0; i < maze.rows_; ++i) {
            for (int j = 0; j < maze.cols_; ++j) {
                *(file->GetStream()) >> maze_down[i][j];
            }
        }

        maze.wall_down_ = maze_down;
        maze.wall_right_ = maze_right;

        // for (int i = 0; i < maze.rows_; ++i) {
        //     for (int j = 0; j < maze.cols_; ++j) {
        //         std::cout << (maze.wall_right_[i][j]) << " ";
        //     }
        //     std::cout << std::endl;
        // }

        // for (int i = 0; i < maze.rows_; ++i) {
        //     for (int j = 0; j < maze.cols_; ++j) {
        //         std::cout << (maze.wall_down_[i][j]) << " ";
        //     }
        //     std::cout << std::endl;
        // }
        
        return maze;
    };

private:

};

#endif // MODEL_FILE_PARSER_H
