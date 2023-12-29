#ifndef MODEL_MAZE_H
#define MODEL_MAZE_H

#include <vector>

struct Maze {
    unsigned int cols_;
    unsigned int rows_;
    std::vector<std::vector<unsigned int>>* wall_right_;
    std::vector<std::vector<unsigned int>>* wall_down_;
};

// class Maze {
// public:
    // Maze(): 
    //     cols_(0),
    //     rows_(0)
    // {
    //     wall_right_ = new std::vector<std::vector<unsigned int>>;
    //     wall_down_ = new std::vector<std::vector<unsigned int>>;
    // }
        
    // ~Maze(){
    //     delete wall_right_;
    //     delete wall_down_;
    // }

    // Maze(const Maze &maze){
    //     cols_ = maze.cols_;
    //     rows_ = maze.rows_;
    //     wall_down_ = maze.wall_down_;
    //     wall_right_ = maze.wall_right_;
    // }

    // Maze& operator=(const Maze &maze)
    // {
    //     if (this == &maze) return *this;

    //     delete wall_right_;
    //     delete wall_down_;

    //     cols_ = maze.cols_;
    //     rows_ = maze.rows_;
    //     wall_down_ = maze.wall_down_;
    //     wall_right_ = maze.wall_right_;
        
    //     return *this;
    // }    

    // Maze& operator=(Maze &&maze)
    // {
    //     if (this == &maze) return *this;

    //     delete wall_right_;
    //     delete wall_down_;

    //     cols_ = maze.cols_;
    //     rows_ = maze.rows_;
    //     wall_down_ = maze.wall_down_;
    //     wall_right_ = maze.wall_right_;
    //     maze.wall_down_ = nullptr;
    //     maze.wall_right_ = nullptr;

    //     return *this;
    // }

    
// private:
//     unsigned int cols_;
//     unsigned int rows_;
//     std::vector<std::vector<unsigned int>>* wall_right_;
//     std::vector<std::vector<unsigned int>>* wall_down_;
// };


#endif // MODEL_MAZE_H
