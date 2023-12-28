#ifndef SRC_MAZE_CONTROLLER_CONTROLLER_H
#define SRC_MAZE_CONTROLLER_CONTROLLER_H

#include "../Model/parser.h"
#include "../Model/fileCreator/fileCreator.h"

class Controller {
 public:
  Controller() = default;

  bool loadMap(const std::string& filename);
  RowsAndColumns GetData();

  void MazeGenerate(int cols){ // он тут не должен быть, и вообще нужно все переделать
      FileCreator file;
      file.CreateFile(cols);
  }

  void MazeUpdate(RowsAndColumns new_maze){ // это тоже не должен быть тут
    data_ = new_maze;
  }

 private:
  Parser pars;
  RowsAndColumns data_;
};

#endif  // SRC_MAZE_CONTROLLER_CONTROLLER_H
