#ifndef SRC_MAZE_MODEL_PARSER_H
#define SRC_MAZE_MODEL_PARSER_H

#include <fstream>
#include <iostream>
#include <vector>

using std::vector;

class Parser {
 public:
  Parser() = default;
  vector<vector<int>> loadMazeFromFile(const std::string& filename);

 private:
  vector<vector<int>> data_;
};
#endif  // SRC_MAZE_MODEL_PARSER_H
