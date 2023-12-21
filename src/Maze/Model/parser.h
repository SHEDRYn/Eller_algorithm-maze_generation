#ifndef SRC_MAZE_MODEL_PARSER_H
#define SRC_MAZE_MODEL_PARSER_H

#include <fstream>
#include <iostream>

#include "dataTypes.h"

class Parser {
 public:
  Parser() = default;

  RowsAndColumns loadMazeFromFile(const std::string& filename);
};
#endif  // SRC_MAZE_MODEL_PARSER_H
