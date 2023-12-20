#ifndef SRC_MAZE_MODEL_PARSER_H
#define SRC_MAZE_MODEL_PARSER_H

#include <fstream>
#include <iostream>
#include <vector>

using std::vector;

class Parser {
 public:
  Parser() = default;

  struct RowsAndColumns {
    vector<vector<int>> rows;
    vector<vector<int>> columns;
  };

  RowsAndColumns loadMazeFromFile(const std::string& filename);
};
#endif  // SRC_MAZE_MODEL_PARSER_H
