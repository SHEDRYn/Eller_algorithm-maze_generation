#ifndef SRC_MAZE_CONTROLLER_CONTROLLER_H
#define SRC_MAZE_CONTROLLER_CONTROLLER_H

#include "../Model/parser.h"

using std::vector;

class Controller {
 public:
  Controller() = default;

  bool loadMap(const std::string& filename);
  vector<vector<int>> GetData();

 private:
  Parser pars;
  vector<vector<int>> data_;
};

#endif  // SRC_MAZE_CONTROLLER_CONTROLLER_H