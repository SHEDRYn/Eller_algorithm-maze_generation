#ifndef MODEL_MAZE_H
#define MODEL_MAZE_H

#include <vector>

struct Maze {
    int cols_;
    int rows_;
    std::vector<std::vector<int>> wall_right_;
    std::vector<std::vector<int>> wall_down_;
};

// class Maze {
// public:
//     Maze(): 
//         cols_(0),
//         rows_(0)
//     {
//         wall_right_ = new std::vector<std::vector<unsigned int>>;
//         wall_down_ = new std::vector<std::vector<unsigned int>>;
//     }

//     Maze(unsigned int cols,unsigned int rows){
//         wall_right_ = new std::vector<std::vector<unsigned int>>(cols, std::vector<unsigned int>(cols));
//         wall_down_ = new std::vector<std::vector<unsigned int>>(rows, std::vector<unsigned int>(rows));
//     }
        
//     ~Maze(){
//         delete wall_right_;
//         delete wall_down_;
//     }

//     Maze(const Maze &maze){
//         cols_ = maze.cols_;
//         rows_ = maze.rows_;
//         wall_down_ = maze.wall_down_;
//         wall_right_ = maze.wall_right_;
//     }

//     // Maze& operator=(const Maze &maze)
//     // {
//     //     if (this == &maze) return *this;

//     //     delete wall_right_;
//     //     delete wall_down_;

//     //     cols_ = maze.cols_;
//     //     rows_ = maze.rows_;
//     //     wall_down_ = maze.wall_down_;
//     //     wall_right_ = maze.wall_right_;
        
//     //     return *this;
//     // }    

//     Maze& operator=(Maze &&maze)
//     {
//         if (this == &maze) return *this;

//         delete wall_right_;
//         delete wall_down_;

//         cols_ = maze.cols_;
//         rows_ = maze.rows_;
//         wall_down_ = maze.wall_down_;
//         wall_right_ = maze.wall_right_;
//         maze.wall_down_ = nullptr;
//         maze.wall_right_ = nullptr;

//         return *this;
//     }

//     void SetCols(unsigned int cols){
//         cols = cols;
//     }

//     void SetRows(unsigned int rows){
//         rows_ = rows;
//     }

//     void SetElement(unsigned int row, unsigned int col){
//         wall_right_[row][col];
//     }

//     unsigned int GetCols(){
//         return cols_;
//     }

//     unsigned int GetRows(){
//         return rows_;
//     }

//     unsigned int GetElement(unsigned int row, unsigned int col){
//         return wall_right_[row][col];
//     }



//     // void Rendering(){

//     // }

    
// private:
//     unsigned int cols_;
//     unsigned int rows_;
//     std::vector<std::vector<unsigned int>>* wall_right_;
//     std::vector<std::vector<unsigned int>>* wall_down_;
// };


#endif // MODEL_MAZE_H
