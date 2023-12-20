#ifndef SRC_MAZE_CONTROLLER_CONTROLLER_H
#define SRC_MAZE_CONTROLLER_CONTROLLER_H

#include "../Model/parser.h"

using std::vector;

class Controller {
 public:
  Controller() = default;

  bool loadMap(const std::string& filename);
  Parser::RowsAndColumns GetData();

 private:
  Parser pars;
  Parser::RowsAndColumns data_;
};

#endif  // SRC_MAZE_CONTROLLER_CONTROLLER_H