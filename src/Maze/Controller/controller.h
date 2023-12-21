#ifndef SRC_MAZE_CONTROLLER_CONTROLLER_H
#define SRC_MAZE_CONTROLLER_CONTROLLER_H

#include "../Model/parser.h"

class Controller {
 public:
  Controller() = default;

  bool loadMap(const std::string& filename);
  RowsAndColumns GetData();

 private:
  Parser pars;
  RowsAndColumns data_;
};

#endif  // SRC_MAZE_CONTROLLER_CONTROLLER_H